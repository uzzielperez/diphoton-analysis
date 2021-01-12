int plot_kinematics_with_etaBin(TFile *f_all, TFile *f_fakes, TFile *f_reweighted, TString name, TString era = "2017"){

  gROOT->SetBatch();
  TCanvas *c = new TCanvas("c", "", 1500, 700);
  c->Divide(2,1);

  TString etaBinned_reweighted_str = "photon_"+name+"_denominator_fake_rate_weighted_gran";
  TString reweighted_str = "photon_"+name+"_denominator_fake_rate_weighted";

  // EB
  TH1D *h_etaBinned_reweighted_EB = (TH1D *) f_reweighted->Get(etaBinned_reweighted_str+"_EB");
  TH1D *h_reweighted_EB = (TH1D *) f_reweighted->Get(reweighted_str+"_EB");
  TH1D *h_fakes_EB = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EB");
  TH1D *h_unweighted_EB = (TH1D *) f_all->Get("photon_"+name+"_denominator_EB");

  // Rebin histograms (from 200 bins to 400)
  if (name == "pt"){
    // h->Rebin() merges 2 bins in one h1
    // https://root.cern.ch/root/html534/TH1.html#TH1:Rebin
    h_etaBinned_reweighted_EB->Rebin();
    h_reweighted_EB->Rebin();
    h_fakes_EB->Rebin();
    h_unweighted_EB->Rebin();
  }

  TLegend *l_EB = new TLegend(0.55, 0.65, 0.85, 0.85);
  l_EB->SetBorderSize(0);
  l_EB->SetFillColor(0);
  if (name == "pt") l_EB->AddEntry(h_unweighted_EB, "Denominator", "ep");
  l_EB->AddEntry(h_fakes_EB, "MC truth", "ep");
  l_EB->AddEntry(h_etaBinned_reweighted_EB, "Fake Prediction (#eta)-binned");
  l_EB->AddEntry(h_reweighted_EB, "Fake Prediction");

  c->cd(1);

  TPad *pad1_EB = new TPad("pad1_EB", "", 0, 0.3, 1, 1.0);
  pad1_EB->SetBottomMargin(0.015);
  pad1_EB->Draw();
  pad1_EB->cd();

  if (name == "pt"){
    h_unweighted_EB->Draw();
    h_unweighted_EB->SetMarkerColor(kBlack);
    h_unweighted_EB->SetLineColor(kBlack);
  }
  h_etaBinned_reweighted_EB->Draw("same");
  h_etaBinned_reweighted_EB->SetMarkerColor(kBlue);
  h_etaBinned_reweighted_EB->SetLineColor(kBlue);
  h_reweighted_EB->Draw("same");
  if (name != "pt"){
    h_reweighted_EB->SetMarkerColor(kBlack);
    h_reweighted_EB->SetLineColor(kBlack);
  }
  else{
    h_reweighted_EB->SetMarkerColor(kGreen);
    h_reweighted_EB->SetLineColor(kGreen);
  }
  h_fakes_EB->Draw("same");
  h_fakes_EB->SetMarkerColor(kRed);
  h_fakes_EB->SetLineColor(kRed);
  h_unweighted_EB->SetTitle("EB");
  h_unweighted_EB->SetMaximum(max(h_unweighted_EB->GetMaximum()*1.5,max(h_etaBinned_reweighted_EB->GetMaximum()*1.5,h_fakes_EB->GetMaximum()*1.5)));
  if (name == "pt") gPad->SetLogy();
  if (name == "eta") h_unweighted_EB->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_unweighted_EB->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_unweighted_EB->SetMinimum(0.);
  l_EB->Draw();

  if (name == "pt"){
    h_unweighted_EB->GetYaxis()->SetLabelSize(16);
    h_unweighted_EB->GetYaxis()->SetLabelFont(43);
    h_unweighted_EB->GetXaxis()->SetLabelSize(16);
    h_unweighted_EB->GetXaxis()->SetLabelFont(0);
  }
  else{
    h_reweighted_EB->GetYaxis()->SetLabelSize(16);
    h_reweighted_EB->GetYaxis()->SetLabelFont(43);
    h_reweighted_EB->GetXaxis()->SetLabelSize(16);
    h_reweighted_EB->GetXaxis()->SetLabelFont(0);
  }


  c->cd(1);

  TPad *pad2_EB = new TPad("pad2_EB","", 0, 0.05, 1, 0.3);
  pad2_EB->SetTopMargin(0);
  pad2_EB->SetBottomMargin(0.4);
  // pad2_EB->SetGridx();
  pad2_EB->Draw();
  pad2_EB->cd();
  pad2_EB->SetGrid(0,1);

  TH1D *h_ratio_EB = (TH1D*) h_reweighted_EB->Clone("h_reweighted_EB");
  if (name=="pt"){
    h_ratio_EB->SetLineColor(kGreen);
    h_ratio_EB->SetMarkerColor(kGreen);
  }
  else {
    h_ratio_EB->SetLineColor(kBlack);
    h_ratio_EB->SetMarkerColor(kBlack);
  }

  h_ratio_EB->SetMinimum(0.4);
  h_ratio_EB->SetMaximum(1.5);
  if (name == "pt") h_ratio_EB->SetMinimum(0);
  //if (name == "pt") h_ratio_EB->SetMaximum(3.5);
  if (name == "pt") h_ratio_EB->SetMaximum(2.0);
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

  TH1D *h_ratio_etaBinned_EB = (TH1D*) h_etaBinned_reweighted_EB->Clone("h_etaBinned_reweighted_EB");
  h_ratio_etaBinned_EB->SetLineColor(kBlue);
  h_ratio_etaBinned_EB->SetMarkerColor(kBlue);
  h_ratio_etaBinned_EB->SetMinimum(0.4);
  h_ratio_etaBinned_EB->SetMaximum(1.3);
  if (name == "pt") h_ratio_etaBinned_EB->SetMinimum(0);
  //if (name == "pt") h_ratio_etaBinned_EB->SetMaximum(3.5);
  if (name == "pt") h_ratio_etaBinned_EB->SetMaximum(2.0);
  h_ratio_etaBinned_EB->SetStats(0);
  h_ratio_etaBinned_EB->Divide(h_fakes_EB);
  // h_ratio_etaBinned_EB->SetMarkerStyle(21);
  h_ratio_etaBinned_EB->Draw("ep, SAME");
  h_ratio_etaBinned_EB->SetTitle("");


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
  TH1D *h_etaBinned_reweighted_EE= (TH1D *) f_reweighted->Get(etaBinned_reweighted_str+"_EE");
  TH1D *h_reweighted_EE = (TH1D *) f_reweighted->Get(reweighted_str+"_EE");
  TH1D *h_fakes_EE = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EE");
  TH1D *h_unweighted_EE = (TH1D *) f_all->Get("photon_"+name+"_denominator_EE");

  TLegend *l_EE = new TLegend(0.55, 0.65, 0.85, 0.85);
  l_EE->SetBorderSize(0);
  l_EE->SetFillColor(0);
  if (name == "pt") l_EE->AddEntry(h_unweighted_EE, "Denominator", "ep");
  l_EE->AddEntry(h_fakes_EE, "MC truth", "ep");
  l_EE->AddEntry(h_etaBinned_reweighted_EE, "Fake Prediction (#eta)-binned");
  l_EE->AddEntry(h_reweighted_EE, "Fake Prediction");

  c->cd(2);

  TPad *pad1_EE = new TPad("pad1_EE", "", 0, 0.3, 1, 1.0);
  pad1_EE->SetBottomMargin(0.015);
  pad1_EE->Draw();
  pad1_EE->cd();

  if (name == "pt"){
    h_unweighted_EE->Draw();
    h_unweighted_EE->SetMarkerColor(kBlack);
    h_unweighted_EE->SetLineColor(kBlack);
  }

  h_etaBinned_reweighted_EE->Draw("same");
  h_etaBinned_reweighted_EE->SetMarkerColor(kBlue);
  h_etaBinned_reweighted_EE->SetLineColor(kBlue);
  h_reweighted_EE->Draw("same");
  if (name == "pt") {
    h_reweighted_EE->SetMarkerColor(kGreen);
    h_reweighted_EE->SetLineColor(kGreen);
  }
  else{
    h_reweighted_EE->SetMarkerColor(kBlack);
    h_reweighted_EE->SetLineColor(kBlack);
  }
  h_fakes_EE->Draw("same");
  h_fakes_EE->SetMarkerColor(kRed);
  h_fakes_EE->SetLineColor(kRed);
  h_unweighted_EE->SetTitle("EE");
  h_unweighted_EE->SetMaximum(max(h_unweighted_EE->GetMaximum()*1.5,max(h_etaBinned_reweighted_EE->GetMaximum()*1.5,h_fakes_EE->GetMaximum()*1.5)));
  if (name == "pt") gPad->SetLogy();
  if (name == "eta") h_unweighted_EE->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_unweighted_EE->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_unweighted_EE->SetMinimum(0.);
  l_EE->Draw();

  if (name == "pt"){
    h_unweighted_EE->GetYaxis()->SetLabelSize(16);
    h_unweighted_EE->GetYaxis()->SetLabelFont(43);
    h_unweighted_EE->GetXaxis()->SetLabelSize(16);
    h_unweighted_EE->GetXaxis()->SetLabelFont(0);
  }
  else{
    h_reweighted_EE->GetYaxis()->SetLabelSize(16);
    h_reweighted_EE->GetYaxis()->SetLabelFont(43);
    h_reweighted_EE->GetXaxis()->SetLabelSize(16);
    h_reweighted_EE->GetXaxis()->SetLabelFont(0);
  }

  c->cd(2);

  TPad *pad2_EE = new TPad("pad2_EE","", 0, 0.05, 1, 0.3);
  pad2_EE->SetTopMargin(0);
  pad2_EE->SetBottomMargin(0.4);
  // pad2_EE->SetGridx();
  pad2_EE->Draw();
  pad2_EE->cd();
  pad2_EE->SetGrid(0,1);

  TH1D *h_ratio_EE = (TH1D*) h_reweighted_EE->Clone("h_reweighted");
  if (name == "pt"){
    h_ratio_EE->SetLineColor(kGreen);
    h_ratio_EE->SetMarkerColor(kGreen);
  }
  else {
    h_ratio_EE->SetLineColor(kBlack);
    h_ratio_EE->SetMarkerColor(kBlack);
  }

  h_ratio_EE->SetMinimum(0.4);
  h_ratio_EE->SetMaximum(1.5);
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

  TH1D *h_ratio_etaBinned_EE = (TH1D*) h_etaBinned_reweighted_EE->Clone("h_etaBinned_reweighted_EE");
  h_ratio_etaBinned_EE->SetLineColor(kBlue);
  h_ratio_etaBinned_EE->SetMarkerColor(kBlue);
  h_ratio_etaBinned_EE->SetMinimum(0.4);
  h_ratio_etaBinned_EE->SetMaximum(1.3);
  if (name == "pt") h_ratio_etaBinned_EE->SetMinimum(0);
  //if (name == "pt") h_ratio_etaBinned_EE->SetMaximum(3.5);
  if (name == "pt") h_ratio_etaBinned_EE->SetMaximum(2.0);
  h_ratio_etaBinned_EE->SetStats(0);
  h_ratio_etaBinned_EE->Divide(h_fakes_EE);
  // h_ratio_etaBinned_EE->SetMarkerStyle(21);
  h_ratio_etaBinned_EE->Draw("ep, SAME");
  h_ratio_etaBinned_EE->SetTitle("");

  if (name == "pt") h_ratio_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
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

  TString outputfilename = "closure_test_photon_kinematics_"+name+"_"+era+"_withEtaBin";
  c->SaveAs(outputfilename+".pdf");

  delete c;

  return 0;
}

