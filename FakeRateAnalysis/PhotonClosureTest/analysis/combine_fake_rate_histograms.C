// used to take numerator distributions from fake matching
// and use as faketemplates when treating MC as data

void combine_fake_rate_histograms() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);

  TFile *f_mc = TFile::Open("diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");  
  TFile *f_matching = TFile::Open("diphoton_fake_rate_closure_test_matching_QCD_Pt_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");

  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

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

  TFile file_out("diphoton_fake_rate_closure_test_combined_templates_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root","RECREATE");
  
  for (int i = 0; i < 2; ++i) {
    TString region;
    if (i==0) region = "EB";
    if (i==1) region = "EE";

    TH1F *h_denom_var = (TH1F*) f_mc->Get("phoPt"+region+"_denominator_varbin");
    //cout << h_denom_var->GetName() << endl;
    h_denom_var->Write();
    
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];  
      TString bin = Form("pt%dTo%d",(int)binLowEdge,(int)binUpperEdge);
    
      TH1F *h_num = (TH1F*) f_mc->Get("sieie"+region+"_numerator_"+bin);
      //cout << h_num->GetName() << endl;
      h_num->Write();
      
      TH1F *h_denom = (TH1F*) f_mc->Get("Pt"+region+"_denominator_"+bin);
      //cout << h_denom->GetName() << endl;
      h_denom->Write();

      for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it){
	double sidebandLow = it->first;
	double sidebandHigh = it->second;
	TString chIso = Form("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);

	TH1F *h_matching = (TH1F*) f_matching->Get("sieie"+region+"_numerator_fakes_"+bin);
	h_matching->SetName("sieie"+region+"_faketemplate_"+bin+"_"+chIso);
	h_matching->Write("sieie"+region+"_faketemplate_"+bin+"_"+chIso,TObject::kWriteDelete);
	
      } // end for loop over chIso bin
    } // end for loop over pt bin
  } // end for loop over region
  
  file_out.ls();
  file_out.Close();
  
}
