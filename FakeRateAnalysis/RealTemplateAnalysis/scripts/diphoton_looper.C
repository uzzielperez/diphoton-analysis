#include "diphoton-analysis/FakeRateAnalysis/RealTemplateAnalysis/analysis/MCFakeRateAnalysis.C"
#include "diphoton-analysis/Tools/interface/sampleList.hh"
#include "TChain.h"
#include "TStopwatch.h"

#include <iostream>
#include <map>

void diphoton_looper(int year, const std::string & sample, int nPVLow, int nPVHigh) {
  // ntuple path (change as needed)
  std::map<int, TString> ntuple_paths;
  ntuple_paths[2016] = "root://cmseos.fnal.gov//eos/uscms/store/user/abuccill/diphoton-analysis/fake_rate_real_templates";
  ntuple_paths[2017] = "root://cmseos.fnal.gov//eos/uscms/store/user/cawest";
  // currently 2017 MC is used for 2018 samples
  ntuple_paths[2018] = "root://cmseos.fnal.gov//eos/uscms/store/user/cawest";
  
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // initialize sample list
  init();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  if (sample == "all" || sample == "GGJets") {
    if(year==2016) {
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-60To200_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-500To1000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-2000To4000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-6000To8000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GGJets_M-8000To13000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
    }
    if(year == 2017) {
      chain->Add(chains["gg_2017"]);
    }
    if(year == 2018) {
      chain->Add(chains["gg_2018"]);
    }
  }

  if (sample == "all" || sample == "GJets") {
    if(year==2016) {
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
      chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
    }
    if(year == 2017) {
      chain->Add(chains["gj_2017"]);
    }
    if(year == 2018) {
      chain->Add(chains["gj_2018"]);
    }
  }

  if (year==2016 && sample == "DiPhotonJets") {
    chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8_76X_MiniAOD_merged.root",0);
  }
  
  // list chain and entries
  chain->ls();
  std::cout << "Total number of entries: " << chain->GetEntries() << std::endl;

  // create instance of class, passing our chain
  MCFakeRateAnalysis loop(chain);

  // loop over all entries of our tree
  loop.Loop(year, sample, nPVLow, nPVHigh);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
