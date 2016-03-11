#include "MCFakeRateAnalysis.C"

void diphoton_chain_looper() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  chain->Add("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateMerged/diphoton_fakeRate_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  MCFakeRateAnalysis ptl(chain);

  // loop over all entries of our tree
  ptl.Loop();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
