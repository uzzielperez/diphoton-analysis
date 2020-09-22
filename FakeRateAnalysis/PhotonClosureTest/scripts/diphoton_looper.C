#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TSystem.h"
#include "TString.h"
#include "TStopwatch.h"
#include <iostream>

#include "diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/analysis/MCFakeRateClosureTest.C"
#include "diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/analysis/MCFakeRateClosureTestWithFakes.C"

using namespace std;

void diphoton_looper(TString run, TString sample, bool do_fakes) {
  cout << "\nUsing sample: " << sample << endl;
  
  if (do_fakes) cout << "Running analysis class MCFakeRateClosureTestWithFakes.C" << endl;
  else cout << "Running analysis class MCFakeRateClosureTest.C" << endl;
  cout << endl;
  
  // use stopwatch for timing
  TStopwatch sw;
  sw.Start();

  // select tree
  TString tree = "";
  if (do_fakes) tree = "diphoton/fTreeFake";
  else tree = "diphoton/fTree";
  cout << "Using tree: " << tree << endl;
  
  // ntuple path (change as needed)
  TString ntuple_path = "/store/user/abuccill/diphoton-analysis/fake_rate_closure_test";
  
  // create tchain of all files to loop over
  TChain *chain = new TChain(tree);

  if (run == "2016") {  
    if (sample == "all" || sample == "QCD") {
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
  
    if (sample == "all" || sample == "GJets") {
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
    }

    if (sample == "GGJets") {
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
  if (run == "2017") {
    if (sample == "all" || sample == "GJets") {
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v2__MINIAODSIM_resub/200904_\
235904/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/20090\
5_000007/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/20090\
5_000330/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/20090\
5_000726/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v2__MINIAODSIM_resub/20090\
5_000637/0000/*.root");
    }
    if (sample == "all" || sample == "GGJets") {
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_23343\
9/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_232\
918/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_2\
33026/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904\
_232739/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v2__MINIAODSIM_resub/200904\
_233559/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v2__MINIAODSIM_resub/200904\
_233641/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904\
_233321/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/2009\
04_233735/0000/*.root");
    }
  }
  if (run == "2018") {
    if (sample == "all" || sample == "GJets") {
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade20\
18_realistic/200821_031620/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-4cores5k_102\
X_upgrade2018/200821_021447/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade\
2018_realisti/200821_023518/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade\
2018_realisti/200821_025548/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade\
2018_realisti/200821_033205/0000/*.root");
    }
    if (sample == "all" || sample == "GGJets") {
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINI/\
200730_042411/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__M\
I/200730_151230/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN\
/200730_151014/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN\
/200730_151138/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN\
/200730_151111/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN\
/200730_150946/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIAO/20\
0730_151203/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIA/2\
00730_151042/0000/*.root");
    }
  }
  
  // list chain and entries
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl;
  
  // create instance using our chain and loop over entries
  if (do_fakes) {
    MCFakeRateClosureTestWithFakes loop_fakes(chain);
    loop_fakes.Loop(run, sample);
  }
  else {
    MCFakeRateClosureTest loop_all(chain);
    loop_all.Loop(run, sample);
  }
  
  // stop stopwatch
  sw.Stop();
  
  // convert total time to minutes 
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
