// run in batch mode from "plots" directory
// root -l -b -q plot_fake_template_comparison.C
void plot_closure_test_fake_rate() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  TFile *f_fitNumerator = TFile::Open("../../RooFitTemplateFitting/analysis/fakeRatePlots.root");
  
  TFile *f_fakeNumerator = TFile::Open("../analysis/diphoton_fakeRate_matchedFakes_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TH1D *h_fakeNumeratorEB = (TH1D*) f_fakeNumerator->Get("phoPtEB_passHighPtID_varbin");
  TH1D *h_fakeNumeratorEE = (TH1D*) f_fakeNumerator->Get("phoPtEE_passHighPtID_varbin");

  for (int i=1; i<h_fakeNumeratorEB->GetSize()-1; i++) {
    double binWidth = h_fakeNumeratorEB->GetXaxis()->GetBinWidth(i);

    h_fakeNumeratorEB->SetBinContent(i,h_fakeNumeratorEB->GetBinContent(i) / binWidth);
    h_fakeNumeratorEB->SetBinError(i,h_fakeNumeratorEB->GetBinError(i) / binWidth);
    h_fakeNumeratorEE->SetBinContent(i,h_fakeNumeratorEE->GetBinContent(i) / binWidth);
    h_fakeNumeratorEE->SetBinError(i,h_fakeNumeratorEE->GetBinError(i) / binWidth);
  }
  
  // make vector of sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );
  //sieieEB_faketemplate_pt300To14000_chIso6To11
  
    TCanvas *canvas = new TCanvas("canvas","canvas",1500,600);
    canvas->Divide(2,1);
    
    // EB
    canvas->cd(1);
    h_fakeNumeratorEB->Draw();

    TLegend *legendEB = new TLegend(0.55,0.65,0.90,0.85);
    legendEB->SetBorderSize(0);
    legendEB->SetFillColor(0);
    legendEB->AddEntry(h_fakeNumeratorEB,"QCD Fakes passHighPtID","lp"); 
    
    int i = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) { 
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fitNumeratorEB = (TH1D*) f_fitNumerator->Get("bkgvsptEB_"+sideBand);
      h_fitNumeratorEB->Draw("same");
      h_fitNumeratorEB->SetLineColor(2+i);
      h_fitNumeratorEB->SetMarkerColor(2+i);
      legendEB->AddEntry(h_fitNumeratorEB,"QCD numerator after fit "+sideBand,"lp");
      i++;
    }

    h_fakeNumeratorEB->SetTitle("Closure test in EB");
    
    gPad->SetLogy();
    h_fakeNumeratorEB->SetMinimum(0.3);
    h_fakeNumeratorEB->SetMaximum(100.);
    
    legendEB->Draw();
    
    // EE
    canvas->cd(2);
    h_fakeNumeratorEE->Draw();

    TLegend *legendEE = new TLegend(0.55,0.65,0.90,0.85);
    legendEE->SetBorderSize(0);
    legendEE->SetFillColor(0);
    legendEE->AddEntry(h_fakeNumeratorEE,"QCD Fakes passHighPtID","lp");

    int j = 0;
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TString sideBand = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      TH1D *h_fitNumeratorEE = (TH1D*) f_fitNumerator->Get("bkgvsptEE_"+sideBand);
      h_fitNumeratorEE->Draw("same");
      h_fitNumeratorEE->SetLineColor(2+j);
      h_fitNumeratorEE->SetMarkerColor(2+j);
      legendEE->AddEntry(h_fitNumeratorEE,"QCD numerator after fit "+sideBand,"lp");
      j++;
    }
    
    h_fakeNumeratorEE->SetTitle("Closure test in EE");
    
    gPad->SetLogy();
    h_fakeNumeratorEE->SetMinimum(0.3);
    h_fakeNumeratorEE->SetMaximum(100.);
    
    legendEE->Draw();
    
    canvas->SaveAs("closure_test_fit_numerator_vs_fake_passHighPtID.png");
}
