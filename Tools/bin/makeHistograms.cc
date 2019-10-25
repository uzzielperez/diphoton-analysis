#include "diphoton-analysis/Tools/interface/sampleList.hh"
#include "diphoton-analysis/Tools/interface/utilities.hh"

#include "TCanvas.h"
#include "TString.h"
#include "TH1.h"
#include "TFile.h"

void allSamples(const std::string &region, const std::string &year, TFile * output);
std::string getSampleBase(const std::string & sampleName, const std::string & year);
std::string getBase(const std::string & sampleName);

int main(int argc, char *argv[])
{
  std::string region, year;

  if(argc!=3) {
    std::cout << "Syntax: makeHistograms.exe [BB/BE] [2016/2017/2018]" << std::endl;
      return -1;
  }
  else {
    region = argv[1];
    if(region!="BB" and region!="BE") {
      std::cout << "Only 'BB' and 'BE' are allowed regions. " << std::endl;
      return -1;
    }
    year = argv[2];
    if(year!="2016" and year!="2017" and year!="2018") {
      std::cout << "Only '2016', 2017' and '2018' are allowed years. " << std::endl;
      return -1;
    }
  }

  // include signal samples but not unskimmed data samples
  init(false, true);

  TFile *output = new TFile(Form("datacards/Minv_histos_%s_%s.root", region.c_str(), year.c_str()), "recreate");
  output->mkdir(region.c_str());
  std::vector<std::string> fakeRates = {"average", "doublemuon", "jetht"};
  std::map<std::string, std::string> histPostFix;
  histPostFix["average"] = "";
  histPostFix["jetht"] = "_fake_sampleUp";
  histPostFix["doublemuon"] = "_fake_sampleDown";
  for (const auto& fakeRate : fakeRates) {
    TFile *fakes = new TFile(Form("data/fakes_%s_%s.root", year.c_str(), fakeRate.c_str()));
    TH1F *fakeHist = static_cast<TH1F*>(fakes->Get(Form("%s/gj", region.c_str())));
    output->cd(region.c_str());
    fakeHist->SetName(Form("gj%s", histPostFix[fakeRate].c_str()));
    fakeHist->Write();
  }
  allSamples(region, year, output);
  output->Write();
  output->Close();

}

