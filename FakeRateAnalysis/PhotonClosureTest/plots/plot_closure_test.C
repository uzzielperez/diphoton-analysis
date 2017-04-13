/**
 * To run:
 * root -l -b -q plot_closure_test.C'("all","sieie")' 
 */
void plot_closure_test(TString sample, TString templateVariable) {
  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;

  if (templateVariable != "sieie" && templateVariable != "chIso") {
    cout << "Choose template variable: sieie or chIso\n" << endl;
    return;
  }
  cout << "Using template variable: " << templateVariable << endl;
  
  TString filename = "";
  if (sample == "QCD")    filename = "../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = "../analysis/diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = "../analysis/diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    filename = "../analysis/diphoton_fake_rate_closure_test_matching_all_samples_76X_MiniAOD_histograms.root";
  cout << "\nfilename: " << filename << endl << endl;

  TFile *f_fake = TFile::Open(filename);
  TFile *f_fit = TFile::Open("../../RooFitTemplateFitting/analysis/fakeRatePlots.root");

  cout << "Fit file must contain appropriate histograms for templateVariable choice: ../../RooFitTemplateFitting/analysis/fakeRatePlots.root\n" << endl;
    
  // make vector of sidebands
  int nSidebands = 8;
  std::vector< std::pair<double,double> > chIsoSidebands;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  // chIsoSidebands.push_back( std::make_pair(6.,11.) );
  // chIsoSidebands.push_back( std::make_pair(7.,12.) );
  // chIsoSidebands.push_back( std::make_pair(8.,13.) );
  // chIsoSidebands.push_back( std::make_pair(9.,14.) );
  // chIsoSidebands.push_back( std::make_pair(10.,15.) );
  // chIsoSidebands.push_back( std::make_pair(15.,20.) );
  // chIsoSidebands.push_back( std::make_pair(10.,20.) );

  // vector of sieie sidebands
  // EB
  std::vector< std::pair<double,double> > sieie_EB_sidebands;
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,1.0000) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,0.0150) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0150,0.0200) );
  // EE
  std::vector< std::pair<double,double> > sieie_EE_sidebands;
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,1.000) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,0.040) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0400,0.060) );

  std::vector< std::pair<double,double> > sidebandsEB, sidebandsEE;
  if (templateVariable == "sieie") {
    sidebandsEB = chIsoSidebands;
    sidebandsEE = chIsoSidebands;
  }
  else if (templateVariable == "chIso") {
    sidebandsEB = sieie_EB_sidebands;
    sidebandsEE = sieie_EE_sidebands;
  }
  
  // convert histograms of matched fakes into graphs
  // EB
  TH1D *h_fakes_EB = (TH1D*) f_fake->Get("phoPtEB_passHighPtID_varbin");
  TGraphAsymmErrors* g_fakes_EB = new TGraphAsymmErrors();
  for (int i = 1; i < h_fakes_EB->GetSize()-1; i++) {
    TString plot;
    if (templateVariable == "sieie") plot = "bkgvsptEB_chIso5To10";
    else if (templateVariable == "chIso") plot = "bkgvsptEB_sieie0.0105To1.0000";
    // set x-location to match the fit result
    TGraphAsymmErrors *g_fit_EB = (TGraphAsymmErrors*) f_fit->Get(plot);
    double binWidth = h_fakes_EB->GetXaxis()->GetBinWidth(i);
    g_fakes_EB->SetPoint(i-1,g_fit_EB->GetX()[i-1],h_fakes_EB->GetBinContent(i) / binWidth);
    g_fakes_EB->SetPointError(i-1,g_fit_EB->GetX()[i-1]-h_fakes_EB->GetBinLowEdge(i),h_fakes_EB->GetBinLowEdge(i)+binWidth-g_fit_EB->GetX()[i-1],h_fakes_EB->GetBinErrorLow(i)/binWidth,h_fakes_EB->GetBinErrorUp(i)/binWidth);   
  }
  // EE
  TH1D *h_fakes_EE = (TH1D*) f_fake->Get("phoPtEE_passHighPtID_varbin");
  TGraphAsymmErrors* g_fakes_EE = new TGraphAsymmErrors();
  for (int i = 1; i < h_fakes_EE->GetSize()-1; i++) {
    TString plot;
    if (templateVariable == "sieie") plot = "bkgvsptEE_chIso5To10";
    else if (templateVariable == "chIso") plot = "bkgvsptEE_sieie0.0280To1.0000";
    // set x-location to match the fit result
    TGraphAsymmErrors *g_fit_EE = (TGraphAsymmErrors*) f_fit->Get(plot);
    double binWidth = h_fakes_EE->GetXaxis()->GetBinWidth(i);
    g_fakes_EE->SetPoint(i-1,g_fit_EE->GetX()[i-1],h_fakes_EE->GetBinContent(i) / binWidth);
    g_fakes_EE->SetPointError(i-1,g_fit_EE->GetX()[i-1]-h_fakes_EE->GetBinLowEdge(i),h_fakes_EE->GetBinLowEdge(i)+binWidth-g_fit_EE->GetX()[i-1],h_fakes_EE->GetBinErrorLow(i)/binWidth,h_fakes_EE->GetBinErrorUp(i)/binWidth);
  }
  
  std::vector<TGraphAsymmErrors*> fit_EB;
  std::vector<TGraphAsymmErrors*> ratio_EB;

  for (std::vector< std::pair<double,double> >::const_iterator it = sidebandsEB.begin(); it != sidebandsEB.end(); ++it) { 
    double sidebandLow = it->first;
    double sidebandHigh = it->second;
    TString sideband, name;
    if (templateVariable == "sieie") {
      sideband = Form("%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      name = "chIso" + sideband;
    }
    else if (templateVariable == "chIso") {
      sideband = Form("%.4fTo%.4f",sidebandLow,sidebandHigh);
      name = "sieie" + sideband;
    }
    
    std::cout << std::setprecision(4) << std::fixed;
    cout << "Using sideband " << sidebandLow << " < "+templateVariable+" < " << sidebandHigh << endl;
    
    TGraphAsymmErrors *g_fit_EB = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEB_"+name);
    g_fit_EB->SetName(sideband);
    fit_EB.push_back(g_fit_EB);
    
    TGraphAsymmErrors* g_ratio_EB = new TGraphAsymmErrors();
    g_ratio_EB->SetName(sideband);

    cout << "EB" << endl;
    for (int i = 0; i < g_fit_EB->GetN(); i++) {
      g_ratio_EB->SetPoint(i,g_fit_EB->GetX()[i],g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]);
      g_ratio_EB->SetPointError(i,
				g_fit_EB->GetErrorXlow(i),
				g_fit_EB->GetErrorXhigh(i),
				g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EB->GetErrorYlow(i)/g_fit_EB->GetY()[i],2)+TMath::Power(g_fakes_EB->GetErrorYlow(i)/g_fakes_EB->GetY()[i],2)),
				g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EB->GetErrorYhigh(i)/g_fit_EB->GetY()[i],2)+TMath::Power(g_fakes_EB->GetErrorYhigh(i)/g_fakes_EB->GetY()[i],2))
	);
      cout << "pt: " << g_fit_EB->GetX()[i] << ", prediction: " << g_fit_EB->GetY()[i] << ", truth: " << g_fakes_EB->GetY()[i] << ", prediction / truth: " <<  g_ratio_EB->GetY()[i] << endl;
    }
    ratio_EB.push_back(g_ratio_EB);
    cout << endl;
  }

  std::vector<TGraphAsymmErrors*> fit_EE;
  std::vector<TGraphAsymmErrors*> ratio_EE;
  
  for (std::vector< std::pair<double,double> >::const_iterator it = sidebandsEE.begin(); it != sidebandsEE.end(); ++it) { 
    double sidebandLow = it->first;
    double sidebandHigh = it->second;
    TString sideband, name;
    if (templateVariable == "sieie") {
      sideband = Form("%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      name = "chIso" + sideband;
    }
    else if (templateVariable == "chIso") {
      sideband = Form("%.4fTo%.4f",sidebandLow,sidebandHigh);
      name = "sieie" + sideband;
    }
    
    std::cout << std::setprecision(4) << std::fixed;
    cout << "Using sideband " << sidebandLow << " < "+templateVariable+" < " << sidebandHigh << endl;
    
    TGraphAsymmErrors *g_fit_EE = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEE_"+name);
    g_fit_EE->SetName(sideband);
    fit_EE.push_back(g_fit_EE);
    
    TGraphAsymmErrors* g_ratio_EE = new TGraphAsymmErrors();
    g_ratio_EE->SetName(sideband);

    cout << "EE" << endl;
    for (int i = 0; i < g_fit_EE->GetN(); i++) {
      g_ratio_EE->SetPoint(i,g_fit_EE->GetX()[i],g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]);
      g_ratio_EE->SetPointError(i,
				g_fit_EE->GetErrorXlow(i),
				g_fit_EE->GetErrorXhigh(i),
				g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EE->GetErrorYlow(i)/g_fit_EE->GetY()[i],2)+TMath::Power(g_fakes_EE->GetErrorYlow(i)/g_fakes_EE->GetY()[i],2)),
				g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EE->GetErrorYhigh(i)/g_fit_EE->GetY()[i],2)+TMath::Power(g_fakes_EE->GetErrorYhigh(i)/g_fakes_EE->GetY()[i],2))
	);
      cout << "pt: " << g_fit_EE->GetX()[i] << ", prediction: " << g_fit_EE->GetY()[i] << ", truth: " << g_fakes_EE->GetY()[i] << ", prediction / truth: " <<  g_ratio_EE->GetY()[i] << endl;
    }
    ratio_EE.push_back(g_ratio_EE);
    cout << endl;
  }

  // =====================================================================
  // Plot fit results for each sideband and overlay actual number of fakes
  // =====================================================================
  
  TCanvas *c_fit_vs_fake = new TCanvas("c_fit_vs_fake","",1500,800);
  c_fit_vs_fake->Divide(2,2);

  TLegend *l_fit_vs_fake_EB = new TLegend(0.50,0.50,0.85,0.85);
  l_fit_vs_fake_EB->SetBorderSize(0);
  l_fit_vs_fake_EB->SetFillColor(0);
  
  // EB - linear
  c_fit_vs_fake->cd(1);
  g_fakes_EB->Draw();
  l_fit_vs_fake_EB->AddEntry(g_fakes_EB,"Fakes from MC truth","elp");
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EB.begin(); it != fit_EB.end(); ++it) {
    auto pos = it - fit_EB.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString sideband = (TString) (*it)->GetName();
    if (templateVariable == "sieie") {
      sideband.ReplaceAll("To"," < Iso_{Ch} < ");
      sideband += " GeV";
    }
    else if (templateVariable == "chIso") sideband.ReplaceAll("To"," < #sigma_{i#etai#eta} < ");
    l_fit_vs_fake_EB->AddEntry(*it,"Fake prediction using "+sideband,"le");
  }
  
  g_fakes_EB->SetTitle("EB");
  g_fakes_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  g_fakes_EB->GetXaxis()->SetRangeUser(0,625);
  g_fakes_EB->GetYaxis()->SetTitle("fakes / bin width");
  g_fakes_EB->GetYaxis()->SetTitleOffset(1.4);
  g_fakes_EB->SetMaximum(TMath::MaxElement(g_fakes_EB->GetN(),g_fakes_EB->GetY())*1.1);
  g_fakes_EB->SetMinimum(10e-2);
  l_fit_vs_fake_EB->Draw();

  // EB - log
  c_fit_vs_fake->cd(2);
  g_fakes_EB->Draw();
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EB.begin(); it != fit_EB.end(); ++it) {
    auto pos = it - fit_EB.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
  }
  gPad->SetLogy();
  
  TLegend *l_fit_vs_fake_EE = new TLegend(0.50,0.50,0.85,0.85);
  l_fit_vs_fake_EE->SetBorderSize(0);
  l_fit_vs_fake_EE->SetFillColor(0);
  
  // EE - linear
  c_fit_vs_fake->cd(3);
  g_fakes_EE->Draw();
  l_fit_vs_fake_EE->AddEntry(g_fakes_EE,"Fakes from MC truth","elp");
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EE.begin(); it != fit_EE.end(); ++it) {
    auto pos = it - fit_EE.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString sideband = (TString) (*it)->GetName();
    if (templateVariable == "sieie") {
      sideband.ReplaceAll("To"," < Iso_{Ch} < ");
      sideband += " GeV";
    }
    else if (templateVariable == "chIso") sideband.ReplaceAll("To"," < #sigma_{i#etai#eta} < ");
    l_fit_vs_fake_EE->AddEntry(*it,"Fake prediction using "+sideband,"le");
  }
  
  g_fakes_EE->SetTitle("EE");
  g_fakes_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  g_fakes_EE->GetXaxis()->SetRangeUser(0,625);
  g_fakes_EE->GetYaxis()->SetTitle("fakes / bin width");
  g_fakes_EE->GetYaxis()->SetTitleOffset(1.4);
  g_fakes_EE->SetMaximum(TMath::MaxElement(g_fakes_EE->GetN(),g_fakes_EE->GetY())*1.1);
  g_fakes_EE->SetMinimum(10e-2);
  l_fit_vs_fake_EE->Draw();

  // EE - log
  c_fit_vs_fake->cd(4);
  g_fakes_EE->Draw();
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EE.begin(); it != fit_EE.end(); ++it) {
    auto pos = it - fit_EE.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
  }
  gPad->SetLogy();

  
  c_fit_vs_fake->SaveAs("closure_test_fit_prediction_vs_actual_fake_template_variable_"+templateVariable+"_sample_"+sample+".pdf");

  // ================================================================
  // Plot fit results divided by actual fake number for each sideband
  // ================================================================

  TLine *line_EB = new TLine(0, 1, 629, 1);
  line_EB->SetLineWidth(3);
  
  TCanvas *c_fit_over_fake = new TCanvas("c_fit_over_fake","",1500,600);
  c_fit_over_fake->Divide(2,1);
  
  TLegend *l_fit_over_fake_EB = new TLegend(0.40,0.70,0.85,0.85);
  l_fit_over_fake_EB->SetBorderSize(0);
  l_fit_over_fake_EB->SetFillColor(0);
  
  // EB
  c_fit_over_fake->cd(1);
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = ratio_EB.begin(); it != ratio_EB.end(); ++it) {
    auto pos = it - ratio_EB.begin();
    if (pos == 0) (*it)->Draw("AP");
    else (*it)->Draw("Psame");
    (*it)->SetMarkerStyle(8);
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString sideband = (TString) (*it)->GetName();
    if (templateVariable == "sieie") {
      sideband.ReplaceAll("To"," < Iso_{Ch} < ");
      sideband += " GeV";
    }
    else if (templateVariable == "chIso") sideband.ReplaceAll("To"," < #sigma_{i#etai#eta} < ");
    l_fit_over_fake_EB->AddEntry(*it,"Ratio using "+sideband,"pe");
  }

  ratio_EB.at(0)->SetTitle("EB");
  ratio_EB.at(0)->GetYaxis()->SetRangeUser(0,2);
  ratio_EB.at(0)->GetYaxis()->SetTitle("prediction / truth");
  ratio_EB.at(0)->GetYaxis()->SetTitleOffset(1.4);
  ratio_EB.at(0)->GetXaxis()->SetRangeUser(0,625);
  ratio_EB.at(0)->GetXaxis()->SetTitle("p_{T} (GeV)");

  l_fit_over_fake_EB->Draw();
  
  line_EB->Draw();

  TLine *line_EE = new TLine(0, 1, 629, 1);
  line_EE->SetLineWidth(3);
  
  TLegend *l_fit_over_fake_EE = new TLegend(0.40,0.70,0.85,0.85);
  l_fit_over_fake_EE->SetBorderSize(0);
  l_fit_over_fake_EE->SetFillColor(0);
  
  // EE
  c_fit_over_fake->cd(2);
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = ratio_EE.begin(); it != ratio_EE.end(); ++it) {
    auto pos = it - ratio_EE.begin();
    if (pos == 0) (*it)->Draw("APE");
    else (*it)->Draw("PEsame");
    (*it)->SetMarkerStyle(8);
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString sideband = (TString) (*it)->GetName();
    if (templateVariable == "sieie") {
      sideband.ReplaceAll("To"," < Iso_{Ch} < ");
      sideband += " GeV";
    }
    else if (templateVariable == "chIso") sideband.ReplaceAll("To"," < #sigma_{i#etai#eta} < ");
    l_fit_over_fake_EE->AddEntry(*it,"Ratio using "+sideband,"pe");
  }

  ratio_EE.at(0)->SetTitle("EE");
  ratio_EE.at(0)->GetYaxis()->SetRangeUser(0,2);
  ratio_EE.at(0)->GetYaxis()->SetTitle("prediction / actual");
  ratio_EE.at(0)->GetYaxis()->SetTitleOffset(1.4);
  ratio_EE.at(0)->GetXaxis()->SetRangeUser(0,625);
  ratio_EE.at(0)->GetXaxis()->SetTitle("p_{T} (GeV)");

  l_fit_over_fake_EE->Draw();
  
  line_EE->Draw();
  
  c_fit_over_fake->SaveAs("closure_test_fit_prediction_over_actual_fake_template_variable_"+templateVariable+"_sample_"+sample+".pdf");
}
