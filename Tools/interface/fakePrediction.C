#define fakePrediction_cxx
#include "fakePrediction.h"
#include "TF1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

#include <iostream>

#include "diphoton-analysis/Tools/interface/tdrstyle.hh"

const double etaMaxBarrel = 1.4442;
const double etaMinEndcap = 1.566;
const double etaMaxEndcap = 2.5;
const double minvMin = 500;

void fakePrediction::fakeRateInit(int year, std::string fakeRateType)
{
  const std::string iso("chIso5To10");

  m_fakeRateType = fakeRateType;

  std::vector<std::string> datasets = {"jetht", "doublemuon"};
  std::vector<std::string> regions = {"EB", "EE"};
  std::vector<std::string> pvCuts = {"0-22", "23-27", "28-32", "33-37", "38-200"};
  if(year==2016) pvCuts.push_back("28-200");
  else {
    pvCuts.push_back("28-32");
    pvCuts.push_back("33-37");
    pvCuts.push_back("38-200");
  }

  for(auto region : regions) {
    for(auto dataset : datasets) {
      for(auto pvCut : pvCuts) {
	TFile *f = TFile::Open(Form("../FakeRateAnalysis/RooFitTemplateFitting/analysis/fakeRatePlots_%s_%d_nPV%s.root", dataset.c_str(), year, pvCut.c_str()));
	const TString graphName(Form("fakeRate%s_%s", region.c_str(), iso.c_str()));
	TGraphAsymmErrors *gr = dynamic_cast<TGraphAsymmErrors*>(f->Get(graphName));
	gr->Eval(1000.0);
	std::string keyname(region + "_" + dataset + "_" + pvCut);
	m_fakeRates[keyname] = gr;
      }
    }
  }
}

// type:
// 0 = average of doublemuon and jetht
// 1 = doublemuon
// 2 = jetht
double fakePrediction::getFakeRate(double pt, int region)
{
  std::vector<std::string> regions = {"EB", "EE"};
  std::string pvCut = "";
  if(nPV >= 0 && nPV <= 22) pvCut = "0-22";
  else if(nPV >= 23 && nPV <= 27) pvCut = "23-27";
  else if(nPV >= 28 && nPV <= 32) pvCut = "28-32";
  else if(nPV >= 33 && nPV <= 37) pvCut = "33-37";
  else if(nPV >= 38 && nPV <= 200) pvCut = "38-200";
  else std::cout << "Anomalous nPV: " << nPV << std::endl;

  std::string keyname_doublemuon(regions[region] + "_doublemuon_" + pvCut);
  std::string keyname_jetht(regions[region] + "_jetht_" + pvCut);

  if(m_fakeRateType == "average") return 0.5*(m_fakeRates[keyname_doublemuon]->Eval(pt)+m_fakeRates[keyname_jetht]->Eval(pt));
  else if(m_fakeRateType == "doublemuon") return m_fakeRates[keyname_doublemuon]->Eval(pt);
  else if(m_fakeRateType == "jetht") return m_fakeRates[keyname_jetht]->Eval(pt);
  else std::cout << "Fake rate type " << m_fakeRateType << "not supported." << std::endl;

  return 0;
}

