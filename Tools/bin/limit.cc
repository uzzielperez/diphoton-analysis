#ifdef __CINT__
#include "interface/sampleList.hh"
#else
#include "diphoton-analysis/Tools/interface/sampleList.hh"
#endif

#include "TAxis.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"

bool useLogy = false;
bool drawObservedLimit = false;

void limit(const std::string &directory);
void oneLimit(int ned, int kk, const std::string& directory);
void setStyle()
{
  gStyle->SetCanvasDefW(600);
  gStyle->SetCanvasDefH(600);
  gStyle->SetTitleOffset(1.2,"x"); 
  gStyle->SetTitleOffset(1.7,"z"); 
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadTopMargin(0.08);
  
  gStyle->SetLabelFont(42);
  gStyle->SetLabelSize(0.05);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleSize(0.07);
}

void drawHeader(bool isPreliminary = false)
{
  std::string cms("#font[62]{CMS}");
  if(isPreliminary) cms += " #scale[0.8]{#font[52]{Preliminary}}";
  TLatex *lat = new TLatex;
  lat->SetTextSize(0.038);
  lat->DrawLatexNDC(0.12, 0.93, cms.c_str());
  lat->SetTextFont(42);
  lat->DrawLatexNDC(0.66, 0.93, Form("%2.1f fb^{-1} (13 TeV)", luminosity["2017"]+luminosity["2018"]));
}

double intersection(TGraph *gr, double value)
{
  for(int i=0; i<gr->GetN()-1; i++) {
    double x1, y1, x2, y2;
    gr->GetPoint(i, x1, y1);
    gr->GetPoint(i+1, x2, y2);
    if( (y1 < value && y2 >= value) ||
	(y1 > value && y2 <= value) ) {
      double m = (y2-y1)/(x2-x1);
      double x = x1 + (value - y1)/m;
      return x;
    }
  }
  // did not find an intersection
  return -1;
}

int main(int argc, char *argv[])
{
  std::string limitDirectory = "/uscms/homes/c/cawest/diphoton/limits/CMSSW_8_1_0/src/HiggsAnalysis/CombinedLimit";
  if(argc > 2) {
    std::cout << "Syntax: limit.exe [combine directory]" << std::endl;
    return -1;
  }
  else if(argc == 2) {
    limitDirectory = argv[1];
  }

  limit(limitDirectory);
}

void limit(const std::string &directory)
{

  oneLimit(2, 1, directory);
  oneLimit(2, 4, directory);
  oneLimit(4, 1, directory);
}

