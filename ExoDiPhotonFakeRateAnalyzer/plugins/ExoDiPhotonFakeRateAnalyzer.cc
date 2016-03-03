// -*- C++ -*-
//
// Package:    DiPhotonAnalysis/ExoDiPhotonFakeRateAnalyzer
// Class:      ExoDiPhotonFakeRateAnalyzer
// 
/**\class ExoDiPhotonFakeRateAnalyzer ExoDiPhotonFakeRateAnalyzer.cc DiPhotonAnalysis/ExoDiPhotonFakeRateAnalyzer/plugins/ExoDiPhotonFakeRateAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrew Buccilli
//         Created:  Wed, 02 Mar 2016 14:43:55 GMT
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
#include "DiPhotonAnalysis/CommonClasses/interface/EventInfo.h"
#include "DiPhotonAnalysis/CommonClasses/interface/PhotonID_FakeRate.h"
#include "DiPhotonAnalysis/CommonClasses/interface/PhotonInfo_FakeRate.h"

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

// for photons
#include "DataFormats/PatCandidates/interface/Photon.h"


//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class ExoDiPhotonFakeRateAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit ExoDiPhotonFakeRateAnalyzer(const edm::ParameterSet&);
      ~ExoDiPhotonFakeRateAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  // ----------member data ---------------------------
  
  // miniAOD photon token
  edm::EDGetToken photonsMiniAODToken_;
    
  // ECAL recHits
  edm::InputTag recHitsEBTag_;
  edm::InputTag recHitsEETag_;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEBToken;
  edm::EDGetTokenT<EcalRecHitCollection> recHitsEEToken;

  // rho token
  edm::EDGetTokenT<double> rhoToken_;
  
  // rho variable
  double rho_;
  
  // main tree
  TTree *fTree;

  // photons
  ExoDiPhotons::photonInfo_t fPhotonInfo;
  
  // event
  ExoDiPhotons::eventInfo_t fEventInfo;
  
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
ExoDiPhotonFakeRateAnalyzer::ExoDiPhotonFakeRateAnalyzer(const edm::ParameterSet& iConfig)
  : rhoToken_(consumes<double> (iConfig.getParameter<edm::InputTag>("rho")))
{
  //now do what ever initialization is needed
  usesResource("TFileService");
  
  edm::Service<TFileService> fs;
  
  fTree = fs->make<TTree>("fTree","PhotonTree");
  fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
  fTree->Branch("Photon",&fPhotonInfo,ExoDiPhotons::photonBranchDefString.c_str());
  
  // MiniAOD tokens
  photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonsMiniAOD"));
  
  // ECAL RecHits
  recHitsEBTag_ = iConfig.getUntrackedParameter<edm::InputTag>("RecHitsEBTag",edm::InputTag("reducedEgamma:reducedEBRecHits"));
  recHitsEETag_ = iConfig.getUntrackedParameter<edm::InputTag>("RecHitsEETag",edm::InputTag("reducedEgamma:reducedEERecHits"));
  recHitsEBToken = consumes <edm::SortedCollection<EcalRecHit> > (recHitsEBTag_);
  recHitsEEToken = consumes <edm::SortedCollection<EcalRecHit> > (recHitsEETag_);
  
}


ExoDiPhotonFakeRateAnalyzer::~ExoDiPhotonFakeRateAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ExoDiPhotonFakeRateAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace pat;
  
  ExoDiPhotons::InitEventInfo(fEventInfo);
  ExoDiPhotons::FillBasicEventInfo(fEventInfo, iEvent);
  
  cout <<  "Run: " << iEvent.id().run() << ", LS: " <<  iEvent.id().luminosityBlock() << ", Event: " << iEvent.id().event() << endl;

  // Get rho
  edm::Handle< double > rhoH;
  iEvent.getByToken(rhoToken_,rhoH);
  rho_ = *rhoH;
  
  cout << "rho: " << rho_ << endl;
  
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

  ExoDiPhotons::InitPhotonInfo(fPhotonInfo);
  
  // Get pat::Photon
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);
  
  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i){
    const auto pho = photons->ptrAt(i);
    cout << "Photon: " << "pt = " << pho->pt() << "; eta = " << pho->eta() << "; phi = " << pho->phi() << endl;
    fPhotonInfo.isSaturated = ExoDiPhotons::isSaturated(&(*pho), &(*recHitsEB), &(*recHitsEE), &(*subDetTopologyEB_), &(*subDetTopologyEE_));
    cout << "isSat: " << fPhotonInfo.isSaturated << endl;
    ExoDiPhotons::FillBasicPhotonInfo(fPhotonInfo, &(*pho));
    ExoDiPhotons::FillPhotonIDInfo(fPhotonInfo, &(*pho), rho_, fPhotonInfo.isSaturated);
    // fill our tree
    fTree->Fill();
  }
  
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
ExoDiPhotonFakeRateAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ExoDiPhotonFakeRateAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ExoDiPhotonFakeRateAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ExoDiPhotonFakeRateAnalyzer);
