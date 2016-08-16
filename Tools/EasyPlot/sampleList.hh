#ifndef SAMPLELIST_HH
#define SAMPLELIST_HH

#include "TChain.h"
#include "tdrstyle.C"

#include <string>
#include <map>

const double luminosity=2.2; // fb^-1

std::map<std::string, TChain*> chains;
std::map<std::string, int> lineStyles;
std::map<std::string, int> lineColors;
std::map<std::string, int> fillStyles;
std::map<std::string, int> fillColors;
std::map<std::string, std::string> prettyName;

TString filestring(TString sample)
{
  TString output(Form("/afs/cern.ch/user/c/cawest/links/%s/*root", sample.Data()));

  return output;
}

void init() {
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

  chains["data"] = chData;
  chains["gg"] = chGG;
  chains["gj"] = chGJ;
  chains["jj"] = chJJ;
  chains["vg"] = chVG;
  chains["w"] = chW;
  chains["dy"] = chDY;
  chains["ttg"] = chTTG;

  fillColors["data"]=kWhite;
  fillColors["gg"]=kBlue;
  fillColors["gj"]=kCyan;
  fillColors["jj"]=kSpring;
  fillColors["vg"]=kOrange;
  fillColors["w"]=kBlack;
  fillColors["dy"]=kYellow;
  fillColors["ttg"]=kMagenta;

  lineColors["data"]=kBlack;
  lineColors["gg"]=kBlack;
  lineColors["gj"]=kBlack;
  lineColors["jj"]=kBlack;
  lineColors["vg"]=kBlack;
  lineColors["w"]=kBlack;
  lineColors["dy"]=kBlack;
  lineColors["ttg"]=kBlack;

  fillStyles["data"]=1001;
  fillStyles["gg"]=1001;
  fillStyles["gj"]=1001;
  fillStyles["jj"]=1001;
  fillStyles["vg"]=1001;
  fillStyles["w"]=1001;
  fillStyles["dy"]=1001;
  fillStyles["ttg"]=1001;

  lineStyles["data"]=kSolid;
  lineStyles["gg"]=kSolid;
  lineStyles["gj"]=kSolid;
  lineStyles["jj"]=kSolid;
  lineStyles["vg"]=kSolid;
  lineStyles["w"]=kSolid;
  lineStyles["dy"]=kSolid;
  lineStyles["ttg"]=kSolid;

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
#endif
