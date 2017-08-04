// -*- C++ -*-
//
// Package:    diphoton-analysis/TriphotonAnalyzerTest
// Class:      TriphotonAnalyzerTest
// 
/**\class TriphotonAnalyzerTest TriphotonAnalyzerTest.cc diphoton-analysis/TriphotonAnalyzerTest/plugins/TriphotonAnalyzerTest.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Cilicia Uzziel Perez
//         Created:  Sun, 23 Jul 2017 00:42:00 GMT
//
//


// system include files
#include <memory>
#include <iostream>
#include <fstream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "diphoton-analysis/CommonClasses/interface/EventInfo.h"
#include "diphoton-analysis/CommonClasses/interface/BeamSpotInfo.h"
#include "diphoton-analysis/CommonClasses/interface/VertexInfo.h"
#include "diphoton-analysis/CommonClasses/interface/TriggerInfo.h"
#include "diphoton-analysis/CommonClasses/interface/JetInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonID.h"
#include "diphoton-analysis/CommonClasses/interface/PhotonInfo.h"
#include "diphoton-analysis/CommonClasses/interface/GenParticleInfo.h"
#include "diphoton-analysis/CommonClasses/interface/DiPhotonInfo.h"
#include "diphoton-analysis/CommonClasses/interface/PileupInfo.h"

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

class TriphotonAnalyzerTest : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit TriphotonAnalyzerTest(const edm::ParameterSet&);
      ~TriphotonAnalyzerTest();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
    
    // miniAOD photon token
    edm::EDGetToken photonsMiniAODToken_;
    
    // trees
    TTree *fTree;
    
    // event
     ExoDiPhotons::eventInfo_t fEventInfo; 
    
    // photons (all good)
    ExoDiPhotons::photonInfo_t fTriPhotonInfo[3]; // AllThree
    ExoDiPhotons::photonInfo_t fgoodTriPhotonInfo[3]; //Good Photons 

    // flag to determine if sample is data or MC
    bool isMC_; 

   //Comparer (Request to be pushed into parent repo) 
   static bool comparePhotonsByPt(const edm::Ptr<pat::Photon> photon1, const edm::Ptr<pat::Photon> photon2) {
          return(photon1->pt()<=photon2->pt());
            }

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
TriphotonAnalyzerTest::TriphotonAnalyzerTest(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");
   edm::Service<TFileService> fs;
   
   //Tree Information Branches
   fTree = fs->make<TTree>("fTree","TriphotonTree");
   fTree->Branch("Event",&fEventInfo,ExoDiPhotons::eventBranchDefString.c_str());
   fTree->Branch("Photon1Cand", &fTriPhotonInfo[0], ExoDiPhotons::photonBranchDefString.c_str());
   fTree->Branch("Photon2Cand", &fTriPhotonInfo[1], ExoDiPhotons::photonBranchDefString.c_str());
   fTree->Branch("Photon3Cand", &fTriPhotonInfo[2], ExoDiPhotons::photonBranchDefString.c_str());
   
   fTree->Branch("Photon1", &fgoodTriPhotonInfo[0], ExoDiPhotons::photonBranchDefString.c_str());
   fTree->Branch("Photon2", &fgoodTriPhotonInfo[1], ExoDiPhotons::photonBranchDefString.c_str());
   fTree->Branch("Photon3", &fgoodTriPhotonInfo[2], ExoDiPhotons::photonBranchDefString.c_str());

  // photon token
  // photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonsMiniAOD"));
   photonsMiniAODToken_ = mayConsume<edm::View<pat::Photon>>(edm::InputTag("slimmedPhotons"));
}


TriphotonAnalyzerTest::~TriphotonAnalyzerTest()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TriphotonAnalyzerTest::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;
   using namespace pat;
   using namespace reco;

  //Store Print out in a file: 
  ofstream cout("output.txt", ios::app);

  // ==========
  // EVENT INFO
  // ==========
  
  ExoDiPhotons::InitEventInfo(fEventInfo);
  ExoDiPhotons::FillBasicEventInfo(fEventInfo, iEvent);
  cout <<  "Run: " << iEvent.id().run() << ", LS: " <<  iEvent.id().luminosityBlock() << ", Event: " << iEvent.id().event() << endl;
  
  // =======
  // PHOTONS
  // =======
  
  // get photon collection
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonsMiniAODToken_,photons);
 
  //Initializations
  ExoDiPhotons::InitPhotonInfo(fTriPhotonInfo[0]);
  ExoDiPhotons::InitPhotonInfo(fTriPhotonInfo[1]);
  ExoDiPhotons::InitPhotonInfo(fTriPhotonInfo[2]);
  ExoDiPhotons::InitPhotonInfo(fgoodTriPhotonInfo[0]);
  ExoDiPhotons::InitPhotonInfo(fgoodTriPhotonInfo[1]);
  ExoDiPhotons::InitPhotonInfo(fgoodTriPhotonInfo[2]);


  // pointer to photon in collection that passes high pt ID
  std::vector<edm::Ptr<pat::Photon>> goodPhotons; // We will implement this later 
  std::vector<edm::Ptr<pat::Photon>> photon_obj;  // Just any photon

  //for (edm::View<pat::Photon>::const_iterator pho = photons->begin(); pho != photons->end(); ++pho) {
  for (size_t i = 0; i < photons->size(); ++i) {
    const auto pho = photons->ptrAt(i);  
    
    cout << "Photon: " << "pt = " << pho->pt() << ";hadToweroverEM = "  << pho->hadTowOverEm() <<endl; 
    //fill photons No ID
    photon_obj.push_back(pho);
     
    bool passHoverE = ExoDiPhotons::passHadTowerOverEmCut(&(*pho));
    if(passHoverE) goodPhotons.push_back(pho);
    
    //double hOverE = pho->hadTowOverEm();
    //if(hOverE < 0.05) goodPhotons.push_back(pho);
  } // end of photon loop

  // sort vector of photons by pt
  sort(photon_obj.rbegin(), photon_obj.rend(), comparePhotonsByPt);
  sort(goodPhotons.rbegin(), goodPhotons.rend(), comparePhotonsByPt);

  if(goodPhotons.size()>2){
  //Check Infos
       cout << "Photon 1: " <<"pt = " << goodPhotons[0]->pt() << "; H/E = " <<  goodPhotons[0]->hadTowOverEm() << endl;
       cout << "Photon 2: " << "pt = " << goodPhotons[1]->pt() << "; H/E = "<<  goodPhotons[1]->hadTowOverEm() << endl;
       cout << "Photon 3: " << "pt = " << goodPhotons[2]->pt() << "; H/E = "<<  goodPhotons[2]->hadTowOverEm() << endl;

  //Fill Info
  ExoDiPhotons::FillBasicPhotonInfo(fgoodTriPhotonInfo[0],  &(*goodPhotons[0]));
  ExoDiPhotons::FillBasicPhotonInfo(fgoodTriPhotonInfo[1], &(*goodPhotons[1]));
  ExoDiPhotons::FillBasicPhotonInfo(fgoodTriPhotonInfo[2],  &(*goodPhotons[2]));
   
  // cout << "Photon 1: " <<"pt = " << fgoodTriPhotonInfo[0].pt << "; H/E = " << fgoodTriPhotonInfo[0].hadTowerOverEm << endl;
  // cout << "Photon 2: " << "pt = " <<  fgoodTriPhotonInfo[1].pt << "; H/E = "<<   fgoodTriPhotonInfo[1].hadTowerOverEm << endl;
  // cout << "Photon 3: " << "pt = " << fgoodTriPhotonInfo[2].pt << "; H/E = "<<  fgoodTriPhotonInfo[2].hadTowerOverEm << endl;
  
  fTree->Fill();
  }
  
cout << "======================================RUN ENDS==================================" <<endl;
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
TriphotonAnalyzerTest::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TriphotonAnalyzerTest::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TriphotonAnalyzerTest::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TriphotonAnalyzerTest);