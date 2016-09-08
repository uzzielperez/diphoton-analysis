// creates combine datacards for all signal points
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "TH1.h"
#include "TFile.h"

#include "diphoton-analysis/Tools/interface/sampleList.hh" // integrated luminosity only defined once

class nuisance {

public:
  nuisance(std::string syst, std::string distribution, std::vector<std::string> contribution) :
    m_syst(syst),
    m_distribution(distribution),
    m_contribution(contribution) {}
  std::string m_syst;
  std::string m_distribution;
  std::vector<std::string> m_contribution;
};

double getYield(const std::string& region, const std::string& sample, const int& minBin);
void makeOneDatacard(const std::string& signalPoint);

// Loop over ADD samples to make datacards for each
int main()
{
  // string scales
  std::vector<std::string> MS = {"3000", "3500", "4000", "4500",
                                 "5000", "5500", "6000"};
  // number of extra dimensions
  std::vector<std::string> NED = {"2", "4"};
  // KK cutoff conventions
  std::vector<std::string> KK = {"1", "4"};

  for(const auto iMS : MS) {
    for(const auto iNED : NED) {
      for(const auto iKK : KK) {
        // no samples were generated with KK convention 4
        // and four extra dimensions
        if(strcmp(iKK.c_str(), "4")==0 && strcmp(iNED.c_str(), "4")==0) continue;
	std::string pointName = "ADDGravToGG_MS-";
        pointName += iMS;
        pointName += "_NED-";
        pointName += iNED;
        pointName += "_KK-";
        pointName += iKK;
	makeOneDatacard(pointName);
      }
    }
  }
}

void makeOneDatacard(const std::string& signalPoint)
{
  // lower limit of bin number; for now only a single bin is supported
  std::vector<int> binLowerLimits = {21};
  std::vector<std::string> regions = {"BB", "BE"};
  // the following line assumes fakes taken from MC
  //  std::vector<std::string> processes = {signalPoint, "gg", "gj", "other"};
  std::vector<std::string> processes = {signalPoint, "gg", "gjDataDriven", "other"};
  unsigned int nchannels = regions.size()*binLowerLimits.size();
  unsigned int nbackgrounds = processes.size()-1;

  // define nuisances with dummy values for now
  nuisance smkfactor("smkfactor", "lnN", {"-", "1.1", "-", "-"});
  nuisance lumi("lumi", "lnN", {"1.062", "1.062", "-", "1.062"});
  nuisance pileup("pileup", "lnN", {"1.05", "1.05", "-", "1.05"});
  nuisance fakes("fakes", "lnN", {"-", "-", "1.3", "-"});
  nuisance eff("eff", "lnN", {"1.1", "1.1", "1.05", "1.05"});
  nuisance xsec_minor_bkg("xsec_minor_bkg", "lnN", {"-", "-", "-", "1.5"});

  std::vector<nuisance> allNuisances;
  allNuisances.push_back(smkfactor);
  allNuisances.push_back(lumi);
  allNuisances.push_back(pileup);
  allNuisances.push_back(fakes);
  allNuisances.push_back(eff);
  allNuisances.push_back(xsec_minor_bkg);

  std::ofstream output;
  std::string filename("datacards/");
  filename+=signalPoint;
  filename+=".dat";
  output.open(filename);
  if (output.is_open()) {
    // header
    output << "imax " << nchannels << " number of channels" << std::endl;
    output << "jmax " << nbackgrounds << " number of backgrounds" << std::endl;
    output << "kmax " << allNuisances.size() << " number of nuisance parameters" << std::endl;
    output << "-------------------" << std::endl;
    
    // definition of bins and rates
    output << "bin          ";
    for(unsigned int i=0; i<nchannels; i++) {
      output << i << "   ";
    }
    output << "\n";
    output << "observation  ";
    for(auto iregion : regions) {
      output << getYield(iregion, "data", binLowerLimits.at(0)) << " " ;
    }
    output << "\n";
    
    output << "-------------------" << std::endl;
    output << "bin            ";
    
    for(unsigned iregion=0; iregion<regions.size(); iregion++) {
      for(auto iprocess : processes) {
	output << iregion << "    ";
      }
    }
    output << "\n";
    output << "process    ";
    for(auto iregion : regions) {
      for(unsigned iprocess=0; iprocess<processes.size(); iprocess++) {
	output << iprocess << "    ";
      }
    }
    output << "\n";
    output << "process    ";
    
    for(auto iregion : regions) {
      for(auto iprocess : processes) {
	output << iprocess << "    ";
      }
    }
    
    output << "\n";
    // output rates
    output << "rate        ";
    for(auto iregion : regions) {
      for(auto iprocess : processes) {
	output << getYield(iregion, iprocess, binLowerLimits.at(0)) << "    ";
      }
    }
    output << "\n-------------------" << std::endl;
    
    // output systematics
    for(auto inuisance : allNuisances) {
      output << inuisance.m_syst  << "      " << inuisance.m_distribution << "  ";
      for(auto iregion : regions) {
	for( auto icontrib : inuisance.m_contribution) {
	  output << icontrib << " ";
	}
      }
      output << "\n";
    }
  } // closes is_open()
  else {
    std::cout << "Could not open output file " << filename << std::endl;
  }
}

double getYield(const std::string& region, const std::string& sample, const int& minBin)
{
  double integral = 0.0;

  std::string histName(region);
  histName+="/";

  // histograms for photon fakes from data-driven method are in a different file
  if(sample.find("gjDataDriven") != std::string::npos) {
    TFile *inputFakes = TFile::Open("data/fakes.root");
    histName+=sample;
    histName+=region;

    TH1D *hist = static_cast<TH1D*>(inputFakes->Get(histName.c_str()));
    integral = hist->Integral(minBin, hist->GetNbinsX()+1);
    inputFakes->Close();
  }
  else {
    TFile *input = TFile::Open("data/Minv_histos.root");
    histName+=sample;
    
    TH1D *hist = static_cast<TH1D*>(input->Get(histName.c_str()));
    integral = hist->Integral(minBin, hist->GetNbinsX()+1);
    if(sample.find("data") == std::string::npos) integral *= luminosity;

    // if the sample is an ADD sample, need to subtract SM background
    if(sample.find("ADD") != std::string::npos) {
      std::string gg70HistName(region);
      gg70HistName+="/gg70";
      
      TH1D *gg70 = static_cast<TH1D*>(input->Get(gg70HistName.c_str()));
      integral -= luminosity*gg70->Integral(minBin, hist->GetNbinsX()+1);
    }
    input->Close();
  }

  return integral;
}
