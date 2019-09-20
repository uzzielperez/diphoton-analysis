#include "FakeRateAnalysis.C"

void diphoton_chain_looper(TString run, TString dataset, int npvLow = 0, int npvHigh = 2000) {

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
    if(run=="Run2016B" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016B-17Jul2018_ver2-v2__MINIAOD/190308_223624/0000/*.root",0);
    }
    if(run=="Run2016C" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016C-17Jul2018-v1__MINIAOD/190308_223637/0000/*.root",0);
    }
    if(run=="Run2016D" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016D-17Jul2018-v1__MINIAOD/190308_223649/0000/*.root",0);
    }
    if(run=="Run2016E" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016E-17Jul2018-v1__MINIAOD/190308_223702/0000/*.root",0);
    }
    if(run=="Run2016F" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016F-17Jul2018-v1__MINIAOD/190308_223714/0000/*.root",0);
    }
    if(run=="Run2016G" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016G-17Jul2018-v1__MINIAOD/190308_223729/0000/*.root",0);
    }
    if(run=="Run2016H" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/JetHT/crab_JetHT__Run2016H-17Jul2018-v1__MINIAOD/190308_223742/0000/*.root",0);
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
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-17Sep2018-v1__MINIAOD/181115_215140/0005/*.root",0);
    }
    if(run=="Run2018Aprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181130_211700/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181130_211700/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181130_211700/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v1__MINIAOD/181130_211700/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v2__MINIAOD/181130_211716/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181130_211731/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181130_211731/0001/*.root",0);
    }
    if(run=="Run2018B" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-17Sep2018-v1__MINIAOD/181115_215156/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-17Sep2018-v1__MINIAOD/181115_215156/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-17Sep2018-v1__MINIAOD/181115_215156/0002/*.root",0);
    }
    if(run=="Run2018Bprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181130_211747/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181130_211747/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181130_211747/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v2__MINIAOD/181130_211801/0000/*.root",0);
    }
    if(run=="Run2018C" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-17Sep2018-v1__MINIAOD/190103_172712/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-17Sep2018-v1__MINIAOD/190103_172712/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-17Sep2018-v1__MINIAOD/190103_172712/0002/*.root",0);
    }
    if(run=="Run2018Cprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v1__MINIAOD/181130_211816/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181130_211830/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181130_211830/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181130_211845/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181130_211845/0001/*.root",0);
    }
    if(run=="Run2018D" or run=="2018" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0005/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0006/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0007/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0008/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181130_212625/0009/*.root",0);
    }
  }
  if(dataset=="doublemuon") {
    if(run=="Run2016B" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016B-17Jul2018_ver2-v1__MINIAOD/190308_222833/0000/*.root",0);
    }
    if(run=="Run2016C" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016C-17Jul2018-v1__MINIAOD/190308_223056/0000/*.root",0);
    }
    if(run=="Run2016D" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016D-17Jul2018-v1__MINIAOD/190308_164519/0000/*.root",0);
    }
    if(run=="Run2016E" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016E-17Jul2018-v1__MINIAOD/190308_223111/0000/*.root",0);
    }
    if(run=="Run2016F" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016F-17Jul2018-v1__MINIAOD/190308_223123/0000/*.root",0);
    }
    if(run=="Run2016G" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016G-17Jul2018-v1__MINIAOD/190308_223136/0000/*.root",0);
    }
    if(run=="Run2016H" or run=="2016") {
      chain->Add("root://cmseos.fnal.gov//store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2016H-17Jul2018-v1__MINIAOD/190308_223149/0000/*.root",0);
    }
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
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-17Sep2018-v2__MINIAOD/190115_215157/0005/*.root",0);
    }
    if(run=="Run2018Aprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181128_204823/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181128_204823/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181128_204823/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v1__MINIAOD/181128_204823/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v2__MINIAOD/181128_213957/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v3__MINIAOD/181128_214013/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018A-PromptReco-v3__MINIAOD/181128_214013/0001/*.root",0);
    }
    if(run=="Run2018B" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-17Sep2018-v1__MINIAOD/190115_215215/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-17Sep2018-v1__MINIAOD/190115_215215/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-17Sep2018-v1__MINIAOD/190115_215215/0002/*.root",0);
    }
    if(run=="Run2018Bprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181128_214030/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181128_214030/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v1__MINIAOD/181128_214030/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018B-PromptReco-v2__MINIAOD/181128_214045/0000/*.root",0);
    }
    if(run=="Run2018C" or run=="Run2018Ctest" or run=="2018") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-17Sep2018-v1__MINIAOD/190115_215229/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-17Sep2018-v1__MINIAOD/190115_215229/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-17Sep2018-v1__MINIAOD/190115_215229/0002/*.root",0);
    }
    if(run=="Run2018Cprompt" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v1__MINIAOD/181128_214100/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v2__MINIAOD/181206_015946/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v2__MINIAOD/181206_015946/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v3__MINIAOD/181128_214629/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018C-PromptReco-v3__MINIAOD/181128_214629/0001/*.root",0);
    }
    if(run=="Run2018D" or run=="2018" or run=="2018prompt") {
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0000/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0001/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0002/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0003/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0004/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0005/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0006/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0007/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0008/*.root",0);
      chain->Add("root://cmseos.fnal.gov//eos/uscms/store/user/cawest/DoubleMuon/crab_DoubleMuon__Run2018D-PromptReco-v2__MINIAOD/181129_230306/0009/*.root",0);
    }
  }
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  FakeRateAnalysis ptl(chain);

  // loop over all entries of our tree
  if(dataset=="jetht") {
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
