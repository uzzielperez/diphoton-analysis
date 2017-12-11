int fit_fake_rate() {

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
  
  TFile *f = TFile::Open("fake_rate_sieie_template_fits.root");

  TH1D *hEB = (TH1D*) f->Get("hEBRate_chIso5To10");

  TCanvas *cEB = new TCanvas("cEB","",800,600);

  TF1 *fEB = new TF1("fEB","[0]+[1]/(x^[2])",0.,600.);
  fEB->SetLineColor(kRed);
  fEB->SetParameter(0,0.1);
  fEB->SetParameter(1,1.);
  fEB->SetParameter(2,0.1);

  cout << "\nEB fit" << endl;
  hEB->Fit(fEB);
  cout << "GetChisquare() = " << fEB->GetChisquare() << endl;
  cout << "GetNDF() = " << fEB->GetNDF() << endl;
  cout << "Fit function: [0]+[1]/(x^[2])" << endl;
  cout << "[0] = " << fEB->GetParameter(0) << endl;
  cout << "[1] = " << fEB->GetParameter(1) << endl;
  cout << "[2] = " << fEB->GetParameter(2) << endl;
  cout << endl;

  hEB->Draw();
  hEB->SetStats(1);
  fEB->SetLineColor(kRed);
  cEB->SaveAs("closure_test_fake_rate_fit_chIso5To10_EB.pdf");


  TH1D *hEE = (TH1D*) f->Get("hEERate_chIso5To10");

  TF1 *fEE = new TF1("fEE","[0]+[1]/(x^[2])",0.,600.);
  fEE->SetLineColor(kRed);
  fEE->SetParameter(0,0.1);
  fEE->SetParameter(1,1.);
  fEE->SetParameter(2,0.1);

  TCanvas *cEE = new TCanvas("cEE","",800,600);

  cout << "\nEE fit" << endl;
  hEE->Fit(fEE);
  cout << "GetChisquare() = " << fEE->GetChisquare() << endl;
  cout << "GetNDF() = " << fEE->GetNDF() << endl;
  cout << "Fit function: [0]+[1]/(x^[2])" << endl;
  cout << "[0] = " << fEE->GetParameter(0) << endl;
  cout << "[1] = " << fEE->GetParameter(1) << endl;
  cout << "[2] = " << fEE->GetParameter(2) << endl;
  cout << endl;
  
  hEE->Draw();
  hEE->SetStats(1);
  fEE->SetLineColor(kRed);
  cEE->SaveAs("closure_test_fake_rate_fit_chIso5To10_EE.pdf");
  
  return 0;
}
