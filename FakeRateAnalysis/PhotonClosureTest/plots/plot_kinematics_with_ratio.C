// compare MC truth kinematics against denominator with and without fake rate applied
int plot_kinematics(TFile *f_all, TFile *f_fakes, TString name, TString era = "2016") {

  gROOT->SetBatch();
  TCanvas *c = new TCanvas("c","",1500,700);
  c->Divide(2,1);

  // EB
  TH1D *h_all_EB = (TH1D *) f_all->Get("photon_"+name+"_denominator_fake_rate_weighted_EB");
  TH1D *h_fakes_EB = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EB");
  TH1D *h_unweighted_EB = (TH1D *) f_all->Get("photon_"+name+"_denominator_EB");
  TLegend *l_EB = new TLegend(0.55,0.65,0.85,0.85);
  l_EB->SetBorderSize(0);
  l_EB->SetFillColor(0);
  l_EB->AddEntry(h_unweighted_EB,"Denominator","ep");
  l_EB->AddEntry(h_fakes_EB,"MC truth","ep");
  l_EB->AddEntry(h_all_EB,"Fake prediction","ep");

  c->cd(1);

  TPad *pad1_EB = new TPad("pad1_EB","", 0, 0.3, 1, 1.0);
  pad1_EB->SetBottomMargin(0.015);
  // pad1_EB->SetGridx();
  pad1_EB->Draw();
  pad1_EB->cd();

  h_unweighted_EB->Draw();
  h_unweighted_EB->SetMarkerColor(kBlack);
  h_unweighted_EB->SetLineColor(kBlack);
  h_all_EB->Draw("same");
  h_all_EB->SetMarkerColor(kBlue);
  h_all_EB->SetLineColor(kBlue);
  h_fakes_EB->Draw("same");
  h_fakes_EB->SetMarkerColor(kRed);
  h_fakes_EB->SetLineColor(kRed);
  h_unweighted_EB->SetTitle("EB");
  h_unweighted_EB->SetMaximum(max(h_unweighted_EB->GetMaximum()*1.5,max(h_all_EB->GetMaximum()*1.5,h_fakes_EB->GetMaximum()*1.5)));
  if (name == "pt") gPad->SetLogy();
  if (name == "eta") h_unweighted_EB->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_unweighted_EB->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_unweighted_EB->SetMinimum(0.);
  l_EB->Draw();

  h_unweighted_EB->GetYaxis()->SetLabelSize(16);
  h_unweighted_EB->GetYaxis()->SetLabelFont(43);
  h_unweighted_EB->GetXaxis()->SetLabelSize(16);
  h_unweighted_EB->GetXaxis()->SetLabelFont(0);

  c->cd(1);

  TPad *pad2_EB = new TPad("pad2_EB","", 0, 0.05, 1, 0.3);
  pad2_EB->SetTopMargin(0);
  pad2_EB->SetBottomMargin(0.4);
  // pad2_EB->SetGridx();
  pad2_EB->Draw();
  pad2_EB->cd();
  pad2_EB->SetGrid(0,1);

  TH1D *h_ratio_EB = (TH1D*) h_all_EB->Clone("h_all_EB");
  h_ratio_EB->SetLineColor(kBlack);
  h_ratio_EB->SetMarkerColor(kBlack);
  h_ratio_EB->SetMinimum(0.4);
  h_ratio_EB->SetMaximum(1.3);
  if (name == "pt") h_ratio_EB->SetMinimum(0);
  if (name == "pt") h_ratio_EB->SetMaximum(3.5);
  h_ratio_EB->SetStats(0);
  h_ratio_EB->Divide(h_fakes_EB);
  // h_ratio_EB->SetMarkerStyle(21);
  h_ratio_EB->Draw("ep");
  h_ratio_EB->SetTitle("");

  h_ratio_EB->GetYaxis()->SetTitle("prediction / truth");
  h_ratio_EB->GetYaxis()->SetNdivisions(505);
  h_ratio_EB->GetYaxis()->SetTitleSize(14);
  h_ratio_EB->GetYaxis()->CenterTitle();
  h_ratio_EB->GetYaxis()->SetTitleFont(43);
  h_ratio_EB->GetYaxis()->SetTitleOffset(1.55);
  h_ratio_EB->GetYaxis()->SetLabelFont(43);
  h_ratio_EB->GetYaxis()->SetLabelSize(16);

  if (name == "pt") h_ratio_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  if (name == "eta") {
    h_ratio_EB->GetXaxis()->SetTitle("#eta");
    h_ratio_EB->GetXaxis()->SetRangeUser(-3,3);
  }
  if (name == "phi") {
    h_ratio_EB->GetXaxis()->SetTitle("#phi");
    h_ratio_EB->GetXaxis()->SetRangeUser(-4,4);
  }
  if (name == "phi" || name == "eta") h_ratio_EB->GetXaxis()->CenterTitle();
  h_ratio_EB->GetXaxis()->SetTitleSize(25);
  h_ratio_EB->GetXaxis()->SetTitleFont(43);
  h_ratio_EB->GetXaxis()->SetTitleOffset(4.5);
  h_ratio_EB->GetXaxis()->SetLabelFont(43);
  h_ratio_EB->GetXaxis()->SetLabelSize(16);


  // EE
  TH1D *h_all_EE = (TH1D *) f_all->Get("photon_"+name+"_denominator_fake_rate_weighted_EE");
  TH1D *h_fakes_EE = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EE");
  TH1D *h_unweighted_EE = (TH1D *) f_all->Get("photon_"+name+"_denominator_EE");
  TLegend *l_EE = new TLegend(0.55,0.65,0.85,0.85);
  l_EE->SetBorderSize(0);
  l_EE->SetFillColor(0);
  l_EE->AddEntry(h_unweighted_EE,"Denominator","ep");
  l_EE->AddEntry(h_fakes_EE,"MC truth","ep");
  l_EE->AddEntry(h_all_EE,"Fake prediction","ep");

  c->cd(2);

  TPad *pad1_EE = new TPad("pad1_EE","", 0, 0.3, 1, 1.0);
  pad1_EE->SetBottomMargin(0.015);
  // pad1_EE->SetGridx();
  pad1_EE->Draw();
  pad1_EE->cd();

  h_unweighted_EE->Draw();
  h_unweighted_EE->SetMarkerColor(kBlack);
  h_unweighted_EE->SetLineColor(kBlack);
  h_all_EE->Draw("same");
  h_all_EE->SetMarkerColor(kBlue);
  h_all_EE->SetLineColor(kBlue);
  h_fakes_EE->Draw("same");
  h_fakes_EE->SetMarkerColor(kRed);
  h_fakes_EE->SetLineColor(kRed);
  h_unweighted_EE->SetTitle("EE");
  h_unweighted_EE->SetMaximum(max(h_unweighted_EE->GetMaximum()*1.5,max(h_all_EE->GetMaximum()*1.5,h_fakes_EE->GetMaximum()*1.5)));
  if (name == "pt") {
    h_unweighted_EE->GetXaxis()->SetRangeUser(0,1500);
    gPad->SetLogy();
  }
  if (name == "eta") h_unweighted_EE->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_unweighted_EE->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_unweighted_EE->SetMinimum(0.);
  l_EE->Draw();

  h_unweighted_EE->GetYaxis()->SetLabelSize(16);
  h_unweighted_EE->GetYaxis()->SetLabelFont(43);
  h_unweighted_EE->GetXaxis()->SetLabelSize(16);
  h_unweighted_EE->GetXaxis()->SetLabelFont(0);

  c->cd(2);

  TPad *pad2_EE = new TPad("pad2_EE","", 0, 0.05, 1, 0.3);
  pad2_EE->SetTopMargin(0);
  pad2_EE->SetBottomMargin(0.4);
  // pad2_EE->SetGridx();
  pad2_EE->Draw();
  pad2_EE->cd();
  pad2_EE->SetGrid(0,1);

  TH1D *h_ratio_EE = (TH1D*) h_all_EE->Clone("h_all_EE");
  h_ratio_EE->SetLineColor(kBlack);
  h_ratio_EE->SetMarkerColor(kBlack);
  h_ratio_EE->SetMinimum(0.4);
  h_ratio_EE->SetMaximum(1.1);
  if (name == "pt") h_ratio_EE->SetMinimum(0);
  if (name == "pt") h_ratio_EE->SetMaximum(3.5);
  h_ratio_EE->SetStats(0);
  h_ratio_EE->Divide(h_fakes_EE);
  // h_ratio_EE->SetMarkerStyle(21);
  h_ratio_EE->Draw("ep");
  h_ratio_EE->SetTitle("");

  h_ratio_EE->GetYaxis()->SetTitle("prediction / truth");
  h_ratio_EE->GetYaxis()->SetNdivisions(505);
  h_ratio_EE->GetYaxis()->SetTitleSize(14);
  h_ratio_EE->GetYaxis()->CenterTitle();
  h_ratio_EE->GetYaxis()->SetTitleFont(43);
  h_ratio_EE->GetYaxis()->SetTitleOffset(1.55);
  h_ratio_EE->GetYaxis()->SetLabelFont(43);
  h_ratio_EE->GetYaxis()->SetLabelSize(16);

  if (name == "pt") {
    h_ratio_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
    h_ratio_EE->GetXaxis()->SetRangeUser(0,1500);
  }
  if (name == "eta") {
    h_ratio_EE->GetXaxis()->SetTitle("#eta");
    h_ratio_EE->GetXaxis()->SetRangeUser(-3,3);
  }
  if (name == "phi") {
    h_ratio_EE->GetXaxis()->SetTitle("#phi");
    h_ratio_EE->GetXaxis()->SetRangeUser(-4,4);
  }
  if (name == "phi" || name == "eta") h_ratio_EE->GetXaxis()->CenterTitle();
  h_ratio_EE->GetXaxis()->SetTitleSize(25);
  h_ratio_EE->GetXaxis()->SetTitleFont(43);
  h_ratio_EE->GetXaxis()->SetTitleOffset(4.5);
  h_ratio_EE->GetXaxis()->SetLabelFont(43);
  h_ratio_EE->GetXaxis()->SetLabelSize(16);


  c->SaveAs("closure_test_photon_kinematics_"+name+"_"+era+".pdf");

  delete c;

  return 0;
}

