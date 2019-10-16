#ifdef __CINT__
#include "interface/tdrstyle.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#endif

#include "TCanvas.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TROOT.h"

#include <iostream>

TH1F* getHist(TFile *file, const int year, const std::string& type, const std::string& region, const std::string& histName);
TH1F* getTH1F(TGraphAsymmErrors *gr);
TH1F* getTH1F(TH1F *h);

const float binWidth = 50; // GeV

void plot_blinded();

int main(void)
{
  plot_blinded();

  return 0;
}


void plot_blinded()
{
  const double xmin = 500.;
  setTDRStyle();
  gROOT->ForceStyle();
  gStyle->SetOptStat(0);

  std::string type("shapes_fit_b");

  TFile *f = TFile::Open("../../HiggsAnalysis/CombinedLimit/fitDiagnosticsADDGravToGG_MS-5000_NED-4_KK-1_lowmass.root");

  std::vector<int> years = {2016, 2017, 2018};
  std::vector<std::string> regions = {"BB", "BE"};
  std::vector<TH1F*> histsBackground, histsData;

  std::map<std::string, TH1F*> sumBackground, sumData;
  for(const auto& region : regions) {
    sumBackground[region] = sumData[region] = nullptr;
    for(const auto& year : years) {
      histsBackground.push_back(getHist(f, year, type, region, "total_background"));
      histsData.push_back(getHist(f, year, type, region, "data"));
      if(sumBackground[region] == nullptr) sumBackground[region] = histsBackground.back();
      else sumBackground[region]->Add(histsBackground.back());
      if(sumData[region] == nullptr) sumData[region] = histsData.back();
      else sumData[region]->Add(histsData.back());
    }
  }

  std::map<std::string, TCanvas*> canvases;
  std::map<std::string, std::string> prettyName;
  prettyName["BB"] = "EB-EB";
  prettyName["BE"] = "EB-EE";
  for(const auto& region : regions) {
    canvases[region] = new TCanvas;
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1,1);
    pad1->SetBottomMargin(0);
    pad1->Draw();

    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1,0.3);
    pad2->SetBottomMargin(0.25);
    pad2->SetTopMargin(0);
    pad2->Draw();

    pad1->cd();
    sumBackground[region]->SetTitle(Form(";m_{#gamma#gamma} (GeV); Events / %d GeV", static_cast<int>(binWidth)));
    sumBackground[region]->GetXaxis()->SetRangeUser(xmin, 1000);    
    sumBackground[region]->Draw("hist");
    sumData[region]->SetLineColor(kBlack);
    sumData[region]->SetMarkerStyle(kFullCircle);
    sumData[region]->GetXaxis()->SetRangeUser(xmin, 1000);    
    sumData[region]->Draw("same");
    TLegend *leg = new TLegend(0.7, 0.6, 0.9, 0.9);
    leg->AddEntry(sumBackground[region], "Total background", "L");
    leg->AddEntry(sumData[region], "Data", "ELP");
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->Draw();
    TLatex *lat = new TLatex();
    lat->DrawLatexNDC(0.4, 0.8, prettyName[region].c_str());

    pad2->cd();

    TH1F* ratio = dynamic_cast<TH1F*>(sumData[region]->Clone("ratio"));
    float chi2 = 0.0;
    for(int i = 1; i <= ratio->GetNbinsX(); i++ ) {
      float data = sumData[region]->GetBinContent(i);
      float dataError = sumData[region]->GetBinError(i);
      float background = sumBackground[region]->GetBinContent(i);
      ratio->SetBinContent(i, data/background);
      ratio->SetBinError(i, dataError/background);
      float pull = 0.0;
      if(data > 0.0) pull = (data - background) / sqrt(data);
      chi2 += pull*pull;
    }
    std::cout << "chi^2/ndof (" << region << "): " 
	      << chi2 << "/" << ratio->GetNbinsX() << std::endl;
    ratio->SetTitle(";m_{#gamma#gamma} (GeV); Ratio");
    ratio->GetXaxis()->SetRangeUser(xmin, 1000);    
    ratio->GetYaxis()->SetRangeUser(0.5, 1.5);
    ratio->Draw();

    TLine *line = new TLine(xmin, 1.0, ratio->GetXaxis()->GetXmax(), 1.0);
    line->SetLineColor(kRed);
    line->SetLineStyle(kDashed);
    line->SetLineWidth(2);
    line->Draw();
    ratio->Draw("same");

    std::string histName("mgg_");
    histName += region;
    for(auto year : years) {
      histName += "_";
      histName += std::to_string(year);
    }
    histName += ".pdf";
    canvases[region]->Print(histName.c_str());
  }
}

TH1F* getHist(TFile *file, const int year, const std::string& type, const std::string& region, const std::string& histName)
{
  std::string channel = type + "/" + region + "_" + std::to_string(year);
  std::string fullHistName = channel + "/" + histName;
  TH1F *hist;
  if(histName.compare("data") == 0) {
    hist = getTH1F(dynamic_cast<TGraphAsymmErrors*>(file->Get(fullHistName.c_str())));
  }
  else {
    hist = getTH1F(dynamic_cast<TH1F*>(file->Get(fullHistName.c_str())));
  }

  return hist;
}

TH1F* getTH1F(TGraphAsymmErrors *gr)
{
  unsigned int npoints = gr->GetN();
  TH1F *hist = new TH1F(gr->GetName(), gr->GetName(), npoints, 0, npoints*binWidth);
  for (unsigned int i = 1; i <= npoints; i++) {
    hist->SetBinContent(i, gr->GetY()[i-1]);
    hist->SetBinError(i, sqrt(gr->GetY()[i-1]));
  }

  return hist;
}

TH1F* getTH1F(TH1F *h)
{
  unsigned int npoints = h->GetNbinsX();
  TH1F *hist = new TH1F(h->GetName(), h->GetName(), npoints, 0, npoints*binWidth);
  for (unsigned int i = 1; i <= npoints; i++) {
    float binContent = h->GetBinContent(i);
    hist->SetBinContent(i, binContent);
    hist->SetBinError(i, sqrt(binContent));
  }

  return hist;
}