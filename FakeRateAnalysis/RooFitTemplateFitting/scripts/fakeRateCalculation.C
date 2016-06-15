#include "rooFitFakeRateProducer_pTBinLoop.C"

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate){
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  int ptBinArray[11] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 600 };
  double ptBinArray_double[11] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  // int ptBinArray[11] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 14000 };
  // double ptBinArray_double[11] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 14.e3 };

  // make vector of sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
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

  for (unsigned int i=0; i<chIsoSidebands.size(); i++){
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

    fakeRateEB->GetXaxis()->SetTitle("Photon pT (GeV)");
    fakeRateEE->GetXaxis()->SetTitle("Photon pT (GeV)");
    bkgvsptEB->GetXaxis()->SetTitle("Photon pT (GeV)");
    bkgvsptEE->GetXaxis()->SetTitle("Photon pT (GeV)");

    fakeRatesEB.push_back(fakeRateEB);
    fakeRatesEE.push_back(fakeRateEE);

    bkgVsPtEBVec.push_back(bkgvsptEB);
    bkgVsPtEEVec.push_back(bkgvsptEE);
  }
  // TGraphAsymmErrors fakeRateEB;
  // TGraphAsymmErrors fakeRateEE;
  // fakeRateEB.SetName("fakeRateEB");
  // fakeRateEE.SetName("fakeRateEE");

  // TH1D bkgvsptEB("bkgvsptEB","",10,ptBinArray_double);
  // TH1D bkgvsptEE("bkgvsptEE","",10,ptBinArray_double);
  // bkgvsptEB.GetXaxis()->SetTitle("Photon pT (GeV)");
  // bkgvsptEE.GetXaxis()->SetTitle("Photon pT (GeV)");

  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitFakeRateProducer, we don't need it open here too

  // for data
  TFile infile("../../DataFakeRateAnalysis/analysis/jetht_matchedtothirdleadingjet.root","read");
  // for MC as data
  // TFile infile("../../MCFakeRateClosureTest/analysis/diphoton_fakeRate_QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root","read");

  // debug vectors
  std::vector<double> numVec;
  std::vector<double> denomVec;
  
  for (unsigned int j=0; j<chIsoSidebands.size(); j++){ // loop over sidebands
    for (int i = 0; i < 10; i++){  // loop over pT bins
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
      //double graphX = (1.*ptBinArray[i] + 1.*ptBinArray[i+1])/2.;
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
      if (sidebandLow == 9.){
        numVec.push_back(resEE.first);
        denomVec.push_back(denomEE);
      }

      // record background fit result


      bkgVsPtEBVec.at(j)->SetPoint(i,graphX_EB,resEB.first/ptBinSize);
      bkgVsPtEBVec.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,resEB.second/ptBinSize,resEB.second/ptBinSize);

      bkgVsPtEEVec.at(j)->SetPoint(i,graphX_EE,resEE.first/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);
      // bkgVsPtEBVec.at(j)->SetBinContent(i+1,resEB.first);
      // bkgVsPtEBVec.at(j)->SetBinError(i+1,resEB.second);

      // bkgVsPtEEVec.at(j)->SetBinContent(i+1,resEE.first);
      // bkgVsPtEEVec.at(j)->SetBinError(i+1,resEE.second);

    } // end loop over pT bins
  } // end loop over sidebands

  //TFile infile("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","read");
  infile.cd();
  TH1D* denomvsptEB = (TH1D*)infile.Get("phoPtEB_denominator_varbin")->Clone();
  TH1D* denomvsptEE = (TH1D*)infile.Get("phoPtEE_denominator_varbin")->Clone();

  for (int i=1; i<=10; i++){
    double binWidth = denomvsptEB->GetXaxis()->GetBinWidth(i);

    denomvsptEB->SetBinContent(i,denomvsptEB->GetBinContent(i) / binWidth);
    denomvsptEB->SetBinError(i,denomvsptEB->GetBinError(i) / binWidth);
    denomvsptEE->SetBinContent(i,denomvsptEE->GetBinContent(i) / binWidth);
    denomvsptEE->SetBinError(i,denomvsptEE->GetBinError(i) / binWidth);

  }

  denomvsptEB->GetXaxis()->SetTitle("Photon pT (GeV/c)");
  denomvsptEE->GetXaxis()->SetTitle("Photon pT (GeV/c)");

  // TH1D* fakeRateEB = (TH1D*)bkgvsptEB.Clone();
  // TH1D* fakeRateEE = (TH1D*)bkgvsptEE.Clone();

  // fakeRateEB->SetName("fakeRateEB");
  // fakeRateEE->SetName("fakeRateEE");

  // fakeRateEB->Divide(denomvsptEB);
  // fakeRateEE->Divide(denomvsptEE);

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
  for (unsigned int j=0; j<chIsoSidebands.size(); j++){
    outfile2.cd();
    double sidebandLow = chIsoSidebands.at(j).first;
    double sidebandHigh = chIsoSidebands.at(j).second;
    TString postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    fakeRatesEB.at(j)->Write();
    fakeRatesEE.at(j)->Write();
    bkgVsPtEBVec.at(j)->Write();
    bkgVsPtEEVec.at(j)->Write();

    TCanvas c("c","",1200,800);
    fakeRatesEB.at(j)->GetXaxis()->SetTitle("Photon pT (GeV/c)");
    fakeRatesEB.at(j)->GetYaxis()->SetTitle("Fake Rate");
    fakeRatesEB.at(j)->Draw();
    c.SetLogx();
    c.SaveAs("fakeRateEB" + postFix + ".png");

    c.Clear();
    fakeRatesEE.at(j)->GetXaxis()->SetTitle("Photon pT (GeV/c)");
    fakeRatesEE.at(j)->GetYaxis()->SetTitle("Fake Rate");
    fakeRatesEE.at(j)->GetYaxis()->SetTitleOffset(1.4);
    fakeRatesEE.at(j)->Draw();
    c.SetLogx();
    c.SaveAs("fakeRateEE" + postFix + ".png");
  }
  outfile2.Close();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
