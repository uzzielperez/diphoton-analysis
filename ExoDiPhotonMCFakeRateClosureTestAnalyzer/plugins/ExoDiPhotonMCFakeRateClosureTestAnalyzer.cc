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
// Original Author:  andrew buccilli
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

  // photons
  ExoDiPhotons::photonInfo_t fPhotonInfo;

  // jets
  ExoDiPhotons::jetInfo_t fJetInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;

  // gen event info token
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken_;

  // genParticles
  ExoDiPhotons::genParticleInfo_t fGenParticleInfo;
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
  fTree->Branch("PhotonGenMatch",&fGenParticleInfo,ExoDiPhotons::genParticleBranchDefString.c_str());
  
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
  
  cout <<  "Run: " << iEvent.id().run() << ", LS: " <<  iEvent.id().luminosityBlock() << ", Event: " << iEvent.id().event() << endl;

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
  
  // ===
  // RHO
  // ===
  
  // Get rho
  edm::Handle< double > rhoH;
  iEvent.getByToken(rhoToken_,rhoH);
  rho_ = *rhoH;
  
  cout << "rho: " << rho_ << endl;

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

  ExoDiPhotons::InitGenParticleInfo(fGenParticleInfo);
  
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
  
  // get photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);
  
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i) {
    const auto pho = photons->ptrAt(i);
    
    // print photon info
    cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;
    
    // deltaR cut
    double minDeltaR       = 0.2;
    double minDeltaRfromHP = 0.1;
    
    // no match when starting loop
    const reco::GenParticle *photonMatch       = NULL;
    const reco::GenParticle *photonMatchFromHP = NULL;
    
    // loop through genParticles to find photon matches
    //for (edm::View<reco::GenParticle>::const_iterator gen = genParticles->begin(); gen != genParticles->end(); ++gen) {
    for (size_t i = 0; i < genParticles->size(); ++i) {
      const auto gen = genParticles->ptrAt(i);
      
      // calculate deltaR for current genParticle
      double deltaR = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
      
      // find best match
      if (deltaR < minDeltaR) {
	//cout << "GenParticle match: Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
	//<< gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; deltaR = " << deltaR << endl;
	minDeltaR = deltaR;
	photonMatch = &(*gen);
      }
      
      // find best final state from hard process match
      if (gen->fromHardProcessFinalState()) {
	double deltaRfromHP = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
	if (deltaRfromHP < minDeltaRfromHP) {
	  minDeltaRfromHP = deltaRfromHP;
	  photonMatchFromHP = &(*gen);
	}
      }
      
    } // end of genParticle loop

    // consider all mothers when matching (no deltaR cut)
    double minMotherMatchDeltaR = 10000;
    int matchMotherIndex = 0;
    
    if (photonMatch) {
      cout << "PhotonMatch START: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId() << "; pt = "
	   << photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi()  << "; deltaR = " << minDeltaR << endl;
      
      // if there is a best final-state-from-hard-interaction match in deltaR <= 0.1, start from this instead of best overall match 
      if (photonMatchFromHP) {
	photonMatch = &(*photonMatchFromHP);
	cout << "PhotonMatch RESTART: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId() << "; pt = "
	     << photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi()  << "; deltaR = " << minDeltaRfromHP << endl;
      }
      
      // loop over all mothers to find best match in deltaR. this is consider the true mother
      // do this for each mother until its mother has pT = 0 (from hard interaction)
      // photonMatch will always have at least one mother
      while (photonMatch->mother()->pt() != 0) {
	for (unsigned int j=0; j < photonMatch->numberOfMothers(); j++) {
	  double deltaR = reco::deltaR(photonMatch->eta(),photonMatch->phi(),photonMatch->mother(j)->eta(),photonMatch->mother(j)->phi());
	  if (deltaR < minMotherMatchDeltaR) {
	    minMotherMatchDeltaR = deltaR;
	    matchMotherIndex = j;
	  }
	}
	photonMatch = (reco::GenParticle *) photonMatch->mother(matchMotherIndex);
	cout << "PhotonMatch WHILE: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId() << "; pt = "
	     << photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi()  << "; deltaR = " << minMotherMatchDeltaR << endl;
	// reset cut! 
	minMotherMatchDeltaR = 10000;
      }
      // this is our hard interaction match, with mother having pT = 0 (interacting parton)
      cout << "PhotonMatch END: Status = " << photonMatch->status()  << "; ID = " << photonMatch->pdgId() << "; pt = "
	   << photonMatch->pt() << "; eta = " << photonMatch->eta() << "; phi = " << photonMatch->phi()  << endl;

      // print photonMatch mother
      cout << "PhotonMatch Mother: Status = " << photonMatch->mother()->status()  << "; ID = " << photonMatch->mother()->pdgId() << "; pt = "
	   << photonMatch->mother()->pt() << "; eta = " << photonMatch->mother()->eta() << "; phi = " << photonMatch->mother()->phi()  << endl;

      // only fill tree if photon is matched to hard interaction particle, but not a photon
      if (photonMatch->pdgId() != 22) {
	// fill photon saturation
	fPhotonInfo.isSaturated = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
	cout << "isSat: " << fPhotonInfo.isSaturated << endl;
	
	// fill photonMatch genParticle info
	ExoDiPhotons::FillGenParticleInfo(fGenParticleInfo,photonMatch);
	
	// fill photon info
	ExoDiPhotons::FillBasicPhotonInfo(fPhotonInfo, &(*pho));
	ExoDiPhotons::FillPhotonIDInfo(fPhotonInfo, &(*pho), rho_, fPhotonInfo.isSaturated);
	
	// fill EGM ID info
	ExoDiPhotons::FillPhotonEGMidInfo(fPhotonInfo, &(*pho), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
	fPhotonInfo.passEGMLooseID  = (*loose_id_decisions)[pho];
	fPhotonInfo.passEGMMediumID = (*medium_id_decisions)[pho];
	fPhotonInfo.passEGMTightID  = (*tight_id_decisions)[pho];
      
	// fill our tree
	if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) ) fTree->Fill();
      }
      
    } // end if photonMatch
    else cout << "No photon match in DeltaR <= " << minDeltaR << endl;
    
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
