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

#include "tdrstyle.C"


const double luminosity=2.2; // fb^-1

std::map<std::string, TChain*> chains;
std::map<std::string, int> lineStyles;
std::map<std::string, int> lineColors;
std::map<std::string, int> fillStyles;
std::map<std::string, int> fillColors;
std::map<std::string, std::string> prettyName;

TString filestring(TString sample);
void init();
void initADD();
void listSamples();

TString filestring(TString sample)
{
  TString directory(Form("/afs/cern.ch/user/c/cawest/links/%s", sample.Data()));
  char resolved_path[PATH_MAX];

  // resolve the symbolic link
  struct stat sb;
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

void init()
{
  TString treeType("diphoton/fTree");

  TChain *chData = new TChain(treeType);
  //  chData->Add("/afs/cern.ch/user/c/cawest/links/DoubleEG__Run2015D/out_DoubleEG_Run2015D-16Dec2015-v2_numEvent100_126.root");
  chData->Add(filestring("DoubleEG__Run2015D"));
  TChain *chGG = new TChain(treeType);
  chGG->Add(filestring("GGJets_M-60To200_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-200To500_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-500To1000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-1000To2000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-2000To4000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-4000To6000_Pt-50_13TeV-sherpa"));
  chGG->Add(filestring("GGJets_M-6000To8000_Pt-50_13TeV-sherpa"));
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
  chW->Add(filestring("WToLNu_0J_13TeV-amcatnloFXFX"));
  chW->Add(filestring("WToLNu_1J_13TeV-amcatnloFXFX"));
  chW->Add(filestring("WToLNu_2J_13TeV-amcatnloFXFX"));
  TChain *chDY = new TChain(treeType);
  chDY->Add(filestring("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  TChain *chTTG = new TChain(treeType);
  chTTG->Add(filestring("TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX"));
  TChain *chGGGen = new TChain("diphoton/fSherpaGenTree");
  chGGGen->Add(filestring("GGJets_M-60To200_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-200To500_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-500To1000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-1000To2000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-2000To4000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-4000To6000_Pt-50_13TeV-sherpa"));
  chGGGen->Add(filestring("GGJets_M-6000To8000_Pt-50_13TeV-sherpa"));

  std::vector<std::string> sampleNames = {"data", "gg", "gj", "jj", "vg", "w", "dy", "ttg"};

  chains["data"] = chData;
  chains["gg"] = chGG;
  chains["ggGen"] = chGGGen;
  chains["gj"] = chGJ;
  chains["jj"] = chJJ;
  chains["vg"] = chVG;
  chains["w"] = chW;
  chains["dy"] = chDY;
  chains["ttg"] = chTTG;

  // ADD initialization done separately to avoid clutter
  initADD();

  // set default styles
  for( auto isample : sampleNames ) {
    lineColors[isample] = kBlack;
    fillStyles[isample] = 1001;
    lineStyles[isample] = kSolid;
  }

  fillColors["data"]=kWhite;
  fillColors["gg"]=kCyan;
  fillColors["gj"]=kBlue;
  fillColors["jj"]=kSpring;
  fillColors["vg"]=kOrange;
  fillColors["w"]=kBlack;
  fillColors["dy"]=kYellow;
  fillColors["ttg"]=kMagenta;

  prettyName["data"]="Data";
  prettyName["gg"]="Diphoton";
  prettyName["gj"]="#gamma + jets";
  prettyName["jj"]="Multijet";
  prettyName["vg"]="V#gamma";
  prettyName["w"]="W";
  prettyName["dy"]="DY";
  prettyName["ttg"]="t#bar{t}#gamma";

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
  MggBins["3000"] = {"500To1000", "1000To2000", "2000To3000"};
  MggBins["3500"] = {"500To1000", "1000To2000", "2000To3500"};
  MggBins["4000"] = {"500To1000", "1000To2000", "2000To4000"};
  MggBins["4500"] = {"500To1000", "1000To2000", "2000To3000", "3000To4500"};
  MggBins["5000"] = {"500To1000", "1000To2000", "2000To3000", "3000To5000"};
  MggBins["5500"] = {"500To1000", "1000To2000", "2000To4000", "4000To5500"};
  MggBins["6000"] = {"500To1000", "1000To2000", "2000To4000", "4000To6000"};

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
