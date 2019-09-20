#include "TChain.h"
#include "TFile.h"
#include "TTree.h"

#include <iostream>

int main(int argc, char *argv[])
{
  TString input, output;

  if(argc!=3) {
    std::cout << "Syntax: skim.exe [input_directory] [output_file]" << std::endl;
    return -1;
  }
  else {
    input = argv[1];
    output = argv[2];
  }

  TString selection;
  if(input.Contains("Run2015") || input.Contains("Run2016")) selection = "HLT_DoublePhoton60 || HLT_ECALHT800";
  else if(input.Contains("Run2017") || input.Contains("Run2018")) selection = "HLT_DoublePhoton70 && Minv<1000";
  else {
    std::cout << "Could not determine year from input filename." << std::endl;
    return -1;
  }

  TChain * chain = new TChain("diphoton/fTree");
  chain->Add(input + "/*.root");
  
  TFile *outFile = new TFile(output, "recreate");
  outFile->mkdir("diphoton");
  outFile->cd("diphoton");
  TTree *outTree = chain->CopyTree(selection);

  outTree->Write();
  outFile->Write();

  return 0;
}
