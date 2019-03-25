#ifdef __CINT__
#include "interface/tdrstyle.hh"
#include "interface/sampleList.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#include "diphoton-analysis/Tools/interface/sampleList.hh"
#endif

#include "TCanvas.h"
#include "TF1.h"
#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TLatex.h"
#include "TMath.h"

#include <iostream>
#include <algorithm>

void oneHist(const std::string& varname, TChain *ch, const std::string& year, const bool isTF);
int efficiency(const std::string& year, const std::string& variable);

Double_t errorFun(Double_t *x, Double_t *par) {
  double value(0.5*par[0]*(1. + TMath::Erf( (x[0] - par[1]) / (sqrt(2.)*par[2]) )));
  return value;
}


int main()
{
  setTDRStyle();
  // initialize chains
  init(true);

  std::vector<std::string> years = {"2017", "2018"};
  std::vector<std::string> variables = {"Photon2.pt", "Photon2.eta", "TFPhoton2.pt", "TFPhoton2.eta"};

  for(auto iyear : years) {
    for(auto ivar : variables) {
      efficiency(iyear, ivar);
    }
  }

  return 0;
}

int efficiency(const std::string& year, const std::string& variable)
{
  std::cout << "Calculating trigger turn-on for " << variable
	    << " in " << year << " data." << std::endl;

  bool isTF = false;
  if(variable.find("TF") != std::string::npos) isTF = true;
  std::string chainName("data_");
  // trigger efficiency for fakes needs to be evaluated using the JetHT dataset
  if(isTF) chainName += "jetht_";
  chainName += year + "_unskimmed";
  std::cout << "Processing " << chains[chainName]->GetEntries() << " entries." << std::endl;

  oneHist(variable, chains[chainName], year, isTF);

  return 0;
}


