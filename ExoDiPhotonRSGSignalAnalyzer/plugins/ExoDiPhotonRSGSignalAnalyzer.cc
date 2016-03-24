// -*- C++ -*-
//
// Package:    diphoton-analysis/ExoDiPhotonRSGSignalAnalyzer
// Class:      ExoDiPhotonRSGSignalAnalyzer
// 
/**\class ExoDiPhotonRSGSignalAnalyzer ExoDiPhotonRSGSignalAnalyzer.cc diphoton-analysis/ExoDiPhotonRSGSignalAnalyzer/plugins/ExoDiPhotonRSGSignalAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrew Buccilli
//         Created:  Tue, 15 Mar 2016 23:40:37 GMT
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

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class ExoDiPhotonRSGSignalAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ExoDiPhotonRSGSignalAnalyzer(const edm::ParameterSet&);
      ~ExoDiPhotonRSGSignalAnalyzer();

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
    
  // ECAL recHits
  edm::InputTag recHitsEBTag_;
  edm::InputTag recHitsEETag_;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEBToken;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEEToken;

  // BeamHaloSummary token
  edm::EDGetToken beamHaloSummaryToken_;

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
  ExoDiPhotons::photonInfo_t fPhoton1Info; // leading
  ExoDiPhotons::photonInfo_t fPhoton2Info; // subleading

  // jets
  ExoDiPhotons::jetInfo_t fJetInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;

  // gen event info token
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken_;

  // genParticles
  // Unstable photons are directly RSG decay
  ExoDiPhotons::genParticleInfo_t fUnstablePhoton1Info; // leading
  ExoDiPhotons::genParticleInfo_t fUnstablePhoton2Info; // subleading
  // Stable photons are final state photons from RSG decay
  ExoDiPhotons::genParticleInfo_t fStablePhoton1Info; // leading
  ExoDiPhotons::genParticleInfo_t fStablePhoton2Info; // subleading

  // diphotons
  ExoDiPhotons::diphotonInfo_t fDiphotonInfo;
  ExoDiPhotons::diphotonInfo_t fGenDiphotonUnstableInfo;
  ExoDiPhotons::diphotonInfo_t fGenDiphotonStableInfo;
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
ExoDiPhotonRSGSignalAnalyzer::ExoDiPhotonRSGSignalAnalyzer(const edm::ParameterSet& iConfig)
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
  fTree = fs->make<TTree>("fTree","DiPhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("Jet",&fJetInfo,ExoDiPhotons::jetBranchDefString.c_str());
  fTree->Branch("Photon1",&fPhoton1Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("Photon2",&fPhoton2Info,ExoDiPhotons::photonBranchDefString.c_str());
  fTree->Branch("UnstablePhoton1",&fUnstablePhoton1Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("UnstablePhoton2",&fUnstablePhoton2Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("StablePhoton1",&fStablePhoton1Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("StablePhoton2",&fStablePhoton2Info,ExoDiPhotons::genParticleBranchDefString.c_str());
  fTree->Branch("Diphoton",&fDiphotonInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  fTree->Branch("GenDiphotonUnstable",&fGenDiphotonUnstableInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  fTree->Branch("GenDiphotonStable",&fGenDiphotonStableInfo,ExoDiPhotons::diphotonBranchDefString.c_str());
  
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


ExoDiPhotonRSGSignalAnalyzer::~ExoDiPhotonRSGSignalAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ExoDiPhotonRSGSignalAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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

  ExoDiPhotons::InitGenParticleInfo(fUnstablePhoton1Info);
  ExoDiPhotons::InitGenParticleInfo(fUnstablePhoton2Info);
  ExoDiPhotons::InitGenParticleInfo(fStablePhoton1Info);
  ExoDiPhotons::InitGenParticleInfo(fStablePhoton2Info);
  
  // get genParticle collection
  Handle<edm::View<reco::GenParticle> > genParticles;
  iEvent.getByToken(genParticlesMiniAODToken_,genParticles);

  const reco::GenParticle *unstablePhoton1 = NULL;
  const reco::GenParticle *unstablePhoton2 = NULL;
  const reco::GenParticle *stablePhoton1 = NULL;
  const reco::GenParticle *stablePhoton2 = NULL;

  vector<int> interactingPartons;
  
  //for (edm::View<reco::GenParticle>::const_iterator gen = genParticles->begin(); gen != genParticles->end(); ++gen) {
  for (size_t i = 0; i < genParticles->size(); ++i) {
    //const GenParticle & gen = (*genParticles)[i];
    const auto gen = genParticles->ptrAt(i);
    
    // find initial state particles in hard process
    if (gen->isHardProcess() && gen->pt() == 0) {
      //cout << "Hard Process genParticle: " << "status = " << gen->status() << "; pdgId = " << gen->pdgId()
      //<< "; pt = " << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi() << endl;
      if (gen->pdgId() != 5100039) {
	interactingPartons.push_back(gen->pdgId());
      }
    }

    unsigned nDau = gen->numberOfDaughters();
    
    if (gen->pdgId() == 5100039 && gen->isLastCopy()) { 
      cout << "---RSG---" << endl;
      cout << "numberOfDaughters: " << nDau << endl;
      cout << "Status: " << gen->status() << endl;
      cout << "isLastCopy(): " << gen->isLastCopy() << endl;
      cout << "GenParticle: " << "pt = " << gen->pt() << "; eta = " << gen->eta() << "; phi = " << gen->phi() << endl;
      
      for (unsigned j = 0; j < nDau; ++j) {
	
	const GenParticle * dau = (GenParticle *) gen->daughter( j );
	unsigned nDauDau = dau->numberOfDaughters();
	int dauId = dau->pdgId();
	
	// since p is last copy, should be true, but will require it anyway
	if(nDau == 2 && dauId == 22) {
	  //const GenParticle  *pho = dau;
	  cout << " -dauID: " << dauId << endl;
	  cout << "   isLastCopy: " << dau->isLastCopy() << endl;
	  cout << "   numberOfDaughters: " << nDauDau << endl;
	  cout << "   dauStatus: " << dau->status() << endl;
	  cout << "   dauPt, Eta, Phi: " << dau->pt() << ", " << dau->eta() << ", " << dau->phi() << endl;
	  
	  // assign unstable photons
	  if (!unstablePhoton1) unstablePhoton1 = dau;
	   else unstablePhoton2 = dau;
	  
	  // assign stable photons
	  // CASE 1: Unstable photon is stable photon
	  if (nDauDau == 0 && dau->status() == 1) {
	    if (!stablePhoton1) stablePhoton1 = dau;
	    else stablePhoton2 = dau;
	  }
	  
	  // assign stable photons
	  // CASE 2: One unstable photon pair produces, while the other has a stable photon daughter,
	  // or they both pair produce
	  else if (nDauDau == 1 && dau->daughter(0)->pdgId() == 22) {
	    if (dau->daughter(0)->status() == 1) {
	      //const Candidate *dauDau = dau->daughter(0);
	      const GenParticle *dauDau = (GenParticle *) dau->daughter(0);
	      if (!stablePhoton1) stablePhoton1 = dauDau;
	      else stablePhoton2 = dauDau;
	    }
	    else if (dau->daughter(0)->numberOfDaughters()==2
		     && fabs(dau->daughter(0)->daughter(0)->pdgId()) == fabs(dau->daughter(0)->daughter(1)->pdgId())) {
	      //const Candidate *dauDauDau = dau->daughter(0)->daughter(0); // take either, choose 1st
	      const GenParticle *dauDauDau = (GenParticle *) dau->daughter(0)->daughter(0); // take either, choose 1st
	      cout << "  *Unstable photon pair produced.*" << endl;
	      if (!stablePhoton1) stablePhoton1 = dauDauDau;
	      else stablePhoton2 = dauDauDau;
	    }
	  }
	  else if (nDauDau == 2 && fabs(dau->daughter(0)->pdgId()) == fabs(dau->daughter(1)->pdgId())) {
	    //const Candidate *dauDau = dau->daughter(0); // take either, choose 1st
	    const GenParticle *dauDau = (GenParticle *) dau->daughter(0); // take either, choose 1st
	    cout << "  *Unstable photon pair produced.*" << endl;
	    if (!stablePhoton1) stablePhoton1 = dauDau;
	    else stablePhoton2 = dauDau;
	  }
	  else {
	    cout << "Didnt find Stable Photon!" << endl;
	  }
	  
	  // print dauDau info
	  for (unsigned j=0; j<nDauDau; ++j) {
	    //const Candidate *dauDau = dau->daughter( j );
	    const GenParticle *dauDau = (GenParticle *) dau->daughter(j);
	    cout << "  --dauID: " << dauDau->pdgId() << endl;
	    cout << "     isLastCopy: " << dauDau->isLastCopy() << endl;
	    cout << "     numberOfDaughters: " << dauDau->numberOfDaughters() << endl;
	    cout << "     dauStatus: " << dauDau->status() << endl;
	    cout << "     dauPt, Eta, Phi: " << dauDau->pt() << ", " << dauDau->eta() << ", " << dauDau->phi() << endl;
	    
	    //print dauDauDau info
	    unsigned nDauDauDau = dauDau->numberOfDaughters();
	     for (unsigned j=0; j<nDauDauDau; ++j) {
	       //const Candidate *dauDauDau = dauDau->daughter( j );
	       const GenParticle *dauDauDau = (GenParticle *) dauDau->daughter(j);
	       cout << "   ---dauID: " << dauDauDau->pdgId() << endl;
	       cout << "       isLastCopy: " << dauDauDau->isLastCopy() << endl;
	       cout << "       numberOfDaughters: " << dauDauDau->numberOfDaughters() << endl;
	       cout << "       dauStatus: " << dauDauDau->status() << endl;
	       cout << "       dauPt, Eta, Phi: " << dauDauDau->pt() << ", " << dauDauDau->eta() << ", " << dauDauDau->phi() << endl;
	     } // end dauDauDau loop
	  } // end dauDau loop
	  
	} // end 2 photon check
	else cout << "Didnt find 2 photons from RSG decay!" << endl;
      } // end dau loop
    } // end RSG check
    
  } // end of genParticle loop
  
  if (interactingPartons.size() == 2) {
    fEventInfo.interactingParton1PdgId = interactingPartons[0];
    fEventInfo.interactingParton2PdgId = interactingPartons[1];
  }
  else cout << "Two interacting partons not found!" << endl;
  
  // what if some of the unstable photons arent found? 
   if (!unstablePhoton1) {
     cout << "Couldnt find Unstable Photon 1 !" <<endl;
     fUnstablePhoton1Info.status = -99;
     fTree->Fill();
     return;
   }
   if (!unstablePhoton2) {
     cout << "Couldnt find Unstable Photon 2 !" <<endl;
     fUnstablePhoton2Info.status = -99;
     fTree->Fill();
     return;
   }

   // what if some of the stable photons arent found? 
   if (!stablePhoton1) {
     cout << "Couldnt find Stable Photon 1 !" <<endl;
     fStablePhoton1Info.status = -888.888;
   }
   if (!stablePhoton2) {
     cout << "Couldnt find Stable Photon 2 !" <<endl;
     fStablePhoton2Info.status = -888.888;
   }
  
   // reorder the unstable photons by pt,
   // which are correlted to the stable photons
   if (unstablePhoton2->pt()>unstablePhoton1->pt()) {
     const reco::GenParticle *tempUnstablePhoton = unstablePhoton1;
     unstablePhoton1 = unstablePhoton2;
     unstablePhoton2 = tempUnstablePhoton;
     //if (stablePhoton1 && stablePhoton2) {
     const reco::GenParticle *tempStablePhoton = stablePhoton1;
     stablePhoton1 = stablePhoton2; // could be NULL
     stablePhoton2 = tempStablePhoton; // could be NULL
     // }
   }

   // if stablePhoton pair produces, store pdgId of particle it pair produces to
   if (stablePhoton1 && stablePhoton1->pdgId() != 22) {
     cout << "StablePhoton1 is part of pair production." << endl;
     fStablePhoton1Info.status = -77;
     fStablePhoton1Info.pdgId = fabs(stablePhoton1->pdgId());
     fStablePhoton1Info.pt= -77.77;
     fStablePhoton1Info.eta= -77.77;
     fStablePhoton1Info.phi= -77.77;
   }
   if (stablePhoton2 && stablePhoton2->pdgId() != 22) {
     cout << "StablePhoton2 is part of pair production." << endl;
     fStablePhoton2Info.status = -77;
     fStablePhoton2Info.pdgId = fabs(stablePhoton2->pdgId());
     fStablePhoton2Info.pt= -77.77;
     fStablePhoton2Info.eta= -77.77;
     fStablePhoton2Info.phi= -77.77;
   }
      
   ExoDiPhotons::FillGenParticleInfo(fUnstablePhoton1Info,unstablePhoton1);
   ExoDiPhotons::FillGenParticleInfo(fUnstablePhoton2Info,unstablePhoton2);
   
   if(stablePhoton1 && stablePhoton1->pdgId() == 22) ExoDiPhotons::FillGenParticleInfo(fStablePhoton1Info,stablePhoton1);
   if(stablePhoton2 && stablePhoton2->pdgId() == 22) ExoDiPhotons::FillGenParticleInfo(fStablePhoton2Info,stablePhoton2);

   cout << endl;
   cout << "UnstablePhoton1 status, pdgId, pt: " << fUnstablePhoton1Info.status << ", " << fUnstablePhoton1Info.pdgId << ", " << fUnstablePhoton1Info.pt << endl;
   cout << "UnstablePhoton2 status, pdgId, pt: " << fUnstablePhoton2Info.status << ", " << fUnstablePhoton2Info.pdgId << ", " << fUnstablePhoton2Info.pt << endl;
   cout << endl;
   cout << "StablePhoton1 status, pdgId, pt: " << fStablePhoton1Info.status << ", " << fStablePhoton1Info.pdgId << ", " << fStablePhoton1Info.pt << endl;
   cout << "StablePhoton2 status, pdgId, pt: " << fStablePhoton2Info.status << ", " << fStablePhoton2Info.pdgId << ", " << fStablePhoton2Info.pt << endl;
   cout << endl;
  
  // =======
  // PHOTONS
  // =======
  
  ExoDiPhotons::InitPhotonInfo(fPhoton1Info);
  ExoDiPhotons::InitPhotonInfo(fPhoton2Info);
  
  // for matching signal to reco photons
  const pat::Photon *matchPhoton1 = NULL;
  const pat::Photon *matchPhoton2 = NULL;
  
  // use 0.2 as min deltaR cut
  double minDeltaR1 = 0.2;
  double minDeltaR2 = 0.2;
  
  // get photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);

  // index
  int matchPhoton1Index = -1;
  int matchPhoton2Index = -1;
  int phoIndex = -1;
  
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i){
    const auto pho = photons->ptrAt(i);

    // increment index
    phoIndex++;

    // print photon info
    //cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;

    if (stablePhoton1 && stablePhoton1->pdgId()==22) {
      double deltaR = reco::deltaR(pho->eta(),pho->phi(),stablePhoton1->eta(),stablePhoton1->phi());
      
      if (deltaR < minDeltaR1) {
	minDeltaR1 = deltaR;
	matchPhoton1 = &(*pho);
	matchPhoton1Index = phoIndex;
      }       
    }
    if (stablePhoton2 && stablePhoton2->pdgId()==22) {
      double deltaR = reco::deltaR(pho->eta(),pho->phi(),stablePhoton2->eta(),stablePhoton2->phi());       
      
      if (deltaR < minDeltaR2) {
	minDeltaR2 = deltaR;
	matchPhoton2 = &(*pho);
	matchPhoton2Index = phoIndex;
      }       
    }
    
  } // end of photon loop
  
  
  if (matchPhoton1) {
    // get pointer to matchPhoton in photon collection
    edm::Ptr<pat::Photon> matchPho1Ptr(photons,matchPhoton1Index);
    
    // fill photon saturation
    fPhoton1Info.isSaturated = ExoDiPhotons::isSaturated(matchPhoton1, &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    
    // fill photon info
    ExoDiPhotons::FillBasicPhotonInfo(fPhoton1Info, matchPhoton1);
    ExoDiPhotons::FillPhotonIDInfo(fPhoton1Info, matchPhoton1, rho_, fPhoton1Info.isSaturated);
    
    // fill EGM ID info
    ExoDiPhotons::FillPhotonEGMidInfo(fPhoton1Info, matchPhoton1, rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
    fPhoton1Info.passEGMLooseID  = (*loose_id_decisions)[matchPho1Ptr];
    fPhoton1Info.passEGMMediumID = (*medium_id_decisions)[matchPho1Ptr];
    fPhoton1Info.passEGMTightID  = (*tight_id_decisions)[matchPho1Ptr];
  } // end matchPhoton1
  else {
    cout << "No match to stablePhoton1!" << endl;
    fPhoton1Info.pt = -777.777;
  }
  
  if (matchPhoton2) {
    // get pointer to matchPhoton in photon collection
    edm::Ptr<pat::Photon> matchPho2Ptr(photons,matchPhoton2Index);
    
    // fill photon saturation
    fPhoton2Info.isSaturated = ExoDiPhotons::isSaturated(matchPhoton2, &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    
    // fill photon info
    ExoDiPhotons::FillBasicPhotonInfo(fPhoton2Info, matchPhoton2);
    ExoDiPhotons::FillPhotonIDInfo(fPhoton2Info, matchPhoton2, rho_, fPhoton2Info.isSaturated);
    
    // fill EGM ID info
    ExoDiPhotons::FillPhotonEGMidInfo(fPhoton2Info, matchPhoton2, rho_, effAreaChHadrons_, effAreaNeuHadrons_, effAreaPhotons_);
    fPhoton2Info.passEGMLooseID  = (*loose_id_decisions)[matchPho2Ptr];
    fPhoton2Info.passEGMMediumID = (*medium_id_decisions)[matchPho2Ptr];
    fPhoton2Info.passEGMTightID  = (*tight_id_decisions)[matchPho2Ptr];
  } // end matchPhoton2
  else {
    cout << "No match to stablePhoton2!" << endl;
    fPhoton2Info.pt = -777.777;
  }
  
  cout << "Photon1 pt, eta, phi: " << fPhoton1Info.pt << ", " << fPhoton1Info.eta << ", " << fPhoton1Info.phi << "; isSat: " << fPhoton1Info.isSaturated << endl;
  cout << "Photon2 pt, eta, phi: " << fPhoton2Info.pt << ", " << fPhoton2Info.eta << ", " << fPhoton2Info.phi << "; isSat: " << fPhoton2Info.isSaturated << endl;
  cout << endl;
  
  // =========
  // DIPHOTONS
  // =========

  ExoDiPhotons::InitDiphotonInfo(fDiphotonInfo);
  ExoDiPhotons::InitDiphotonInfo(fGenDiphotonUnstableInfo);
  ExoDiPhotons::InitDiphotonInfo(fGenDiphotonStableInfo);

  if (unstablePhoton1 && unstablePhoton2) {
    ExoDiPhotons::FillDiphotonInfo(fGenDiphotonUnstableInfo,unstablePhoton1,unstablePhoton2);
  }
  
  if (stablePhoton1 && stablePhoton2 && stablePhoton1->pdgId()==22 && stablePhoton2->pdgId()==22) {
    ExoDiPhotons::FillDiphotonInfo(fGenDiphotonStableInfo,stablePhoton1,stablePhoton2);
  }
  
  if (matchPhoton1 && matchPhoton2) {
    ExoDiPhotons::FillDiphotonInfo(fDiphotonInfo,matchPhoton1,matchPhoton2);
  }
  
  // fill the tree for every event
  fTree->Fill();
  
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
ExoDiPhotonRSGSignalAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExoDiPhotonRSGSignalAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ExoDiPhotonRSGSignalAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ExoDiPhotonRSGSignalAnalyzer);
