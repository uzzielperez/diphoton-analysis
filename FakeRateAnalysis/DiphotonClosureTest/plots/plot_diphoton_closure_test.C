void plot_diphoton_closure_test() {
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
  
  const TString category[3] = {"TF","FT","FF"};
  const TString region[4] = {"EBEB", "EBEE", "EEEB", "EEEE"};

  for (TString cat : category) {
    TCanvas *c = new TCanvas("c"+cat,"",1500,900);
    c->Divide(2,2);
    int pos = 1;
    for (TString reg : region) {
      c->cd(pos);
      TH1D *h1 = (TH1D*) f->Get(cat+"_diphoton_minv_"+reg);
      TH1D *h2 = (TH1D*) f->Get("TT_"+cat+"_mc_truth_diphoton_minv_"+reg);
      TH1D *h3 = (TH1D*) f->Get(cat+"_diphoton_minv_with_fake_rate_"+reg);
      h1->SetMarkerColor(kBlack);
      h2->SetMarkerColor(kRed);
      h3->SetMarkerColor(kBlue);
      h1->SetLineColor(kBlack);
      h2->SetLineColor(kRed);
      h3->SetLineColor(kBlue);
      h1->Draw();
      h2->Draw("same");
      h3->Draw("same");
      h1->SetTitle(cat+" "+reg);
      h1->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
      h1->GetXaxis()->SetRangeUser(0,2000);
      h1->GetYaxis()->SetTitle("Events / 50 GeV");
      h1->GetXaxis()->SetTitleOffset(1.4);
      gPad->SetLogy();
      TLegend *legend = new TLegend(0.50,0.65,0.85,0.85);
      legend->SetBorderSize(0);
      legend->SetFillColor(0);
      legend->AddEntry(h1,"No fake rate","ep");
      legend->AddEntry(h2,"MC truth","ep");
      legend->AddEntry(h3,"Fake rate applied","ep");
      legend->Draw();
      pos++;
    }
    c->SaveAs("diphoton_"+cat+"_closure_test_"+sample+".pdf");
  }
  
}
