#include <iostream>
#include "TFile.h"
#include "TTree.h"

void diphoton_makeClass() {
  // load file
  TFile *f = TFile::Open("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181001_212426/0000/ExoDiphotonAnalyzer_1.root");
  
  // list the contents of this file
  f->ls();

  // get tree
  TTree *tree = (TTree *) f->Get("diphoton/fTree");

  // print tree contents
  tree->Print();

  // list the total number of entries in tree
  cout << "Entries: " << tree->GetEntries() << endl;
  
  // make class
  tree->MakeClass("FakeRateAnalysis");
}
