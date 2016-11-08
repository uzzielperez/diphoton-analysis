#include "TH1D.h"
#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <iostream>
#include <vector>

TH1D * getHist(TChain * ch, TString histName, int nBins, double min, double max, double weight, TString cut);

TString filestring(TString sample)
{
  TString output(Form("/afs/cern.ch/user/c/cawest/links/%s/*root", sample.Data()));
  
  return output;
}

TChain* getChain()
{
  TChain *ch = new TChain("diphoton/fSherpaGenTree");
  ch->Add(filestring("GGJets_M-60To200_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-200To500_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-500To1000_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-1000To2000_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-2000To4000_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-4000To6000_Pt-50_13TeV-sherpa"));
  ch->Add(filestring("GGJets_M-6000To8000_Pt-50_13TeV-sherpa"));

  std::cout << "Events: " << ch->GetEntries() << std::endl;

  return ch;
}

int main()
{
  std::map<TString, TString> cuts, cutsNoIso;
  cuts["BB"] = ("SherpaGenPhoton1.pt>75 && SherpaGenPhoton2.pt>75 && abs(SherpaGenPhoton1.eta)<1.4442 && abs(SherpaGenPhoton2.eta)<1.4442 && SherpaGenDiphoton.Minv>230 && SherpaGenDiphoton.Minv<2000 && SherpaGenPhoton1_iso<5 && SherpaGenPhoton2_iso<5");
  cuts["BE"] = ("SherpaGenPhoton1.pt>75 && SherpaGenPhoton2.pt>75 && !(abs(SherpaGenPhoton1.eta)<1.4442 && abs(SherpaGenPhoton2.eta)<1.4442) && ((abs(SherpaGenPhoton1.eta)<1.4442 && (abs(SherpaGenPhoton2.eta)>1.56 && abs(SherpaGenPhoton2.eta)<2.5)) || (abs(SherpaGenPhoton2.eta)<1.4442 && (abs(SherpaGenPhoton1.eta)>1.56 && abs(SherpaGenPhoton1.eta)<2.5))) && SherpaGenDiphoton.Minv>320 && SherpaGenDiphoton.Minv<2000 && SherpaGenPhoton1_iso<5 && SherpaGenPhoton2_iso<5");
  cutsNoIso["BB"] = ("SherpaGenPhoton1.pt>75 && SherpaGenPhoton2.pt>75 && abs(SherpaGenPhoton1.eta)<1.4442 && abs(SherpaGenPhoton2.eta)<1.4442 && SherpaGenDiphoton.Minv>230");
  cutsNoIso["BE"] = ("SherpaGenPhoton1.pt>75 && SherpaGenPhoton2.pt>75 && !(abs(SherpaGenPhoton1.eta)<1.4442 && abs(SherpaGenPhoton2.eta)<1.4442) && ((abs(SherpaGenPhoton1.eta)<1.4442 && (abs(SherpaGenPhoton2.eta)>1.56 && abs(SherpaGenPhoton2.eta)<2.5)) || (abs(SherpaGenPhoton2.eta)<1.4442 && (abs(SherpaGenPhoton1.eta)>1.56 && abs(SherpaGenPhoton1.eta)<2.5))) && SherpaGenDiphoton.Minv>320 && SherpaGenDiphoton.Minv<2000");
  double lumi=0.001; // weights gives yield per fb^-1; we want yield per pb^-1

  TChain *ch = getChain();

  std::vector<TString> regions = {"BB", "BE"};

  TFile *outFile = new TFile("data/sherpa.root", "recreate");

  for(auto iregion : regions) {
    outFile->mkdir(iregion);
    outFile->cd(iregion);

    std::vector<TH1D*> hists;
    hists.push_back(getHist(ch, "hist1", 100, 0, 2000, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist2", 100, 0, 2000, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist3", 100, 0, 2000, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist4", 100, 0, 2000, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist5", 72, -3.15, 3.15, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist6", 72, -3.15, 3.15 , lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist7", 72, 0, 3.15, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist8", 50, -2.5, 2.5, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist9", 50, -2.5, 2.5, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist10", 100, -5, 5, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist11", 20, 0, 1, lumi, cuts[iregion]));
    hists.push_back(getHist(ch, "hist12", 100, 0, 500, lumi, cutsNoIso[iregion]));
    hists.push_back(getHist(ch, "hist13", 100, 0, 500, lumi, cutsNoIso[iregion]));

    for( auto ihist : hists) {
      ihist->Write();
    }
    std::cout << "Cross section: " << hists.at(0)->Integral() << std::endl;
  }
  
  outFile->Close();

}

TString getVariableByHistName(TString histName)
{
  if(histName.EqualTo("hist1")) return "SherpaGenDiphoton.Minv";
  if(histName.EqualTo("hist2")) return "SherpaGenPhoton1.pt";
  if(histName.EqualTo("hist3")) return "SherpaGenPhoton2.pt";
  if(histName.EqualTo("hist4")) return "SherpaGenDiphoton.qt";
  if(histName.EqualTo("hist5")) return "SherpaGenPhoton1.phi";
  if(histName.EqualTo("hist6")) return "SherpaGenPhoton2.phi";
  if(histName.EqualTo("hist7")) return "abs(SherpaGenDiphoton.deltaPhi)";
  if(histName.EqualTo("hist8")) return "SherpaGenPhoton1.eta";
  if(histName.EqualTo("hist9")) return "SherpaGenPhoton2.eta";
  if(histName.EqualTo("hist10")) return "SherpaGenDiphoton.deltaEta";
  if(histName.EqualTo("hist11")) return "abs(SherpaGenDiphoton.cosThetaStar)";
  if(histName.EqualTo("hist12")) return "SherpaGenPhoton1_iso";
  if(histName.EqualTo("hist13")) return "SherpaGenPhoton2_iso";



  // should never get here!
  return "";
}

TH1D * getHist(TChain *ch, TString histName, int nBins, double min, double max, double weight, TString cut)
{
  std::cout << weight << std::endl;

  TH1D *h = new TH1D(histName, histName, nBins, min, max);

  TString drawString(Form("%s>>%s", getVariableByHistName(histName).Data(), histName.Data()));
  TString normString(Form("(%6.6e*weightAll)*(%s)", weight, cut.Data()));
  std::cout << drawString << std::endl;
  std::cout << normString << std::endl;
  ch->Draw(drawString, normString);

  h->SetTitle(";M_{#gamma#gamma, RECO};Events / 20 GeV");
  h->SetLineStyle(kSolid);
  std::cout << h->Integral() << std::endl;
  return h;
}
