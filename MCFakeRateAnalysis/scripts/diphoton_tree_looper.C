#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TSystem.h"
#include "TString.h"
#include "TStopwatch.h"
#include <iostream>

#include "MCFakeRateAnalysis.C"

using namespace std;

void diphoton_tree_looper(const Char_t *iMass) {  
  // use stopwatch for timing
  TStopwatch sw;
  sw.Start();
  
  // use input mass to specify input file
  cout << "Input Mass: " << iMass << endl;
  TString filename = TString::Format("root://cmsxrootd.fnal.gov///store/user/abuccill/DiPhotonAnalysis/MCFakeRateMerged/diphoton_fakeRate_GGJets_M-%s_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",iMass);
  
  // use file to get tree data
  TFile *f = TFile::Open(filename);
  
  // list file contents
  f->ls();

  // get tree from file
  TTree *tree = (TTree *) f->Get("diphoton/fTree");

  // print tree
  //tree->Print();

  // print number of entries
  cout << "Total number of entries: " << tree->GetEntries() << endl;

  // load file to loop over entries
  //gROOT->LoadMacro("AnalyzeEvent.C");
  //gSystem->CompileMacro("AnalyzeEvent.C");

  // create instance using our tree
  MCFakeRateAnalysis ptl(tree);

  // loop over all entries of our tree
  ptl.Loop(iMass);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes 
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
