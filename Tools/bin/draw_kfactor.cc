#ifdef __CINT__
#include "interface/tdrstyle.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#endif

#include <string>
#include <map>
#include <vector>

#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TString.h"
#include "TLegend.h"

void draw_kfactor(const std::string& region);

int main()
{
  draw_kfactor("BB");
  draw_kfactor("BE");

  return 0;
}

void draw_kfactor(const std::string& region)
{
  const std::string kfactorType("125GeV_NNPDF");
  setTDRStyle();

  std::string histName("pol3");
  std::string histName_NLO(histName);
  histName_NLO+="_NLO";
  std::string histName_LO(histName);
  histName_LO+="_LO";

  std::vector<std::string> orders = {"R0p5F0p5", "R1F1", "R2F2"};
  std::map<std::string, int> colors;
  colors["R0p5F0p5"] = kRed;
  colors["R1F1"] = kBlue;
  colors["R2F2"] = kBlack;
  std::vector<TFile*> files;
  std::vector<TF1*> kfactors;
  std::vector<TF1*> kfactors_NLO;
  std::vector<TF1*> kfactors_LO;

  TCanvas *c = new TCanvas;

  for(auto iorder : orders) {
    TString filename(Form("data/kfactor_%s_%s_%s.root", region.c_str(), iorder.c_str(), kfactorType.c_str()));
    files.push_back(TFile::Open(filename));
    kfactors.push_back(static_cast<TF1*>(files.back()->Get(histName.c_str())));
    kfactors_NLO.push_back(static_cast<TF1*>(files.back()->Get(histName_NLO.c_str())));
    kfactors_LO.push_back(static_cast<TF1*>(files.back()->Get(histName_LO.c_str())));
    kfactors.back()->SetLineColor(kRed);
    kfactors_NLO.back()->SetLineColor(kBlue);
    kfactors_LO.back()->SetLineColor(kBlack);
    if(kfactors.size()==1) {
      kfactors.back()->Draw();
      kfactors.back()->GetXaxis()->SetNdivisions(505);
    }
    else  kfactors.back()->Draw("same");
    if(iorder != "R1F1" ) {
      kfactors.back()->SetLineStyle(kDashed);
      kfactors.back()->SetTitle(";m_{#gamma#gamma} (GeV);MCFM/Sherpa");
      kfactors_NLO.back()->SetLineStyle(kDashed);
      kfactors_LO.back()->SetLineStyle(kDashed);
    }
    kfactors.back()->GetXaxis()->SetRangeUser(500, 4000);
    kfactors.back()->GetYaxis()->SetRangeUser(0, 3);
    kfactors_NLO.back()->Draw("same");
    kfactors_LO.back()->Draw("same");
  }

  TLegend *leg = new TLegend(0.2, 0.7, 0.4, 0.9);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(kfactors.at(1), "NNLO", "L");
  leg->AddEntry(kfactors_NLO.at(1), "NLO", "L");
  leg->AddEntry(kfactors_LO.at(1), "LO", "L");
  leg->Draw();

  c->Print(Form("plots/kfactor_comparison_%s_%s.pdf", region.c_str(), kfactorType.c_str()));
}
