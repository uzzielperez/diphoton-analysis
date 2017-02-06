#include <iostream>
#include "TFile.h"
#include "TTree.h"

void diphoton_makeClass() {
  // load file
  TFile *f = TFile::Open("root://cmsxrootd.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_real_templates/diphoton_fake_rate_real_templates_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root");
  
  // list the contents of this file
  f->ls();

  // get tree
  TTree *tree = (TTree *) f->Get("diphoton/fTree");

  // print tree contents
  tree->Print();

  // list the total number of entries in tree
  cout << "Entries: " << tree->GetEntries() << endl;
  
  // make class
  tree->MakeClass("MCFakeRateAnalysis");
}
