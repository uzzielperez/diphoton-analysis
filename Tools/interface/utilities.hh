#ifndef UTILITIES_HH
#define UTILITIES_HH

#include "TString.h"
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include <string>

std::string kfactorString(const std::string & region, const std::string & scales)
{
  std::map<std::string, std::string> fitFuncs;
  fitFuncs["BB"] = "pol3";
  fitFuncs["BE"] = "pol1";
  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }

  TFile *f = new TFile(Form("%s/src/diphoton-analysis/Tools/data/kfactor_%s_%s.root", cmssw_base, region.c_str(), scales.c_str()));
  TF1 *kfactorFunction;
  f->Print();
  f->GetObject(fitFuncs[region].c_str(), kfactorFunction);
  kfactorFunction->Print("v");
  TString kfactorWeight;
  if(region == "BB") kfactorWeight = Form("(%6.6e + %6.6e*Diphoton.Minv + %6.6e*Diphoton.Minv*Diphoton.Minv + %6.6e*Diphoton.Minv*Diphoton.Minv*Diphoton.Minv)",
					  kfactorFunction->GetParameter(0), kfactorFunction->GetParameter(1),
					  kfactorFunction->GetParameter(2),  kfactorFunction->GetParameter(3));
  else kfactorWeight = Form("(%6.6e + %6.6e*Diphoton.Minv)", kfactorFunction->GetParameter(0), kfactorFunction->GetParameter(1));
  
  return kfactorWeight.Data();
}

TH1D* getHists(const std::string & base, const std::string & region, const std::string & type)
{
  unsigned int nfiles=10;
  if(type.find("NNLO") != std::string::npos) nfiles = 50;
  TH1D *sum = 0;
  for(unsigned int i=1; i<=nfiles; i++) {
    TString filename(Form("%s/%s_%s_R1F1_Mass0p23To2TeV_13TeV/Job%d/bin/ReRoot.root", base.c_str(), region.c_str(), type.c_str(), i));
    TFile *f = TFile::Open(filename);
    TH1D *tempHist = static_cast<TH1D*>(f->Get("hist1"));
    if(tempHist==nullptr) continue;
    if(sum == 0) {
      sum = static_cast<TH1D*>(tempHist->Clone());
      sum->SetDirectory(0);
      sum->SetBit(TH1::kIsAverage);
    }
    else {
      tempHist->SetBit(TH1::kIsAverage);
      sum->Add(tempHist);
    }

    f->Close();
  }

  return sum;
}

TH1D* getHistsMCFM(const std::string & base, const std::string & type)
{
  unsigned int seedBase = 1189;
  unsigned int nfiles=10;
  if(type.find("nnlo") != std::string::npos) nfiles = 100;
  TH1D *sum = 0;
  for(unsigned int i=1; i<=nfiles; i++) {
    unsigned int seed = seedBase + i;
    TString filename(Form("%s/%s_seed%d.root", base.c_str(), type.c_str(), seed));
    TFile *f = TFile::Open(filename);
    if(!f) continue;
    if(!f->IsOpen()) continue;
    TH1D *tempHist = static_cast<TH1D*>(f->Get("id1"));
    if(tempHist==nullptr) continue;
    if(sum == 0) {
      sum = static_cast<TH1D*>(f->Get("id1"));
      sum->SetBit(TH1::kIsAverage);
    }
    else {
      tempHist->SetBit(TH1::kIsAverage);
      sum->Add(tempHist);
    }
  }
  // scale to pb
  double fbtopb = 0.001;
  // scale by bin width
  double binWidth = (sum->GetXaxis()->GetXmax()-sum->GetXaxis()->GetXmin())/sum->GetNbinsX();
  std::cout << "binWidth: " << binWidth << std::endl;
  std::cout << "integral*binWidth: " << sum->Integral()*binWidth*fbtopb << std::endl;
  sum->Scale(binWidth*fbtopb);

  return sum;
}

#endif
