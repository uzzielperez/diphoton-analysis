// creates combine datacards for all signal points
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "TH1.h"
#include "TFile.h"

#include "diphoton-analysis/Tools/interface/sampleList.hh" // integrated luminosity only defined once
#include "diphoton-analysis/Tools/interface/utilities.hh"

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

double getYield(const std::string& region, const std::string& sample, const std::string& datacardYear, const int& minBin, const int& maxBin, double& yieldError, const TF1 * scaleFactor = 0);
std::string getDiphotonYieldVariations(const std::string& region, const int& minBin, const int& maxBin, const std::string& variation);
void makeOneDatacard(const std::string& signalPoint, const std::string& datacardYear, const std::string& interferenceType);

bool positiveInterference;
bool useInterference;

// Loop over ADD samples to make datacards for each
int main(int argc, char *argv[])
{
  std::string interferenceType("");

  positiveInterference=true;

  if(argc!=2 && argc!=3) {
    std::cout << "Syntax: makeDatacards.exe [2015/2016] [positive/negative]\n";
    std::cout << "If 'positive' or 'negative' are not specified,\n";
    std::cout << "linear scaling will be used for the interference term." << std::endl;
    return -1;
  }
  std::string datacardYear(argv[1]);
  if(argc==3) {
    interferenceType = argv[2];
    if(interferenceType.compare("negative") != 0 and interferenceType.compare("positive") != 0) {
      std::cout << "Only 'negative' and 'positive' are allowed input parameters. " << std::endl;
      return -1;
    }
    if(interferenceType == "negative") positiveInterference = false;
  }

  // string scales
  std::vector<std::string> MS = {"3000", "3500", "4000", "4500",
                                 "5000", "5500", "6000"};
  // number of extra dimensions
  std::vector<std::string> NED = {"2", "4"};
  // KK cutoff conventions
  std::vector<std::string> KK = {"1", "4"};

  useInterference = interferenceType.compare("negative") == 0 or interferenceType.compare("positive") == 0;
  // only need to use one NED or KK convention if interference is considered
  if(useInterference) {
    NED.erase(NED.begin()+1);
    KK.erase(KK.begin()+1);
  }

  for(const auto iMS : MS) {
    for(const auto iNED : NED) {
      for(const auto iKK : KK) {
        // no samples were generated with KK convention 4
        // and four extra dimensions
        if(strcmp(iKK.c_str(), "4")==0 && strcmp(iNED.c_str(), "4")==0) continue;
	std::string pointName = "ADDGravToGG_MS-";
        pointName += iMS;
	if(!useInterference) {
	  pointName += "_NED-";
	  pointName += iNED;
	  pointName += "_KK-";
	  pointName += iKK;
	}
	makeOneDatacard(pointName, datacardYear, interferenceType);
      }
    }
  }
}

void makeTable(const std::string& region, const std::vector<int>& binLowerLimits, const std::vector<int>& binUpperLimits)
{
  std::map<std::string, std::string> regionString;
  regionString["BB"] = "barrel-barrel";
  regionString["BE"] = "barrel-endcap";

  std::string filename("data/yields_");
  filename+=region;
  filename+=".tex";

  std::ofstream tableFile;
  tableFile.open(filename.c_str());
  if(tableFile.is_open()) {
    tableFile << "\\documentclass[12pt]{article}\n";
    tableFile << "\\usepackage{graphicx}\n";
    tableFile << "\\begin{document}\n";

    tableFile << "\\begin{table}[!htb]\n";
    tableFile << "\\begin{center}\n";
    tableFile << "\\caption{\\label{tab:" << region << "_yield}Event yields for " << regionString[region] << ".}\n";
    tableFile << "\\begin{tabular}{l ";
    for(unsigned int i=0; i<binLowerLimits.size(); i++) tableFile << " c";
    tableFile << "}\\hline\n";

    tableFile << "\\end{tabular}\n";
    tableFile << "\\end{center}\n";
    tableFile << "\\end{table}\n";

    tableFile << "\\end{document}\n" << std::endl;
    tableFile.close();
  }
  else {
    std::cout << "Could not open " << filename << std::endl;
  }
}

