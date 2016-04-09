#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TSystem.h"
#include "TString.h"
#include "TStopwatch.h"
#include <iostream>

#include "MCFakeRateClosureTest.C"

using namespace std;

void diphoton_fTree_looper(const Char_t *iMass) {  
  // use stopwatch for timing
  TStopwatch sw;
  sw.Start();
  
  // use input mass to specify input file
  cout << "Input Mass: " << iMass << endl;
  TString filename = TString::Format("root://cmsxrootd.fnal.gov///store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_QCD_Pt-%s_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",iMass);
  
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
  MCFakeRateClosureTest ptl(tree);

  // loop over all entries of our tree
  ptl.Loop(iMass,10.,15.);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes 
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
