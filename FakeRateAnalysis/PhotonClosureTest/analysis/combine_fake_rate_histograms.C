/**
 * Purpose is to use MC truth templates as "true" fake templates
 * in fitting code. 
 * and use as faketemplates when treating MC as data
 *   
 * To run:
 * root -l -b -q combine_fake_rate_histograms.C'("all")'
 */
void combine_fake_rate_histograms(TString sample) {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);
  gStyle->SetNdivisions(505);
  gStyle->SetOptStat(0);
  
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;
  
  TString filename_matching = "";
  if (sample == "QCD")    filename_matching = "diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  filename_matching = "diphoton_fake_rate_closure_test_matching_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") filename_matching = "diphoton_fake_rate_closure_test_matching_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    filename_matching = "diphoton_fake_rate_closure_test_matching_all_samples_76X_MiniAOD_histograms.root";
  cout << "\nfilename_matching: " << filename_matching << endl;
  TFile *f_matching = TFile::Open(filename_matching);
  
  TString filename = "";
  if (sample == "QCD")    filename = "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root";
  cout << "\nfilename: " << filename << endl;
  TFile *f_mc = TFile::Open(filename);  
  
  TString output_filename = "";
  if (sample == "QCD")    output_filename = "diphoton_fake_rate_closure_test_combined_templates_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  output_filename = "diphoton_fake_rate_closure_test_combined_templates_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") output_filename = "diphoton_fake_rate_closure_test_combined_templates_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    output_filename = "diphoton_fake_rate_closure_test_combined_templates_all_samples_76X_MiniAOD_histograms.root";
  cout << "\noutput_filename: " << output_filename << endl;
  TFile file_out(output_filename,"RECREATE");
  
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
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

  for (int i = 0; i < nBins-1; i++) {
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];  
    TString bin = Form("pt%dTo%d",(int)binLowEdge,(int)binUpperEdge);
    
    for (int i = 0; i < 2; ++i) {
      TString region;
      if (i==0) region = "EB";
      if (i==1) region = "EE";
      
      TH1D *h_denom_var = (TH1D*) f_mc->Get("phoPt"+region+"_denominator_varbin");
      // cout << h_denom_var->GetName() << endl;
      h_denom_var->Write();
      
      TH1D *h_num_sieie = (TH1D*) f_mc->Get("sieie"+region+"_numerator_"+bin);
      // cout << h_num_sieie->GetName() << endl;
      h_num_sieie->Write();

      TH1D *h_num_chIso = (TH1D*) f_mc->Get("chIso"+region+"_numerator_"+bin);
      // cout << h_num_chIso->GetName() << endl;
      h_num_chIso->Write();
      
      TH1D *h_denom = (TH1D*) f_mc->Get("Pt"+region+"_denominator_"+bin);
      // cout << h_denom->GetName() << endl;
      h_denom->Write();
    
      for (std::vector< std::pair<double,double> >::const_iterator it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
	TString sideband = Form("chIso%dTo%d",(int)it->first,(int)it->second);
	TH1D *h_matching = (TH1D*) f_matching->Get("sieie"+region+"_numerator_fakes_"+bin);
	h_matching->SetName("sieie"+region+"_faketemplate_"+bin+"_"+sideband);
	h_matching->Write("sieie"+region+"_faketemplate_"+bin+"_"+sideband,TObject::kWriteDelete);
      }
      
    } // end for loop over ECAL region
    
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EB_sidebands.begin(); it != sieie_EB_sidebands.end(); ++it) {
      TString sideband = Form("sieie%.4fTo%.4f",it->first,it->second);
      TH1D *h_matching = (TH1D*) f_matching->Get("chIsoEB_numerator_fakes_"+bin);
      h_matching->SetName("chIsoEB_faketemplate_"+bin+"_"+sideband);
      h_matching->Write("chIsoEB_faketemplate_"+bin+"_"+sideband,TObject::kWriteDelete);
    }
    
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EE_sidebands.begin(); it != sieie_EE_sidebands.end(); ++it) {
      TString sideband = Form("sieie%.4fTo%.4f",it->first,it->second);
      TH1D *h_matching = (TH1D*) f_matching->Get("chIsoEE_numerator_fakes_"+bin);
      h_matching->SetName("chIsoEE_faketemplate_"+bin+"_"+sideband);
      h_matching->Write("chIsoEE_faketemplate_"+bin+"_"+sideband,TObject::kWriteDelete);
    }
    
  } // end for loop over pt bin
  
  file_out.ls();
  file_out.Close();
  
}
