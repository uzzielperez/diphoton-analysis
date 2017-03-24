void plot_fake_rate_from_matching() {
  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // get files
  TFile *f_all = TFile::Open("../analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *f_matching = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

  // get denominator
  TH1D *h_denom_EB = (TH1D*) f_all->Get("phoPtEB_denominator_varbin");
  TH1D *h_denom_EE = (TH1D*) f_all->Get("phoPtEE_denominator_varbin");

  // get "numerator" - use matched fakes as numerator
  //
  // all fakes
  TH1D *h_num_EB = (TH1D*) f_matching->Get("phoPtEB_passHighPtID_varbin");
  TH1D *h_num_EE = (TH1D*) f_matching->Get("phoPtEE_passHighPtID_varbin");
  // quark fakes
  TH1D *h_quark_num_EB = (TH1D*) f_matching->Get("phoPtEB_quark_passHighPtID_varbin");
  TH1D *h_quark_num_EE = (TH1D*) f_matching->Get("phoPtEE_quark_passHighPtID_varbin");
  // gluon fakes
  TH1D *h_gluon_num_EB = (TH1D*) f_matching->Get("phoPtEB_gluon_passHighPtID_varbin");
  TH1D *h_gluon_num_EE = (TH1D*) f_matching->Get("phoPtEE_gluon_passHighPtID_varbin");

  // normalize to unity
  // h_num_EB->Scale(1.0/h_num_EB->Integral());
  // h_num_EE->Scale(1.0/h_num_EE->Integral());
  // h_quark_num_EB->Scale(1.0/h_quark_num_EB->Integral());
  // h_quark_num_EE->Scale(1.0/h_quark_num_EE->Integral());
  // h_gluon_num_EB->Scale(1.0/h_gluon_num_EB->Integral());
  // h_gluon_num_EE->Scale(1.0/h_gluon_num_EE->Integral());
  
  // form fake rates -- fake rates plotted at bin centers, not mean pT of each pT bin
  h_num_EB->Divide(h_denom_EB);
  h_num_EE->Divide(h_denom_EE);
  h_quark_num_EB->Divide(h_denom_EB);
  h_quark_num_EE->Divide(h_denom_EE);
  h_gluon_num_EB->Divide(h_denom_EB);
  h_gluon_num_EE->Divide(h_denom_EE);

  TLegend *legend = new TLegend(0.55,0.65,0.85,0.85);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(h_num_EB,"All fakes","ep");
  legend->AddEntry(h_quark_num_EB,"Quark fakes","ep");
  legend->AddEntry(h_gluon_num_EB,"Gluon fakes","ep");
  
  TCanvas *c_all = new TCanvas("c_all","",1500,700);
  c_all->Divide(2,1);
  c_all->cd(1);
  h_num_EB->Draw();
  h_quark_num_EB->Draw("same");
  h_gluon_num_EB->Draw("same");
  h_quark_num_EB->SetMarkerColor(kRed);
  h_gluon_num_EB->SetMarkerColor(kBlue);
  h_num_EB->GetYaxis()->SetRangeUser(0.,0.2);
  h_num_EB->SetTitle("EB");
  h_num_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  legend->Draw();
  //gPad->SetLogy();
  c_all->cd(2);
  h_num_EE->Draw();
  h_quark_num_EE->Draw("same");
  h_gluon_num_EE->Draw("same");
  h_quark_num_EE->SetMarkerColor(kRed);
  h_gluon_num_EE->SetMarkerColor(kBlue);
  h_num_EE->GetYaxis()->SetRangeUser(0.,0.2);
  h_num_EE->SetTitle("EB");
  h_num_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  legend->Draw();
  //gPad->SetLogy();
  c_all->SaveAs("fake_rate_using_matched_fakes.png");
  
}
