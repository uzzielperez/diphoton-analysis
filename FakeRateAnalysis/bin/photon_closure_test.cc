#include "diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/scripts/diphoton_looper.C"

#include <iostream>

int main(int argc, char *argv[])
{
  std::string samples, run, fakes;

  if(argc != 4) {
    std::cout << "Syntax: photon_closure_test.exe [2016/2017/2018] [QCD/GJets/GGJets/all] [fakes/truth]" << std::endl;
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
    fakes = argv[3];
    if(fakes.compare("fakes") != 0
       and fakes.compare("truth") != 0) {
      std::cout << "Only 'fakes' and 'truth' are allowed parameters. " << std::endl;
      return -1;
    }
  }
  bool do_fakes = fakes.compare("fakes");
  std::cout << "Doing MC as " << fakes << std::endl;

  diphoton_looper(run, samples, do_fakes);

  return 0;
}
