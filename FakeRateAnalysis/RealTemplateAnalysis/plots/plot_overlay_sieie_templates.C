// to run:
// root -l -q -b plot_sieie_templates.C

void plot_overlay_sieie_templates() {
  // set global root options
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(8);
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  // get real template file
  // from GGJets+GJets
  TFile *f = TFile::Open("../analysis/diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root");
  // from GGJets
  // TFile *f = TFile::Open("../analysis/diphoton_fake_rate_real_templates_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  
  // pt bins
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  TCanvas *c = new TCanvas("c_","",1500,900);
  c->Divide(2,1);

  TLegend *legend = new TLegend(0.55,0.65,0.85,0.85);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  
  int j = 0;
  
  // loop over pt bins
  for (int i = 0; i < nBins-1; ++i) {
    
    TString bin = Form("%dTo%d",(int)ptBinArray[i],(int)ptBinArray[i+1]);

    if (bin != "50To70" && bin != "110To130" && bin != "200To250" && bin != "300To600") continue;
    
    TString label = bin;
    label.ReplaceAll("To"," < p_{T} < ");
    label += " GeV";
    
    // EB - linear
    c->cd(1);
    TH1D *h_EB = (TH1D*) f->Get("sieieEB_realtemplate_pt"+bin);
    legend->AddEntry(h_EB,label,"ep");
    if (j == 0) h_EB->Draw("HIST");
    else {
      h_EB->Draw("HISTsame");
      h_EB->SetMarkerColor(1+j);
      h_EB->SetLineColor(1+j);
    }
    h_EB->SetTitle("EB");
    h_EB->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_EB->GetXaxis()->SetRangeUser(0,0.03);
    h_EB->GetYaxis()->SetTitle("Events / ( 0.0005 )");
    h_EB->GetYaxis()->SetRangeUser(10e-9,10e-1);
    h_EB->GetYaxis()->SetTitleOffset(1.6);
    legend->Draw();
    gPad->SetLogy();

    // EE
    c->cd(2);
    TH1D *h_EE = (TH1D*) f->Get("sieieEE_realtemplate_pt"+bin);
    if (j == 0) h_EE->Draw("HIST");
    else {
      h_EE->Draw("HISTsame");
      h_EE->SetMarkerColor(1+j);
      h_EE->SetLineColor(1+j);
    }
    h_EE->SetTitle("EE");
    h_EE->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
    h_EE->GetXaxis()->SetRangeUser(0,0.07);
    h_EE->GetYaxis()->SetTitle("Events / ( 0.001 )");
    h_EE->GetYaxis()->SetRangeUser(10e-9,10e-1);
    h_EE->GetYaxis()->SetTitleOffset(1.6);
    legend->Draw();
    gPad->SetLogy();

    j++;
  } // end for loop over pt bins

  c->SaveAs("real_templates_sieie_overlaid.pdf");
  
}
