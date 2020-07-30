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
#include "diphoton-analysis/CommonClasses/interface/TriggerInfo.h"
#include "diphoton-analysis/CommonClasses/interface/JetInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonID.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonInfo.h"
#include "diphoton-analysis/CommonClasses/interface/GenParticleInfo.h"
#include "diphoton-analysis/CommonClasses/interface/VertexInfo.h"

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

  // Trigger decisions token
  edm::EDGetToken triggerDecisionToken_;

  // Trigger prescales token
  edm::EDGetToken prescalesToken_;

  // vertex token
  edm::EDGetTokenT<reco::VertexCollection> verticesToken_;
  
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

  // output file name
  TString outputFile_;
  
  // number of events in sample
  uint32_t nEventsSample_;
  
  // trees
  TTree *fTree;
  TTree *fTreeFake;
  
  // photons
  ExoDiPhotons::photonInfo_t fPhotonInfo;
  ExoDiPhotons::photonInfo_t fPhotonMatchInfo;
  
  // jets
  ExoDiPhotons::jetInfo_t fJetInfo;

  // triggers
  ExoDiPhotons::triggerInfo_t fTriggerBitInfo;
  ExoDiPhotons::triggerInfo_t fTriggerPrescaleInfo;

  // vertex collection
  ExoDiPhotons::vertexCollInfo_t fVertexCollInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;

  // gen event info token
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken_;

  // genParticles
  ExoDiPhotons::genParticleInfo_t fPhotonGenMatchInfo;
  ExoDiPhotons::genParticleInfo_t fPhotonGenParentInfo;

  // all final state gen particle info in cone cut
  std::vector<double> gen_match_pt;
  std::vector<double> gen_match_eta;
  std::vector<double> gen_match_phi;
  std::vector<double> gen_match_pdgId;
  std::vector<double> gen_match_deltaR;
  std::vector<double> gen_match_pt_diff;
  std::vector<double> gen_match_num_mothers;
  std::vector<double> gen_match_mother_pt;
  std::vector<double> gen_match_mother_eta;
  std::vector<double> gen_match_mother_phi;
  std::vector<double> gen_match_mother_status;
  std::vector<double> gen_match_mother_pdgId;

  // check if reco photon is matched to a real template photon
  int is_real_template_photon = 0;
  
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
    outputFile_(TString(iConfig.getParameter<std::string>("outputFile"))),
    nEventsSample_(iConfig.getParameter<uint32_t>("nEventsSample")),
    genInfoToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("genInfo")))
{
  //now do what ever initialization is needed
  usesResource("TFileService");
  
  edm::Service<TFileService> fs;
  
  // tree for objects passing numerator or denominator definitions
  fTree = fs->make<TTree>("fTree","PhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTree->Branch("Photon",&fPhotonInfo,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("PhotonRealMatch",&is_real_template_photon,"is_real_template_photon/I");
  fTree->Branch("VertexCollInfo.vx","std::vector<double>",&fVertexCollInfo.vx);
  fTree->Branch("VertexCollInfo.vy","std::vector<double>",&fVertexCollInfo.vy);
  fTree->Branch("VertexCollInfo.vz","std::vector<double>",&fVertexCollInfo.vz);
  fTree->Branch("VertexCollInfo.vxError","std::vector<double>",&fVertexCollInfo.vxError);
  fTree->Branch("VertexCollInfo.vyError","std::vector<double>",&fVertexCollInfo.vyError);
  fTree->Branch("VertexCollInfo.vzError","std::vector<double>",&fVertexCollInfo.vzError);
  fTree->Branch("VertexCollInfo.ndof","std::vector<double>",&fVertexCollInfo.ndof);
  fTree->Branch("VertexCollInfo.d0","std::vector<double>",&fVertexCollInfo.d0);
  fTree->Branch("VertexCollInfo.nTracks","std::vector<int>",&fVertexCollInfo.nTracks);
  fTree->Branch("VertexCollInfo.isFake","std::vector<int>",&fVertexCollInfo.isFake);
  
  // tree for photon objects matched to fake genPhotons
  fTreeFake = fs->make<TTree>("fTreeFake","FakePhotonTree");
  fTreeFake->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTreeFake->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTreeFake->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTreeFake->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTreeFake->Branch("Photon",&fPhotonMatchInfo,ExoDiPhotons::photonBranchDefString.c_str());
  fTreeFake->Branch("PhotonGenMatch",&fPhotonGenMatchInfo,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTreeFake->Branch("PhotonGenParent",&fPhotonGenParentInfo,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTreeFake->Branch("GenMatchPt",&gen_match_pt);
  fTreeFake->Branch("GenMatchEta",&gen_match_eta);
  fTreeFake->Branch("GenMatchPhi",&gen_match_phi);
  fTreeFake->Branch("GenMatchPdgId",&gen_match_pdgId);
  fTreeFake->Branch("GenMatchDeltaR",&gen_match_deltaR);
  fTreeFake->Branch("GenMatchPtDiff",&gen_match_pt_diff);
  fTreeFake->Branch("GenMatchNumMothers",&gen_match_num_mothers);
  fTreeFake->Branch("GenMatchMotherPt",&gen_match_mother_pt);
  fTreeFake->Branch("GenMatchMotherEta",&gen_match_mother_eta);
  fTreeFake->Branch("GenMatchMotherPhi",&gen_match_mother_phi);
  fTreeFake->Branch("GenMatchMotherStatus",&gen_match_mother_status);
  fTreeFake->Branch("GenMatchMotherPdgId",&gen_match_mother_pdgId);
  
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

  // Trigger decisions
  triggerDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","","HLT") );

  // trigger prescales
  prescalesToken_ = consumes<pat::PackedTriggerPrescales>( edm::InputTag("patTrigger","","PAT") );

  // vertices
  verticesToken_ = consumes<reco::VertexCollection>( edm::InputTag("offlineSlimmedPrimaryVertices") );
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
  ExoDiPhotons::FillEventWeights(fEventInfo, outputFile_, nEventsSample_);
  
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
  for (unsigned int i=0; i < trigNames.size(); i++) {
    std::string tempName = trigNames.at(i);
    if (tempName == "Flag_eeBadScFilter") {
      EEBadScFilterNum = i;
      break;
    }
  }
  if (EEBadScFilterNum < 0) throw cms::Exception("FilterDecisionInfo") << "Cannot find Flag_eeBadScFilter in the filter decision object!! This must be investigated!!!";
  
  bool passEEBadScFilter = filterResults->accept(EEBadScFilterNum);

  // Go to next photon if this filter is not passed
  if (!passEEBadScFilter) {
    cout << "Event did not pass the EE Bad Supercrystal Filter, skip it!" << endl;
    return;
  }

  // =====================
  // TRIGGER DECISION INFO
  // =====================

  edm::Handle<edm::TriggerResults> triggerHandle;
  iEvent.getByToken(triggerDecisionToken_,triggerHandle);
  const edm::TriggerResults* triggerResults = triggerHandle.product();

  edm::Handle<pat::PackedTriggerPrescales> prescalesHandle;
  iEvent.getByToken(prescalesToken_,prescalesHandle);
  const pat::PackedTriggerPrescales* prescales = prescalesHandle.product();

  ExoDiPhotons::FillTriggerBits(fTriggerBitInfo, triggerResults, iEvent); // fill trigger bits into trigger bit branch
  ExoDiPhotons::FillTriggerPrescales(fTriggerPrescaleInfo, triggerResults, prescales, iEvent); // fill trigger prescale info in trigger prescale branch

  // ========
  // VERTICES
  // ========

  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByToken(verticesToken_,vertices);
  const reco::VertexCollection* vtxColl = vertices.product();
  ExoDiPhotons::FillVertexCollInfo(fVertexCollInfo,vtxColl);
  
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
  ExoDiPhotons::InitGenParticleInfo(fPhotonGenParentInfo);
  
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
    
    if (pho->pt() < 50.) continue;

    // reset matching value
    is_real_template_photon = 0;
    
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
    // this method of retrieving EGM decisions is not currently supported
    // fPhotonInfo.passEGMLooseID  = (*loose_id_decisions)[pho];
    // fPhotonInfo.passEGMMediumID = (*medium_id_decisions)[pho];
    // fPhotonInfo.passEGMTightID  = (*tight_id_decisions)[pho];

    fPhotonInfo.passEGMLooseID  = 0;
    fPhotonInfo.passEGMMediumID = 0;
    fPhotonInfo.passEGMTightID  = 0;

    // only match to "numerator" photons
    //if ( !(ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) &&
    //ExoDiPhotons::passChargedHadronCut(&(*pho))) ) {
    //cout << "Photon not a numerator object, will not proceed with matching." << endl;
    //continue;
    //}
    //if (ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) && (5.0 < pho->chargedHadronIso()) && (pho->chargedHadronIso() < 10.) ) {
    //cout << "Sideband photon!" << endl;
    if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) ) {
      cout << "Numerator 'candidate' photon!" << endl;
      cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi()
	   << "; sc_eta = " << pho->superCluster()->eta() << "; sieie = " << pho->full5x5_sigmaIetaIeta()
	   << "; pass sieie cut = " << ExoDiPhotons::passSigmaIetaIetaCut(&(*pho),fPhotonInfo.isSaturated)
	   << "; pass CHIso cut = " << ExoDiPhotons::passChargedHadronCut(&(*pho))
	   << endl;
      
      // deltaR cut
      const double deltaR_cut       = 0.1;
      double minDeltaR_finalState   = deltaR_cut;
      double minDeltaR_realTemplate = deltaR_cut;
      double minDeltaR_genParticles = 0.3;
      
      // no match when starting loop
      const reco::GenParticle *photonMatch_finalState   = NULL;
      const reco::GenParticle *photonMatch_realTemplate = NULL;
      const reco::GenParticle *photonMatch_genParticles = NULL;
      
      // loop through genParticles to find photon matches
      //for (edm::View<reco::GenParticle>::const_iterator gen = genParticles->begin(); gen != genParticles->end(); ++gen) {
      for (size_t i = 0; i < genParticles->size(); ++i) {
	const auto gen = genParticles->ptrAt(i);

	// calculate deltaR for current genParticle
	double deltaR = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
	
	// print all gen particles considered part of the hard interaction
	if (gen->isHardProcess()) {
	  cout << "GenParticle isHardProcess(): Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
	       << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; deltaR = " << deltaR << endl;
	}

	// aviod low reco/gen matches in pT (at least 10% agreement)
	//if (fabs(1 - pho->pt()/gen->pt()) > 0.90) continue;
	
	// check for best match among all gen particles (just for curiosity's sake)
	if (deltaR <= minDeltaR_genParticles) {
	  minDeltaR_genParticles = deltaR;
	  photonMatch_genParticles = &(*gen);
	}
	
	// check for best match among final state particles
	if (gen->status() == 1) {
	  cout << "GenParticle final state: Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
	       << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; deltaR = " << deltaR << endl;
	  if (deltaR <= minDeltaR_finalState) {
	    minDeltaR_finalState = deltaR;
	    photonMatch_finalState = &(*gen);
	  }
	  // print mothers
	  // for (unsigned int i = 0; i < gen->numberOfMothers(); ++i) {
	  //   const auto mother = gen->mother(i);
	  //   cout << "\t\t Mother " << i << ": Status = " << mother->status() << ", ID = " << mother->pdgId() << ", pt = " << mother->pt()
	  // 	 << ", eta = " << mother->eta() << ", phi = " << mother->phi() << endl;
	  // }
	}
	
	// check for best match among final state photons //with at least 60% pT gen/reco match (real template selection)
	if (gen->status() == 1 && gen->pdgId() == 22) { //&& fabs(1 - pho->pt()/gen->pt()) < 0.40) {
	  if (deltaR <= minDeltaR_realTemplate) {
	    minDeltaR_realTemplate = deltaR;
	    photonMatch_realTemplate = &(*gen);
	  }
	}
	
      } // end for genParticle loop
      
      // if best final state match is an electron, check for electron pair
      // -----------------------------------------------------------------
      // increase final state DeltaR cut to allow for best final state electron close to cut and pair outside of cut
      double minDeltaR_finalStateElectornPair = 0.5;
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

      // clear matching vectors before we consider matching
      gen_match_pt.clear();
      gen_match_eta.clear();
      gen_match_phi.clear();
      gen_match_pdgId.clear();
      gen_match_deltaR.clear();
      gen_match_pt_diff.clear();
      gen_match_num_mothers.clear();
      gen_match_mother_pt.clear();
      gen_match_mother_eta.clear();
      gen_match_mother_phi.clear();
      gen_match_mother_status.clear();
      gen_match_mother_pdgId.clear();
      
      // photon's gen particle match to be filled into tree
      // either photonMatch_finalState or photonMatch_genParticles
      const reco::GenParticle *photonMatch = NULL;

      // photonMatch's parent
      // quark jet, gluon jet, or photon
      // or colliding proton if it's the photon's only mother
      const reco::GenParticle *photonParent = NULL;
      
      // **************************************************************************************************************************
      // first check for final state real template photons
      bool is_match_real_template_photon = false;
      if (photonMatch_realTemplate) {
	cout << "Real Template match." << endl;
	//cout << "RealTemplate PhotonMatch   : Status = " << photonMatch_realTemplate->status()  << "; ID = " << photonMatch_realTemplate->pdgId() << "; pt = "
	//   << photonMatch_realTemplate->pt() << "; eta = " << photonMatch_realTemplate->eta() << "; phi = " << photonMatch_realTemplate->phi()  << "; deltaR = " << minDeltaR_realTemplate << endl;

	// particle stored into tree
	photonMatch = &(*photonMatch_realTemplate);
	      	
	// store DeltaR between photon and final state match
	fPhotonGenMatchInfo.deltaR_match = minDeltaR_realTemplate;
	
	// pT difference between final state match and reco photon
	fPhotonGenMatchInfo.ptDiff_match = fabs(pho->pt() - photonMatch_realTemplate->pt())/pho->pt(); 
	
	// particle whose mothers will looped through
	const reco::GenParticle *matchedMother = &(*photonMatch_realTemplate);

	// first check if final state gen. match is a real photon using same selection that is done for real templates
	
	cout << "First checking if final state gen. photon match is a real template photon." << endl;

	// count the number of photon matches according to matchCategory
	fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kFinalStatePhotonMatch;
	  
	// consider all mothers when matching (no deltaR cut)
	double minMotherMatchDeltaR = 10000;
	int matchedMotherIndex = 0;
	
	// check if each mother is a photon
	bool is_mother_photon = true;
	
	cout << "PhotonMatch START   : Status = " << matchedMother->status()  << "; ID = " << matchedMother->pdgId() << "; pt = "
	     << matchedMother->pt() << "; eta = " << matchedMother->eta() << "; phi = " << matchedMother->phi()  << "; deltaR = " << minDeltaR_realTemplate << endl;

	bool photon_check = true;
      
	// trace back match to hard interaction proton by finding mothers
	// each mother may have multiple mothers, so sole, "true" mother is best dR match among all mothers
	while (matchedMother->mother()) {
	  for (unsigned int j = 0; j < matchedMother->numberOfMothers(); j++) {
	    double deltaR = reco::deltaR(matchedMother->eta(),matchedMother->phi(),matchedMother->mother(j)->eta(),matchedMother->mother(j)->phi());
	    cout << "\t    Mother " << j << ": Status = " << matchedMother->mother(j)->status()  << "; ID = " << matchedMother->mother(j)->pdgId() << "; pt = "
		 << matchedMother->mother(j)->pt() << "; eta = " << matchedMother->mother(j)->eta() << "; phi = " << matchedMother->mother(j)->phi()  << "; deltaR = " << deltaR << endl;
	    if (deltaR < minMotherMatchDeltaR) {
	      minMotherMatchDeltaR = deltaR;
	      matchedMotherIndex = j;
	    }
	  }
	  // select best mother as sole mother
	  matchedMother = (reco::GenParticle *) matchedMother->mother(matchedMotherIndex);
	  // stop checking for photon history when the interacting (incoming) parton is found
	  if ((matchedMother->pdgId() == 21 || std::abs(matchedMother->pdgId() < 9)) && matchedMother->pt() == 0) photon_check = false;
	  // check if each mother in photon's history is a photon until the incoming, interacting parton is found
	  if (photon_check && matchedMother->pdgId() != 22) is_mother_photon = false;
	  // print each mother
	  cout << "PhotonMatch MOTHER "<< matchedMotherIndex <<": Status = " << matchedMother->status()  << "; ID = " << matchedMother->pdgId() << "; pt = "
	       << matchedMother->pt() << "; eta = " << matchedMother->eta() << "; phi = " << matchedMother->phi()  << "; deltaR = " << minMotherMatchDeltaR << endl;
	  // reset cut! (and index to be safe)
	  minMotherMatchDeltaR = 10000;
	  matchedMotherIndex = 0;
	} // end while loop through mothers
	  
	// if any mother is not a photon, then don't fill the match
	if (!is_mother_photon) cout << "Not a real template photon." << endl;
	  
	// only mark if every mother is a photon; in particular, the hard interatciton particle is a photon
	if (is_mother_photon) {
	  cout << "Found real template photon." << endl;
	  is_match_real_template_photon = true;
	  fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kRealTemplatePhoton;
	}

      } // end check for real tempalate
      
      // **************************************************************************************************************************
      // first consider final state matches that aren't real template photons
      if (photonMatch_finalState && !is_match_real_template_photon) {

	// if photonMatch_realTemplate was found however, then this match supersedes photonMatch_finalState
	// if (photonMatch_realTemplate) {
	//   photonMatch_finalState = &(*photonMatch_realTemplate);
	//   minDeltaR_finalState = minDeltaR_realTemplate;
	// }
	
	cout << "Final state match." << endl;
	cout << "FinalState PhotonMatch     : Status = " << photonMatch_finalState->status()  << "; ID = " << photonMatch_finalState->pdgId() << "; pt = "
	     << photonMatch_finalState->pt() << "; eta = " << photonMatch_finalState->eta() << "; phi = " << photonMatch_finalState->phi()  << "; deltaR = " << minDeltaR_finalState << endl;

	// particle stored into tree
	photonMatch = &(*photonMatch_finalState);
	      	
	// store DeltaR between photon and final state match
	fPhotonGenMatchInfo.deltaR_match = minDeltaR_finalState;
	
	// pT difference between final state match and reco photon
	fPhotonGenMatchInfo.ptDiff_match = fabs(pho->pt() - photonMatch_finalState->pt())/pho->pt(); 
	
	// particle whose mothers will looped through
	const reco::GenParticle *matchedMother = &(*photonMatch_finalState);
	
	// ------------------------------------------------------------------------------------------------------------------------
	// now consider final state photon matches
	if (photonMatch_finalState->pdgId() == 22) {
	  
	  // count the number of photon matches according to matchCategory
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kFinalStatePhotonMatch;
	  
	  // set to false after finidng first mother
	  bool isFirstMother = true;
	  // set to true if any mother is a hadron (interacting proton is not considered as true)
	  bool isHadronMother = false;
	  // is photon's first mother a quark
	  bool isQuarkFirstMother = false;
	  // is the photon radiated directly from the proton (with the proton being its only mother)
	  bool isISRfromProton = false;
	  // check if photon's first mother is a gluon (photon fragmentation)
	  bool isGluonMotherPhotonFrag = false;
	  // flag if any of the daughters of the photon's first mother are a hadron
	  bool isAnyFirstMotherDaughterHadron = false;
	  // identify first time a mother in family tree is a quark or gluon
	  bool isMotherQuarkGluon = false;
	  
	  // find first mother that's not a photon
	  bool isPhotonChain = true;
	  
	  // consider all mothers when tying to find best mother (no deltaR cut)
	  double minMotherMatchDeltaR = 1000000;
	  // store index of best mother
	  int matchMotherIndex = 0;

	  // loop through all mothers until no mothers exist (will trace back to colliding proton)
	  while (matchedMother->mother()) {
	    
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
	    
	    // matched particle now becomes best mother
	    matchedMother = (reco::GenParticle *) matchedMother->mother(matchMotherIndex);

 	    if (!isMotherQuarkGluon && (matchedMother->pdgId() == 21 || (-9 < matchedMother->pdgId() && matchedMother->pdgId() < 9))) {
	      photonParent = &(*matchedMother);
	      isMotherQuarkGluon = true;
	    }

	    // check until first mother is not a photon
	    if (isPhotonChain && matchedMother->pdgId() != 22) {
	      isPhotonChain = false;
	    }
	    
	    // print best mother's info
	    cout << "FinalState Matched MOTHER " << matchMotherIndex << ": Status = " << matchedMother->status()  << "; ID = " << matchedMother->pdgId() << "; pt = "
		 << matchedMother->pt() << "; eta = " << matchedMother->eta() << "; phi = " << matchedMother->phi()  << "; deltaR = " << minMotherMatchDeltaR << endl;
	    
	    // make decisions based on photon's first mother
	    if (!isPhotonChain && isFirstMother) {
	      // store info
	      fPhotonGenMatchInfo.nPhotonMotherDaughters = matchedMother->numberOfDaughters();
	      fPhotonGenMatchInfo.deltaR_matchDau = reco::deltaR(matchedMother->eta(),matchedMother->phi(),photonMatch_finalState->eta(),photonMatch_finalState->phi());

	      // check if first non-photon mother is a hadron (colliding proton not considered true)
	      if (fabs(matchedMother->pdgId()) > 99 && matchedMother->pt() != 0.) {
		isHadronMother = true;
	      }
	      
	      // if photon is radiated from colliding proton, then ISR
	      if (matchedMother->pdgId()==2212 && matchedMother->pt()==0) {
		isISRfromProton = true;
		photonParent = &(*matchedMother);
	      }
	      // check if first mother is a gluon
	      if (matchedMother->pdgId() == 21) {
		isGluonMotherPhotonFrag = true;
	      }
	      // check if first mother is a quark
	      if (-9 < matchedMother->pdgId() && matchedMother->pdgId() < 9) {
		isQuarkFirstMother = true;
	      }
	      // print daughters of photon's first mother
	      cout << "\t\t           Printing daughters of photon's first mother" << endl;
	      // check for hadron among first daughters
	      bool checkForFirstMotherDaughterHadron = true;
	      // particle to check daughters of
	      const reco::GenParticle *matchedDaughter = &(*matchedMother);
	      // consider all daughters when tying to find best daughter (no deltaR cut)
	      double minDaughterMatchDeltaR = 1000000;
	      // store index of best daughter
	      int matchDaughterIndex = 0;
	      // loop through all daughters until no daughter exists
	      // daughter constructor requires an argument
	      while ((reco::GenParticle *)matchedDaughter->daughter(0)) {
		// loop through all daughters and keep index of best deltaR match
		for (unsigned int j=0; j < matchedDaughter->numberOfDaughters(); j++) {
		  // hadron status for each daughter
		  bool isHadron = false;
		  // check if daughter is a hadron
		  if (fabs(matchedDaughter->daughter(j)->pdgId()) > 99) {
		    isHadron = true;
		    if (checkForFirstMotherDaughterHadron) isAnyFirstMotherDaughterHadron = true;
		  }
		  // calculate deltaR between particle and daughter
		  double deltaR = reco::deltaR(matchedDaughter->eta(),matchedDaughter->phi(),matchedDaughter->daughter(j)->eta(),matchedDaughter->daughter(j)->phi());
		  // print each daughter
		  cout << "\t\t\t           Daughter " << j << ": Status = " << matchedDaughter->daughter(j)->status()  << "; ID = " << matchedDaughter->daughter(j)->pdgId() << "; pt = "
		       << matchedDaughter->daughter(j)->pt() << "; eta = " << matchedDaughter->daughter(j)->eta() << "; phi = " << matchedDaughter->daughter(j)->phi()
		       << "; deltaR = " << deltaR << "; isHadron = " << isHadron << endl;
		  // if current deltaR is smallest, save index
		  if (deltaR < minDaughterMatchDeltaR) {
		    minDaughterMatchDeltaR = deltaR;
		    matchDaughterIndex = j;
		  }
		} // end for loop through daughters
		// matched particle now becomes best daughter
		matchedDaughter = (reco::GenParticle *) matchedDaughter->daughter(matchDaughterIndex);
		// print best daughter match
		cout << "\t\t           Selected DAUGHTER " << matchDaughterIndex << ": Status = " << matchedDaughter->status()  << "; ID = " << matchedDaughter->pdgId() << "; pt = "
		     << matchedDaughter->pt() << "; eta = " << matchedDaughter->eta() << "; phi = " << matchedDaughter->phi()  << "; deltaR = " << minDaughterMatchDeltaR << endl;
		// finished checking first daughter
		checkForFirstMotherDaughterHadron = false;
		// reset cut! so we will consider all daughters again during next loop
		minDaughterMatchDeltaR = 1000000;
		// index could be > 0 and only one daughter on next match and could be beam particle with very high deltaR
		// so reset index just to be safe
		matchDaughterIndex = 0;
	      } // end while loop through daughters
	      
	      // checked first mother, so set to false
	      isFirstMother = false;
	      
	    } // end if first mother    
	    
	    // reset cut! so we will consider all mothers again during next loop
	    minMotherMatchDeltaR = 1000000;
	    
	    // index could be > 0 and only one mother on next match and could be beam particle with very high deltaR
	    // so reset index just to be safe
	    matchMotherIndex = 0;
	  } // end while loop through mothers

	  // if photon has a hadron mother, look at other final state particles in same cone
	  if (isHadronMother) {
	    int nPho = 0;
	    double phoPtSum = 0;
	    cout << "Other final state gen particles with in cone of " << deltaR_cut << ":" << endl;
	    for (size_t i = 0; i < genParticles->size(); ++i) {
	      const auto gen = genParticles->ptrAt(i);
	      // calculate deltaR for current genParticle
	      double deltaR = reco::deltaR(pho->eta(),pho->phi(),gen->eta(),gen->phi());
	      // check for best match among final state particles
	      if (gen->status()==1 && deltaR <= deltaR_cut) {
		if (gen->pdgId() == 22) {
		  nPho++;
		  phoPtSum += gen->pt();
		}
		
		gen_match_pt.push_back         ( gen->pt()                           );
		gen_match_eta.push_back        ( gen->eta()                          );
		gen_match_phi.push_back        ( gen->phi()                          );		  
		gen_match_pdgId.push_back      ( gen->pdgId()                        );
		gen_match_deltaR.push_back     ( deltaR                              );
		gen_match_pt_diff.push_back    ( fabs(pho->pt()-gen->pt())/pho->pt() );
		gen_match_num_mothers.push_back( gen->numberOfMothers()              );
		
		cout << "Final state gen paticle: Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
		     << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi()  << "; pt diff (reco/gen) = "
		     << fabs(pho->pt()-gen->pt())/pho->pt() << "; deltaR = " << deltaR << endl;
		// TODO - select best mother as "mother"
		int mom_index = 0;
		double deltaR_mom_cut = 1000000;
		for (unsigned int i = 0; i < gen->numberOfMothers(); ++i) {
		  const auto mother = gen->mother(i);
		  
		  double deltaR_mom = reco::deltaR(gen->eta(),gen->phi(),mother->eta(),mother->phi());
		  
		  cout << "\t\t Mother " << i << ": Status = " << mother->status() << ", ID = " << mother->pdgId() << ", pt = " << mother->pt()
		       << ", eta = " << mother->eta() << ", phi = " << mother->phi() << "; deltaR = " << deltaR_mom << endl;

		  if (deltaR_mom < deltaR_mom_cut) {
		    deltaR_mom_cut = deltaR_mom;
		    mom_index = i;
		  } 
		}
		const auto mother = gen->mother(mom_index);
		gen_match_mother_pt.push_back    ( mother->pt()     );
		gen_match_mother_eta.push_back   ( mother->eta()    );
		gen_match_mother_phi.push_back   ( mother->phi()    );
		gen_match_mother_status.push_back( mother->status() );
		gen_match_mother_pdgId.push_back ( mother->pdgId()  );
		//mom_index = 0;
		//deltaR_mom_cut = 1000000;
	      } // end final state in dR cut
	    } // end for genParticle loop
	    cout << "Number of gen matches in cone of " << deltaR_cut << ": " << gen_match_pt.size() << endl;
	    for (std::vector<double>::iterator i = gen_match_pt.begin(); i != gen_match_pt.end(); ++i) {
	      auto pos = i - gen_match_pt.begin();
	      cout << "Match: " << pos << " pdgId: " << gen_match_pdgId.at(pos) << "; pt: " << gen_match_pt.at(pos) << endl;
	    }
	    cout << "Number of photons in cone of " << deltaR_cut << ": " << nPho << "; pt sum of these photons: " << phoPtSum
		 << "; pt diff (reco / pho sum): " << fabs(pho->pt()-phoPtSum)/pho->pt() << ". " << endl;
	  } // end isHadronMother
	  
	  // radiation if quark mother and no hadrons
	  bool isOtherPhotonRadiation = isQuarkFirstMother && !isAnyFirstMotherDaughterHadron;
	  // fragmentation if quark mother and at least one hadron
	  bool isOtherPhotonFragmentation = isQuarkFirstMother && isAnyFirstMotherDaughterHadron;
	  
	  // if photon has hadron mother
	  if (isHadronMother) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kHadronMother;
	  }
	  // if not hadron mother, should be one of these distinct processes (e.g., can't be FSR and ISR, or FSR and fragmentation)
	  if (!isHadronMother) {
	    if (isISRfromProton) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kISRfromProton;
	    }
	    if (isOtherPhotonRadiation) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kOtherPhotonRadiation;
	    }
	    if (isGluonMotherPhotonFrag) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kGluonMotherPhotonFrag;
	    }
	    if (isOtherPhotonFragmentation) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kOtherPhotonFragmentation;
	    }
	    if (!isISRfromProton && !isOtherPhotonRadiation  && !isGluonMotherPhotonFrag && !isOtherPhotonFragmentation) {
	      fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kNoMatchType;
	    }
	  } // end if not hadron mother
	  
	  cout << "Is hadron mother     : " << isHadronMother << endl;
	  cout << "Is quark first mother: " << isQuarkFirstMother << endl;
	  cout << "Is any daughter of first mother a hadron: " << isAnyFirstMotherDaughterHadron << endl;
	  cout << "Is ISR directly from proton      : " << isISRfromProton << endl;
	  cout << "Is other photon radiation        : " << isOtherPhotonRadiation << endl;
	  cout << "Is photon frag. from gluon mother: " << isGluonMotherPhotonFrag << endl;
	  cout << "Is other photon fragmentation    : " << isOtherPhotonFragmentation << endl;
	  cout << "Number of daughters from photon's first matched mother: " << fPhotonGenMatchInfo.nPhotonMotherDaughters << endl;
	} // end if final state photon match
	
	// ------------------------------------------------------------------------------------------------------------------------
	// if final state match is not a photon
	if (photonMatch_finalState->pdgId() != 22) {

	  // count number of non-photon final state matches according to matchCategory
	  fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kFinalStateNonPhotonMatch;

	  // flag if final state match is a hadron
	  bool isHadron = false;
	  // identify first time a mother in family tree is a quark or gluon
	  bool isMotherQuarkGluon = false;
	  
	  // consider all mothers when tying to find best mother (no deltaR cut)
	  double minMotherMatchDeltaR = 1000000;
	  // store index of best mother
	  int matchMotherIndex = 0;

	  // determine if final state match is hadron (colliding proton not considered)
	  if (fabs(matchedMother->pdgId()) > 99 && matchedMother->pt() != 0.) isHadron = true;
	  
	  // loop through all mothers
	  while (matchedMother->mother()) {

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
	    
	    // matched particle now becomes best mother
	    matchedMother = (reco::GenParticle *) matchedMother->mother(matchMotherIndex);

	    if (!isMotherQuarkGluon && (matchedMother->pdgId() == 21 || (-9 < matchedMother->pdgId() && matchedMother->pdgId() < 9))) {
	      photonParent = &(*matchedMother);
	      isMotherQuarkGluon = true;
	    }
	    
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

	  if (isHadron) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kHadronMother;
	  }
	  if (!isHadron && photonMatch_finalStateElectronPair) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kElectronPairMatch;
	  }
	  if (!isHadron && !photonMatch_finalStateElectronPair) {
	    fPhotonGenMatchInfo.matchType = ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kNoMatchType;
	  }
	  
	  cout << "Is hadron: " << isHadron << endl;
	} // end if NOT a final state photon match
	
      } // end if final state match
      
      // **************************************************************************************************************************
      // no final state match BUT gen particle match (should be considered not matched; just checking for curisoity's sake)
      if (!is_match_real_template_photon && !photonMatch_finalState && photonMatch_genParticles) {
	cout << "No final state match in DeltaR <= " << minDeltaR_finalState << endl;
	cout << "GenParticle match." << endl;
	cout << "GenParticle PhotonMatch    : Status = " << photonMatch_genParticles->status()  << "; ID = " << photonMatch_genParticles->pdgId() << "; pt = "
	     << photonMatch_genParticles->pt() << "; eta = " << photonMatch_genParticles->eta() << "; phi = " << photonMatch_genParticles->phi()  << "; deltaR = " << minDeltaR_genParticles << endl;

	// particle stored into tree
	photonMatch = &(*photonMatch_genParticles);
	
	fPhotonGenMatchInfo.deltaR_match = minDeltaR_genParticles;
	
	// --------------------------------------------------------------------------------------------------------------------------
	// since no final state match, investigate daughters

	// starting particle to determine daughters from
	const reco::GenParticle *matchedDaughter = &(*photonMatch_genParticles);
	
	// consider all daughters when tying to find best daughter (no deltaR cut)
	double minDaughterMatchDeltaR = 1000000;
	// store index of best daughter
	int matchDaughterIndex = 0;

	// loop through all daughters until no daughter exists (i.e., a final state daughter is found)
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
	  cout << "FinalState Matched DAUGHTER " << matchDaughterIndex << ": Status = " << matchedDaughter->status()  << "; ID = " << matchedDaughter->pdgId() << "; pt = "
	       << matchedDaughter->pt() << "; eta = " << matchedDaughter->eta() << "; phi = " << matchedDaughter->phi()  << "; deltaR = " << minDaughterMatchDeltaR << endl;
	  
	  // reset cut!
	  // so we will consider all daughters again during next loop
	  minDaughterMatchDeltaR = 1000000;
	  
	  // index could be > 0 and only one daughter on next match and could be beam particle with very high deltaR
	  // so reset index just to be safe
	  matchDaughterIndex = 0;
	} // end while loop through daughters
	
	// store final daugher
	//photonMatch = &(*matchedDaughter);

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
      if (!photonMatch_realTemplate && !photonMatch_finalState && !photonMatch_genParticles) {
	cout << "No photon match in final state with DeltaR <= " << minDeltaR_finalState << ", or among all gen particles with DeltaR <= " << minDeltaR_genParticles << endl;
	
	// count number according to matchCategory
	fPhotonGenMatchInfo.matchCategory = ExoDiPhotons::GenMatchingFlags::MatchCategoryFlags::kNoMatchCategory;
	
      } // end if no final state match, or gen particle match
      
      cout << "Match category: " << fPhotonGenMatchInfo.matchCategory << ", and match type: " << fPhotonGenMatchInfo.matchType << endl;
      cout << "pT difference between reco photon and final state gen match: " << fPhotonGenMatchInfo.ptDiff_match << endl;
      cout << "dR between reco photon and final state gen match           : " << fPhotonGenMatchInfo.deltaR_match << endl;
      cout << "dR between final state photon match and first daughter     : " << fPhotonGenMatchInfo.deltaR_matchDau << endl;
      
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
      
      // if photon parent, print filled match and store info
      if (photonParent) {
	cout << "Filled gen particle PhotonParent: Status = " << photonParent->status()  << "; ID = " << photonParent->pdgId() << "; pt = "
	     << photonParent->pt() << "; eta = " << photonParent->eta() << "; phi = " << photonParent->phi() << endl;
	
	// fill photonParent genParticle info
	ExoDiPhotons::FillGenParticleInfo(fPhotonGenParentInfo,photonParent);
      } // end if photonParent
      
      // fill photon info
      ExoDiPhotons::FillBasicPhotonInfo(fPhotonMatchInfo, &(*pho));
      ExoDiPhotons::FillPhotonIDInfo(fPhotonMatchInfo, &(*pho), rho_, fPhotonMatchInfo.isSaturated);
      
      // fill EGM ID info
      ExoDiPhotons::FillPhotonEGMidInfo(fPhotonMatchInfo, &(*pho), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
      // this method of retrieving EGM decisions is not currently supported
      // fPhotonMatchInfo.passEGMLooseID  = (*loose_id_decisions)[pho];
      // fPhotonMatchInfo.passEGMMediumID = (*medium_id_decisions)[pho];
      // fPhotonMatchInfo.passEGMTightID  = (*tight_id_decisions)[pho];

      fPhotonMatchInfo.passEGMLooseID  = 0;
      fPhotonMatchInfo.passEGMMediumID = 0;
      fPhotonMatchInfo.passEGMTightID  = 0;
      
      // fill our tree
      //if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) &&
      //ExoDiPhotons::passChargedHadronCut(&(*pho)) )
      fTreeFake->Fill();
      
    } // end if numerator candidate photon
    else cout << "Photon not a numerator 'candidate'!" << endl;

    if (fPhotonGenMatchInfo.matchType == ExoDiPhotons::GenMatchingFlags::MatchTypeFlags::kRealTemplatePhoton)
      is_real_template_photon = 1;

    // fill our tree
    if ( ExoDiPhotons::passNumeratorCandCut(&(*pho), rho_) ||
         ExoDiPhotons::passDenominatorCut(&(*pho), rho_, fPhotonInfo.isSaturated)
      ) fTree->Fill();
    
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
