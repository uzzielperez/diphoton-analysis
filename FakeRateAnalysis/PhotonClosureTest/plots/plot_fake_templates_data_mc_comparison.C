int plot_fake_templates_data_mc_comparison() {

  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  gROOT->ForceStyle();
  
  TFile *f_mc = TFile::Open("../analysis/diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root");
  TFile *f_data = TFile::Open("/uscms_data/d3/skaplan/diphotons/fakerate_chIso/CMSSW_7_6_4/src/diphoton-analysis/FakeRateAnalysis/DataFakeRateAnalysis/analysis/jetht_fakerate_2016input.root");

  const int nBins = 6;
  double ptBinArray[nBins] = { 50., 70., 90., 130., 200., 600. };

  // vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  //chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  //chIsoSidebands.push_back( std::make_pair(8.,13.) );
  //chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  // chIsoSidebands.push_back( std::make_pair(15.,20.) );
  //chIsoSidebands.push_back( std::make_pair(10.,20.) );
  
  
  // loop over chIso sidebands
  for (std::vector< std::pair<double,double> >::const_iterator it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
    auto pos = it - chIsoSidebands.begin();
    
    TString sideband = Form("chIso%dTo%d",(int)it->first,(int)it->second);
    TString label = Form("%d < Iso_{Ch} < %d GeV",(int)it->first,(int)it->second);
  
  
  
    // loop over pt bins
    for (int i = 0; i < nBins-1; ++i) {
	
      TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);
      TString pt_label = Form("%d < p_{T} < %d GeV",(int)ptBinArray[i],(int)ptBinArray[i+1]);

      // TLatex *label = new TLatex();
      // label->SetTextAlign(12);
      
      // EB
      TCanvas *c_EB = new TCanvas("c_EB_"+sideband+"_"+bin,"",800,600);
      	
      TLegend *legend_EB = new TLegend(0.55,0.65,0.85,0.85);
      legend_EB->SetBorderSize(0);
      legend_EB->SetFillColor(0);
      
      TH1D *h_mc_EB = (TH1D*) f_mc->Get("sieieEB_faketemplate_"+bin+"_"+sideband);
      h_mc_EB->Scale(1.0/h_mc_EB->Integral());
      TH1D* h_data_EB = (TH1D*) f_data->Get("sieieEB_faketemplate_"+bin+"_"+sideband);
      h_data_EB->Scale(1.0/h_data_EB->Integral());
      
      h_mc_EB->Draw("E"); // "HIST"
      h_mc_EB->SetMarkerColor(kBlue);
      h_mc_EB->SetLineColor(kBlue);
      h_mc_EB->SetTitle("EB, "+pt_label+", "+label);
      h_mc_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      h_mc_EB->SetMaximum(h_data_EB->GetMaximum()*1.3);
      h_mc_EB->GetYaxis()->SetTitleOffset(1.2);
      h_mc_EB->GetYaxis()->SetTitle("Events / "+TString::Format("%.4f",h_mc_EB->GetBinWidth(1)));
      
      h_data_EB->Draw("Esame");
      h_data_EB->SetMarkerColor(kRed);
      h_data_EB->SetLineColor(kRed);
      //h_data_EB->SetMarkerStyle(8);
      //h_data_EB->SetHistLineWidth(2);
      
      legend_EB->AddEntry(h_data_EB,"Data fake template","pe");
      legend_EB->AddEntry(h_mc_EB,"MC fake template","pe");
      legend_EB->Draw();

      // gPad->SetLogy();
      
      c_EB->SaveAs("fake_template_data_mc_comparison_sieie_template_EB_"+sideband+"_"+bin+".pdf");
      
      // EE
      TCanvas *c_EE = new TCanvas("c_EE_"+sideband+"_"+bin,"",800,600);
      
      TLegend *legend_EE = new TLegend(0.55,0.65,0.85,0.85);
      legend_EE->SetBorderSize(0);
      legend_EE->SetFillColor(0);
      
      TH1D *h_mc_EE = (TH1D*) f_mc->Get("sieieEE_faketemplate_"+bin+"_"+sideband);
      h_mc_EE->Scale(1.0/h_mc_EE->Integral());

      TH1D* h_data_EE = (TH1D*) f_data->Get("sieieEE_faketemplate_"+bin+"_"+sideband);
      h_data_EE->Scale(1.0/h_data_EE->Integral());

      h_mc_EE->Draw("E"); // "HIST"
      h_mc_EE->SetMarkerColor(kBlue);
      h_mc_EE->SetLineColor(kBlue);
      h_mc_EE->SetTitle("EE, "+pt_label+", "+label);
      h_mc_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
      h_mc_EE->GetYaxis()->SetTitleOffset(1.2);
      h_mc_EE->GetYaxis()->SetTitle("Events / "+TString::Format("%.3f",h_mc_EE->GetBinWidth(1)));
      h_mc_EE->SetMaximum(h_data_EE->GetMaximum()*1.2);

      h_data_EE->Draw("Esame");
      h_data_EE->SetMarkerColor(kRed);
      h_data_EE->SetLineColor(kRed);;

      legend_EE->AddEntry(h_data_EE,"Data fake template","pe");
      legend_EE->AddEntry(h_mc_EE,"MC fake template","pe");
      legend_EE->Draw();

      c_EE->SaveAs("fake_template_data_mc_comparison_sieie_template_EE_"+sideband+"_"+bin+".pdf");

    } // end of loop over pt bins
    
  } // end for loop over chIso sidebands
  
  return 0;
}
