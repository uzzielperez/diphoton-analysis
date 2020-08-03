#include "diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/scripts/diphoton_chain_looper.C"

#include <iostream>

int main(int argc, char *argv[])
{
  int nPVLow, nPVHigh;
  std::string samples, variable, run;

  if(argc!=5) {
    std::cout << "Syntax: fake_templates_closure.exe [2016/2017/2018] [GJets/GGJets] [PV_low] [PV_high]" << std::endl;
    return -1;
  }
  else {
    run = argv[1];
    if(run.find("2016") != std::string::npos
       and run.find("2017") != std::string::npos
       and run.find("2018") != std::string::npos) {
      std::cout << "Only 2016', '2017', and '2018' are allowed years." << std::endl;
      return -1;
    }
    samples = argv[2];
    if(samples.compare("GJets") != 0 and samples.compare("GGJets") != 0) {
      std::cout << "Only 'GJets' and 'GGJets' are allowed samples. " << std::endl;
      return -1;
    }
    nPVLow = std::atoi(argv[3]);
    nPVHigh = std::atoi(argv[4]);
  }

  diphoton_chain_looper(run, samples, nPVLow, nPVHigh);

  return 0;
}
