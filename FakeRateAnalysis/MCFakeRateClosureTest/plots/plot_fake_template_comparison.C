void plot_fake_template_comparison() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  TFile *fMC = TFile::Open("../analysis/diphoton_fakeRate_QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *fData = TFile::Open("../analysis/diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root");
  TFile *fFakes = TFile::Open("../analysis/diphoton_fakeRate_matchedFakes_QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

  const int nBins = 11;
  
  double ptBinArray[nBins] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 14.e3 };

  for (int i = 0; i < nBins-1; ++i) {
    
    const char *bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    // =============================
    // DATA FAKE TEMPLATE COMPARISON
    // =============================
    TCanvas *cSieieData = new TCanvas(Form("cSieieData_pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]),"SigmaIetaIeta",1500,600);
    cSieieData->Divide(2,1);
    
    // EB
    cSieieData->cd(1);
    
    TH1D *hMCEB = (TH1D*) fMC->Get(TString::Format("sieieEB_faketemplate_%s",bin));
    TH1D *hDataEB = (TH1D*) fData->Get(TString::Format("sieieEB_faketemplate_%s",bin));
    
    hMCEB->Draw();
    hDataEB->Draw("same");
    
    hMCEB->SetLineColor(kRed);
    hMCEB->SetMarkerColor(kRed);
    
    hMCEB->SetTitle(TString::Format("EB %s",bin));
    
    hMCEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEB->GetXaxis()->SetRangeUser(0,0.03);
    
    gPad->SetLogy();
   
    TLegend *lsIeIeDataEB = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeDataEB->SetBorderSize(0);
    lsIeIeDataEB->SetFillColor(0);
    lsIeIeDataEB->AddEntry(hMCEB,"MC faketemplate from QCD","lp");
    lsIeIeDataEB->AddEntry(hDataEB,"Data faketemplate from JetHT","lp");
    lsIeIeDataEB->Draw();
    
    // EE
    cSieieData->cd(2);
    
    TH1D *hMCEE = (TH1D*) fMC->Get(TString::Format("sieieEE_faketemplate_%s",bin));
    TH1D *hDataEE = (TH1D*) fData->Get(TString::Format("sieieEE_faketemplate_%s",bin));
    
    hMCEE->Draw();
    hDataEE->Draw("same");
    
    hMCEE->SetLineColor(kRed);
    hMCEE->SetMarkerColor(kRed);
    
    hMCEE->SetTitle(TString::Format("EE %s",bin));
    
    hMCEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEE->GetXaxis()->SetRangeUser(0,0.08);
    
    gPad->SetLogy();
    
    TLegend *lsIeIeDataEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeDataEE->SetBorderSize(0);
    lsIeIeDataEE->SetFillColor(0);
    lsIeIeDataEE->AddEntry(hMCEE,"MC faketemplate from QCD","lp");
    lsIeIeDataEE->AddEntry(hDataEE,"Data faketemplate from JetHT","lp");
    lsIeIeDataEE->Draw();  

    cSieieData->SaveAs(TString::Format("closure_test_data_faketemplate_%s_comparison.png",bin));

    // ===========================
    // MC FAKE TEMPLATE COMPARISON
    // ===========================
    TCanvas *cSieieMC = new TCanvas(Form("cSieieMC_pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]),"SigmaIetaIeta",1500,600);
    cSieieMC->Divide(2,1);
    
    // EB
    cSieieMC->cd(1);
    
    TH1D *hFakesEB = (TH1D*) fFakes->Get(TString::Format("sieieEB_faketemplate_%s",bin));
    
    hMCEB->Draw();
    hFakesEB->Draw("same");
    
    hMCEB->SetLineColor(kRed);
    hMCEB->SetMarkerColor(kRed);
    
    hMCEB->SetTitle(TString::Format("EB %s",bin));
    
    hMCEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEB->GetXaxis()->SetRangeUser(0,0.03);
    
    gPad->SetLogy();
   
    TLegend *lsIeIeMCEB = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCEB->SetBorderSize(0);
    lsIeIeMCEB->SetFillColor(0);
    lsIeIeMCEB->AddEntry(hMCEB,"MC faketemplate from QCD","lp");
    lsIeIeMCEB->AddEntry(hFakesEB,"MC faketemplate from QCD fakes","lp");
    lsIeIeMCEB->Draw();
    
    // EE
    cSieieMC->cd(2);
    
    TH1D *hFakesEE = (TH1D*) fFakes->Get(TString::Format("sieieEE_faketemplate_%s",bin));
    
    hMCEE->Draw();
    hFakesEE->Draw("same");
    
    hMCEE->SetLineColor(kRed);
    hMCEE->SetMarkerColor(kRed);
    
    hMCEE->SetTitle(TString::Format("EE %s",bin));
    
    hMCEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEE->GetXaxis()->SetRangeUser(0,0.08);
    
    gPad->SetLogy();
    
    TLegend *lsIeIeMCEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCEE->SetBorderSize(0);
    lsIeIeMCEE->SetFillColor(0);
    lsIeIeMCEE->AddEntry(hMCEE,"MC faketemplate from QCD","lp");
    lsIeIeMCEE->AddEntry(hFakesEE,"MC faketemplate from QCD fakes","lp");
    lsIeIeMCEE->Draw();  

    cSieieMC->SaveAs(TString::Format("closure_test_mc_faketemplate_%s_comparison.png",bin));
    
  } // end pt bin loop
  
}
