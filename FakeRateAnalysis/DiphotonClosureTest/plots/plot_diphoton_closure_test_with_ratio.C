void setPlot(TH1D *h1, TH1D *h2, TH1D *h3, TString cat, TString reg){
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
  // h1->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  h1->GetXaxis()->SetRangeUser(0,2000);
  h1->GetYaxis()->SetTitle("Events / 50 GeV");
  h1->GetYaxis()->SetTitleOffset(1.3);
  h1->GetXaxis()->SetTitleOffset(1);
  gPad->SetLogy();
  TLegend *legend = new TLegend(0.50,0.65,0.85,0.85);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(h1,"No fake rate","ep");
  legend->AddEntry(h2,"MC truth","ep");
  legend->AddEntry(h3,"Fake rate applied","ep");
  legend->Draw();
}

void ratioPlot(TH1D *h1, TH1D *h2, TH1D *h3){
  TH1D *hRatio = (TH1D*) h2->Clone("h2");
  hRatio->SetLineColor(kBlack);
  hRatio->SetMarkerColor(kBlack);
  hRatio->SetMinimum(0.01);
  hRatio->SetMaximum(2);
  hRatio->SetStats(0);
  hRatio->Divide(h3);
  hRatio->Draw("ep");
  hRatio->SetTitle("");

  hRatio->GetYaxis()->SetTitle("prediction / truth");
  hRatio->GetYaxis()->SetNdivisions(505);
  hRatio->GetYaxis()->SetTitleSize(14);
  hRatio->GetYaxis()->CenterTitle();
  hRatio->GetYaxis()->SetTitleFont(43);
  hRatio->GetYaxis()->SetTitleOffset(1.3);
  hRatio->GetYaxis()->SetLabelFont(43);
  hRatio->GetYaxis()->SetLabelSize(5);
  hRatio->GetXaxis()->SetTitle("M_{#gamma#gamma} (GeV)");
  hRatio->GetXaxis()->SetTitleSize(0.1);
  hRatio->GetXaxis()->SetTitleOffset(1);

}

void plot_diphoton_closure_test_with_ratio(TString sample="all", TString era="2016") {
  // set global root options
  gROOT->SetStyle("Plain");
  gROOT->SetBatch();
  //gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // input what sample to plot
  // TString sample = "";
  // cout << "Enter sample to plot (QCD, GJets, GGJets, or all): ";
  // cin >> sample;
  // if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
  //   cout << "Invalid choice!" << endl;
  //   return;
  // }
  cout << "\nUsing sample: " << sample << endl;
  std::map<TString, TString> cmssw_version;
  cmssw_version["2016"] = "76X";
  cmssw_version["2017"] = "94X";
  cmssw_version["2018"] = "102X";

  TString templatesBase = "/uscms/home/cuperez/nobackup/tribosons/FakeRate/CMSSW_10_2_18/src/";

  TString filename = "";
  if (sample == "QCD")     filename = templatesBase + "diphoton_fake_rate_diphoton_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")   filename = templatesBase + "diphoton_fake_rate_diphoton_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets")  filename = templatesBase + "diphoton_fake_rate_diphoton_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "all")     filename = templatesBase + "diphoton_fake_rate_diphoton_closure_test_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  cout << "filename: " << filename << endl << endl;

  TFile *f = TFile::Open(filename);

  const TString category[3] = {"TF","FT","FF"};
  const TString region[4] = {"EBEB", "EBEE", "EEEB", "EEEE"};

  for (TString cat : category) {
    TCanvas *c = new TCanvas("c"+cat,"",1500,1000);
    c->Divide(2,2);
    int pos = 1;
    for (TString reg : region) {
      TCanvas *cReg = new TCanvas("c"+cat+"_"+reg, "", 500,500);
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
      h1->GetYaxis()->SetTitleOffset(1.3);
      h1->GetXaxis()->SetTitleOffset(1);
      gPad->SetLogy();
      TLegend *legend = new TLegend(0.50,0.65,0.85,0.85);
      legend->SetBorderSize(0);
      legend->SetFillColor(0);
      legend->AddEntry(h1,"No fake rate","ep");
      legend->AddEntry(h2,"MC truth","ep");
      legend->AddEntry(h3,"Fake rate applied","ep");
      legend->Draw();
      pos++;

      cReg->cd();
      TPad *pad = new TPad("pad", "", 0, 0.3, 1, 1.0);
      pad->SetBottomMargin(0.01);
      pad->Draw();
      pad->cd();
      setPlot(h1, h2, h3, cat, reg);
      // Ratio
      cReg->cd();
      TPad *padRatio = new TPad("padRatio", "", 0, 0, 1, 0.3);
      padRatio->SetTopMargin(0);
      padRatio->SetBottomMargin(0.3);
      padRatio->Draw();
      padRatio->cd();
      padRatio->SetGrid(0, 1);
      ratioPlot(h1, h2, h3);

      cReg->SaveAs("diphoton_"+cat+"_"+reg+"_closure_test"+sample+"withratio"+era+".pdf");
    }
    c->SaveAs("diphoton_"+cat+"_closure_test_"+sample+"withratio"+era+".pdf");
  }

}
