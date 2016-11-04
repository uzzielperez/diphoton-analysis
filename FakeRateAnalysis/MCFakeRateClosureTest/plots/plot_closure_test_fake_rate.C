// run in batch mode from "plots" directory
// root -l -b -q plot_fake_template_comparison.C

void plot_closure_test_fake_rate() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  TFile *f_fitNumerator = TFile::Open("../../RooFitTemplateFitting/analysis/fakeRatePlots.root");
  TFile *f_fakeNumerator = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TH1D *h_fakeNumeratorEB = (TH1D*) f_fakeNumerator->Get("phoPtEB_passHighPtID_varbin");
  TH1D *h_fakeNumeratorEE = (TH1D*) f_fakeNumerator->Get("phoPtEE_passHighPtID_varbin");

  // vector of histograms using fit results (TGraph) evaluated at bin center for each side band
  std::vector<TH1D*> fit_results_EB;
  std::vector<TH1D*> fit_results_EE;
  
  for (int i=1; i<h_fakeNumeratorEB->GetSize()-1; i++) {
    double binWidth = h_fakeNumeratorEB->GetXaxis()->GetBinWidth(i);

    h_fakeNumeratorEB->SetBinContent(i,h_fakeNumeratorEB->GetBinContent(i) / binWidth);
    h_fakeNumeratorEB->SetBinError(i,h_fakeNumeratorEB->GetBinError(i) / binWidth);
    h_fakeNumeratorEE->SetBinContent(i,h_fakeNumeratorEE->GetBinContent(i) / binWidth);
    h_fakeNumeratorEE->SetBinError(i,h_fakeNumeratorEE->GetBinError(i) / binWidth);
  }
  
  // pt bin edges
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // pt bin centers
  double pt_bin_centers[nBins-1];
  for (int i = 0; i < nBins-1; i++) {
    pt_bin_centers[i] = ptBinArray[i] + (ptBinArray[i+1]-ptBinArray[i])/2;
    //cout << "Bin center: " << pt_bin_centers[i] << endl;
  }
  
  // make vector of sidebands
  int nSidebands = 8;
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

  // =====================================================================
  // Plot fit results for each sideband and overlay actual number of fakes
  // =====================================================================
  
  TCanvas *c_fit_vs_fake = new TCanvas("c_fit_vs_fake","",1500,600);
  c_fit_vs_fake->Divide(2,1);
    
  // EB
  cout << "EB" << endl;
  c_fit_vs_fake->cd(1);
  h_fakeNumeratorEB->Draw();

  TLegend *l_fit_vs_fake_EB = new TLegend(0.50,0.65,0.85,0.85);
  l_fit_vs_fake_EB->SetBorderSize(0);
  l_fit_vs_fake_EB->SetFillColor(0);
  l_fit_vs_fake_EB->AddEntry(h_fakeNumeratorEB,"QCD Fakes passHighPtID","lp"); 
    
  int i = 0;
  for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) { 
    double sidebandLow = it->first;
    double sidebandHigh = it->second;
    TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    cout << "Using sideband: " << sidebandLow << " < chIso < " << sidebandHigh << endl;
    
    TGraphAsymmErrors *h_fitNumeratorEB = (TGraphAsymmErrors*) f_fitNumerator->Get("bkgvsptEB_"+sideBand);
    TH1D *h_fit_results_EB = new TH1D("fit_over_actual_EB_"+sideBand,"",nBins-1,ptBinArray);
    h_fit_results_EB->Sumw2();
    for (int i = 0; i < nBins-1; i++) {
      cout << "Fake prediction at pt " << pt_bin_centers[i] << ": " << h_fitNumeratorEB->Eval(pt_bin_centers[i]) << ", actual fakes: " << h_fakeNumeratorEB->GetBinContent(i+1)
	   << ", prediction/actual: " << h_fitNumeratorEB->Eval(pt_bin_centers[i])/h_fakeNumeratorEB->GetBinContent(i+1) << endl;
      h_fit_results_EB->SetBinContent(i+1,h_fitNumeratorEB->Eval(pt_bin_centers[i]));
      h_fit_results_EB->SetBinError(i+1,h_fitNumeratorEB->GetErrorY(pt_bin_centers[i])); // correct errors?
    }
    fit_results_EB.push_back(h_fit_results_EB);
    
    h_fitNumeratorEB->Draw("same");
    h_fitNumeratorEB->SetLineColor(2+i);
    h_fitNumeratorEB->SetMarkerColor(2+i);
    l_fit_vs_fake_EB->AddEntry(h_fitNumeratorEB,"QCD numerator after fit "+sideBand,"lp");
    i++;
  }

  h_fakeNumeratorEB->SetTitle("Closure test in EB");
  h_fakeNumeratorEB->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_fakeNumeratorEB->GetYaxis()->SetTitle("fakes / bin width");
  
  //gPad->SetLogy();
  h_fakeNumeratorEB->SetMinimum(0);//0.3);
  h_fakeNumeratorEB->SetMaximum(20.);//100.);
        
  l_fit_vs_fake_EB->Draw();
    
  // EE
  cout << "EE" << endl;
  c_fit_vs_fake->cd(2);
  h_fakeNumeratorEE->Draw();

  TLegend *l_fit_vs_fake_EE = new TLegend(0.50,0.65,0.85,0.85);
  l_fit_vs_fake_EE->SetBorderSize(0);
  l_fit_vs_fake_EE->SetFillColor(0);
  l_fit_vs_fake_EE->AddEntry(h_fakeNumeratorEE,"QCD Fakes passHighPtID","lp");

  int j = 0;
  for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
    double sidebandLow = it->first;
    double sidebandHigh = it->second;
    TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    cout << "Using sideband: " << sidebandLow << " < chIso < " << sidebandHigh << endl;
    
    TGraphAsymmErrors *h_fitNumeratorEE = (TGraphAsymmErrors*) f_fitNumerator->Get("bkgvsptEE_"+sideBand);
    TH1D *h_fit_results_EE = new TH1D("fit_over_actual_EE_"+sideBand,"",nBins-1,ptBinArray);
    h_fit_results_EE->Sumw2();
    for (int i = 0; i < nBins-1; i++) {
      cout << "Fake prediction at pt " << pt_bin_centers[i] << ": " << h_fitNumeratorEE->Eval(pt_bin_centers[i]) << ", actual fakes: " << h_fakeNumeratorEE->GetBinContent(i+1)
	   << ", prediction/actual: " << h_fitNumeratorEE->Eval(pt_bin_centers[i])/h_fakeNumeratorEE->GetBinContent(i+1) << endl;
      h_fit_results_EE->SetBinContent(i+1,h_fitNumeratorEE->Eval(pt_bin_centers[i]));
      h_fit_results_EE->SetBinError(i+1,h_fitNumeratorEE->GetErrorY(pt_bin_centers[i])); // correct errors?
    }
    fit_results_EE.push_back(h_fit_results_EE);
    
    h_fitNumeratorEE->Draw("same");
    h_fitNumeratorEE->SetLineColor(2+j);
    h_fitNumeratorEE->SetMarkerColor(2+j);
    l_fit_vs_fake_EE->AddEntry(h_fitNumeratorEE,"QCD numerator after fit "+sideBand,"lp");
    j++;
  }
    
  h_fakeNumeratorEE->SetTitle("Closure test in EE");
  h_fakeNumeratorEE->GetXaxis()->SetTitle("p_{T} (GeV)");
  h_fakeNumeratorEE->GetYaxis()->SetTitle("fakes / bin width");
  
  //gPad->SetLogy();
  h_fakeNumeratorEE->SetMinimum(0);//0.3);
  h_fakeNumeratorEE->SetMaximum(20.); //100.);
       
  l_fit_vs_fake_EE->Draw();
    
  c_fit_vs_fake->SaveAs("closure_test_fit_prediction_vs_actual_fake.png");

  // ================================================================
  // Plot fit results divided by actual fake number for each sideband
  // ================================================================

  TLine *line = new TLine(50, 1, 300, 1);
  
  TCanvas *c_fit_over_fake = new TCanvas("c_fit_over_fake","",1500,600);
  c_fit_over_fake->Divide(2,1);

  // EB
  c_fit_over_fake->cd(1);
  
  TLegend *l_fit_over_fake_EB = new TLegend(0.60,0.65,0.85,0.85);
  l_fit_over_fake_EB->SetBorderSize(0);
  l_fit_over_fake_EB->SetFillColor(0);

  for (int i = 0; i < nSidebands; i++) {
    fit_results_EB.at(i)->Divide(h_fakeNumeratorEB);
    if (i==0) fit_results_EB.at(i)->Draw();
    else fit_results_EB.at(i)->Draw("same");
    fit_results_EB.at(i)->SetMarkerStyle(11);
    fit_results_EB.at(i)->SetLineColor(2+i);
    fit_results_EB.at(i)->SetMarkerColor(2+i);
    l_fit_over_fake_EB->AddEntry(fit_results_EB.at(i),fit_results_EB.at(i)->GetName(),"lp");
  }

  fit_results_EB.at(0)->SetTitle("Closure test in EB");
  //fit_results_EB.at(0)->GetYaxis()->SetRangeUser(0.,3.);
  //fit_results_EB.at(0)->GetXaxis()->SetRangeUser(50.,300.);
  fit_results_EB.at(0)->GetXaxis()->SetTitle("p_{T} (GeV)");
  fit_results_EB.at(0)->GetYaxis()->SetTitle("prediction / actual");
  
  l_fit_over_fake_EB->Draw();
  line->SetLineWidth(3);
  //line->Draw();

  // EE
  c_fit_over_fake->cd(2);

  TLegend *l_fit_over_fake_EE = new TLegend(0.60,0.65,0.85,0.85);
  l_fit_over_fake_EE->SetBorderSize(0);
  l_fit_over_fake_EE->SetFillColor(0);

  for (int i = 0; i < 8; i++) {
    fit_results_EE.at(i)->Divide(h_fakeNumeratorEE);
    if (i==0) fit_results_EE.at(i)->Draw();
    else fit_results_EE.at(i)->Draw("same");
    fit_results_EE.at(i)->SetMarkerStyle(11);
    fit_results_EE.at(i)->SetLineColor(2+i);
    fit_results_EE.at(i)->SetMarkerColor(2+i);
    l_fit_over_fake_EE->AddEntry(fit_results_EE.at(i),fit_results_EE.at(i)->GetName(),"lp");
  }

  fit_results_EE.at(0)->SetTitle("Closure test in EE");
  //fit_results_EE.at(0)->GetYaxis()->SetRangeUser(0.,3.);
  //fit_results_EE.at(0)->GetXaxis()->SetRangeUser(50.,300.);
  fit_results_EE.at(0)->GetXaxis()->SetTitle("p_{T} (GeV)");
  fit_results_EE.at(0)->GetYaxis()->SetTitle("prediction / actual");
  
  l_fit_over_fake_EE->Draw();
  line->SetLineWidth(3);
  //line->Draw();
  
  c_fit_over_fake->SaveAs("closure_test_fit_prediction_over_actual_fake.png");
}
