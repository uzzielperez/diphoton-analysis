/**
 * Produces fake rate plot as a function of pT
 *
 * This function calls /analysis/rooFitFakeRateProducer.C
 * From /analysis, run
 * root -l -b -q ../scripts/fakeRateCalculation.C'("mc","sieie", era)'
 * where year = 2016 or 2017
 */

#include "rooFitFakeRateProducer.C"

double fakeRateUncertainty(double denominator, double fakeerror, double fakerate) {
  double uncert = TMath::Sqrt((fakeerror*fakeerror/denominator/denominator) + (fakerate*fakerate/denominator));
  return uncert;
}

void fakeRateCalculation(TString sample, TString templateVariable, TString era)
{
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();
  
  cout << "\nStarting fakeRateCalculation()\n" << endl;
  
  if (!era.Contains("2016") && !era.Contains("2017") && !era.Contains("2018")) {
    cout << "Only years 2016, 2017 and 2018 are supported" << endl;
    return;
  }

  if (sample != "jetht" && sample != "doublemuon" && sample != "mc" && sample != "mc_QCD" && sample != "mc_GJets" && sample != "mc_GGJets") {
    cout << "Choose sample: jetht, doublemuon, mc, mc_QCD, mc_GJets, or mc_GGJets\n" << endl;
    return;
  }

  cout << "Using sample: " << sample << endl;

  if (templateVariable != "sieie" && templateVariable != "chIso") {
    cout << "Choose template variable: sieie or chIso\n" << endl;
    return;
  }

  cout << "Using template variable: " << templateVariable << endl;
  
  // array of pt bin edges
  std::vector<int> ptBinArray({ 50, 70, 90, 110, 130, 150});
  // With higher statistics in JetHT sample, additional bins can be used
  if(sample=="jetht") {
    ptBinArray.push_back(200);
    ptBinArray.push_back(250);
    ptBinArray.push_back(300);
  }
  ptBinArray.push_back(600);
  std::vector<double> ptBinArray_double;
  for (auto iBin : ptBinArray) {
    ptBinArray_double.push_back(static_cast<double>(iBin));
  }
  const int nBins = ptBinArray.size();

  // make vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
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

  std::vector< std::pair<double,double> > sidebandsEB, sidebandsEE;
  if (templateVariable == "sieie") {
    sidebandsEB = chIsoSidebands;
    sidebandsEE = chIsoSidebands;
  }
  else if (templateVariable == "chIso") {
    sidebandsEB = sieie_EB_sidebands;
    sidebandsEE = sieie_EE_sidebands;
  }
  
  std::vector<TGraphAsymmErrors*> fakeRatesEB;
  std::vector<TGraphAsymmErrors*> fakeRatesEE;
  std::vector<TGraphAsymmErrors*> bkgVsPtEBVec;
  std::vector<TGraphAsymmErrors*> bkgVsPtEEVec;
  
  for (unsigned int i = 0; i < sidebandsEB.size(); i++) {
    double sidebandLow = sidebandsEB.at(i).first;
    double sidebandHigh = sidebandsEB.at(i).second;
    TString postFix = "";
    if (templateVariable == "sieie")
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    else if (templateVariable == "chIso")
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
    
    TGraphAsymmErrors* fakeRateEB = new TGraphAsymmErrors();
    fakeRateEB->SetName("fakeRateEB"+postFix);
    fakeRateEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB.push_back(fakeRateEB);
    
    TGraphAsymmErrors* bkgvsptEB = new TGraphAsymmErrors();
    bkgvsptEB->SetName("bkgvsptEB"+postFix);
    bkgvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgVsPtEBVec.push_back(bkgvsptEB);
  }

  for (unsigned int i = 0; i < sidebandsEE.size(); i++) {
    double sidebandLow = sidebandsEE.at(i).first;
    double sidebandHigh = sidebandsEE.at(i).second;
    TString postFix = "";
    if (templateVariable == "sieie")
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    else if (templateVariable == "chIso")
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
    
    TGraphAsymmErrors* fakeRateEE = new TGraphAsymmErrors();
    fakeRateEE->SetName("fakeRateEE"+postFix);
    fakeRateEE->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE.push_back(fakeRateEE);
    
    TGraphAsymmErrors* bkgvsptEE = new TGraphAsymmErrors();
    bkgvsptEE->SetName("bkgvsptEE"+postFix);
    bkgvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");
    bkgVsPtEEVec.push_back(bkgvsptEE);
  }
  
  TFile outfile("fakeRatePlots_" + sample + "_" + era + ".root","recreate");
  outfile.Close(); // create the file so it can be updated in the rooFitFakeRateProducer, we don't need it open here too

  TString input_filename;
  //  if (sample == "data")      input_filename = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_vanilla.root";
  //  if (sample == "data")      input_filename = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_UNKNOWN_newDenomDef.root";
  if (sample == "jetht" or sample == "doublemuon") {
    input_filename = "../../DataFakeRateAnalysis/analysis/" + sample + "_fakerate_" + era + "_newDenomDef.root";
  }
  if (sample == "mc")        input_filename = "../../PhotonClosureTest/analysis/diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root";
  if (sample == "mc_QCD")    input_filename = "../../PhotonClosureTest/analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "mc_GJets")  input_filename = "../../PhotonClosureTest/analysis/diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "mc_GGJets") input_filename = "../../PhotonClosureTest/analysis/diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  TFile infile(input_filename,"read");
  
  // debug vectors
  std::vector<double> numVec;
  std::vector<double> denomVec;
  
  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
    for (int i = 0; i < nBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      infile.cd();

      double sidebandLow = sidebandsEB.at(j).first;
      double sidebandHigh = sidebandsEB.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")
	postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso")
	postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      
      std::pair<double,double> resEB = rooFitFakeRateProducer(sample,templateVariable,binName,TString("EB"),sidebandsEB.at(j),i+1, era); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      
      // record fake rate in TGraphs
      TString histNameEB = TString::Format("PtEB_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEB = (TH1D*) infile.Get(histNameEB);
      
      double denomEB = histEB->Integral();
      double graphX_EB = histEB->GetMean();
      double graphY_EB = resEB.first/denomEB; // i.e. the fake rate in the EB
      double eXLow_EB = graphX_EB - ptLow;
      double eXHigh_EB = ptHigh - graphX_EB;
      double ey_EB = fakeRateUncertainty(denomEB,resEB.second,graphY_EB);
      
      fakeRatesEB.at(j)->SetPoint(i,graphX_EB,graphY_EB);
      fakeRatesEB.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,ey_EB,ey_EB);
      
      // record background fit result
      bkgVsPtEBVec.at(j)->SetPoint(i,graphX_EB,resEB.first/ptBinSize);
      bkgVsPtEBVec.at(j)->SetPointError(i,eXLow_EB,eXHigh_EB,resEB.second/ptBinSize,resEB.second/ptBinSize);
    } // end loop over pT bins
  } // end loop over sidebands
  
  for (unsigned int j = 0; j < sidebandsEE.size(); j++) {
    for (int i = 0; i < nBins-1; i++) {
      double ptLow = ptBinArray_double[i];
      double ptHigh = ptBinArray_double[i+1];
      double ptBinSize = ptHigh - ptLow;
      TString binName = TString::Format("%iTo%i",ptBinArray[i],ptBinArray[i+1]);

      infile.cd();

      double sidebandLow = sidebandsEE.at(j).first;
      double sidebandHigh = sidebandsEE.at(j).second;
      TString postFix = "";
      if (templateVariable == "sieie")
	postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      else if (templateVariable == "chIso")
	postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      
      std::pair<double,double> resEE = rooFitFakeRateProducer(sample,templateVariable,binName,TString("EE"),sidebandsEE.at(j),i+1, era); // i+1 is the bin number in the denominator pT distribution corresponding to this pT bin
      
      // record fake rate in TGraphs
      TString histNameEE = TString::Format("PtEE_denominator_pt%iTo%i",ptBinArray[i],ptBinArray[i+1]);
      TH1D* histEE = (TH1D*) infile.Get(histNameEE);
      
      double denomEE = histEE->Integral();
      double graphX_EE = histEE->GetMean();
      double graphY_EE = resEE.first/denomEE; // i.e. the fake rate in the EE
      double eXLow_EE = graphX_EE - ptLow;
      double eXHigh_EE = ptHigh - graphX_EE;
      double ey_EE = fakeRateUncertainty(denomEE,resEE.second,graphY_EE);
      
      fakeRatesEE.at(j)->SetPoint(i,graphX_EE,graphY_EE);
      fakeRatesEE.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,ey_EE,ey_EE);
      
      // fill debug vectors
      if (templateVariable == "sieie") {
	if (sidebandLow == 9.) {
	  numVec.push_back(resEE.first);
	  denomVec.push_back(denomEE);
	}
      }
      
      // record background fit result
      bkgVsPtEEVec.at(j)->SetPoint(i,graphX_EE,resEE.first/ptBinSize);
      bkgVsPtEEVec.at(j)->SetPointError(i,eXLow_EE,eXHigh_EE,resEE.second/ptBinSize,resEE.second/ptBinSize);
    } // end loop over pT bins
  } // end loop over sidebands

  infile.cd();
  
  TH1D* denomvsptEB = (TH1D*) infile.Get("phoPtEB_denominator_varbin")->Clone();
  TH1D* denomvsptEE = (TH1D*) infile.Get("phoPtEE_denominator_varbin")->Clone();

  for (int i = 1; i <= nBins-1; i++) {
    double binWidth = denomvsptEB->GetXaxis()->GetBinWidth(i);
    denomvsptEB->SetBinContent(i, denomvsptEB->GetBinContent(i) / binWidth);
    denomvsptEB->SetBinError  (i, denomvsptEB->GetBinError(i) / binWidth);
    denomvsptEE->SetBinContent(i, denomvsptEE->GetBinContent(i) / binWidth);
    denomvsptEE->SetBinError  (i, denomvsptEE->GetBinError(i) / binWidth);
  }
  
  denomvsptEB->GetXaxis()->SetTitle("p_{T} (GeV)");
  denomvsptEE->GetXaxis()->SetTitle("p_{T} (GeV)");
  
  // debug printout to see fake rate ratios
  if (templateVariable == "sieie") {
    for (unsigned int i = 0; i < (numVec.size()-1); i++) {
      double numratio = numVec.at(i+1) / numVec.at(i);
      double denomratio = denomVec.at(i) / denomVec.at(i+1);
      cout << "EE Debug Info: ptBinLowEdge       n2/n1       d1/d2       FR" << endl;
      cout << ptBinArray[i] << " " << numratio << " " << denomratio << " " << numratio*denomratio << endl;
      cout << " " << endl;
    }
  }
  
  TFile outfile2("fakeRatePlots_" + sample + "_" + era + ".root","update");
  outfile2.cd();
  denomvsptEB->Write();
  denomvsptEE->Write();
  
  for (unsigned int j = 0; j < sidebandsEB.size(); j++) {
    outfile2.cd();
    
    fakeRatesEB.at(j)->Write();
    bkgVsPtEBVec.at(j)->Write();
    
    double sidebandLow = sidebandsEB.at(j).first;
    double sidebandHigh = sidebandsEB.at(j).second;
    TString postFix = "";
    TString label = "";
    if (templateVariable == "sieie") {
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      label = TString::Format("%d < Iso_{Ch} < %d GeV",(int)sidebandLow,(int)sidebandHigh);
    }
    else if (templateVariable == "chIso") {
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      label = TString::Format("%.4f < #sigma_{i#etai#eta} < %.4f",sidebandLow,sidebandHigh);
    }
    
    TCanvas c("c","",800,600);
    
    fakeRatesEB.at(j)->Draw();
    // fakeRatesEB.at(j)->SetTitle("EB");
    fakeRatesEB.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEB.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEB.at(j)->GetYaxis()->SetRangeUser(0.0, 0.25);
    fakeRatesEB.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label = new TLatex();
    t_label->SetTextAlign(12);
    t_label->DrawLatexNDC(0.50,0.75,"ECAL barrel");
    t_label->DrawLatexNDC(0.50,0.70,label);
    
    c.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EB"+postFix+".pdf");
  }
  
  for (unsigned int j = 0; j < sidebandsEE.size(); j++) {
    outfile2.cd();
    
    fakeRatesEE.at(j)->Write();
    bkgVsPtEEVec.at(j)->Write();
    
    double sidebandLow = sidebandsEE.at(j).first;
    double sidebandHigh = sidebandsEE.at(j).second;
    TString postFix = "";
    TString label = "";
    if (templateVariable == "sieie") {
      postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
      label = TString::Format("%d < Iso_{Ch} < %d GeV",(int)sidebandLow,(int)sidebandHigh);
    }
    else if (templateVariable == "chIso") {
      postFix = TString::Format("_sieie%.4fTo%.4f",sidebandLow,sidebandHigh);
      label = TString::Format("%.4f < #sigma_{i#etai#eta} < %.4f",sidebandLow,sidebandHigh);
    }

    TCanvas c("c","",800,600);
    
    fakeRatesEE.at(j)->Draw();
    // fakeRatesEE.at(j)->SetTitle("EE");
    fakeRatesEE.at(j)->GetXaxis()->SetTitle("p_{T} (GeV)");
    fakeRatesEE.at(j)->GetYaxis()->SetTitle("fake rate");
    fakeRatesEE.at(j)->GetYaxis()->SetRangeUser(0.0, 0.6);
    fakeRatesEE.at(j)->GetYaxis()->SetTitleOffset(1.6);

    TLatex *t_label = new TLatex();
    t_label->SetTextAlign(12);
    t_label->DrawLatexNDC(0.50,0.75,"ECAL endcap");
    t_label->DrawLatexNDC(0.50,0.70,label);
    
    c.SaveAs("plots/fake_rate_" + sample + "_" + era + "_EE"+postFix+".pdf");
  }

  outfile2.Close();

  cout << "\nEnding fakeRateCalculation()\n" << endl;
  
  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
