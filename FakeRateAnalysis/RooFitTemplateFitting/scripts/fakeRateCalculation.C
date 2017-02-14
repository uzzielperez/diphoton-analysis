#include "rooFitFakeRateProducer.C"

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate) {
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

void fakeRateCalculation() {

  // true - data
  // false - mc (closure test)
  bool is_data = true;
  if (is_data) cout << "Running over data." << endl;
  if (!is_data) cout << "Running over MC." << endl;
  
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // array of pt bin edges
  const int nBins = 10;
  int ptBinArray[nBins] = { 50, 70, 90, 110, 130, 150, 200, 250, 300, 600 };
  double ptBinArray_double[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  
  // make vector of sidebands
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

  std::vector<TGraphAsymmErrors*> fakeRatesEB;
  std::vector<TGraphAsymmErrors*> fakeRatesEE;
  std::vector<TGraphAsymmErrors*> bkgVsPtEBVec;
  std::vector<TGraphAsymmErrors*> bkgVsPtEEVec;

  for (unsigned int i = 0; i < chIsoSidebands.size(); i++) {
    double sidebandLow = chIsoSidebands.at(i).first;
    double sidebandHigh = chIsoSidebands.at(i).second;
    TString postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);

    TGraphAsymmErrors* fakeRateEB = new TGraphAsymmErrors();
    TGraphAsymmErrors* fakeRateEE = new TGraphAsymmErrors();
    TGraphAsymmErrors* bkgvsptEB = new TGraphAsymmErrors();
    TGraphAsymmErrors* bkgvsptEE = new TGraphAsymmErrors();

    fakeRateEB->SetName("fakeRateEB"+postFix);
    fakeRateEE->SetName("fakeRateEE"+postFix);
    bkgvsptEB->SetName("bkgvsptEB"+postFix);
    bkgvsptEE->SetName("bkgvsptEE"+postFix);

    fakeRateEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRateEE->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");

    fakeRatesEB.push_back(fakeRateEB);
    fakeRatesEE.push_back(fakeRateEE);

    bkgVsPtEBVec.push_back(bkgvsptEB);
    bkgVsPtEEVec.push_back(bkgvsptEE);
  }
  
  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitFakeRateProducer, we don't need it open here too

  TString input_filename;
  if (is_data) input_filename = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_vanilla.root";
  if (!is_data) input_filename = "../../MCFakeRateClosureTest/analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  TFile infile(input_filename,"read");
  
  // debug vectors
  std::vector<double> numVec;
  std::vector<double> denomVec;
  
  for (unsigned int j = 0; j < chIsoSidebands.size(); j++) { // loop over sidebands
    for (int i = 0; i < nBins-1; i++) {  // loop over pT bins
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      infile.cd();

      double sidebandLow = chIsoSidebands.at(j).first;
      double sidebandHigh = chIsoSidebands.at(j).second;
      TString postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      
      // run calculation twice, once for EB and once for EE
      std::pair<double,double> resEB = rooFitFakeRateProducer(binName,TString("EB"),chIsoSidebands.at(j),i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      std::pair<double,double> resEE = rooFitFakeRateProducer(binName,TString("EE"),chIsoSidebands.at(j),i+1);

      // record fake rate in TGraphs
      TString histNameEB = TString::Format("PtEB_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TString histNameEE = TString::Format("PtEE_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEB = (TH1D*)infile.Get(histNameEB);
      TH1D* histEE = (TH1D*)infile.Get(histNameEE);

      double denomEB = histEB->Integral();
      double denomEE = histEE->Integral();

      double graphX_EB = histEB->GetMean();
      double graphX_EE = histEE->GetMean();
      double graphY_EB = resEB.first/denomEB; // i.e. the fake rate in the EB
      double graphY_EE = resEE.first/denomEE; // i.e. the fake rate in the EE
      double eXLow_EB = graphX_EB - ptLow;
      double eXHigh_EB = ptHigh - graphX_EB;
      double eXLow_EE = graphX_EE - ptLow;
      double eXHigh_EE = ptHigh - graphX_EE;
      double ey_EB = fakeRateUncertainty(denomEB,resEB.second,graphY_EB);
      double ey_EE = fakeRateUncertainty(denomEE,resEE.second,graphY_EE);
      fakeRatesEB.at(j)->SetPoint(i,graphX_EB,graphY_EB);
      fakeRatesEB.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,ey_EB,ey_EB);
      fakeRatesEE.at(j)->SetPoint(i,graphX_EE,graphY_EE);
      fakeRatesEE.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,ey_EE,ey_EE);

      // fill debug vectors
      if (sidebandLow == 9.) {
        numVec.push_back(resEE.first);
        denomVec.push_back(denomEE);
      }
      
      // record background fit result
      bkgVsPtEBVec.at(j)->SetPoint(i,graphX_EB,resEB.first/ptBinSize);
      bkgVsPtEBVec.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,resEB.second/ptBinSize,resEB.second/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPoint(i,graphX_EE,resEE.first/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);
    } // end loop over pT bins
  } // end loop over sidebands

  infile.cd();
  
  TH1D* denomvsptEB = (TH1D*) infile.Get("phoPtEB_denominator_varbin")->Clone();
  TH1D* denomvsptEE = (TH1D*) infile.Get("phoPtEE_denominator_varbin")->Clone();

  for (int i = 1; i <= nBins-1; i++) {
    double binWidth = denomvsptEB->GetXaxis()->GetBinWidth(i);
    denomvsptEB->SetBinContent(i, denomvsptEB->GetBinContent(i) / binWidth);
    denomvsptEB->SetBinError  (i, denomvsptEB->GetBinError(i) / binWidth);
    denomvsptEE->SetBinContent(i, denomvsptEE->GetBinContent(i) / binWidth);
    denomvsptEE->SetBinError  (i, denomvsptEE->GetBinError(i) / binWidth);
  }
  
  denomvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");
  
  // debug printout to see fake rate ratios
  for (unsigned int i = 0; i < (numVec.size()-1); i++){
    double numratio = numVec.at(i+1) / numVec.at(i);
    double denomratio = denomVec.at(i) / denomVec.at(i+1);
    cout << "EE Debug Info: ptBinLowEdge       n2/n1       d1/d2       FR" << endl;
    cout << ptBinArray[i] << " " << numratio << " " << denomratio << " " << numratio*denomratio << endl;
    cout << " " << endl;
  }

  TFile outfile2("fakeRatePlots.root","update");
  outfile2.cd();
  denomvsptEB->Write();
  denomvsptEE->Write();
  
  for (unsigned int j = 0; j < chIsoSidebands.size(); j++) {
    outfile2.cd();
    double sidebandLow = chIsoSidebands.at(j).first;
    double sidebandHigh = chIsoSidebands.at(j).second;
    TString postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    fakeRatesEB.at(j)->Write();
    fakeRatesEE.at(j)->Write();
    bkgVsPtEBVec.at(j)->Write();
    bkgVsPtEEVec.at(j)->Write();
  
    TCanvas c("c","",1500,600);
    c.Divide(2,1);
    
    c.cd(1);
    fakeRatesEB.at(j)->Draw();
    fakeRatesEB.at(j)->SetTitle("EB");
    fakeRatesEB.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEB.at(j)->GetYaxis()->SetTitleOffset(1.6);
    
    c.cd(2);
    fakeRatesEE.at(j)->Draw();
    fakeRatesEE.at(j)->SetTitle("EE");
    fakeRatesEE.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE.at(j)->GetYaxis()->SetTitleOffset(1.6);
    
    c.SaveAs("fake_rate"+postFix+".pdf");
  }
  
  outfile2.Close();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
