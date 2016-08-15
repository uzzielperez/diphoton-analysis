#ifndef EASYPLOT_HH
#define EASYPLOT_HH

#include "sampleList.hh"

#include "TCanvas.h"
#include "TChain.h"
#include "TH1.h"
#include "THStack.h"
#include "TLegend.h"
#include "TString.h"

#include <string>
#include <vector>

TString reformat(TString input);


class sample {
  
public:
  sample(std::string name, std::string label, double extraWeight, std::string extraCut);
  sample();

  TChain* chain() { return chains[m_name]; }
  std::string name() { return m_name; }
  double extraWeight() { return m_extraWeight; }
  std::string extraCut() { return m_extraCut; }
  int lineStyle() { return m_lineStyle; }
  int lineColor() { return m_lineColor; }
  int fillStyle() { return m_fillStyle; }
  int fillColor() { return m_fillColor; }

  bool isData;

private:
  std::string m_name;
  std::string m_label;
  double m_extraWeight;
  std::string m_extraCut;
  int m_lineStyle;
  int m_lineColor;
  int m_fillStyle;
  int m_fillColor;
};

sample::sample(std::string name, std::string label, double extraWeight=1.0, std::string extraCut="1"):
  m_name(name),
  m_label(label),
  m_extraWeight(extraWeight),
  m_extraCut(extraCut),
  m_lineStyle(lineStyles[m_name]),
  m_lineColor(lineColors[m_name]),
  m_fillStyle(fillStyles[m_name]),
  m_fillColor(fillColors[m_name])
{
  isData=false;
}

// make compiler happy
sample::sample() {}

class plot {

public:
  plot(std::vector<sample> samples, std::string variable, std::string cut, int nbins, double xmin, double xmax);
  void output(std::string outputDirectory);
  std::string variable() { return m_variable; }
  std::string cut() {return m_cut; }

private:
  std::vector<sample> m_samples;
  std::string m_variable;
  std::string m_cut;
  int m_nbins;
  double m_xmin;
  double m_xmax;

};

plot::plot(std::vector<sample> samples, std::string variable, std::string cut, int nbins, double xmin, double xmax):
  m_samples(samples),
  m_variable(variable),
  m_cut(cut),
  m_nbins(nbins),
  m_xmin(xmin),
  m_xmax(xmax)
{ 
}



void plot::output(std::string outputDirectory)
{
  TCanvas *c = new TCanvas;
  std::vector<TH1D*> hists;
  
  for(auto isample : m_samples) {
    TString newCut(m_cut.c_str());
    if(isample.name().find("data")==std::string::npos) newCut = Form("weightAll*%6.6e*%6.6e*((%s)*(%s))", 
								     luminosity, isample.extraWeight(), m_cut.c_str(), isample.extraCut().c_str());
    // std::string histName(isample.name());
    // histName += "_";
    // histName += m_variable;
    hists.push_back(new TH1D(isample.name().c_str(), isample.name().c_str(), m_nbins, m_xmin, m_xmax));
    isample.chain()->Project(isample.name().c_str(), m_variable.c_str(), newCut.Data());
    hists.back()->SetLineStyle(isample.lineStyle());
    hists.back()->SetLineColor(isample.lineColor());
    hists.back()->SetFillStyle(isample.fillStyle());
    hists.back()->SetFillColor(isample.fillColor());
  }

  THStack *hs = new THStack("hs", "hs");
  for(auto ihist : hists) {
    // don't stack the data histogram
    TString name(ihist->GetName());
    if(!name.Contains("data")) hs->Add(ihist);
  }

  TLegend *leg = new TLegend(0.6, 0.6, 0.9, 0.9);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);

  // draw data histogram on top
  for(auto ihist : hists) {
    TString name(ihist->GetName());
    ihist->SetLineColor(kBlack);
    ihist->GetXaxis()->SetNdivisions(505);
    ihist->GetXaxis()->SetTitle(reformat(m_variable.c_str()));
    ihist->SetTitle(reformat(m_cut.c_str()));

    int binWidth=static_cast<int>((m_xmax-m_xmin)/m_nbins);
    TString yTitle(Form("Events / %d", binWidth));
    // if the bin width was rounded to zero, use a double instead
    if(binWidth==0) {
      double binWidthD = static_cast<double>((m_xmax-m_xmin)/m_nbins);
      yTitle = Form("Events / %1.1f", binWidthD);
    }
    if(m_variable.find("Minv")!=std::string::npos ||
       m_variable.find("qt")!=std::string::npos ||
       m_variable.find("pt")!=std::string::npos )  yTitle=Form("Events / %d GeV", binWidth);
    ihist->GetYaxis()->SetTitle(reformat(yTitle));
    ihist->GetYaxis()->SetTitleOffset(1.35);

    if(name.Contains("data")) {
      ihist->Draw("e");
      leg->AddEntry(ihist, prettyName[ihist->GetName()].c_str(), "ELP");
    }
    else {
      leg->AddEntry(ihist, prettyName[ihist->GetName()].c_str(), "F");
    }
  }

  hs->Draw("hist,same");

  // draw data histogram on top
  for(auto ihist : hists) {
    TString name(ihist->GetName());
    if(name.Contains("data")) ihist->Draw("e,same");
  }
  
  leg->Draw();

  c->RedrawAxis();

  c->Print(Form("%s/%s.pdf", outputDirectory.c_str(), variable().c_str()));
  c->Print(Form("%s/%s.root", outputDirectory.c_str(), variable().c_str()));
}

TString reformat(TString input)
{
  TString output=input;
  if(input.Contains("Minv") || input.Contains("pt")) output+=" (GeV)";
  output.ReplaceAll("Minv", "m_{#gamma#gamma}");
  output.ReplaceAll("Photon1.pt", "p_{T1}");
  output.ReplaceAll("Photon2.pt", "p_{T2}");
  output.ReplaceAll("Diphoton.qt", "q_{T,#gamma#gamma}");
  output.ReplaceAll("Diphoton.deltaPhi", "#Delta#phi_{#gamma#gamma}");
  output.ReplaceAll("Diphoton.deltaEta", "#Delta#eta_{#gamma#gamma}");

  return output;
}


#endif
