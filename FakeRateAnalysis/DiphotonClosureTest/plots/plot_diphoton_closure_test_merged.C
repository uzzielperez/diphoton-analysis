void plot_diphoton_closure_test_merged() {
  // set global root options
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // input what sample to plot
  TString sample = "";
  cout << "Enter sample to plot (QCD, GJets, GGJets, or all): ";
  cin >> sample;
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;
  
  TString filename = "";
  if (sample == "QCD")     filename = "../analysis/diphoton_fake_rate_diphoton_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")   filename = "../analysis/diphoton_fake_rate_diphoton_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets")  filename = "../analysis/diphoton_fake_rate_diphoton_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")     filename = "../analysis/diphoton_fake_rate_diphoton_closure_test_all_samples_76X_MiniAOD_histograms.root";
  cout << "filename: " << filename << endl << endl;
  
  TFile *f = TFile::Open(filename);

  // merge histograms with fake rate applied
  TH1D *hTF1 = (TH1D*) f->Get("TF_diphoton_minv_with_fake_rate_EBEB");
  TH1D *hTF2 = (TH1D*) f->Get("TF_diphoton_minv_with_fake_rate_EBEE");
  TH1D *hTF3 = (TH1D*) f->Get("TF_diphoton_minv_with_fake_rate_EEEB");
  TH1D *hFT1 = (TH1D*) f->Get("FT_diphoton_minv_with_fake_rate_EBEB");
  TH1D *hFT2 = (TH1D*) f->Get("FT_diphoton_minv_with_fake_rate_EBEE");
  TH1D *hFT3 = (TH1D*) f->Get("FT_diphoton_minv_with_fake_rate_EEEB");
  TH1D *hFF1 = (TH1D*) f->Get("FF_diphoton_minv_with_fake_rate_EBEB");
  TH1D *hFF2 = (TH1D*) f->Get("FF_diphoton_minv_with_fake_rate_EBEE");
  TH1D *hFF3 = (TH1D*) f->Get("FF_diphoton_minv_with_fake_rate_EEEB");
  TH1D *ggjets_EBEB = (TH1D*) hFF1->Clone("ggjets_EBEB");
  TH1D *ggjets_EBEE = (TH1D*) hFF2->Clone("ggjets_EBEE");
  ggjets_EBEE->Add(hFF3);
  TH1D *gjets_EBEB = (TH1D*) hTF1->Clone("gjets_EBEB");
  gjets_EBEB->Add(hFT1);
  gjets_EBEB->Add(ggjets_EBEB,-2);
  TH1D *gjets_EBEE = (TH1D*) hTF2->Clone("gjets_EBEE");
  gjets_EBEE->Add(hTF3);
  gjets_EBEE->Add(hFT2);
  gjets_EBEE->Add(hFT3);
  gjets_EBEE->Add(ggjets_EBEE,-2);
  
  // merge histograms from mc truth
  TH1D *hTF1_truth = (TH1D*) f->Get("TT_TF_mc_truth_diphoton_minv_EBEB");
  TH1D *hTF2_truth = (TH1D*) f->Get("TT_TF_mc_truth_diphoton_minv_EBEE");
  TH1D *hTF3_truth = (TH1D*) f->Get("TT_TF_mc_truth_diphoton_minv_EEEB");
  TH1D *hFT1_truth = (TH1D*) f->Get("TT_FT_mc_truth_diphoton_minv_EBEB");
  TH1D *hFT2_truth = (TH1D*) f->Get("TT_FT_mc_truth_diphoton_minv_EBEE");
  TH1D *hFT3_truth = (TH1D*) f->Get("TT_FT_mc_truth_diphoton_minv_EEEB");
  TH1D *hFF1_truth = (TH1D*) f->Get("TT_FF_mc_truth_diphoton_minv_EBEB");
  TH1D *hFF2_truth = (TH1D*) f->Get("TT_FF_mc_truth_diphoton_minv_EBEE");
  TH1D *hFF3_truth = (TH1D*) f->Get("TT_FF_mc_truth_diphoton_minv_EEEB");
  TH1D *gjets_EBEB_truth = (TH1D*) hTF1_truth->Clone("gjets_EBEB_truth");
  gjets_EBEB_truth->Add(hFT1);
  TH1D *gjets_EBEE_truth = (TH1D*) hTF2_truth->Clone("gjets_EBEE_truth");
  gjets_EBEE_truth->Add(hTF3_truth);
  gjets_EBEE_truth->Add(hFT2_truth);
  gjets_EBEE_truth->Add(hFT3_truth);
  TH1D *ggjets_EBEB_truth = (TH1D*) hFF1_truth->Clone("ggjets_EBEB_truth");
  TH1D *ggjets_EBEE_truth = (TH1D*) hFF2_truth->Clone("ggjets_EBEE_truth");
  ggjets_EBEE_truth->Add(hFF3_truth);

  // gjets
  TCanvas *c_gjets = new TCanvas("c_gjets","",1500,900);
  c_gjets->Divide(2,1);
  c_gjets->cd(1);
  gjets_EBEB->SetMarkerColor(kBlack);
  gjets_EBEB_truth->SetMarkerColor(kRed);
  gjets_EBEB->SetLineColor(kBlack);
  gjets_EBEB_truth->SetLineColor(kRed);
  gjets_EBEB->Draw();
  gjets_EBEB_truth->Draw("same");
  gjets_EBEB->SetTitle("EBEB");
  gjets_EBEB->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  gjets_EBEB->GetXaxis()->SetRangeUser(0,2000);
  gjets_EBEB->GetYaxis()->SetTitle("Events / 50 GeV");
  gjets_EBEB->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  TLegend *l_gjets_EBEB = new TLegend(0.50,0.65,0.85,0.85);
  l_gjets_EBEB->SetBorderSize(0);
  l_gjets_EBEB->SetFillColor(0);
  l_gjets_EBEB->AddEntry(gjets_EBEB,"gjets with fake rate","ep");
  l_gjets_EBEB->AddEntry(gjets_EBEB_truth,"gjets with MC truth","ep");
  l_gjets_EBEB->Draw();
  c_gjets->cd(2);
  gjets_EBEE->SetMarkerColor(kBlack);
  gjets_EBEE_truth->SetMarkerColor(kRed);
  gjets_EBEE->SetLineColor(kBlack);
  gjets_EBEE_truth->SetLineColor(kRed);
  gjets_EBEE->Draw();
  gjets_EBEE_truth->Draw("same");
  gjets_EBEE->SetTitle("EBEE");
  gjets_EBEE->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  gjets_EBEE->GetXaxis()->SetRangeUser(0,2000);
  gjets_EBEE->GetYaxis()->SetTitle("Events / 50 GeV");
  gjets_EBEE->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  TLegend *l_gjets_EBEE = new TLegend(0.50,0.65,0.85,0.85);
  l_gjets_EBEE->SetBorderSize(0);
  l_gjets_EBEE->SetFillColor(0);
  l_gjets_EBEE->AddEntry(gjets_EBEE,"gjets with fake rate","ep");
  l_gjets_EBEE->AddEntry(gjets_EBEE_truth,"gjets with MC truth","ep");
  l_gjets_EBEE->Draw();
  c_gjets->SaveAs("diphoton_gjets_closure_test_"+sample+".pdf");

  // dijet
  TCanvas *c_ggjets = new TCanvas("c_ggjets","",1500,900);
  c_ggjets->Divide(2,1);
  c_ggjets->cd(1);
  ggjets_EBEB->SetMarkerColor(kBlack);
  ggjets_EBEB_truth->SetMarkerColor(kRed);
  ggjets_EBEB->SetLineColor(kBlack);
  ggjets_EBEB_truth->SetLineColor(kRed);
  ggjets_EBEB->Draw();
  ggjets_EBEB_truth->Draw("same");
  ggjets_EBEB->SetTitle("EBEB");
  ggjets_EBEB->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  ggjets_EBEB->GetXaxis()->SetRangeUser(0,2000);
  ggjets_EBEB->GetYaxis()->SetTitle("Events / 50 GeV");
  ggjets_EBEB->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  TLegend *l_ggjets_EBEB = new TLegend(0.50,0.65,0.85,0.85);
  l_ggjets_EBEB->SetBorderSize(0);
  l_ggjets_EBEB->SetFillColor(0);
  l_ggjets_EBEB->AddEntry(ggjets_EBEB,"ggjets with fake rate","ep");
  l_ggjets_EBEB->AddEntry(ggjets_EBEB_truth,"ggjets with MC truth","ep");
  l_ggjets_EBEB->Draw();
  c_ggjets->cd(2);
  ggjets_EBEE->SetMarkerColor(kBlack);
  ggjets_EBEE_truth->SetMarkerColor(kRed);
  ggjets_EBEE->SetLineColor(kBlack);
  ggjets_EBEE_truth->SetLineColor(kRed);
  ggjets_EBEE->Draw();
  ggjets_EBEE_truth->Draw("same");
  ggjets_EBEE->SetTitle("EBEE");
  ggjets_EBEE->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  ggjets_EBEE->GetXaxis()->SetRangeUser(0,2000);
  ggjets_EBEE->GetYaxis()->SetTitle("Events / 50 GeV");
  ggjets_EBEE->GetYaxis()->SetTitleOffset(1.4);
  gPad->SetLogy();
  TLegend *l_ggjets_EBEE = new TLegend(0.50,0.65,0.85,0.85);
  l_ggjets_EBEE->SetBorderSize(0);
  l_ggjets_EBEE->SetFillColor(0);
  l_ggjets_EBEE->AddEntry(ggjets_EBEE,"ggjets with fake rate","ep");
  l_ggjets_EBEE->AddEntry(ggjets_EBEE_truth,"ggjets with MC truth","ep");
  l_ggjets_EBEE->Draw();
  c_ggjets->SaveAs("diphoton_ggjets_closure_test_"+sample+".pdf");  
}
