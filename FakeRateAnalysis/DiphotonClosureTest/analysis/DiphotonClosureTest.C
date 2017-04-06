#define DiphotonClosureTest_cxx
#include "DiphotonClosureTest.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DiphotonClosureTest::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DiphotonClosureTest.C
//      root> DiphotonClosureTest t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  if (fChain == 0) return;

  // input what sample is being run on
  TString sample = "";
  cout << "Enter sample being run on (QCD, GJets, GGJets, or all): ";
  cin >> sample;
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;
  
  // output filename
  TString filename = "";
  if (sample == "QCD")     filename = "diphoton_fake_rate_diphoton_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")   filename = "diphoton_fake_rate_diphoton_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets")  filename = "diphoton_fake_rate_diphoton_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")     filename = "diphoton_fake_rate_diphoton_closure_test_all_samples_76X_MiniAOD_histograms.root";
  cout << "Output filename: " << filename << endl << endl;

  int nbins = 120;
  double xmin = 0.0;
  double xmax = 6000.0;
  
  enum diphotonRegions {EBEB = 0, EBEE, EEEB, EEEE};
  const TString regions[4] = {"EBEB", "EBEE", "EEEB", "EEEE"};
  
  TH1D *good_TF_mc_truth_diphoton_minv[4], *TT_TF_mc_truth_diphoton_minv[4], *TF_diphoton_minv[4], *TF_diphoton_minv_with_fake_rate[4];
  TH1D *good_FT_mc_truth_diphoton_minv[4], *TT_FT_mc_truth_diphoton_minv[4], *FT_diphoton_minv[4], *FT_diphoton_minv_with_fake_rate[4];
  TH1D *good_FF_mc_truth_diphoton_minv[4], *TT_FF_mc_truth_diphoton_minv[4], *FF_diphoton_minv[4], *FF_diphoton_minv_with_fake_rate[4];

  for (int iregion = 0; iregion < 4; iregion++) {
    // TF
    good_TF_mc_truth_diphoton_minv[iregion] = new TH1D("good_TF_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    TT_TF_mc_truth_diphoton_minv[iregion] = new TH1D("TT_TF_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    TF_diphoton_minv[iregion] = new TH1D("TF_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    TF_diphoton_minv_with_fake_rate[iregion] = new TH1D("TF_diphoton_minv_with_fake_rate_"+regions[iregion],"", nbins, xmin, xmax);
    // FT
    good_FT_mc_truth_diphoton_minv[iregion] = new TH1D("good_FT_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    TT_FT_mc_truth_diphoton_minv[iregion] = new TH1D("TT_FT_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    FT_diphoton_minv[iregion] = new TH1D("FT_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    FT_diphoton_minv_with_fake_rate[iregion] = new TH1D("FT_diphoton_minv_with_fake_rate_"+regions[iregion],"", nbins, xmin, xmax);
    // FF
    good_FF_mc_truth_diphoton_minv[iregion] = new TH1D("good_FF_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    TT_FF_mc_truth_diphoton_minv[iregion] = new TH1D("TT_FF_mc_truth_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    FF_diphoton_minv[iregion] = new TH1D("FF_diphoton_minv_"+regions[iregion],"", nbins, xmin, xmax);
    FF_diphoton_minv_with_fake_rate[iregion] = new TH1D("FF_diphoton_minv_with_fake_rate_"+regions[iregion],"", nbins, xmin, xmax);
  }
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry % 100000 == 0)
      std::cout << "Number of entries looped over: " << jentry << std::endl;
    
    if (isGood) {
      bool pass_sipip_Good = Photon1_sigmaIphiIphi5x5 > 0.009 && Photon2_sigmaIphiIphi5x5 > 0.009;
      bool pass_pt_Good = Photon1_pt > 50. && Photon2_pt > 50.;
      bool pass_ID_Good = Photon1_passHighPtID && Photon2_passHighPtID;
      if (pass_sipip_Good && pass_pt_Good && pass_ID_Good) {
	if (Diphoton_isEBEB) {
	  if (Photon1_isMCTruthFake == 0 && Photon2_isMCTruthFake == 1) good_TF_mc_truth_diphoton_minv[EBEB]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 0) good_FT_mc_truth_diphoton_minv[EBEB]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 1) good_FF_mc_truth_diphoton_minv[EBEB]->Fill(Diphoton_Minv,Event_weightAll);
	}
	else if (Diphoton_isEBEE) {
	  if (Photon1_isMCTruthFake == 0 && Photon2_isMCTruthFake == 1) good_TF_mc_truth_diphoton_minv[EBEE]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 0) good_FT_mc_truth_diphoton_minv[EBEE]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 1) good_FF_mc_truth_diphoton_minv[EBEE]->Fill(Diphoton_Minv,Event_weightAll);
	}
	else if (Diphoton_isEEEB) {
	  if (Photon1_isMCTruthFake == 0 && Photon2_isMCTruthFake == 1) good_TF_mc_truth_diphoton_minv[EEEB]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 0) good_FT_mc_truth_diphoton_minv[EEEB]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 1) good_FF_mc_truth_diphoton_minv[EEEB]->Fill(Diphoton_Minv,Event_weightAll);
	}
	else if (Diphoton_isEEEE) {
	  if (Photon1_isMCTruthFake == 0 && Photon2_isMCTruthFake == 1) good_TF_mc_truth_diphoton_minv[EEEE]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 0) good_FT_mc_truth_diphoton_minv[EEEE]->Fill(Diphoton_Minv,Event_weightAll);
	  if (Photon1_isMCTruthFake == 1 && Photon2_isMCTruthFake == 1) good_FF_mc_truth_diphoton_minv[EEEE]->Fill(Diphoton_Minv,Event_weightAll);
	}
      }
    }
    
    if (isTT) {
      bool pass_sipip_TT = TTPhoton1_sigmaIphiIphi5x5 > 0.009 && TTPhoton2_sigmaIphiIphi5x5 > 0.009;
      bool pass_pt_TT = TTPhoton1_pt > 50. && TTPhoton2_pt > 50.;
      bool pass_ID_TT = TTPhoton1_passHighPtID && TTPhoton2_passHighPtID;
      if (pass_sipip_TT && pass_pt_TT && pass_ID_TT) {
	if (TTDiphoton_isEBEB) {
	  if (TTPhoton1_isMCTruthFake == 0 && TTPhoton2_isMCTruthFake == 1) TT_TF_mc_truth_diphoton_minv[EBEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 0) TT_FT_mc_truth_diphoton_minv[EBEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 1) TT_FF_mc_truth_diphoton_minv[EBEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	}
	else if (TTDiphoton_isEBEE) {
	  if (TTPhoton1_isMCTruthFake == 0 && TTPhoton2_isMCTruthFake == 1) TT_TF_mc_truth_diphoton_minv[EBEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 0) TT_FT_mc_truth_diphoton_minv[EBEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 1) TT_FF_mc_truth_diphoton_minv[EBEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	}
	else if (TTDiphoton_isEEEB) {
	  if (TTPhoton1_isMCTruthFake == 0 && TTPhoton2_isMCTruthFake == 1) TT_TF_mc_truth_diphoton_minv[EEEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 0) TT_FT_mc_truth_diphoton_minv[EEEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 1) TT_FF_mc_truth_diphoton_minv[EEEB]->Fill(TTDiphoton_Minv,Event_weightAll);
	}
	else if (TTDiphoton_isEEEE) {
	  if (TTPhoton1_isMCTruthFake == 0 && TTPhoton2_isMCTruthFake == 1) TT_TF_mc_truth_diphoton_minv[EEEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 0) TT_FT_mc_truth_diphoton_minv[EEEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	  if (TTPhoton1_isMCTruthFake == 1 && TTPhoton2_isMCTruthFake == 1) TT_FF_mc_truth_diphoton_minv[EEEE]->Fill(TTDiphoton_Minv,Event_weightAll);
	}
      }
    }
    
    if (isTF) {
      bool pass_sipip_TF = TFPhoton1_sigmaIphiIphi5x5 > 0.009 && TFPhoton2_sigmaIphiIphi5x5 > 0.009;
      bool pass_pt_TF = TFPhoton1_pt > 50. && TFPhoton2_pt > 50.;
      bool pass_ID_TF = TFPhoton1_passHighPtID && TFPhoton2_isDenominatorObj;
      if (pass_sipip_TF && pass_pt_TF && pass_ID_TF) {
	if (TFDiphoton_isEBEB) {
	  TF_diphoton_minv[EBEB]->Fill(TFDiphoton_Minv,Event_weightAll);
	  TF_diphoton_minv_with_fake_rate[EBEB]->Fill(TFDiphoton_Minv,Event_weightAll*fakeRate("EB",TFPhoton2_pt));
	}
	else if (TFDiphoton_isEBEE) {
	  TF_diphoton_minv[EBEE]->Fill(TFDiphoton_Minv,Event_weightAll);
	  TF_diphoton_minv_with_fake_rate[EBEE]->Fill(TFDiphoton_Minv,Event_weightAll*fakeRate("EE",TFPhoton2_pt));
	}
	else if (TFDiphoton_isEEEB) {
	  TF_diphoton_minv[EEEB]->Fill(TFDiphoton_Minv,Event_weightAll);
	  TF_diphoton_minv_with_fake_rate[EEEB]->Fill(TFDiphoton_Minv,Event_weightAll*fakeRate("EB",TFPhoton2_pt));
	}
	else if (TFDiphoton_isEEEE) {
	  TF_diphoton_minv[EEEE]->Fill(TFDiphoton_Minv,Event_weightAll);
	  TF_diphoton_minv_with_fake_rate[EEEE]->Fill(TFDiphoton_Minv,Event_weightAll*fakeRate("EE",TFPhoton2_pt));
	}
      }
    }
    
    if (isFT) {
      bool pass_sipip_FT = FTPhoton1_sigmaIphiIphi5x5 > 0.009 && FTPhoton2_sigmaIphiIphi5x5 > 0.009;
      bool pass_pt_FT = FTPhoton1_pt > 50. && FTPhoton2_pt > 50.;
      bool pass_ID_FT = FTPhoton1_isDenominatorObj && FTPhoton2_passHighPtID;
      if (pass_sipip_FT && pass_pt_FT && pass_ID_FT) {
	if (FTDiphoton_isEBEB) {
	  FT_diphoton_minv[EBEB]->Fill(FTDiphoton_Minv,Event_weightAll);
	  FT_diphoton_minv_with_fake_rate[EBEB]->Fill(FTDiphoton_Minv,Event_weightAll*fakeRate("EB",FTPhoton1_pt));
	}
	else if (FTDiphoton_isEBEE) {
	  FT_diphoton_minv[EBEE]->Fill(FTDiphoton_Minv,Event_weightAll);
	  FT_diphoton_minv_with_fake_rate[EBEE]->Fill(FTDiphoton_Minv,Event_weightAll*fakeRate("EE",FTPhoton1_pt));
	}
	else if (FTDiphoton_isEEEB) {
	  FT_diphoton_minv[EEEB]->Fill(FTDiphoton_Minv,Event_weightAll);
	  FT_diphoton_minv_with_fake_rate[EEEB]->Fill(FTDiphoton_Minv,Event_weightAll*fakeRate("EB",FTPhoton1_pt));
	}
	else if (FTDiphoton_isEEEE) {
	  FT_diphoton_minv[EEEE]->Fill(FTDiphoton_Minv,Event_weightAll);
	  FT_diphoton_minv_with_fake_rate[EEEE]->Fill(FTDiphoton_Minv,Event_weightAll*fakeRate("EE",FTPhoton1_pt));
	}
      }
    }
    
    if (isFF) {
      bool pass_sipip_FF = FFPhoton1_sigmaIphiIphi5x5 > 0.009 && FFPhoton2_sigmaIphiIphi5x5 > 0.009;
      bool pass_pt_FF = FFPhoton1_pt > 50. && FFPhoton2_pt > 50.;
      bool pass_ID_FF = FFPhoton1_isDenominatorObj && FFPhoton2_isDenominatorObj;
      if (pass_sipip_FF && pass_pt_FF && pass_ID_FF) {
	if (FFDiphoton_isEBEB) {
	  FF_diphoton_minv[EBEB]->Fill(FFDiphoton_Minv,Event_weightAll);
	  FF_diphoton_minv_with_fake_rate[EBEB]->Fill(FFDiphoton_Minv,Event_weightAll*fakeRate("EB",FFPhoton1_pt)*fakeRate("EB",FFPhoton2_pt));
	}
	else if (FFDiphoton_isEBEE) {
	  FF_diphoton_minv[EBEE]->Fill(FFDiphoton_Minv,Event_weightAll);
	  FF_diphoton_minv_with_fake_rate[EBEE]->Fill(FFDiphoton_Minv,Event_weightAll*fakeRate("EB",FFPhoton1_pt)*fakeRate("EE",FFPhoton2_pt));
	}
	else if (FFDiphoton_isEEEB) {
	  FF_diphoton_minv[EEEB]->Fill(FFDiphoton_Minv,Event_weightAll);
	  FF_diphoton_minv_with_fake_rate[EEEB]->Fill(FFDiphoton_Minv,Event_weightAll*fakeRate("EE",FFPhoton1_pt)*fakeRate("EB",FFPhoton2_pt));
	}
	else if (FFDiphoton_isEEEE) {
	  FF_diphoton_minv[EEEE]->Fill(FFDiphoton_Minv,Event_weightAll);
	  FF_diphoton_minv_with_fake_rate[EEEE]->Fill(FFDiphoton_Minv,Event_weightAll*fakeRate("EE",FFPhoton1_pt)*fakeRate("EE",FFPhoton2_pt));
	}
      }
    }
    
  } // end for loop over entries

  TFile file_out(filename,"RECREATE");
  
  for (int iregion = 0; iregion < 4; iregion++) {
    // TF
    good_TF_mc_truth_diphoton_minv[iregion]->Write();
    TT_TF_mc_truth_diphoton_minv[iregion]->Write();
    TF_diphoton_minv[iregion]->Write();
    TF_diphoton_minv_with_fake_rate[iregion]->Write();
    // FT
    good_FT_mc_truth_diphoton_minv[iregion]->Write();
    TT_FT_mc_truth_diphoton_minv[iregion]->Write();
    FT_diphoton_minv[iregion]->Write();
    FT_diphoton_minv_with_fake_rate[iregion]->Write();
    // FF
    good_FF_mc_truth_diphoton_minv[iregion]->Write();
    TT_FF_mc_truth_diphoton_minv[iregion]->Write();
    FF_diphoton_minv[iregion]->Write();
    FF_diphoton_minv_with_fake_rate[iregion]->Write();
  }

  file_out.ls();
  file_out.Close();
  
} // end Loop()

double DiphotonClosureTest::fakeRate(TString region, double pt) {
  
  if (region == "EB") {
    double p0 = 0.00849217687309;
    double p1 = 4626.30436377913156;
    double p2 = 2.63645174829998;
    return p0+p1/std::pow(pt,p2);
  }
  
  else if (region == "EE") {
    double p0 = -0.29630917846842;
    double p1 = 0.72329540931979;
    double p2 = 0.13882649927513;
    return p0+p1/std::pow(pt,p2);
  }
  
  else return 0.0;
}
