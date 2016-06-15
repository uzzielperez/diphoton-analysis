void plot_diphoton_minv() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat("ourme");
  
  TFile *fData = TFile::Open("../analysis/diphoton_histograms.root");
  
  TH1D *h_diphotonMinv_EBEB = (TH1D*) fData->Get("diphotonMinvEBEB");
  TH1D *h_diphotonMinv_EBEE = (TH1D*) fData->Get("diphotonMinvEBEE");

  TH1D *h_photon1Pt_EBEB = (TH1D*) fData->Get("photon1PtEBEB");
  TH1D *h_photon1Pt_EBEE = (TH1D*) fData->Get("photon1PtEBEE");

  TH1D *h_photon2Pt_EBEB = (TH1D*) fData->Get("photon2PtEBEB");
  TH1D *h_photon2Pt_EBEE = (TH1D*) fData->Get("photon2PtEBEE");
  
  TCanvas *canvas = new TCanvas("canvas","canvas",1500,600);
  canvas->Divide(2,1);

  canvas->cd(1);
  h_diphotonMinv_EBEB->Draw("E1");
  h_diphotonMinv_EBEB->SetTitle("EBEB");
  h_diphotonMinv_EBEB->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  h_diphotonMinv_EBEB->GetXaxis()->SetRangeUser(225.,1600.);
  h_diphotonMinv_EBEB->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_diphotonMinv_EBEB->GetYaxis()->SetTitleOffset(1.4);
  h_diphotonMinv_EBEB->SetMinimum(0.1);
  h_diphotonMinv_EBEB->SetMaximum(500.);
  gPad->SetLogy();

  canvas->cd(2);
  h_diphotonMinv_EBEE->Draw("E1");
  h_diphotonMinv_EBEE->SetTitle("EBEE");
  h_diphotonMinv_EBEE->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  h_diphotonMinv_EBEE->GetXaxis()->SetRangeUser(225.,1600.);
  h_diphotonMinv_EBEE->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_diphotonMinv_EBEE->GetYaxis()->SetTitleOffset(1.4);
  h_diphotonMinv_EBEE->SetMinimum(0.1);
  h_diphotonMinv_EBEE->SetMaximum(200.);
  gPad->SetLogy();

  canvas->SaveAs("diphotonMinv_DoubleEG_Run2015D-16Dec2015-v2_final_selection.png");


  TCanvas *c1_photon1Pt = new TCanvas("c1_photon1Pt","canvas",1500,600);
  c1_photon1Pt->Divide(2,1);

  c1_photon1Pt->cd(1);
  h_photon1Pt_EBEB->Draw("E1");
  h_photon1Pt_EBEB->SetTitle("EBEB");
  h_photon1Pt_EBEB->GetXaxis()->SetTitle("#gamma_{1} p_{T} (GeV)");
  h_photon1Pt_EBEB->GetXaxis()->SetRangeUser(50.,1000.);
  h_photon1Pt_EBEB->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_photon1Pt_EBEB->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  
  c1_photon1Pt->cd(2);
  h_photon1Pt_EBEE->Draw("E1");
  h_photon1Pt_EBEE->SetTitle("EBEE");
  h_photon1Pt_EBEE->GetXaxis()->SetTitle("#gamma_{1} p_{T} (GeV)");
  h_photon1Pt_EBEE->GetXaxis()->SetRangeUser(50.,1000.);
  h_photon1Pt_EBEE->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_photon1Pt_EBEE->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();

  c1_photon1Pt->SaveAs("photon1Pt_DoubleEG_Run2015D-16Dec2015-v2_final_selection.png");


  TCanvas *c1_photon2Pt = new TCanvas("c1_photon2Pt","canvas",1500,600);
  c1_photon2Pt->Divide(2,1);

  c1_photon2Pt->cd(1);
  h_photon2Pt_EBEB->Draw("E1");
  h_photon2Pt_EBEB->SetTitle("EBEB");
  h_photon2Pt_EBEB->GetXaxis()->SetTitle("#gamma_{2} p_{T} (GeV)");
  h_photon2Pt_EBEB->GetXaxis()->SetRangeUser(50.,700.);
  h_photon2Pt_EBEB->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_photon2Pt_EBEB->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  
  c1_photon2Pt->cd(2);
  h_photon2Pt_EBEE->Draw("E1");
  h_photon2Pt_EBEE->SetTitle("EBEE");
  h_photon2Pt_EBEE->GetXaxis()->SetTitle("#gamma_{2} p_{T} (GeV)");
  h_photon2Pt_EBEE->GetXaxis()->SetRangeUser(50.,700.);
  h_photon2Pt_EBEE->GetYaxis()->SetTitle("Events / (20 GeV)");
  h_photon2Pt_EBEE->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();

  c1_photon2Pt->SaveAs("photon2Pt_DoubleEG_Run2015D-16Dec2015-v2_final_selection.png");
}
