#ifndef UTILITIES_HH
#define UTILITIES_HH

#include "TString.h"
#include "TFile.h"
#include "TF1.h"
#include <string>

std::string kfactorString(const std::string & region)
{
  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }

  TFile *f = new TFile(Form("%s/src/diphoton-analysis/Tools/data/kfactor_%s.root", cmssw_base, region.c_str()));
  TF1 *kfactorFunction;
  f->GetObject("pol1", kfactorFunction);  
  TString kfactorWeight(Form("(%6.6e+%6.6e*Diphoton.Minv)", kfactorFunction->GetParameter(0), kfactorFunction->GetParameter(1)));
  f->Close();
  
  return kfactorWeight.Data();
}

#endif
