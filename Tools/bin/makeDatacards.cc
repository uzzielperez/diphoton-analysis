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

double getYield(const std::string& region, const std::string& sample, const std::string& datacardYear, double& yieldError, const TF1 * scaleFactor = 0);
std::string getDiphotonYieldVariations(const std::string& region, const std::string& variation);
void makeOneDatacard(const std::string& signalPoint, const std::string& region, const std::string& datacardYear, const std::string& interferenceType);

bool positiveInterference;
bool useInterference;

std::string datacardYear;

// Loop over ADD samples to make datacards for each
int main(int argc, char *argv[])
{
  std::string interferenceType("");

  positiveInterference=true;

  if(argc!=2 && argc!=3) {
    std::cout << "Syntax: makeDatacards.exe [2015/2016/2017/2018] [positive/negative]\n";
    std::cout << "If 'positive' or 'negative' are not specified,\n";
    std::cout << "linear scaling will be used for the interference term." << std::endl;
    return -1;
  }
  datacardYear = argv[1];
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
                                 "5000", "5500", "6000", "7000",
				 "8000", "9000", "10000", "11000"};
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
	// Hewett- convention samples do not extend past Mgg > 6 TeV
	if(iNED.compare("2")==0 && iKK.compare("4")==0 && std::stoi(iMS)>6000) continue;
	std::string pointName = "ADDGravToGG_MS-";
        pointName += iMS;
	if(!useInterference) {
	  pointName += "_NED-";
	  pointName += iNED;
	  pointName += "_KK-";
	  pointName += iKK;
	}
	makeOneDatacard(pointName, "BB", datacardYear, interferenceType);
	makeOneDatacard(pointName, "BE", datacardYear, interferenceType);
      }
    }
  }
}

void makeTable(const std::string& region)
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
    tableFile << " c";
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

