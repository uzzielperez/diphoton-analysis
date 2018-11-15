#define fakePrediction_cxx
#include "fakePrediction.h"
#include "TF1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iostream>

#include "diphoton-analysis/Tools/interface/tdrstyle.hh"

const double etaMaxBarrel = 1.4442;
const double etaMinEndcap = 1.56;
const double etaMaxEndcap = 2.5;
const double minvMin = 500;

void fakePrediction::Loop(int year, const std::string &dataset)
{
  std::map<int, double> ptCuts;
  //  ptCuts[2016] = 75.;
  ptCuts[2016] = 125.;
  ptCuts[2017] = 125.;
  ptCuts[2018] = 125.;
  const double ptMin = ptCuts[year];
  const double hadronicOverEmCut = 0.1;

  enum diphotonEventTypes { BB = 0, BE = 1};
  enum ecalRegions { EB = 0, EE = 1};
  const std::vector<std::string> regions = {"BB", "BE"};

  // define binning for input to datacard
  int nbins=40;
  double xmin=0.0;
  double xmax=2000.0;

  setTDRStyle();
  gROOT->ForceStyle();

  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }
  const std::string cmssw_base_string(cmssw_base);

  std::string yearString(std::to_string(year));
  // until 2018 fake rate is sensible
  if(year==2018 && dataset=="jetht") yearString="2017";
  //  std::string inputFile("fakeRateFunctions_" + std::to_string(year) + "_" + dataset +  ".root");
  std::string inputFile("fakeRateFunctions_" + yearString + "_" + dataset +  ".root");
  if(isMC) inputFile = "fakeRateFunctions_mc.root";

  TFile *fakeRateFile = TFile::Open(Form("%s/src/diphoton-analysis/Tools/data/%s",
					 cmssw_base_string.c_str(), inputFile.c_str()));
  TF1 * fakeRate[2];
  
  fakeRateFile->GetObject("fakeRateEB_chIso5To10_fit", fakeRate[EB]);
  fakeRateFile->GetObject("fakeRateEE_chIso5To10_fit", fakeRate[EE]);
  std::cout << "Using barrel fake rate: " << std::endl;
  fakeRate[EB]->Print("v");
  std::cout << "Using endcap fake rate: " << std::endl;
  fakeRate[EE]->Print("v");
  const std::string outputFile("data/fakes_" + std::to_string(year) + "_" + dataset + ".root");
  TFile *output = new TFile(outputFile.c_str(), "recreate");
  output->mkdir("BB");
  output->mkdir("BE");


  TH1D *good[2], *TT[2], *FT[2], *TF[2], *FF[2];
  for(unsigned int region=0; region<regions.size(); region++) {
    good[region] = new TH1D((regions[region] + "good").c_str(), (regions[region] + "good").c_str(), nbins, xmin, xmax);
    TT[region] = new TH1D((regions[region] + "TT").c_str(), (regions[region] + "TT").c_str(), nbins, xmin, xmax);
    FT[region] = new TH1D((regions[region] + "FT").c_str(), (regions[region] + "FT").c_str(), nbins, xmin, xmax);
    TF[region] = new TH1D((regions[region] + "TF").c_str(), (regions[region] + "TF").c_str(), nbins, xmin, xmax);
    FF[region] = new TH1D((regions[region] + "FF").c_str(), (regions[region] + "FF").c_str(), nbins, xmin, xmax);
  }

  if (fChain == 0) return;


   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     if(jentry%10000==0) std::cout << "Processing entry " << jentry << " of " << nentries << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      double weight = 1.0;
      bool triggered = false;
      if(isMC) weight = Event_weightAll;
      else {
#ifdef ntupleAnalyzerBase2016_h
	triggered = TriggerBit_HLT_DoublePhoton60;
#else
	triggered = TriggerBit_HLT_DoublePhoton70;
#endif
      }
      if(!triggered) continue;

      // highest pT photons
      if(isGood) {
	if(Photon1_pt > ptMin && Photon2_pt > ptMin && Diphoton_Minv > minvMin) {
	  if(isBarrelBarrel(Photon1_eta, Photon2_eta)) good[BB]->Fill(Diphoton_Minv, weight);
	  else if (isBarrelEndcap(Photon1_eta, Photon2_eta)) good[BE]->Fill(Diphoton_Minv, weight);
	}
      }
      // true, true
      if(isTT) {
	if(TTPhoton1_pt > ptMin && TTPhoton2_pt > ptMin && TTDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(TTPhoton1_eta, TTPhoton2_eta)) TT[BB]->Fill(TTDiphoton_Minv, weight);
	  else if (isBarrelEndcap(TTPhoton1_eta, TTPhoton2_eta)) TT[BE]->Fill(TTDiphoton_Minv, weight);
	}
      }
      // true, fake
      if(isTF) {
	bool pass = (TFPhoton2_isEB || (TFPhoton2_isEE && TFPhoton2_passCorPhoIso)) && TFPhoton2_hadronicOverEm < hadronicOverEmCut
	  && TFPhoton1_r9_5x5 > 0.8 && TFPhoton2_r9_5x5 > 0.8;
	if(pass && TFPhoton1_pt > ptMin && TFPhoton2_pt > ptMin && TFDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(TFPhoton1_eta, TFPhoton2_eta)) TF[BB]->Fill(TFDiphoton_Minv, weight*fakeRate[EB]->Eval(TFPhoton2_pt));
	  else if (isBarrelEndcap(TFPhoton1_eta, TFPhoton2_eta)) {
	    int region = TFPhoton2_isEB ? EB : EE;
	    TF[BE]->Fill(TFDiphoton_Minv, weight*fakeRate[region]->Eval(TFPhoton2_pt));
	  }
	}
      }
      // fake, true
      if(isFT) {
	bool pass = (FTPhoton1_isEB || (FTPhoton1_isEE && FTPhoton1_passCorPhoIso)) && FTPhoton1_hadronicOverEm < hadronicOverEmCut
	  && FTPhoton1_r9_5x5 > 0.8 && FTPhoton2_r9_5x5 > 0.8;
	if(pass && FTPhoton1_pt > ptMin && FTPhoton2_pt > ptMin && FTDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(FTPhoton1_eta, FTPhoton2_eta)) FT[BB]->Fill(FTDiphoton_Minv, weight*fakeRate[EB]->Eval(FTPhoton1_pt));
	  else if (isBarrelEndcap(FTPhoton1_eta, FTPhoton2_eta)) {
	    int region = FTPhoton1_isEB ? EB : EE;
	    FT[BE]->Fill(FTDiphoton_Minv, weight*fakeRate[region]->Eval(FTPhoton1_pt));
	  }
	}
      }
      // fake, fake
      if(isFF) {
	bool pass = (FFPhoton1_isEB || (FFPhoton1_isEE && FFPhoton1_passCorPhoIso)) && (FFPhoton2_isEB || (FFPhoton2_isEE && FFPhoton2_passCorPhoIso))
	  && FFPhoton1_hadronicOverEm < hadronicOverEmCut && FFPhoton2_hadronicOverEm < hadronicOverEmCut
	  && FFPhoton1_r9_5x5 > 0.8 && FFPhoton2_r9_5x5 > 0.8;
	if(pass && FFPhoton1_pt > ptMin && FFPhoton2_pt > ptMin && FFDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(FFPhoton1_eta, FFPhoton2_eta)) FF[BB]->Fill(FFDiphoton_Minv, weight*fakeRate[EB]->Eval(FFPhoton1_pt)*fakeRate[EB]->Eval(FFPhoton2_pt));
	  else if (isBarrelEndcap(FFPhoton1_eta, FFPhoton2_eta)) {
	    int region1 = FFPhoton1_isEB ? EB : EE;
	    int region2 = FFPhoton2_isEB ? EB : EE;
	    FF[BE]->Fill(FFDiphoton_Minv, weight*fakeRate[region1]->Eval(FFPhoton1_pt)*fakeRate[region2]->Eval(FFPhoton2_pt));
	  }
	}
      }
   }

   // barrel, barrel fakes sum
   TH1D *sum[2];
   sum[BB] = static_cast<TH1D*>(TF[BB]->Clone("gjDataDrivenBB"));
   sum[BB]->Add(FT[BB]);
   sum[BB]->Add(FF[BB]);
   // barrel, endcap fakes sum
   sum[BE] = static_cast<TH1D*>(TF[BE]->Clone("gjDataDrivenBE"));
   sum[BE]->Add(FT[BE]);
   sum[BE]->Add(FF[BE]);

   std::cout << "Writing histograms." << std::endl;
   
   for(unsigned int i = 0; i < regions.size(); i++) {
     output->cd(regions[i].c_str());
     std::cout << "Changed directory to " << gDirectory->GetName() << std::endl;
     good[i]->Write();
     TT[i]->Write();
     TF[i]->Write();
     FT[i]->Write();
     FF[i]->Write();
     sum[i]->Write();
   }
   std::cout << "Closing output file." << std::endl;

   output->Close();
}

bool fakePrediction::isBarrelBarrel(double eta1, double eta2)
{
  return (fabs(eta1) < etaMaxBarrel && fabs(eta2) < etaMaxBarrel);

}

bool fakePrediction::isBarrelEndcap(double eta1, double eta2)
{
  return ((fabs(eta1) < etaMaxBarrel && (fabs(eta2) > etaMinEndcap && fabs(eta2) < etaMaxEndcap)) ||
	  ((fabs(eta2) < etaMaxBarrel && (fabs(eta1) > etaMinEndcap && fabs(eta1) < etaMaxEndcap))));

}