void plot_kinematics_with_ratio(TString sample =  "all", TString era= "2016") {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // input what sample to plot
  // TString sample = "";
  // cout << "Enter sample to plot (QCD, GJets, GGJets, or all): ";
  // cin >> sample;
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "Using sample: " << sample << endl;

  std::map<TString, TString> cmssw_version;
  cmssw_version["2016"] = "76X";
  cmssw_version["2017"] = "94X";
  cmssw_version["2018"] = "102X";

  TString base = "/uscms/home/cuperez/nobackup/tribosons/FakeRate/CMSSW_10_2_18/src/";

  TString filename = "";
  if (sample == "QCD")    filename = base + "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = base + "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = base + "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "all")    filename = base + "diphoton_fake_rate_closure_test_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";

  cout << "filename: " << filename << endl;
  TFile *f_closure_test = TFile::Open(filename);

  TString filename_truth = "";
  if (sample == "QCD")    filename_truth = base + "diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")  filename_truth = base + "diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets") filename_truth = base + "diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  //if (sample == "all")    filename_truth base + = "diphoton_fake_rate_closure_test_matching_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "all")    filename_truth = base + "diphoton_fake_rate_closure_test_matching_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";

  cout << "filename for mc truth: " << filename_truth << endl;
  TFile *f_closure_test_matching = TFile::Open(filename_truth);

  plot_kinematics(f_closure_test,f_closure_test_matching,"pt",era);
  plot_kinematics(f_closure_test,f_closure_test_matching,"eta",era);
  plot_kinematics(f_closure_test,f_closure_test_matching,"phi",era);
}
