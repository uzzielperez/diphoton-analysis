#include "diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/analysis/MCFakeRateClosureTest2.C"

#include "TChain.h"
#include "TStopwatch.h"

#include <iostream>

void diphoton_chain_looper(TString run, TString dataset, int npvLow = 0, int npvHigh = 2000) {

  TString ntuple_path("root://cmseos.fnal.gov//store/user/cawest/");

  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");

  if(dataset=="GGJets") {
    if (run=="2018"){
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIAO/200730_151203/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIA/200730_151042/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINI/200730_042411/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_150946/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151014/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151111/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151138/0000/*.root");
      chain->Add(ntuple_path + "diphoton_closure/27a1c52/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MI/200730_151230/0000/*.root");
    }
    if (run=="2016"){
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-60To200_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-500To1000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-2000To4000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-6000To8000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-8000To13000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    }
  }
  if(dataset=="GJets") {
    if(run=="2016") {
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
    }
  }
  if (dataset=="QCD") {
    // chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_5to10_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    // chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_10to15_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    // chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_15to30_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    // chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root",0);
  }
  chain->ls();
  std::cout << "Total number of entries: " << chain->GetEntries() << std::endl;

  // create instance of class, passing our chain
  MCFakeRateClosureTest2 ptl(chain);

  // loop over all entries of our tree
  if(dataset=="GGJets") {
    // use matching to leading jet
    //    ptl.Loop(1, run, dataset, npvLow, npvHigh);
    ptl.Loop(0, run, dataset, npvLow, npvHigh);
  }
  else {
    ptl.Loop(0, run, dataset, npvLow, npvHigh);
  }
  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
