
int plot_closure_test_comparison() {
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  TFile *f = TFile::Open("../analysis/diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root");
  TFile *f_truth = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_all_samples_76X_MiniAOD_histograms.root");

  TFile *f_sieie = TFile::Open("../../ClosureTestTemplateFits/fake_rate_sieie_template_fits.root");
  TFile *f_chIso = TFile::Open("../../ClosureTestTemplateFits/fake_rate_chIso_template_fits.root");
  
  // truth fake rate
  TH1D *h_denom_EB = (TH1D*) f->Get("phoPtEB_denominator_varbin");
  TH1D *h_denom_EE = (TH1D*) f->Get("phoPtEE_denominator_varbin");
  TH1D *h_num_EB = (TH1D*) f_truth->Get("phoPtEB_passHighPtID_varbin");
  TH1D *h_num_EE = (TH1D*) f_truth->Get("phoPtEE_passHighPtID_varbin");
  h_num_EB->Divide(h_denom_EB);
  h_num_EE->Divide(h_denom_EE);

  TH1D *h_sieie_EB = (TH1D*) f_sieie->Get("hEBRate_chIso5To10");
  TH1D *h_sieie_EE = (TH1D*) f_sieie->Get("hEERate_chIso5To10");
  TH1D *h_sieie_sb1_EB = (TH1D*) f_sieie->Get("hEBRate_chIso7To12");
  TH1D *h_sieie_sb1_EE = (TH1D*) f_sieie->Get("hEERate_chIso7To12");
  TH1D *h_sieie_sb2_EB = (TH1D*) f_sieie->Get("hEBRate_chIso10To15");
  TH1D *h_sieie_sb2_EE = (TH1D*) f_sieie->Get("hEERate_chIso10To15");
  TH1D *h_sieie_truth_EB = (TH1D*) f_sieie->Get("hEBTruthRate_chIso5To10");
  TH1D *h_sieie_truth_EE = (TH1D*) f_sieie->Get("hEETruthRate_chIso5To10");
  
  TH1D *h_chIso_EB = (TH1D*) f_chIso->Get("hEBRate_sieie0.0105To0.0150");
  TH1D *h_chIso_EE = (TH1D*) f_chIso->Get("hEERate_sieie0.0280To0.0400");
  TH1D *h_chIso_sb1_EB = (TH1D*) f_chIso->Get("hEBRate_sieie0.0105To1.0000");
  TH1D *h_chIso_sb1_EE = (TH1D*) f_chIso->Get("hEERate_sieie0.0280To1.0000");
  TH1D *h_chIso_sb2_EB = (TH1D*) f_chIso->Get("hEBRate_sieie0.0150To0.0200");
  TH1D *h_chIso_sb2_EE = (TH1D*) f_chIso->Get("hEERate_sieie0.0400To0.0600");
  TH1D *h_chIso_truth_EB = (TH1D*) f_chIso->Get("hEBTruthRate_sieie0.0105To0.0150");
  TH1D *h_chIso_truth_EE = (TH1D*) f_chIso->Get("hEETruthRate_sieie0.0280To0.0400");

  // prediction / truth
  h_sieie_EB->Divide(h_num_EB);
  h_sieie_EE->Divide(h_num_EE);
  h_chIso_EB->Divide(h_num_EB);
  h_chIso_EE->Divide(h_num_EE);
  
  TLatex *label = new TLatex();
  label->SetTextAlign(12);

  TLegend *l = new TLegend(0.50,0.70,0.85,0.85);
  l->SetBorderSize(0);
  l->SetFillColor(0);
  TCanvas *c_EB = new TCanvas("c_EB","",800,600);
  h_sieie_EB->Draw();
  h_sieie_EB->SetMarkerColor(kBlue);
  h_sieie_EB->SetLineColor(kBlue); 
  h_sieie_EB->SetTitle(0);
  h_sieie_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_sieie_EB->GetYaxis()->SetTitle("prediction / truth");
  h_sieie_EB->GetYaxis()->SetTitleOffset(1.3);
  h_sieie_EB->GetYaxis()->SetRangeUser(0,2.);
  label->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  // label->DrawLatexNDC(0.40,0.85,"MC truth yield");
  h_chIso_EB->Draw("same");
  h_chIso_EB->SetMarkerColor(kRed);
  h_chIso_EB->SetLineColor(kRed);
  l->AddEntry(h_sieie_EB,"#sigma_{i#etai#eta} templates","ep");
  l->AddEntry(h_chIso_EB,"Iso_{Ch} templates","ep");
  l->Draw();
  c_EB->SaveAs("closure_test_fake_rate_ratio_comparison_EB.pdf");
  TCanvas *c_EE = new TCanvas("c_EE","",800,600);
  h_sieie_EE->Draw();
  h_sieie_EE->SetMarkerColor(kBlue);
  h_sieie_EE->SetLineColor(kBlue); 
  h_sieie_EE->SetTitle(0);
  h_sieie_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_sieie_EE->GetYaxis()->SetTitle("prediction / truth");
  h_sieie_EE->GetYaxis()->SetRangeUser(0,2.);
  h_sieie_EE->GetYaxis()->SetTitleOffset(1.3);
  label->DrawLatexNDC(0.25,0.80,"ECAL endcap");
  // label->DrawLatexNDC(0.40,0.85,"MC truth yield");
  h_chIso_EE->Draw("same");
  h_chIso_EE->SetMarkerColor(kRed);
  h_chIso_EE->SetLineColor(kRed);
  l->Draw();
  c_EE->SaveAs("closure_test_fake_rate_ratio_comparison_EE.pdf");


  TLegend *l_sieie = new TLegend(0.50,0.75,0.85,0.85);
  l_sieie->SetBorderSize(0);
  l_sieie->SetFillColor(0);
  TCanvas *c_sieie_EB = new TCanvas("c_sieie_EB","",800,600);
  h_sieie_EB->Draw();
  h_sieie_EB->SetTitle(0);
  h_sieie_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_sieie_EB->GetYaxis()->SetTitle("prediction / truth");
  h_sieie_EB->GetYaxis()->SetTitleOffset(1.3);
  h_sieie_EB->GetYaxis()->SetRangeUser(0,2.);
  label->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  label->DrawLatexNDC(0.25,0.75,"#sigma_{i#etai#eta} templates");
  l_sieie->AddEntry(h_sieie_EB,"5 < Iso_{Ch} < 10 GeV","ep");
  l_sieie->Draw();
  c_sieie_EB->SaveAs("closure_test_fake_rate_ratio_sieie_EB.pdf");
  TCanvas *c_sieie_EE = new TCanvas("c_sieie_EE","",800,600);
  h_sieie_EE->Draw();
  h_sieie_EE->SetTitle(0);
  h_sieie_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_sieie_EE->GetYaxis()->SetTitle("prediction / truth");
  h_sieie_EE->GetYaxis()->SetRangeUser(0,2.);
  h_sieie_EE->GetYaxis()->SetTitleOffset(1.3);
  label->DrawLatexNDC(0.25,0.80,"ECAL endcap");
  label->DrawLatexNDC(0.25,0.75,"#sigma_{i#etai#eta} templates");
  l_sieie->Draw();
  c_sieie_EE->SaveAs("closure_test_fake_rate_ratio_sieie_EE.pdf");


  
  TLegend *l_chIso_EB = new TLegend(0.50,0.75,0.85,0.85);
  l_chIso_EB->SetBorderSize(0);
  l_chIso_EB->SetFillColor(0);
  TLegend *l_chIso_EE = new TLegend(0.50,0.75,0.85,0.85);
  l_chIso_EE->SetBorderSize(0);
  l_chIso_EE->SetFillColor(0);
  TCanvas *c_chIso_EB = new TCanvas("c_chIso_EB","",800,600);
  h_chIso_EB->Draw();
  h_chIso_EB->SetTitle(0);
  h_chIso_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_chIso_EB->GetYaxis()->SetTitle("prediction / truth");
  h_chIso_EB->GetYaxis()->SetTitleOffset(1.3);
  h_chIso_EB->GetYaxis()->SetRangeUser(0,2.);
  label->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  label->DrawLatexNDC(0.25,0.75,"Iso_{Ch} templates");
  l_chIso_EB->AddEntry(h_chIso_EB,"0.0105 < #sigma_{i#etai#eta} < 0.0150","ep");
  l_chIso_EB->Draw();
  c_chIso_EB->SaveAs("closure_test_fake_rate_ratio_chIso_EB.pdf");
  TCanvas *c_chIso_EE = new TCanvas("c_chIso_EE","",800,600);
  h_chIso_EE->Draw();
  h_chIso_EE->SetTitle(0);
  h_chIso_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_chIso_EE->GetYaxis()->SetTitle("prediction / truth");
  h_chIso_EE->GetYaxis()->SetRangeUser(0,2.);
  h_chIso_EE->GetYaxis()->SetTitleOffset(1.3);
  label->DrawLatexNDC(0.25,0.80,"ECAL endcap");
  label->DrawLatexNDC(0.25,0.75,"Iso_{Ch} templates");
  l_chIso_EE->AddEntry(h_chIso_EB,"0.0280 < #sigma_{i#etai#eta} < 0.0400","ep");
  l_chIso_EE->Draw();
  c_chIso_EE->SaveAs("closure_test_fake_rate_ratio_chIso_EE.pdf");
  
  return 0;
}
