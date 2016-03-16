#include "rooFitFakeRateProducer_pTBinLoop.C"

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  std::string ptBins[16] = { "30To50","50To70","70To90","90To110","110To130","130To150","150To200","200To250","250To300","300To350","350To400","400To450","450To500","500To550","550To600","600ToInf" };
  double ptBinArray[17] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 350., 400., 450., 500., 550., 600., 14.e3 };

  TGraphAsymmErrors fakeRateEB;
  fakeRateEB.SetName("fakeRateEB");
  fakeRateEB.GetXaxis()->SetTitle("Photon pT (GeV/c)");
  fakeRateEB.GetYaxis()->SetTitle("Fake Rate");
  // loop over pT bins
  for (int i = 0; i < 16; i++){
    if (i == 15) continue; // no 600ToInf real template yet
    std::pair<double,double> res = rooFitFakeRateProducer(ptBins[i],i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
    cout << "Results: " << res.first << " " << res.second << endl;
    // record fake rate in TGraph
    double graphX = (ptBinArray[i] + ptBinArray[i+1])/2.;
    double graphY = res.first;
    double ex = (ptBinArray[i+1] - ptBinArray[i])/2.;
    fakeRateEB.SetPoint(i,graphX,graphY);
    fakeRateEB.SetPointError(i,ex,ex,0.,0.);
  }
  TFile outfile("fakeRatePlots.root","recreate");
  outfile.cd();
  fakeRateEB.Write();
  outfile.Close();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
