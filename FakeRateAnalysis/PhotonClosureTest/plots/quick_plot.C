int plot(TFile *qcd, TFile *gjets, TString *name) {
  TLegend *l = new TLegend(0.75,0.75,0.85,0.85);
  l->SetBorderSize(0);
  l->SetFillColor(0);
  TCanvas *c = new TCanvas("c","",800,600);
  TH1D *h_qcd = (TH1D*) qcd->Get(name);
  TH1D *h_gjets = (TH1D*) gjets->Get(name);
  l->AddEntry(h_qcd,"QCD","pe");
  l->AddEntry(h_gjets,"GJets","pe");
  h_qcd->Scale(1.0/h_qcd->Integral());
  h_gjets->Scale(1.0/h_gjets->Integral());
  h_qcd->Draw();
  h_gjets->Draw("same");
  h_gjets->SetMarkerColor(kRed);
  gPad->SetLogy();
  TString n = (TString) name;
  h_qcd->SetTitle(n);
  l->Draw();
  c->SaveAs("comp_"+n+".pdf");
  delete c;
  return 0;
}

void quick_plot() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  TFile *qcd = TFile::Open("../analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *gjets = TFile::Open("../analysis/diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root");

  TFile *qcd_match = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  TFile *gjets_match = TFile::Open("../analysis/diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root");
  
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  
  vector<TString> ecal = {"EB","EE"};
  for (vector<TString>::iterator it=ecal.begin(); it != ecal.end(); it++) {
    plot(qcd,gjets,"photon_pt_denominator_"+*it);
    plot(qcd,gjets,"photon_eta_denominator_"+*it);
    plot(qcd,gjets,"photon_phi_denominator_"+*it);

    plot(qcd_match,gjets_match,"photon_fakes_sIeIe_"+*it);
    plot(qcd_match,gjets_match,"photon_fakes_pt_"+*it);
    plot(qcd_match,gjets_match,"photon_fakes_eta_"+*it);
    plot(qcd_match,gjets_match,"photon_fakes_phi_"+*it);
    plot(qcd_match,gjets_match,"pt_all_fakes_"+*it);
    plot(qcd_match,gjets_match,"sieie_all_fakes_"+*it);
    
    for (int i = 0; i < nBins-1; ++i) {
      TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);
      plot(qcd,gjets,"sieie"+*it+"_numerator_"+bin);
      //plot(qcd,gjets,"Pt"+*it+"_denominator_"+bin);
      plot(qcd,gjets,"sieie"+*it+"_faketemplate_"+bin+"_chIso5To10");

      plot(qcd_match,gjets_match,"sieie"+*it+"_numerator_photonHadronMother_"+bin);
    }
    
  }
  

  
}
