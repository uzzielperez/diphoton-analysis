void compareToMCTruth(int year=2016){

   // int year = std::stoi(era);
   auto c1 = new TCanvas("c1","c1",200,10,700,500);
   auto mg = new TMultiGraph();

   const char *cmssw_base = getenv("CMSSW_BASE");
   if(cmssw_base==NULL) {
     std::cout << "Please issue cmsenv before running" << std::endl;
     exit(-1);
   }

   TFile *fFake = TFile::Open(Form("%s/src/fakeRatePlots_all_%d_nPV0-200.root", cmssw_base, year));
   TFile *fTruth = TFile::Open(Form("%s/src/fakeRatePlots_alltruth_%d_nPV0-200.root", cmssw_base, year));

   const std::string region = "EB";
   const std::string iso("chIso5To10");
   const TString graphName(Form("fakeRate%s_%s", region.c_str(), iso.c_str()));
   auto grTruth = dynamic_cast<TGraphAsymmErrors*>(fFake->Get(graphName));
   auto grFake = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(graphName));
   grTruth->SetLineColor(kRed);
   grFake->SetLineColor(kOrange);

   mg->Add(grTruth); grTruth->SetTitle("MC as Truth"); //grTruth->SetLineWidth(3);
   mg->Add(grFake); grFake->SetTitle("chIso5To10")  ; //grFake->SetLineWidth(3);

   // Extra chIso

   // auto grTruth = dynamic_cast<TGraphAsymmErrors*>(fFake->Get(graphName));
   // auto grFake = dynamic_cast<TGraphAsymmErrors*>(fTruth->Get(graphName));
   // grTruth->SetLineColor(kRed);
   // grFake->SetLineColor(kOrange);

   mg->SetTitle(Form("Closure Test %s", std::to_string(year).c_str()));
   mg->Draw("apl");
   //c1->BuildLegend();
   c1->BuildLegend(0.6,0.68,0.8,0.88);

   mg->GetHistogram()->GetXaxis()->SetRangeUser(0.,2.5);
   gPad->Modified();
   gPad->Update();
   c1->SaveAs(Form("closureTest_MCTruth_comparisons_%s.pdf", std::to_string(year).c_str()));

   return 0;
}
