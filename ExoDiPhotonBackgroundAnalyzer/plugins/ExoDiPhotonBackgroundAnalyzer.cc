// -*- C++ -*-
//
// Package:    diphoton-analysis/ExoDiPhotonBackgroundAnalyzer
// Class:      ExoDiPhotonBackgroundAnalyzer
// 
/**\class ExoDiPhotonBackgroundAnalyzer ExoDiPhotonBackgroundAnalyzer.cc diphoton-analysis/ExoDiPhotonBackgroundAnalyzer/plugins/ExoDiPhotonBackgroundAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrew Buccilli
//         Created:  Tue, 05 Apr 2016 22:30:14 GMT
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

// from our CommonClasses
#include "diphoton-analysis/CommonClasses/interface/EventInfo.h"
#include "diphoton-analysis/CommonClasses/interface/BeamSpotInfo.h"
#include "diphoton-analysis/CommonClasses/interface/VertexInfo.h"
#include "diphoton-analysis/CommonClasses/interface/TriggerInfo.h"
#include "diphoton-analysis/CommonClasses/interface/JetInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonID.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonInfo.h"
#include "diphoton-analysis/CommonClasses/interface/GenParticleInfo.h"
#include "diphoton-analysis/CommonClasses/interface/DiPhotonInfo.h"

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

class ExoDiPhotonBackgroundAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ExoDiPhotonBackgroundAnalyzer(const edm::ParameterSet&);
      ~ExoDiPhotonBackgroundAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
      void fillGenInfo(const edm::Handle<edm::View<reco::GenParticle> > genParticles, const std::vector<edm::Ptr<pat::Photon>> selectedPhotons);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  // ----------member data ---------------------------
  // genParticle token
  edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticlesMiniAODToken_;
  
  // miniAOD photon token
  edm::EDGetToken photonsMiniAODToken_;
  double fMinPt;

  // AK4 jet token and cuts
  edm::EDGetToken jetsMiniAODToken_;
  double jetPtThreshold;
  double jetEtaThreshold;
    
  // ECAL recHits
  edm::InputTag recHitsEBTag_;
  edm::InputTag recHitsEETag_;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEBToken;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEEToken;

  // BeamHaloSummary token
  edm::EDGetToken beamHaloSummaryToken_;

  // Filter decisions token
  edm::EDGetToken filterDecisionToken_;

  // trigger decisions token
  edm::EDGetToken triggerDecisionToken_;

  // trigger prescales token
  edm::EDGetToken prescalesToken_;
  
  // trees
  TTree *fTightTightTree;
  TTree *fTightFakeTree;
  TTree *fFakeTightTree;
  TTree *fFakeFakeTree;

  // rho token
  edm::EDGetTokenT<double> rhoToken_;
  
  // vertex token
  edm::EDGetTokenT<reco::VertexCollection> verticesToken_;

  // beam spot token
  edm::EDGetTokenT<reco::BeamSpot> beamSpotToken_;

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

  // photons
  ExoDiPhotons::photonInfo_t fPhoton1Info; // leading
  ExoDiPhotons::photonInfo_t fPhoton2Info; // subleading

  // jets
  ExoDiPhotons::jetInfo_t fJetInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;

  // vertex
  ExoDiPhotons::vertexInfo_t fVertex0Info;
  ExoDiPhotons::vertexInfo_t fPrimaryVertexInfo;

  // beam spot
  ExoDiPhotons::beamSpotInfo_t fBeamSpotInfo;

  // triggers
  ExoDiPhotons::triggerInfo_t fTriggerBitInfo;
  ExoDiPhotons::triggerInfo_t fTriggerPrescaleInfo;

  // gen event info token
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken_;

  // flag to determine if sample is data or MC
  bool isMC_;

  // genParticles
  ExoDiPhotons::genParticleInfo_t fGenPhoton1Info; // leading
  ExoDiPhotons::genParticleInfo_t fGenPhoton2Info; // subleading

  // diphotons
  ExoDiPhotons::diphotonInfo_t fDiphotonInfo;
  ExoDiPhotons::diphotonInfo_t fGenDiphotonInfo;
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
ExoDiPhotonBackgroundAnalyzer::ExoDiPhotonBackgroundAnalyzer(const edm::ParameterSet& iConfig)
  : rhoToken_(consumes<double> (iConfig.getParameter<edm::InputTag>("rho"))),
    verticesToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"))),
    beamSpotToken_(consumes<reco::BeamSpot>(iConfig.getParameter<edm::InputTag>("beamSpot"))),
    effAreaChHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaChHadFile")).fullPath() ),
    effAreaNeuHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaNeuHadFile")).fullPath() ),
    effAreaPhotons_( (iConfig.getParameter<edm::FileInPath>("effAreaPhoFile")).fullPath() ),
    phoLooseIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoLooseIdMap"))),
    phoMediumIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoMediumIdMap"))),
    phoTightIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoTightIdMap"))),
    outputFile_(TString(iConfig.getParameter<std::string>("outputFile"))),
    nEventsSample_(iConfig.getParameter<uint32_t>("nEventsSample")),
    genInfoToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("genInfo"))),
    isMC_(iConfig.getParameter<bool>("isMC"))
{
  //now do what ever initialization is needed
  usesResource("TFileService");

  edm::Service<TFileService> fs;
  
  // tree for objects passing numerator or denominator definitions
  fTree = fs->make<TTree>("fTree","DiPhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("GenPhoton1",&fGenPhoton1Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("GenPhoton2",&fGenPhoton2Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  fTree->Branch("GenDiphoton",&fGenDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  
  // define trees and branches
  fTightTightTree = fs->make<TTree>("fTightTightTree","DiPhotonTightTightTree");
  fTightTightTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTightTightTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  fTightTightTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  fTightTightTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  fTightTightTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTightTightTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTightTightTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTightTightTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTightTightTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTightTightTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  fTightFakeTree = fs->make<TTree>("fTightFakeTree","DiPhotonTightFakeTree");
  fTightFakeTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTightFakeTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  fTightFakeTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  fTightFakeTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  fTightFakeTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTightFakeTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTightFakeTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTightFakeTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTightFakeTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTightFakeTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  fFakeTightTree = fs->make<TTree>("fFakeTightTree","DiPhotonFakeTightTree");
  fFakeTightTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fFakeTightTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  fFakeTightTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  fFakeTightTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  fFakeTightTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fFakeTightTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fFakeTightTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fFakeTightTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fFakeTightTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fFakeTightTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  fFakeFakeTree = fs->make<TTree>("fFakeFakeTree","DiPhotonFakeFakeTree");
  fFakeFakeTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fFakeFakeTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  fFakeFakeTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  fFakeFakeTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  fFakeFakeTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fFakeFakeTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fFakeFakeTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fFakeFakeTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fFakeFakeTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fFakeFakeTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  // photon token
  photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonsMiniAOD"));
  fMinPt = iConfig.getParameter<double>("minPhotonPt");

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

  // Filter decisions (created in "PAT" process in MC but "RECO" in data)
  filterDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","",isMC_?("PAT"):("RECO")) );

  // Trigger decisions
  triggerDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","","HLT") );

  // trigger prescales
  prescalesToken_ = consumes<pat::PackedTriggerPrescales>( edm::InputTag("patTrigger","",isMC_?("PAT"):("RECO")) );
}


ExoDiPhotonBackgroundAnalyzer::~ExoDiPhotonBackgroundAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ExoDiPhotonBackgroundAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace pat;
  using namespace reco;

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
  if(isMC_) {
    iEvent.getByToken(genInfoToken_,genInfo);
    ExoDiPhotons::FillGenEventInfo(fEventInfo, &(*genInfo));
  }
  ExoDiPhotons::FillEventWeights(fEventInfo, outputFile_, nEventsSample_);

  // =========
  // BEAM SPOT
  // =========

  ExoDiPhotons::InitBeamSpotInfo(fBeamSpotInfo);

  edm::Handle<reco::BeamSpot> beamSpotHandle;
  iEvent.getByToken(beamSpotToken_,beamSpotHandle);

  ExoDiPhotons::FillBeamSpotInfo(fBeamSpotInfo,&(*beamSpotHandle));

  // ========
  // VERTICES
  // ========

  ExoDiPhotons::InitVertexInfo(fVertex0Info);
  ExoDiPhotons::InitVertexInfo(fPrimaryVertexInfo);

  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByToken(verticesToken_,vertices);

  // fill vertex0
  ExoDiPhotons::FillVertexInfo(fVertex0Info,&(vertices->at(0)));
  
  // select the primary vertex, if any
  int nPV = 0;
  const reco::Vertex *myPV = &(vertices->front());
  bool foundPV = false;
  for(unsigned int i = 0; i < vertices->size(); i++){
    if(vertices->at(i).isValid() && !vertices->at(i).isFake()){
      if (!foundPV) {
	myPV = &(vertices->at(i));
	foundPV = true;
      }
      nPV++;
    }
  }

  // fill vertex0
  ExoDiPhotons::FillVertexInfo(fPrimaryVertexInfo,&(*myPV));

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

  // =========
  // DIPHOTONS
  // =========

  ExoDiPhotons::InitDiphotonInfo(fDiphotonInfo);
  if(isMC_) ExoDiPhotons::InitDiphotonInfo(fGenDiphotonInfo);
  
  // ============
  // GENPARTICLES
  // ============

  Handle<edm::View<reco::GenParticle> > genParticles;
  if(isMC_) {
    ExoDiPhotons::InitGenParticleInfo(fGenPhoton1Info);
    ExoDiPhotons::InitGenParticleInfo(fGenPhoton2Info);

    // get genParticle collection
    iEvent.getByToken(genParticlesMiniAODToken_,genParticles);
  }

  // =======
  // PHOTONS
  // =======
   
  ExoDiPhotons::InitPhotonInfo(fPhoton1Info);
  ExoDiPhotons::InitPhotonInfo(fPhoton2Info);
  
  // get photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);

  // check if photon in loop is saturated
  bool isSat = false;

  // pointer to photon in collection that passes high pt ID
  std::vector<edm::Ptr<pat::Photon>> selectedPhotons;
    
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i) {
    const auto pho = photons->ptrAt(i);
    
    // print photon info
    cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;
    
    // check if photon is saturated
    isSat = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));

    // fill photons that pass high pt ID
    if( ExoDiPhotons::passHighPtID(&(*pho), rho_, isSat) ) selectedPhotons.push_back(pho);  
    
  } // end of photon loop

  // sort vector of photons by pt
  sort(selectedPhotons.begin(),selectedPhotons.end(),ExoDiPhotons::comparePhotonsByPt);

  if (selectedPhotons.size() >= 2) {
    cout << "Photon 1 pt = " << selectedPhotons[0]->pt() << "; eta = " << selectedPhotons[0]->eta() << "; phi = " << selectedPhotons[0]->phi() << endl;
    cout << "Photon 2 pt = " << selectedPhotons[1]->pt() << "; eta = " << selectedPhotons[1]->eta() << "; phi = " << selectedPhotons[1]->phi() << endl;

    // ==================
    // fill photon 1 info
    // ==================
    // fill photon saturation
    fPhoton1Info.isSaturated = ExoDiPhotons::isSaturated(&(*selectedPhotons[0]), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    cout << "Photon 1 isSat: " << fPhoton1Info.isSaturated << endl;
    
    // fill photon info
    ExoDiPhotons::FillBasicPhotonInfo(fPhoton1Info, &(*selectedPhotons[0]));
    ExoDiPhotons::FillPhotonIDInfo(fPhoton1Info, &(*selectedPhotons[0]), rho_, fPhoton1Info.isSaturated);
    
    // fill EGM ID info
    ExoDiPhotons::FillPhotonEGMidInfo(fPhoton1Info, &(*selectedPhotons[0]), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
    fPhoton1Info.passEGMLooseID  = (*loose_id_decisions)[selectedPhotons[0]];
    fPhoton1Info.passEGMMediumID = (*medium_id_decisions)[selectedPhotons[0]];
    fPhoton1Info.passEGMTightID  = (*tight_id_decisions)[selectedPhotons[0]];

    // ==================
    // fill photon 2 info
    // ==================
    // fill photon saturation
    fPhoton2Info.isSaturated = ExoDiPhotons::isSaturated(&(*selectedPhotons[1]), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    cout << "Photon 2 isSat: " << fPhoton2Info.isSaturated << endl;
    
    // fill photon info
    ExoDiPhotons::FillBasicPhotonInfo(fPhoton2Info, &(*selectedPhotons[1]));
    ExoDiPhotons::FillPhotonIDInfo(fPhoton2Info, &(*selectedPhotons[1]), rho_, fPhoton2Info.isSaturated);
    
    // fill EGM ID info
    ExoDiPhotons::FillPhotonEGMidInfo(fPhoton2Info, &(*selectedPhotons[1]), rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
    fPhoton2Info.passEGMLooseID  = (*loose_id_decisions)[selectedPhotons[1]];
    fPhoton2Info.passEGMMediumID = (*medium_id_decisions)[selectedPhotons[1]];
    fPhoton2Info.passEGMTightID  = (*tight_id_decisions)[selectedPhotons[1]];

    //cout << "fPhoton 1 pt = " << fPhoton1Info.pt << "; eta = " << fPhoton1Info.eta << "; phi = " << fPhoton1Info.phi << endl;
    //cout << "fPhoton 2 pt = " << fPhoton2Info.pt << "; eta = " << fPhoton2Info.eta << "; phi = " << fPhoton2Info.phi << endl;

    // ==================
    // fill diphoton info
    // ==================
    ExoDiPhotons::FillDiphotonInfo(fDiphotonInfo,&(*selectedPhotons[0]),&(*selectedPhotons[1]));

    
    // fill our trees
    if ( fPhoton1Info.passHighPtID && fPhoton2Info.passHighPtID ) fTightTightTree->Fill();
    else if ( fPhoton1Info.passHighPtID && fPhoton2Info.isDenominatorObj ) fTightFakeTree->Fill();
    else if ( fPhoton1Info.isDenominatorObj && fPhoton2Info.passHighPtID ) fFakeTightTree->Fill();
    else if ( fPhoton1Info.isDenominatorObj && fPhoton2Info.isDenominatorObj ) fFakeFakeTree->Fill();
    fTree->Fill();
    
  } // end 2 photon check
  
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
ExoDiPhotonBackgroundAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExoDiPhotonBackgroundAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ExoDiPhotonBackgroundAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}


void ExoDiPhotonBackgroundAnalyzer::fillGenInfo(const edm::Handle<edm::View<reco::GenParticle> > genParticles, const std::vector<edm::Ptr<pat::Photon>> selectedPhotons) {
  using namespace std;

  // ========================================
  // check for gen photon final state matches
  // ========================================
  // gen photons to match to
  const reco::GenParticle *genPhoton1 = NULL;
  const reco::GenParticle *genPhoton2 = NULL;

  // min deltaR cut
  double minDeltaR1 = 0.1;
  double minDeltaR2 = 0.1;

  // store interacting partons in vector
  vector<int> interactingPartons;

  // loop over gen particle collection
  for (size_t i = 0; i < genParticles->size(); ++i) {
    const auto gen = genParticles->ptrAt(i);

    // find initial state particles in hard process
    // checked for GGJets
    if (gen->isHardProcess() && gen->pt() == 0) {
      //cout << "Hard Process genParticle: " << "status = " << gen->status() << "; pdgId = " << gen->pdgId()
      //<< "; pt = " << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi() << endl;
      interactingPartons.push_back(gen->pdgId());
    }

    // find photon matches in final state from hard process gen particles
    if (gen->fromHardProcessFinalState()) {
      //cout << "GenParticle fromHardProcessFinalState(): Status = " << gen->status()  << "; ID = " << gen->pdgId() << "; pt = "
      //<< gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi() << endl;

      // check for photon 1 (best) match
      double deltaR1 = reco::deltaR(selectedPhotons[0]->eta(),selectedPhotons[0]->phi(),gen->eta(),gen->phi());
      if (deltaR1 < minDeltaR1) {
	minDeltaR1 = deltaR1;
	genPhoton1 = &(*gen);
      }

      // check for photon 2 (best) match
      double deltaR2 = reco::deltaR(selectedPhotons[1]->eta(),selectedPhotons[1]->phi(),gen->eta(),gen->phi());
      if (deltaR2 < minDeltaR2) {
	minDeltaR2 = deltaR2;
	genPhoton2 = &(*gen);
      }

    } // end fromHardProcessFinalState check

  } // end of genParticle loop

    // fill interacting partons
  if (interactingPartons.size() == 2) {
    fEventInfo.interactingParton1PdgId = interactingPartons[0];
    fEventInfo.interactingParton2PdgId = interactingPartons[1];
  }
  else cout << "Exactly two interacting partons not found!" << endl;

  // fill gen photon info
  if (genPhoton1) ExoDiPhotons::FillGenParticleInfo(fGenPhoton1Info, genPhoton1);
  if (genPhoton2) ExoDiPhotons::FillGenParticleInfo(fGenPhoton2Info, genPhoton2);

  // fill gen diphoton info
  if (genPhoton1 && genPhoton2) ExoDiPhotons::FillDiphotonInfo(fGenDiphotonInfo,genPhoton1,genPhoton2);

}

//define this as a plug-in
DEFINE_FWK_MODULE(ExoDiPhotonBackgroundAnalyzer);
