void plot_fake_matching_templates() {
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(kPlus);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  TFile *file = TFile::Open("../analysis/diphoton_fakeRate_matchedFakes_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  bool rebin = true;
  bool normalize = false;
  
  for (int i = 0; i < nBins-1; ++i) {
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    // ======================================
    // SIEIE TEMPLATE COMPARISON FROM MATCHES
    // ======================================

    TCanvas *cPhotonMatches = new TCanvas("cPhotonMatches_"+bin,"SigmaIetaIeta",1500,900);
    cPhotonMatches->Divide(2,2);

    // EB
    
    TH1D *hphotonHM_EB        = (TH1D*) file->Get("sieieEB_numerator_photonHadronMother_"+bin);
    TH1D *hphotonFragQuark_EB = (TH1D*) file->Get("sieieEB_numerator_photonOtherFragQuark_"+bin);
    TH1D *hphotonFragGluon_EB = (TH1D*) file->Get("sieieEB_numerator_photonOtherFragGluon_"+bin);
    TH1D *hnonPhoton_EB       = (TH1D*) file->Get("sieieEB_numerator_nonPhotonMatch_"+bin);
    TH1D *hgenParticle_EB     = (TH1D*) file->Get("sieieEB_numerator_genParticleMatch_"+bin);
    TH1D *hnoMatch_EB         = (TH1D*) file->Get("sieieEB_numerator_noMatch_"+bin);

    if (normalize) {
      hphotonHM_EB->Scale(1.0/hphotonHM_EB->Integral());
      hphotonFragQuark_EB->Scale(1.0/hphotonFragQuark_EB->Integral());
      hphotonFragGluon_EB->Scale(1.0/hphotonFragGluon_EB->Integral());
      hnonPhoton_EB->Scale(1.0/hnonPhoton_EB->Integral());
      hgenParticle_EB->Scale(1.0/hgenParticle_EB->Integral());
      hnoMatch_EB->Scale(1.0/hnoMatch_EB->Integral());
    }
    
    TLegend *lPhotonMatches_EB = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonMatches_EB->SetBorderSize(0);
    lPhotonMatches_EB->SetFillColor(0);
    lPhotonMatches_EB->AddEntry(hphotonHM_EB,"Photon with hadron mothers","lp");
    lPhotonMatches_EB->AddEntry(hphotonFragQuark_EB,"Other photon fragmentation with quark mother","lp");
    lPhotonMatches_EB->AddEntry(hphotonFragGluon_EB,"Other photon fragmentation with gluon mother","lp");
    lPhotonMatches_EB->AddEntry(hnonPhoton_EB,"Final state Non-photon match","lp");
    lPhotonMatches_EB->AddEntry(hgenParticle_EB,"No final state, gen particle match","lp");
    lPhotonMatches_EB->AddEntry(hnoMatch_EB,"No match","lp");
        
    cPhotonMatches->cd(1);
    hphotonHM_EB->Draw();
    hphotonFragQuark_EB->Draw("same");
    hphotonFragGluon_EB->Draw("same");
    hnonPhoton_EB->Draw("same");
    hgenParticle_EB->Draw("same");
    hnoMatch_EB->Draw("same");
    hphotonHM_EB->SetMarkerStyle(kPlus);
    hphotonFragQuark_EB->SetMarkerStyle(kPlus);
    hphotonFragGluon_EB->SetMarkerStyle(kPlus);
    hnonPhoton_EB->SetMarkerStyle(kPlus);
    hgenParticle_EB->SetMarkerStyle(kPlus);
    hnoMatch_EB->SetMarkerStyle(kPlus);
    hphotonHM_EB->SetLineColor(kBlack);
    hphotonFragQuark_EB->SetLineColor(kRed);
    hphotonFragGluon_EB->SetLineColor(kViolet);
    hnonPhoton_EB->SetLineColor(kBlue);
    hgenParticle_EB->SetLineColor(kOrange-2);
    hnoMatch_EB->SetLineColor(kGreen+3);
    hphotonHM_EB->SetMarkerColor(kBlack);
    hphotonFragQuark_EB->SetMarkerColor(kRed);
    hphotonFragGluon_EB->SetMarkerColor(kViolet);
    hnonPhoton_EB->SetMarkerColor(kBlue);
    hgenParticle_EB->SetMarkerColor(kOrange-2);
    hnoMatch_EB->SetMarkerColor(kGreen+3);
    hphotonHM_EB->SetTitle("EB "+bin);
    hphotonHM_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonHM_EB->GetXaxis()->SetRangeUser(0.005,0.025);
    //hphotonHM_EB->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonMatches_EB->Draw();

    cPhotonMatches->cd(2);
    hphotonHM_EB->Draw();
    hphotonFragQuark_EB->Draw("same");
    hphotonFragGluon_EB->Draw("same");
    hgenParticle_EB->Draw("same");
    hnonPhoton_EB->Draw("same");
    hnoMatch_EB->Draw("same");
    gPad->SetLogy();
    lPhotonMatches_EB->Draw();

    // EE

    TH1D *hphotonHM_EE        = (TH1D*) file->Get("sieieEE_numerator_photonHadronMother_"+bin);
    TH1D *hphotonFragQuark_EE = (TH1D*) file->Get("sieieEE_numerator_photonOtherFragQuark_"+bin);
    TH1D *hphotonFragGluon_EE = (TH1D*) file->Get("sieieEE_numerator_photonOtherFragGluon_"+bin);
    TH1D *hnonPhoton_EE       = (TH1D*) file->Get("sieieEE_numerator_nonPhotonMatch_"+bin);
    TH1D *hgenParticle_EE     = (TH1D*) file->Get("sieieEE_numerator_genParticleMatch_"+bin);
    TH1D *hnoMatch_EE         = (TH1D*) file->Get("sieieEE_numerator_noMatch_"+bin);

    if (rebin) {
      hphotonHM_EE->Rebin();
      hphotonFragQuark_EE->Rebin();
      hphotonFragGluon_EE->Rebin();
      hnonPhoton_EE->Rebin();
      hgenParticle_EE->Rebin();
      hnoMatch_EE->Rebin();
    }

    if (normalize) {
      hphotonHM_EE->Scale(1.0/hphotonHM_EE->Integral());
      hphotonFragQuark_EE->Scale(1.0/hphotonFragQuark_EE->Integral());
      hphotonFragGluon_EE->Scale(1.0/hphotonFragGluon_EE->Integral());
      hnonPhoton_EE->Scale(1.0/hnonPhoton_EE->Integral());
      hgenParticle_EE->Scale(1.0/hgenParticle_EE->Integral());
      hnoMatch_EE->Scale(1.0/hnoMatch_EE->Integral());
    }
    
    TLegend *lPhotonMatches_EE = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonMatches_EE->SetBorderSize(0);
    lPhotonMatches_EE->SetFillColor(0);
    lPhotonMatches_EE->AddEntry(hphotonHM_EE,"Photon with hadron mothers","lp");
    lPhotonMatches_EE->AddEntry(hphotonFragQuark_EE,"Other photon fragmentation with quark mother","lp");
    lPhotonMatches_EE->AddEntry(hphotonFragGluon_EE,"Other photon fragmentation with gluon mother","lp");
    lPhotonMatches_EE->AddEntry(hnonPhoton_EE,"Final state Non-photon match","lp");
    lPhotonMatches_EE->AddEntry(hgenParticle_EE,"No final state, gen particle match","lp");
    lPhotonMatches_EE->AddEntry(hnoMatch_EE,"No match","lp");
        
    cPhotonMatches->cd(3);
    hphotonHM_EE->Draw();
    hphotonFragQuark_EE->Draw("same");
    hphotonFragGluon_EE->Draw("same");
    hnonPhoton_EE->Draw("same");
    hgenParticle_EE->Draw("same");
    hnoMatch_EE->Draw("same");
    hphotonHM_EE->SetMarkerStyle(kPlus);
    hphotonFragQuark_EE->SetMarkerStyle(kPlus);
    hphotonFragGluon_EE->SetMarkerStyle(kPlus);
    hnonPhoton_EE->SetMarkerStyle(kPlus);
    hgenParticle_EE->SetMarkerStyle(kPlus);
    hnoMatch_EE->SetMarkerStyle(kPlus);
    hphotonHM_EE->SetLineColor(kBlack);
    hphotonFragQuark_EE->SetLineColor(kRed);
    hphotonFragGluon_EE->SetLineColor(kViolet);
    hnonPhoton_EE->SetLineColor(kBlue);
    hgenParticle_EE->SetLineColor(kOrange-2);
    hnoMatch_EE->SetLineColor(kGreen+3);
    hphotonHM_EE->SetMarkerColor(kBlack);
    hphotonFragQuark_EE->SetMarkerColor(kRed);
    hphotonFragGluon_EE->SetMarkerColor(kViolet);
    hnonPhoton_EE->SetMarkerColor(kBlue);
    hgenParticle_EE->SetMarkerColor(kOrange-2);
    hnoMatch_EE->SetMarkerColor(kGreen+3);
    hphotonHM_EE->SetTitle("EE "+bin);
    hphotonHM_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonHM_EE->GetXaxis()->SetRangeUser(0.015,0.045);
    //hphotonHM_EE->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonMatches_EE->Draw();

    cPhotonMatches->cd(4);
    hphotonHM_EE->Draw();
    hphotonFragQuark_EE->Draw("same");
    hphotonFragGluon_EE->Draw("same");
    hgenParticle_EE->Draw("same");
    hnonPhoton_EE->Draw("same");
    hnoMatch_EE->Draw("same");
    gPad->SetLogy();
    lPhotonMatches_EE->Draw();

    cPhotonMatches->SaveAs("sieie_templates_from_fake_matches_"+bin+".png");

    // ==================================================
    // SIEIE TEMPLATE COMPARISON FROM REAL PHOTON MATCHES
    // ==================================================

    TCanvas *cPhotonReal = new TCanvas("cPhotonReal_"+bin,"SigmaIetaIeta",1500,900);
    cPhotonReal->Divide(2,2);

    // EB
    
    TH1D *hphotonISR_EB = (TH1D*) file->Get("sieieEB_numerator_photonISR_"+bin);
    TH1D *hphotonFSR_EB = (TH1D*) file->Get("sieieEB_numerator_photonFSR_"+bin);

    if (normalize) {
      hphotonISR_EB->Scale(1.0/hphotonISR_EB->Integral());
      hphotonFSR_EB->Scale(1.0/hphotonFSR_EB->Integral());
    }
    
    TLegend *lPhotonReal_EB = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonReal_EB->SetBorderSize(0);
    lPhotonReal_EB->SetFillColor(0);
    lPhotonReal_EB->AddEntry(hphotonISR_EB,"Photon ISR","lp");
    lPhotonReal_EB->AddEntry(hphotonFSR_EB,"Photon FSR","lp");
    lPhotonReal_EB->AddEntry(hphotonFragQuark_EB,"Other photon fragmentation with quark mother","lp");
    lPhotonReal_EB->AddEntry(hphotonFragGluon_EB,"Other photon fragmentation with gluon mother","lp");
    
    cPhotonReal->cd(1);
    hphotonISR_EB->Draw();
    hphotonFSR_EB->Draw("same");
    hphotonFragQuark_EB->Draw("same");
    hphotonFragGluon_EB->Draw("same");
    hphotonISR_EB->SetMarkerStyle(kPlus);
    hphotonFSR_EB->SetMarkerStyle(kPlus);
    hphotonFragQuark_EB->SetMarkerStyle(kPlus);
    hphotonFragGluon_EB->SetMarkerStyle(kPlus);
    hphotonISR_EB->SetLineColor(kBlack);
    hphotonFSR_EB->SetLineColor(kRed);
    hphotonFragQuark_EB->SetLineColor(kGreen+3);
    hphotonFragGluon_EB->SetLineColor(kBlue);
    hphotonISR_EB->SetMarkerColor(kBlack);
    hphotonFSR_EB->SetMarkerColor(kRed);
    hphotonFragQuark_EB->SetMarkerColor(kGreen+3);
    hphotonFragGluon_EB->SetMarkerColor(kBlue);
    hphotonISR_EB->SetTitle("EB "+bin);
    hphotonISR_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonISR_EB->GetXaxis()->SetRangeUser(0.005,0.025);
    //hphotonISR_EB->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonReal_EB->Draw();

    cPhotonReal->cd(2);
    hphotonISR_EB->Draw();
    hphotonFSR_EB->Draw("same");
    hphotonFragQuark_EB->Draw("same");
    hphotonFragGluon_EB->Draw("same");
    gPad->SetLogy();
    lPhotonReal_EB->Draw();

    // EE

    TH1D *hphotonISR_EE = (TH1D*) file->Get("sieieEE_numerator_photonISR_"+bin);
    TH1D *hphotonFSR_EE = (TH1D*) file->Get("sieieEE_numerator_photonFSR_"+bin);

    if (rebin) {
      hphotonISR_EE->Rebin();
      hphotonFSR_EE->Rebin();
    }

    if (normalize) {
      hphotonISR_EE->Scale(1.0/hphotonISR_EE->Integral());
      hphotonFSR_EE->Scale(1.0/hphotonFSR_EE->Integral());
    }
    
    TLegend *lPhotonReal_EE = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonReal_EE->SetBorderSize(0);
    lPhotonReal_EE->SetFillColor(0);
    lPhotonReal_EE->AddEntry(hphotonISR_EE,"Photon ISR","lp");
    lPhotonReal_EE->AddEntry(hphotonFSR_EE,"Photon FSR","lp");
    lPhotonReal_EE->AddEntry(hphotonFragQuark_EE,"Other photon fragmentation with quark mother","lp");
    lPhotonReal_EE->AddEntry(hphotonFragGluon_EE,"Other photon fragmentation with gluon mother","lp");
    
    cPhotonReal->cd(3);
    hphotonISR_EE->Draw();
    hphotonFSR_EE->Draw("same");
    hphotonFragQuark_EE->Draw("same");
    hphotonFragGluon_EE->Draw("same");
    hphotonISR_EE->SetMarkerStyle(kPlus);
    hphotonFSR_EE->SetMarkerStyle(kPlus);
    hphotonFragQuark_EE->SetMarkerStyle(kPlus);
    hphotonFragGluon_EE->SetMarkerStyle(kPlus);
    hphotonISR_EE->SetLineColor(kBlack);
    hphotonFSR_EE->SetLineColor(kRed);
    hphotonFragQuark_EE->SetLineColor(kGreen+3);
    hphotonFragGluon_EE->SetLineColor(kBlue);
    hphotonISR_EE->SetMarkerColor(kBlack);
    hphotonFSR_EE->SetMarkerColor(kRed);
    hphotonFragQuark_EE->SetMarkerColor(kGreen+3);
    hphotonFragGluon_EE->SetMarkerColor(kBlue);
    hphotonISR_EE->SetTitle("EE "+bin);
    hphotonISR_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonISR_EE->GetXaxis()->SetRangeUser(0.015,0.045);
    //hphotonISR_EE->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonReal_EE->Draw();

    cPhotonReal->cd(4);
    hphotonISR_EE->Draw();
    hphotonFSR_EE->Draw("same");
    hphotonFragQuark_EE->Draw("same");
    hphotonFragGluon_EE->Draw("same");
    gPad->SetLogy();
    lPhotonReal_EE->Draw();
    
    cPhotonReal->SaveAs("sieie_templates_from_real_matches_"+bin+".png");
  }
  
}
