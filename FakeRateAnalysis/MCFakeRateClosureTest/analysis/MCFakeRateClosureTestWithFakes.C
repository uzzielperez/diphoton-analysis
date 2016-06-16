#define MCFakeRateClosureTestWithFakes_cxx
#include "MCFakeRateClosureTestWithFakes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MCFakeRateClosureTestWithFakes::Loop(const Char_t *iMass)
{
//   In a ROOT session, you can do:
//      root> .L MCFakeRateClosureTestWithFakes.C
//      root> MCFakeRateClosureTestWithFakes t
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

  // define number of bin edges
  const int nBins = 10;
  
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  
  // pt spectrum of passHighPtID objects
  TH1D phoPtEB_passHighPtID_varbin("phoPtEB_passHighPtID_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE_passHighPtID_varbin("phoPtEE_passHighPtID_varbin","",nBins-1,ptBinArray);
  phoPtEB_passHighPtID_varbin.Sumw2();
  phoPtEE_passHighPtID_varbin.Sumw2();
  
  // numerator histograms
  std::vector<TH1D*> sIeIeNumeratorEB_fromFakes;
  std::vector<TH1D*> sIeIeNumeratorEE_fromFakes;
  std::vector<TH1D*> sIeIeNumeratorEB_fromReal;
  std::vector<TH1D*> sIeIeNumeratorEE_fromReal;
  
  // loop over bins increments and create histograms
  for (int i = 0; i < nBins-1; i++) {
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];  
    
    TH1D *hEB_numerator_fakes = new TH1D(Form("sieieEB_numerator_fakes_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_fakes->Sumw2();
    sIeIeNumeratorEB_fromFakes.push_back(hEB_numerator_fakes);
    
    TH1D *hEE_numerator_fakes = new TH1D(Form("sieieEE_numerator_fakes_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_fakes->Sumw2();
    sIeIeNumeratorEE_fromFakes.push_back(hEE_numerator_fakes);

    TH1D *hEB_numerator_real = new TH1D(Form("sieieEB_numerator_real_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_real->Sumw2();
    sIeIeNumeratorEB_fromReal.push_back(hEB_numerator_real);
    
    TH1D *hEE_numerator_real = new TH1D(Form("sieieEE_numerator_real_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_real->Sumw2();
    sIeIeNumeratorEE_fromReal.push_back(hEE_numerator_real);
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

    // numerator object definitions
    bool isNumeratorObj = Photon_isNumeratorObjCand && Photon_passChIso;
    
    // reject beam halo
    //if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;

    // don't consider number of not real photons
    if ( !(PhotonGenMatch_matchCategory == 1 && (PhotonGenMatch_matchType == 2 || PhotonGenMatch_matchType == 3)) ) {
      // EB
      if (fabs(Photon_scEta) < 1.4442) {
	if (Photon_passHighPtID) {
	  phoPtEB_passHighPtID_varbin.Fill(Photon_pt,Event_weight);
	}
      } // end EB
      // EE
      else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	if (Photon_passHighPtID) {
	  phoPtEE_passHighPtID_varbin.Fill(Photon_pt,Event_weight);
	}
      } // end EE
    } // end if not real photons
    
    // loop over bin edges
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      
      // pt cut
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {

	// fill numerator histograms
	if (isNumeratorObj) {

	  // fake photons
	  if ( !(PhotonGenMatch_matchCategory == 1 && (PhotonGenMatch_matchType == 2 || PhotonGenMatch_matchType == 3)) ) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  
	  // real photons
	  if ( PhotonGenMatch_matchCategory == 1 && (PhotonGenMatch_matchType == 2 || PhotonGenMatch_matchType == 3) ) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  
	} // end numerator obj

      } // end pt cut
      
    } // end loop over pt bins for fake template
    
  } // end loop over entries
  
  TString filename;
  if (strcmp(iMass,"all") == 0) filename = "diphoton_fakeRate_matchedFakes_QCD_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  else filename = TString::Format("diphoton_fakeRate_matchedFakes_QCD_Pt_%s_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root",iMass);
  TFile file_out(filename,"RECREATE");

  // write passHighPtID histograms
  phoPtEB_passHighPtID_varbin.Write();
  phoPtEE_passHighPtID_varbin.Write();

  double bin_sum_EB = 0;
  cout << phoPtEB_passHighPtID_varbin.GetName() << "\t integral: " << phoPtEB_passHighPtID_varbin.Integral() << endl;
  for (int i = 1; i < phoPtEB_passHighPtID_varbin.GetSize()-1; i++) {
    cout << phoPtEB_passHighPtID_varbin.GetName()
	 << " bin "
	 << phoPtEB_passHighPtID_varbin.GetBin(i)
	 << " content: "
	 << phoPtEB_passHighPtID_varbin.GetBinContent(i)
	 << endl;
    bin_sum_EB = bin_sum_EB + phoPtEB_passHighPtID_varbin.GetBinContent(i);
  }
  cout << phoPtEB_passHighPtID_varbin.GetName() << " bin sum: " << bin_sum_EB << endl;
  
  double bin_sum_EE = 0;
  cout << phoPtEE_passHighPtID_varbin.GetName() << "\t integral: " << phoPtEE_passHighPtID_varbin.Integral() << endl;
  for (int i = 1; i < phoPtEB_passHighPtID_varbin.GetSize()-1; i++) {  
    cout << phoPtEE_passHighPtID_varbin.GetName()
	 << " bin "
	 << phoPtEE_passHighPtID_varbin.GetBin(i)
	 << " content: "
	 << phoPtEE_passHighPtID_varbin.GetBinContent(i)
	 << endl;
    bin_sum_EE = bin_sum_EE + phoPtEE_passHighPtID_varbin.GetBinContent(i);
  }
  cout << phoPtEB_passHighPtID_varbin.GetName() << " bin sum: " << bin_sum_EE << endl;
  
  // write numerator histograms
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromFakes.begin() ; it != sIeIeNumeratorEB_fromFakes.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromFakes.begin() ; it != sIeIeNumeratorEE_fromFakes.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromReal.begin() ; it != sIeIeNumeratorEB_fromReal.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromReal.begin() ; it != sIeIeNumeratorEE_fromReal.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  
  file_out.ls();
  file_out.Close();
  
} // end of Loop()
