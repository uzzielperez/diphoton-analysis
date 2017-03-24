void plot_fake_numerator () {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  std::vector<string> samples;
  samples.push_back("all");
  // samples.push_back("5to10");
  // samples.push_back("10to15");
  // samples.push_back("15to30");
  // samples.push_back("30to50");
  // samples.push_back("50to80");
  // samples.push_back("80to120");
  // samples.push_back("120to170");
  // samples.push_back("170to300");
  // samples.push_back("300to470");
  // samples.push_back("470to600");
  // samples.push_back("600to800");
  // samples.push_back("800to1000");
  // samples.push_back("1000to1400");
  // samples.push_back("1400to1800");
  // samples.push_back("1800to2400");
  // samples.push_back("2400to3200");
  // samples.push_back("3200toInf");

  THStack *h_EB = new THStack("h_EB","");
  THStack *h_EE = new THStack("h_EE","");

  TLegend *l_EB = new TLegend(0.50,0.20,0.85,0.85);
  TLegend *l_EE = new TLegend(0.50,0.20,0.85,0.85);
  
  for (std::vector<string>::iterator it = samples.begin(); it != samples.end(); ++it) {
    cout << "Using sample: " << *it << endl;
    TString bin = (*it).c_str();
    int pos = it-samples.begin();
    TFile *f_fakeNumerator = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_"+bin+"_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
    TH1D *h_fakeNumeratorEB = (TH1D*) f_fakeNumerator->Get("phoPtEB_passHighPtID_varbin");
    TH1D *h_fakeNumeratorEE = (TH1D*) f_fakeNumerator->Get("phoPtEE_passHighPtID_varbin");

    for (int i=1; i<h_fakeNumeratorEB->GetSize()-1; i++) {
      double binWidth = h_fakeNumeratorEB->GetXaxis()->GetBinWidth(i);
      h_fakeNumeratorEB->SetBinContent(i,h_fakeNumeratorEB->GetBinContent(i) / binWidth);
      h_fakeNumeratorEB->SetBinError(i,h_fakeNumeratorEB->GetBinError(i) / binWidth);
      h_fakeNumeratorEE->SetBinContent(i,h_fakeNumeratorEE->GetBinContent(i) / binWidth);
      h_fakeNumeratorEE->SetBinError(i,h_fakeNumeratorEE->GetBinError(i) / binWidth);
    }

    l_EB->AddEntry(h_fakeNumeratorEB,"QCD_Pt_"+bin,"lp");
    l_EE->AddEntry(h_fakeNumeratorEE,"QCD_Pt_"+bin,"lp");

    if (pos > 8) pos=pos*4-11;
    
    h_fakeNumeratorEB->SetMarkerStyle(kPlus);
    h_fakeNumeratorEB->SetLineColor(1+pos);
    h_fakeNumeratorEB->SetMarkerColor(1+pos);
    h_fakeNumeratorEE->SetMarkerStyle(kPlus);
    h_fakeNumeratorEE->SetLineColor(1+pos);
    h_fakeNumeratorEE->SetMarkerColor(1+pos);
    
    h_EB->Add(h_fakeNumeratorEB);
    h_EE->Add(h_fakeNumeratorEE);
    
  } // end loop over samples

  l_EB->SetBorderSize(0);
  l_EB->SetFillColor(0);
  l_EE->SetBorderSize(0);
  l_EE->SetFillColor(0);
  
  TCanvas *c_fakes = new TCanvas("c_fakes","",1500,600);
  c_fakes->Divide(2,2);

  c_fakes->cd(1);
  h_EB->Draw();
  l_EB->Draw();
  h_EB->SetTitle("EB");
  h_EB->GetYaxis()->SetTitle("fakes / bin width");
  h_EB->GetXaxis()->SetTitle("p_{T} (GeV)");
  
  c_fakes->cd(2);
  h_EB->Draw();
  gPad->SetLogy();

  c_fakes->cd(3);
  h_EE->Draw();
  l_EE->Draw();
  h_EE->SetTitle("EE");
  h_EE->GetYaxis()->SetTitle("fakes / bin width");
  h_EE->GetXaxis()->SetTitle("p_{T} (GeV)");
  
  c_fakes->cd(4);
  h_EE->Draw();
  gPad->SetLogy();

  c_fakes->SaveAs("fake_numerator_from_matching.png");
}