void makeOneDatacard(const std::string& signalPoint, const std::string& region, const std::string& datacardYear, const std::string& interferenceType)
{
  const bool scaleRegionNorm = true;

  makeTable(region);

  std::string signalPointInt = signalPoint;
  signalPointInt += "_int";
  std::vector<std::string> processes = {signalPoint, "gg", "gj", "other"};
  if(useInterference) {
    // need to include a separate column for interference term
    processes.insert(processes.begin()+1, signalPointInt);
  }

  // std::string diphotonkfactorStatValue0 = getDiphotonYieldVariations(region, "diphotonkfactorStat0");
  // nuisance diphotonkfactorStat0("diphotonkfactorStat0", "lnN", {"-", diphotonkfactorStatValue0, "-", "-"});
  // std::string diphotonkfactorStatValue1 = getDiphotonYieldVariations(region, "diphotonkfactorStat1");
  // nuisance diphotonkfactorStat1("diphotonkfactorStat1", "lnN", {"-", diphotonkfactorStatValue1, "-", "-"});
  // std::string diphotonkfactorStatValue2 = getDiphotonYieldVariations(region, "diphotonkfactorStat2");
  // nuisance diphotonkfactorStat2("diphotonkfactorStat2", "lnN", {"-", diphotonkfactorStatValue2, "-", "-"});
  // std::string diphotonkfactorStatValue3 = getDiphotonYieldVariations(region, "diphotonkfactorStat3");
  // nuisance diphotonkfactorStat3("diphotonkfactorStat3", "lnN", {"-", diphotonkfactorStatValue3, "-", "-"});
  nuisance diphotonkfactorScalesBB("diphotonkfactorScalesBB", "shape", {"-", "1", "-", "-"});
  nuisance diphotonkfactorScalesBB_dummy("diphotonkfactorScalesBB", "shape", {"-", "-", "-", "-"});
  nuisance diphotonkfactorScalesBE("diphotonkfactorScalesBE", "shape", {"-", "1", "-", "-"});
  nuisance diphotonkfactorScalesBE_dummy("diphotonkfactorScalesBE", "shape", {"-", "-", "-", "-"});
  nuisance diphotonNormBB("diphotonNormBB", "lnU", {"-", "1.5", "-", "-"});
  nuisance diphotonNormBB_dummy("diphotonNormBB_dummy", "lnU", {"-", "-", "-", "-"});
  nuisance diphotonNormBE("diphotonNormBE", "lnU", {"-", "1.5", "-", "-"});
  nuisance diphotonNormBE_dummy("diphotonNormBE_dummy", "lnU", {"-", "-", "-", "-"});
  std::string lumiError = std::to_string(1 + luminosityErrorFrac[datacardYear]);
  nuisance lumi("lumi", "lnN", {lumiError, lumiError, "-", lumiError});
  nuisance pileup("pileup", "lnN", {"1.05", "1.05", "-", "1.05"});
  nuisance fake_sample("fake_sample", "shape", {"-", "-", "1.0", "-"});
  nuisance eff("eff", "lnN", {"1.1", "1.1", "1.05", "1.1"});
  nuisance xsec_minor_bkg("xsec_minor_bkg", "lnN", {"-", "-", "-", "1.5"});

  std::vector<nuisance> allNuisances;
  // allNuisances.push_back(diphotonkfactorStat0);
  // allNuisances.push_back(diphotonkfactorStat1);
  // allNuisances.push_back(diphotonkfactorStat2);
  // allNuisances.push_back(diphotonkfactorStat3);
  if(region.compare("BB") == 0) {
    allNuisances.push_back(diphotonkfactorScalesBB);
    allNuisances.push_back(diphotonkfactorScalesBE_dummy);
    if(scaleRegionNorm) {
      allNuisances.push_back(diphotonNormBE);
      allNuisances.push_back(diphotonNormBB_dummy);
    }
  }
  else {
    allNuisances.push_back(diphotonkfactorScalesBB_dummy);
    allNuisances.push_back(diphotonkfactorScalesBE);
    if(scaleRegionNorm) {
      allNuisances.push_back(diphotonNormBB);
      allNuisances.push_back(diphotonNormBE_dummy);
    }
  }
  allNuisances.push_back(lumi);
  allNuisances.push_back(pileup);
  allNuisances.push_back(fake_sample);
  allNuisances.push_back(eff);
  allNuisances.push_back(xsec_minor_bkg);

  unsigned int nchannels = 1;
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
  filename+="_" + region;
  filename+=".dat";
  output.open(filename);
  if (output.is_open()) {
    double yieldError = 0.0;

    // header
    output << "imax " << nchannels << " number of channels" << std::endl;
    output << "jmax " << nbackgrounds << " number of backgrounds" << std::endl;
    output << "kmax " << allNuisances.size() << " number of nuisance parameters" << std::endl;
    output << "-------------------" << std::endl;
    output << "shapes * " << region << " datacards/Minv_histos_$CHANNEL_" << datacardYear << ".root $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC" << std::endl;
    output << "-------------------" << std::endl;

    // definition of bins and rates
    output << "bin          ";
    for(unsigned int i=0; i<nchannels; i++) {
      output << region << "   ";
    }
    output << "\n";
    output << "observation  ";
    output << getYield(region, "data_obs", datacardYear, yieldError) << " " ;
    output << "\n";
    
    output << "-------------------" << std::endl;
    output << "bin            ";
    
    for(auto iprocess : processes) {
      output << region << "    ";
    }
    output << "\n";
    output << "process    ";
    for(int iprocess=0; iprocess<static_cast<int>(processes.size()); iprocess++) {
      if(useInterference) output << iprocess-1 << "    ";
      else output << iprocess << "    ";
    }
    output << "\n";
    output << "process    ";
    
    for(auto iprocess : processes) {
      output << iprocess << "    ";
    }
    
    output << "\n";
    // output rates
    output << "rate        ";
    for(auto iprocess : processes) {
      output << getYield(region, iprocess, datacardYear, yieldError) << "    ";
    }
    output << "\n-------------------" << std::endl;
    
    // output systematics
    for(auto inuisance : allNuisances) {
      output << inuisance.m_syst  << "      " << inuisance.m_distribution << "  ";
      for( auto icontrib : inuisance.m_contribution) {
	output << icontrib << " ";
      }
      output << "\n";
    }
  } // closes is_open()
  else {
    std::cout << "Could not open output file " << filename << std::endl;
  }
}

