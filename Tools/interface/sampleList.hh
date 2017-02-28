// This file defines the samples that are used, the chains that specify their
// locations and basic formatting for the samples.
// It can be used by including the header and then calling
// init()
// to initialize the chains.
#ifndef SAMPLELIST_HH
#define SAMPLELIST_HH

#include "TChain.h"
#include "TSystem.h"

#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include <linux/limits.h>

#include "diphoton-analysis/Tools/interface/tdrstyle.hh"


double luminosity = 2.62; // fb^-1
const double luminosity2016 = 35.9; // fb^-1
const double luminosityRatio = 35.9/2.62;
const double luminosityError = 0.023;
const double luminosity2016Error = 0.026;

std::map<std::string, TChain*> chains;
std::map<std::string, int> lineStyles;
std::map<std::string, int> lineColors;
std::map<std::string, int> fillStyles;
std::map<std::string, int> fillColors;
std::map<std::string, std::string> prettyName;

TString filestring(TString sample);
void init(); // initializes samples
void initADD(); // initializes ADD samples; performed by a loop rather than being listed explicitly
void listSamples(); // list the available samples

TString filestring(TString sample)
{
  // paths are defined as symbolic links here
  TString directory(Form("/afs/cern.ch/user/c/cawest/links/%s", sample.Data()));
  char resolved_path[PATH_MAX];

  // resolve the symbolic link
  ssize_t r = readlink(directory.Data(), resolved_path, PATH_MAX);
  // if it fails, try filename directly
  if(r==-1) {
    return Form("%s/*.root", directory.Data());
  }
  // if we were successful, convert symbolic link to xrootd path
  else {
    // have to null terminate manually
    resolved_path[r] = '\0';

    // convert AFS path to xrootd path
    TString mypath(resolved_path);
    mypath.ReplaceAll("/afs/cern.ch/user/c/cawest/eos/cms", "root://eoscms.cern.ch/");
    mypath += "/*.root";
    return mypath;
  }
}

void listSamples()
{
  for( auto ichain : chains) {
    std::cout << ichain.first << std::endl;
  }
}

std::vector<std::string> getSampleList()
{
  std::vector<std::string> list;

  for( auto ichain : chains) {
    list.push_back(ichain.first);
  }

  return list;
}

