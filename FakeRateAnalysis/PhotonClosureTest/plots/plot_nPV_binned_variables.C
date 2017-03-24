void plot_nPV_binned_variables() {
  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // get files
  // from QCD
  TFile *f_QCD = TFile::Open("../analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  // from GJets
  TFile *f_GJets = TFile::Open("../analysis/diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root");
  // from GGJets
  TFile *f_GGJets = TFile::Open("../analysis/diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");

  // vector of files
  std::vector<TFile*> files = {f_QCD, f_GJets, f_GGJets};

  // vector of ECAL regions
  std::vector<TString> region = {"","1","2"};

  // vector of nPV regions
  std::vector< std::pair<int,int> > nPV_regions;
  nPV_regions.push_back( std::make_pair(0,100000) ); // no cut
  nPV_regions.push_back( std::make_pair(0,13) );
  nPV_regions.push_back( std::make_pair(14,17) );
  nPV_regions.push_back( std::make_pair(18,20) );
  nPV_regions.push_back( std::make_pair(21,24) );
  nPV_regions.push_back( std::make_pair(25,100000) ); // 25-Inf
  
  // loop over each file
  for (std::vector<TFile*>::iterator it = files.begin(); it != files.end(); ++it) {

    // get string corresponding to filename
    auto pos = it - files.begin();
    TString filename = "";
    if (pos == 0) filename = "QCD";
    if (pos == 1) filename = "GJets";
    if (pos == 2) filename = "GGJets";
    cout << "Using filename: " << filename << endl;
    cout << "File path: " << (*it)->GetName() << endl;

    // loop through ECAL regions
    for (TString reg : region) {

      TLegend *legend = new TLegend(0.50,0.50,0.85,0.85);
      legend->SetBorderSize(0);
      legend->SetFillColor(0);
      
      TCanvas *c = new TCanvas("c_EBEE"+reg+"_"+filename,"",1500,900);
      c->Divide(2,2);
      
      // loop over nPV bins
      for (std::vector<std::pair<int,int> >::const_iterator pv = nPV_regions.begin(); pv != nPV_regions.end(); ++pv) {

	auto pv_pos = pv-nPV_regions.begin();
	
	TString pv_low = Form("%d",pv->first);
	TString pv_high = Form("%d",pv->second);

	c->cd(1);
	TH1D *h_phoIso_EB = (TH1D*) (*it)->Get("photonIso_EB"+reg+"_nPV"+pv_low+"To"+pv_high);
	h_phoIso_EB->Scale(1.0/h_phoIso_EB->Integral());
	// cout << h_phoIso_EB->GetName() << endl;
	if (pv_pos == 0) {
	  h_phoIso_EB->Draw("HIST");
	  h_phoIso_EB->SetTitle("EB"+reg);
	  h_phoIso_EB->GetYaxis()->SetRangeUser(0,1);
	  h_phoIso_EB->GetXaxis()->SetRangeUser(-1,5);
	  h_phoIso_EB->GetXaxis()->SetTitle("Iso_{#gamma} (GeV)");
	}
	else h_phoIso_EB->Draw("HISTsame");
	h_phoIso_EB->SetMarkerColor(1+pv_pos);
	h_phoIso_EB->SetLineColor(1+pv_pos);
	legend->AddEntry(h_phoIso_EB,pv_low+" #leq nPV #leq "+pv_high,"l");
	legend->Draw();
	
	c->cd(2);
	TH1D *h_phoIso_EE = (TH1D*) (*it)->Get("photonIso_EE"+reg+"_nPV"+pv_low+"To"+pv_high);
	h_phoIso_EE->Scale(1.0/h_phoIso_EE->Integral());
	// cout << h_phoIso_EE->GetName() << endl;
	if (pv-nPV_regions.begin() == 0) {
	  h_phoIso_EE->Draw("HIST");
	  h_phoIso_EE->SetTitle("EE"+reg);
	  h_phoIso_EE->GetYaxis()->SetRangeUser(0,1);
	  h_phoIso_EE->GetXaxis()->SetRangeUser(-1,5);
	  h_phoIso_EE->GetXaxis()->SetTitle("Iso_{#gamma} (GeV)");
	}
	else h_phoIso_EE->Draw("HISTsame");
	h_phoIso_EE->SetMarkerColor(1+pv_pos);
	h_phoIso_EE->SetLineColor(1+pv_pos);
	legend->Draw();
	
	c->cd(3);
	TH1D *h_corPhoIso_EB = (TH1D*) (*it)->Get("corPhotonIso_EB"+reg+"_nPV"+pv_low+"To"+pv_high);
	h_corPhoIso_EB->Scale(1.0/h_corPhoIso_EB->Integral());
	if (pv-nPV_regions.begin() == 0) {
	  h_corPhoIso_EB->Draw("HIST");
	  h_corPhoIso_EB->SetTitle("EB"+reg);
	  h_corPhoIso_EB->GetYaxis()->SetRangeUser(0,0.70);
	  h_corPhoIso_EB->GetXaxis()->SetRangeUser(-5,4);
	  h_corPhoIso_EB->GetXaxis()->SetTitle("#bar{Iso_{#gamma}} (GeV)");
	}
	else h_corPhoIso_EB->Draw("HISTsame");
	h_corPhoIso_EB->SetMarkerColor(1+pv_pos);
	h_corPhoIso_EB->SetLineColor(1+pv_pos);
	
	c->cd(4);
	TH1D *h_corPhoIso_EE = (TH1D*) (*it)->Get("corPhotonIso_EE"+reg+"_nPV"+pv_low+"To"+pv_high);
	h_corPhoIso_EE->Scale(1.0/h_corPhoIso_EE->Integral());
	if (pv-nPV_regions.begin() == 0) {
	  h_corPhoIso_EE->Draw("HIST");
	  h_corPhoIso_EE->SetTitle("EE"+reg);
	  h_corPhoIso_EE->GetYaxis()->SetRangeUser(0,0.70);
	  h_corPhoIso_EE->GetXaxis()->SetRangeUser(-5,3);
	  h_corPhoIso_EE->GetXaxis()->SetTitle("#bar{Iso_{#gamma}} (GeV)");
	}
	else h_corPhoIso_EE->Draw("HISTsame");
	h_corPhoIso_EE->SetMarkerColor(1+pv_pos);
	h_corPhoIso_EE->SetLineColor(1+pv_pos);
	
      } // end for loop over nPV bins

      c->SaveAs("photon_isolation_EEEB"+reg+"_nPV_binned_"+filename+"_MC.pdf");
      
    } // end for loop over ECAL regions
    
  } // end loop over files
  
}