double getYield(const std::string& region, const std::string& sample, const std::string& datacardYear, double& yieldError, const TF1 * scaleFactor)
{
  double integral = 0.0;

  std::string histName(region);
  histName+="/";

  // histograms for photon fakes from data-driven method are in a different file
  if(sample.find("gj") != std::string::npos) {
    TFile *inputFakes = TFile::Open(Form("data/fakes_%s_average.root", datacardYear.c_str()));
    histName+=sample;
    histName+="DataDriven";
    histName+=region;

    TH1D *hist = static_cast<TH1D*>(inputFakes->Get(histName.c_str()));
    integral = hist->Integral();
    inputFakes->Close();
  }
  else {
    TString filename(Form("datacards/Minv_histos_%s_%s.root", region.c_str(), datacardYear.c_str()));
    if(useInterference) {
      filename = "data/Minv_histos_with_interference.root";
    }
    TFile *input = TFile::Open(filename);
    histName+=sample;
    
    std::cout << "Getting histogram " << histName << std::endl;
    TH1D *hist = static_cast<TH1D*>(input->Get(histName.c_str()));
    // take max to avoid negative entries arising from
    // negative weights in NLO samples
    integral = hist->Integral();
    if(useInterference) {
      // in the case of negative interference, multiply inteference term by -k
      // and signal by k^2 to adjust to Hewett- convention
      if(sample.find("ADD") != std::string::npos && !positiveInterference) {
	double k = 2/TMath::Pi();
	if(sample.find("int") != std::string::npos) integral *= -k;
	else integral *= k*k;
      }
    }
    input->Close();
  }

  return integral;
}

std::string getDiphotonYieldVariations(const std::string& region, const std::string& variation)
{
  TString histogramFile(Form("datacards/Minv_histos_%s_%s.root", region.c_str(), datacardYear.c_str()));
  // put dummy values here for now
  if(variation.find("diphotonkfactorStat") != std::string::npos) {
    int parameter = 0;
    if(strcmp(variation.c_str(), "diphotonkfactorStat1")==0) parameter = 1;
    if(strcmp(variation.c_str(), "diphotonkfactorStat2")==0) parameter = 2;
    if(strcmp(variation.c_str(), "diphotonkfactorStat3")==0) parameter = 3;
    TFile *input = TFile::Open(histogramFile);
    TH1D* diphoton = static_cast<TH1D*>(input->Get(Form("%s/gg", region.c_str())));
    TH1D* diphotonStatUp = static_cast<TH1D*>(diphoton->Clone("diphotonStatUp"));
    TH1D* diphotonStatDown = static_cast<TH1D*>(diphoton->Clone("diphotonStatDown"));
    TF1 *kfactorFunction = kfactor(region, "R1F1");
    TString fitFunc("pol3");
    TString filename="data/kfactor_" + region + "_R1F1.root";
    TFile *file = TFile::Open(filename);
    TFitResult* fitResult = static_cast<TFitResult*>(file->Get(Form("TFitResult-id1-%s",fitFunc.Data())));

    TF1 *kfactorStatUp = eigenvectorVariation(true, parameter, kfactorFunction, fitResult);
    TF1 *kfactorStatDown = eigenvectorVariation(false, parameter, kfactorFunction, fitResult);
    diphotonStatUp->Multiply(kfactorStatUp);
    diphotonStatDown->Multiply(kfactorStatDown);
    // need to undo the kfactor applied by default
    diphotonStatUp->Divide(kfactorFunction);
    diphotonStatDown->Divide(kfactorFunction);

    double integralUp = diphotonStatUp->Integral();
    double integral = diphoton->Integral();
    double integralDown = diphotonStatDown->Integral();

    double averageVariation = (fabs(integralUp-integral) + fabs(integralDown-integral))/2.;

    input->Close();
    return std::to_string(1+averageVariation/integral);
  }
  if(strcmp(variation.c_str(), "diphotonkfactorScales")==0) {
    TFile *input = TFile::Open(histogramFile);
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

    double integralUp = diphotonScalesUp->Integral();
    double integral = diphoton->Integral();
    double integralDown = diphotonScalesDown->Integral();

    double averageVariation = (fabs(integralUp-integral) + fabs(integralDown-integral))/2.;

    input->Close();
    return std::to_string(1+averageVariation/integral);
  }
  if(strcmp(variation.c_str(), "diphotonFragmentation")==0) return "1.01";

  std::cout << "Systematic variation not found!" << std::endl;
  exit(-1);

  return "";
}