void init()
{
  TString treeType("diphoton/fTree");

  TChain *chData = new TChain(treeType);
  chData->Add(filestring("DoubleEG__Run2015D"));
  chData->Add(filestring("DoubleEG__Run2015C_25ns"));
  TChain *chData2016_preREMINIAOD = new TChain(treeType);
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016B"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016C"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016D"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016E"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016F"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016G"));
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016H"));
  // // both -v2 and -v3 should be included
  // chData2016_preREMINIAOD->Add(filestring("DoubleEG__Run2016H-PromptReco-v2"));
  TChain *chData2016 = new TChain(treeType);
  chData2016->Add(filestring("DoubleEG__Run2016B-03Feb2017"));
  chData2016->Add(filestring("DoubleEG__Run2016C-03Feb2017"));
  chData2016->Add(filestring("DoubleEG__Run2016D-03Feb2017"));
  chData2016->Add(filestring("DoubleEG__Run2016E-03Feb2017"));
  chData2016->Add(filestring("DoubleEG__Run2016F-03Feb2017"));
  chData2016->Add(filestring("DoubleEG__Run2016G-03Feb2017"));
  // both _ver2 and _ver3 should be included, corresponding to -v2 and -v3
  // of the PromptReco
  chData2016->Add(filestring("DoubleEG__Run2016H-03Feb2017_ver2"));
  chData2016->Add(filestring("DoubleEG__Run2016H-03Feb2017_ver3"));
  TChain *chGG = new TChain(treeType);
  chGG->Add(filestring("GGJets_M-60To200_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-200To500_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-500To1000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-1000To2000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-2000To4000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-4000To6000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-6000To8000_Pt-50_13TeV-sherpa"));
  TChain *chGG_aMC_2015 = new TChain(treeType);
  chGG_aMC_2015->Add(filestring("DiPhotonJets_MGG-80toInf_2015"));
  TChain *chGG_2016 = new TChain(treeType);
  chGG_2016->Add(filestring("DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa"));
  TChain *chGJ = new TChain(treeType);
  chGJ->Add(filestring("GJets_HT-40To100"));
  chGJ->Add(filestring("GJets_HT-100To200"));
  chGJ->Add(filestring("GJets_HT-200To400"));
  chGJ->Add(filestring("GJets_HT-400To600"));
  chGJ->Add(filestring("GJets_HT-600ToInf"));
  TChain *chJJ = new TChain(treeType);
  chJJ->Add(filestring("QCD_Pt-20to30_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-30to50_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-50to80_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-80to120_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-120to170_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-170to300_EMEnriched"));
  chJJ->Add(filestring("QCD_Pt-300toInf_EMEnriched"));
  TChain *chVG = new TChain(treeType);
  chVG->Add(filestring("WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  chVG->Add(filestring("ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  TChain *chW = new TChain(treeType);
  // The following samples have a bug and should be excluded.
  // Should switch to a different W sample.
  //  chW->Add(filestring("WToLNu_0J_13TeV-amcatnloFXFX"));
  //  chW->Add(filestring("WToLNu_1J_13TeV-amcatnloFXFX"));
  chW->Add(filestring("WToLNu_2J_13TeV-amcatnloFXFX"));
  TChain *chDY = new TChain(treeType);
  chDY->Add(filestring("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  TChain *chTTG = new TChain(treeType);
  chTTG->Add(filestring("TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  // sum of minor backgrounds for use in limit setting
  TChain *chOther = new TChain(treeType);
  chOther->Add(chVG);
  chOther->Add(chW);
  chOther->Add(chDY);
  chOther->Add(chTTG);
  TChain *chGGGen = new TChain("diphoton/fSherpaGenTree");
  chGGGen->Add(filestring("GGJets_M-60To200_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-200To500_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-500To1000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-1000To2000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-2000To4000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-4000To6000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-6000To8000_Pt-50_13TeV-sherpa"));
  // These samples are defined in the same way as the SM background in the signal samples.
  // They are needed to take into account interference of the signal with SM backgrounds.
  TChain *chGG70 = new TChain(treeType);
  chGG70->Add(filestring("GG_M-200To500_Pt-70_13TeV-sherpa"));
  chGG70->Add(filestring("GG_M-500To1000_Pt-70_13TeV-sherpa"));
  chGG70->Add(filestring("GG_M-1000To2000_Pt-70_13TeV-sherpa"));
  chGG70->Add(filestring("GG_M-2000To4000_Pt-70_13TeV-sherpa"));
  chGG70->Add(filestring("GG_M-4000To8000_Pt-70_13TeV-sherpa"));
  chGG70->Add(filestring("GG_M-8000To13000_Pt-70_13TeV-sherpa"));

  std::vector<std::string> sampleNames = {"data", "gg", "gj", "jj", "vg", "w", "dy", "ttg", "gg70"};

  chains["data_2015"] = chData;
  chains["data_2016"] = chData2016;
  chains["data_2016_preREMINIAOD"] = chData2016_preREMINIAOD;
  chains["gg"] = chGG;
  chains["gg_aMC_2015"] = chGG_aMC_2015;
  chains["gg_2016"] = chGG_2016;
  chains["ggGen"] = chGGGen;
  chains["gj"] = chGJ;
  chains["jj"] = chJJ;
  chains["vg"] = chVG;
  chains["w"] = chW;
  chains["dy"] = chDY;
  chains["ttg"] = chTTG;
  chains["gg70"] = chGG70;
  chains["other"] = chOther;

  // ADD initialization done separately to avoid clutter
  initADD();

  // set default styles
  for( auto isample : sampleNames ) {
    lineColors[isample] = kBlack;
    fillStyles[isample] = 1001;
    lineStyles[isample] = kSolid;
  }

  fillColors["data"]=kWhite;
  fillColors["data_2016"]=kWhite;
  fillColors["data_2016_preREMINIAOD"]=kWhite;
  fillColors["gg"]=kCyan;
  fillColors["gg_2016"]=kCyan;
  fillColors["gg_aMC_2015"]=kCyan;
  fillColors["gj"]=kBlue;
  fillColors["jj"]=kSpring;
  fillColors["vg"]=kOrange;
  fillColors["w"]=kBlack;
  fillColors["dy"]=kYellow;
  fillColors["ttg"]=kMagenta;
  fillColors["gg70"]=kCyan;

  prettyName["data_2015"]="Data (2015)";
  prettyName["data_2016"]="Data (2016)";
  prettyName["data_2016_preREMINIAOD"]="Data (2016, pre-reMINIAOD)";
  prettyName["gg"]="#gamma#gamma";
  prettyName["gg_2016"]="#gamma#gamma (2016)";
  prettyName["gg_aMC_2015"]="#gamma#gamma (aMC@NLO)";
  prettyName["gj"]="#gamma + jets";
  prettyName["jj"]="Multijet";
  prettyName["vg"]="V#gamma";
  prettyName["w"]="W";
  prettyName["dy"]="DY";
  prettyName["ttg"]="t#bar{t}#gamma";
  prettyName["gg70"]="Diphoton, p_{T,#gamma} > 70";

  setTDRStyle();
}

void initADD()
{
  // ADD samples
  std::vector<std::string> MS = {"3000", "3500", "4000", "4500",
				 "5000", "5500", "6000"};
  std::vector<std::string> NED = {"2", "4"};
  std::vector<std::string> KK = {"1", "4"};
  std::map<std::string, std::vector<std::string>> MggBins;
  // the 250To500 mass bin is only present for the NED=4, KK=1 sample
  // but it is skipped manually later
  MggBins["3000"] = {"250To500", "500To1000", "1000To2000", "2000To3000"};
  MggBins["3500"] = {"250To500", "500To1000", "1000To2000", "2000To3500"};
  MggBins["4000"] = {"250To500", "500To1000", "1000To2000", "2000To4000"};
  MggBins["4500"] = {"250To500", "500To1000", "1000To2000", "2000To3000", "3000To4500"};
  MggBins["5000"] = {"250To500", "500To1000", "1000To2000", "2000To3000", "3000To5000"};
  MggBins["5500"] = {"250To500", "500To1000", "1000To2000", "2000To4000", "4000To5500"};
  MggBins["6000"] = {"250To500", "500To1000", "1000To2000", "2000To4000", "4000To6000"};

  for(const auto iMS : MS) {
    for(const auto iNED : NED) {
      for(const auto iKK : KK) {
	// no samples were generated with KK convention 4
	// and four extra dimensions
	if(strcmp(iKK.c_str(), "4")==0 && strcmp(iNED.c_str(), "4")==0) continue;
	std::string pointName = "ADDGravToGG_MS-";
	pointName += iMS;
	pointName += "_NED-";
	pointName += iNED;
	pointName += "_KK-";
	pointName += iKK;
	chains[pointName] = new TChain("diphoton/fTree");
	for(std::string iMgg : MggBins[iMS] ) {
	  // the 200To500 bins are only present for the NED=4 samples
	  if(strcmp(iNED.c_str(), "2")==0 && strcmp(iMgg.c_str(), "250To500")==0) continue;
	  std::string sampleName(pointName);
	  sampleName += "_M-";
	  sampleName += iMgg;
	  sampleName += "_13TeV-sherpa";
	  chains[pointName]->Add(filestring(sampleName));
	  lineColors[pointName] = kBlack;
	  fillStyles[pointName] = 1001;
	  lineStyles[pointName] = kSolid;
	}
      }
    }
  }

}

#endif
