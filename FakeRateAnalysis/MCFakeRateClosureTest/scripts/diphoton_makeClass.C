#include <iostream>
#include "TFile.h"
#include "TTree.h"

void diphoton_makeClass() {
  // load file
  TFile *f = TFile::Open("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis//MCFakeRateClosureTest/QCD/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/crab_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_23aug/160823_151856/0000/ExoDiphotonAnalyzer_1.root");
  
  // list the contents of this file
  f->ls();

  // get tree
  TTree *tree = (TTree *) f->Get("diphoton/fTree");

  // print tree contents
  tree->Print();

  // list the total number of entries in tree
  cout << "Entries: " << tree->GetEntries() << endl;
  
  // make class
  tree->MakeClass("MCFakeRateClosureTest");

  // =============
  // get next tree
  // =============
  TTree *treeFake = (TTree *) f->Get("diphoton/fTreeFake");
  
  // print tree contents
  treeFake->Print();
  
  // list the total number of entries in tree
  cout << "Entries: " << treeFake->GetEntries() << endl;
  
  // make class
  treeFake->MakeClass("MCFakeRateClosureTestWithFakes");
}
