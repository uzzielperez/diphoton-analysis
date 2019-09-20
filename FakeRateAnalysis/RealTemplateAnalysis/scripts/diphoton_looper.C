#include "../analysis/MCFakeRateAnalysis.C"

void diphoton_looper(int nPVLow, int nPVHigh) {
  // ntuple path (change as needed)
  std::map<int, TString> ntuple_paths;
  ntuple_paths[2016] = "root://cmseos.fnal.gov//eos/uscms/store/user/abuccill/diphoton-analysis/fake_rate_real_templates";
  ntuple_paths[2017] = "root://cmseos.fnal.gov//eos/uscms/store/user/cawest";
  // currently 2017 MC is used for 2018 samples
  ntuple_paths[2018] = "root://cmseos.fnal.gov//eos/uscms/store/user/cawest";

  // input what sample to run on
  TString sample = "";
  cout << "Enter sample being run on (DiPhotonJets, GGJets, GJets, or all): ";
  cin >> sample;
  if (sample != "DiPhotonJets" && sample != "GGJets" && sample != "GJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  int year;
  cout << "Enter year (2016, 2017 or 2018):";
  cin >> year;
  if(year != 2016 and year != 2017 and year != 2018) {
    cout << "Invalid choice!" << std::endl;
  }
  cout << "\nUsing sample: " << sample << " for analysis of " << year << " data." << endl;
  cout << endl;
  
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

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
    if(year==2017 || year==2018) {
      chain->Add(ntuple_paths[year]+"/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14/180802_182753/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v1/180802_182810/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v/180802_182827/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/180802_182843/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/181023_222120/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/181023_222138/0000/*.root");
      // chain->Add(ntuple_paths[year]+"/*.root");

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
    if(year==2017 || year==2018) {
      chain->Add(ntuple_paths[year]+"/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_1core_94X/180802_182943/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/180802_183001/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/180802_183020/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/181023_222158/0000/*.root");
      chain->Add(ntuple_paths[year]+"/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/180802_183039/0000/*.root");
    }
  }

  if (year==2016 && sample == "DiPhotonJets") {
    chain->Add(ntuple_paths[year]+"/diphoton_fake_rate_real_templates_DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8_76X_MiniAOD_merged.root",0);
  }
  
  // list chain and entries
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  MCFakeRateAnalysis loop(chain);

  // loop over all entries of our tree
  loop.Loop(year, nPVLow, nPVHigh);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
