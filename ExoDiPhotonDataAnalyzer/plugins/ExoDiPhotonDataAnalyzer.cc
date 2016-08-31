// -*- C++ -*-
//
// Package:    diphoton-analysis/ExoDiPhotonDataAnalyzer
// Class:      ExoDiPhotonDataAnalyzer
// 
/**\class ExoDiPhotonDataAnalyzer ExoDiPhotonDataAnalyzer.cc diphoton-analysis/ExoDiPhotonDataAnalyzer/plugins/ExoDiPhotonDataAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrew Buccilli
//         Created:  Thu, 09 Jun 2016 15:17:54 GMT
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
#include "diphoton-analysis/CommonClasses/interface/BeamSpotInfo.h"
#include "diphoton-analysis/CommonClasses/interface/VertexInfo.h"
#include "diphoton-analysis/CommonClasses/interface/TriggerInfo.h"
#include "diphoton-analysis/CommonClasses/interface/JetInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonID.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonInfo.h"
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

// for trigger and filter decisions
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"

// for beam spot
#include "DataFormats/BeamSpot/interface/BeamSpot.h"

// for vertex
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class ExoDiPhotonDataAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ExoDiPhotonDataAnalyzer(const edm::ParameterSet&);
      ~ExoDiPhotonDataAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  // ----------member data ---------------------------

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
  
  // beamHaloSummary token
  edm::EDGetToken beamHaloSummaryToken_;
  
  // filter decisions token
  edm::EDGetToken filterDecisionToken_;
  
  // trigger decisions token
  edm::EDGetToken triggerDecisionToken_;

  // trigger prescales token
  edm::EDGetToken prescalesToken_;
  
  // trees
  TTree* fTree;
  // TTree *fTightTightTree;
  // TTree *fTightFakeTree;
  // TTree *fFakeTightTree;
  // TTree *fFakeFakeTree;
  
  // photons
  ExoDiPhotons::photonInfo_t fPhoton1Info; // leading
  ExoDiPhotons::photonInfo_t fPhoton2Info; // sub-leading

  // diphoton
  ExoDiPhotons::diphotonInfo_t fDiphotonInfo;
  
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
ExoDiPhotonDataAnalyzer::ExoDiPhotonDataAnalyzer(const edm::ParameterSet& iConfig)
  : rhoToken_(consumes<double> (iConfig.getParameter<edm::InputTag>("rho"))),
    verticesToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"))),
    beamSpotToken_(consumes<reco::BeamSpot>(iConfig.getParameter<edm::InputTag>("beamSpot"))),
    effAreaChHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaChHadFile")).fullPath() ),
    effAreaNeuHadrons_( (iConfig.getParameter<edm::FileInPath>("effAreaNeuHadFile")).fullPath() ),
    effAreaPhotons_( (iConfig.getParameter<edm::FileInPath>("effAreaPhoFile")).fullPath() ),
    phoLooseIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoLooseIdMap"))),
    phoMediumIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoMediumIdMap"))),
    phoTightIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoTightIdMap")))
{
  //now do what ever initialization is needed
  usesResource("TFileService");

  edm::Service<TFileService> fs;
  
  // define trees and branches

  fTree = fs->make<TTree>("fTree","DiPhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  fTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  fTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  fTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  fTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());


  // fTightTightTree = fs->make<TTree>("fTightTightTree","DiPhotonTightTightTree");
  // fTightTightTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  // fTightTightTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  // fTightTightTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  // fTightTightTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  // fTightTightTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  // fTightTightTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fTightTightTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fTightTightTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fTightTightTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fTightTightTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  // fTightFakeTree = fs->make<TTree>("fTightFakeTree","DiPhotonTightFakeTree");
  // fTightFakeTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  // fTightFakeTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  // fTightFakeTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  // fTightFakeTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  // fTightFakeTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  // fTightFakeTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fTightFakeTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fTightFakeTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fTightFakeTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fTightFakeTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  // fFakeTightTree = fs->make<TTree>("fFakeTightTree","DiPhotonFakeTightTree");
  // fFakeTightTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  // fFakeTightTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  // fFakeTightTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  // fFakeTightTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  // fFakeTightTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  // fFakeTightTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fFakeTightTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fFakeTightTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fFakeTightTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fFakeTightTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());

  // fFakeFakeTree = fs->make<TTree>("fFakeFakeTree","DiPhotonFakeFakeTree");
  // fFakeFakeTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  // fFakeFakeTree->Branch("BeamSpot",&fBeamSpotInfo,ExoDiPhotons::beamSpotBranchDefString.c_str());
  // fFakeFakeTree->Branch("Vertex0",&fVertex0Info,ExoDiPhotons::vertexBranchDefString.c_str());
  // fFakeFakeTree->Branch("PrimaryVertex",&fPrimaryVertexInfo,ExoDiPhotons::vertexBranchDefString.c_str());
  // fFakeFakeTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  // fFakeFakeTree->Branch("TriggerBit",&fTriggerBitInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fFakeFakeTree->Branch("TriggerPrescale",&fTriggerPrescaleInfo,ExoDiPhotons::triggerBranchDefString.c_str());
  // fFakeFakeTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fFakeFakeTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  // fFakeFakeTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  
  // MiniAOD tokens
  photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonsMiniAOD"));
  fMinPt = iConfig.getParameter<double>("minPhotonPt");
  
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
  filterDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","","RECO") );
  
  // Trigger decisions
  triggerDecisionToken_ = consumes<edm::TriggerResults>( edm::InputTag("TriggerResults","","HLT") );
  
  // trigger prescales
  prescalesToken_ = consumes<pat::PackedTriggerPrescales>( edm::InputTag("patTrigger","","RECO") );
}


ExoDiPhotonDataAnalyzer::~ExoDiPhotonDataAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ExoDiPhotonDataAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace pat;

  // =====
  // EVENT
  // =====

  edm::Handle< reco::BeamHaloSummary > bhsHandle;
  iEvent.getByToken(beamHaloSummaryToken_,bhsHandle);
  const reco::BeamHaloSummary* bhs = &(*bhsHandle);
  
  ExoDiPhotons::InitEventInfo(fEventInfo);
  ExoDiPhotons::FillBasicEventInfo(fEventInfo, iEvent);
  ExoDiPhotons::FillBeamHaloEventInfo(fEventInfo, bhs);
  
  cout <<  "Run: " << iEvent.id().run() << ", LS: " <<  iEvent.id().luminosityBlock() << ", Event: " << iEvent.id().event() << endl;

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
  
  
  // ===
  // JET
  // ===

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

  // test which triggers fired

  // std::vector<std::string> trigNames2 = iEvent.triggerNames(*triggerResults).triggerNames();

  // for (unsigned int i=0; i < trigNames2.size(); i++){
  //   std::string currentTrigger = trigNames2.at(i);
  //   if (triggerResults->accept(i)) std::cout << currentTrigger << " = " << triggerResults->accept(i) << std::endl;
  // }

  // =========
  // DIPHOTONS
  // =========
  
  ExoDiPhotons::InitDiphotonInfo(fDiphotonInfo);
  
  // =======
  // PHOTONS
  // =======
  
  ExoDiPhotons::InitPhotonInfo(fPhoton1Info);
  ExoDiPhotons::InitPhotonInfo(fPhoton2Info);

  // check if photon in loop is saturated
  bool isSat = false;

  // pointer to photons in collection that pass high pt ID or pass the denominator definition
  std::vector<edm::Ptr<pat::Photon>> selectedPhotons;
  
  // get pat::Photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);
  
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i){
    const auto pho = photons->ptrAt(i);
    
    // print photon info
    cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;

    if (pho->pt() < fMinPt){
      cout << "Photon pt less than " << fMinPt << ", so we're skipping it!" << endl;
      continue;
    }
    
    // check if photon is saturated
    isSat = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));

    // fill photons that pass high pt ID
    if( ExoDiPhotons::passHighPtID(&(*pho), rho_, isSat) || ExoDiPhotons::passDenominatorCut(&(*pho), rho_, isSat) ) selectedPhotons.push_back(pho);  
    
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
    bool TT = fPhoton1Info.passHighPtID && fPhoton2Info.passHighPtID;
    bool TL = fPhoton1Info.passHighPtID && fPhoton2Info.isDenominatorObj;
    bool LT = fPhoton1Info.isDenominatorObj && fPhoton2Info.passHighPtID;
    bool LL = fPhoton1Info.isDenominatorObj && fPhoton2Info.isDenominatorObj;

    if (TT || TL || LT || LL) fTree->Fill();

    // if ( fPhoton1Info.passHighPtID && fPhoton2Info.passHighPtID ) fTightTightTree->Fill();
    // else if ( fPhoton1Info.passHighPtID && fPhoton2Info.isDenominatorObj ) fTightFakeTree->Fill();
    // else if ( fPhoton1Info.isDenominatorObj && fPhoton2Info.passHighPtID ) fFakeTightTree->Fill();
    // else if ( fPhoton1Info.isDenominatorObj && fPhoton2Info.isDenominatorObj ) fFakeFakeTree->Fill();
    
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
ExoDiPhotonDataAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExoDiPhotonDataAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ExoDiPhotonDataAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ExoDiPhotonDataAnalyzer);
