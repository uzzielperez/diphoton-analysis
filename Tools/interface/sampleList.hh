// This file defines the samples that are used, the chains that specify their
// locations and basic formatting for the samples.
// It can be used by including the header and then calling
// init()
// to initialize the chains.
#ifndef SAMPLELIST_HH
#define SAMPLELIST_HH

#include "TChain.h"
#include "TSystem.h"

#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include <linux/limits.h>

#include "diphoton-analysis/Tools/interface/tdrstyle.hh"

// 20.3 fb^-1 were acquired in 2018 before loss of HEM15/HEM16
// 59.97 fb^-1 are validated but only 59.28 fb^-1 available in EGamma dataset
std::map<std::string, double> luminosity { {"2015", 2.62}, {"2016", 35.9}, {"2017", 41.527}, {"2018", 59.67}, {"2018_newjson", 14.00}, {"2018ABC_prompt", 28.04}, {"2018ABC_rereco", 28.04}, {"2018AB", 14.00+7.10}, {"2018ABC", 14.00+7.10+6.94}, {"2018D", 31.93}};
std::map<std::string, double> luminosityErrorFrac { {"2015", 0.023}, {"2016", 0.026}, {"2017", 0.023}, {"2018", 0.025}, {"2018_newjson", 0.025}, {"2018ABC_prompt", 0.025}, {"2018ABC_rereco", 0.025}, {"2018AB", 0.025}, {"2018ABC", 0.025}, {"2018D", 0.025}};

std::map<std::string, TChain*> chains;
std::map<std::string, int> lineStyles;
std::map<std::string, int> lineColors;
std::map<std::string, int> fillStyles;
std::map<std::string, int> fillColors;
std::map<std::string, int> markerColors;
std::map<std::string, std::string> prettyName;

TString filestring(TString sample);
void init(bool includeUnskimmmed, bool includeSignal); // initializes samples; can skip long initialization of unskimmed samples
void initADD2016(const TString & baseDirectory); // initializes 2016 ADD samples; performed by a loop rather than being listed explicitly
void initADD(const TString & baseDirectory); // initializes ADD samples; performed by a loop rather than being listed explicitly
void initRSG(const TString & baseDirectory); // initializes RSG samples; performed by a loop rather than being listed explicitly
void initHeavyHiggs(const TString & baseDirectory); // initializes Heavy Higgs samples; performed by a loop rather than being listed explicitly
void listSamples(); // list the available samples

TString filestring(TString sample)
{
  // paths are defined as symbolic links here
  TString directory(Form("/uscms/homes/c/cawest/links/%s", sample.Data()));
  char resolved_path[PATH_MAX];

  // resolve the symbolic link
  ssize_t r = readlink(directory.Data(), resolved_path, PATH_MAX);
  // if it fails, try filename directly
  if(r==-1) {
    return Form("%s/*.root", directory.Data());
  }
  // if we were successful, convert symbolic link to xrootd path
  else {
    // have to null terminate manually
    resolved_path[r] = '\0';

    // convert AFS path to xrootd path
    TString mypath(resolved_path);
    //    mypath.ReplaceAll("/afs/cern.ch/user/c/cawest/eos/cms", "root://eoscms.cern.ch/");
    mypath.ReplaceAll("/uscms/homes/c/cawest", "root://cmseos.fnal.gov/");
    mypath += "/*.root";
    return mypath;
  }
}

void listSamples()
{
  for(const auto& ichain : chains) {
    std::cout << ichain.first << std::endl;
  }
}

std::vector<std::string> getSampleList()
{
  std::vector<std::string> list;

  for(const auto& ichain : chains) {
    list.push_back(ichain.first);
  }

  return list;
}