void oneLimit(int ned, int kk, const std::string &directory)
{
  std::map<int, std::string> kkconvention;
  kkconvention[1] = "HLZ";
  kkconvention[4] = "Hewett-";

  std::vector<float> stringScales = {3000, 3500, 4000, 4500, 5000, 5500, 6000,
				     7000, 8000, 9000, 10000, 11000};
  std::vector<float> minus2Sigma, minus1Sigma, mean, plus1Sigma, plus2Sigma;
  std::vector<float> observed;
  std::vector<float> dummy;

  TFile *f;
  for(unsigned int i=0; i<stringScales.size(); i++) {
    if(ned == 2 && kk == 4 && stringScales.at(i) > 6000) continue;
    TString filename(Form("%s/higgsCombineADDGravToGG_MS-%d_NED-%d_KK-%d.AsymptoticLimits.mH120.root", directory.c_str(), static_cast<int>(stringScales.at(i)), ned, kk));
    f = TFile::Open(filename);
    if(!f->IsOpen()) {
      std::cout << "Could not open file " << filename << std::endl;
      exit(1);
    }
    TTree *tree = static_cast<TTree*>(f->Get("limit"));
    if(tree == nullptr) { 
      std::cout << "Could not get limit tree " << filename << std::endl;
      exit(1);
    }
    
    double limit;
    double minus2SigmaExpected, minus1SigmaExpected, meanExpected, plus1SigmaExpected, plus2SigmaExpected;
    double obs;
    tree->SetBranchAddress("limit", &limit);
    tree->GetEntry(0);
    minus2SigmaExpected=limit;
    tree->GetEntry(1);
    minus1SigmaExpected=limit;
    tree->GetEntry(2);
    meanExpected=limit;
    tree->GetEntry(3);
    plus1SigmaExpected=limit;
    tree->GetEntry(4);
    plus2SigmaExpected=limit;
    tree->GetEntry(5);
    obs=limit;

    double xSec;
    xSec=1;
    minus2Sigma.push_back(abs(minus2SigmaExpected-meanExpected)*xSec);
    minus1Sigma.push_back(abs(minus1SigmaExpected-meanExpected)*xSec);
    mean.push_back(meanExpected*xSec);
    plus1Sigma.push_back(abs(plus1SigmaExpected-meanExpected)*xSec);
    plus2Sigma.push_back(abs(plus2SigmaExpected-meanExpected)*xSec);
    observed.push_back(obs*xSec);
    dummy.push_back(0);
  }

  setStyle();
  TCanvas *c = new TCanvas;
  if(useLogy) c->SetLogy();

  TGraph *gr = new TGraph(mean.size(), &stringScales.at(0), &mean.at(0));
  gr->SetTitle(";M_{S} (GeV);Signal strength");
  gr->SetMarkerStyle(kFullCircle);
  gr->GetYaxis()->SetTitleOffset(1.4);
  gr->GetYaxis()->SetTitleSize(0.04);
  gr->GetXaxis()->SetTitleSize(0.04);
  gr->GetXaxis()->SetNdivisions(505);
  gr->SetLineWidth(3);
  gr->SetMinimum(0.1);
  gr->SetMaximum(500);
  if(!useLogy) {
    gr->SetMinimum(0);
    gr->SetMaximum(3);
  }
  // expected limit +/- 1 sigma
  TGraphAsymmErrors *grMean = new TGraphAsymmErrors(mean.size(), &stringScales.at(0), &mean.at(0), 
						    &dummy.at(0), &dummy.at(0),
						    &minus1Sigma.at(0), &plus1Sigma.at(0));
  grMean->SetLineColor(kBlack);
  grMean->SetFillColor(kGreen+1);

  // expected limit +/- 2 sigma
  TGraphAsymmErrors *grMean2Sigma = new TGraphAsymmErrors(mean.size(), &stringScales.at(0), &mean.at(0), 
							  &dummy.at(0), &dummy.at(0),
							  &minus2Sigma.at(0), &plus2Sigma.at(0));
  grMean2Sigma->SetFillColor(kYellow);

  TGraph *grObserved = new TGraph(observed.size(), &stringScales.at(0), &observed.at(0));
  grObserved->SetLineWidth(2);
  grObserved->SetMarkerSize(2);

  // draw all limits
  gr->Draw("AL");
  grMean2Sigma->Draw("L3");
  grMean->Draw("L3");
  std::cout << "Expected limit (mu=1): " << intersection(gr, 1) << std::endl;
  std::cout << "Expected limit (mu=2): " << intersection(gr, 2) << std::endl;

  grMean->Draw("LX,same");
  if(drawObservedLimit) grObserved->Draw("LP");

  TLine * l = new TLine(gr->GetXaxis()->GetXmin(), 1, gr->GetXaxis()->GetXmax(), 1);
  l->SetLineColor(kBlack);
  l->SetLineStyle(kDashed);
  l->Draw();

  TLegend *leg = new TLegend(0.5, 0.6, 0.85, 0.9);
  if(drawObservedLimit) leg->AddEntry(grObserved, "Observed 95% CL limit", "L");
  leg->AddEntry(grMean, "Expected 95% CL limit", "L");
  leg->AddEntry(grMean, "Expected limit #pm 1 #sigma", "F");
  leg->AddEntry(grMean2Sigma, "Expected limit #pm 2 #sigma", "F");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->Draw();

  TLatex *lat = new TLatex;
  if( ned!=-1 ) {
    lat->DrawLatexNDC(0.2, 0.8, Form("N_{ED} = %d", ned));
    lat->DrawLatexNDC(0.2, 0.7, Form("%s", kkconvention[kk].c_str()));
  }

  drawHeader();
  c->Print(Form("plots/limits_ADDGravToGG_NED-%d_KK-%d.pdf", ned, kk));
}
