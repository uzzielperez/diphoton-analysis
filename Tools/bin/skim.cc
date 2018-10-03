#include "TChain.h"
#include "TFile.h"
#include "TTree.h"

#include <iostream>

int main(int argc, char *argv[])
{
  const TString selection("HLT_DoublePhoton70");
  TString input, output;

  if(argc!=3) {
    std::cout << "Syntax: skim.exe [input_directory] [output_file]" << std::endl;
    return -1;
  }
  else {
    input = argv[1];
    output = argv[2];
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
