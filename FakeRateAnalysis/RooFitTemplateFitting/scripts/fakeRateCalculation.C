#include "rooFitFakeRateProducer_pTBinLoop.C"

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  int ptBinArray[11] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 14000 };

  TGraphAsymmErrors fakeRateEB;
  TGraphAsymmErrors fakeRateEE;
  fakeRateEB.SetName("fakeRateEB");
  fakeRateEE.SetName("fakeRateEE");

  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close();
  // loop over pT bins
  for (int i = 0; i < 10; i++){
    // if (i == 15) continue; // no 600ToInf real template yet
    TString binName = "300ToInf";
    if (i < 9) binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);
    // run calculation twice, once for EB and once for EE
    std::pair<double,double> resEB = rooFitFakeRateProducer(binName,TString("EB"),i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
    std::pair<double,double> resEE = rooFitFakeRateProducer(binName,TString("EE"),i+1);

    // record fake rate in TGraphs
    double graphX = (1.*ptBinArray[i] + 1.*ptBinArray[i+1])/2.;
    double graphY_EB = resEB.first;
    double graphY_EE = resEE.first;
    double ex = (1.*ptBinArray[i+1] - 1.*ptBinArray[i])/2.;
    double ey_EB = resEB.second;
    double ey_EE = resEE.second;
    fakeRateEB.SetPoint(i,graphX,graphY_EB);
    fakeRateEB.SetPointError(i,ex,ex,ey_EB,ey_EB);
    fakeRateEE.SetPoint(i,graphX,graphY_EE);
    fakeRateEE.SetPointError(i,ex,ex,ey_EE,ey_EE);
  }
  TFile outfile2("fakeRatePlots.root","update");
  outfile2.cd();
  fakeRateEB.Write();
  fakeRateEE.Write();
  outfile2.Close();

  TCanvas c("c","",1200,800);
  fakeRateEB.Draw("AL");
  fakeRateEB.GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEB.GetYaxis()->SetTitle("Fake Rate");
  fakeRateEB.Draw("AL");
  c.SetLogx();
  c.SaveAs("fakeRateEB.png");

  c.Clear();
  fakeRateEE.Draw("AL");
  fakeRateEE.GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEE.GetYaxis()->SetTitle("Fake Rate");
  fakeRateEE.GetYaxis()->SetTitleOffset(1.4);
  fakeRateEE.Draw("AL");
  c.SetLogx();
  c.SaveAs("fakeRateEE.png");

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
