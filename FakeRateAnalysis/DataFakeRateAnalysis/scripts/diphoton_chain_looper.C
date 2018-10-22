#include "FakeRateAnalysis.C"

void diphoton_chain_looper(TString run, TString dataset) {

  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015C_25ns-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015D-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/FakeRateMerged/diphoton_fakeRate_JetHT_Run2015C_25ns-16Dec2015-v1_MINIAOD_merged.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/FakeRateMerged/diphoton_fakeRate_JetHT_Run2015D-16Dec2015-v1_MINIAOD_merged.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/AlternativeDenomDefNtuples/Merged/JetHT_Run2015C_25ns-16Dec2015-v1_MINIAOD_DENOM2/merged.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/AlternativeDenomDefNtuples/Merged/JetHT_Run2015D-16Dec2015-v1_MINIAOD_DENOM2/merged.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FakeRate/WithTriggerAndJetInfo/JetHT_Run2015C_15Dec2015ReReco.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FakeRate/WithTriggerAndJetInfo/JetHT_Run2015D_15Dec2015ReReco.root",0);
  if(dataset=="jetht") {
    if(run=="2015") {
      chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/JetHT_Run2015C.root",0);
      chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/JetHT_Run2015D.root",0);
    }
    if(run=="Run2017B" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2017B-31Mar2018-v1__MINIAOD/181021_053437/0000/*.root");
    }
    if(run=="Run2017C" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2017C-31Mar2018-v1__MINIAOD/181021_053459/0000/*.root");
    }
    if(run=="Run2017D" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2017D-31Mar2018-v1__MINIAOD/181021_053520/0000/*.root");
    }
    if(run=="Run2017E" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2017E-31Mar2018-v1__MINIAOD/181021_053542/0000/*.root");
    }
    if(run=="Run2017F" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2017F-31Mar2018-v1__MINIAOD/181021_053606/0000/*.root");
    }
    if(run=="Run2018A" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181003_233747/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181003_233747/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181003_233747/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181003_233747/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181003_233819/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181003_233819/0001/*.root",0);
    }
    if(run=="Run2018B" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181003_233839/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181003_233839/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181003_233839/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181003_233839/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v2__MINIAOD/181003_233855/0000/*.root",0);
    }
    if(run=="Run2018C" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v1__MINIAOD/181003_233913/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181003_233929/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181003_233929/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181001_212426/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181001_212426/0001/*.root",0);
    }
    if(run=="Run2018D" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0005/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181003_234009/0006/*.root",0);
    }
  }
  if(dataset=="doublemuon") {
    if(run=="Run2017B" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2017B-31Mar2018-v1__MINIAOD/181021_053626/0000/*.root");
    }
    if(run=="Run2017C" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2017C-31Mar2018-v1__MINIAOD/181021_053649/0000/*.root");
    }
    if(run=="Run2017D" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2017D-31Mar2018-v1__MINIAOD/181021_053712/0000/*.root");
    }
    if(run=="Run2017E" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2017E-31Mar2018-v1__MINIAOD/181021_053735/0000/*.root");
    }
    if(run=="Run2017F" or run=="2017") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2017F-31Mar2018-v1__MINIAOD/181021_053759/0000/*.root");
    }
    if(run=="Run2018A" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181010_181659/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181010_181659/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181010_181659/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181010_181659/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v2__MINIAOD/181010_181713/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v3__MINIAOD/181010_181729/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v3__MINIAOD/181010_181729/0001/*.root",0);
    }
    if(run=="Run2018B" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181010_181744/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181010_181744/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181010_181744/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v2__MINIAOD/181010_181800/0000/*.root",0);
    }
    if(run=="Run2018C" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v1__MINIAOD/181010_181815/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v2__MINIAOD/181010_181831/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v2__MINIAOD/181010_181831/0001/*.root",0);
    }
    if(run=="Run2018D" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0005/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181010_181902/0006/*.root",0);
    }
  }
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  FakeRateAnalysis ptl(chain);

  // loop over all entries of our tree
  ptl.Loop(0, run, dataset);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
