#include "rooFitFakeRateProducer_pTBinLoop.C"

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  int ptBinArray[11] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 14000 };
  double ptBinArray_double[11] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 14000. };

  // TGraphAsymmErrors fakeRateEB;
  // TGraphAsymmErrors fakeRateEE;
  // fakeRateEB.SetName("fakeRateEB");
  // fakeRateEE.SetName("fakeRateEE");

  TH1D bkgvsptEB("bkgvsptEB","",10,ptBinArray_double);
  TH1D bkgvsptEE("bkgvsptEE","",10,ptBinArray_double);
  bkgvsptEB.GetXaxis()->SetTitle("Photon pT (GeV)");
  bkgvsptEE.GetXaxis()->SetTitle("Photon pT (GeV)");

  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close();
  // loop over pT bins
  for (int i = 0; i < 10; i++){
    TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);
    // run calculation twice, once for EB and once for EE
    std::pair<double,double> resEB = rooFitFakeRateProducer_bkgreturn(binName,TString("EB"),i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
    std::pair<double,double> resEE = rooFitFakeRateProducer_bkgreturn(binName,TString("EE"),i+1);

    // record fake rate in TGraphs
    // double graphX = (1.*ptBinArray[i] + 1.*ptBinArray[i+1])/2.;
    // double graphY_EB = resEB.first;
    // double graphY_EE = resEE.first;
    // double ex = (1.*ptBinArray[i+1] - 1.*ptBinArray[i])/2.;
    // double ey_EB = resEB.second;
    // double ey_EE = resEE.second;
    // fakeRateEB.SetPoint(i,graphX,graphY_EB);
    // fakeRateEB.SetPointError(i,ex,ex,ey_EB,ey_EB);
    // fakeRateEE.SetPoint(i,graphX,graphY_EE);
    // fakeRateEE.SetPointError(i,ex,ex,ey_EE,ey_EE);

    // record background fit result in TH1Ds
    bkgvsptEB.SetBinContent(i+1,resEB.first);
    bkgvsptEB.SetBinError(i+1,resEB.second);

    bkgvsptEE.SetBinContent(i+1,resEE.first);
    bkgvsptEE.SetBinError(i+1,resEE.second);
  }

  TFile infile("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","read");
  infile.cd();
  TH1D* denomvsptEB = (TH1D*)infile.Get("phoPtEB_denominator_varbin");
  TH1D* denomvsptEE = (TH1D*)infile.Get("phoPtEE_denominator_varbin");

  denomvsptEB->GetXaxis()->SetTitle("Photon pT (GeV/c)");
  denomvsptEE->GetXaxis()->SetTitle("Photon pT (GeV/c)");

  TH1D* fakeRateEB = (TH1D*)bkgvsptEB.Clone();
  TH1D* fakeRateEE = (TH1D*)bkgvsptEE.Clone();

  fakeRateEB->SetName("fakeRateEB");
  fakeRateEE->SetName("fakeRateEE");

  fakeRateEB->Divide(denomvsptEB);
  fakeRateEE->Divide(denomvsptEE);

  TFile outfile2("fakeRatePlots.root","update");
  outfile2.cd();
  fakeRateEB->Write();
  fakeRateEE->Write();
  bkgvsptEB.Write();
  bkgvsptEE.Write();
  denomvsptEB->Write();
  denomvsptEE->Write();
  outfile2.Close();

  TCanvas c("c","",1200,800);
  fakeRateEB->GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEB->GetYaxis()->SetTitle("Fake Rate");
  fakeRateEB->Draw();
  c.SetLogx();
  c.SaveAs("fakeRateEB.png");

  c.Clear();
  fakeRateEE->GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEE->GetYaxis()->SetTitle("Fake Rate");
  fakeRateEE->GetYaxis()->SetTitleOffset(1.4);
  fakeRateEE->Draw();
  c.SetLogx();
  c.SaveAs("fakeRateEE.png");

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
