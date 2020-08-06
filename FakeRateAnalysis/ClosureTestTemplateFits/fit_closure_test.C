#include <TH1D.h>
#include <TH1.h>
#include <TFile.h>
#include <TString.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TPad.h>
#include <TMath.h>
#include <TMinuit.h>
#include "TStopwatch.h"

#include <iostream>
#include <sstream>


// rooFit
#include "TF1.h"
#include "RooHistPdf.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooDataHist.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooNDKeysPdf.h"
#include "TFile.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TMath.h"
#include "TText.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "RooChi2Var.h"

const int NPTBINS=5;
const float PTBINS[NPTBINS+1] = { 50, 70, 90, 130, 200, 600 };

enum hist_t { Real, Fake, Truth, Numerator, Denominator };

const int NEBBINS=9;
const double EBBINS[NEBBINS+1] = { 0., 0.0075, 0.009, 0.0105, 0.0120, 0.0135, 0.0150, 0.0165, 0.0180, 0.03};
const int EBSIEIECUTBIN=4;

const int NEEBINS=8;
const double EEBINS[NEEBINS+1] = { 0., 0.016, 0.020, 0.024, 0.028, 0.032, 0.036, 0.040, 0.08 };
const int EESIEIECUTBIN=5;

TFile* rootfile=0;

// histograms used by the fitter
TH1 *theData, *theBkg1, *theBkg2;

void fit_closure_test(TString run, TString templateVariable, TString sample, int npvLow = 0, int npvHigh = 2000){
  TStopwatch sw;
  sw.Start();

  // array of pt bin edges
  std::vector<int> ptBinArray({ 50, 70, 90, 110, 130, 150});
  // With higher statistics in JetHT sample, additional bins can be used
  if(sample=="jetht") {
    ptBinArray.push_back(200);
    ptBinArray.push_back(250);
    ptBinArray.push_back(300);
  }
  ptBinArray.push_back(600);
  std::vector<double> ptBinArray_double;
  for (auto iBin : ptBinArray) {
    ptBinArray_double.push_back(static_cast<double>(iBin));
  }
  const int nBins = ptBinArray.size();

  // make vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );

  // vector of sieie sidebands
  // EB
  std::vector< std::pair<double,double> > sieie_EB_sidebands;
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,1.0000) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,0.0150) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0150,0.0200) );
  // EE
  std::vector< std::pair<double,double> > sieie_EE_sidebands;
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,1.000) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,0.040) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0400,0.060) );

  std::vector< std::pair<double,double> > sidebandsEB, sidebandsEE;
  if (templateVariable == "sieie") {
    sidebandsEB = chIsoSidebands;
    sidebandsEE = chIsoSidebands;
  }
  else if (templateVariable == "chIso") {
    sidebandsEB = sieie_EB_sidebands;
    sidebandsEE = sieie_EE_sidebands;
  }

  // Get Sample
  TString input_filename;
  if (sample == "GGJets") input_filename = "GGJets_fakerate_2018_pV38-200_newDenomDef.root";
  else std::cout << "Sample not supported for now." << std::endl;

  TFile *histo_templatefile = TFile::Open(input_filename);
  // Get Histograms

  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
  // Loop over ptBin
    TString etaBin = "EB"; //or EB1, EB2, EE
    for (int i = 0; i < nBins-1; i++) { // ptBins loop
      // double ptLow = ptBinArray_double[i];
      // double ptHigh = ptBinArray_double[i+1];
      // double ptBinSize = ptHigh - ptLow;
      TString ptBin = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      double sidebandLow = sidebandsEB.at(j).first;
      double sidebandHigh = sidebandsEB.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")  postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso") postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      TString histName( templateVariable + etaBin + TString("_faketemplate_pt") + ptBin + postFix );
      std::cout << "Getting " << histName << std::endl;

      histo_templatefile->Print();
      TH1D *hfakeTemplate = (TH1D*) histo_templatefile->Get(histName);
      hfakeTemplate->Print();
  } // end loop over ptBins
} // end loop over sideBands


  sw.Stop();
  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