void oneHist(const std::string& varname, TChain *ch, const std::string& year, bool isTF)
{
  std::map<std::string, int> nbins;
  nbins["Photon2.pt"] = 40;
  nbins["Photon2.eta"] = 200;
  nbins["TFPhoton2.pt"] = 40;
  nbins["TFPhoton2.eta"] = 200;
  std::map<std::string, double> min;
  min["Photon2.pt"] = 0.0;
  min["Photon2.eta"] = -2.5;
  min["TFPhoton2.pt"] = 0.0;
  min["TFPhoton2.eta"] = -2.5;
  std::map<std::string, double> max;
  max["Photon2.pt"] = 1000.0;
  max["Photon2.eta"] = 2.5;
  max["TFPhoton2.pt"] = 1000.0;
  max["TFPhoton2.eta"] = 2.5;

  std::string histnames[2] = {"numerator", "denominator"};
  std::vector<TH1F*> hists;

  for(int i = 0; i < 2; i++) {
    hists.push_back(new TH1F(histnames[i].c_str(), histnames[i].c_str(), nbins[varname], min[varname], max[varname]));
  }

  std::string numerator(varname);
  numerator += ">>numerator";
  std::string denominator(varname);
  denominator += ">>denominator";

  TString numeratorCut("isGood && (HLT_DoublePhoton60 || HLT_ECALHT800)");
  TString jetCut("(HLT_PFJet40 || HLT_PFJet60  || HLT_PFJet80 || HLT_PFJet140 || HLT_PFJet200 || HLT_PFJet260 || HLT_PFJet320 || HLT_PFJet400 || HLT_PFJet450 || HLT_PFJet500)");

  if(year.find("2017") != std::string::npos || year.find("2018") != std::string::npos) {
    if(isTF) {
      numeratorCut = "isTF && (HLT_DoublePhoton70 || HLT_ECALHT800) &&" + jetCut + "&& abs(TFPhoton1.eta)<2.5 && abs(TFPhoton2.eta)<2.5 && TFPhoton1.r9_5x5 > 0.8 && TFPhoton2.r9_5x5 > 0.8 && TFPhoton1.hadronicOverEm < 0.1 && TFPhoton2.hadronicOverEm < 0.1";
    }
    else {
      numeratorCut = "isGood && (HLT_DoublePhoton70 || HLT_ECALHT800) && HLT_DoublePhoton33_CaloIdL && abs(Photon1.eta)<2.5 && abs(Photon2.eta)<2.5 && Photon1.r9_5x5 > 0.8 && Photon2.r9_5x5 > 0.8";
    }
    if(varname.find("eta") != std::string::npos) numeratorCut += isTF ? "&& TFPhoton2.pt>125" : "&& Photon2.pt>125";
  }
  ch->Draw(numerator.c_str() , numeratorCut);
  if(year.find("2017") != std::string::npos || year.find("2018") != std::string::npos) {
    TString denominatorCut;
    if(isTF) {
      denominatorCut = "isTF &&" + jetCut + "&& abs(TFPhoton1.eta)<2.5 && abs(TFPhoton2.eta)<2.5 && TFPhoton1.r9_5x5 > 0.8 && TFPhoton2.r9_5x5 > 0.8 && TFPhoton1.hadronicOverEm < 0.1";
    }
    else {
      denominatorCut = "isGood && HLT_DoublePhoton33_CaloIdL && abs(Photon1.eta)<2.5 && abs(Photon2.eta)<2.5 && Photon1.r9_5x5 > 0.8 && Photon2.r9_5x5 > 0.8";
    }
    if(varname.find("eta") != std::string::npos) denominatorCut += isTF ? "&& TFPhoton2.pt>125" : "&& Photon2.pt>125";
    ch->Draw(denominator.c_str(), denominatorCut);
  }
  else {
    ch->Draw(denominator.c_str(), "isGood && HLT_DoublePhoton40");
  }
  // add overflow
  for(int i = 0; i < 2; i++) {
    int maxBin = hists[i]->GetNbinsX();
    hists[i]->SetBinContent(maxBin, hists[i]->GetBinContent(maxBin) + hists[i]->GetBinContent(maxBin+1));
  }

  TCanvas *c0 = new TCanvas;
  c0->SetLogy();
  hists[0]->SetLineColor(kRed);
  hists[1]->SetLineColor(kBlue);
  hists[0]->Draw();
  hists[1]->Draw("same");
  // latex can't figure out what to do with files
  // with more than one period in them
  std::string varForFilename(varname);
  std::replace(varForFilename.begin(), varForFilename.end(), '.', '_');
  if(isTF)  c0->Print(Form("plots/eff_input_%s_%s_fake.pdf", year.c_str(), varForFilename.c_str()));
  else c0->Print(Form("plots/eff_input_%s_%s.pdf", year.c_str(), varForFilename.c_str()));

  TCanvas *c1 = new TCanvas;
  TGraphAsymmErrors *eff = new TGraphAsymmErrors(hists[0], hists[1], "cp");
  //  TEfficiency *eff = new TEfficiency(*hists[0], *hists[1]);
  eff->Draw("AP");
  eff->SetTitle(";p_{T}(#gamma_{2}) (GeV);Efficiency");

  // Fitting turn on curve
  if(varname.find("pt") != std::string::npos) {
    double minx = hists[0]->GetXaxis()->GetXmin();
    double maxx = hists[0]->GetXaxis()->GetXmax();
    TF1 *fitCurve = new TF1("fitCurve",errorFun,40.,maxx,3);
    Double_t params[] = {0.99,minx+(maxx-minx)/4.,50., 50.};
    fitCurve->SetParameters(params);
    fitCurve->SetParNames("#epsilon","#mu","#sigma");
    fitCurve->SetLineColor(2);
    fitCurve->SetLineWidth(2);
    eff->Fit("fitCurve","QEM+","",minx, maxx);
  }

  TLatex *lat = new TLatex;
  lat->SetTextSize(0.038);
  lat->DrawLatexNDC(0.17, 0.96, "#font[62]{CMS} #scale[0.8]{#font[52]{Preliminary}}");
  lat->SetTextFont(42);
  lat->DrawLatexNDC(0.70, 0.96, Form("%1.1f fb^{-1} (13 TeV)", luminosity[year]));

  if(isTF) c1->Print(Form("plots/eff_%s_%s_fake.pdf", year.c_str(), varForFilename.c_str()));
  else c1->Print(Form("plots/eff_%s_%s.pdf", year.c_str(), varForFilename.c_str()));
}
