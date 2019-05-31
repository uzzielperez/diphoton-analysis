#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TSystem.h"
#include "TString.h"
#include "TStopwatch.h"
#include <iostream>

#include "../analysis/MCFakeRateClosureTest.C"
#include "../analysis/MCFakeRateClosureTestWithFakes.C"

using namespace std;

void diphoton_looper() {
  // input what sample to run on
  TString sample = "";
  cout << "Enter sample being run on (QCD, GJets, GGJets, or all): ";
  cin >> sample;
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;
  
  // choose what analysis class you want to use (run one at a time)
  bool do_all = false;
  bool do_fakes = true;
  
  if (!do_all && !do_fakes) {
    cout << "Choose an analysis class to run on." << endl;
    return;
  }
  if (do_all) cout << "Running analysis class MCFakeRateClosureTest.C" << endl;
  if (do_fakes) cout << "Running analysis class MCFakeRateClosureTestWithFakes.C" << endl;
  cout << endl;
  
  // use stopwatch for timing
  TStopwatch sw;
  sw.Start();

  // select tree
  TString tree = "";
  if (do_all) tree = "diphoton/fTree";
  if (do_fakes) tree = "diphoton/fTreeFake";

  cout << "Using tree: " << tree << endl;
  
  // ntuple path (change as needed)
  TString ntuple_path = "/store/user/abuccill/diphoton-analysis/fake_rate_closure_test";
  
  // create tchain of all files to loop over
  TChain *chain = new TChain(tree);
  
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

  if (/*sample == "all" || */sample == "GGJets") {
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-60To200_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-500To1000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-2000To4000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-6000To8000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    chain->Add("root://cmsxrootd.fnal.gov/"+ntuple_path+"/diphoton_fake_rate_closure_test_GGJets_M-8000To13000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  }
  
  // list chain and entries
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl;
  
  // create instance using our chain and loop over entries
  if (do_all) {
    MCFakeRateClosureTest loop_all(chain);
    loop_all.Loop();
  }
  if (do_fakes) {
    MCFakeRateClosureTestWithFakes loop_fakes(chain);
    loop_fakes.Loop();
  }
  
  // stop stopwatch
  sw.Stop();
  
  // convert total time to minutes 
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
