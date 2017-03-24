// to run:
// root -l -q -b plot_sieie_templates.C

void plot_sieie_templates() {

  // set global root options
  gROOT->SetStyle("Plain");
  //gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat("ourmei");

  // get real template file
  // from GGJets+GJets
  TFile *f = TFile::Open("../analysis/diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root");
  // from GGJets
  // TFile *f = TFile::Open("../analysis/diphoton_fake_rate_real_templates_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  
  
  // pt bins
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // loop over pt bins
  for (int i = 0; i < nBins-1; ++i) {
    
    TString bin = Form("pt%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    TCanvas *c = new TCanvas("c_"+bin,"",1500,900);
    c->Divide(2,2);
    
    // EB - linear
    c->cd(1);
    TH1D *h_EB = (TH1D*) f->Get("sieieEB_realtemplate_"+bin);
    h_EB->Draw();
    h_EB->SetTitle("EB "+bin);
    h_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_EB->GetXaxis()->SetRangeUser(0,0.03);
    // EB - log
    c->cd(2);
    h_EB->Draw();
    gPad->SetLogy();
    // EE - linear
    c->cd(3);
    TH1D *h_EE = (TH1D*) f->Get("sieieEE_realtemplate_"+bin);
    h_EE->Draw();
    h_EE->SetTitle("EE "+bin);
    h_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_EE->GetXaxis()->SetRangeUser(0,0.07);
    // EE - log
    c->cd(4);
    h_EE->Draw();
    gPad->SetLogy();

    c->SaveAs("real_templates_sieie_"+bin+".png");
    
  } // end for loop over pt bins
  
}
