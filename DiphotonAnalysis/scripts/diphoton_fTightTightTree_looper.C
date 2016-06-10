#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TSystem.h"
#include "TString.h"
#include "TStopwatch.h"
#include <iostream>

#include "DiphotonAnalysis.C"

using namespace std;

void diphoton_fTightTightTree_looper() {  
  // use stopwatch for timing
  TStopwatch sw;
  sw.Start();
  
  // use file to get tree data
  TFile *f = TFile::Open("root://cmsxrootd.fnal.gov///store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root");
  
  // list file contents
  f->ls();
  
  // get tree from file
  TTree *tree = (TTree *) f->Get("diphoton/fTightTightTree");
  
  // print tree
  //tree->Print();
  
  // print number of entries
  cout << "Total number of entries: " << tree->GetEntries() << endl;
  
  // load file to loop over entries
  //gROOT->LoadMacro("AnalyzeEvent.C");
  //gSystem->CompileMacro("AnalyzeEvent.C");
  
  // create instance using our tree
  DiphotonAnalysis ptl(tree);
  
  // loop over all entries of our tree
  ptl.Loop();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes 
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
