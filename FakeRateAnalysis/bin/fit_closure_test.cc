#include "diphoton-analysis/FakeRateAnalysis/ClosureTestTemplateFits/fit_closure_test.C"

#include <iostream>

int main(int argc, char *argv[])
{
  TString sample;
  TString templateVariable;
  TString era;
  int pvCutLow = 0;
  int pvCutHigh = 2000;

  if(argc<3) {
    std::cout << "Syntax: fit_closure_test.exe [2015/2016/2017/2018] [GGJets/GJets] [PV_low] [PV_high]" << std::endl;
    return -1;
  }
  else {
    sample = argv[1];
    if (sample != "GJets" && sample != "GGJets" && sample !="GGJets") {
      std::cout << "Choose sample: GJets, GGJets\n" << std::endl;
      return -1;
    }

    templateVariable = argv[2];
    if (templateVariable != "sieie" && templateVariable != "chIso") {
      std::cout << "Choose template variable: sieie or chIso\n" << std::endl;
      return -1;
    }
    std::cout << "Using template variable: " << templateVariable << std::endl;

    era = argv[3];
    if (!era.Contains("2015") && !era.Contains("2016") && !era.Contains("2017") && !era.Contains("2018")) {
      std::cout << "Only years 2015, 2016, 2017 and 2018 are supported" << std::endl;
      return -1;
    }
    if(argc>3) pvCutLow = std::atoi(argv[4]);
    if(argc>4) pvCutHigh = std::atoi(argv[5]);
  }

  // Input file

  // TString input_filename = TString::Format("GGJets_fakerate_2018_pV%d-%d_newDenomDef.root", pvCutLow, pvCutHigh);
  // std::cout << "Processing: " << input_filename << std::endl;

  // Run Template fitting here
  fit_closure_test(era, templateVariable, sample, pvCutLow, pvCutHigh);

  return 0;
}
