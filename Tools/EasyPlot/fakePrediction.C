#define fakePrediction_cxx
#include "fakePrediction.h"
#include "TF1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>

#include <iostream>

#include "easyplot.hh"

const double etaMaxBarrel = 1.4442;
const double etaMinEndcap = 1.56;
const double etaMaxEndcap = 2.5;
const double ptMin = 75.0;

void fakePrediction::Loop(bool isMC=false)
{
  enum diphotonEventTypes { BB = 0, BE = 1};
  enum ecalRegions { EB = 0, EE = 1};
  const TString regions[2] = {"BB", "BE"};

  // define binning for input to datacard
  int nbins=120;
  double xmin=0.0;
  double xmax=6000.0;

  setTDRStyle();
  gROOT->ForceStyle();

  std::string inputFile("fakeRateFunctions_jetht.root");
  if(isMC) inputFile = "fakeRateFunctions_mc.root";
  
  TFile *fakeRateFile = TFile::Open(Form("../../FakeRateAnalysis/RooFitTemplateFitting/analysis/%s", inputFile.c_str()));
  TF1 * fakeRate[2];
  
  fakeRateFile->GetObject("fakeRateEB_chIso5To10_fit", fakeRate[EB]);
  fakeRateFile->GetObject("fakeRateEE_chIso5To10_fit", fakeRate[EE]);
  std::cout << "Using barrel fake rate: " << std::endl;
  fakeRate[EB]->Print("v");
  std::cout << "Using endcap fake rate: " << std::endl;
  fakeRate[EE]->Print("v");
  TFile *output = new TFile("data/fakes.root", "recreate");
  output->mkdir("BB");
  output->mkdir("BE");


  TH1D *good[2], *TT[2], *FT[2], *TF[2], *FF[2];
  for(int iregion=0; iregion<2; iregion++) {
    good[iregion] = new TH1D(regions[iregion] + "good", regions[iregion] + "good", nbins, xmin, xmax);
    TT[iregion] = new TH1D(regions[iregion] + "TT", regions[iregion] + "TT", nbins, xmin, xmax);
    FT[iregion] = new TH1D(regions[iregion] + "FT", regions[iregion] + "FT", nbins, xmin, xmax);
    TF[iregion] = new TH1D(regions[iregion] + "TF", regions[iregion] + "TF", nbins, xmin, xmax);
    FF[iregion] = new TH1D(regions[iregion] + "FF", regions[iregion] + "FF", nbins, xmin, xmax);
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
      if(isMC) weight = Event_weightAll;

      // highest pT photons
      if(isGood) {
	if(Photon1_pt > ptMin && Photon2_pt > ptMin) {
	  if(isBarrelBarrel(Photon1_eta, Photon2_eta)) good[BB]->Fill(Diphoton_Minv, weight);
	  else if (isBarrelEndcap(Photon1_eta, Photon2_eta)) good[BE]->Fill(Diphoton_Minv, weight);
	}
      }
      // true, true
      if(isTT) {
	if(TTPhoton1_pt > ptMin && TTPhoton2_pt > ptMin) {
	  if(isBarrelBarrel(TTPhoton1_eta, TTPhoton2_eta)) TT[BB]->Fill(TTDiphoton_Minv, weight);
	  else if (isBarrelEndcap(TTPhoton1_eta, TTPhoton2_eta)) TT[BE]->Fill(TTDiphoton_Minv, weight);
	}
      }
      // true, fake
      if(isTF) {
	if(TFPhoton1_pt > ptMin && TFPhoton2_pt > ptMin) {
	  if(isBarrelBarrel(TFPhoton1_eta, TFPhoton2_eta)) TF[BB]->Fill(TFDiphoton_Minv, weight*fakeRate[EB]->Eval(TFPhoton2_pt));
	  else if (isBarrelEndcap(TFPhoton1_eta, TFPhoton2_eta)) TF[BE]->Fill(TFDiphoton_Minv, weight*fakeRate[EE]->Eval(TFPhoton2_pt));
	}
      }
      // fake, true
      if(isFT) {
	if(FTPhoton1_pt > ptMin && FTPhoton2_pt > ptMin) {
	  if(isBarrelBarrel(FTPhoton1_eta, FTPhoton2_eta)) FT[BB]->Fill(FTDiphoton_Minv, weight*fakeRate[EB]->Eval(FTPhoton1_pt));
	  else if (isBarrelEndcap(FTPhoton1_eta, FTPhoton2_eta)) FT[BE]->Fill(FTDiphoton_Minv, weight*fakeRate[EE]->Eval(FTPhoton1_pt));
	}
      }
      // fake, fake
      if(isFF) {
	if(FFPhoton1_pt > ptMin && FFPhoton2_pt > ptMin) {
	  if(isBarrelBarrel(FFPhoton1_eta, FFPhoton2_eta)) FF[BB]->Fill(FFDiphoton_Minv, weight*fakeRate[EB]->Eval(FFPhoton1_pt)*fakeRate[EB]->Eval(FFPhoton2_pt));
	  else if (isBarrelEndcap(FFPhoton1_eta, FFPhoton2_eta)) FF[BE]->Fill(FFDiphoton_Minv, weight*fakeRate[EE]->Eval(FFPhoton1_pt)*fakeRate[EE]->Eval(FFPhoton2_pt));
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
   
   for(unsigned int i = 0; i < 2; i++) {
     output->cd(regions[i]);
     good[i]->Write();
     TT[i]->Write();
     TF[i]->Write();
     FT[i]->Write();
     FF[i]->Write();
     sum[i]->Write();
   }
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
