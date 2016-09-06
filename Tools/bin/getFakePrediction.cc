#include "diphoton-analysis/Tools/interface/fakePrediction.C"
#include "diphoton-analysis/Tools/interface/sampleList.hh"

#include <iostream>

#include "TChain.h"

int main(int argc, char *argv[])
{
  std::string source;

  if(argc!=2) {
    std::cout << "Syntax: getFakeRatePrediction.exe [data/mc]" << std::endl;
    return -1;
  }
  else {
    source = argv[1];
    if(source!="mc" and source!="data") {
      std::cout << "Only 'data' and 'mc' are allowed input parameters. " << std::endl;
      return -1;
    }
  }
  
  init();
  TChain *ch = chains[source];
  fakePrediction f(ch);
  if(source=="mc") f.Loop(true);
  else f.Loop(false);

  return 0;
}
