#ifdef __CINT__
#include "interface/tdrstyle.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#endif

#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TLegend.h"
#include "TROOT.h"

#include <map>
#include <vector>

void kfactorScaleVariations();

int main()
{
  kfactorScaleVariations();

  return 0;
}

void kfactorScaleVariations()
{
  setTDRStyle();
  gROOT->ForceStyle();

  std::vector<std::string> scales = {"R0p5F0p5", "R1F1", "R2F2"};
  std::vector<std::string> regions = {"BB", "BE"};
  std::map<std::string, Color_t> scaleColor;
  std::map<std::string, TF1*> fits;
  std::map<std::string, TCanvas*> canvases;
  scaleColor["R0p5F0p5"] = kRed;
  scaleColor["R1F1"] = kBlack;
  scaleColor["R2F2"] = kBlue;

  for(auto iregion : regions) {
    canvases[iregion] =  new TCanvas;
    for(auto iscale : scales) {
      TFile *f = TFile::Open(Form("data/kfactor_%s_%s.root", iregion.c_str(), iscale.c_str()));
      fits[iscale] = static_cast<TF1*>(f->Get("pol3"));
      std::cout << "Value at 2 TeV for scale " << iscale 
		<< " and region " << iregion
		<< " : " << fits[iscale]->Eval(2000.) << std::endl;
      if(iscale == "R0p5F0p5") {
	fits[iscale]->GetXaxis()->SetNdivisions(505);
	fits[iscale]->SetTitle(";m_{#gamma#gamma} (GeV);k-factor");
	fits[iscale]->SetMinimum(1.0);
	fits[iscale]->SetMaximum(3.75);
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
    TLegend *leg = new TLegend(0.2, 0.7, 0.5, 0.9);
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->AddEntry(fits["R0p5F0p5"], "Scales down", "L");
    leg->AddEntry(fits["R1F1"], "Nominal", "L");
    leg->AddEntry(fits["R2F2"], "Scales up", "L");
    leg->Draw();

    canvases[iregion]->Print(Form("plots/kfactorScaleVariations_%s.pdf", iregion.c_str()));
  }


}
