#include <iostream>
#include "TFile.h"
#include "TTree.h"

void diphoton_makeClass() {
  // load file
  TFile *f = TFile::Open("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root");
  
  // list the contents of this file
  f->ls();

  // get tree
  TTree *tree = (TTree *) f->Get("diphoton/fTightTightTree");

  // print tree contents
  tree->Print();

  // list the total number of entries in tree
  cout << "Entries: " << tree->GetEntries() << endl;
  
  // make class
  tree->MakeClass("DiphotonAnalysis");

  // =============
  // get next tree
  // =============
  // TTree *treeFake = (TTree *) f->Get("diphoton/fTreeFake");
  
  // // print tree contents
  // treeFake->Print();
  
  // // list the total number of entries in tree
  // cout << "Entries: " << treeFake->GetEntries() << endl;
  
  // // make class
  // treeFake->MakeClass("MCFakeRateClosureTestWithFakes");
}
