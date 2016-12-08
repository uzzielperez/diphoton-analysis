#include "diphoton-analysis/Tools/interface/sampleList.hh"
#include "diphoton-analysis/Tools/interface/utilities.hh"

#include "TCanvas.h"
#include "TString.h"
#include "TH1.h"
#include "TFile.h"

void allSamples(const std::string &region, TFile * output);
std::string getBase(const std::string & sampleName);

int main()
{
  init();

  TFile *output = new TFile("data/Minv_histos.root", "recreate");
  output->mkdir("BB");
  output->mkdir("BE");
  output->cd("BE");
  allSamples("BE", output);
  output->cd("BB");
  allSamples("BB", output);
  output->Write();
  output->Close();

}

void allSamples(const std::string &region, TFile * output)
{

  int nBins = 120;
  double xMin = 0.0;
  double xMax = 6000.;

  std::map<std::string, std::string> cuts;
  cuts["BB"] = "isGood*(Photon1.pt>75 && Photon2.pt>75 && Photon1.isEB && Photon2.isEB)";
  cuts["BE"] = "isGood*(Photon1.pt>75 && Photon2.pt>75 && ( (Photon1.isEB && Photon2.isEE) || (Photon2.isEB &&  Photon1.isEE )))";

  std::vector<std::string> samples = getSampleList();

  // add scale variations
  samples.push_back("gg_R2F2");
  samples.push_back("gg_R0p5F0p5");

  std::vector<int> stringScales = {3000, 3500, 4000, 4500, 5000, 5500, 6000};

  for(auto isample : samples) {
    std::cout << isample << std::endl;
  }
  for(auto isample : samples) {
    std::string sampleCut = cuts[region];
    // skip the Sherpa GEN trees
    if( isample.compare("ggGen") == 0) continue;
    // apply weights for all samples except data
    if( isample.compare("data") != 0 ) sampleCut+="*weightAll";
    // need to re-run to add this trigger
    //    else sampleCut+="*HLT_DoublePhoton60_v1";
    // apply k-factor to Sherpa GG sample
    if( isample.compare("gg") == 0) sampleCut += "*" + kfactorString(region, "R1F1");
    if( isample.compare("gg_R2F2") == 0) sampleCut += "*" + kfactorString(region, "R2F2");
    if( isample.compare("gg_R0p5F0p5") == 0) sampleCut += "*" + kfactorString(region, "R0p5F0p5");
    std::cout << "Making histograms for sample " << isample << " with cut\n" << sampleCut << std::endl;
    TH1F *hist = new TH1F(isample.c_str(), isample.c_str(), nBins, xMin, xMax);
    std::cout << "Making histograms for sample " << hist->GetName() << " with cut\n" << sampleCut << std::endl;
    chains[getBase(isample)]->Project(isample.c_str(), "Diphoton.Minv",  sampleCut.c_str());
    output->cd(region.c_str());
    hist->Write();
  }

}

// ignore variations to get dataset name
std::string getBase(const std::string & sampleName)
{
  if(sampleName.compare("gg_R2F2") == 0 ) return "gg";
  if(sampleName.compare("gg_R0p5F0p5") == 0 ) return "gg";
  return sampleName;
}