void fakePrediction::Loop(int year, const std::string &dataset)
{
  fakeRateInit(year, dataset);

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
  int nbins=80;
  double xmin=0.0;
  double xmax=2000.0;

  setTDRStyle();
  gROOT->ForceStyle();

  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }
  const std::string outputFile("data/fakes_" + std::to_string(year) + "_" + dataset + ".root");
  TFile *output = new TFile(outputFile.c_str(), "recreate");
  output->mkdir("BB");
  output->mkdir("BE");


  TH1D *good[2], *TT[2], *FT[2], *TF[2], *FF[2];
  TH1D *qt[2], *absDeltaPhi[2], *deltaEta[2], *deltaR[2];
  TH1D *pt1[2], *pt2[2], *scEta1[2], *scEta2[2],  *phi1[2],  *phi2[2];
  for(unsigned int region=0; region<regions.size(); region++) {
    good[region] = new TH1D((regions[region] + "good").c_str(), (regions[region] + "good").c_str(), nbins, xmin, xmax);
    // real/fake decomposition
    TT[region] = new TH1D((regions[region] + "TT").c_str(), (regions[region] + "TT").c_str(), nbins, xmin, xmax);
    FT[region] = new TH1D((regions[region] + "FT").c_str(), (regions[region] + "FT").c_str(), nbins, xmin, xmax);
    TF[region] = new TH1D((regions[region] + "TF").c_str(), (regions[region] + "TF").c_str(), nbins, xmin, xmax);
    FF[region] = new TH1D((regions[region] + "FF").c_str(), (regions[region] + "FF").c_str(), nbins, xmin, xmax);
    qt[region] = new TH1D((regions[region] + "_qt").c_str(), (regions[region] + "_qt").c_str(), 50, 0., 1000.);
    // diphoton variables
    absDeltaPhi[region] = new TH1D((regions[region] + "_absDeltaPhi").c_str(), (regions[region] + "_absDeltaPhi").c_str(), 25, 0, TMath::Pi());
    deltaEta[region] = new TH1D((regions[region] + "_deltaEta").c_str(), (regions[region] + "_deltaEta").c_str(), 50, -5, 5);
    deltaR[region] = new TH1D((regions[region] + "_deltaR").c_str(), (regions[region] + "_deltaR").c_str(), 60, 0, 6);
    // single photon variables
    pt1[region] = new TH1D((regions[region] + "_pt1").c_str(), (regions[region] + "_pt1").c_str(), 40, 0., 1000.);
    pt2[region] = new TH1D((regions[region] + "_pt2").c_str(), (regions[region] + "_pt2").c_str(), 40, 0., 1000.);
    scEta1[region] = new TH1D((regions[region] + "_scEta1").c_str(), (regions[region] + "_scEta1").c_str(), 25, -2.5, 2.5);
    scEta2[region] = new TH1D((regions[region] + "_scEta2").c_str(), (regions[region] + "_scEta2").c_str(), 25, -2.5, 2.5);
    phi1[region] = new TH1D((regions[region] + "_phi1").c_str(), (regions[region] + "_phi1").c_str(), 50, -TMath::Pi(), TMath::Pi());
    phi2[region] = new TH1D((regions[region] + "_phi2").c_str(), (regions[region] + "_phi2").c_str(), 50, -TMath::Pi(), TMath::Pi());
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
	  if(isBarrelBarrel(TFPhoton1_eta, TFPhoton2_eta)) {
	    double rate = getFakeRate(TFPhoton2_pt, EB);
	    TF[BB]->Fill(TFDiphoton_Minv, weight*rate);
	    qt[BB]->Fill(TFDiphoton_qt, weight*rate);
	    absDeltaPhi[BB]->Fill(abs(TFDiphoton_deltaPhi), weight*rate);
	    deltaEta[BB]->Fill(TFDiphoton_deltaEta, weight*rate);
	    deltaR[BB]->Fill(TFDiphoton_deltaR, weight*rate);
	    pt1[BB]->Fill(TFPhoton1_pt, weight*rate);
	    scEta1[BB]->Fill(TFPhoton1_scEta, weight*rate);
	    phi1[BB]->Fill(TFPhoton1_phi, weight*rate);
	    pt2[BB]->Fill(TFPhoton2_pt, weight*rate);
	    scEta2[BB]->Fill(TFPhoton2_scEta, weight*rate);
	    phi2[BB]->Fill(TFPhoton2_phi, weight*rate);
	  }
	  else if (isBarrelEndcap(TFPhoton1_eta, TFPhoton2_eta)) {
	    int region = TFPhoton2_isEB ? EB : EE;
	    double rate = getFakeRate(TFPhoton2_pt, region);
	    TF[BE]->Fill(TFDiphoton_Minv, weight*rate);
	    qt[BE]->Fill(TFDiphoton_qt, weight*rate);
	    absDeltaPhi[BE]->Fill(abs(TFDiphoton_deltaPhi), weight*rate);
	    deltaEta[BE]->Fill(TFDiphoton_deltaEta, weight*rate);
	    deltaR[BE]->Fill(TFDiphoton_deltaR, weight*rate);
	    pt1[BE]->Fill(TFPhoton1_pt, weight*rate);
	    scEta1[BE]->Fill(TFPhoton1_scEta, weight*rate);
	    phi1[BE]->Fill(TFPhoton1_phi, weight*rate);
	    pt2[BE]->Fill(TFPhoton2_pt, weight*rate);
	    scEta2[BE]->Fill(TFPhoton2_scEta, weight*rate);
	    phi2[BE]->Fill(TFPhoton2_phi, weight*rate);
	  }
	}
      }
      // fake, true
      if(isFT) {
	bool pass = (FTPhoton1_isEB || (FTPhoton1_isEE && FTPhoton1_passCorPhoIso)) && FTPhoton1_hadronicOverEm < hadronicOverEmCut
	  && FTPhoton1_r9_5x5 > 0.8 && FTPhoton2_r9_5x5 > 0.8;
	if(pass && FTPhoton1_pt > ptMin && FTPhoton2_pt > ptMin && FTDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(FTPhoton1_eta, FTPhoton2_eta)) {
	    double rate = getFakeRate(FTPhoton1_pt, EB);
	    FT[BB]->Fill(FTDiphoton_Minv, weight*rate);
	    qt[BB]->Fill(FTDiphoton_qt, weight*rate);
	    absDeltaPhi[BB]->Fill(abs(FTDiphoton_deltaPhi), weight*rate);
	    deltaEta[BB]->Fill(FTDiphoton_deltaEta, weight*rate);
	    deltaR[BB]->Fill(FTDiphoton_deltaR, weight*rate);
	    pt1[BB]->Fill(FTPhoton1_pt, weight*rate);
	    scEta1[BB]->Fill(FTPhoton1_scEta, weight*rate);
	    phi1[BB]->Fill(FTPhoton1_phi, weight*rate);
	    pt2[BB]->Fill(FTPhoton2_pt, weight*rate);
	    scEta2[BB]->Fill(FTPhoton2_scEta, weight*rate);
	    phi2[BB]->Fill(FTPhoton2_phi, weight*rate);
	  }
	  else if (isBarrelEndcap(FTPhoton1_eta, FTPhoton2_eta)) {
	    int region = FTPhoton1_isEB ? EB : EE;
	    double rate = getFakeRate(FTPhoton1_pt, region);
	    FT[BE]->Fill(FTDiphoton_Minv, weight*rate);
	    qt[BE]->Fill(FTDiphoton_qt, weight*rate);
	    absDeltaPhi[BE]->Fill(abs(FTDiphoton_deltaPhi), weight*rate);
	    deltaEta[BE]->Fill(FTDiphoton_deltaEta, weight*rate);
	    deltaR[BE]->Fill(FTDiphoton_deltaR, weight*rate);
	    pt1[BE]->Fill(FTPhoton1_pt, weight*rate);
	    scEta1[BE]->Fill(FTPhoton1_scEta, weight*rate);
	    phi1[BE]->Fill(FTPhoton1_phi, weight*rate);
	    pt2[BE]->Fill(FTPhoton2_pt, weight*rate);
	    scEta2[BE]->Fill(FTPhoton2_scEta, weight*rate);
	    phi2[BE]->Fill(FTPhoton2_phi, weight*rate);
	  }
	}
      }
      // fake, fake
      if(isFF) {
	bool pass = (FFPhoton1_isEB || (FFPhoton1_isEE && FFPhoton1_passCorPhoIso)) && (FFPhoton2_isEB || (FFPhoton2_isEE && FFPhoton2_passCorPhoIso))
	  && FFPhoton1_hadronicOverEm < hadronicOverEmCut && FFPhoton2_hadronicOverEm < hadronicOverEmCut
	  && FFPhoton1_r9_5x5 > 0.8 && FFPhoton2_r9_5x5 > 0.8;
	if(pass && FFPhoton1_pt > ptMin && FFPhoton2_pt > ptMin && FFDiphoton_Minv > minvMin) {
	  if(isBarrelBarrel(FFPhoton1_eta, FFPhoton2_eta)) {
	    double rate = getFakeRate(FFPhoton1_pt, EB)*getFakeRate(FFPhoton2_pt, EB);
	    FF[BB]->Fill(FFDiphoton_Minv, weight*rate);
	    qt[BB]->Fill(FFDiphoton_qt, weight*rate);
	    absDeltaPhi[BB]->Fill(abs(FFDiphoton_deltaPhi), weight*rate);
	    deltaEta[BB]->Fill(FFDiphoton_deltaEta, weight*rate);
	    deltaR[BB]->Fill(FFDiphoton_deltaR, weight*rate);
	    pt1[BB]->Fill(FFPhoton1_pt, weight*rate);
	    scEta1[BB]->Fill(FFPhoton1_scEta, weight*rate);
	    phi1[BB]->Fill(FFPhoton1_phi, weight*rate);
	    pt2[BB]->Fill(FFPhoton2_pt, weight*rate);
	    scEta2[BB]->Fill(FFPhoton2_scEta, weight*rate);
	    phi2[BB]->Fill(FFPhoton2_phi, weight*rate);
	  }
	  else if (isBarrelEndcap(FFPhoton1_eta, FFPhoton2_eta)) {
	    int region1 = FFPhoton1_isEB ? EB : EE;
	    int region2 = FFPhoton2_isEB ? EB : EE;
	    double rate = getFakeRate(FFPhoton1_pt, region1)*getFakeRate(FFPhoton2_pt, region2);
	    FF[BE]->Fill(FFDiphoton_Minv, weight*rate);
	    qt[BE]->Fill(FFDiphoton_qt, weight*rate);
	    absDeltaPhi[BE]->Fill(abs(FFDiphoton_deltaPhi), weight*rate);
	    deltaEta[BE]->Fill(FFDiphoton_deltaEta, weight*rate);
	    deltaR[BE]->Fill(FFDiphoton_deltaR, weight*rate);
	    pt1[BE]->Fill(FFPhoton1_pt, weight*rate);
	    scEta1[BE]->Fill(FFPhoton1_scEta, weight*rate);
	    phi1[BE]->Fill(FFPhoton1_phi, weight*rate);
	    pt2[BE]->Fill(FFPhoton2_pt, weight*rate);
	    scEta2[BE]->Fill(FFPhoton2_scEta, weight*rate);
	    phi2[BE]->Fill(FFPhoton2_phi, weight*rate);
	  }
	}
      }
   }

   // barrel, barrel fakes sum
   TH1D *sum[2], *sum_copy[2], *sum_for_datacard[2];
   sum[BB] = static_cast<TH1D*>(TF[BB]->Clone("gjDataDrivenBB"));
   sum[BB]->Add(FT[BB]);
   sum[BB]->Add(FF[BB]);
   // barrel, endcap fakes sum
   sum[BE] = static_cast<TH1D*>(TF[BE]->Clone("gjDataDrivenBE"));
   sum[BE]->Add(FT[BE]);
   sum[BE]->Add(FF[BE]);
   sum_copy[BB] = static_cast<TH1D*>(sum[BB]->Clone("BB_Minv"));
   sum_copy[BE] = static_cast<TH1D*>(sum[BE]->Clone("BE_Minv"));
   sum_for_datacard[BB] = static_cast<TH1D*>(sum[BB]->Clone("gj"));
   sum_for_datacard[BE] = static_cast<TH1D*>(sum[BE]->Clone("gj"));

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
     sum_copy[i]->Write();
     sum_for_datacard[i]->Write();
     pt1[i]->Write();
     pt2[i]->Write();
     qt[i]->Write();
     absDeltaPhi[i]->Write();
     deltaEta[i]->Write();
     deltaR[i]->Write();
     pt1[i]->Write();
     scEta1[i]->Write();
     phi1[i]->Write();
     pt2[i]->Write();
     scEta2[i]->Write();
     phi2[i]->Write();
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