int plot_kinematics(TFile *f_all, TFile *f_fakes, TFile *f_reweighted, TString name, TString era = "2016", bool isEtaBinned = true) {

  gROOT->SetBatch();
  TCanvas *c = new TCanvas("c","",1500,700);
  c->Divide(2,1);

  TString reweighted_strname = "photon_"+name+"_denominator_fake_rate_weighted";
  if (isEtaBinned) reweighted_strname = reweighted_strname + "_gran";

  std::cout << "Reweighted Histogram: " << reweighted_strname << std::endl;

  // EB
  TH1D *h_all_EB = (TH1D *) f_reweighted->Get(reweighted_strname+"_EB");
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
  TH1D *h_all_EE = (TH1D *) f_reweighted->Get(reweighted_strname+"_EE");
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

  TString outputfilename = "closure_test_photon_kinematics_"+name+"_"+era;
  if (isEtaBinned) outputfilename = outputfilename + "gran";

  c->SaveAs(outputfilename+".pdf");

  delete c;

  return 0;
}

// compare MC truth kinematics against denominator with and without fake rate applied
int plot_kinematics_sansdenom(TFile *f_all, TFile *f_fakes, TFile *f_reweighted,  TString name, TString era = "2016", bool isEtaBinned=true) {

  gROOT->SetBatch();
  TCanvas *c = new TCanvas("c","",1500,700);
  c->Divide(2,1);

  TString reweighted_strname = "photon_"+name+"_denominator_fake_rate_weighted";
  if (isEtaBinned) reweighted_strname = reweighted_strname + "_gran";

  std::cout << "Reweighted Histogram: " << reweighted_strname << std::endl;

  // EB
  TH1D *h_all_EB = (TH1D *) f_reweighted->Get(reweighted_strname+"_EB");
  TH1D *h_fakes_EB = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EB");

  TLegend *l_EB = new TLegend(0.55,0.65,0.85,0.85);
  l_EB->SetBorderSize(0);
  l_EB->SetFillColor(0);
  l_EB->AddEntry(h_fakes_EB,"MC truth","ep");
  l_EB->AddEntry(h_all_EB,"Fake prediction","ep");

  c->cd(1);

  TPad *pad1_EB = new TPad("pad1_EB","", 0, 0.3, 1, 1.0);
  pad1_EB->SetBottomMargin(0.015);
  // pad1_EB->SetGridx();
  pad1_EB->Draw();
  pad1_EB->cd();

  h_all_EB->Draw();
  h_all_EB->SetMarkerColor(kBlue);
  h_all_EB->SetLineColor(kBlue);
  h_fakes_EB->Draw("same");
  h_fakes_EB->SetMarkerColor(kRed);
  h_fakes_EB->SetLineColor(kRed);
  h_all_EB->SetTitle("EB");
  h_all_EB->SetMaximum(max(h_all_EB->GetMaximum()*1.5,h_fakes_EB->GetMaximum()*1.5));
  if (name == "pt") gPad->SetLogy();
  if (name == "eta") h_all_EB->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_all_EB->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_all_EB->SetMinimum(0.);
  l_EB->Draw();

  h_all_EB->GetYaxis()->SetLabelSize(16);
  h_all_EB->GetYaxis()->SetLabelFont(43);
  h_all_EB->GetXaxis()->SetLabelSize(16);
  h_all_EB->GetXaxis()->SetLabelFont(0);

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
  TH1D *h_all_EE = (TH1D *) f_reweighted->Get(reweighted_strname+"_EE");
  TH1D *h_fakes_EE = (TH1D *) f_fakes->Get("photon_fakes_"+name+"_EE");
  TLegend *l_EE = new TLegend(0.55,0.65,0.85,0.85);
  l_EE->SetBorderSize(0);
  l_EE->SetFillColor(0);
  l_EE->AddEntry(h_fakes_EE,"MC truth","ep");
  l_EE->AddEntry(h_all_EE,"Fake prediction","ep");

  c->cd(2);

  TPad *pad1_EE = new TPad("pad1_EE","", 0, 0.3, 1, 1.0);
  pad1_EE->SetBottomMargin(0.015);
  // pad1_EE->SetGridx();
  pad1_EE->Draw();
  pad1_EE->cd();

  h_all_EE->Draw("same");
  h_all_EE->SetMarkerColor(kBlue);
  h_all_EE->SetLineColor(kBlue);
  h_fakes_EE->Draw("same");
  h_fakes_EE->SetMarkerColor(kRed);
  h_fakes_EE->SetLineColor(kRed);
  h_all_EE->SetTitle("EE");
  h_all_EE->SetMaximum(max(h_all_EE->GetMaximum()*1.5,h_fakes_EE->GetMaximum()*1.5));
  if (name == "pt") {
    h_all_EE->GetXaxis()->SetRangeUser(0,1500);
    gPad->SetLogy();
  }
  if (name == "eta") h_all_EE->GetXaxis()->SetRangeUser(-3,3);
  if (name == "phi") h_all_EE->GetXaxis()->SetRangeUser(-4,4);
  if (name == "phi" || name == "eta") h_all_EE->SetMinimum(0.);
  l_EE->Draw();

  h_all_EE->GetYaxis()->SetLabelSize(16);
  h_all_EE->GetYaxis()->SetLabelFont(43);
  h_all_EE->GetXaxis()->SetLabelSize(16);
  h_all_EE->GetXaxis()->SetLabelFont(0);

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

  TString outputfilename = "closure_test_photon_kinematics_"+name+"_"+era;
  if (isEtaBinned) outputfilename = outputfilename + "gran";

  c->SaveAs(outputfilename+"sans_Denom.pdf");

  delete c;

  return 0;
}

