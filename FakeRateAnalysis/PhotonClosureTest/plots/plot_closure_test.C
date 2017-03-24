// run in batch mode from "plots" directory
// root -l -b -q plot_fake_template_comparison.C

void plot_closure_test() {

  // select what sample to run on (hardcoded for now)
  bool isAll = false;
  bool isQCD = false;
  bool isGJets = true;
  bool isGGJets = false;
  cout << "\nUsing sample: QCD " << isQCD << ", GJets " << isGJets << ", GGJets " << isGGJets << ", all " << isAll << endl;
  cout << endl;
  
  cout << endl;
  
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // make vector of sidebands
  int nSidebands = 8;
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) ); // show
  // chIsoSidebands.push_back( std::make_pair(6.,11.) );
  // chIsoSidebands.push_back( std::make_pair(7.,12.) );
  // chIsoSidebands.push_back( std::make_pair(8.,13.) ); // show
  // chIsoSidebands.push_back( std::make_pair(9.,14.) );
  // chIsoSidebands.push_back( std::make_pair(10.,15.) ); // show
  // chIsoSidebands.push_back( std::make_pair(15.,20.) );
  // chIsoSidebands.push_back( std::make_pair(10.,20.) );
  
  TFile *f_fit = TFile::Open("../../RooFitTemplateFitting/analysis/fakeRatePlots.root");
  TString matching_filename = "";
  if (isAll)  matching_filename = "../analysis/diphoton_fake_rate_closure_test_matching_all_QCD_GJets_GGJets_76X_MiniAOD_histograms.root";
  if (isQCD) matching_filename = "../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (isGJets) matching_filename = "../analysis/diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (isGGJets) matching_filename = "../analysis/diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  TFile *f_fake = TFile::Open(matching_filename);
  
  // convert histograms of fakes into graphs
  // EB
  TH1D *h_fakes_EB = (TH1D*) f_fake->Get("phoPtEB_passHighPtID_varbin");
  TGraphAsymmErrors* g_fakes_EB = new TGraphAsymmErrors();
  for (int i = 1; i < h_fakes_EB->GetSize()-1; i++) {
    // set x-location to match the fit result
    TGraphAsymmErrors *g_fit_EB = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEB_chIso5To10");
    double binWidth = h_fakes_EB->GetXaxis()->GetBinWidth(i);
    g_fakes_EB->SetPoint(i-1,g_fit_EB->GetX()[i-1],h_fakes_EB->GetBinContent(i) / binWidth);
    g_fakes_EB->SetPointError(i-1,g_fit_EB->GetX()[i-1]-h_fakes_EB->GetBinLowEdge(i),h_fakes_EB->GetBinLowEdge(i)+binWidth-g_fit_EB->GetX()[i-1],h_fakes_EB->GetBinErrorLow(i)/binWidth,h_fakes_EB->GetBinErrorUp(i)/binWidth);   
  }
  // EE
  TH1D *h_fakes_EE = (TH1D*) f_fake->Get("phoPtEE_passHighPtID_varbin");
  TGraphAsymmErrors* g_fakes_EE = new TGraphAsymmErrors();
  for (int i = 1; i < h_fakes_EE->GetSize()-1; i++) {
    // set x-location to match the fit result
    TGraphAsymmErrors *g_fit_EE = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEE_chIso5To10");
    double binWidth = h_fakes_EE->GetXaxis()->GetBinWidth(i);
    g_fakes_EE->SetPoint(i-1,g_fit_EE->GetX()[i-1],h_fakes_EE->GetBinContent(i) / binWidth);
    g_fakes_EE->SetPointError(i-1,g_fit_EE->GetX()[i-1]-h_fakes_EE->GetBinLowEdge(i),h_fakes_EE->GetBinLowEdge(i)+binWidth-g_fit_EE->GetX()[i-1],h_fakes_EE->GetBinErrorLow(i)/binWidth,h_fakes_EE->GetBinErrorUp(i)/binWidth);
    //fakes_EE->SetPointError(i,eXLow_EE,eXHigg_fit_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);
  }
  

  std::vector<TGraphAsymmErrors*> fit_EB;
  std::vector<TGraphAsymmErrors*> fit_EE;
  std::vector<TGraphAsymmErrors*> ratio_EB;
  std::vector<TGraphAsymmErrors*> ratio_EE;

  
  for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) { 
    double sidebandLow = it->first;
    double sidebandHigh = it->second;
    TString sideBand = Form("%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    
    std::cout << std::setprecision(2) << std::fixed;
    cout << "Using sideband " << sidebandLow << " < chIso < " << sidebandHigh << " GeV" << endl;
    
    TGraphAsymmErrors *g_fit_EB = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEB_chIso"+sideBand);
    g_fit_EB->SetName(sideBand);
    fit_EB.push_back(g_fit_EB);
    
    TGraphAsymmErrors* g_ratio_EB = new TGraphAsymmErrors();
    g_ratio_EB->SetName(sideBand);

    cout << "\nEB" << endl;
    for (int i = 0; i < g_fit_EB->GetN(); i++) {
      g_ratio_EB->SetPoint(i,g_fit_EB->GetX()[i],g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]);
      g_ratio_EB->SetPointError(i,
				g_fit_EB->GetErrorXlow(i),
				g_fit_EB->GetErrorXhigh(i),
				g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EB->GetErrorYlow(i)/g_fit_EB->GetY()[i],2)+TMath::Power(g_fakes_EB->GetErrorYlow(i)/g_fakes_EB->GetY()[i],2)),
				g_fit_EB->GetY()[i]/g_fakes_EB->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EB->GetErrorYhigh(i)/g_fit_EB->GetY()[i],2)+TMath::Power(g_fakes_EB->GetErrorYhigh(i)/g_fakes_EB->GetY()[i],2))
	);
      cout << "pt: " << g_fit_EB->GetX()[i] << ", prediction: " << g_fit_EB->GetY()[i] << ", actual: " << g_fakes_EB->GetY()[i] << ", prediction / actual: " <<  g_ratio_EB->GetY()[i] << endl;
    }
    ratio_EB.push_back(g_ratio_EB);

    
    TGraphAsymmErrors *g_fit_EE = (TGraphAsymmErrors*) f_fit->Get("bkgvsptEE_chIso"+sideBand);
    g_fit_EE->SetName(sideBand);
    fit_EE.push_back(g_fit_EE);
    
    TGraphAsymmErrors* g_ratio_EE = new TGraphAsymmErrors();
    g_ratio_EE->SetName(sideBand);

    cout << "\nEE" << endl;
    for (int i = 0; i < g_fit_EE->GetN(); i++) {
      g_ratio_EE->SetPoint(i,g_fit_EE->GetX()[i],g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]);
      g_ratio_EE->SetPointError(i,
				g_fit_EE->GetErrorXlow(i),
				g_fit_EE->GetErrorXhigh(i),
				g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EE->GetErrorYlow(i)/g_fit_EE->GetY()[i],2)+TMath::Power(g_fakes_EE->GetErrorYlow(i)/g_fakes_EE->GetY()[i],2)),
				g_fit_EE->GetY()[i]/g_fakes_EE->GetY()[i]*TMath::Sqrt(TMath::Power(g_fit_EE->GetErrorYhigh(i)/g_fit_EE->GetY()[i],2)+TMath::Power(g_fakes_EE->GetErrorYhigh(i)/g_fakes_EE->GetY()[i],2))
	);
      cout << "pt: " << g_fit_EE->GetX()[i] << ", prediction: " << g_fit_EE->GetY()[i] << ", actual: " << g_fakes_EE->GetY()[i] << ", prediction / actual: " <<  g_ratio_EE->GetY()[i] << endl;
    }
    ratio_EE.push_back(g_ratio_EE);
    
    cout << endl;
      
  } // end for loop over sidebands

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
  l_fit_vs_fake_EB->AddEntry(g_fakes_EB,"Actual number of fakes","elp");
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EB.begin(); it != fit_EB.end(); ++it) {
    auto pos = it - fit_EB.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString ch_iso_name = (TString) (*it)->GetName();
    ch_iso_name.ReplaceAll("To"," < Iso_{Ch} < ");
    l_fit_vs_fake_EB->AddEntry(*it,"Fake prediction using "+ch_iso_name+" GeV","le");
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
  l_fit_vs_fake_EE->AddEntry(g_fakes_EE,"Actual number of fakes","elp");
  
  for (std::vector<TGraphAsymmErrors*>::iterator it = fit_EE.begin(); it != fit_EE.end(); ++it) {
    auto pos = it - fit_EE.begin();
    (*it)->Draw("same");
    (*it)->SetMarkerColor(2+pos);
    (*it)->SetLineColor(2+pos);
    TString ch_iso_name = (TString) (*it)->GetName();
    ch_iso_name.ReplaceAll("To"," < Iso_{Ch} < ");
    l_fit_vs_fake_EE->AddEntry(*it,"Fake prediction using "+ch_iso_name+" GeV","le");
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

  
  c_fit_vs_fake->SaveAs("closure_test_fit_prediction_vs_actual_fake.pdf");

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
    TString ch_iso_name = (TString) (*it)->GetName();
    ch_iso_name.ReplaceAll("To"," < Iso_{Ch} < ");
    l_fit_over_fake_EB->AddEntry(*it,"Ratio using "+ch_iso_name+" GeV","pe");
  }

  ratio_EB.at(0)->SetTitle("EB");
  ratio_EB.at(0)->GetYaxis()->SetRangeUser(0,2);
  ratio_EB.at(0)->GetYaxis()->SetTitle("prediction / actual");
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
    TString ch_iso_name = (TString) (*it)->GetName();
    ch_iso_name.ReplaceAll("To"," < Iso_{Ch} < ");
    l_fit_over_fake_EE->AddEntry(*it,"Ratio using "+ch_iso_name+" GeV","pe");
  }

  ratio_EE.at(0)->SetTitle("EE");
  ratio_EE.at(0)->GetYaxis()->SetRangeUser(0,2);
  ratio_EE.at(0)->GetYaxis()->SetTitle("prediction / actual");
  ratio_EE.at(0)->GetYaxis()->SetTitleOffset(1.4);
  ratio_EE.at(0)->GetXaxis()->SetRangeUser(0,625);
  ratio_EE.at(0)->GetXaxis()->SetTitle("p_{T} (GeV)");

  l_fit_over_fake_EE->Draw();
  
  line_EE->Draw();
  
  c_fit_over_fake->SaveAs("closure_test_fit_prediction_over_actual_fake.pdf");

  
}
