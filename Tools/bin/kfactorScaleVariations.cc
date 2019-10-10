#ifdef __CINT__
#include "interface/tdrstyle.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#endif
#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TROOT.h"

#include <map>
#include <vector>

void kfactorScaleVariations(const std::string & kfactorType);

int main(int argc, char *argv[])
{
  std::string kfactorType;

  if(argc > 2) {
    std::cout << "Syntax: kfactorScaleVariations.exe [k-factor type]" << std::endl;
    return -1;
  }
  else if(argc == 2) {
    kfactorType = argv[1];
  }

  kfactorScaleVariations(kfactorType);

  return 0;
}

void kfactorScaleVariations(const std::string & kfactorType)
{
  bool preliminary = true;

  setTDRStyle();
  gROOT->ForceStyle();

  std::vector<std::string> scales = {"R0p5F0p5", "R1F1", "R2F2"};
  std::vector<std::string> regions = {"BB", "BE"};
  std::map<std::string, std::string> regiontext;
  regiontext["BB"] = "Barrel-barrel";
  regiontext["BE"] = "Barrel-endcap";
  if(!preliminary) {
    regiontext["BB"] = "EBEB";
    regiontext["BE"] = "EBEE";
  }
  std::map<std::string, Color_t> scaleColor;
  std::map<std::string, TF1*> fits;
  std::map<std::string, TCanvas*> canvases;
  scaleColor["R0p5F0p5"] = kRed;
  scaleColor["R1F1"] = kBlack;
  scaleColor["R2F2"] = kBlue;

  for(auto iregion : regions) {
    canvases[iregion] =  new TCanvas;
    for(auto iscale : scales) {
      TFile *f = TFile::Open(Form("data/kfactor_%s_%s_125GeV_%s.root", iregion.c_str(), iscale.c_str(), kfactorType.c_str()));
      fits[iscale] = static_cast<TF1*>(f->Get("pol3"));
      if(iscale == "R0p5F0p5") {
	fits[iscale]->GetXaxis()->SetNdivisions(505);
	fits[iscale]->SetTitle(";m_{#gamma#gamma} (GeV);K factor");
	fits[iscale]->SetMinimum(1.0);
	fits[iscale]->SetMaximum(4.0);
	fits[iscale]->Draw();
	fits[iscale]->SetLineColor(kBlue);
      }
      else if(iscale == "R1F1") {
	fits[iscale]->Draw("same");
	fits[iscale]->SetLineColor(kBlack);
	fits[iscale]->SetLineWidth(2);
      }
      else {
	fits[iscale]->Draw("same");
	fits[iscale]->SetLineColor(kRed);
      }
    }
    TLegend *leg = new TLegend(0.3, 0.55, 0.6, 0.75);
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->AddEntry(fits["R0p5F0p5"], "Scales down", "L");
    leg->AddEntry(fits["R1F1"], "Nominal", "L");
    leg->AddEntry(fits["R2F2"], "Scales up", "L");
    leg->Draw();

    TString label("#font[42]{#it{Simulation Preliminary}}");
    if(!preliminary) label = "#font[42]{#it{Simulation Supplementary}}";
    TLatex *TitleC2 = new TLatex(0.32,0.88,label);
    TitleC2->SetTextSize(0.04);
    TitleC2->SetNDC();
    TitleC2->Draw();
    TLatex *TitleB1 = new TLatex(0.22,0.88,"#font[61]{CMS}");
    TitleB1->SetTextSize(0.04);
    TitleB1->SetNDC();
    TitleB1->Draw();

    TLatex *region = new TLatex(0.3, 0.78, regiontext[iregion].c_str());
    region->SetNDC();
    region->Draw();

    std::string filestring("");
    if(preliminary) filestring = "_preliminary";
    canvases[iregion]->Print(Form("plots/kfactorScaleVariations_%s%s_%s.pdf", iregion.c_str(), filestring.c_str(), kfactorType.c_str()));
  }


}
