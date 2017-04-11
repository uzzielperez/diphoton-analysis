// to run:
// root -l -q -b plot_overlay_sieie_templates.C

void plot_overlay_chIso_truth_fake_templates() {
  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
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
  cout << "Using sample: " << sample << endl;
  
  TString filename = "";
  if (sample == "QCD")    filename = "../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = "../analysis/diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = "../analysis/diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    filename = "../analysis/diphoton_fake_rate_closure_test_matching_all_samples_76X_MiniAOD_histograms.root";
  cout << "filename: " << filename << endl;
  
  TFile *f = TFile::Open(filename);
  
  // pt bins
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  TCanvas *c = new TCanvas("c_","",1500,900);
  c->Divide(2,1);

  TLegend *legend = new TLegend(0.55,0.65,0.85,0.85);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  
  int j = 0;
  
  // loop over pt bins
  for (int i = 0; i < nBins-1; ++i) {
    
    TString bin = Form("%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    if (bin != "50To70" && bin != "110To130" && bin != "200To250" && bin != "300To600") continue;
    
    TString label = bin;
    label.ReplaceAll("To"," < p_{T} < ");
    label += " GeV";
    
    // EB
    c->cd(1);
    TH1D *h_EB = (TH1D*) f->Get("chIsoEB_numerator_fakes_pt"+bin);
    h_EB->Scale(1.0/h_EB->Integral());
    legend->AddEntry(h_EB,label,"ep");
    if (j == 0) h_EB->Draw("HIST");
    else {
      h_EB->Draw("HISTsame");
      h_EB->SetMarkerColor(1+j);
      h_EB->SetLineColor(1+j);
    }
    h_EB->SetTitle("EB - MC truth");
    h_EB->GetXaxis()->SetTitle("Iso_{ch} (GeV)");
    h_EB->GetXaxis()->SetRangeUser(0,50.);
    h_EB->GetYaxis()->SetTitle("Events / ( "+(TString)Form("%.1f GeV",h_EB->GetBinWidth(2))+" )");
    h_EB->GetYaxis()->SetRangeUser(10e-4,10e-1);
    h_EB->GetYaxis()->SetTitleOffset(1.6);
    legend->Draw();
    gPad->SetLogy();

    // EE
    c->cd(2);
    TH1D *h_EE = (TH1D*) f->Get("chIsoEE_numerator_fakes_pt"+bin);
    h_EE->Scale(1.0/h_EE->Integral());
    if (j == 0) h_EE->Draw("HIST");
    else {
      h_EE->Draw("HISTsame");
      h_EE->SetMarkerColor(1+j);
      h_EE->SetLineColor(1+j);
    }
    h_EE->SetTitle("EE - MC truth");
    h_EE->GetXaxis()->SetTitle("Iso_{ch} (GeV)");
    h_EE->GetXaxis()->SetRangeUser(0,50.);
    h_EE->GetYaxis()->SetTitle("Events / ( "+(TString)Form("%.1f GeV",h_EE->GetBinWidth(2))+" )");
    h_EE->GetYaxis()->SetRangeUser(10e-4,10e-1);
    h_EE->GetYaxis()->SetTitleOffset(1.6);
    legend->Draw();
    gPad->SetLogy();

    j++;
  } // end for loop over pt bins

  c->SaveAs("fake_templates_chIso_mc_truth_overlaid_sample_"+sample+".pdf");
  
}