void makeOneDatacard(const std::string& signalPoint, const std::string& datacardYear, const std::string& interferenceType)
{
  std::vector<int> binLowerLimits = {11, 21, 31, 41, 46};
  std::vector<int> binUpperLimits;
  for(unsigned int i=1; i<binLowerLimits.size(); i++) {
    // add 1 to bin index to avoid double-counting bins in integral
    binUpperLimits.push_back(binLowerLimits.at(i)-1);
  }
  binUpperLimits.push_back(1001);
  std::vector<std::string> regions = {"BB", "BE"};
  for(auto iregion : regions) makeTable(iregion, binLowerLimits, binUpperLimits);

  // the following line assumes fakes taken from MC
  //  std::vector<std::string> processes = {signalPoint, "gg", "gj", "other"};
  std::string signalPointInt = signalPoint;
  signalPointInt += "_int";
  std::vector<std::string> processes = {signalPoint, "gg", "gjDataDriven", "other"};
  if(useInterference) {
    // need to include a separate column for interference term
    processes.insert(processes.begin()+1, signalPointInt);
  }

  for(unsigned int iBin = 0; iBin < binLowerLimits.size(); iBin++) {
  // define nuisances with dummy values for now
  std::string diphotonkfactorStatValue0 = getDiphotonYieldVariations("BB", binLowerLimits.at(iBin), binUpperLimits.at(iBin), "diphotonkfactorStat0");
  nuisance diphotonkfactorStat0("diphotonkfactorStat0", "lnN", {"-", diphotonkfactorStatValue0, "-", "-"});
  std::string diphotonkfactorStatValue1 = getDiphotonYieldVariations("BB", binLowerLimits.at(iBin), binUpperLimits.at(iBin), "diphotonkfactorStat1");
  nuisance diphotonkfactorStat1("diphotonkfactorStat1", "lnN", {"-", diphotonkfactorStatValue1, "-", "-"});
  std::string diphotonkfactorStatValue2 = getDiphotonYieldVariations("BB", binLowerLimits.at(iBin), binUpperLimits.at(iBin), "diphotonkfactorStat2");
  nuisance diphotonkfactorStat2("diphotonkfactorStat2", "lnN", {"-", diphotonkfactorStatValue2, "-", "-"});
  std::string diphotonkfactorStatValue3 = getDiphotonYieldVariations("BB", binLowerLimits.at(iBin), binUpperLimits.at(iBin), "diphotonkfactorStat3");
  nuisance diphotonkfactorStat3("diphotonkfactorStat3", "lnN", {"-", diphotonkfactorStatValue3, "-", "-"});
  //  std::string diphotonkfactorScalesValue = getDiphotonYieldVariations("BB", binLowerLimits.at(iBin), binUpperLimits.at(iBin), "diphotonkfactorScales");
  //  nuisance diphotonkfactorScales("diphotonkfactorScales", "lnN", {"-", diphotonkfactorScalesValue, "-", "-"});
  std::string lumiError = std::to_string(1 + luminosityErrorFrac[datacardYear]);
  nuisance lumi("lumi", "lnN", {lumiError, lumiError, "-", lumiError});
  nuisance pileup("pileup", "lnN", {"1.05", "1.05", "-", "1.05"});
  nuisance fakes("fakes", "lnN", {"-", "-", "1.3", "-"});
  nuisance eff("eff", "lnN", {"1.1", "1.1", "1.05", "1.05"});
  nuisance xsec_minor_bkg("xsec_minor_bkg", "lnN", {"-", "-", "-", "1.5"});

  std::vector<nuisance> allNuisances;
  allNuisances.push_back(diphotonkfactorStat0);
  allNuisances.push_back(diphotonkfactorStat1);
  allNuisances.push_back(diphotonkfactorStat2);
  allNuisances.push_back(diphotonkfactorStat3);
  //  allNuisances.push_back(diphotonkfactorScales);
  allNuisances.push_back(lumi);
  allNuisances.push_back(pileup);
  allNuisances.push_back(fakes);
  allNuisances.push_back(eff);
  allNuisances.push_back(xsec_minor_bkg);

  unsigned int nchannels = regions.size();
  unsigned int nbackgrounds = processes.size()-1;

  if(useInterference) {
    for(std::vector<nuisance>::iterator inuisance = allNuisances.begin();
	inuisance != allNuisances.end();  ++inuisance) {
      // use same systematics as signal for interference term
      (*inuisance).m_contribution.insert((*inuisance).m_contribution.begin()+1, (*inuisance).m_contribution.front());
    }
  }

  std::ofstream output;
  std::string filename("datacards/");
  filename+=signalPoint;
  if(useInterference) {
    filename+="_";
    filename+=interferenceType;
  }
  filename+="_";
  filename+=datacardYear;
  filename+="_bins";
  filename+=std::to_string(binLowerLimits.at(iBin));
  filename+="to";
  filename+=std::to_string(binUpperLimits.at(iBin));
  filename+=".dat";
  output.open(filename);
  if (output.is_open()) {
    double yieldError = 0.0;

    // header
    output << "imax " << nchannels << " number of channels" << std::endl;
    output << "jmax " << nbackgrounds << " number of backgrounds" << std::endl;
    output << "kmax " << allNuisances.size() << " number of nuisance parameters" << std::endl;
    output << "-------------------" << std::endl;
    
    // definition of bins and rates
    output << "bin          ";
    for(unsigned int i=0; i<nchannels; i++) {
      output << "b" << i << "   ";
    }
    output << "\n";
    output << "observation  ";
    for(auto iregion : regions) {
      output << getYield(iregion, "data_" + datacardYear, datacardYear, binLowerLimits.at(iBin), binUpperLimits.at(iBin), yieldError) << " " ;
    }
    output << "\n";
    
    output << "-------------------" << std::endl;
    output << "bin            ";
    
    for(unsigned iregion=0; iregion<regions.size(); iregion++) {
      for(auto iprocess : processes) {
	output << "b" << iregion << "    ";
      }
    }
    output << "\n";
    output << "process    ";
    for(auto iregion : regions) {
      for(int iprocess=0; iprocess<static_cast<int>(processes.size()); iprocess++) {
	if(useInterference) output << iprocess-1 << "    ";
	else output << iprocess << "    ";
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
	output << getYield(iregion, iprocess, datacardYear, binLowerLimits.at(iBin), binUpperLimits.at(iBin), yieldError) << "    ";
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
}

double getYield(const std::string& region, const std::string& sample, const std::string& datacardYear, const int& minBin, const int& maxBin, double& yieldError, const TF1 * scaleFactor)
{
  double integral = 0.0;

  std::string histName(region);
  histName+="/";

  // histograms for photon fakes from data-driven method are in a different file
  if(sample.find("gjDataDriven") != std::string::npos) {
    TFile *inputFakes = TFile::Open(Form("data/fakes_%s_jetht.root", datacardYear.c_str()));
    histName+=sample;
    histName+=region;

    TH1D *hist = static_cast<TH1D*>(inputFakes->Get(histName.c_str()));
    integral = hist->Integral(minBin, maxBin);
    inputFakes->Close();
  }
  else {
    TString filename("data/Minv_histos.root");
    if(useInterference) {
      filename = "data/Minv_histos_with_interference.root";
    }
    TFile *input = TFile::Open(filename);
    histName+=sample + "_" + datacardYear;
    
    std::cout << "Getting histogram " << histName << std::endl;
    TH1D *hist = static_cast<TH1D*>(input->Get(histName.c_str()));
    // take max to avoid negative entries arising from
    // negative weights in NLO samples
    integral = std::max(hist->Integral(minBin, maxBin), 0.0);
    if(sample.find("data") == std::string::npos) integral *= luminosity[datacardYear];
    else {
      std::cout << "Using bin with range " << hist->GetBinLowEdge(minBin) << " to " << hist->GetBinLowEdge(maxBin+1) << std::endl;
    }
    if(useInterference) {
      // in the case of negative interference, multiply inteference term by -k
      // and signal by k^2 to adjust to Hewett- convention
      if(sample.find("ADD") != std::string::npos && !positiveInterference) {
	double k = 2/TMath::Pi();
	if(sample.find("int") != std::string::npos) integral *= -k;
	else integral *= k*k;
      }
    }
    else {
      // if the sample is an ADD sample, need to subtract SM background
      if(sample.find("ADD") != std::string::npos) {
	std::string gg70HistName(region);
	gg70HistName+="/gg70";

	TH1D *gg70 = static_cast<TH1D*>(input->Get(gg70HistName.c_str()));
	integral -= luminosity[datacardYear]*gg70->Integral(minBin, maxBin);
      }
    }
    input->Close();
  }

  return integral;
}

std::string getDiphotonYieldVariations(const std::string& region, const int& minBin, const int& maxBin, const std::string& variation)
{
  // put dummy values here for now
  if(variation.find("diphotonkfactorStat") != std::string::npos) {
    int parameter = 0;
    if(strcmp(variation.c_str(), "diphotonkfactorStat1")==0) parameter = 1;
    if(strcmp(variation.c_str(), "diphotonkfactorStat2")==0) parameter = 2;
    if(strcmp(variation.c_str(), "diphotonkfactorStat3")==0) parameter = 3;
    TFile *input = TFile::Open("data/Minv_histos.root");
    TH1D* diphoton = static_cast<TH1D*>(input->Get(Form("%s/gg", region.c_str())));
    TH1D* diphotonStatUp = static_cast<TH1D*>(diphoton->Clone("diphotonStatUp"));
    TH1D* diphotonStatDown = static_cast<TH1D*>(diphoton->Clone("diphotonStatDown"));
    TF1 *kfactorFunction = kfactor(region, "R1F1");
    TString fitFunc("pol3");
    TString filename="data/kfactor_BB_R1F1.root";
    TFile *file = TFile::Open(filename);
    TFitResult* fitResult = static_cast<TFitResult*>(file->Get(Form("TFitResult-id1-%s",fitFunc.Data())));

    //    TF1 * variation(bool up, int parameter, TF1* nominal, TFitResult* fitResult)

    TF1 *kfactorStatUp = eigenvectorVariation(true, parameter, kfactorFunction, fitResult);
    TF1 *kfactorStatDown = eigenvectorVariation(false, parameter, kfactorFunction, fitResult);
    diphotonStatUp->Multiply(kfactorStatUp);
    diphotonStatDown->Multiply(kfactorStatDown);
    // need to undo the kfactor applied by default
    diphotonStatUp->Divide(kfactorFunction);
    diphotonStatDown->Divide(kfactorFunction);

    double integralUp = diphotonStatUp->Integral(minBin, maxBin);
    double integral = diphoton->Integral(minBin, maxBin);
    double integralDown = diphotonStatDown->Integral(minBin, maxBin);

    double averageVariation = (fabs(integralUp-integral) + fabs(integralDown-integral))/2.;

    input->Close();
    return std::to_string(1+averageVariation/integral);
  }
  if(strcmp(variation.c_str(), "diphotonkfactorScales")==0) {
    TFile *input = TFile::Open("data/Minv_histos.root");
    TH1D* diphoton = static_cast<TH1D*>(input->Get(Form("%s/gg", region.c_str())));
    TH1D* diphotonScalesUp = static_cast<TH1D*>(diphoton->Clone("diphotonScalesUp"));
    TH1D* diphotonScalesDown = static_cast<TH1D*>(diphoton->Clone("diphotonScalesDown"));
    TF1 *kfactorFunctionScalesUp = kfactor(region, "R2F2");
    TF1 *kfactorFunction = kfactor(region, "R1F1");
    TF1 *kfactorFunctionScalesDown = kfactor(region, "R0p5F0p5");
    diphotonScalesUp->Multiply(kfactorFunctionScalesUp);
    diphotonScalesDown->Multiply(kfactorFunctionScalesDown);
    // need to undo the kfactor applied by default
    diphotonScalesUp->Divide(kfactorFunction);
    diphotonScalesDown->Divide(kfactorFunction);

    double integralUp = diphotonScalesUp->Integral(minBin, maxBin);
    double integral = diphoton->Integral(minBin, maxBin);
    double integralDown = diphotonScalesDown->Integral(minBin, maxBin);

    double averageVariation = (fabs(integralUp-integral) + fabs(integralDown-integral))/2.;

    input->Close();
    return std::to_string(1+averageVariation/integral);
  }
  if(strcmp(variation.c_str(), "diphotonFragmentation")==0) return "1.01";

  std::cout << "Systematic variation not found!" << std::endl;
  exit(-1);

  return "";
}
