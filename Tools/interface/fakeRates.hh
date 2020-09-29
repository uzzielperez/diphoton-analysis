#ifndef fakeRates_hh
#define fakeRates_hh

#include <iostream>
#include <map>
#include <string>
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TString.h"

class fakeRates {
  int m_year;
  std::map<std::string, TGraphAsymmErrors*> m_fakeRates;
  std::string m_fakeRateType;

 public:
  fakeRates(std::string fakeRateType, int year);
  double getFakeRate(double pt, int region, int nPV);

};

fakeRates::fakeRates(std::string fakeRateType, int year) : m_year(year)
{
  const std::string iso("chIso5To10");

  m_fakeRateType = fakeRateType;

  std::vector<std::string> datasets = {"jetht", "doublemuon"};
  std::vector<std::string> regions = {"EB", "EE"};
  std::vector<std::string> pvCuts = {"0-22", "23-27"};
  if(m_year==2016) pvCuts.push_back("28-200");
  else {
    pvCuts.push_back("28-32");
    pvCuts.push_back("33-37");
    pvCuts.push_back("38-200");
  }

  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }

  for(auto region : regions) {
    for(auto dataset : datasets) {
      for(auto pvCut : pvCuts) {
        TFile *f = TFile::Open(Form("%s/diphoton-analysis/FakeRateAnalysis/fakeRatePlots_%s_%d_nPV%s.root", cmssw_base, dataset.c_str(), m_year, pvCut.c_str()));
        const TString graphName(Form("fakeRate%s_%s", region.c_str(), iso.c_str()));
        TGraphAsymmErrors *gr = dynamic_cast<TGraphAsymmErrors*>(f->Get(graphName));
        gr->Eval(1000.0);
	std::string keyname(region + "_" + dataset + "_" + pvCut);
        m_fakeRates[keyname] = gr;
      }
    }
  }
}

// type:
// 0 = average of doublemuon and jetht
// 1 = doublemuon
// 2 = jetht
double fakeRates::getFakeRate(double pt, int region, int nPV)
{
  std::vector<std::string> regions = {"EB", "EE"};
  std::string pvCut = "";
  if(nPV >= 0 && nPV <= 22) pvCut = "0-22";
  else if(nPV >= 23 && nPV <= 27) pvCut = "23-27";
  else if(nPV >= 28 && nPV <=200) {
    if(m_year == 2016) {
      pvCut = "28-200";
    }
    else {
      if(nPV >= 28 && nPV <= 32) pvCut = "28-32";
      else if(nPV >= 33 && nPV <= 37) pvCut = "33-37";
      else if(nPV >= 38 && nPV <= 200) pvCut = "38-200";
    }
  }
  else std::cout << "Anomalous nPV: " << nPV << std::endl;

  std::string keyname_doublemuon(regions[region] + "_doublemuon_" + pvCut);
  std::string keyname_jetht(regions[region] + "_jetht_" + pvCut);

  if(m_fakeRateType == "average") return 0.5*(m_fakeRates[keyname_doublemuon]->Eval(pt)+m_fakeRates[keyname_jetht]->Eval(pt));
  else if(m_fakeRateType == "doublemuon") return m_fakeRates[keyname_doublemuon]->Eval(pt);
  else if(m_fakeRateType == "jetht") return m_fakeRates[keyname_jetht]->Eval(pt);
  else std::cout << "Fake rate type " << m_fakeRateType << "not supported." << std::endl;

  return 0;
}
#endif // fakeRates_hh
