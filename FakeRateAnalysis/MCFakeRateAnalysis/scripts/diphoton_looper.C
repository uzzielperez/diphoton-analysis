#include "MCFakeRateAnalysis.C"

void diphoton_looper() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");

  // ntuple path (change as needed)
  TString ntuple_path = "/store/user/abuccill/diphoton-analysis/fake_rate_real_templates";
  
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-60To200_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-500To1000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-2000To4000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-6000To8000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_real_templates_GGJets_M-8000To13000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);

  // list chain and entries
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  MCFakeRateAnalysis loop(chain);

  // loop over all entries of our tree
  loop.Loop();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
