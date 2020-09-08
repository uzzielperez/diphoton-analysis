#include "diphoton-analysis/FakeRateAnalysis/DiphotonClosureTest/scripts/diphoton_looper.C"

#include <iostream>

int main(int argc, char *argv[])
{
  std::string samples, run;

  if(argc!=3) {
    std::cout << "Syntax: closure_test.exe [2016/2017/2018] [QCD/GJets/GGJets/all]" << std::endl;
    return -1;
  }
  else {
    run = argv[1];
    if(run.find("2016") != std::string::npos
       and run.find("2017") != std::string::npos
       and run.find("2018") != std::string::npos) {
      std::cout << "Only '2016', '2017', and '2018' are allowed years." << std::endl;
      return -1;
    }
    samples = argv[2];
    if(samples.compare("QCD") != 0 
       and samples.compare("GJets") != 0
       and samples.compare("GGJets") != 0
       and samples.compare("QCD") != 0
       and samples.compare("all") != 0) {
      std::cout << "Only 'QCD', 'GJets', 'GGJets' and 'all' are allowed samples. " << std::endl;
      return -1;
    }
  }

  diphoton_looper(run, samples);

  return 0;
}
