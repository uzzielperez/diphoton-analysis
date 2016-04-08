#include "rooFitFakeRateProducer_pTBinLoop.C"

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate){
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  int ptBinArray[11] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 14000 };
  double ptBinArray_double[11] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 14000. };

  TGraphAsymmErrors fakeRateEB;
  TGraphAsymmErrors fakeRateEE;
  fakeRateEB.SetName("fakeRateEB");
  fakeRateEE.SetName("fakeRateEE");

  TH1D bkgvsptEB("bkgvsptEB","",10,ptBinArray_double);
  TH1D bkgvsptEE("bkgvsptEE","",10,ptBinArray_double);
  bkgvsptEB.GetXaxis()->SetTitle("Photon pT (GeV)");
  bkgvsptEE.GetXaxis()->SetTitle("Photon pT (GeV)");

  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitFakeRateProducer, we don't need it open here too

  std::vector<double> denomBinMeansEB;
  std::vector<double> denomBinMeansEE;
  TFile infile("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms_chIsoSB10To15.root","read"); // we'll want a loop over these guys, just putting in the infrastructure now

  // loop over pT bins
  for (int i = 0; i < 10; i++){
    infile.cd();
    double ptLow = ptBinArray_double[i];
    double ptHigh = ptBinArray_double[i+1];
    TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);
    // run calculation twice, once for EB and once for EE
    std::pair<double,double> resEB = rooFitFakeRateProducer(binName,TString("EB"),i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
    std::pair<double,double> resEE = rooFitFakeRateProducer(binName,TString("EE"),i+1);

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
    fakeRateEB.SetPoint(i,graphX_EB,graphY_EB);
    fakeRateEB.SetPointError(i,eXLow_EB,eXHigh_EB,ey_EB,ey_EB);
    fakeRateEE.SetPoint(i,graphX_EE,graphY_EE);
    fakeRateEE.SetPointError(i,eXLow_EE,eXHigh_EE,ey_EE,ey_EE);

    // record background fit result in TH1Ds
    bkgvsptEB.SetBinContent(i+1,resEB.first);
    bkgvsptEB.SetBinError(i+1,resEB.second);

    bkgvsptEE.SetBinContent(i+1,resEE.first);
    bkgvsptEE.SetBinError(i+1,resEE.second);


  }

  //TFile infile("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","read");
  infile.cd();
  TH1D* denomvsptEB = (TH1D*)infile.Get("phoPtEB_denominator_varbin");
  TH1D* denomvsptEE = (TH1D*)infile.Get("phoPtEE_denominator_varbin");

  denomvsptEB->GetXaxis()->SetTitle("Photon pT (GeV/c)");
  denomvsptEE->GetXaxis()->SetTitle("Photon pT (GeV/c)");

  // TH1D* fakeRateEB = (TH1D*)bkgvsptEB.Clone();
  // TH1D* fakeRateEE = (TH1D*)bkgvsptEE.Clone();

  // fakeRateEB->SetName("fakeRateEB");
  // fakeRateEE->SetName("fakeRateEE");

  // fakeRateEB->Divide(denomvsptEB);
  // fakeRateEE->Divide(denomvsptEE);

  TFile outfile2("fakeRatePlots.root","update");
  outfile2.cd();
  fakeRateEB.Write();
  fakeRateEE.Write();
  bkgvsptEB.Write();
  bkgvsptEE.Write();
  denomvsptEB->Write();
  denomvsptEE->Write();
  outfile2.Close();

  TCanvas c("c","",1200,800);
  fakeRateEB.GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEB.GetYaxis()->SetTitle("Fake Rate");
  fakeRateEB.Draw();
  c.SetLogx();
  c.SaveAs("fakeRateEB.png");

  c.Clear();
  fakeRateEE.GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEE.GetYaxis()->SetTitle("Fake Rate");
  fakeRateEE.GetYaxis()->SetTitleOffset(1.4);
  fakeRateEE.Draw();
  c.SetLogx();
  c.SaveAs("fakeRateEE.png");

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
