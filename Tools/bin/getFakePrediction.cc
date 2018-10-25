#include "diphoton-analysis/Tools/interface/fakePrediction.C"
#include "diphoton-analysis/Tools/interface/sampleList.hh"

#include <iostream>

#include "TChain.h"

int main(int argc, char *argv[])
{
  std::string source;

  int year = 0;
  if(argc!=2) {
    std::cout << "Syntax: getFakeRatePrediction.exe [data_2017/data_2018/mc]" << std::endl;
    return -1;
  }
  else {
    source = argv[1];
    //    if(source!="mc" and source!="data") {
    if(source!="mc" and source!="data_2017" and source!="data_2018") {
      std::cout << "Only 'data_2017', 'data_2018' and 'mc' are allowed input parameters. " << std::endl;
      return -1;
    }
  }
  if(source=="data_2017") year = 2017;
  if(source=="data_2018") year = 2018;
  
  init();
  TChain *ch = chains[source];
  fakePrediction f(ch);

  if(source=="mc") f.setIsMC(true);
  else f.setIsMC(false);

  f.Loop(year);

  return 0;
}
