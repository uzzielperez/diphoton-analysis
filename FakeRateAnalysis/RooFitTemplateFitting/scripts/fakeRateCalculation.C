#include "rooFitFakeRateProducer_pTBinLoop.C"

void fakeRateCalculation() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  int ptBinArray[17] = { 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 14000 };

  TGraphAsymmErrors fakeRateEB;
  fakeRateEB.SetName("fakeRateEB");

  TFile outfile("fakeRatePlots.root","recreate");
  outfile.Close();
  // loop over pT bins
  for (int i = 0; i < 16; i++){
    if (i == 15) continue; // no 600ToInf real template yet
    TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);
    std::pair<double,double> res = rooFitFakeRateProducer(binName,i+1); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
    cout << "Results: " << res.first << " " << res.second << endl;
    // record fake rate in TGraph
    double graphX = (1.*ptBinArray[i] + 1.*ptBinArray[i+1])/2.;
    double graphY = res.first;
    double ex = (1.*ptBinArray[i+1] - 1.*ptBinArray[i])/2.;
    fakeRateEB.SetPoint(i,graphX,graphY);
    fakeRateEB.SetPointError(i,ex,ex,0.,0.);
  }
  TFile outfile2("fakeRatePlots.root","update");
  outfile2.cd();
  fakeRateEB.Write();
  outfile2.Close();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
