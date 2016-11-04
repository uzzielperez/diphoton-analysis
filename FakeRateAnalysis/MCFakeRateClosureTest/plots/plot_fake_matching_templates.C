void plot_fake_matching_templates() {
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(kPlus);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  TFile *file = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

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
    
    TH1D *hphotonHM_EB              = (TH1D*) file->Get("sieieEB_numerator_photonHadronMother_"+bin);
    TH1D *hOtherPhotonFrag_EB       = (TH1D*) file->Get("sieieEB_numerator_otherPhotonFragmentation_"+bin);
    TH1D *hGluonMotherPhotonFrag_EB = (TH1D*) file->Get("sieieEB_numerator_gluonMotherPhotonFrag_"+bin);
    TH1D *hnonPhoton_EB             = (TH1D*) file->Get("sieieEB_numerator_nonPhotonMatch_"+bin);
    TH1D *hgenParticle_EB           = (TH1D*) file->Get("sieieEB_numerator_genParticleMatch_"+bin);
    TH1D *hnoMatch_EB               = (TH1D*) file->Get("sieieEB_numerator_noMatch_"+bin);

    if (normalize) {
      hphotonHM_EB->Scale(1.0/hphotonHM_EB->Integral());
      hOtherPhotonFrag_EB->Scale(1.0/hOtherPhotonFrag_EB->Integral());
      hGluonMotherPhotonFrag_EB->Scale(1.0/hGluonMotherPhotonFrag_EB->Integral());
      hnonPhoton_EB->Scale(1.0/hnonPhoton_EB->Integral());
      hgenParticle_EB->Scale(1.0/hgenParticle_EB->Integral());
      hnoMatch_EB->Scale(1.0/hnoMatch_EB->Integral());
    }
    
    TLegend *lPhotonMatches_EB = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonMatches_EB->SetBorderSize(0);
    lPhotonMatches_EB->SetFillColor(0);
    lPhotonMatches_EB->AddEntry(hphotonHM_EB,"Photon with hadron mothers","lp");
    lPhotonMatches_EB->AddEntry(hOtherPhotonFrag_EB,"Other photon fragmentation","lp");
    lPhotonMatches_EB->AddEntry(hGluonMotherPhotonFrag_EB,"Photon fragmentation with gluon mother","lp");
    lPhotonMatches_EB->AddEntry(hnonPhoton_EB,"Final state Non-photon match","lp");
    lPhotonMatches_EB->AddEntry(hgenParticle_EB,"No final state, gen particle match","lp");
    lPhotonMatches_EB->AddEntry(hnoMatch_EB,"No match","lp");
        
    cPhotonMatches->cd(1);
    hphotonHM_EB->Draw();
    hOtherPhotonFrag_EB->Draw("same");
    hGluonMotherPhotonFrag_EB->Draw("same");
    hnonPhoton_EB->Draw("same");
    hgenParticle_EB->Draw("same");
    hnoMatch_EB->Draw("same");
    hphotonHM_EB->SetMarkerStyle(kPlus);
    hOtherPhotonFrag_EB->SetMarkerStyle(kPlus);
    hGluonMotherPhotonFrag_EB->SetMarkerStyle(kPlus);
    hnonPhoton_EB->SetMarkerStyle(kPlus);
    hgenParticle_EB->SetMarkerStyle(kPlus);
    hnoMatch_EB->SetMarkerStyle(kPlus);
    hphotonHM_EB->SetLineColor(kBlack);
    hOtherPhotonFrag_EB->SetLineColor(kRed);
    hGluonMotherPhotonFrag_EB->SetLineColor(kViolet);
    hnonPhoton_EB->SetLineColor(kBlue);
    hgenParticle_EB->SetLineColor(kOrange-2);
    hnoMatch_EB->SetLineColor(kGreen+3);
    hphotonHM_EB->SetMarkerColor(kBlack);
    hOtherPhotonFrag_EB->SetMarkerColor(kRed);
    hGluonMotherPhotonFrag_EB->SetMarkerColor(kViolet);
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
    hOtherPhotonFrag_EB->Draw("same");
    hGluonMotherPhotonFrag_EB->Draw("same");
    hgenParticle_EB->Draw("same");
    hnonPhoton_EB->Draw("same");
    hnoMatch_EB->Draw("same");
    gPad->SetLogy();
    lPhotonMatches_EB->Draw();

    // EE

    TH1D *hphotonHM_EE              = (TH1D*) file->Get("sieieEE_numerator_photonHadronMother_"+bin);
    TH1D *hOtherPhotonFrag_EE       = (TH1D*) file->Get("sieieEE_numerator_otherPhotonFragmentation_"+bin);
    TH1D *hGluonMotherPhotonFrag_EE = (TH1D*) file->Get("sieieEE_numerator_gluonMotherPhotonFrag_"+bin);
    TH1D *hnonPhoton_EE             = (TH1D*) file->Get("sieieEE_numerator_nonPhotonMatch_"+bin);
    TH1D *hgenParticle_EE           = (TH1D*) file->Get("sieieEE_numerator_genParticleMatch_"+bin);
    TH1D *hnoMatch_EE               = (TH1D*) file->Get("sieieEE_numerator_noMatch_"+bin);

    if (rebin) {
      hphotonHM_EE->Rebin();
      hOtherPhotonFrag_EE->Rebin();
      hGluonMotherPhotonFrag_EE->Rebin();
      hnonPhoton_EE->Rebin();
      hgenParticle_EE->Rebin();
      hnoMatch_EE->Rebin();
    }

    if (normalize) {
      hphotonHM_EE->Scale(1.0/hphotonHM_EE->Integral());
      hOtherPhotonFrag_EE->Scale(1.0/hOtherPhotonFrag_EE->Integral());
      hGluonMotherPhotonFrag_EE->Scale(1.0/hGluonMotherPhotonFrag_EE->Integral());
      hnonPhoton_EE->Scale(1.0/hnonPhoton_EE->Integral());
      hgenParticle_EE->Scale(1.0/hgenParticle_EE->Integral());
      hnoMatch_EE->Scale(1.0/hnoMatch_EE->Integral());
    }
    
    TLegend *lPhotonMatches_EE = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonMatches_EE->SetBorderSize(0);
    lPhotonMatches_EE->SetFillColor(0);
    lPhotonMatches_EE->AddEntry(hphotonHM_EE,"Photon with hadron mothers","lp");
    lPhotonMatches_EE->AddEntry(hOtherPhotonFrag_EE,"Other photon fragmentation","lp");
    lPhotonMatches_EE->AddEntry(hGluonMotherPhotonFrag_EE,"Photon fragmentation with gluon mother","lp");
    lPhotonMatches_EE->AddEntry(hnonPhoton_EE,"Final state Non-photon match","lp");
    lPhotonMatches_EE->AddEntry(hgenParticle_EE,"No final state, gen particle match","lp");
    lPhotonMatches_EE->AddEntry(hnoMatch_EE,"No match","lp");
        
    cPhotonMatches->cd(3);
    hphotonHM_EE->Draw();
    hOtherPhotonFrag_EE->Draw("same");
    hGluonMotherPhotonFrag_EE->Draw("same");
    hnonPhoton_EE->Draw("same");
    hgenParticle_EE->Draw("same");
    hnoMatch_EE->Draw("same");
    hphotonHM_EE->SetMarkerStyle(kPlus);
    hOtherPhotonFrag_EE->SetMarkerStyle(kPlus);
    hGluonMotherPhotonFrag_EE->SetMarkerStyle(kPlus);
    hnonPhoton_EE->SetMarkerStyle(kPlus);
    hgenParticle_EE->SetMarkerStyle(kPlus);
    hnoMatch_EE->SetMarkerStyle(kPlus);
    hphotonHM_EE->SetLineColor(kBlack);
    hOtherPhotonFrag_EE->SetLineColor(kRed);
    hGluonMotherPhotonFrag_EE->SetLineColor(kViolet);
    hnonPhoton_EE->SetLineColor(kBlue);
    hgenParticle_EE->SetLineColor(kOrange-2);
    hnoMatch_EE->SetLineColor(kGreen+3);
    hphotonHM_EE->SetMarkerColor(kBlack);
    hOtherPhotonFrag_EE->SetMarkerColor(kRed);
    hGluonMotherPhotonFrag_EE->SetMarkerColor(kViolet);
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
    hOtherPhotonFrag_EE->Draw("same");
    hGluonMotherPhotonFrag_EE->Draw("same");
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
    
    TH1D *hphotonISRfromProton_EB  = (TH1D*) file->Get("sieieEB_numerator_photonISRfromProton_"+bin);
    TH1D *hotherPhotonRadiation_EB = (TH1D*) file->Get("sieieEB_numerator_otherPhotonRadiation_"+bin);

    if (normalize) {
      hphotonISRfromProton_EB->Scale(1.0/hphotonISRfromProton_EB->Integral());
      hotherPhotonRadiation_EB->Scale(1.0/hotherPhotonRadiation_EB->Integral());
    }
    
    TLegend *lPhotonReal_EB = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonReal_EB->SetBorderSize(0);
    lPhotonReal_EB->SetFillColor(0);
    lPhotonReal_EB->AddEntry(hphotonISRfromProton_EB,"Photon ISR from proton","lp");
    lPhotonReal_EB->AddEntry(hotherPhotonRadiation_EB,"Other photon radiation","lp");
    lPhotonReal_EB->AddEntry(hOtherPhotonFrag_EB,"Other photon fragmentation","lp");
    lPhotonReal_EB->AddEntry(hGluonMotherPhotonFrag_EB,"Photon fragmentation with gluon mother","lp");
    
    cPhotonReal->cd(1);
    hphotonISRfromProton_EB->Draw();
    hotherPhotonRadiation_EB->Draw("same");
    hOtherPhotonFrag_EB->Draw("same");
    hGluonMotherPhotonFrag_EB->Draw("same");
    hphotonISRfromProton_EB->SetMarkerStyle(kPlus);
    hotherPhotonRadiation_EB->SetMarkerStyle(kPlus);
    hOtherPhotonFrag_EB->SetMarkerStyle(kPlus);
    hGluonMotherPhotonFrag_EB->SetMarkerStyle(kPlus);
    hphotonISRfromProton_EB->SetLineColor(kBlack);
    hotherPhotonRadiation_EB->SetLineColor(kRed);
    hOtherPhotonFrag_EB->SetLineColor(kGreen+3);
    hGluonMotherPhotonFrag_EB->SetLineColor(kBlue);
    hphotonISRfromProton_EB->SetMarkerColor(kBlack);
    hotherPhotonRadiation_EB->SetMarkerColor(kRed);
    hOtherPhotonFrag_EB->SetMarkerColor(kGreen+3);
    hGluonMotherPhotonFrag_EB->SetMarkerColor(kBlue);
    hphotonISRfromProton_EB->SetTitle("EB "+bin);
    hphotonISRfromProton_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonISRfromProton_EB->GetXaxis()->SetRangeUser(0.005,0.025);
    //hphotonISRfromProton_EB->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonReal_EB->Draw();

    cPhotonReal->cd(2);
    hphotonISRfromProton_EB->Draw();
    hotherPhotonRadiation_EB->Draw("same");
    hOtherPhotonFrag_EB->Draw("same");
    hGluonMotherPhotonFrag_EB->Draw("same");
    gPad->SetLogy();
    lPhotonReal_EB->Draw();

    // EE

    TH1D *hphotonISRfromProton_EE = (TH1D*) file->Get("sieieEE_numerator_photonISRfromProton_"+bin);
    TH1D *hotherPhotonRadiation_EE = (TH1D*) file->Get("sieieEE_numerator_otherPhotonRadiation_"+bin);

    if (rebin) {
      hphotonISRfromProton_EE->Rebin();
      hotherPhotonRadiation_EE->Rebin();
    }

    if (normalize) {
      hphotonISRfromProton_EE->Scale(1.0/hphotonISRfromProton_EE->Integral());
      hotherPhotonRadiation_EE->Scale(1.0/hotherPhotonRadiation_EE->Integral());
    }
    
    TLegend *lPhotonReal_EE = new TLegend(0.65,0.65,0.90,0.85);
    lPhotonReal_EE->SetBorderSize(0);
    lPhotonReal_EE->SetFillColor(0);
    lPhotonReal_EE->AddEntry(hphotonISRfromProton_EE,"Photon ISR from proton","lp");
    lPhotonReal_EE->AddEntry(hotherPhotonRadiation_EE,"Other photon radiation","lp");
    lPhotonReal_EE->AddEntry(hOtherPhotonFrag_EE,"Other photon fragmentation","lp");
    lPhotonReal_EE->AddEntry(hGluonMotherPhotonFrag_EE,"Photon fragmentation with gluon mother","lp");
    
    cPhotonReal->cd(3);
    hphotonISRfromProton_EE->Draw();
    hotherPhotonRadiation_EE->Draw("same");
    hOtherPhotonFrag_EE->Draw("same");
    hGluonMotherPhotonFrag_EE->Draw("same");
    hphotonISRfromProton_EE->SetMarkerStyle(kPlus);
    hotherPhotonRadiation_EE->SetMarkerStyle(kPlus);
    hOtherPhotonFrag_EE->SetMarkerStyle(kPlus);
    hGluonMotherPhotonFrag_EE->SetMarkerStyle(kPlus);
    hphotonISRfromProton_EE->SetLineColor(kBlack);
    hotherPhotonRadiation_EE->SetLineColor(kRed);
    hOtherPhotonFrag_EE->SetLineColor(kGreen+3);
    hGluonMotherPhotonFrag_EE->SetLineColor(kBlue);
    hphotonISRfromProton_EE->SetMarkerColor(kBlack);
    hotherPhotonRadiation_EE->SetMarkerColor(kRed);
    hOtherPhotonFrag_EE->SetMarkerColor(kGreen+3);
    hGluonMotherPhotonFrag_EE->SetMarkerColor(kBlue);
    hphotonISRfromProton_EE->SetTitle("EE "+bin);
    hphotonISRfromProton_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hphotonISRfromProton_EE->GetXaxis()->SetRangeUser(0.015,0.045);
    //hphotonISRfromProton_EE->GetYaxis()->SetRangeUser(0.005,0.75);
    lPhotonReal_EE->Draw();

    cPhotonReal->cd(4);
    hphotonISRfromProton_EE->Draw();
    hotherPhotonRadiation_EE->Draw("same");
    hOtherPhotonFrag_EE->Draw("same");
    hGluonMotherPhotonFrag_EE->Draw("same");
    gPad->SetLogy();
    lPhotonReal_EE->Draw();
    
    cPhotonReal->SaveAs("sieie_templates_from_real_matches_"+bin+".png");
  }
  
}
