#ifdef __CINT__
#include "interface/tdrstyle.hh"
#include "interface/sampleList.hh"
#else
#include "diphoton-analysis/Tools/interface/tdrstyle.hh"
#include "diphoton-analysis/Tools/interface/sampleList.hh"
#endif

#include "TCanvas.h"
#include "TEfficiency.h"
#include "TH1.h"

#include <iostream>
#include <algorithm>

void oneHist(const std::string& varname, TChain *ch, const std::string& year);
int efficiency(const std::string& year, const std::string& variable);

int main()
{
  setTDRStyle();
  // initialize chains
  init();

  std::vector<std::string> years = {"2015", "2016"};
  std::vector<std::string> variables = {"Photon2.pt"};

  for(auto iyear : years) {
    for(auto ivar : variables) {
      efficiency(iyear, ivar);
    }
  }

  return 0;
}

int efficiency(const std::string& year = "2016", const std::string& variable = "Photon2.pt")
{
  std::cout << "Calculating trigger turn-on for " << variable 
	    << " in " << year << " data." << std::endl;


  std::string chainName("data_");
  chainName += year;
  std::cout << "Processing " << chains[chainName]->GetEntries() << " entries." << std::endl;

  oneHist(variable, chains[chainName], year);

  return 0;
}


void oneHist(const std::string& varname, TChain *ch, const std::string& year)
{
  int nbins = 40;
  double min = 0.0;
  double max = 1000.0;

  std::string histnames[2] = {"numerator", "denominator"};
  std::vector<TH1F*> hists;
  
  for(int i = 0; i < 2; i++) {
    hists.push_back(new TH1F(histnames[i].c_str(), histnames[i].c_str(), nbins, min, max));
  }

  std::string numerator(varname);
  numerator += ">>numerator";
  std::string denominator(varname);
  denominator += ">>denominator";

  ch->Draw(numerator.c_str() , "isGood && HLT_DoublePhoton60");
  ch->Draw(denominator.c_str(), "isGood && HLT_DoublePhoton40");

  // add overflow
  for(int i = 0; i < 2; i++) {
    int maxBin = hists[i]->GetNbinsX();
    hists[i]->SetBinContent(maxBin, hists[i]->GetBinContent(maxBin) + hists[i]->GetBinContent(maxBin+1));
  }


  TCanvas *c1 = new TCanvas;
  TEfficiency *eff = new TEfficiency(*hists[0], *hists[1]);
  eff->Draw("AP");
  eff->SetTitle(";p_{T}(#gamma_{2}) (GeV);Efficiency");
  // latex can't figure out what to do with files 
  // with more than one period in them
  std::string varForFilename(varname);
  std::replace(varForFilename.begin(), varForFilename.end(), '.', '_');
  c1->Print(Form("plots/eff_%s_%s.pdf", year.c_str(), varForFilename.c_str()));
}
