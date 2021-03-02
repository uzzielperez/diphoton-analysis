/**
 * Produces fake rate plot as a function of pT
 *
 * This function calls /analysis/rooFitClosureTest.C
 * From /analysis, run
 * root -l -b -q ../scripts/fakeRateCalculation.C'("mc","sieie", era)'
 * where year = 2016 or 2017
 */

#include "diphoton-analysis/FakeRateAnalysis/RooFitTemplateFitting/analysis/rooFitClosureTest.C"

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate) {
  // double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  // Calculate fakeRate Uncertainty given numerator error = fitresult.2 and numerator (fakevalue) = fitresult.1
  // and the denominator error and the denominator
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

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

  std::cout << "\nStarting closure_test_rooFit()\n" << std::endl;
  // FIXME: Call ulimit -n 2048 when doing granular

  if(argc < 3) {
    std::cout << "Syntax: closure_test_rooFit.exe [DiPhotonJets/GGJets/GJets/all/alltruth] [sieie/chIso] [2016/2017/2018] [PV_low] [PV_high]" << std::endl;
    return -1;
  }
  else {
    sample = argv[1];
    if (sample != "all" && sample != "GGJets" && sample != "GJets" && sample != "QCD" && sample !="alltruth") {
      std::cout << "Choose sample: QCD, GJets, GGJets, all, or alltruth\n" << std::endl;
      return -1;
    }

    templateVariable = argv[2];
    if (templateVariable != "sieie" && templateVariable != "chIso") {
      std::cout << "Choose template variable: sieie or chIso\n" << std::endl;
      return -1;
    }
    std::cout << "Using template variable: " << templateVariable << std::endl;

    era = argv[3];
    if (!era.Contains("2016") && !era.Contains("2017") && !era.Contains("2018")) {
      std::cout << "Only years 2016, 2017 and 2018 are supported" << std::endl;
      return -1;
    }
    if(argc>3) pvCutLow = std::atoi(argv[4]);
    if(argc>4) pvCutHigh = std::atoi(argv[5]);
  }

  // array of pt bin edges
  std::vector<int> ptBinArray({ 50, 70, 90, 110, 130, 150});
  // With higher statistics in JetHT sample, additional bins can be used
  if(sample=="all" || sample=="alltruth") {
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
  // chIsoSidebands.push_back( std::make_pair(0.,5.) );
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

  std::vector<TGraphAsymmErrors*> fakeRatesEB;
  std::vector<TGraphAsymmErrors*> fakeRatesEE;
  std::vector<TGraphAsymmErrors*> bkgVsPtEBVec;
  std::vector<TGraphAsymmErrors*> bkgVsPtEEVec;

  // granular 1- inner, 2- outer
  std::vector<TGraphAsymmErrors*> fakeRatesEB1;
  std::vector<TGraphAsymmErrors*> fakeRatesEB2;
  std::vector<TGraphAsymmErrors*> fakeRatesEE1;
  std::vector<TGraphAsymmErrors*> fakeRatesEE2;
  std::vector<TGraphAsymmErrors*> fakeRatesEE3;

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

  // granular 1- inner, 2- outer
    TGraphAsymmErrors* fakeRateEB1 = new TGraphAsymmErrors();
    fakeRateEB1->SetName("fakeRateEB1"+postFix);
    fakeRateEB1->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB1.push_back(fakeRateEB1);

    TGraphAsymmErrors* fakeRateEB2 = new TGraphAsymmErrors();
    fakeRateEB2->SetName("fakeRateEB2"+postFix);
    fakeRateEB2->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB2.push_back(fakeRateEB2);
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

    // granular 1- inner, 2- outer
    TGraphAsymmErrors* fakeRateEE1 = new TGraphAsymmErrors();
    fakeRateEE1->SetName("fakeRateEE1"+postFix);
    fakeRateEE1->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE1.push_back(fakeRateEE1);

    TGraphAsymmErrors* fakeRateEE2 = new TGraphAsymmErrors();
    fakeRateEE2->SetName("fakeRateEE2"+postFix);
    fakeRateEE2->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE2.push_back(fakeRateEE2);

    TGraphAsymmErrors* fakeRateEE3 = new TGraphAsymmErrors();
    fakeRateEE3->SetName("fakeRateEE3"+postFix);
    fakeRateEE3->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE3.push_back(fakeRateEE3);
  }

  TString pvCut = "";
  if(pvCutLow!=0 || pvCutHigh!=2000) pvCut = Form("_nPV%i-%i", pvCutLow, pvCutHigh);
  TFile outfile("fakeRatePlots_" + sample + "_" + era + pvCut + ".root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitClosureTest, we don't need it open here too

  std::map<TString, TString> cmssw_version;
  cmssw_version["2016"] = "76X";
  cmssw_version["2017"] = "94X";
  cmssw_version["2018"] = "102X";

  TString input_filename;
  //  if (sample == "data")      input_filename = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_vanilla.root";
  //  if (sample == "data")      input_filename = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_UNKNOWN_newDenomDef.root";
  //TString basefilename("root://cmseos.fnal.gov//store/user/cawest/fake_rate/");
  TString basefilename("/uscms/home/cuperez/nobackup/tribosons/FakeRate/FakeRate/CMSSW_10_2_18/src/");

  if (sample == "all" || sample == "alltruth")        input_filename = "diphoton_fake_rate_closure_test_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "QCD")    input_filename = "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")  input_filename = "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets") input_filename = "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  // if (sample == "alltruth")   input_filename = "diphoton_fake_rate_closure_test_matching_all_samples_"+ cmssw_version[era] +"_MiniAOD_histograms.root";
  TFile *infile = TFile::Open(input_filename,"read");

  // debug vectors
  std::vector<double> numVec;
  std::vector<double> denomVec;

  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
    for (int i = 0; i < nBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      infile->cd();

      double sidebandLow = sidebandsEB.at(j).first;
      double sidebandHigh = sidebandsEB.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")
	postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso")
	postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

      // Return pair: (fakevalue, fakerrormax) for ptBin, sideband
      std::pair<double,double> resEB = rooFitClosureTest(sample,templateVariable,binName,TString("EB"),sidebandsEB.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin

      // record fake rate in TGraphs
      TString histNameEB = TString::Format("PtEB_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEB = static_cast<TH1D*>(infile->Get(histNameEB));

      double denomEB = histEB->Integral();
      double graphX_EB = histEB->GetMean();
      double graphY_EB = resEB.first/denomEB; // i.e. the fake rate in the EB
      double eXLow_EB = graphX_EB - ptLow;
      double eXHigh_EB = ptHigh - graphX_EB;
      double ey_EB = fakeRateUncertainty(denomEB,resEB.second,graphY_EB);

      fakeRatesEB.at(j)->SetPoint(i,graphX_EB,graphY_EB);
      fakeRatesEB.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,ey_EB,ey_EB);

      // record background fit result
      bkgVsPtEBVec.at(j)->SetPoint(i,graphX_EB,resEB.first/ptBinSize);
      bkgVsPtEBVec.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,resEB.second/ptBinSize,resEB.second/ptBinSize);

      //granular 1-inner, 2-outer
      //FIXME Return pair: (fake)
      std::pair<double,double> resEB1 = rooFitClosureTest(sample,templateVariable,binName,TString("EB1"),sidebandsEB.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      std::pair<double,double> resEB2 = rooFitClosureTest(sample,templateVariable,binName,TString("EB2"),sidebandsEB.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin

      TString histNameEB1 = TString::Format("PtEB1_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TString histNameEB2 = TString::Format("PtEB2_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEB1 = static_cast<TH1D*>(infile->Get(histNameEB1));
      TH1D* histEB2 = static_cast<TH1D*>(infile->Get(histNameEB2));

      double denomEB1 = histEB1->Integral();
      double graphX_EB1 = histEB1->GetMean();
      // Fake Rate in EB1
      double graphY_EB1 = resEB1.first/denomEB1;
      double eXLow_EB1 = graphX_EB1 - ptLow;
      double eXHigh_EB1 = ptHigh - graphX_EB1;
      double ey_EB1 = fakeRateUncertainty(denomEB1,resEB1.second,graphY_EB1);

      fakeRatesEB1.at(j)->SetPoint(i,graphX_EB1,graphY_EB1);
      fakeRatesEB1.at(j)->SetPointError(i,eXLow_EB1,eXHigh_EB1,ey_EB1,ey_EB1);

      double denomEB2 = histEB2->Integral();
      double graphX_EB2 = histEB2->GetMean();
      // Fake Rate in EB2
      double graphY_EB2 = resEB2.first/denomEB2;
      double eXLow_EB2 = graphX_EB2 - ptLow;
      double eXHigh_EB2 = ptHigh - graphX_EB2;
      double ey_EB2 = fakeRateUncertainty(denomEB2,resEB2.second,graphY_EB2);

      fakeRatesEB2.at(j)->SetPoint(i,graphX_EB2,graphY_EB2);
      fakeRatesEB2.at(j)->SetPointError(i,eXLow_EB2,eXHigh_EB2,ey_EB2,ey_EB2);

    } // end loop over pT bins
  } // end loop over sidebands

  for (unsigned int j = 0; j < sidebandsEE.size(); j++) {
    for (int i = 0; i < nBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      infile->cd();

      double sidebandLow = sidebandsEE.at(j).first;
      double sidebandHigh = sidebandsEE.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")
	postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso")
	postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);

      std::pair<double,double> resEE = rooFitClosureTest(sample,templateVariable,binName,TString("EE"),sidebandsEE.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin

      // record fake rate in TGraphs
      TString histNameEE = TString::Format("PtEE_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEE = static_cast<TH1D*>(infile->Get(histNameEE));

      double denomEE = histEE->Integral();
      double graphX_EE = histEE->GetMean();
      double graphY_EE = resEE.first/denomEE; // i.e. the fake rate in the EE
      double eXLow_EE = graphX_EE - ptLow;
      double eXHigh_EE = ptHigh - graphX_EE;
      double ey_EE = fakeRateUncertainty(denomEE,resEE.second,graphY_EE);

      fakeRatesEE.at(j)->SetPoint(i,graphX_EE,graphY_EE);
      fakeRatesEE.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,ey_EE,ey_EE);

      //granular 1-inner, 2-outer
      //FIXME Return pair: (fake)
      std::pair<double,double> resEE1 = rooFitClosureTest(sample,templateVariable,binName,TString("EE1"),sidebandsEE.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      std::pair<double,double> resEE2 = rooFitClosureTest(sample,templateVariable,binName,TString("EE2"),sidebandsEE.at(j),i+1, era, pvCutLow, pvCutHigh); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      std::pair<double,double> resEE3 = rooFitClosureTest(sample,templateVariable,binName,TString("EE3"),sidebandsEE.at(j),i+1, era, pvCutLow, pvCutHigh);

      TString histNameEE1 = TString::Format("PtEE1_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TString histNameEE2 = TString::Format("PtEE2_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEE1 = static_cast<TH1D*>(infile->Get(histNameEE1));
      TH1D* histEE2 = static_cast<TH1D*>(infile->Get(histNameEE2));

      TString histNameEE3 = TString::Format("PtEE3_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEE3 = static_cast<TH1D*>(infile->Get(histNameEE3));

      double denomEE1 = histEE1->Integral();
      double graphX_EE1 = histEE1->GetMean();
      // Fake Rate in EE1
      double graphY_EE1 = resEE1.first/denomEE1;
      double eXLow_EE1 = graphX_EE1 - ptLow;
      double eXHigh_EE1 = ptHigh - graphX_EE1;
      double ey_EE1 = fakeRateUncertainty(denomEE1,resEE1.second,graphY_EE1);

      fakeRatesEE1.at(j)->SetPoint(i,graphX_EE1,graphY_EE1);
      fakeRatesEE1.at(j)->SetPointError(i,eXLow_EE1,eXHigh_EE1,ey_EE1,ey_EE1);

      double denomEE2 = histEE2->Integral();
      double graphX_EE2 = histEE2->GetMean();
      // Fake Rate in EE2
      double graphY_EE2 = resEE2.first/denomEE2;
      double eXLow_EE2 = graphX_EE2 - ptLow;
      double eXHigh_EE2 = ptHigh - graphX_EE2;
      double ey_EE2 = fakeRateUncertainty(denomEE2,resEE2.second,graphY_EE2);

      fakeRatesEE2.at(j)->SetPoint(i,graphX_EE2,graphY_EE2);
      fakeRatesEE2.at(j)->SetPointError(i,eXLow_EE2,eXHigh_EE2,ey_EE2,ey_EE2);

      double denomEE3 = histEE3->Integral();
      double graphX_EE3 = histEE3->GetMean();
      // Fake Rate in EE3
      double graphY_EE3 = resEE3.first/denomEE3;
      double eXLow_EE3 = graphX_EE3 - ptLow;
      double eXHigh_EE3 = ptHigh - graphX_EE3;
      double ey_EE3 = fakeRateUncertainty(denomEE3,resEE3.second,graphY_EE3);

      fakeRatesEE3.at(j)->SetPoint(i,graphX_EE3,graphY_EE3);
      fakeRatesEE3.at(j)->SetPointError(i,eXLow_EE3,eXHigh_EE3,ey_EE3,ey_EE3);

      // fill debug vectors
      if (templateVariable == "sieie") {
	if (sidebandLow == 9.) {
	  numVec.push_back(resEE.first);
	  denomVec.push_back(denomEE);
	}
      }

      // record background fit result
      bkgVsPtEEVec.at(j)->SetPoint(i,graphX_EE,resEE.first/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);
    } // end loop over pT bins
  } // end loop over sidebands

  infile->cd();

  TH1D* denomvsptEB = (TH1D*) infile->Get("phoPtEB_denominator_varbin")->Clone();
  TH1D* denomvsptEE = (TH1D*) infile->Get("phoPtEE_denominator_varbin")->Clone();
  //granular: 1-inner, 2-outer
  TH1D* denomvsptEB1 = (TH1D*) infile->Get("phoPtEB1_denominator_varbin")->Clone();
  TH1D* denomvsptEB2 = (TH1D*) infile->Get("phoPtEB2_denominator_varbin")->Clone();
  TH1D* denomvsptEE1 = (TH1D*) infile->Get("phoPtEE1_denominator_varbin")->Clone();
  TH1D* denomvsptEE2 = (TH1D*) infile->Get("phoPtEE2_denominator_varbin")->Clone();
  TH1D* denomvsptEE3 = (TH1D*) infile->Get("phoPtEE3_denominator_varbin")->Clone();


  for (int i = 1; i <= nBins-1; i++) {
    double binWidth = denomvsptEB->GetXaxis()->GetBinWidth(i);
    denomvsptEB->SetBinContent(i, denomvsptEB->GetBinContent(i) / binWidth);
    denomvsptEB->SetBinError  (i, denomvsptEB->GetBinError(i) / binWidth);
    denomvsptEE->SetBinContent(i, denomvsptEE->GetBinContent(i) / binWidth);
    denomvsptEE->SetBinError  (i, denomvsptEE->GetBinError(i) / binWidth);
    // granular: 1-inner, 2-outer
    denomvsptEB1->SetBinContent(i, denomvsptEB1->GetBinContent(i) / binWidth );
    denomvsptEB1->SetBinError  (i, denomvsptEB1->GetBinError(i) / binWidth );
    denomvsptEB2->SetBinContent(i, denomvsptEB2->GetBinContent(i) / binWidth );
    denomvsptEB2->SetBinError  (i, denomvsptEB2->GetBinError(i) / binWidth );
    denomvsptEE1->SetBinContent(i, denomvsptEE1->GetBinContent(i) / binWidth);
    denomvsptEE1->SetBinError  (i, denomvsptEE1->GetBinError(i) / binWidth);
    denomvsptEE2->SetBinContent(i, denomvsptEE2->GetBinContent(i) / binWidth);
    denomvsptEE2->SetBinError  (i, denomvsptEE2->GetBinError(i) / binWidth);
    denomvsptEE3->SetBinContent(i, denomvsptEE3->GetBinContent(i) / binWidth);
    denomvsptEE3->SetBinError  (i, denomvsptEE3->GetBinError(i) / binWidth);
  }

  denomvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");
  // granular: 1-inner, 2-outer
  denomvsptEB1->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEB2->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE1->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE2->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE3->GetXaxis()->SetTitle("p_{T} (GeV)");

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

  TFile outfile2("fakeRatePlots_" + sample + "_" + era + pvCut + ".root","update");
  outfile2.cd();
  denomvsptEB->Write();
  denomvsptEE->Write();
  denomvsptEB1->Write();
  denomvsptEB2->Write();
  denomvsptEE1->Write();
  denomvsptEE2->Write();
  denomvsptEE3->Write();


  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
    outfile2.cd();

    fakeRatesEB.at(j)->Write();
    bkgVsPtEBVec.at(j)->Write();

    double sidebandLow = sidebandsEB.at(j).first;
    double sidebandHigh = sidebandsEB.at(j).second;
    TString postFix = "";
    TString label = "";
    if (templateVariable == "sieie") {
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      label = TString::Format("%d < Iso_{Ch} < %d GeV",(int)sidebandLow,(int)sidebandHigh);
    }
    else if (templateVariable == "chIso") {
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      label = TString::Format("%.4f < #sigma_{i#etai#eta} < %.4f",sidebandLow,sidebandHigh);
    }

    TCanvas c("c","",800,600);

    fakeRatesEB.at(j)->Draw();
    // fakeRatesEB.at(j)->SetTitle("EB");
    fakeRatesEB.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEB.at(j)->GetYaxis()->SetRangeUser(0.0, 0.25);
    fakeRatesEB.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label = new TLatex();
    t_label->SetTextAlign(12);
    t_label->DrawLatexNDC(0.50,0.75,"ECAL barrel");
    t_label->DrawLatexNDC(0.50,0.70,label);

    c.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EB"+postFix+ pvCut + ".pdf");

    // granular: 1-inner, 2-outer
    fakeRatesEB1.at(j)->Write();
    fakeRatesEB2.at(j)->Write();

    TCanvas c1("c1","",800,600);

    fakeRatesEB1.at(j)->Draw();
    fakeRatesEB1.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB1.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEB1.at(j)->GetYaxis()->SetRangeUser(0.0, 0.25);
    fakeRatesEB1.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label1 = new TLatex();
    t_label1->SetTextAlign(12);
    t_label1->DrawLatexNDC(0.50,0.75,"ECAL inner barrel");
    t_label1->DrawLatexNDC(0.50,0.70,label);

    c1.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EB1"+postFix+ pvCut + ".pdf");

    TCanvas c2("c2","",800,600);

    fakeRatesEB2.at(j)->Draw();
    fakeRatesEB2.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB2.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEB2.at(j)->GetYaxis()->SetRangeUser(0.0, 0.25);
    fakeRatesEB2.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label2 = new TLatex();
    t_label2->SetTextAlign(12);
    t_label2->DrawLatexNDC(0.50,0.75,"ECAL outer barrel");
    t_label2->DrawLatexNDC(0.50,0.70,label);

    c2.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EB2"+postFix+ pvCut + ".pdf");

  }

  for (unsigned int j = 0; j < sidebandsEE.size(); j++) {
    outfile2.cd();

    fakeRatesEE.at(j)->Write();
    bkgVsPtEEVec.at(j)->Write();

    double sidebandLow = sidebandsEE.at(j).first;
    double sidebandHigh = sidebandsEE.at(j).second;
    TString postFix = "";
    TString label = "";
    if (templateVariable == "sieie") {
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      label = TString::Format("%d < Iso_{Ch} < %d GeV",(int)sidebandLow,(int)sidebandHigh);
    }
    else if (templateVariable == "chIso") {
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      label = TString::Format("%.4f < #sigma_{i#etai#eta} < %.4f",sidebandLow,sidebandHigh);
    }

    TCanvas c("c","",800,600);

    fakeRatesEE.at(j)->Draw();
    // fakeRatesEE.at(j)->SetTitle("EE");
    fakeRatesEE.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE.at(j)->GetYaxis()->SetRangeUser(0.0, 0.6);
    fakeRatesEE.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label = new TLatex();
    t_label->SetTextAlign(12);
    t_label->DrawLatexNDC(0.50,0.75,"ECAL endcap");
    t_label->DrawLatexNDC(0.50,0.70,label);

    c.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EE"+postFix+ pvCut + ".pdf");

    // granular: 1-inner, 2-outer
    fakeRatesEE1.at(j)->Write();
    fakeRatesEE2.at(j)->Write();
    fakeRatesEE3.at(j)->Write();

    TCanvas c1("c1","",800,600);

    fakeRatesEE1.at(j)->Draw();
    fakeRatesEE1.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE1.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE1.at(j)->GetYaxis()->SetRangeUser(0.0, 0.6);
    fakeRatesEE1.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label1 = new TLatex();
    t_label1->SetTextAlign(12);
    t_label1->DrawLatexNDC(0.50,0.75,"ECAL inner endcap");
    t_label1->DrawLatexNDC(0.50,0.70,label);

    c1.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EE1"+postFix+ pvCut + ".pdf");

    TCanvas c2("c2","",800,600);

    fakeRatesEE2.at(j)->Draw();
    fakeRatesEE2.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE2.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE2.at(j)->GetYaxis()->SetRangeUser(0.0, 0.6);
    fakeRatesEE2.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label2 = new TLatex();
    t_label2->SetTextAlign(12);
    t_label2->DrawLatexNDC(0.50,0.75,"ECAL outer endcap");
    t_label2->DrawLatexNDC(0.50,0.70,label);

    c2.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EE2"+postFix+ pvCut + ".pdf");

    TCanvas c3("c3","",800,600);

    fakeRatesEE3.at(j)->Draw();
    fakeRatesEE3.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE3.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE3.at(j)->GetYaxis()->SetRangeUser(0.0, 0.6);
    fakeRatesEE3.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label3 = new TLatex();
    t_label3->SetTextAlign(12);
    t_label3->DrawLatexNDC(0.50,0.75,"ECAL outer endcap");
    t_label3->DrawLatexNDC(0.50,0.70,label);

    c2.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EE3"+postFix+ pvCut + ".pdf");
  }

  outfile2.Close();

  std::cout << "\nEnding closure_test_rooFit()\n" << std::endl;

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;

  return 0;
}
