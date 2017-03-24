// to run:
// root -l -q -b plot_fake_templates.C

// plot fake templates using all chIso and sieie sidebands for each pt bin
void plot_fake_templates() {

  // set global root options
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // get fake template file
  // from QCD
  // TFile *f = TFile::Open("../analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  // from GJets
  TFile *f = TFile::Open("../analysis/diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root");
  
  // vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );

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
  
  // pt bins
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // loop over pt bins
  for (int i = 0; i < nBins-1; ++i) {
    
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);
    
    // loop over chIso sidebands EB
    TCanvas *c_EB_sieie = new TCanvas("c_EB_sieie_"+bin,"",1500,900);
    c_EB_sieie->Divide(2,1);
    TLegend *legend_EB_sieie = new TLegend(0.55,0.65,0.85,0.85);
    legend_EB_sieie->SetBorderSize(0);
    legend_EB_sieie->SetFillColor(0);
    for (std::vector< std::pair<double,double> >::const_iterator it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      auto pos = it - chIsoSidebands.begin();
      
      TString sideband = Form("chIso%dTo%d",(int)it->first,(int)it->second);
      TString label = Form("%d < Iso_{CH} < %d GeV",(int)it->first,(int)it->second);
      
      // EB - linear
      c_EB_sieie->cd(1);
      TH1D *h = (TH1D*) f->Get("sieieEB_faketemplate_"+bin+"_"+sideband);
      if (pos == 0) {
	h->Draw("HIST");
	h->SetTitle("EB "+bin);
	h->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
	h->GetXaxis()->SetRangeUser(0,0.03);
	h->SetMaximum(1.2*h->GetMaximum());
      }
      else {
	h->Draw("HISTsame");
	h->SetMarkerColor(1+pos);
	h->SetLineColor(1+pos);
      }
      legend_EB_sieie->AddEntry(h,label,"l");
      legend_EB_sieie->Draw();
      // EB - log
      c_EB_sieie->cd(2);
      if (pos == 0) h->Draw("HIST");
      else h->Draw("HISTsame");
      gPad->SetLogy();
    } // end for loop over chIso sidebands EB
    c_EB_sieie->SaveAs("fake_template_sieie_EB_"+bin+".pdf");
    
    // loop over chIso sidebands EE
    TCanvas *c_EE_sieie = new TCanvas("c_EE_sieie_"+bin,"",1500,900);
    c_EE_sieie->Divide(2,1);
    TLegend *legend_EE_sieie = new TLegend(0.55,0.65,0.85,0.85);
    legend_EE_sieie->SetBorderSize(0);
    legend_EE_sieie->SetFillColor(0);
    for (std::vector< std::pair<double,double> >::const_iterator it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      auto pos = it - chIsoSidebands.begin();
      
      TString sideband = Form("chIso%dTo%d",(int)it->first,(int)it->second);
      TString label = Form("%d < Iso_{CH} < %d GeV",(int)it->first,(int)it->second);
            
      // EE - linear
      c_EE_sieie->cd(1);
      TH1D *h = (TH1D*) f->Get("sieieEE_faketemplate_"+bin+"_"+sideband);
      if (pos == 0) {
	h->Draw("HIST");
	h->SetTitle("EE "+bin);
	h->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
	h->GetXaxis()->SetRangeUser(0,0.07);
	h->SetMaximum(1.2*h->GetMaximum());
      }
      else {
	h->Draw("HISTsame");
	h->SetMarkerColor(1+pos);
	h->SetLineColor(1+pos);
      }
      legend_EE_sieie->AddEntry(h,label,"l");
      legend_EE_sieie->Draw();
      // EE - log
      c_EE_sieie->cd(2);
      if (pos == 0) h->Draw("HIST");
      else h->Draw("HISTsame");
      gPad->SetLogy();
    } // end for loop over chIso sidebands EE
    c_EE_sieie->SaveAs("fake_template_sieie_EE_"+bin+".pdf");
    
    // loop over sieie sidebands EB
    TCanvas *c_EB_chIso = new TCanvas("c_EB_chIso_"+bin,"",1500,900);
    c_EB_chIso->Divide(2,1);
    TLegend *legend_EB_chIso = new TLegend(0.55,0.65,0.85,0.85);
    legend_EB_chIso->SetBorderSize(0);
    legend_EB_chIso->SetFillColor(0);
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EB_sidebands.begin(); it != sieie_EB_sidebands.end(); ++it) {
      auto pos = it - sieie_EB_sidebands.begin();
      
      TString sideband = Form("sieie%1.4fTo%1.4f",it->first,it->second);
      TString label = Form("%1.4f < #sigma_{i#etai#eta} < %1.4f",it->first,it->second);
      
      // EB - linear
      c_EB_chIso->cd(1);
      TH1D *h = (TH1D*) f->Get("chIsoEB_faketemplate_"+bin+"_"+sideband);
      if (pos == 0) {
	h->Draw("HIST");
	h->SetTitle("EB "+bin);
	h->GetXaxis()->SetTitle("Iso_{CH} (GeV)");
	h->GetXaxis()->SetRangeUser(0,50);
	h->SetMaximum(1.2*h->GetMaximum());
      }
      else {
	h->Draw("HISTsame");
	h->SetMarkerColor(1+pos);
	h->SetLineColor(1+pos);
      }
      legend_EB_chIso->AddEntry(h,label,"l");
      legend_EB_chIso->Draw();
      // EB - log
      c_EB_chIso->cd(2);
      if (pos == 0) h->Draw("HIST");
      else h->Draw("HISTsame");
      gPad->SetLogy();
    } // end for loop over sieie sidebands EB
    c_EB_chIso->SaveAs("fake_template_chIso_EB_"+bin+".pdf");
    
    // loop over sieie sidebands EE
    TCanvas *c_EE_chIso = new TCanvas("c_EE_chIso_"+bin,"",1500,900);
    c_EE_chIso->Divide(2,1);
    TLegend *legend_EE_chIso = new TLegend(0.55,0.65,0.85,0.85);
    legend_EE_chIso->SetBorderSize(0);
    legend_EE_chIso->SetFillColor(0);
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EE_sidebands.begin(); it != sieie_EE_sidebands.end(); ++it) {
      auto pos = it - sieie_EE_sidebands.begin();
      
      TString sideband = Form("sieie%1.4fTo%1.4f",it->first,it->second);
      TString label = Form("%1.4f < #sigma_{i#etai#eta} < %1.4f",it->first,it->second);
            
      // EE - linear
      c_EE_chIso->cd(1);
      TH1D *h = (TH1D*) f->Get("chIsoEE_faketemplate_"+bin+"_"+sideband);
      if (pos == 0) {
	h->Draw("HIST");
	h->SetTitle("EE "+bin);
	h->GetXaxis()->SetTitle("Iso_{CH} (GeV)");
	h->GetXaxis()->SetRangeUser(0,50);
	h->SetMaximum(1.2*h->GetMaximum());
      }
      else {
	h->Draw("HISTsame");
	h->SetMarkerColor(1+pos);
	h->SetLineColor(1+pos);
      }
      legend_EE_chIso->AddEntry(h,label,"l");
      legend_EE_chIso->Draw();
      // EE - log
      c_EE_chIso->cd(2);
      if (pos == 0) h->Draw("HIST");
      else h->Draw("HISTsame");
      gPad->SetLogy();
    } // end for loop over sieie sidebands EE
    c_EE_chIso->SaveAs("fake_template_chIso_EE_"+bin+".pdf");
    
  } // end for loop over pt bins
  
}
