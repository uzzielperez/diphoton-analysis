void plot_GGJets_GJets_comparison() {

  // set global root options
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // get real template files
  TFile *f_ggjets = TFile::Open("../analysis/diphoton_fake_rate_real_templates_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  TFile *f_gjets = TFile::Open("../analysis/diphoton_fake_rate_real_templates_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root");
  
  // pt bins
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // loop over pt bins
  for (int i = 0; i < nBins-1; ++i) {
    
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    TCanvas *c = new TCanvas("c_"+bin,"",1500,900);
    c->Divide(2,2);
    
    // EB - linear
    c->cd(1);
    TH1D *h_ggjets_EB = (TH1D*) f_ggjets->Get("sieieEB_realtemplate_"+bin);
    TH1D *h_gjets_EB = (TH1D*) f_gjets->Get("sieieEB_realtemplate_"+bin);
    TLegend *l_EB = new TLegend(0.55,0.75,0.85,0.85);
    l_EB->SetBorderSize(0);
    l_EB->SetFillColor(0);
    l_EB->AddEntry(h_ggjets_EB,"GGJets MC","ep");
    l_EB->AddEntry(h_gjets_EB,"GJets MC","ep");
    h_ggjets_EB->Draw();
    h_gjets_EB->Draw("same");
    h_gjets_EB->SetMarkerColor(kRed);
    h_gjets_EB->SetLineColor(kRed);
    h_gjets_EB->SetMarkerStyle(kPlus);
    h_ggjets_EB->SetTitle("EB "+bin);
    h_ggjets_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_ggjets_EB->GetXaxis()->SetRangeUser(0,0.03);
    l_EB->Draw();
    // EB - log
    c->cd(2);
    h_ggjets_EB->Draw();
    h_gjets_EB->Draw("same");
    l_EB->Draw();
    gPad->SetLogy();
    // EE - linear
    c->cd(3);
    TH1D *h_ggjets_EE = (TH1D*) f_ggjets->Get("sieieEE_realtemplate_"+bin);
    TH1D *h_gjets_EE = (TH1D*) f_gjets->Get("sieieEE_realtemplate_"+bin);
    TLegend *l_EE = new TLegend(0.55,0.75,0.85,0.85);
    l_EE->SetBorderSize(0);
    l_EE->SetFillColor(0);
    l_EE->AddEntry(h_ggjets_EE,"GGJets MC","ep");
    l_EE->AddEntry(h_gjets_EE,"GJets MC","ep");
    h_ggjets_EE->Draw();
    h_gjets_EE->Draw("same");
    h_gjets_EE->SetMarkerColor(kRed);
    h_gjets_EE->SetLineColor(kRed);
    h_gjets_EE->SetMarkerStyle(kPlus);
    h_ggjets_EE->SetTitle("EE "+bin);
    h_ggjets_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_ggjets_EE->GetXaxis()->SetRangeUser(0,0.07);
    l_EE->Draw();
    // EE - log
    c->cd(4);
    h_ggjets_EE->Draw();
    h_gjets_EE->Draw("same");
    l_EE->Draw();
    gPad->SetLogy();

    c->SaveAs("real_templates_GGJets_GJets_comparison_sieie_"+bin+".png");
    
  } // end for loop over pt bins
  
}
