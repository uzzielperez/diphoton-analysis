TString graphNamer(std::string region, std::string iso){
  const TString graphName(Form("fakeRate%s_%s", region.c_str(), iso.c_str()));
  return graphName;
}

void add_gr(int year, std::string region="EE"){

  auto c1 = new TCanvas("c1","c1",200,10,700,500);
  auto mg = new TMultiGraph();

  auto *padRatio = new TPad("padRatio","padRatio",0.,0.,1.,0.3); padRatio->Draw();
  padRatio->SetTopMargin(0.001);
  padRatio->SetBottomMargin(0.3);
  // padRatio->SetLogx ();
  padRatio->SetGrid();

  auto *p1 = new TPad("p1","p1",0.,0.3,1.,1.);  p1->Draw();
  p1->SetBottomMargin(0.08);
  p1->cd();
  p1->SetGrid();
  //p1->SetLogx();
  //p1->SetLogy();

  const char *cmssw_base = getenv("CMSSW_BASE");
  if(cmssw_base==NULL) {
    std::cout << "Please issue cmsenv before running" << std::endl;
    exit(-1);
  }

  TFile *fFake = TFile::Open(Form("%s/src/fakeRatePlots_all_%d_nPV0-200.root", cmssw_base, year));
  TFile *fTruth = TFile::Open(Form("%s/src/fakeRatePlots_alltruth_%d_nPV0-200.root", cmssw_base, year));

  const std::string iso("chIso5To10");
  // const TString graphName(Form("fakeRate%s_%s", region.c_str(), iso.c_str()));

  auto grTruth = dynamic_cast<TGraphAsymmErrors*>(fFake->Get(graphNamer(region, iso)));
  auto grFake = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(graphNamer(region, iso)));

  grTruth->SetLineColor(kOrange);
  grFake->SetLineColor(kRed);
  mg->Add(grTruth); grTruth->SetTitle("MC as Truth"); //grTruth->SetLineWidth(3);
  mg->Add(grFake); grFake->SetTitle("chIso5To10")  ; //grFake->SetLineWidth(3);


  // Uncomment for Additional ChIso comparisons
  // auto grFake1 = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(graphNamer(region, "chIso10To15")));
  // auto grFake1 = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(Form("fakeRate%s_%s", region.c_str(), "chIso10To15")));
  // auto grFake2 = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(Form("fakeRate%s_%s", region.c_str(), "chIso15To20")));
  // grFake1->SetLineColor(kBlue);
  // grFake2->SetLineColor(kGreen);
  // mg->Add(grFake1); grFake1->SetTitle("chIso10To15");
  // mg->Add(grFake2); grFake2->SetTitle("chIso15To20");


  mg->SetTitle(Form("Closure Test %s %s", std::to_string(year).c_str(), region.c_str()));
  mg->Draw("apl");
  //c1->BuildLegend();
  p1->BuildLegend(0.6,0.68,0.8,0.88);

  mg->GetHistogram()->GetXaxis()->SetRangeUser(0.,2.5);
  gPad->Modified();
  gPad->Update();

  padRatio->cd();

  // TH1F *hTruth = grTruth->GetHistogram();
  // TH1F *hFake = grFake->GetHistogram();
  // TH1F *hRatio = (TH1F*)hTruth->Clone("hTruth");
  //
  // hRatio->Sumw2();
  // hRatio->SetStats(0);
  // hRatio->Divide(hFake);
  // hRatio->SetMarkerStyle(21);
  // hRatio->Draw("ep");

  std::vector<int> ptBinArray({ 50, 70, 90, 110, 130, 150, 200, 250, 300, 600});
  std::vector<double> ptBinArray_double;
  for (auto iBin : ptBinArray) {
    ptBinArray_double.push_back(static_cast<double>(iBin));
  }

  const int nBins = ptBinArray.size();
  // TGraph*r = new TGraph(nBins); r->SetTitle("");
  TGraphAsymmErrors* r = new TGraphAsymmErrors();

  for (int i = 0; i < nBins-1; i++){
    double ptLow = ptBinArray_double[i];
    double ptHigh = ptBinArray_double[i+1];
    double ptBinSize = ptHigh - ptLow;
    TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

    double x = (ptLow+ptHigh)/2;
    //double x = ptBinArray[i];
    double y = grFake->Eval(x)/grTruth->Eval(x);

    std::cout << binName << ": " << x << ": " << y << std::endl;
    r->SetPoint(i, x, y);
    //r->SetPointError(i, );
  }

  //r->GetHistogram()->GetXaxis()->SetRangeUser(1,2.5);
  //r->GetXaxis()->SetLimits(0.2,2.5);
  r->GetHistogram()->GetXaxis()->SetTitle("pT (GeV)");
  r->GetXaxis()->SetLabelSize(0.075);
  r->GetYaxis()->SetLabelSize(0.075);
  r->Draw("AL");

  c1->SaveAs(Form("closureTest_MCTruth_comparisons%s_%s.pdf", region.c_str(), std::to_string(year).c_str()));
  return 0;

}

void compareToMCTruth(int year=2016, bool setBatch=true){

   if (setBatch) gROOT->SetBatch();

   add_gr(year, "EB");
   add_gr(year, "EE");

   return 0;
}
