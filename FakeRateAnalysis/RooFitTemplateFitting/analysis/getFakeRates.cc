// Fits fake rate plots and creates an output file 
// containing a TF1 for each plot
// To generate the input files for this code:
// cd ${CMSSW_BASE}/src/diphoton-analysis/FakeRateAnalysis/RooFitTemplateFitting/analysis
// root -l -q ../scripts/fakeRateCalculation.C
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TFile.h"
#include "TString.h"

#include <string>
#include <map>

#include "../../../Tools/EasyPlot/tdrstyle.C"

TF1* getFakeRateFunction(const std::string& isolation, const std::string& region);


void getFakeRates(bool isMC=false)
{
  setTDRStyle();
  gROOT->ForceStyle();

  std::string fakeRateFile("fakeRatePlots.root");
  std::string fakeRateOutputFile("fakeRateFunctions_jetht.root");
  if(isMC) fakeRateOutputFile = "fakeRateFunctions_mc.root"

  std::vector<std::pair<int, int> > isolationRanges;
  isolationRanges.push_back(std::pair<int, int>(5, 10));
  isolationRanges.push_back(std::pair<int, int>(6, 11));
  isolationRanges.push_back(std::pair<int, int>(7, 12));
  isolationRanges.push_back(std::pair<int, int>(8, 13));
  isolationRanges.push_back(std::pair<int, int>(9, 14));
  isolationRanges.push_back(std::pair<int, int>(10, 15));
  isolationRanges.push_back(std::pair<int, int>(15, 20));
  isolationRanges.push_back(std::pair<int, int>(10, 20));

  // to create nice looking plots
  std::map<std::string, std::string> displayDictionary;
  displayDictionary["EB"] = "Barrel";
  displayDictionary["EE"] = "Endcap";

  std::vector<std::string> isolationSidebands;
  for(auto irange : isolationRanges) {
    std::string iso("chIso");
    iso+=std::to_string(irange.first);
    iso+="To";
    iso+=std::to_string(irange.second);
    isolationSidebands.push_back(iso);
  }

  std::vector<std::string> regions = {"EB", "EE"};

  TFile *input = TFile::Open(fakeRateFile.c_str());
  TFile *output = new TFile("fakeRateFunctions.root", "recreate");
  
  for(unsigned int iIso = 0; iIso<isolationSidebands.size(); iIso++) {
    for(unsigned int iRegion = 0; iRegion<regions.size(); iRegion++) { 
      TString histName(Form("fakeRate%s_%s", regions[iRegion].c_str(), isolationSidebands[iIso].c_str()));
      TGraphAsymmErrors *graph;
      std::cout << "Getting fake rate graph " << histName << " from file " << fakeRateFile << std::endl;
      input->GetObject(histName, graph);
      TCanvas *c = new TCanvas;
      c->SetLeftMargin(0.18);
      std::cout << "Getting fake rate function for isolation sideband " << isolationSidebands[iIso]
		<< " and region " << regions[iRegion] << std::endl;
      TF1 * func = getFakeRateFunction(isolationSidebands[iIso], regions[iRegion]);
      graph->Fit(func);
      graph->SetMarkerStyle(kFullCircle);
      graph->SetTitle(";Photon p_{T} (GeV);Fake rate");
      graph->GetYaxis()->SetTitleOffset(1.5); // times the standard value
      graph->SetMinimum(0.0);
      graph->Draw("AP");

      TLatex *latex = new TLatex;
      latex->SetNDC(true);
      latex->DrawLatex(0.5, 0.7, displayDictionary[regions[iRegion]].c_str());
      TString isoString(Form("%d < Iso_{ch} < %d GeV", isolationRanges[iIso].first, isolationRanges[iIso].second));
      latex->DrawLatex(0.5, 0.65, isoString);

      graph->Write();
      func->Write();
      c->Print(Form("plots/%s.pdf", histName.Data()));
    }
  }

  output->Close();
  input->Close();

}

TF1* getFakeRateFunction(const std::string& isolation, const std::string& region) 
{
  // fit range
  double xmin = 75.;
  double xmax = 2000.;

  // list of possible fit functions
  std::map<std::string, std::string> fitFunc;
  fitFunc["EB"] = "[0]+[1]/(x^[2])";
  fitFunc["EE"] = "(x<175)*([0]+[1]*(x-175)+[2]*(x-175)^2)+(x>175)*([3]+x*[4])";

  TString fitName(Form("fakeRate%s_%s_fit", region.c_str(), isolation.c_str()));

  TF1* fakeRate = new TF1(fitName, fitFunc[region].c_str(), xmin, xmax);

  // decent initial guesses are needed for the fit to converge
  if(region=="EB") fakeRate->SetParameters(0.00225253, 30882, 3.25285);
  if(region=="EE") fakeRate->SetParameters(0.00984487675098, 0.00001462335960, 0.00000249248908,
					   0.00728578882033, 0.00001462335960);

  return fakeRate;		    
}
