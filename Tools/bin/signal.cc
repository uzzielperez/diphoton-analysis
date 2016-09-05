#include "diphoton-analysis/Tools/interface/sampleList.hh"

#include "TCanvas.h"
#include "TString.h"
#include "TH1.h"
#include "TFile.h"
#include "TLegend.h"

void allSamples(const std::string &region);
void oneSignal(int ned, int kk, bool bkgSub);

int main()
{
  init();

  oneSignal(2, 1, false);
  oneSignal(2, 4, false);
  oneSignal(4, 1, false);

  oneSignal(2, 1, true);
  oneSignal(2, 4, true);
  oneSignal(4, 1, true);
}


void oneSignal(int ned, int kk, bool bkgSub)
{

  int nBins = 120;
  double xMin = 0.0;
  double xMax = 6000.;

  TString barrelCut("weightAll*isGood*(Diphoton.Minv>230 && Photon1.pt>75 && Photon2.pt>75 && abs(Photon1.eta)<1.4442 && abs(Photon2.eta)<1.4442)");
  if(bkgSub) barrelCut = "weightAll*isGood*(Diphoton.Minv>500 && Photon1.pt>75 && Photon2.pt>75 && abs(Photon1.eta)<1.4442 && abs(Photon2.eta)<1.4442)";
  std::vector<int> stringScales = {3000, 3500, 4000, 4500, 5000, 5500, 6000};

  TCanvas *c = new TCanvas;
  c->SetLogy();
  TLegend *l = new TLegend(0.6, 0.6, 0.9, 0.9);
  l->SetBorderSize(0);
  l->SetFillStyle(0);
  // draw SM background first
  TH1F *histSM = new TH1F("gg70", "gg70", nBins, xMin, xMax);
  chains["gg70"]->Project("gg70", "Minv", barrelCut);
  for(size_t i=0; i<stringScales.size(); i++) {
    TString sample(Form("ADDGravToGG_MS-%d_NED-%d_KK-%d", stringScales.at(i), ned, kk));
    TH1F *hist = new TH1F(sample, sample, nBins, xMin, xMax);
    chains[sample.Data()]->Project(sample, "Minv",  barrelCut);
    hist->SetTitle(";M_{#gamma#gamma} (GeV);Events / 50 GeV");
    hist->SetLineColor(kBlue-4+i%4);
    hist->SetMarkerColor(kBlue-4+i%4);
    if(bkgSub) hist->Add(histSM, -1.0);
    if(i==0) hist->Draw();
    else hist->Draw("same");  
    l->AddEntry(sample, sample, "L");
  }
  l->Draw();
  
  TString outputFilename(Form("ADDGravToGG_NED-%d_KK-%d.pdf", ned, kk));
  if(bkgSub) {
    outputFilename = Form("ADDGravToGG_NED-%d_KK-%d_bkg_sub.pdf", ned, kk);
  }
  c->Print(outputFilename);
}