void allSamples(const std::string &region, const std::string &year, TFile * output)
{

  int nBins = 80;
  double xMin = 0.0;
  double xMax = 4000.;

  std::map<std::string, std::string> cuts;
  cuts["BB"] = "isGood*(Diphoton.Minv > 500 && Diphoton.deltaR > 0.45 && Photon1.pt>125 && Photon2.pt>125 && Photon1.isEB && Photon2.isEB)";
  cuts["BE"] = "isGood*(Diphoton.Minv > 500 && Diphoton.deltaR > 0.45 && Photon1.pt>125 && Photon2.pt>125 && ( (Photon1.isEB && Photon2.isEE) || (Photon2.isEB &&  Photon1.isEE )))";

  std::vector<std::string> samples = getSampleList();

  // add scale variations
  samples.push_back("gg_R2F2_2016");
  samples.push_back("gg_R2F2_2017");
  samples.push_back("gg_R2F2_2018");
  samples.push_back("gg_R0p5F0p5_2016");
  samples.push_back("gg_R0p5F0p5_2017");
  samples.push_back("gg_R0p5F0p5_2018");


  std::vector<int> stringScales = {3000, 3500, 4000, 4500, 5000, 5500, 6000};

  for(auto isample : samples) {
    std::cout << isample << std::endl;
  }
  std::map<std::string, TH1F*> histograms;
  for(auto isample : samples) {
    std::string sampleCut = cuts[region];
    // skip the Sherpa GEN trees
    if( isample.compare("ggGen") == 0) continue;
    if( isample.find("unskimmed") != std::string::npos ) continue;
    // use data-driven prediction instead
    if( isample.find("gj") != std::string::npos ) continue;
    if( isample.find(year) == std::string::npos && isample.find("ADD") == std::string::npos ) continue;
    // apply weights for all samples except data
    bool is2015or2016 = isample.find("2015") != std::string::npos || isample.find("2016") != std::string::npos;
    if( isample.find("ADDGravToGG_MS") != std::string::npos
	|| isample.find("gg70") != std::string::npos
	|| is2015or2016 ) {
      sampleCut += "*(HLT_DoublePhoton60>0 || HLT_ECALHT800>0)";
    }
    else {
      sampleCut += "*(HLT_DoublePhoton70>0 || HLT_ECALHT800>0)";
    }
    if( isample.find("data") == std::string::npos ) {
      sampleCut+="*weightAll*" + std::to_string(luminosity[year]);
      // need to increase selection for ADD cuts to avoid negative weights
      // from background subtraction
      if( isample.find("ADD") != std::string::npos
	  or isample.find("gg70") != std::string::npos ) {
	sampleCut += "*(Diphoton.Minv > 600)";
      }
    }
    else {
      sampleCut += "*(Diphoton.Minv < 1000)";
    }
    // apply k-factor to Sherpa GG sample
    if( isample.find("gg_R2F2_") != std::string::npos) {
      if( is2015or2016 ) sampleCut += "*" + kfactorString(region, "R2F2_125GeV_CT10");
      else sampleCut += "*" + kfactorString(region, "R2F2_125GeV_NNPDF");
    }
    else if( isample.find("gg_R0p5F0p5_") != std::string::npos) {
      if( is2015or2016 ) sampleCut += "*" + kfactorString(region, "R0p5F0p5_125GeV_CT10");
      else sampleCut += "*" + kfactorString(region, "R0p5F0p5_125GeV_NNPDF");
    }
    else if( isample.find("gg_") != std::string::npos) {
      if( is2015or2016 ) sampleCut += "*" + kfactorString(region, "R1F1_125GeV_CT10");
      else sampleCut += "*" + kfactorString(region, "R1F1_125GeV_NNPDF");
    }
    std::cout << "Making histograms for sample " << isample << " with cut\n" << sampleCut << std::endl;
    std::string baseName(getSampleBase(isample, year));
    TH1F *hist = new TH1F(baseName.c_str(), baseName.c_str(), nBins, xMin, xMax);
    histograms[baseName] = hist;
    std::cout << "Making histograms for sample " << hist->GetName() << " with cut\n" << sampleCut << std::endl;
    chains[getBase(isample)]->Project(baseName.c_str(), "Diphoton.Minv",  sampleCut.c_str());
    // move overflow to last bin
    int nbins = histograms[baseName]->GetNbinsX();
    float lastBin = histograms[baseName]->GetBinContent(nbins);
    float overflow = histograms[baseName]->GetBinContent(nbins+1);
    histograms[baseName]->SetBinContent(nbins, lastBin + overflow);
    histograms[baseName]->SetBinContent(nbins+1, 0.0);
    std::cout << "Integral: " << histograms[baseName]->Integral() << std::endl;
    output->cd(region.c_str());
  }

  // subtract nonresonant background
  for(auto histogram : histograms) {
    std::string title(histogram.second->GetTitle());
    if(title.find("ADD") != std::string::npos) histogram.second->Add(histograms["gg70"], -1);
    histogram.second->Write();
  }

  // create additional histograms for scale variations only in BB or BE
  TH1F *scaleUp = dynamic_cast<TH1F*>(histograms["gg_diphotonkfactorScalesUp"]->Clone());
  std::string histNameBase("gg_diphotonkfactorScales");
  std::string histName = histNameBase + region + "Up";
  scaleUp->SetName(histName.c_str());
  TH1F *scaleDown = dynamic_cast<TH1F*>(histograms["gg_diphotonkfactorScalesDown"]->Clone());
  histName = histNameBase + region + "Down";
  scaleDown->SetName(histName.c_str());

}

// remove year
std::string getSampleBase(const std::string & sampleName, const std::string & year)
{
  std::string newString(sampleName);
  if( sampleName.find("_201") != std::string::npos) {
    newString.replace(newString.find("_201"), 5, "");
  }
  if(sampleName.find("_R2F2") != std::string::npos) {
    newString.replace(newString.find("_R2F2"), 5, "_diphotonkfactorScalesUp");
  }
  if(sampleName.find("_R0p5F0p5") != std::string::npos) {
    newString.replace(newString.find("_R0p5F0p5"), 9, "_diphotonkfactorScalesDown");
  }
  // "data_obs" is always the name of the data observation histogram
  std::string data("data_" + year);
  if( sampleName.compare(data) == 0) newString = "data_obs";
  return newString;
}

// ignore variations to get dataset name
std::string getBase(const std::string & sampleName)
{
  if(sampleName.compare("gg_R2F2_2016") == 0 ) return "gg_2016";
  if(sampleName.compare("gg_R0p5F0p5_2016") == 0 ) return "gg_2016";
  if(sampleName.compare("gg_R2F2_2017") == 0 ) return "gg_2017";
  if(sampleName.compare("gg_R0p5F0p5_2017") == 0 ) return "gg_2017";
  if(sampleName.compare("gg_R2F2_2018") == 0 ) return "gg_2018";
  if(sampleName.compare("gg_R0p5F0p5_2018") == 0 ) return "gg_2018";
  return sampleName;
}
