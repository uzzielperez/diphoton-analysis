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

  if (do_fakes) cout << "Running analysis class MCFakeRateClosureTestWithFakes.C for MC as truth" << endl;
  else cout << "Running analysis class MCFakeRateClosureTest.C for MC as fakes" << endl;
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
  TString ntuple_path("root://cmseos.fnal.gov//store/user/cawest/");

  // create tchain of all files to loop over
  TChain *chain = new TChain(tree);

  if (run == "2016") {
    ntuple_path = "/store/user/abuccill/diphoton-analysis/fake_rate_closure_test";
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

    if (sample== "all" || sample == "GGJets") {
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
    if (sample == "all" || sample == "QCD") {
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_50to80_TuneCP5_13TeV_pythia8/crab_QCD_Pt_50to80_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034131/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_50to80_TuneCP5_13TeV_pythia8/crab_QCD_Pt_50to80_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034115/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_80to120_TuneCP5_13TeV_pythia8/crab_QCD_Pt_80to120_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034149/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_80to120_TuneCP5_13TeV_pythia8/crab_QCD_Pt_80to120_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034205/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_120to170_TuneCP5_13TeV_pythia8/crab_QCD_Pt_120to170_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034223/0000//*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_170to300_TuneCP5_13TeV_pythia8/crab_QCD_Pt_170to300_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034256/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_170to300_TuneCP5_13TeV_pythia8/crab_QCD_Pt_170to300_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034241/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_300to470_TuneCP5_13TeV_pythia8/crab_QCD_Pt_300to470_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034332/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_300to470_TuneCP5_13TeV_pythia8/crab_QCD_Pt_300to470_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v3__MINIAODSIM/201002_034315/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_470to600_TuneCP5_13TeV_pythia8/crab_QCD_Pt_470to600_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034406/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_470to600_TuneCP5_13TeV_pythia8/crab_QCD_Pt_470to600_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v3__MINIAODSIM/201002_034350/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_600to800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_600to800_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034443/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_600to800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_600to800_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034426/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_800to1000_TuneCP5_13TeV_pythia8/crab_QCD_Pt_800to1000_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034517/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_800to1000_TuneCP5_13TeV_pythia8/crab_QCD_Pt_800to1000_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034501/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v2__MINIAODSIM/201002_034535/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034552/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034609/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/3104b1c/QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v3__MINIAODSIM/201002_033825/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034626/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8/crab_QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034642/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8/crab_QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM/201002_034717/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8/crab_QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8__Fall17_94X_mc2017_realistic_v14_ext1-v1__MINIAODSIM/201002_034700/0000/*.root");
    }
    if (sample == "all" || sample == "GJets") {
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v2__MINIAODSIM_resub/200904_235904/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/200905_000007/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/200905_000330/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v1__MINIAODSIM_resub/200905_000726/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17-v2__MINIAODSIM_resub/200905_000637/0000/*.root");
    }
    if (sample == "all" || sample == "GGJets") {
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_233439/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_232918/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_233026/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_232739/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v2__MINIAODSIM_resub/200904_233559/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v2__MINIAODSIM_resub/200904_233641/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_233321/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/2c8bbea/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Fall17_94X_mc2017_realistic_v14-v1__MINIAODSIM_resub/200904_233735/0000/*.root");
    }
  }
  if (run == "2018") {
    if (sample == "all" || sample == "QCD") {
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_50to80_TuneCP5_13TeV_pythia8/crab_QCD_Pt_50to80_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_034734/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_50to80_TuneCP5_13TeV_pythia8/crab_QCD_Pt_50to80_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034749/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_80to120_TuneCP5_13TeV_pythia8/crab_QCD_Pt_80to120_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034807/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_120to170_TuneCP5_13TeV_pythia8/crab_QCD_Pt_120to170_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034826/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_170to300_TuneCP5_13TeV_pythia8/crab_QCD_Pt_170to300_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034843/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_300to470_TuneCP5_13TeV_pythia8/crab_QCD_Pt_300to470_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034900/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_470to600_TuneCP5_13TeV_pythia8/crab_QCD_Pt_470to600_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_034919/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_470to600_TuneCP5_13TeV_pythia8/crab_QCD_Pt_470to600_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034934/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_600to800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_600to800_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_034951/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_800to1000_TuneCP5_13TeV_pythia8/crab_QCD_Pt_800to1000_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_035008/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_035026/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_035043/0000/*.root");
      // /QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM is not available
      // since the dataset has the same number of events as the other QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8 dataset and the dataset sizes are identical, just add the dataset twice
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_035043/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_035134/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8/crab_QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_035116/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8/crab_QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_035207/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8/crab_QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8__Autumn18_ext1-v2__MINIAODSIM/201002_035151/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8/crab_QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8__Autumn18-v1__MINIAODSIM/201002_035243/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/dc44792/QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8/crab_QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8__Autumn18_ext2-v2__MINIAODSIM/201002_035226/0000/*.root");
    }
    if (sample == "all" || sample == "GJets") {
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic/200821_031620/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-4cores5k_102X_upgrade2018/200821_021447/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/200821_023518/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/200821_025548/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/11c96ff/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/200821_033205/0000/*.root");
    }
    if (sample == "all" || sample == "GGJets") {
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINI/200730_042411/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MI/200730_151230/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151014/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151138/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_151111/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/200730_150946/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIAO/200730_151203/0000/*.root");
      chain->Add(ntuple_path+"diphoton_closure/27a1c52/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIA/200730_151042/0000/*.root");
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
