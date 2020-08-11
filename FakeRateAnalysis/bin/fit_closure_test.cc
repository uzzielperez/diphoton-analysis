//#include "diphoton-analysis/FakeRateAnalysis/ClosureTestTemplateFits/fit_closure_test.C"
//#include "diphoton-analysis/FakeRateAnalysis/RooFitTemplateFitting/analysis/rooFitFakeRateProducer.C"
#include "diphoton-analysis/FakeRateAnalysis/RooFitTemplateFitting/analysis/rooFitClosureTestFakeRate.C"

#include <iostream>
#include "TStopwatch.h"
#include <TH1D.h>
#include <TH1.h>

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate) {
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

// TH1* GetHist(int ptbin, bool isEB, hist_t type)
// {
//   return h;
// }

int main(int argc, char *argv[])
{
  TString sample;
  TString templateVariable;
  TString era;
  int pvCutLow = 0;
  int pvCutHigh = 2000;

  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  std::cout << "\nStarting Closure test code...\n" << std::endl;

  if(argc<3) {
    std::cout << "Syntax: fit_closure_test.exe [2015/2016/2017/2018] [GGJets/GJets] [PV_low] [PV_high]" << std::endl;
    return -1;
  }
  else {
    sample = argv[1];
    if (sample != "GJets" && sample != "GGJets" && sample !="GGJets") {
      std::cout << "Choose sample: GJets, GGJets\n" << std::endl;
      return -1;
    }

    templateVariable = argv[2];
    if (templateVariable != "sieie" && templateVariable != "chIso") {
      std::cout << "Choose template variable: sieie or chIso\n" << std::endl;
      return -1;
    }
    std::cout << "Using template variable: " << templateVariable << std::endl;

    era = argv[3];
    if (!era.Contains("2015") && !era.Contains("2016") && !era.Contains("2017") && !era.Contains("2018")) {
      std::cout << "Only years 2015, 2016, 2017 and 2018 are supported" << std::endl;
      return -1;
    }
    if(argc>3) pvCutLow = std::atoi(argv[4]);
    if(argc>4) pvCutHigh = std::atoi(argv[5]);
  }

  // --- Setup ptBins, sidebands
  std::vector<int> ptBinArray({ 50, 70, 90, 110, 130, 150, 200, 250, 300, 600});
  std::vector<double> ptBinArray_double;
  for (auto iBin : ptBinArray) {
    ptBinArray_double.push_back(static_cast<double>(iBin));
  }
  const int ptBins = ptBinArray.size();

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

  // ---- Setup Vectors for fakeRates
  std::vector<TGraphAsymmErrors*> fakeRatesEB;
  std::vector<TGraphAsymmErrors*> fakeRatesEE;
  std::vector<TGraphAsymmErrors*> bkgVsPtEBVec;
  std::vector<TGraphAsymmErrors*> bkgVsPtEEVec;

  for (unsigned int i = 0; i < sidebandsEB.size(); i++) {
    double sidebandLow = sidebandsEB.at(i).first;
    double sidebandHigh = sidebandsEB.at(i).second;
    TString postFix = "";
    if (templateVariable == "sieie")
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    else if (templateVariable == "chIso")
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

    TGraphAsymmErrors* fakeRateEB = new TGraphAsymmErrors();
    fakeRateEB->SetName("fakeRateEB"+postFix);
    fakeRateEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB.push_back(fakeRateEB);

    TGraphAsymmErrors* bkgvsptEB = new TGraphAsymmErrors();
    bkgvsptEB->SetName("bkgvsptEB"+postFix);
    bkgvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgVsPtEBVec.push_back(bkgvsptEB);
  }

  for (unsigned int i = 0; i < sidebandsEE.size(); i++) {
    double sidebandLow = sidebandsEE.at(i).first;
    double sidebandHigh = sidebandsEE.at(i).second;
    TString postFix = "";
    if (templateVariable == "sieie")
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    else if (templateVariable == "chIso")
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

    TGraphAsymmErrors* fakeRateEE = new TGraphAsymmErrors();
    fakeRateEE->SetName("fakeRateEE"+postFix);
    fakeRateEE->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE.push_back(fakeRateEE);

    TGraphAsymmErrors* bkgvsptEE = new TGraphAsymmErrors();
    bkgvsptEE->SetName("bkgvsptEE"+postFix);
    bkgvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgVsPtEEVec.push_back(bkgvsptEE);
  }

  // --- Setup Input and Output files
  TString pvCut = "";
  if(pvCutLow!=0 || pvCutHigh!=2000) pvCut = Form("_nPV%i-%i", pvCutLow, pvCutHigh);
  TFile outfile("fakeRatePlots_" + sample + "_" + era + pvCut + ".root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitFakeRateProducer, we don't need it open here too

  // Currently handles only one input sample
  TString faketemp_inputfile;
  if (sample == "GGJets") faketemp_inputfile = "GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root";
  else std::cout << "Sample not supported for now." << std::endl;
  std::cout << "Opening Fake Template File: "  << faketemp_inputfile << std::endl;
  TFile *histofaketemp_file = TFile::Open(faketemp_inputfile);

  TString realtemp_inputfile = "diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root";
  TFile *historealtemp_file = TFile::Open(realtemp_inputfile);
  historealtemp_file->Print();

  std::cout << "Fake Template source: " << faketemp_inputfile << std::endl;
  std::cout << "Real Template source: " << realtemp_inputfile << std::endl;
  std::cout <<  ptBins << std::endl;

  //debug vectors
  std::vector<double> numVec;
  std::vector<double> denomVec;

  //---- Fake Rate Calculation per pT Bin using RooFit
  // Currently set up not to run fitting yet

  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
    for (int i = 0; i < ptBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      histofaketemp_file->cd();

      double sidebandLow = sidebandsEB.at(j).first;
      double sidebandHigh = sidebandsEB.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie") postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso") postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

      // --- Rename variables here
      // Result of Fake Rate Producer ( Rename this variable to something more meaningful )
      std::pair<double,double> resEB = rooFitFakeRateProducer(historealtemp_file, histofaketemp_file, sample,templateVariable,binName,TString("EB"),sidebandsEB.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin

      //-- Get Hist
      // TString histfaketemp( templateVariable + etaBin + "_faketemplate_pt" + ptBin + postFix );
      // TString histrealtemp( templateVariable + etaBin + "_realtemplate_pt" + ptBin );
      // TString histNum();
      // TString histDenom();

      // record fake rate in TGraphs
      TString histNameEB = TString::Format("PtEB_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEB = static_cast<TH1D*>(histofaketemp_file->Get(histNameEB));

      double denomEB = histEB->Integral();
      double graphX_EB = histEB->GetMean();
      double graphY_EB = resEB.first/denomEB; // i.e. the fake rate in the EB
      double eXLow_EB = graphX_EB - ptLow;
      double eXHigh_EB = ptHigh - graphX_EB;
      double ey_EB = fakeRateUncertainty(denomEB,resEB.second,graphY_EB);

      // record fakeRate results
      fakeRatesEB.at(j)->SetPoint(i,graphX_EB,graphY_EB);
      fakeRatesEB.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,ey_EB,ey_EB);
      // record background fit result
      bkgVsPtEBVec.at(j)->SetPoint(i,graphX_EB,resEB.first/ptBinSize);
      bkgVsPtEBVec.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,resEB.second/ptBinSize,resEB.second/ptBinSize);

    } // end loop over pTbins
  } // End loop over EB sidebands

  for (unsigned int j = 0; j < sidebandsEE.size(); j++) {
    for (int i = 0; i < ptBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      histofaketemp_file->cd();

      double sidebandLow = sidebandsEE.at(j).first;
      double sidebandHigh = sidebandsEE.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")  postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso") postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

      std::pair<double,double> resEE = rooFitFakeRateProducer(historealtemp_file, histofaketemp_file, sample,templateVariable,binName,TString("EE"),sidebandsEE.at(j),i+1, era, pvCutLow, pvCutHigh);
      // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin

      // record fake rate in TGraphs
      TString histNameEE = TString::Format("PtEE_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEE = static_cast<TH1D*>(  histofaketemp_file->Get(histNameEE) );

      double denomEE = histEE->Integral();
      double graphX_EE = histEE->GetMean();
      double graphY_EE = resEE.first/denomEE; // i.e. the fake rate in the EE
      double eXLow_EE = graphX_EE - ptLow;
      double eXHigh_EE = ptHigh - graphX_EE;
      double ey_EE = fakeRateUncertainty(denomEE,resEE.second,graphY_EE);

      fakeRatesEE.at(j)->SetPoint(i,graphX_EE,graphY_EE);
      fakeRatesEE.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,ey_EE,ey_EE);

      // record background fit result
      bkgVsPtEEVec.at(j)->SetPoint(i,graphX_EE,resEE.first/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);

    } // end loop over pT bins
  } // end loop over sidebands EE

  histofaketemp_file->cd();

  TH1D* denomvsptEB = (TH1D*) histofaketemp_file->Get("phoPtEB_denominator_varbin")->Clone();
  TH1D* denomvsptEE = (TH1D*) histofaketemp_file->Get("phoPtEE_denominator_varbin")->Clone();

  for (int i = 1; i <= ptBins-1; i++) {
    double binWidth = denomvsptEB->GetXaxis()->GetBinWidth(i);
    denomvsptEB->SetBinContent(i, denomvsptEB->GetBinContent(i) / binWidth);
    denomvsptEB->SetBinError  (i, denomvsptEB->GetBinError(i) / binWidth);
    denomvsptEE->SetBinContent(i, denomvsptEE->GetBinContent(i) / binWidth);
    denomvsptEE->SetBinError  (i, denomvsptEE->GetBinError(i) / binWidth);
  }

  denomvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");

  // debug printout to see fake rate ratios
  if (templateVariable == "sieie") {
    for (unsigned int i = 0; i < (numVec.size()-1); i++) {
      double numratio = numVec.at(i+1) / numVec.at(i);
      double denomratio = denomVec.at(i) / denomVec.at(i+1);
      std::cout << "EE Debug Info: ptBinLowEdge       n2/n1       d1/d2       FR" << std::endl;
      std::cout << ptBinArray[i] << " " << numratio << " " << denomratio << " " << numratio*denomratio << std::endl;
      std::cout << " " << std::endl;
    }
  }

  std::cout << "\nEnding fakeRateCalculation()\n" << std::endl;

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;

  return 0;
}
