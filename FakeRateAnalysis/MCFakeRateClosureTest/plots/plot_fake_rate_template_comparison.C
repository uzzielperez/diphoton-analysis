// run in batch mode from "plots" directory
// root -l -b -q plot_fake_template_comparison.C
void plot_fake_rate_template_comparison() {
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(kPlus);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  TFile *fData = TFile::Open("../../DataFakeRateAnalysis/analysis/jetht_fakerate_vanilla.root");
  TFile *fMC = TFile::Open("../../MCFakeRateAnalysis/analysis/GGJets_M-200To500_vanilla.root");
  
  TFile *fClosureTestMCasData = TFile::Open("../analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *fClosureTestMCmatching = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

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
  //chIsoSidebands.push_back( std::make_pair(7.,12.) );
  //chIsoSidebands.push_back( std::make_pair(8.,13.) );
  //chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  //chIsoSidebands.push_back( std::make_pair(15.,20.) );
  //chIsoSidebands.push_back( std::make_pair(10.,20.) );

  bool rebin = true;
  
  for (int i = 0; i < nBins-1; ++i) {
        
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);
    
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {

      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      
      // =============================
      // DATA FAKE TEMPLATE COMPARISON
      // =============================
      TCanvas *cSieieData = new TCanvas("cSieieData_"+bin+"_"+sideBand,"SigmaIetaIeta",1500,900);
      cSieieData->Divide(2,2);
      
      // EB
      
      TH1D *hClosureTestMCasDataEB = (TH1D*) fClosureTestMCasData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);
      TH1D *hDataEB = (TH1D*) fData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);

      if (rebin) {
	hClosureTestMCasDataEB->Rebin();
	hDataEB->Rebin();
      }
      
      TLegend *lsIeIeDataEB = new TLegend(0.65,0.65,0.90,0.85);
      lsIeIeDataEB->SetBorderSize(0);
      lsIeIeDataEB->SetFillColor(0);
      lsIeIeDataEB->AddEntry(hClosureTestMCasDataEB,"Faketemplate from QCD MC","lp");
      lsIeIeDataEB->AddEntry(hDataEB,"Faketemplate from JetHT data","lp");
      
      cSieieData->cd(1);
      hClosureTestMCasDataEB->Draw();
      hDataEB->Draw("same");
      hClosureTestMCasDataEB->SetMarkerStyle(kPlus);
      hClosureTestMCasDataEB->SetLineColor(kRed);
      hClosureTestMCasDataEB->SetMarkerColor(kRed);
      hClosureTestMCasDataEB->SetTitle("EB "+bin+" "+sideBand);
      hClosureTestMCasDataEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      hClosureTestMCasDataEB->GetXaxis()->SetRangeUser(0.005,0.025);
      lsIeIeDataEB->Draw();
      
      cSieieData->cd(2);
      hClosureTestMCasDataEB->Draw();
      hDataEB->Draw("same");
      lsIeIeDataEB->Draw();
      gPad->SetLogy();
      
      // EE
      
      TH1D *hClosureTestMCasDataEE = (TH1D*) fClosureTestMCasData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);
      TH1D *hDataEE = (TH1D*) fData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);

      if (rebin) {
	hClosureTestMCasDataEE->Rebin(4);
	hDataEE->Rebin(4);
      }
      
      TLegend *lsIeIeDataEE = new TLegend(0.65,0.65,0.90,0.85);
      lsIeIeDataEE->SetBorderSize(0);
      lsIeIeDataEE->SetFillColor(0);
      lsIeIeDataEE->AddEntry(hClosureTestMCasDataEE,"Faketemplate from QCD MC","lp");
      lsIeIeDataEE->AddEntry(hDataEE,"Faketemplate from JetHT data","lp");
      
      cSieieData->cd(3);
      hClosureTestMCasDataEE->Draw();
      hDataEE->Draw("same");
      hClosureTestMCasDataEE->SetMarkerStyle(kPlus);
      hClosureTestMCasDataEE->SetLineColor(kRed);
      hClosureTestMCasDataEE->SetMarkerColor(kRed);
      hClosureTestMCasDataEE->SetTitle("EE "+bin+" "+sideBand);
      hClosureTestMCasDataEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      hClosureTestMCasDataEE->GetXaxis()->SetRangeUser(0.01,0.07);
      lsIeIeDataEE->Draw();

      cSieieData->cd(4);
      hClosureTestMCasDataEE->Draw();
      hDataEE->Draw("same");
      gPad->SetLogy();
      lsIeIeDataEE->Draw();  

      cSieieData->SaveAs("closure_test_mc_faketemplate_data_faketemplate_"+bin+"_"+sideBand+"_comparison.png");
      
    } // end chIso sideband loop

    // ==================================================
    // FakeTemplate after fit compared to Numerator Fakes
    // ==================================================
    TCanvas *cSieieFit = new TCanvas("cSieieFit_"+bin,"SigmaIetaIeta",1500,900);
    cSieieFit->Divide(2,2);
    
    // EB
    
    cSieieFit->cd(1);
    TH1D *hClosureTestMCmatchingFakesEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_fakes_"+bin);
    hClosureTestMCmatchingFakesEB->Draw();
    if (rebin) hClosureTestMCmatchingFakesEB->Rebin();
    
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
      //if (rebin) h_fakeTemplateEB_fit->Rebin();
      h_fakeTemplateEB_fit->Draw("same");
      h_fakeTemplateEB_fit->SetLineColor(2+j_EB_fit);
      h_fakeTemplateEB_fit->SetMarkerColor(2+j_EB_fit);
      lsIeIeFitEB->AddEntry(h_fakeTemplateEB_fit,"Faketemplate after fit "+sideBand,"lp");
      j_EB_fit++;
    }
    hClosureTestMCmatchingFakesEB->SetTitle("EB "+bin);
    hClosureTestMCmatchingFakesEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingFakesEB->GetXaxis()->SetRangeUser(0,0.025);
    lsIeIeFitEB->Draw();
    
    cSieieFit->cd(2);
    hClosureTestMCmatchingFakesEB->Draw();
    int j2_EB_fit = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fakeTemplateEB_fit = (TH1D*) f_fitResults->Get("bkgfitEB_"+bin+"_"+sideBand);
      h_fakeTemplateEB_fit->Draw("same");
      h_fakeTemplateEB_fit->SetLineColor(2+j2_EB_fit);
      h_fakeTemplateEB_fit->SetMarkerColor(2+j2_EB_fit);
      j2_EB_fit++;
    }
    gPad->SetLogy();
    lsIeIeFitEB->Draw();
    
    
    // EE
    
    cSieieFit->cd(3);
    TH1D *hClosureTestMCmatchingFakesEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_fakes_"+bin);
    //cout << "nbins: " << hClosureTestMCmatchingFakesEE->GetNbinsX() << endl;
    hClosureTestMCmatchingFakesEE->Draw();

    if (rebin) hClosureTestMCmatchingFakesEE->Rebin(4);
    //cout << "nbins: " << hClosureTestMCmatchingFakesEE->GetNbinsX() << endl;
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
      //if (rebin) h_fakeTemplateEE_fit->Rebin();
      h_fakeTemplateEE_fit->Draw("same");
      h_fakeTemplateEE_fit->SetLineColor(2+j_EE_fit);
      h_fakeTemplateEE_fit->SetMarkerColor(2+j_EE_fit);
      lsIeIeFitEE->AddEntry(h_fakeTemplateEE_fit,"Faketemplate after fit "+sideBand,"lp");
      j_EE_fit++;
    }
    hClosureTestMCmatchingFakesEE->SetTitle("EE "+bin);
    hClosureTestMCmatchingFakesEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hClosureTestMCmatchingFakesEE->GetXaxis()->SetRangeUser(0.01,0.07);
    lsIeIeFitEE->Draw();

    cSieieFit->cd(4);
    hClosureTestMCmatchingFakesEE->Draw();
    int j2_EE_fit = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fakeTemplateEE_fit = (TH1D*) f_fitResults->Get("bkgfitEE_"+bin+"_"+sideBand);
      h_fakeTemplateEE_fit->Draw("same");
      h_fakeTemplateEE_fit->SetLineColor(2+j2_EE_fit);
      h_fakeTemplateEE_fit->SetMarkerColor(2+j2_EE_fit);
      j2_EE_fit++;
    }
    gPad->SetLogy();
    lsIeIeFitEE->Draw();
    
    cSieieFit->SaveAs("closure_test_fit_faketemplate_mc_numerator_fakes_"+bin+"_comparison.png");
    
    // ===========================
    // MC FAKE TEMPLATE COMPARISON
    // ===========================
    TCanvas *cSieieMC = new TCanvas("cSieieMC_"+bin,"SigmaIetaIeta",1500,900);
    cSieieMC->Divide(2,2);
    
    // EB
    
    cSieieMC->cd(1);
    TH1D *hClosureTestMCmatchingEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_fakes_"+bin);
    //if (rebin) hClosureTestMCmatchingEB->Rebin();
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
      //if (rebin) hClosureTestMCasDataEB->Rebin();
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
    hClosureTestMCmatchingEB->GetXaxis()->SetRangeUser(0,0.025);
    lsIeIeMCEB->Draw();

    cSieieMC->cd(2);
    hClosureTestMCmatchingEB->Draw();
    int j1_2 = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *hClosureTestMCasDataEB = (TH1D*) fClosureTestMCasData->Get("sieieEB_faketemplate_"+bin+"_"+sideBand);
      hClosureTestMCasDataEB->Draw("same");
      hClosureTestMCasDataEB->SetLineColor(2+j1_2);
      hClosureTestMCasDataEB->SetMarkerColor(2+j1_2);
      j1_2++;
    }
    gPad->SetLogy();
    lsIeIeMCEB->Draw();
    
    // EE
    
    cSieieMC->cd(3);
    TH1D *hClosureTestMCmatchingEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_fakes_"+bin);
    //cout << "nbins: " << hClosureTestMCmatchingEE->GetNbinsX() << endl;
    //if (rebin) hClosureTestMCmatchingEE->Rebin(4);
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
      //if (rebin) hClosureTestMCasDataEE->Rebin(4);
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
    hClosureTestMCmatchingEE->GetXaxis()->SetRangeUser(0,0.07);
    lsIeIeMCEE->Draw();  

    cSieieMC->cd(4);
    hClosureTestMCmatchingEE->Draw();
    int j2_2 = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *hClosureTestMCasDataEE = (TH1D*) fClosureTestMCasData->Get("sieieEE_faketemplate_"+bin+"_"+sideBand);
      hClosureTestMCasDataEE->Draw("same");
      hClosureTestMCasDataEE->SetLineColor(2+j2_2);
      hClosureTestMCasDataEE->SetMarkerColor(2+j2_2);
      j2_2++;
    }
    gPad->SetLogy();
    lsIeIeMCEE->Draw();
    
    cSieieMC->SaveAs("closure_test_mc_faketemplate_mc_numerator_fake_"+bin+"_comparison.png");
    
    
    // ===========================
    // MC REAL TEMPLATE COMPARISON
    // ===========================

    TCanvas *cSieieMC_real = new TCanvas("cSieieMC_real_"+bin,"SigmaIetaIeta",1500,900);
    cSieieMC_real->Divide(2,2);

    // EB
    
    TH1D *hMCEB          = (TH1D*) fMC->Get("sieieEB_realtemplate_"+bin);
    TH1D *hMatchedRealEB = (TH1D*) fClosureTestMCmatching->Get("sieieEB_numerator_real_"+bin);
    // if (rebin) {
    //   hMCEB->Rebin();
    //   hMatchedRealEB->Rebin();
    // }
    hMCEB->Scale(1.0/hMCEB->Integral());
    hMatchedRealEB->Scale(1.0/hMatchedRealEB->Integral());
    
    TLegend *lsIeIeMCRealEB = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCRealEB->SetBorderSize(0);
    lsIeIeMCRealEB->SetFillColor(0);
    lsIeIeMCRealEB->AddEntry(hMCEB,"Raketemplate from GGJets MC","lp");
    lsIeIeMCRealEB->AddEntry(hMatchedRealEB,"Numerator from QCD MC real","lp");
    
    cSieieMC_real->cd(1);
    hMCEB->Draw();
    hMatchedRealEB->Draw("same");
    hMCEB->SetMarkerStyle(kPlus);
    hMCEB->SetLineColor(kRed);
    hMCEB->SetMarkerColor(kRed);
    hMCEB->SetTitle("EB "+bin);
    hMCEB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEB->GetXaxis()->SetRangeUser(0,0.025);
    lsIeIeMCRealEB->Draw();

    cSieieMC_real->cd(2);
    hMCEB->Draw();
    hMatchedRealEB->Draw("same");
    gPad->SetLogy();
    lsIeIeMCRealEB->Draw();

    // EE

    TH1D *hMCEE          = (TH1D*) fMC->Get("sieieEE_realtemplate_"+bin);
    TH1D *hMatchedRealEE = (TH1D*) fClosureTestMCmatching->Get("sieieEE_numerator_real_"+bin);
    if (rebin) {
      hMCEE->Rebin();
      hMatchedRealEE->Rebin();
    }
    hMCEE->Scale(1.0/hMCEE->Integral());
    hMatchedRealEE->Scale(1.0/hMatchedRealEE->Integral());
    
    TLegend *lsIeIeMCRealEE = new TLegend(0.65,0.65,0.90,0.85);
    lsIeIeMCRealEE->SetBorderSize(0);
    lsIeIeMCRealEE->SetFillColor(0);
    lsIeIeMCRealEE->AddEntry(hMCEE,"Raketemplate from GGJets MC","lp");
    lsIeIeMCRealEE->AddEntry(hMatchedRealEE,"Numerator from QCD MC real","lp");
    
    cSieieMC_real->cd(3);
    hMCEE->Draw();
    hMatchedRealEE->Draw("same");
    hMCEE->SetMarkerStyle(kPlus);
    hMCEE->SetLineColor(kRed);
    hMCEE->SetMarkerColor(kRed);
    hMCEE->SetTitle("EE "+bin);
    hMCEE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    hMCEE->GetXaxis()->SetRangeUser(0,0.07);
    lsIeIeMCRealEE->Draw();

    cSieieMC_real->cd(4);
    hMCEE->Draw();
    hMatchedRealEE->Draw("same");
    gPad->SetLogy();
    lsIeIeMCRealEE->Draw();

    cSieieMC_real->SaveAs("closure_test_mc_realtemplate_mc_numerator_real_"+bin+"_comparison.png");
    
  } // end pt bin loop
  
}
