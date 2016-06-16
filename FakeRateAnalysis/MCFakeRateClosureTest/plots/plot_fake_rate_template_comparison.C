// run in batch mode from "plots" directory
// root -l -b -q plot_fake_template_comparison.C
void plot_fake_rate_template_comparison() {
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(kFullDotSmall);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  TFile *fData = TFile::Open("../../DataFakeRateAnalysis/analysis/diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms_DENOM1.root");
  TFile *fMC = TFile::Open("../../MCFakeRateAnalysis/analysis/diphoton_fakeRate_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  
  TFile *fClosureTestMCasData = TFile::Open("../analysis/diphoton_fakeRate_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *fClosureTestMCmatching = TFile::Open("../analysis/diphoton_fakeRate_matchedFakes_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

  TFile *f_fitResults = TFile::Open("../../RooFitTemplateFitting/analysis/fakeRatePlots.root");
  
  double sieieEBCut = 0.0105;
  double sieieEECut = 0.0280;
  
  const int nBins = 10;
  
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  
  // make vector of sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );
  //sieieEB_faketemplate_pt300To14000_chIso6To11
  
  for (int i = 0; i < nBins-1; ++i) {
    
    //int i = 1;
    
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);


    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {

      double sidebandLow = it->first;
      double sidebandHigh = it->second;

      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      
      // =============================
      // DATA FAKE TEMPLATE COMPARISON
      // =============================
      TCanvas *cSieieData = new TCanvas("cSieieData_"+bin+"_"+sideBand,"SigmaIetaIeta",1500,600);
      cSieieData->Divide(2,1);
      
      // EB
      cSieieData->cd(1);
      
      TH1D *hClosureTestMCasDataEB = (TH1D*) fClosureTestMCasData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);
      TH1D *hDataEB = (TH1D*) fData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);
    
      hClosureTestMCasDataEB->Draw();
      hDataEB->Draw("same");
    
      hClosureTestMCasDataEB->SetLineColor(kRed);
      hClosureTestMCasDataEB->SetMarkerColor(kRed);
    
      hClosureTestMCasDataEB->SetTitle("EB "+bin+" "+sideBand);
    
      hClosureTestMCasDataEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      hClosureTestMCasDataEB->GetXaxis()->SetRangeUser(0,0.03);
    
      gPad->SetLogy();
   
      TLegend *lsIeIeDataEB = new TLegend(0.65,0.65,0.90,0.85);
      lsIeIeDataEB->SetBorderSize(0);
      lsIeIeDataEB->SetFillColor(0);
      lsIeIeDataEB->AddEntry(hClosureTestMCasDataEB,"Faketemplate from QCD MC","lp");
      lsIeIeDataEB->AddEntry(hDataEB,"Faketemplate from JetHT data","lp");
      lsIeIeDataEB->Draw();
    
      // EE
      cSieieData->cd(2);
    
      TH1D *hClosureTestMCasDataEE = (TH1D*) fClosureTestMCasData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);
      TH1D *hDataEE = (TH1D*) fData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);
    
      hClosureTestMCasDataEE->Draw();
      hDataEE->Draw("same");
    
      hClosureTestMCasDataEE->SetLineColor(kRed);
      hClosureTestMCasDataEE->SetMarkerColor(kRed);
    
      hClosureTestMCasDataEE->SetTitle("EE "+bin+" "+sideBand);
    
      hClosureTestMCasDataEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      hClosureTestMCasDataEE->GetXaxis()->SetRangeUser(0,0.08);
    
      gPad->SetLogy();
    
      TLegend *lsIeIeDataEE = new TLegend(0.65,0.65,0.90,0.85);
      lsIeIeDataEE->SetBorderSize(0);
      lsIeIeDataEE->SetFillColor(0);
      lsIeIeDataEE->AddEntry(hClosureTestMCasDataEE,"Faketemplate from QCD MC","lp");
      lsIeIeDataEE->AddEntry(hDataEE,"Faketemplate from JetHT data","lp");
      lsIeIeDataEE->Draw();  

      cSieieData->SaveAs("closure_test_mc_faketemplate_data_faketemplate_"+bin+"_"+sideBand+"_comparison.png");
      
    } // end chIso sideband loop

    // ==================================================
    // FakeTemplate after fit compared to Numerator Fakes
    // ==================================================
    TCanvas *cSieieFit = new TCanvas("cSieieFit_"+bin,"SigmaIetaIeta",1500,600);
    cSieieFit->Divide(2,1);
    
    // EB
    cSieieFit->cd(1);
    TH1D *hClosureTestMCmatchingFakesEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_fakes_"+bin);
    hClosureTestMCmatchingFakesEB->Draw();

    TLegend *lsIeIeFitEB = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeFitEB->SetBorderSize(0);
    lsIeIeFitEB->SetFillColor(0);
    lsIeIeFitEB->AddEntry(hClosureTestMCmatchingFakesEB,"Numerator from QCD MC fakes","lp");
    
    int j_EB_fit = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fakeTemplateEB_fit = (TH1D*) f_fitResults->Get("bkgfitEB_"+bin+"_"+sideBand);
      h_fakeTemplateEB_fit->Draw("same");
      h_fakeTemplateEB_fit->SetLineColor(2+j_EB_fit);
      h_fakeTemplateEB_fit->SetMarkerColor(2+j_EB_fit);
      lsIeIeFitEB->AddEntry(h_fakeTemplateEB_fit,"Faketemplate after fit "+sideBand,"lp");
      j_EB_fit++;
    }

    hClosureTestMCmatchingFakesEB->SetTitle("EB "+bin);
    
    hClosureTestMCmatchingFakesEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingFakesEB->GetXaxis()->SetRangeUser(0,0.03);
    
    gPad->SetLogy();
    lsIeIeFitEB->Draw();
    
    // EE
    cSieieFit->cd(2);
    TH1D *hClosureTestMCmatchingFakesEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_fakes_"+bin);
    hClosureTestMCmatchingFakesEE->Draw();

    TLegend *lsIeIeFitEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeFitEE->SetBorderSize(0);
    lsIeIeFitEE->SetFillColor(0);
    lsIeIeFitEE->AddEntry(hClosureTestMCmatchingFakesEE,"Numerator from QCD MC fakes","lp");
    
    int j_EE_fit = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fakeTemplateEE_fit = (TH1D*) f_fitResults->Get("bkgfitEE_"+bin+"_"+sideBand);
      h_fakeTemplateEE_fit->Draw("same");
      h_fakeTemplateEE_fit->SetLineColor(2+j_EE_fit);
      h_fakeTemplateEE_fit->SetMarkerColor(2+j_EE_fit);
      lsIeIeFitEE->AddEntry(h_fakeTemplateEE_fit,"Faketemplate after fit "+sideBand,"lp");
      j_EE_fit++;
    }

    hClosureTestMCmatchingFakesEE->SetTitle("EE "+bin);
    
    hClosureTestMCmatchingFakesEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingFakesEE->GetXaxis()->SetRangeUser(0,0.08);
    
    gPad->SetLogy();
    lsIeIeFitEE->Draw();

    cSieieFit->SaveAs("closure_test_fit_faketemplate_mc_numerator_fakes_"+bin+"_comparison.png");
    
    // ===========================
    // MC FAKE TEMPLATE COMPARISON
    // ===========================
    TCanvas *cSieieMC = new TCanvas("cSieieMC_"+bin,"SigmaIetaIeta",1500,600);
    cSieieMC->Divide(2,1);
    
    // EB
    cSieieMC->cd(1);
    TH1D *hClosureTestMCmatchingEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_fakes_"+bin);
    hClosureTestMCmatchingEB->Scale(1.0/hClosureTestMCmatchingEB->Integral());
    hClosureTestMCmatchingEB->Draw();

    cout << "Fraction of " << hClosureTestMCmatchingEB->GetName() << " passing sieie cut of " << sieieEBCut << " is "
	 << hClosureTestMCmatchingEB->Integral(hClosureTestMCmatchingEB->FindBin(0.),hClosureTestMCmatchingEB->FindBin(sieieEBCut)) / hClosureTestMCmatchingEB->Integral()
	 << endl;
    
    TLegend *lsIeIeMCEB = new TLegend(0.55,0.65,0.90,0.85);
    lsIeIeMCEB->SetBorderSize(0);
    lsIeIeMCEB->SetFillColor(0);
    lsIeIeMCEB->AddEntry(hClosureTestMCmatchingEB,"Numerator from QCD MC fakes","lp");

    int j1 = 0;
    
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *hClosureTestMCasDataEB = (TH1D*) fClosureTestMCasData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);
      cout << "Fraction of " << hClosureTestMCasDataEB->GetName() << " passing sieie cut of " << sieieEBCut << " is "
	 << hClosureTestMCasDataEB->Integral(hClosureTestMCasDataEB->FindBin(0.),hClosureTestMCasDataEB->FindBin(sieieEBCut)) / hClosureTestMCasDataEB->Integral()
	 << endl;
      hClosureTestMCasDataEB->Draw("same");
      hClosureTestMCasDataEB->SetLineColor(2+j1);
      hClosureTestMCasDataEB->SetMarkerColor(2+j1);
      lsIeIeMCEB->AddEntry(hClosureTestMCasDataEB,"Faketemplate from QCD MC "+sideBand,"lp");
      j1++;
    }
    
    hClosureTestMCmatchingEB->SetTitle("EB "+bin);
    
    hClosureTestMCmatchingEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingEB->GetXaxis()->SetRangeUser(0,0.03);
    
    gPad->SetLogy();
   
    lsIeIeMCEB->Draw();
    
    // EE
    cSieieMC->cd(2);
    TH1D *hClosureTestMCmatchingEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_fakes_"+bin);
    hClosureTestMCmatchingEE->Scale(1.0/hClosureTestMCmatchingEE->Integral());
    hClosureTestMCmatchingEE->Draw();

    cout << "Fraction of " << hClosureTestMCmatchingEE->GetName() << " passing sieie cut of " << sieieEECut << " is "
	 << hClosureTestMCmatchingEE->Integral(hClosureTestMCmatchingEE->FindBin(0.),hClosureTestMCmatchingEE->FindBin(sieieEECut)) / hClosureTestMCmatchingEE->Integral()
	 << endl;
    
    TLegend *lsIeIeMCEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCEE->SetBorderSize(0);
    lsIeIeMCEE->SetFillColor(0);
    lsIeIeMCEE->AddEntry(hClosureTestMCmatchingEE,"Numerator from QCD MC fakes","lp");
    
    int j2 = 0;
    
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *hClosureTestMCasDataEE = (TH1D*) fClosureTestMCasData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);
      cout << "Fraction of " << hClosureTestMCasDataEE->GetName() << " passing sieie cut of " << sieieEECut << " is "
	 << hClosureTestMCasDataEE->Integral(hClosureTestMCasDataEE->FindBin(0.),hClosureTestMCasDataEE->FindBin(sieieEECut)) / hClosureTestMCasDataEE->Integral()
	 << endl;
      hClosureTestMCasDataEE->Draw("same");
      hClosureTestMCasDataEE->SetLineColor(2+j2);
      hClosureTestMCasDataEE->SetMarkerColor(2+j2);
      lsIeIeMCEE->AddEntry(hClosureTestMCasDataEE,"Faketemplate from QCD MC "+sideBand,"lp");
      j2++;
    }
        
    hClosureTestMCmatchingEE->SetTitle("EE "+bin);
    
    hClosureTestMCmatchingEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingEE->GetXaxis()->SetRangeUser(0,0.08);
    
    gPad->SetLogy();
    
    lsIeIeMCEE->Draw();  

    cSieieMC->SaveAs("closure_test_mc_faketemplate_mc_numerator_fake_"+bin+"_comparison.png");
    
    
    // ===========================
    // MC REAL TEMPLATE COMPARISON
    // ===========================

    TCanvas *cSieieMC_real = new TCanvas("cSieieMC_real_"+bin,"SigmaIetaIeta",1500,600);
    cSieieMC_real->Divide(2,1);

    // EB
    cSieieMC_real->cd(1);
    TH1D *hMCEB        = (TH1D*) fMC->Get("sieieEB_realtemplate_"+bin);
    TH1D *hMatchedRealEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_real_"+bin);
    hMCEB->Scale(1.0/hMCEB->Integral());
    hMatchedRealEB->Scale(1.0/hMatchedRealEB->Integral());

    hMCEB->Draw();
    hMatchedRealEB->Draw("same");

    hMCEB->SetLineColor(kRed);
    hMCEB->SetMarkerColor(kRed);
    
    hMCEB->SetTitle("EB "+bin);
    
    hMCEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEB->GetXaxis()->SetRangeUser(0,0.03);
    
    gPad->SetLogy();
    
    TLegend *lsIeIeMCRealEB = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCRealEB->SetBorderSize(0);
    lsIeIeMCRealEB->SetFillColor(0);
    lsIeIeMCRealEB->AddEntry(hMCEB,"Raketemplate from GGJets MC","lp");
    lsIeIeMCRealEB->AddEntry(hMatchedRealEB,"Numerator from QCD MC real","lp");
    lsIeIeMCRealEB->Draw();

    // EE
    cSieieMC_real->cd(2);
    TH1D *hMCEE        = (TH1D*) fMC->Get("sieieEE_realtemplate_"+bin);
    TH1D *hMatchedRealEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_real_"+bin);
    hMCEE->Scale(1.0/hMCEE->Integral());
    hMatchedRealEE->Scale(1.0/hMatchedRealEE->Integral());

    hMCEE->Draw();
    hMatchedRealEE->Draw("same");

    hMCEE->SetLineColor(kRed);
    hMCEE->SetMarkerColor(kRed);
    
    hMCEE->SetTitle("EE "+bin);
    
    hMCEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEE->GetXaxis()->SetRangeUser(0,0.08);
    
    gPad->SetLogy();
    
    TLegend *lsIeIeMCRealEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCRealEE->SetBorderSize(0);
    lsIeIeMCRealEE->SetFillColor(0);
    lsIeIeMCRealEE->AddEntry(hMCEE,"Raketemplate from GGJets MC","lp");
    lsIeIeMCRealEE->AddEntry(hMatchedRealEE,"Numerator from QCD MC real","lp");
    lsIeIeMCRealEE->Draw();

    cSieieMC_real->SaveAs("closure_test_mc_realtemplate_mc_numerator_real_"+bin+"_comparison.png");
    
  } // end pt bin loop
  
}