void init(bool includeUnskimmed = false, bool includeSignal = false)
{
  TString treeType("diphoton/fTree");
  TString baseDirectory("root://cmseos.fnal.gov/");

  TChain *chData2018AB_rereco = new TChain(treeType);
  chData2018AB_rereco->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/*.root");
  chData2018AB_rereco->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018B-17Sep2018-v1__MINIAOD/191115_212444/*.root");

  TChain *chData2018ABC_rereco = new TChain(treeType);
  chData2018ABC_rereco->Add(chData2018AB_rereco);
  chData2018ABC_rereco->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018B-17Sep2018-v1__MINIAOD/191115_212444/*.root");
  chData2018ABC_rereco->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018C-17Sep2018-v1__MINIAOD/191115_212505/*.root");

  TChain *chData2018ABC_prompt = new TChain(treeType);
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v1__MINIAOD/181128_144406/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v2__MINIAOD/181128_144424/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v3__MINIAOD/181128_144442/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v1__MINIAOD/181128_144502/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v2__MINIAOD/181128_144518/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v1__MINIAOD/181128_144536/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v2__MINIAOD/181128_144555/*.root");
  chData2018ABC_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v3__MINIAOD/181128_144612/*.root");

  TChain *chData2018_newjson = new TChain(treeType);
  chData2018_newjson->Add(baseDirectory + "/store/user/cawest/diphoton/1d2157e/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191107_231838/*.root");

  TChain *chData2018D = new TChain(treeType);
  chData2018D->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/*.root");

  // skimmed version of chData2018_unskimmed
  TChain *chData2018 = new TChain(treeType);
  chData2018->Add(chData2018ABC_rereco);
  chData2018->Add(chData2018D);

  TChain *chData2018_prompt = new TChain(treeType);
  chData2018_prompt->Add(chData2018ABC_prompt);
  chData2018_prompt->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/*.root");

  TChain *chData2018ABC_rereco_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0000/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0001/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0002/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0003/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0004/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018A-17Sep2018-v2__MINIAOD/191115_212609/0005/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018B-17Sep2018-v1__MINIAOD/191115_212444/0000/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018B-17Sep2018-v1__MINIAOD/191115_212444/0001/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018B-17Sep2018-v1__MINIAOD/191115_212444/0002/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018C-17Sep2018-v1__MINIAOD/191115_212505/0000/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018C-17Sep2018-v1__MINIAOD/191115_212505/0001/*.root");
    chData2018ABC_rereco_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018C-17Sep2018-v1__MINIAOD/191115_212505/0002/*.root");
  }
  TChain *chData2018ABC_prompt_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v1__MINIAOD/181128_144406/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v1__MINIAOD/181128_144406/0001/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v1__MINIAOD/181128_144406/0002/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v1__MINIAOD/181128_144406/0003/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v2__MINIAOD/181128_144424/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v3__MINIAOD/181128_144442/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018A-PromptReco-v3__MINIAOD/181128_144442/0001/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v1__MINIAOD/181128_144502/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v1__MINIAOD/181128_144502/0001/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v1__MINIAOD/181128_144502/0002/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018B-PromptReco-v2__MINIAOD/181128_144518/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v1__MINIAOD/181128_144536/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v2__MINIAOD/181128_144555/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v2__MINIAOD/181128_144555/0001/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v3__MINIAOD/181128_144612/0000/*.root");
    chData2018ABC_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018C-PromptReco-v3__MINIAOD/181128_144612/0001/*.root");
  }

  TChain *chData2018_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2018_unskimmed->Add(chData2018ABC_rereco_unskimmed);
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0000/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0001/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0002/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0003/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0004/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0005/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0006/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0007/*.root");
    chData2018_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/EGamma/crab_EGamma__Run2018D-22Jan2019-v2__MINIAOD/191115_212527/0008/*.root");
  }

  TChain *chData2018_prompt_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2018_prompt_unskimmed->Add(chData2018ABC_prompt_unskimmed);
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0000/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0001/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0002/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0003/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0004/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0005/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0006/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0007/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0008/*.root");
    chData2018_prompt_unskimmed->Add(baseDirectory + "/store/user/cawest/EGamma/crab_EGamma__Run2018D-PromptReco-v2__MINIAOD/181129_223519/0009/*.root");
  }

  TChain *chDataJetHT2018_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v2__MINIAOD/181109_025710/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181109_025728/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018A-PromptReco-v3__MINIAOD/181109_025728/0001/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181109_025746/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181109_025746/0001/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v1__MINIAOD/181109_025746/0002/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018B-PromptReco-v2__MINIAOD/181109_025803/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v1__MINIAOD/181109_025819/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181109_025836/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v2__MINIAOD/181109_025836/0001/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181109_025852/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018C-PromptReco-v3__MINIAOD/181109_025852/0001/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0000/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0001/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0002/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0003/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0004/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0005/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0006/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0007/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0008/*.root");
    chDataJetHT2018_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2018D-PromptReco-v2__MINIAOD/181109_025928/0009/*.root");
  }

  TChain *chData = new TChain(treeType);
  chData->Add(filestring("DoubleEG__Run2015D"));
  chData->Add(filestring("DoubleEG__Run2015C_25ns"));

  TChain *chData2017_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2017_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017B-31Mar2018-v1__MINIAOD/191204_035400/0000/*.root");
    chData2017_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017C-31Mar2018-v1__MINIAOD/191204_035423/0000/*.root");
    chData2017_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017D-31Mar2018-v1__MINIAOD/191204_035439/0000/*.root");
    chData2017_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017E-31Mar2018-v1__MINIAOD/191204_035516/0000/*.root");
    chData2017_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017F-31Mar2018-v1__MINIAOD/191204_035540/0000/*.root");
  }

  TChain *chData2017 = new TChain(treeType);
  chData2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017B-31Mar2018-v1__MINIAOD/191204_035400/*.root");
  chData2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017C-31Mar2018-v1__MINIAOD/191204_035423/*.root");
  chData2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017D-31Mar2018-v1__MINIAOD/191204_035439/*.root");
  chData2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017E-31Mar2018-v1__MINIAOD/191204_035516/*.root");
  chData2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2017F-31Mar2018-v1__MINIAOD/191204_035540/*.root");

  TChain *chDataJetHT2017_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chDataJetHT2017_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2017B-31Mar2018-v1__MINIAOD/181109_031018/0000/*.root");
    chDataJetHT2017_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2017C-31Mar2018-v1__MINIAOD/181109_153510/0000/*.root");
    chDataJetHT2017_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2017D-31Mar2018-v1__MINIAOD/181109_153529/0000/*.root");
    chDataJetHT2017_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2017E-31Mar2018-v1__MINIAOD/181109_153547/0000/*.root");
    chDataJetHT2017_unskimmed->Add(baseDirectory + "/store/user/cawest/JetHT/crab_JetHT__Run2017F-31Mar2018-v1__MINIAOD/181109_153620/0000/*.root");
  }

  TChain *chData2016_unskimmed = new TChain(treeType);
  if(includeUnskimmed) {
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016B-17Jul2018_ver2-v1__MINIAOD/191204_035607/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016H-17Jul2018-v1__MINIAOD/191204_035845/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016D-17Jul2018-v1__MINIAOD/191204_035709/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016E-17Jul2018-v1__MINIAOD/191204_035739/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016F-17Jul2018-v1__MINIAOD/191204_035805/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016G-17Jul2018-v1__MINIAOD/191204_035827/0000/*.root");
    chData2016_unskimmed->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016C-17Jul2018-v1__MINIAOD/191204_035636/0000/*.root");
  }

  TChain *chData2016 = new TChain(treeType);
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016B-17Jul2018_ver2-v1__MINIAOD/191204_035607/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016H-17Jul2018-v1__MINIAOD/191204_035845/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016D-17Jul2018-v1__MINIAOD/191204_035709/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016E-17Jul2018-v1__MINIAOD/191204_035739/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016F-17Jul2018-v1__MINIAOD/191204_035805/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016G-17Jul2018-v1__MINIAOD/191204_035827/*.root");
  chData2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DoubleEG/crab_DoubleEG__Run2016C-17Jul2018-v1__MINIAOD/191204_035636/*.root");

  TChain *chData2017_2018 = new TChain(treeType);
  chData2017_2018->Add(chData2017);
  chData2017_2018->Add(chData2018);

  TChain *chData2016_2017_2018 = new TChain(treeType);
  chData2016_2017_2018->Add(chData2016);
  chData2016_2017_2018->Add(chData2017_2018);

  TChain *chGG_2018 = new TChain(treeType);
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223346/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223403/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223421/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223438/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223455/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223529/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223512/0000/*.root");
  chGG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223548/0000/*.root");

  TChain *chGG_fake_2018 = new TChain(treeType);
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIAO/191004_223508/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINIA/191004_223521/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MINI/191004_220535/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/191004_223539/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/191004_223551/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/191004_223603/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MIN/191004_223616/0000/*.root");
  chGG_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1__MI/191004_223627/0000/*.root");

  TChain *chGG_2017 = new TChain(treeType);
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192641/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192538/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192602/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192516/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Fall17_PU2017-v2__MINIAODSIM/191204_192703/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Fall17_PU2017-v2__MINIAODSIM/191204_192721/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192620/0000/*.root");
  chGG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192744/0000/*.root");

  TChain *chGG_fake_2017 = new TChain(treeType);
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14/191004_223920/0000/*.root");
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v1/191004_223843/0000/*.root");
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v/191004_223855/0000/*.root");
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/191004_223830/0000/*.root");
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/191004_223934/0000/*.root");
  chGG_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_/191004_223947/0000/*.root");


  TChain *chGG_aMC_2015 = new TChain(treeType);
  chGG_aMC_2015->Add(filestring("DiPhotonJets_MGG-80toInf_2015"));
  TChain *chGG_2016 = new TChain(treeType);
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_/171130_184611/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016/171130_184632/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_201/171130_184657/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184716/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184733/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184751/0000/*.root");
  chGG_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184811/0000/*.root");

  TChain *chGG_fake_2016 = new TChain(treeType);
  TString old_directory("root://cmseos.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_real_templates");
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-60To200_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-500To1000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-1000To2000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-2000To4000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-4000To6000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-6000To8000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);
  chGG_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GGJets_M-8000To13000_Pt-50_13TeV-sherpa_76X_MiniAOD_merged.root",0);

  TChain *chGJ_2018 = new TChain(treeType);
  chGJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-4cores5k_102X_upgrade2018/191115_223609/0000/*.root");
  chGJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191115_223714/0000/*.root");
  chGJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191115_223627/0000/*.root");
  chGJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191115_223653/0000/*.root");
  chGJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18_ext1-v2__MINIAODSIM/191115_223731/0000/*.root");

  TChain *chGJ_fake_2018 = new TChain(treeType);
  chGJ_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realistic/191004_223718/0000/*.root");
  chGJ_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-4cores5k_102X_upgrade2018/191004_223640/0000/*.root");
  chGJ_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/191004_223653/0000/*.root");
  chGJ_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/191004_223705/0000/*.root");
  chGJ_fake_2018->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIAutumn18MiniAOD-102X_upgrade2018_realisti/191004_223731/0000/*.root");

  TChain *chGJ_2017 = new TChain(treeType);
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_192805/0000/*.root");
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_1core_94X/191204_192823/0000/*.root");
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_192844/0000/*.root");
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_192908/0000/*.root");
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_192948/0000/*.root");
  chGJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_192931/0000/*.root");

  TChain *chGJ_fake_2017 = new TChain(treeType);
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_1core_94X/191004_224024/0000/*.root");
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc201/191004_224012/0000/*.root");
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/191004_224038/0000/*.root");
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/191004_224117/0000/*.root");
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/191004_224051/0000/*.root");
  chGJ_fake_2017->Add(baseDirectory + "/store/user/cawest/diphoton_fake/14a6c5e/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc20/191004_224105/0000/*.root");

  TChain *chGJ_2016 = new TChain(treeType);
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194236/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-40To100_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_194212/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194018/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-100To200_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_193955/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194107/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-200To400_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_194044/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194150/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-400To600_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191210_195232/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194322/0000/*.root");
  chGJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_GJets_HT-600ToInf_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_194257/0000/*.root");

  TChain *chGJ_fake_2016 = new TChain(treeType);
  chGJ_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
  chGJ_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
  chGJ_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
  chGJ_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);
  chGJ_fake_2016->Add(old_directory + "/diphoton_fake_rate_real_templates_GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_merged.root",0);

  TChain *chJJ_2016 = new TChain(treeType);
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT100to200_13TeV-MG-PY8__Summer16MiniAODv3-v1__MINIAODSIM/191204_194710/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT200to300_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_204816/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT200to300_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_204756/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT300to500_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_204904/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT300to500_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_204839/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT500to700_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_204941/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT500to700_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_204925/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT700to1000_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_205004/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT700to1000_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_205020/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1000to1500_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_205051/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1000to1500_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_205108/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1500to2000_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_205146/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1500to2000_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_205128/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT2000toInf_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_205203/0000/*.root");
  chJJ_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT2000toInf_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_205221/0000/*.root");


  TChain *chJJ_2017 = new TChain(treeType);
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT100to200_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT100to200_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017_ext1-v1__MINIAODSIM/191204_193346/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT100to200_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT100to200_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_193326/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193411/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_new_pmx_94X_mc/191204_193431/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193452/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_new_pmx_94X_mc/191204_193513/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_193541/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_old_pmx_94X_mc/191204_193559/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_new_pmx_94X_m/191204_193639/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193620/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193749/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr2018_new_pmx_94X_/191204_193809/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_193830/0000/*.root");
  chJJ_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8/crab_QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8__Fall17_PU2017-v2__MINIAODSIM/191204_193852/0000/*.root");

  TChain *chJJ_2018 = new TChain(treeType);
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT100to200_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193415/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT200to300_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT200to300_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193433/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT300to500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT300to500_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193452/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT500to700_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT500to700_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193512/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT700to1000_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT700to1000_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193531/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1000to1500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT1000to1500_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193555/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT1500to2000_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT1500to2000_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193613/0000/*.root");
  chJJ_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/QCD_HT2000toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_QCD_HT2000toInf_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/191120_193632/0000/*.root");

  TChain *chVG_NLO_2016 = new TChain(treeType);
  chVG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext1-v1__MINIAODSIM/191204_194508/0000/*.root");
  chVG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext2-v1__MINIAODSIM/191204_194525/0000/*.root");
  chVG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext3-v1__MINIAODSIM/191204_194546/0000/*.root");
  chVG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext1-v1__MINIAODSIM/191204_194604/0000/*.root");

  TChain *chVG_2016 = new TChain(treeType);
  chVG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-40to130_TuneCUETP8M1_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-40to130_TuneCUETP8M1_13TeV-madgraph__Summer16MiniAODv3-v2__MINIAODSIM/191204_194648/0000/*.root");
  chVG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph__Summer16MiniAODv3-v1__MINIAODSIM/191204_194624/0000/*.root");
  chVG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext1-v1__MINIAODSIM/191204_194604/0000/*.root");

  TChain *chVG_NLO_2017 = new TChain(treeType);
  chVG_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Fall17_PU2017-v3__MINIAODSIM/191204_193210/0000/*.root");
  chVG_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Fall17_PU2017-v3__MINIAODSIM/191204_193302/0000/*.root");

  TChain *chVG_2017 = new TChain(treeType);
  chVG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph__Fall17_PU2017-v3__MINIAODSIM/191204_193008/0000/*.root");
  chVG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph__Fall17_PU2017-v1__MINIAODSIM/191204_193031/0000/*.root");
  chVG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Fall17_PU2017-v3__MINIAODSIM/191204_193302/0000/*.root");

  TChain *chVG_NLO_2018 = new TChain(treeType);
  chVG_NLO_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Autumn18_ext1-v1__MINIAODSIM/191120_193213/0000/*.root");
  chVG_NLO_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Autumn18_ext1-v2__MINIAODSIM/191120_193251/0000/*.root");

  TChain *chVG_2018 = new TChain(treeType);
  chVG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph__Autumn18-v1__MINIAODSIM/191120_193135/0000/*.root");
  chVG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph/crab_WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph__Autumn18-v1__MINIAODSIM/191120_193154/0000/*.root");
  chVG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8__Autumn18_ext1-v2__MINIAODSIM/191120_193251/0000/*.root");

  TChain *chW_2016 = new TChain(treeType);
  chW_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/191204_205240/0000/*.root");
  chW_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_13TeV-MG-PY8__Summer16MiniAODv3_ext2-v2__MINIAODSIM/191204_205304/0000/*.root");

  TChain *chW_2017 = new TChain(treeType);
  chW_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017_ext1-v2__MINIAODSIM/191204_193934/0000/*.root");
  chW_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v3__MINIAODSIM/191204_193914/0000/*.root");

  TChain *chW_2018 = new TChain(treeType);
  chW_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/191120_193829/0000/*.root");

  TChain *chDY_NLO_2016 = new TChain(treeType);
  chDY_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8__Summer16MiniAODv3_ext2-v1__MINIAODSIM/191204_194350/0000/*.root");

  TChain *chDY_2016 = new TChain(treeType);
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/200206_144153/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/200206_144153/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/200206_144208/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/200206_144222/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_13TeV-MG-PY8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/200206_144251/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/200206_144237/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_13TeV-MG-PY8__Summer16MiniAODv3-v2__MINIAODSIM/200206_144304/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_13TeV-MG-PY8__Summer16MiniAODv3-v1__MINIAODSIM/200206_144320/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_13TeV-MG-PY8__Summer16MiniAODv3-v1__MINIAODSIM/200206_144333/0000/*.root");
  chDY_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_13TeV-MG-PY8__Summer16MiniAODv3-v1__MINIAODSIM/200206_144347/0000/*.root");

  TChain *chDY_NLO_2017 = new TChain(treeType);
  chDY_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193132/0000/*.root");
  chDY_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__Fall17_PU2017_ext1-v1__MINIAODSIM/191204_193148/0000/*.root");

  TChain *chDY_2017 = new TChain(treeType);
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-40to70_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-40to70_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/200206_144525/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/200206_144541/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr201/200206_144555/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v2__MINIAODSIM/200206_144608/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr201/200206_144623/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr201/200206_144637/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr20/200206_144652/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8__Fall17_PU2017-v1__MINIAODSIM/200206_144706/0000/*.root");
  chDY_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAODv2-PU2017_12Apr20/200206_144721/0000/*.root");

  TChain *chDY_NLO_2018 = new TChain(treeType);
  chDY_NLO_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__Autumn18-v1__MINIAODSIM/191120_193318/0000/*.root");
  chDY_NLO_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__Autumn18_ext2-v1__MINIAODSIM/191120_193335/0000/*.root");

  TChain *chDY_2018 = new TChain(treeType);
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v1__MINIAODSIM/200206_025122/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200206_025147/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200206_025213/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v7__MINIAODSIM/200206_025242/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200206_025306/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200207_163039/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200207_162922/0000/*.root");
  chDY_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8__Autumn18-v2__MINIAODSIM/200207_162946/0000/*.root");

  TChain *chTTG_NLO_2016 = new TChain(treeType);
  chTTG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/crab_TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8__Summer16MiniAODv3-v2__MINIAODSIM/191204_194423/0000/*.root");
  chTTG_NLO_2016->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/crab_TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8__Summer16MiniAODv3_ext1-v2__MINIAODSIM/191204_194445/0000/*.root");

  TChain *chTTG_2016 = new TChain(treeType);
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__MIN/200206_144431/0000/*.root");
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__MINI/200206_144444/0000/*.root");
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__M/200206_144458/0000/*.root");
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__MI/200206_144512/0000/*.root");
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__MINIA/200206_144401/0000/*.root");
  chTTG_2016->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Summer16MiniAODv3-v1__MINIAO/200206_144415/0000/*.root");

  TChain *chTTG_NLO_2017 = new TChain(treeType);
  chTTG_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/crab_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__Fall17_PU2017_ext1-v1__MINIAODSIM/191204_193110/0000/*.root");
  chTTG_NLO_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/crab_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__Fall17_PU2017-v1__MINIAODSIM/191204_193051/0000/*.root");

  TChain *chTTG_2017 = new TChain(treeType);
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAOD/200206_144805/0000/*.root");
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODS/200206_144819/0000/*.root");
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIA/200206_144833/0000/*.root");
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAO/200206_144846/0000/*.root");
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma100-200_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/200206_144735/0000/*.root");
  chTTG_2017->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma200inf_TuneCP5_PSweights_13TeV-madgraph-pythia8__Fall17_PU2017-v1__MINIAODSIM/200206_144748/0000/*.root");

  TChain *chTTG_NLO_2018 = new TChain(treeType);
  chTTG_NLO_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/crab_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__Autumn18-v1__MINIAODSIM/191120_193353/0000/*.root");

  TChain *chTTG_2018 = new TChain(treeType);
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200207_171510/0000/*.root/");
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Hadronic_ptGamma200inf_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_Hadronic_ptGamma200inf_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200207_162754/0000/*.root");
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200206_034251/0000/*.root");
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_SingleLept_ptGamma200inf_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_SingleLept_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200207_162839/0000/*.root");
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma100-200_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200206_034106/0000/*.root");
  chTTG_2018->Add(baseDirectory + "/store/user/cawest/diphoton/b399c31/TTGamma_Dilept_ptGamma200inf_TuneCP5_13TeV-madgraph-pythia8/crab_TTGamma_Dilept_ptGamma200inf_TuneCP5_13TeV-madgraph-pythia8__Autumn18-v1__MINIAODSIM/200207_162720/0000/*.root");

  // sum of minor backgrounds for use in limit setting
  TChain *chOther_2016 = new TChain(treeType);
  chOther_2016->Add(chVG_2016);
  chOther_2016->Add(chDY_2016);
  chOther_2016->Add(chTTG_2016);
  TChain *chOther_2017 = new TChain(treeType);
  chOther_2017->Add(chVG_2017);
  chOther_2017->Add(chDY_2017);
  chOther_2017->Add(chTTG_2017);
  TChain *chOther_2018 = new TChain(treeType);
  chOther_2018->Add(chVG_2018);
  chOther_2018->Add(chDY_2018);
  chOther_2018->Add(chTTG_2018);

  TChain *chGGGen_2017 = new TChain("diphoton/fSherpaGenTree");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192641/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192538/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192602/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192516/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Fall17_PU2017-v2__MINIAODSIM/191204_192703/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Fall17_PU2017-v2__MINIAODSIM/191204_192721/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192620/0000/*.root");
  chGGGen_2017->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Fall17_PU2017-v1__MINIAODSIM/191204_192744/0000/*.root");

  TChain *chGGGen_2018 = new TChain("diphoton/fSherpaGenTree");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223346/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223403/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223421/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223438/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223455/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223529/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223512/0000/*.root");
  chGGGen_2018->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50_13TeV-sherpa__Autumn18-v1__MINIAODSIM/191115_223548/0000/*.root");

  TChain *chGGGen_2016 = new TChain("diphoton/fSherpaGenTree");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184716/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184733/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016/171130_184632/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184751/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_201/171130_184657/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_20/171130_184811/0000/*.root");
  chGGGen_2016->Add(baseDirectory + "/store/user/cawest/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50_13TeV-sherpa__RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_/171130_184611/0000/*.root");

  // These samples are defined in the same way as the SM background in the signal samples.
  // They are needed to take into account interference of the signal with SM backgrounds.
  TChain *chGG70_2016 = new TChain(treeType);
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/GG_M-200To500_Pt-70_13TeV-sherpa/crab_GG_M-200To500_Pt-70_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_015949/0000/*.root");
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/GG_M-500To1000_Pt-70_13TeV-sherpa/crab_GG_M-500To1000_Pt-70_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020043/0000/*.root");
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/GG_M-1000To2000_Pt-70_13TeV-sherpa/crab_GG_M-1000To2000_Pt-70_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_015936/0000/*.root");
  // 94X version of this sample doesn't exist
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/GG_M-2000To4000_Pt-70_13TeV-sherpa/crab_GG_M-2000To4000_Pt-70_13TeV-sherpa__80XMiniAODv2__MINIAODSIM/181106_183756/0000/*.root");
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/GG_M-4000To8000_Pt-70_13TeV-sherpa/crab_GG_M-4000To8000_Pt-70_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020027/0000/*.root");
  chGG70_2016->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/GG_M-8000To13000_Pt-70_13TeV-sherpa/crab_GG_M-8000To13000_Pt-70_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020100/0000/*.root");

  TChain *chGG70_2017 = new TChain(treeType);
  chGG70_2017->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-500To1000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-500To1000_Pt70_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191020_025700/0000/*.root");
  chGG70_2017->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-1000To2000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-1000To2000_Pt70_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191020_025714/0000/*.root");
  chGG70_2017->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-2000To4000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-2000To4000_Pt70_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191020_025731/0000/*.root");
  chGG70_2017->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-4000To13000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-4000To13000_Pt70_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191020_025751/0000/*.root");

  TChain *chGG70_2018 = new TChain(treeType);
  chGG70_2018->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-500To1000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-500To1000_Pt70_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191020_025100/0000/*.root");
  chGG70_2018->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-1000To2000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-1000To2000_Pt70_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191020_025121/0000/*.root");
  chGG70_2018->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-2000To4000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-2000To4000_Pt70_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191020_025141/0000/*.root");
  // 2018 sample not on disk; currently using 2017 sample
  chGG70_2018->Add(baseDirectory + "/store/user/cawest/diphoton/dbd7b7b/GG_M-4000To13000_Pt70_TuneCP2_13TeV-pythia8/crab_GG_M-4000To13000_Pt70_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191020_025751/0000/*.root");

  std::vector<std::string> sampleNames = {"data", "data_2015", "data_2016", "data_2017", "data_2018", "data_2018_newjson", "data_2017_2018", "gg", "gj", "jj", "vg", "w", "dy", "ttg", "gg70", "gg_2016", "gj_2016"};
  // std::vector<std::string> sampleNames = {"data_2018_newjson", "data_2017_2018",  "gg70"};
  // std::vector<std::string> sampleTypes = {"data", "gg", "gj", "jj", "vg", "w", "dy", "ttg"};
  // std::vector<std::string> years = {"2016", "2017", "2018"};
  // for(auto year : years) {
  //   for(auto sampleType : sampleTypes) {
  //     sampleNames.push_back(sampleType + "_" + year);
  //     std::cout << sampleNames.back() << std::endl;
  //   }
  // }

  chains["data_2015"] = chData;
  chains["data_2016"] = chData2016;
  chains["data_2016_unskimmed"] = chData2016_unskimmed;
  chains["data_2017"] = chData2017;
  chains["data_2017_unskimmed"] = chData2017_unskimmed;
  chains["data_2018_prompt"] = chData2018_prompt;
  chains["data_2018"] = chData2018;
  chains["data_2018ABC_prompt"] = chData2018ABC_prompt;
  chains["data_2018AB"] = chData2018AB_rereco;
  chains["data_2018ABC"] = chData2018ABC_rereco;
  chains["data_2018D"] = chData2018D;
  chains["data_jetht_2017_unskimmed"] = chDataJetHT2017_unskimmed;
  chains["data_jetht_2018_unskimmed"] = chDataJetHT2018_unskimmed;
  chains["data_2018_prompt_unskimmed"] = chData2018_prompt_unskimmed;
  chains["data_2018_unskimmed"] = chData2018_unskimmed;
  chains["data_2018_newjson"] = chData2018_newjson;
  chains["data_2017_2018"] = chData2017_2018;
  chains["data_2016_2017_2018"] = chData2016_2017_2018;
  chains["gg_aMC_2015"] = chGG_aMC_2015;
  chains["gg_2018"] = chGG_2018;
  chains["gg_2017"] = chGG_2017;
  chains["gg_2016"] = chGG_2016;
  chains["gg_fake_2018"] = chGG_fake_2018;
  chains["gg_fake_2017"] = chGG_fake_2017;
  chains["gg_fake_2016"] = chGG_fake_2016;
  chains["ggGen"] = chGGGen_2016;
  chains["gg_gen_2016"] = chGGGen_2016;
  chains["gg_gen_2017"] = chGGGen_2017;
  chains["gg_gen_2018"] = chGGGen_2018;
  chains["gj_2018"] = chGJ_2018;
  chains["gj_2017"] = chGJ_2017;
  chains["gj_2016"] = chGJ_2016;
  chains["gj_fake_2018"] = chGJ_fake_2018;
  chains["gj_fake_2017"] = chGJ_fake_2017;
  chains["gj_fake_2016"] = chGJ_fake_2016;
  chains["jj_2018"] = chJJ_2018;
  chains["jj_2017"] = chJJ_2017;
  chains["jj_2016"] = chJJ_2016;
  chains["vg_2018"] = chVG_2018;
  chains["vg_2017"] = chVG_2017;
  chains["vg_2016"] = chVG_2016;
  chains["vg_nlo_2018"] = chVG_NLO_2018;
  chains["vg_nlo_2017"] = chVG_NLO_2017;
  chains["vg_nlo_2016"] = chVG_NLO_2016;
  chains["w_2018"] = chW_2018;
  chains["w_2017"] = chW_2017;
  chains["w_2016"] = chW_2016;
  chains["dy_2018"] = chDY_2018;
  chains["dy_2017"] = chDY_2017;
  chains["dy_2016"] = chDY_2016;
  chains["dy_nlo_2018"] = chDY_NLO_2018;
  chains["dy_nlo_2017"] = chDY_NLO_2017;
  chains["dy_nlo_2016"] = chDY_NLO_2016;
  chains["ttg_2018"] = chTTG_2018;
  chains["ttg_2017"] = chTTG_2017;
  chains["ttg_2016"] = chTTG_2016;
  chains["ttg_nlo_2018"] = chTTG_NLO_2018;
  chains["ttg_nlo_2017"] = chTTG_NLO_2017;
  chains["ttg_nlo_2016"] = chTTG_NLO_2016;
  chains["gg70_2018"] = chGG70_2018;
  chains["gg70_2017"] = chGG70_2017;
  chains["gg70_2016"] = chGG70_2016;
  chains["other_2018"] = chOther_2018;
  chains["other_2017"] = chOther_2017;
  chains["other_2016"] = chOther_2016;

  // signal initialization done separately to avoid clutter
  if(includeSignal) {
    initADD(baseDirectory);
    initRSG(baseDirectory);
    initHeavyHiggs(baseDirectory);
  }

  // set default styles
  for( auto isample : sampleNames ) {
    lineColors[isample] = kBlack;
    fillStyles[isample] = 1001;
    lineStyles[isample] = kSolid;
    markerColors[isample] = kBlack;
  }

  fillColors["data"] = kWhite;
  fillColors["data_2018"] = kWhite;
  fillColors["data_2017"] = kWhite;
  fillColors["data_2016"] = kWhite;
  fillColors["gg"] = kCyan;
  fillColors["gg_aMC_2015"] = kCyan;
  fillColors["gj"] = kBlue;
  fillColors["jj"] = kSpring;
  fillColors["vg"] = kOrange;
  fillColors["w"] = kBlack;
  fillColors["dy"] = kYellow;
  fillColors["ttg"] = kMagenta;
  fillColors["gg70"] = kCyan;

  prettyName["data"]="Data";
  prettyName["data_2015"]="Data (2015)";
  prettyName["data_2016"]="Data (2016)";
  prettyName["data_2017"]="Data (2017)";
  prettyName["data_2018"]="Data (2018)";
  prettyName["data_2017_2018"]="Data (2017+2018)";
  prettyName["data_2016_2017_2018"]="Data (2016-2018)";
  prettyName["data_2016_unskimmed"]="Data (2016)";
  prettyName["data_2017_unskimmed"]="Data (2017)";
  prettyName["data_2018_unskimmed"]="Data (2018)";
  prettyName["data_2018_newjson"]="Data (2018, new JSON)";
  prettyName["gg"]="#gamma#gamma";
  //  prettyName["gg_2016"]="#gamma#gamma (2016)";
  prettyName["gg_aMC_2015"]="#gamma#gamma (aMC@NLO)";
  prettyName["gj"]="#gamma + jets";
  //  prettyName["gj_2016"]="#gamma + jets (2016)";
  prettyName["jj"]="Multijet";
  prettyName["vg"]="V#gamma";
  prettyName["w"]="W";
  prettyName["dy"]="DY";
  prettyName["ttg"]="t#bar{t}#gamma";
  prettyName["gg70"]="Diphoton, p_{T,#gamma} > 70";

  setTDRStyle();
}

void initADD2016(const TString & baseDirectory)
{
  // ADD samples
  std::vector<std::string> MS = {"3000", "3500", "4000", "4500",
				 "5000", "5500", "6000", "7000",
				 "8000", "9000", "10000", "11000"};
  std::vector<std::string> NED = {"2", "4"};
  std::vector<std::string> KK = {"1", "4"};
  std::map<std::string, std::vector<std::string>> MggBins;
  // the 250To500 mass bin is only present for the NED=4, KK=1 sample
  // but it is skipped manually later
  MggBins["3000"] = {"250To500", "500To1000", "1000To2000", "2000To3000"};
  MggBins["3500"] = {"250To500", "500To1000", "1000To2000", "2000To3500"};
  MggBins["4000"] = {"250To500", "500To1000", "1000To2000", "2000To4000"};
  MggBins["4500"] = {"250To500", "500To1000", "1000To2000", "2000To3000", "3000To4500"};
  MggBins["5000"] = {"250To500", "500To1000", "1000To2000", "2000To3000", "3000To5000"};
  MggBins["5500"] = {"250To500", "500To1000", "1000To2000", "2000To4000", "4000To5500"};
  MggBins["6000"] = {"500To1000", "1000To2000", "2000To4000", "4000To6000"};
  MggBins["7000"] = {"500To1000", "1000To2000", "2000To4000", "4000To7000"};
  MggBins["8000"] = {"500To1000", "1000To2000", "2000To4000", "4000To8000"};
  MggBins["9000"] = {"500To1000", "1000To2000", "2000To4000", "4000To9000"};
  MggBins["10000"] = {"500To1000", "1000To2000", "2000To4000", "4000To10000"};
  MggBins["11000"] = {"500To1000", "1000To2000", "2000To4000", "4000To11000"};

  for(const auto& iMS : MS) {
    for(const auto& iNED : NED) {
      for(const auto& iKK : KK) {
	// no samples were generated with KK convention 4
	// and four extra dimensions
	if(strcmp(iKK.c_str(), "4")==0 && strcmp(iNED.c_str(), "4")==0) continue;
	// no samples were generated with negative interference above MS = 6 TeV
	if(iNED.compare("2")==0 && iKK.compare("4")==0 && std::stoi(iMS)>6000) continue;
	std::string pointName = "ADDGravToGG_MS-";
	pointName += iMS;
	pointName += "_NED-";
	pointName += iNED;
	pointName += "_KK-";
	pointName += iKK;
	chains[pointName] = new TChain("diphoton/fTree");
	for(std::string iMgg : MggBins[iMS] ) {
	  // the 200To500 bins are only present for the NED=4 samples
	  if(iNED.compare("2")==0 && iMgg.compare("250To500")==0) continue;
	  // Hewett- convention samples do not extend past Mgg > 6 TeV
	  std::string sampleName(pointName);
	  sampleName += "_M-";
	  sampleName += iMgg;
	  sampleName += "_13TeV-sherpa";
	  // the following line only works for 80X samples
	  //	  chains[pointName]->Add(filestring(sampleName));
	  lineColors[pointName] = kBlack;
	  fillStyles[pointName] = 1001;
	  lineStyles[pointName] = kSolid;
	}
      }
    }
  }

  chains["ADDGravToGG_MS-10000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191006_233205/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020115/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-2_KK-1_M-4000To10000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-2_KK-1_M-4000To10000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020128/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_020147/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020205/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_020218/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-4_KK-1_M-4000To10000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-4_KK-1_M-4000To10000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020230/0000/*.root");
  chains["ADDGravToGG_MS-10000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-10000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-10000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020243/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191008_123031/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020309/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-2_KK-1_M-4000To11000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-2_KK-1_M-4000To11000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_020322/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020335/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_020350/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020405/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-4_KK-1_M-4000To11000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-4_KK-1_M-4000To11000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020418/0000/*.root");
  chains["ADDGravToGG_MS-11000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-11000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-11000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020431/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020447/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020504/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020518/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020531/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-4_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-4_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020545/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020558/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020610/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020625/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020640/0000/*.root");
  chains["ADDGravToGG_MS-3000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020654/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020706/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-2_KK-1_M-2000To3500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-1_M-2000To3500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020719/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020733/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/ADDGravToGG_MS-3500_NED-2_KK-4_M-2000To3500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-4_M-2000To3500_13TeV-sherpa__80XMiniAODv2__MINIAODSIM/181106_181242/0000/*.root");
  // Use old sample because the 94X sample is broken
  chains["ADDGravToGG_MS-3500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_020746/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020817/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020829/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020845/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020858/0000/*.root");
  chains["ADDGravToGG_MS-3500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020910/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020934/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_020951/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_021004/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021034/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-4_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-4_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021052/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021105/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021117/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021129/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021143/0000/*.root");
  chains["ADDGravToGG_MS-4000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021157/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021210/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021225/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-1_M-3000To4500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-1_M-3000To4500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021242/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021310/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021327/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-4_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-4_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021355/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-4_M-3000To4500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-4_M-3000To4500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021407/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021421/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_021437/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021450/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021503/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021515/0000/*.root");
  chains["ADDGravToGG_MS-4500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021528/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021542/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021554/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-1_M-3000To5000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-1_M-3000To5000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021607/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021620/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021634/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-4_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-4_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021647/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-4_M-3000To5000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-4_M-3000To5000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021700/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021712/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021725/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021738/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021752/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021804/0000/*.root");
  chains["ADDGravToGG_MS-5000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021817/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021829/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021843/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-1_M-4000To5500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-1_M-4000To5500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021857/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021910/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021924/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-4_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-4_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021937/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-4_M-4000To5500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-4_M-4000To5500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_021950/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022004/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022027/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022103/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022117/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa__Summer16MiniAODv3-v1__MINIAODSIM/191007_022130/0000/*.root");
  chains["ADDGravToGG_MS-5500_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022145/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022157/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022210/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-1_M-4000To6000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-1_M-4000To6000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022224/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022237/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-4_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022250/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-4_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-4_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022303/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-4_M-4000To6000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-4_M-4000To6000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022316/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-2_KK-4"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-2_KK-4_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-2_KK-4_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022330/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022342/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022355/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022411/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022424/0000/*.root");
  chains["ADDGravToGG_MS-6000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022439/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022506/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022518/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-2_KK-1_M-4000To7000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-2_KK-1_M-4000To7000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022531/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022545/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022558/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022611/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-4_KK-1_M-4000To7000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-4_KK-1_M-4000To7000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022640/0000/*.root");
  chains["ADDGravToGG_MS-7000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-7000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-7000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022654/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022708/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022722/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-2_KK-1_M-4000To8000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-2_KK-1_M-4000To8000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022740/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022753/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022815/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022834/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-4_KK-1_M-4000To8000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-4_KK-1_M-4000To8000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022846/0000/*.root");
  chains["ADDGravToGG_MS-8000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-8000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-8000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022900/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-2_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022920/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-2_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022932/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-2_KK-1_M-4000To9000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-2_KK-1_M-4000To9000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_022944/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-2_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-2_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-2_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_023009/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-4_KK-1_M-1000To2000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_023024/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-4_KK-1_M-2000To4000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_023036/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-4_KK-1_M-4000To9000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-4_KK-1_M-4000To9000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_023049/0000/*.root");
  chains["ADDGravToGG_MS-9000_NED-4_KK-1"]->Add(baseDirectory + "/store/user/cawest/diphoton/6a01524/ADDGravToGG_MS-9000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-9000_NED-4_KK-1_M-500To1000_13TeV-sherpa__Summer16MiniAODv3-v2__MINIAODSIM/191007_023102/0000/*.root");

}

void initADD(const TString & baseDirectory)
{
  initADD2016(baseDirectory);

  // 2017 and 2018 datasets have a different dataset string
  std::vector<int> years = {2017, 2018};
  std::vector<std::string> negint_values = {"0", "1"};
  std::vector<int> lambdaTs = {4000, 4500, 5000, 5500, 6000,
			       6500, 7000, 7500, 8000, 8500,
			       9000, 10000, 11000, 13000};

  for(const auto& year : years) {
    for(const auto& negint_value : negint_values) {
      for(const auto& lambdaT : lambdaTs) {
	// there is no point with neg_int = "0" and lambdaT == 8500
	if(negint_value.compare("0") == 0 && lambdaT == 8500 ) continue;
	std::string pointName = "ADDGravToGG_NegInt-";
	pointName += negint_value;
	pointName += "_LambdaT-";
	pointName += std::to_string(lambdaT);
	pointName += "_TuneCP2_13TeV-pythia8_";
	pointName += std::to_string(year);
	chains[pointName] = new TChain("diphoton/fTree");
	lineColors[pointName] = kBlack;
	fillStyles[pointName] = 1001;
	lineStyles[pointName] = kSolid;
      }
    }
  }

  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003250/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003306/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003321/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003337/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003353/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003420/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003437/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003454/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003509/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003524/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-4000To13000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-4000To13000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003540/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003559/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003615/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003631/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003646/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003706/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003721/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003737/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003759/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003816/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003832/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003851/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003908/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003924/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_003941/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004001/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004017/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004033/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004101/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004117/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004136/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004151/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004217/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004233/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004258/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004315/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004331/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004347/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004410/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004426/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004442/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004503/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004520/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004538/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004553/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004611/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004628/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004651/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004709/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004724/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004744/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004758/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004815/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004834/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004850/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004905/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004920/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004942/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_004958/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005021/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005039/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005054/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-4000To13000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-4000To13000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005111/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005125/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005141/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005156/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005212/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005230/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005247/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005303/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005319/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005334/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005350/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005405/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005421/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005437/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005452/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005509/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005525/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005541/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005556/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005612/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005632/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005656/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005723/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005742/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005758/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005815/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005831/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005849/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005904/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005920/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005937/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_005955/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010015/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010040/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010059/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010115/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010130/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010146/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010203/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010219/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-4000To8500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-4000To8500_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010234/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010249/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010306/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010322/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010337/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8__Fall17_PU2017-v1__MINIAODSIM/191206_010354/0000/*.root");

  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_184742/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_184815/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_184849/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_184921/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185006/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185037/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185106/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185129/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185200/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185224/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185318/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185415/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185452/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185534/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185605/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185639/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185706/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185748/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185840/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185910/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_185958/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190041/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190118/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190212/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190253/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190344/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190412/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190509/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190546/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190632/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190653/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190759/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190835/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190859/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_190939/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191014/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191046/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191118/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191153/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191243/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191315/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191403/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191435/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191541/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191615/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191716/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191747/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191852/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_191926/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192022/0000/*.root");
  chains["ADDGravToGG_NegInt-0_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-0_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-0_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192101/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192146/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192227/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-4000To10000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192307/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-10000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-10000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192347/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192428/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192458/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-4000To11000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192558/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-11000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-11000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192641/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192719/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192759/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-13000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-13000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192920/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_192944/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193049/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-3000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193145/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193254/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193351/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193446/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-3000To4500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193600/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-4500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-4500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193645/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193745/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-2000To3000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193827/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-3000To5000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_193914/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194020/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194113/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194145/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-4000To5500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194222/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-5500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-5500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194301/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194353/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194431/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-4000To6000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194523/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194605/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194653/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194740/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-4000To6500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194807/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-6500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-6500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_194856/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191218_025216/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195022/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-4000To7000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195107/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195205/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195301/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195348/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-4000To7500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195424/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-7500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-7500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195531/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195607/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195725/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-4000To8000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195829/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_195929/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200038/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200147/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-4000To8500_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-4000To8500_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200253/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-8500_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-8500_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-8500_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200351/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-1000To2000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200519/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-2000To4000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200610/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-4000To9000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200738/0000/*.root");
  chains["ADDGravToGG_NegInt-1_LambdaT-9000_TuneCP2_13TeV-pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/969aff9/ADDGravToGG_NegInt-1_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8/crab_ADDGravToGG_NegInt-1_LambdaT-9000_M-500To1000_TuneCP2_13TeV-pythia8__Autumn18-v1__MINIAODSIM/191203_200837/0000/*.root");


}

void initRSG(const TString & baseDirectory)
{
  std::vector<std::string> years = {"2017", "2018"};
  std::vector<std::string> kMpl_values = {"001", "01", "02"};
  std::map<std::string, std::vector<int> > M_bins;
  M_bins["001"] = {750, 1000, 1250, 1500, 1750,
		   2000, 2250, 2500, 2750, 3000,
		   3250, 3500, 4000, 5000};
  M_bins["01"] = {750, 1000, 1250, 1500, 1750,
		  2000, 2250, 2500, 3000, 3500,
		  4000, 4250, 4500, 4750, 5000,
		  5250, 5500, 5750, 6000, 6500,
		  7000, 8000};
  M_bins["02"] = {750, 1000, 1250, 1500, 1750,
		  2000, 2250, 2500, 3000, 3500,
		  4000, 4500, 4750, 5000, 5250,
		  5500, 5750, 6000, 6500, 7000,
		  8000};

  for(const auto& year : years) {
    for(const auto& kMpl_value : kMpl_values) {
      for(const auto& M_bin : M_bins[kMpl_value]) {
	std::string pointName = "RSGravitonToGammaGamma_kMpl";
	pointName += kMpl_value;
	pointName += "_M_";
	pointName += std::to_string(M_bin);
	pointName += "_TuneCP2_13TeV_pythia8_";
	pointName += year;
	chains[pointName] = new TChain("diphoton/fTree");
	lineColors[pointName] = kBlack;
	fillStyles[pointName] = 1001;
	lineStyles[pointName] = kSolid;
      }
    }
  }

  chains["RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_021941/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031602/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031614/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031626/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031640/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031652/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031707/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031718/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031732/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031744/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031801/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031814/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031827/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031840/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031853/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031910/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031921/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031933/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031945/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031959/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032013/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032026/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032038/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032051/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032104/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032117/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032129/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032143/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032155/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032214/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032227/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032239/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032252/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032307/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032318/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032332/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032344/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032356/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032407/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032426/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032439/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032451/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032503/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032514/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032527/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032540/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032552/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032607/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032623/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032641/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032653/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032712/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032723/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032740/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032752/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032807/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_032819/0000/*.root");

  chains["RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_215942/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220002/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220024/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220046/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220107/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220127/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220148/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_2750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220209/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220230/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220251/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220311/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220330/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220350/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl001_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220411/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_220431/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_231151/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232140/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232219/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232241/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v2__MINIAODSIM/191015_232301/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232322/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232344/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232403/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232425/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232446/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232505/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_4750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232526/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232548/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232610/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232630/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_5750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232652/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_6000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232712/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_6500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232736/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_7000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232802/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232821/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl01_M_8000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232844/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232908/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232927/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_232946/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233010/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233031/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233052/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233111/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233133/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233155/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233214/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233236/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_4750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233259/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233319/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233342/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233406/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_5750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233424/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_6000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233444/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_6500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233507/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_7000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233532/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_213012/0000/*.root");
  chains["RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8/crab_RSGravitonToGammaGamma_kMpl02_M_8000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191015_233553/0000/*.root");

}

void initHeavyHiggs(const TString & baseDirectory)
{
  std::vector<std::string> years = {"2017", "2018"};
  std::vector<std::string> W_values = {"0p014", "1p4", "5p6"};
  std::map<std::string, std::vector<int> > M_bins;
  M_bins["0p014"] = {750, 1000, 1250, 1500, 1750,
		     2000, 2250, 2500, 2750, 3000,
		     3250, 3500, 4000, 4500, 5000};
  M_bins["1p4"] = {750, 1000, 1250, 1500, 1750,
		   2000, 2250, 2500, 3000, 3500,
		   4000, 4250, 4500, 4750, 5000};
  M_bins["5p6"] = {750, 1000, 1250, 1500, 1750,
		   2000, 2250, 2500, 3000, 3500,
		   4000, 4500, 4750, 5000};

  for(const auto& year : years) {
    for(const auto& W_value : W_values) {
      for(const auto& M_bin : M_bins[W_value]) {
	std::string pointName = "GluGluSpin0ToGammaGamma_W_";
	pointName += W_value;
	pointName += "_M_";
	pointName += std::to_string(M_bin);
	pointName += "_TuneCP2_13TeV_pythia8_";
	pointName += year;
	chains[pointName] = new TChain("diphoton/fTree");
	lineColors[pointName] = kBlack;
	fillStyles[pointName] = 1001;
	lineStyles[pointName] = kSolid;
      }
    }
  }

  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030545/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030558/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030612/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030623/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030637/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030651/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030704/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030716/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030737/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030750/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030804/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030815/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030827/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030839/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030851/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030908/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030923/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030937/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_030949/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031006/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031018/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031034/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031046/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031109/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031124/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031141/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031153/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031210/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031227/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031240/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031252/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031308/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031323/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031339/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031350/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031414/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031426/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031438/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031453/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031507/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031518/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031530/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8_2017"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8__Fall17_PU2017-v1__MINIAODSIM/191016_031548/0000/*.root");

  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004343/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004405/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004425/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004448/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004510/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004531/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004553/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_2750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004614/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004641/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004704/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004725/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004744/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_4500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004806/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004827/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_0p014_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004848/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004916/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_004941/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005001/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005032/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005052/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005116/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005143/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005207/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005228/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005255/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005315/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005333/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_4750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005357/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005418/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_1p4_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005440/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005503/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005525/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005545/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_1750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005611/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_2000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005635/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_2500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005720/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_3000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005742/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_3500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005801/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005824/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4500_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005848/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_4750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005908/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_5000_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005933/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/fac6094/GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_750_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_005953/0000/*.root");
  chains["GluGluSpin0ToGammaGamma_W_5p6_M_2250_TuneCP2_13TeV_pythia8_2018"]->Add(baseDirectory + "/store/user/cawest/diphoton/7003ea2/GluGluSpin0ToGammaGamma_W_5p6_M_2250_TuneCP2_13TeV_pythia8/crab_GluGluSpin0ToGammaGamma_W_5p6_M_2250_TuneCP2_13TeV_pythia8__Autumn18-v1__MINIAODSIM/191016_155415/0000/*.root");


}


#endif