void plot_kinematics_with_ratio(TString sample =  "all", TString era= "2017") {
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

  TString base = "/uscms/home/cuperez/nobackup/tribosons/FakeRate/FakeRate/CMSSW_10_2_18/src/";
  TString basetruth = "/uscms/home/cuperez/nobackup/tribosons/FakeRate/FakeRate/CMSSW_10_2_18/src/";

  TString filename = "";
  if (sample == "QCD")    filename = base + "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = base + "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = base + "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "all")    filename = base + "diphoton_fake_rate_closure_test_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";

  cout << "filename: " << filename << endl;
  TFile *f_closure_test = TFile::Open(filename);

  TString filename_truth = "";
  if (sample == "QCD")    filename_truth = basetruth + "diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GJets")  filename_truth = basetruth + "diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "GGJets") filename_truth = basetruth + "diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  //if (sample == "all")    filename_truth basetruth + = "diphoton_fake_rate_closure_test_matching_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";
  if (sample == "all")    filename_truth = basetruth + "diphoton_fake_rate_closure_test_matching_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms.root";

  cout << "filename for mc truth: " << filename_truth << endl;
  TFile *f_closure_test_matching = TFile::Open(filename_truth);

  TString filename_reweighted = "";
  if (sample == "QCD")    filename_reweighted = base + "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_"+cmssw_version[era]+"_MiniAOD_histograms_reweighted.root";
  if (sample == "GJets")  filename_reweighted = base + "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+cmssw_version[era]+"_MiniAOD_histograms_reweighted.root";
  if (sample == "GGJets") filename_reweighted = base + "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_"+cmssw_version[era]+"_MiniAOD_histograms_reweighted.root";
  if (sample == "all")    filename_reweighted = base + "diphoton_fake_rate_closure_test_all_samples_"+cmssw_version[era]+"_MiniAOD_histograms_reweighted.root";

  cout << "filename_reweighted: " << filename_reweighted << endl;
  TFile *f_reweighted = TFile::Open(filename_reweighted);

  // No eta-binning
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "pt",era);
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "eta",era);
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "phi",era);

  plot_kinematics_sansdenom(f_closure_test,f_closure_test_matching, f_reweighted, "eta",era);
  plot_kinematics_sansdenom(f_closure_test,f_closure_test_matching, f_reweighted, "phi",era);

  // Eta-binning only
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "pt",era, false);
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "eta",era, false);
  plot_kinematics(f_closure_test,f_closure_test_matching, f_reweighted, "phi",era, false);

  plot_kinematics_sansdenom(f_closure_test,f_closure_test_matching, f_reweighted, "eta",era, false);
  plot_kinematics_sansdenom(f_closure_test,f_closure_test_matching, f_reweighted, "phi",era, false);

  // With Eta-binning
  plot_kinematics_with_etaBin(f_closure_test,f_closure_test_matching, f_reweighted, "pt",era);
  plot_kinematics_with_etaBin(f_closure_test,f_closure_test_matching, f_reweighted, "eta",era);
  plot_kinematics_with_etaBin(f_closure_test,f_closure_test_matching, f_reweighted, "phi",era);

}
