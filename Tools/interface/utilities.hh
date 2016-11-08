#ifndef UTILITIES_HH
#define UTILITIES_HH

#include "TString.h"
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include <string>

std::string kfactorString(const std::string & region, const std::string & scales)
{
  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }

  TFile *f = new TFile(Form("%s/src/diphoton-analysis/Tools/data/kfactor_%s_%s.root", cmssw_base, region.c_str(), scales.c_str()));
  TF1 *kfactorFunction;
  f->GetObject("pol1", kfactorFunction);  
  TString kfactorWeight(Form("(%6.6e+%6.6e*Diphoton.Minv)", kfactorFunction->GetParameter(0), kfactorFunction->GetParameter(1)));
  //  f->Close();
  
  return kfactorWeight.Data();
}

TH1D* getHists(const std::string & base, const std::string & region, const std::string & type)
{
  unsigned int nfiles=50;
  TH1D *sum;
  for(unsigned int i=1; i<=nfiles; i++) {
    TString filename(Form("%s/%s_%s_R1F1_Mass0p23To2TeV_13TeV/Job%d/bin/ReRoot.root", base.c_str(), region.c_str(), type.c_str(), i));
    TFile *f = TFile::Open(filename);
    TH1D *tempHist;
    if(i==1) {
      sum = static_cast<TH1D*>(f->Get("hist1"));
      sum->SetBit(TH1::kIsAverage);
      std::cout << "Setting TH1::kIsAverage" << std::endl;
    }
    else {
      tempHist = static_cast<TH1D*>(f->Get("hist1"));
      if(tempHist==nullptr) continue;
      tempHist->SetBit(TH1::kIsAverage);
      sum->Add(tempHist);
    }
  }

  return sum;
}

#endif
