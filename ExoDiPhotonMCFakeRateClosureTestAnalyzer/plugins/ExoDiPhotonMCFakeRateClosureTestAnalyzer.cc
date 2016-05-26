// -*- C++ -*-
//
// Package:    diphoton-analysis/ExoDiPhotonMCFakeRateClosureTestAnalyzer
// Class:      ExoDiPhotonMCFakeRateClosureTestAnalyzer
// 
/**\class ExoDiPhotonMCFakeRateClosureTestAnalyzer ExoDiPhotonMCFakeRateClosureTestAnalyzer.cc diphoton-analysis/ExoDiPhotonMCFakeRateClosureTestAnalyzer/plugins/ExoDiPhotonMCFakeRateClosureTestAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrew Buccilli
//         Created:  Thu, 24 Mar 2016 14:11:52 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// from our CommomClasses
#include "diphoton-analysis/CommonClasses/interface/EventInfo.h"
#include "diphoton-analysis/CommonClasses/interface/JetInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonID.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonInfo.h"
#include "diphoton-analysis/CommonClasses/interface/GenParticleInfo.h"

// for TFileService, trees
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "TTree.h"

// for ECAL topology
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"

// for EGM ID
#include "RecoEgamma/EgammaTools/interface/EffectiveAreas.h"

// for photons
#include "DataFormats/PatCandidates/interface/Photon.h"

// for jets
#include "DataFormats/PatCandidates/interface/Jet.h"

// for genParticles
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

// for genEventInfo
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

// for deltaR
#include "DataFormats/Math/interface/deltaR.h"

// for trigger and filter decisions
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class ExoDiPhotonMCFakeRateClosureTestAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ExoDiPhotonMCFakeRateClosureTestAnalyzer(const edm::ParameterSet&);
      ~ExoDiPhotonMCFakeRateClosureTestAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  // ----------member data ---------------------------
  // photon token
  edm::EDGetToken photonsMiniAODToken_;

  // genParticle token
  edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticlesMiniAODToken_;
  
  // AK4 jet token and cuts
  edm::EDGetToken jetsMiniAODToken_;
  double jetPtThreshold;
  double jetEtaThreshold;

  // BeamHaloSummary token
  edm::EDGetToken beamHaloSummaryToken_;

  // Filter decisions token
  edm::EDGetToken filterDecisionToken_;
  
  // ECAL recHits
  edm::InputTag recHitsEBTag_;
  edm::InputTag recHitsEETag_;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEBToken;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEEToken;

  // rho token
  edm::EDGetTokenT<double> rhoToken_;

  // rho variable
  double rho_;

  // EGM eff. areas
  EffectiveAreas effAreaChHadrons_;
  EffectiveAreas effAreaNeuHadrons_;
  EffectiveAreas effAreaPhotons_;

  // EGM ID decision tokens
  edm::EDGetTokenT<edm::ValueMap<bool> > phoLooseIdMapToken_;
  edm::EDGetTokenT<edm::ValueMap<bool> > phoMediumIdMapToken_;
  edm::EDGetTokenT<edm::ValueMap<bool> > phoTightIdMapToken_;
  
  // trees
  TTree *fTree;
  TTree *fTreeFake;
  
  // photons
  ExoDiPhotons::photonInfo_t fPhotonInfo;
  ExoDiPhotons::photonInfo_t fPhotonMatchInfo;
  
  // jets
  ExoDiPhotons::jetInfo_t fJetInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;

  // gen event info token
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken_;

  // genParticles
  ExoDiPhotons::genParticleInfo_t fPhotonGenMatchInfo;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ExoDiPhotonMCFakeRateClosureTestAnalyzer::ExoDiPhotonMCFakeRateClosureTestAnalyzer(const edm::ParameterSet& iConfig)
  : rhoToken_(consumes<double> (iConfig.getParameter<edm::InputTag>("rho"))),
    effAreaChHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaChHadFile")).fullPath() ),
    effAreaNeuHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaNeuHadFile")).fullPath() ),
    effAreaPhotons_( (iConfig.getParameter<edm::FileInPath>("effAreaPhoFile")).fullPath() ),
    phoLooseIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoLooseIdMap"))),
    phoMediumIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoMediumIdMap"))),
    phoTightIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoTightIdMap"))),
    genInfoToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("genInfo")))
{
  //now do what ever initialization is needed
  usesResource("TFileService");
  
  edm::Service<TFileService> fs;
  
  // tree for objects passing numerator or denominator definitions
  fTree = fs->make<TTree>("fTree","PhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTree->Branch("Photon",&fPhotonInfo,ExoDiPhotons::photonBranchDefString.c_str());

  // tree for photon objects matched to fake genPhotons
  fTreeFake = fs->make<TTree>("fTreeFake","FakePhotonTree");
  fTreeFake->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTreeFake->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTreeFake->Branch("Photon",&fPhotonMatchInfo,ExoDiPhotons::photonBranchDefString.c_str());
  fTreeFake->Branch("PhotonGenMatch",&fPhotonGenMatchInfo,ExoDiPhotons::genParticleBranchDefString.c_str());
  
  // photon token
  photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonsMiniAOD"));
  
  // genParticle token
  genParticlesMiniAODToken_ = mayConsume<edm::View<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticlesMiniAOD"));
  
  // AK4 jets token
  jetsMiniAODToken_ = mayConsume< edm::View<pat::Jet> >(iConfig.getParameter<edm::InputTag>("jetsMiniAOD"));
  jetPtThreshold = iConfig.getParameter<double>("jetPtThreshold");
  jetEtaThreshold = iConfig.getParameter<double>("jetEtaThreshold");
  
  // ECAL RecHits
  recHitsEBTag_ = iConfig.getUntrackedParameter<edm::InputTag>("RecHitsEBTag",edm::InputTag("reducedEgamma:reducedEBRecHits"));
  recHitsEETag_ = iConfig.getUntrackedParameter<edm::InputTag>("RecHitsEETag",edm::InputTag("reducedEgamma:reducedEERecHits"));
  recHitsEBToken = consumes <edm::SortedCollection<EcalRecHit> > (recHitsEBTag_);
  recHitsEEToken = consumes <edm::SortedCollection<EcalRecHit> > (recHitsEETag_);
  
  // BeamHaloSummary
  beamHaloSummaryToken_ = consumes<reco::BeamHaloSummary>( edm::InputTag("BeamHaloSummary") );

  // Filter decisions
  filterDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","","PAT") );
}


ExoDiPhotonMCFakeRateClosureTestAnalyzer::~ExoDiPhotonMCFakeRateClosureTestAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ExoDiPhotonMCFakeRateClosureTestAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace pat;

  // ==========
  // EVENT INFO
  // ==========

  edm::Handle< reco::BeamHaloSummary > bhsHandle;
  iEvent.getByToken(beamHaloSummaryToken_,bhsHandle);
  const reco::BeamHaloSummary* bhs = &(*bhsHandle);
  
  ExoDiPhotons::InitEventInfo(fEventInfo);
  ExoDiPhotons::FillBasicEventInfo(fEventInfo, iEvent);
  ExoDiPhotons::FillBeamHaloEventInfo(fEventInfo, bhs);
  
  //cout <<  "Run: " << iEvent.id().run() << ", LS: " <<  iEvent.id().luminosityBlock() << ", Event: " << iEvent.id().event() << endl;

  // ==============
  // GEN EVENT INFO
  // ==============

  // get genEventInfo
  edm::Handle<GenEventInfoProduct> genInfo;
  iEvent.getByToken(genInfoToken_,genInfo);
  
  ExoDiPhotons::FillGenEventInfo(fEventInfo, &(*genInfo));
  
  // ====
  // JETS
  // ====
  
  ExoDiPhotons::InitJetInfo(fJetInfo);
  
  // add jet HT information
  edm::Handle< edm::View<pat::Jet> > jets;
  iEvent.getByToken(jetsMiniAODToken_,jets);
  
  ExoDiPhotons::FillJetInfo(fJetInfo, &(*jets), jetPtThreshold, jetEtaThreshold);

  // =====================
  // FILTER DECISION INFO
  // =====================
  
  edm::Handle<edm::TriggerResults> filtHandle;
  iEvent.getByToken(filterDecisionToken_,filtHandle);
  const edm::TriggerResults *filterResults = filtHandle.product();
  std::vector<std::string> trigNames = iEvent.triggerNames(*filterResults).triggerNames();
  
  int EEBadScFilterNum = -1;
  for (unsigned int i=0; i < trigNames.size(); i++){
    std::string tempName = trigNames.at(i);
    if (tempName == "Flag_eeBadScFilter"){
      EEBadScFilterNum = i;
      break;
    }
  }
  if (EEBadScFilterNum < 0) throw cms::Exception("FilterDecisionInfo") << "Cannot find Flag_eeBadScFilter in the filter decision object!! This must be investigated!!!";
  
  bool passEEBadScFilter = filterResults->accept(EEBadScFilterNum);

  // Go to next photon if this filter is not passed
  if (!passEEBadScFilter){
    cout << "Event did not pass the EE Bad Supercrystal Filter, skip it!" << endl;
    return;
  }
  
  // ===
  // RHO
  // ===
  
  // Get rho
  edm::Handle< double > rhoH;
  iEvent.getByToken(rhoToken_,rhoH);
  rho_ = *rhoH;
  
  //cout << "rho: " << rho_ << endl;

  // ======
  // EGM ID
  // ======
  
  // EGM ID decisions
  edm::Handle<edm::ValueMap<bool> > loose_id_decisions;
  iEvent.getByToken(phoLooseIdMapToken_ ,loose_id_decisions);
  edm::Handle<edm::ValueMap<bool> > medium_id_decisions;
  iEvent.getByToken(phoMediumIdMapToken_,medium_id_decisions);
  edm::Handle<edm::ValueMap<bool> > tight_id_decisions;
  iEvent.getByToken(phoTightIdMapToken_ ,tight_id_decisions);

  // =========
  // ECAL INFO
  // =========
  
  // ECAL RecHits
  edm::Handle<EcalRecHitCollection> recHitsEB;
  iEvent.getByToken(recHitsEBToken,recHitsEB);   
  edm::Handle<EcalRecHitCollection> recHitsEE;
  iEvent.getByToken(recHitsEEToken,recHitsEE);

  // ECAL Topology
  const CaloSubdetectorTopology* subDetTopologyEB_;
  const CaloSubdetectorTopology* subDetTopologyEE_;
  edm::ESHandle<CaloTopology> caloTopology;
  iSetup.get<CaloTopologyRecord>().get(caloTopology);
  subDetTopologyEB_ = caloTopology->getSubdetectorTopology(DetId::Ecal,EcalBarrel);
  subDetTopologyEE_ = caloTopology->getSubdetectorTopology(DetId::Ecal,EcalEndcap);

  // ============
  // GENPARTICLES
  // ============

  ExoDiPhotons::InitGenParticleInfo(fPhotonGenMatchInfo);
  
  // get genParticle collection
  Handle<edm::View<reco::GenParticle> > genParticles;
  iEvent.getByToken(genParticlesMiniAODToken_,genParticles);

  //for (edm::View<reco::GenParticle>::const_iterator gen = genParticles->begin(); gen != genParticles->end(); ++gen) {
  //for (size_t i = 0; i < genParticles->size(); ++i) {
  //const auto gen = genParticles->ptrAt(i);
  //if (gen->pt() > 50)
  //cout << "GenParticle: " << "pt = " << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi() << endl;
  //} // end of genParticle loop
  
  // =======
  // PHOTONS
  // =======

  ExoDiPhotons::InitPhotonInfo(fPhotonInfo);
  ExoDiPhotons::InitPhotonInfo(fPhotonMatchInfo);
  
  // get photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);
  
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i) {
    const auto pho = photons->ptrAt(i);
    
    // print photon info
    //cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;

    // fill photon saturation
    fPhotonInfo.isSaturated = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    //cout << "isSat: " << fPhotonInfo.isSaturated << endl;
    
    // fill photon info
    ExoDiPhotons::FillBasicPhotonInfo(fPhotonInfo, &(*pho));
    ExoDiPhotons::FillPhotonIDInfo(fPhotonInfo, &(*pho), rho_, fPhotonInfo.isSaturated);
    
    // fill EGM ID info
    ExoDiPhotons::FillPhotonEGMidInfo(fPhotonInfo, &(*pho), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
    fPhotonInfo.passEGMLooseID  = (*loose_id_decisions)[pho];
    fPhotonInfo.passEGMMediumID = (*medium_id_decisions)[pho];
    fPhotonInfo.passEGMTightID  = (*tight_id_decisions)[pho];
    
    // fill our tree
    if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) ||
         ExoDiPhotons::passDenominatorCut(&(*pho), rho_, fPhotonInfo.isSaturated)
      ) fTree->Fill();

    // only match to "numerator" photons
    //if ( !(ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) &&
    //ExoDiPhotons::passChargedHadronCut(&(*pho))) ) {
    //cout << "Photon not a numerator object, will not proceed with matching." << endl;
    //continue;
    //}
    if (ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) &&
	ExoDiPhotons::passChargedHadronCut(&(*pho)) ) {
      cout << "Numerator photon!" << endl;
      cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;
      
      // deltaR cut
      double minDeltaR_hardProcess  = 0.4;
      double minDeltaR_finalState   = 0.1;
      double minDeltaR_genParticles = 0.3;
      
      // no match when starting loop
      const reco::GenParticle *photonMatch_hardProcess  = NULL; // not being used
      const reco::GenParticle *photonMatch_finalState   = NULL;
      const reco::GenParticle *photonMatch_genParticles = NULL;
      
      // loop through genParticles to find photon matches
      //for (edm::View<reco::GenParticle>::const_iterator gen = genParticles->begin(); gen != genParticles->end(); ++gen) {
      for (size_t i = 0; i < genParticles->size(); ++i) {
	const auto gen = genParticles->ptrAt(i);
	
	// calculate deltaR for current genParticle
	double deltaR = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
      
	// check for best match among all gen particles
	if (deltaR <= minDeltaR_genParticles) {
	  minDeltaR_genParticles = deltaR;
	  photonMatch_genParticles = &(*gen);
	}
      
	// check for best match among hard interaction particles
	// using prunedGenParticles
	if (gen->isHardProcess()) {
	  cout << "GenParticle isHardProcess(): Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
	       << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; deltaR = " << deltaR << endl;
	  if (deltaR <= minDeltaR_hardProcess) {
	    minDeltaR_hardProcess = deltaR;
	    photonMatch_hardProcess = &(*gen);
	  }
	}
      
	// check for best match among final state particles
	if (gen->status()==1) {
	  cout << "GenParticle final state: Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
	       << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; deltaR = " << deltaR << endl;
	  if (deltaR <= minDeltaR_finalState) {
	    minDeltaR_finalState = deltaR;
	    photonMatch_finalState = &(*gen);
	  }	
	}
      
      } // end for genParticle loop
      
      // if best final state match is an electron, check for electron pair
      
      // increase final state DeltaR cut to allow for best final state electron close to cut and pair outside of cut
      double minDeltaR_finalStateElectornPair = 0.3;
      const reco::GenParticle *photonMatch_finalStateElectronPair = NULL;
      
      // is best final state match an electron
      if (photonMatch_finalState && fabs(photonMatch_finalState->pdgId()) == 11) {
	
	// loop through all gen particles
	for (size_t i = 0; i < genParticles->size(); ++i) {
	  const auto gen = genParticles->ptrAt(i);
	  
	  // calculate deltaR for current genParticle
	  double deltaR = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
	  
	  // check for best electron match among all gen particles in deltaR cut
	  // igonre already found final state electron match
	  if (&(*photonMatch_finalState) != &(*gen) && fabs(gen->pdgId()) == 11  && deltaR <= minDeltaR_finalStateElectornPair) {
	    minDeltaR_finalStateElectornPair = deltaR;
	    photonMatch_finalStateElectronPair = &(*gen);
	  }
	  
	} // end for genParticle loop
	
      } // end if final state electron
      
      // photon's gen particle match to be filled into tree
      const reco::GenParticle *photonMatch = NULL;
      
      if (photonMatch_hardProcess) {
	//photonMatch = &(*photonMatch_hardProcess);
	cout << "Hard process match." << endl;
	//cout << "HardProcess PhotonMatch: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId()
	//<< "; pt = " photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi() << "; deltaR = " << minDeltaR_hardProcess << endl;
      }
      
      // **************************************************************************************************************************
      // first consider final state matches
      if (photonMatch_finalState) {
	cout << "Final state match." << endl;
	cout << "FinalState PhotonMatch     : Status = " << photonMatch_finalState->status()  << "; ID = " << photonMatch_finalState->pdgId() << "; pt = "
	     << photonMatch_finalState->pt() << "; eta = " << photonMatch_finalState->eta() << "; phi = " << photonMatch_finalState->phi()  << "; deltaR = " << minDeltaR_finalState << endl;

	// store DeltaR between photon and final state match
	fPhotonGenMatchInfo.deltaR_match = minDeltaR_finalState;
	
	// particle whose mothers will looped through
	const reco::GenParticle *matchedMother = &(*photonMatch_finalState);

	// ------------------------------------------------------------------------------------------------------------------------
	// first consider photon matches
	if (photonMatch_finalState->pdgId() == 22) {

	  // count the number of photon matches according to matchCategory
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kFinalStatePhotonMatch;

	  // set to false after finidng first mother
	  bool isFirstMother = true;
	  // set to true if any mother is a hadron (interacting proton is not considered as true)
	  bool isHadronMother = false;
	  // keep track of the photon's first mother
	  bool isQuarkFirstMother = false;
	  // store pdgID of if photon's first mother is a quark
	  int quarkMotherPdgId = 0;
	  // set false after first hard process mother is found
	  bool isFirstHardProcess = true;
	  // flag ISR or FSR process
	  bool isISR = false;
	  bool isFSR = false;
	  // check for fragmentation photon
	  bool isOtherFragmentation = false;
	  // check if any mother is a photon
	  bool isPhotonMother = false; // not currently used

	  // save deltaR of first quark mother if ISR or FSR is determined
	  double deltaR_quarkMother = -1111.1111;
      
	  // consider all mothers when tying to find best mother (no deltaR cut)
	  double minMotherMatchDeltaR = 1000000;
	  // store index of best mother
	  int matchMotherIndex = 0;

	  // loop through all mothers of our matched particle and choose mother with best deltaR match
	  // this is considered the matched particle's ture mother
	  // now find this mother's mother and repeat until no mother exists
	  // this will trace back to the colliding proton which has pt()==0
	  //while (!(matchedMother->pt() == 0 && matchedMother->pdgId() == 2212)) { // && !((reco::GenParticle *)matchedMother->mother())->isHardProcess()) {
	  while (matchedMother->mother()) {
	    //if (fabs(matchedMother->pdgId()) > 99) isHadronMother = true;

	    // loop through all mothers and keep index of best deltaR match
	    for (unsigned int j=0; j < matchedMother->numberOfMothers(); j++) {

	      // calculate deltaR between particle and mother
	      double deltaR = reco::deltaR(matchedMother->eta(),matchedMother->phi(),matchedMother->mother(j)->eta(),matchedMother->mother(j)->phi());

	      // print each mother
	      cout << "\t           Mother " << j << ": Status = " << matchedMother->mother(j)->status()  << "; ID = " << matchedMother->mother(j)->pdgId() << "; pt = "
		   << matchedMother->mother(j)->pt() << "; eta = " << matchedMother->mother(j)->eta() << "; phi = " << matchedMother->mother(j)->phi()  << "; deltaR = " << deltaR << endl;
	      
	      // if current deltaR is smallest, save index
	      if (deltaR < minMotherMatchDeltaR) {
		minMotherMatchDeltaR = deltaR;
		matchMotherIndex = j;
	      }

	    } // end for loop through mothers

	    // store match whose mother is one of the outgoing interacting partons
	    // or whose mother is directly the interacting proton
	    // will be overwritten in the case of ISR or FSR
	    if (!photonMatch && matchedMother->mother(matchMotherIndex)->pt()==0) photonMatch = &(*matchedMother);

	    // record is best mother is a hadron
	    // dont condiser interacting proton a hadron mother
	    if (fabs(matchedMother->pdgId()) > 99) isHadronMother = true;

	    // if quark is radiated from colliding proton giving rise to photon final state, then ISR
	    if (isQuarkFirstMother && fabs(matchedMother->pdgId())==fabs(quarkMotherPdgId) && !matchedMother->isHardProcess() &&
		matchedMother->mother(matchMotherIndex)->pdgId()==2212 && matchedMother->mother(matchMotherIndex)->pt()==0) {
	      isISR = true;
	    }
	    
	    // matched particle now becomes best mother
	    matchedMother = (reco::GenParticle *) matchedMother->mother(matchMotherIndex);

	    // record is best mother is a photon
	    if (matchedMother->pdgId()==22) isPhotonMother = true;

	    // check if first mother is a quark and store deltaR between photon and quark mother
	    if (isFirstMother && -9 < matchedMother->pdgId() && matchedMother->pdgId() < 9) {
	      isQuarkFirstMother = true;
	      quarkMotherPdgId = matchedMother->pdgId();
	      deltaR_quarkMother = minMotherMatchDeltaR;
	    }

	    // check if first mother is a gluon
	    if (isFirstMother && matchedMother->pdgId() == 21) {
	      isOtherFragmentation = true;
	    }
	    
	    // if photon is radiated from colliding proton, then ISR
	    if (isFirstMother && matchedMother->pdgId()==2212 && matchedMother->pt()==0) {
	      isISR = true;
	    }
	    
	    // checked first mother, so set to false
	    isFirstMother = false;

	    // check the first time the best mother is from the hard process
	    if (isFirstHardProcess && matchedMother->isHardProcess()) {
	      // reset so we don't check again
	      isFirstHardProcess = false;
	      // if photon's mother is a quark and that quark is unchanged from the hard process, then 
	      if (isQuarkFirstMother && matchedMother->pdgId()==quarkMotherPdgId) {
		// if hard interaction particle has no pT, then it's an incoming interaction particle, so we have ISR
		if (matchedMother->pt()==0) isISR = true;
		// if some pT, then it's an outgoing interacting particle, so FSR
		else isFSR = true;
	      }
	      // if quark came from a different outgoing hard interaction quark, then fragmentation
	      if (isQuarkFirstMother && matchedMother->pdgId() != quarkMotherPdgId && -9 < matchedMother->pdgId() && matchedMother->pdgId() < 9) {
		isOtherFragmentation = true;
	      }
	      // if quark came from a outgoing hard interacction gluon, then fragmentation
	      if (isQuarkFirstMother && matchedMother->pdgId() == 21) {
		isOtherFragmentation = true;
	      }
	    } // end if first hardProcess mother
	    
	    // print best mother match
	    cout << "FinalState Matched MOTHER " << matchMotherIndex << ": Status = " << matchedMother->status()  << "; ID = " << matchedMother->pdgId() << "; pt = "
		 << matchedMother->pt() << "; eta = " << matchedMother->eta() << "; phi = " << matchedMother->phi()  << "; deltaR = " << minMotherMatchDeltaR << endl;
	    
	    // reset cut!
	    // so we will consider all mothers again during next loop
	    minMotherMatchDeltaR = 1000000;

	    // index could be > 0 and only one mother on next match and could be beam particle with very high deltaR
	    // so reset index just to be safe
	    matchMotherIndex = 0;
	    
	  } // end while loop through mothers
      
	  // print matchedMother mother
	  // should be zero
	  //if (matchedMother->mother()) {
	  //for (unsigned int j=0; j < matchedMother->numberOfMothers(); j++) {
	  //cout << "\t FinalState Match MOTHER's MOTHER " << j << ": Status = " << matchedMother->mother(j)->status()  << "; ID = " << matchedMother->mother(j)->pdgId() << "; pt = "
	  //<< matchedMother->mother(j)->pt() << "; eta = " << matchedMother->mother(j)->eta() << "; phi = " << matchedMother->mother(j)->phi()  << endl;
	  //}
	  //}

	  // if photon has hadron mother, store photonMatch determined in loop
	  // want to know if photon's mother is a quark or gluon
	  if (isHadronMother) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kHadronMotherMatch;
	  }
	  // if not hadron mother, should be one of these distinct processes (e.g., can't be FSR and ISR, or FSR and fragmentation)
	  if (!isHadronMother) {
	    // if FSR, store photon and deltaR between photon and its first quark mother
	    if (isFSR) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kFSRMatch;
	      fPhotonGenMatchInfo.deltaR_FSR = deltaR_quarkMother;
	      photonMatch = &(*photonMatch_finalState);
	    }
	    // if ISR, store photon and deltaR between photon and its first quark mother
	    if (isISR) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kISRMatch;
	      fPhotonGenMatchInfo.deltaR_FSR = deltaR_quarkMother;
	      photonMatch = &(*photonMatch_finalState);
	    }
	    // determine if fragmentation
	    // photonMatch determined in loop will be stored
	    if (isOtherFragmentation) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kOtherFragmentationMatch;
	    }
	    // if not FSR, ISR, or fragmentation, then photon is unmatched
	    // photonMatch determined in loop is stored
	    if (!isFSR && !isISR && !isOtherFragmentation) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kNoMatchType;
	    }
	  } // end if not hadron mother
	  
	  cout << "Is photon mother: " << isPhotonMother << endl;
	  cout << "Is hadron mother: " << isHadronMother << endl;
	  cout << "Is quark first mother: " << isQuarkFirstMother << endl;
	  cout << "Is ISR: " << isISR << endl;
	  cout << "Is FSR: " << isFSR << endl;
	  cout << "Is other fragmentation: " << isOtherFragmentation << endl;
	  
	} // end if final state photon match

	// ------------------------------------------------------------------------------------------------------------------------
	// if final state match is not a photon
	if (photonMatch_finalState->pdgId() != 22) {

	  // count number of non-photon final state matches according to matchCategory
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kFinalStateNonPhotonMatch;

	  bool isHadronOrHadronMother = false;
	  bool isPhotonMother = false;

	  // consider all mothers when tying to find best mother (no deltaR cut)
	  double minMotherMatchDeltaR = 1000000;
	  // store index of best mother
	  int matchMotherIndex = 0;
	  
	  while (matchedMother->mother()) {
	    // determine if final state match is hadron or if any of its mothers are
	    if (fabs(matchedMother->pdgId()) > 99) isHadronOrHadronMother = true;
	    
	    // loop through all mothers and keep index of best deltaR match
	    for (unsigned int j=0; j < matchedMother->numberOfMothers(); j++) {
	      
	      // calculate deltaR between particle and mother
	      double deltaR = reco::deltaR(matchedMother->eta(),matchedMother->phi(),matchedMother->mother(j)->eta(),matchedMother->mother(j)->phi());
	      
	      // print each mother
	      cout << "\t           Mother " << j << ": Status = " << matchedMother->mother(j)->status()  << "; ID = " << matchedMother->mother(j)->pdgId() << "; pt = "
		   << matchedMother->mother(j)->pt() << "; eta = " << matchedMother->mother(j)->eta() << "; phi = " << matchedMother->mother(j)->phi()  << "; deltaR = " << deltaR << endl;
	      
	      // if current deltaR is smallest, save index
	      if (deltaR < minMotherMatchDeltaR) {
		minMotherMatchDeltaR = deltaR;
		matchMotherIndex = j;
	      }
	      
	    } // end for loop through mothers
	    
	    // store match whose mother is one of the outgoing interacting partons
	    // or whose mother is directly the interacting proton
	    // will be overwritten in the case of ISR or FSR
	    if (!photonMatch && matchedMother->mother(matchMotherIndex)->pt()==0) photonMatch = &(*matchedMother);
	    
	    // matched particle now becomes best mother
	    matchedMother = (reco::GenParticle *) matchedMother->mother(matchMotherIndex);
	    
	    // record is best mother is a photon
	    if (matchedMother->pdgId()==22) isPhotonMother = true;
	    
	    // print best mother match
	    cout << "FinalState Matched MOTHER " << matchMotherIndex << ": Status = " << matchedMother->status()  << "; ID = " << matchedMother->pdgId() << "; pt = "
		 << matchedMother->pt() << "; eta = " << matchedMother->eta() << "; phi = " << matchedMother->phi()  << "; deltaR = " << minMotherMatchDeltaR << endl;
	    
	    // reset cut!
	    // so we will consider all mothers again during next loop
	    minMotherMatchDeltaR = 1000000;
	    
	    // index could be > 0 and only one mother on next match and could be beam particle with very high deltaR
	    // so reset index just to be safe
	    matchMotherIndex = 0;
	    
	  } // end while loop through mothers
	  
	  if (isHadronOrHadronMother) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kHadronMotherMatch;
	  }

	  if (!isHadronOrHadronMother && photonMatch_finalStateElectronPair) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kElectronPairMatch;
	    // what to store?
	  }
	  
	  if (!isHadronOrHadronMother && !photonMatch_finalStateElectronPair) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kNoMatchType;
	    // store traced back q or g, or store final state match?
	  }
	  
	  cout << "Is photon mother: " << isPhotonMother << endl;
	  cout << "Is hadron or hadron mother: " << isHadronOrHadronMother << endl;
	  
	} // end if NOT a final state photon match
	
	
      } // end if final state match
      
      // **************************************************************************************************************************
      // no final state match BUT gen particle match
      if (!photonMatch_finalState && photonMatch_genParticles) {
	cout << "No final state match in DeltaR <= " << minDeltaR_finalState << endl;
	cout << "GenParticle match." << endl;
	cout << "GenParticle PhotonMatch    : Status = " << photonMatch_genParticles->status()  << "; ID = " << photonMatch_genParticles->pdgId() << "; pt = "
	     << photonMatch_genParticles->pt() << "; eta = " << photonMatch_genParticles->eta() << "; phi = " << photonMatch_genParticles->phi()  << "; deltaR = " << minDeltaR_genParticles << endl;
	
	fPhotonGenMatchInfo.deltaR_match = minDeltaR_genParticles;

	// --------------------------------------------------------------------------------------------------------------------------
	// since no final state match, investigate daughters

	// starting particle to determine daughters from
	const reco::GenParticle *matchedDaughter = &(*photonMatch_genParticles);
	
	// consider all daughters when tying to find best daughter (no deltaR cut)
	double minDaughterMatchDeltaR = 1000000;
	// store index of best daughter
	int matchDaughterIndex = 0;

	// loop through all daughters until no daughter exists
	// daughter constructor requires an argument
	while ((reco::GenParticle *)matchedDaughter->daughter(0)) {
	  
	  // loop through all daughters and keep index of best deltaR match
	  for (unsigned int j=0; j < matchedDaughter->numberOfDaughters(); j++) {
	    
	    // calculate deltaR between particle and daughter
	    double deltaR = reco::deltaR(matchedDaughter->eta(),matchedDaughter->phi(),matchedDaughter->daughter(j)->eta(),matchedDaughter->daughter(j)->phi());
	    
	    // print each daughter
	    cout << "\t           Daughter " << j << ": Status = " << matchedDaughter->daughter(j)->status()  << "; ID = " << matchedDaughter->daughter(j)->pdgId() << "; pt = "
		 << matchedDaughter->daughter(j)->pt() << "; eta = " << matchedDaughter->daughter(j)->eta() << "; phi = " << matchedDaughter->daughter(j)->phi()  << "; deltaR = " << deltaR << endl;
	    
	    // if current deltaR is smallest, save index
	    if (deltaR < minDaughterMatchDeltaR) {
	      minDaughterMatchDeltaR = deltaR;
	      matchDaughterIndex = j;
	    }
	    
	  } // end for loop through daughters
	  
	  // matched particle now becomes best daughter
	  matchedDaughter = (reco::GenParticle *) matchedDaughter->daughter(matchDaughterIndex);
	  
	  // print best daughter match
	  cout << "FinalState Matched DAUGHTER :" << matchDaughterIndex << "Status = " << matchedDaughter->status()  << "; ID = " << matchedDaughter->pdgId() << "; pt = "
	       << matchedDaughter->pt() << "; eta = " << matchedDaughter->eta() << "; phi = " << matchedDaughter->phi()  << "; deltaR = " << minDaughterMatchDeltaR << endl;
	  
	  // reset cut!
	  // so we will consider all daughters again during next loop
	  minDaughterMatchDeltaR = 1000000;
	  
	  // index could be > 0 and only one daughter on next match and could be beam particle with very high deltaR
	  // so reset index just to be safe
	  matchDaughterIndex = 0;
	} // end while loop through daughters
	
	// store final daugher
	photonMatch = &(*matchedDaughter);

	// if genParticle photon match
	if (photonMatch_genParticles->pdgId() == 22) {
	  // count number of gen particles photon matches according to matchCategory
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kGenParticlePhotonMatch;
	} // end if genParticle photon match

	// if genParticle non-photon match
	if (photonMatch_genParticles->pdgId() != 22) {
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kGenParticleNonPhotonMatch;
	} // end if genParticle non-photon match
	
      } // end if no final state match, but gen particle match
      
      // **************************************************************************************************************************
      // no final state match AND no gen paticle match
      if (!photonMatch_finalState && !photonMatch_genParticles) {
	cout << "No photon match in final state with DeltaR <= " << minDeltaR_finalState << ", or among all gen particles with DeltaR <= " << minDeltaR_genParticles << endl;
	
	// count number according to matchCategory
	fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kNoMatchCategory;
	
      } // end if no final state match, or gen particle match

      cout << "Match category: " << fPhotonGenMatchInfo.matchCategory << ", and match type: " << fPhotonGenMatchInfo.matchType << endl;
      cout << "DeltaR match  : " << fPhotonGenMatchInfo.deltaR_match << endl;
      cout << "DeltaR FSR    : " << fPhotonGenMatchInfo.deltaR_FSR << endl;

      // ===============================
      // fill photon info into fTreeFake

      // fill photon saturation
      fPhotonMatchInfo.isSaturated = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
      //cout << "isSat: " << fPhotonMatchInfo.isSaturated << endl;
      
      // if photon match, print filled match and store info
      if (photonMatch) {
	cout << "Filled gen particle PhotonMatch: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId() << "; pt = "
	     << photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi() << endl;
	
	// fill photonMatch genParticle info
	ExoDiPhotons::FillGenParticleInfo(fPhotonGenMatchInfo,photonMatch);
      } // end if photonMatch
      
      // fill photon info
      ExoDiPhotons::FillBasicPhotonInfo(fPhotonMatchInfo, &(*pho));
      ExoDiPhotons::FillPhotonIDInfo(fPhotonMatchInfo, &(*pho), rho_, fPhotonMatchInfo.isSaturated);
      
      // fill EGM ID info
      ExoDiPhotons::FillPhotonEGMidInfo(fPhotonMatchInfo, &(*pho), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
      fPhotonMatchInfo.passEGMLooseID  = (*loose_id_decisions)[pho];
      fPhotonMatchInfo.passEGMMediumID = (*medium_id_decisions)[pho];
      fPhotonMatchInfo.passEGMTightID  = (*tight_id_decisions)[pho];
      
      // fill our tree
      //if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) &&
      //ExoDiPhotons::passChargedHadronCut(&(*pho)) )
      fTreeFake->Fill();
      
    } // end if numerator photon
    //else cout << "Photon not a numerator object!" << endl;
    
  } // end of photon loop
  
  cout << endl;
  
#ifdef THIS_IS_AN_EVENT_EXAMPLE
  Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
ExoDiPhotonMCFakeRateClosureTestAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExoDiPhotonMCFakeRateClosureTestAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ExoDiPhotonMCFakeRateClosureTestAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ExoDiPhotonMCFakeRateClosureTestAnalyzer);
