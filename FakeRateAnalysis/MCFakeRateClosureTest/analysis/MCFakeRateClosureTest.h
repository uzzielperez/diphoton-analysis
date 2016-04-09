//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar 31 14:13:32 2016 by ROOT version 6.02/13
// from TTree fTree/PhotonTree
// found on file: root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root
//////////////////////////////////////////////////////////

#ifndef MCFakeRateClosureTest_h
#define MCFakeRateClosureTest_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MCFakeRateClosureTest {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Long64_t        Event_run;
   Long64_t        Event_LS;
   Long64_t        Event_evnum;
   Long64_t        Event_processid;
   Long64_t        Event_bx;
   Long64_t        Event_orbit;
   Float_t         Event_ptHat;
   Float_t         Event_alphaqcd;
   Float_t         Event_alphaqed;
   Float_t         Event_qscale;
   Float_t         Event_weight0;
   Float_t         Event_weight;
   Int_t           Event_interactingParton1PdgId;
   Int_t           Event_interactingParton2PdgId;
   Bool_t          Event_beamHaloIDLoose;
   Bool_t          Event_beamHaloIDTight;
   Bool_t          Event_beamHaloIDTight2015;
   Float_t         Jet_jetHT;
   Int_t           Jet_nJets;
   Double_t        Photon_pt;
   Double_t        Photon_eta;
   Double_t        Photon_phi;
   Double_t        Photon_scEta;
   Double_t        Photon_scPhi;
   Double_t        Photon_rho;
   Double_t        Photon_chargedHadIso03;
   Double_t        Photon_neutralHadIso03;
   Double_t        Photon_photonIso03;
   Double_t        Photon_rhoCorChargedHadIso03;
   Double_t        Photon_rhoCorNeutralHadIso03;
   Double_t        Photon_rhoCorPhotonIso03;
   Double_t        Photon_corPhotonIso03;
   Double_t        Photon_hadTowerOverEm;
   Double_t        Photon_r9;
   Double_t        Photon_sigmaIetaIeta;
   Double_t        Photon_sigmaIetaIeta5x5;
   Double_t        Photon_sigmaEtaEta;
   Double_t        Photon_sigmaIphiIphi;
   Double_t        Photon_sigmaIphiIphi5x5;
   Double_t        Photon_sigmaIetaIphi;
   Double_t        Photon_sigmaIetaIphi5x5;
   Double_t        Photon_maxEnergyXtal;
   Double_t        Photon_iEta;
   Double_t        Photon_iPhi;
   Double_t        Photon_alphaHighPtID;
   Double_t        Photon_kappaHighPtID;
   Double_t        Photon_phoEAHighPtID;
   Double_t        Photon_chEAegmID;
   Double_t        Photon_nhEAegmID;
   Double_t        Photon_phoEAegmID;
   Bool_t          Photon_passEGMLooseID;
   Bool_t          Photon_passEGMMediumID;
   Bool_t          Photon_passEGMTightID;
   Bool_t          Photon_isEB;
   Bool_t          Photon_isEE;
   Bool_t          Photon_isEBEtaGap;
   Bool_t          Photon_isEBPhiGap;
   Bool_t          Photon_isEERingGap;
   Bool_t          Photon_isEEDeeGap;
   Bool_t          Photon_isEBEEGap;
   Bool_t          Photon_passElectronVeto;
   Bool_t          Photon_passHTowOverE;
   Bool_t          Photon_passChIso;
   Bool_t          Photon_passCorPhoIso;
   Bool_t          Photon_passSieie;
   Bool_t          Photon_passHighPtID;
   Bool_t          Photon_passChIsoDenom;
   Bool_t          Photon_passCorPhoIsoDenom;
   Bool_t          Photon_isFakeable;
   Bool_t          Photon_isNumeratorObjCand;
   Bool_t          Photon_isDenominatorObj;
   Bool_t          Photon_isSaturated;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_Jet;   //!
   TBranch        *b_Photon;   //!

   MCFakeRateClosureTest(TTree *tree=0);
   virtual ~MCFakeRateClosureTest();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(const Char_t *, double, double); // added by me
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MCFakeRateClosureTest_cxx
MCFakeRateClosureTest::MCFakeRateClosureTest(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root:/diphoton");
      dir->GetObject("fTree",tree);

   }
   Init(tree);
}

MCFakeRateClosureTest::~MCFakeRateClosureTest()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MCFakeRateClosureTest::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MCFakeRateClosureTest::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MCFakeRateClosureTest::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_run, &b_Event);
   fChain->SetBranchAddress("Jet", &Jet_jetHT, &b_Jet);
   fChain->SetBranchAddress("Photon", &Photon_pt, &b_Photon);
   Notify();
}

Bool_t MCFakeRateClosureTest::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MCFakeRateClosureTest::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MCFakeRateClosureTest::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MCFakeRateClosureTest_cxx
