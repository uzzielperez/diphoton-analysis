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

  // event counters
  int nEvents = 0;
  int nEvents_EB = 0;
  int nEvents_EE = 0;
  
  // match category counters
  // EB
  int nNoMatch_EB = 0;
  int nFinalStatePhotonMatch_EB = 0;
  int nFinalStateNonPhotonMatch_EB = 0;
  int nGenParticlePhotonMatch_EB = 0;
  int nGenParticleNonPhotonMatch_EB = 0;
  // EE
  int nNoMatch_EE = 0;
  int nFinalStatePhotonMatch_EE = 0;
  int nFinalStateNonPhotonMatch_EE = 0;
  int nGenParticlePhotonMatch_EE = 0;
  int nGenParticleNonPhotonMatch_EE = 0;

  // final state photon type counters
  // EB
  int nFinalStatePhotonNoMatch_EB = 0;
  int nFinalStatePhotonHadronMother_EB = 0;
  int nFinalStatePhotonFSR_EB = 0;
  int nFinalStatePhotonISR_EB = 0;
  int nFinalStatePhotonOtherFragmentationQuark_EB = 0;
  int nFinalStatePhotonOtherFragmentationGluon_EB = 0;
  // EE
  int nFinalStatePhotonNoMatch_EE = 0;
  int nFinalStatePhotonHadronMother_EE = 0;
  int nFinalStatePhotonFSR_EE = 0;
  int nFinalStatePhotonISR_EE = 0;
  int nFinalStatePhotonOtherFragmentationQuark_EE = 0;
  int nFinalStatePhotonOtherFragmentationGluon_EE = 0;
  
  // final state non-photon type counters
  // EB
  int nFinalStateNonPhotonNoMatch_EB = 0;
  int nFinalStateNonPhotonHadronMother_EB = 0;
  int nFinalStateNonPhotonElectronPair_EB = 0;
  // EE
  int nFinalStateNonPhotonNoMatch_EE = 0;
  int nFinalStateNonPhotonHadronMother_EE = 0;
  int nFinalStateNonPhotonElectronPair_EE = 0;

  // average number of daughters
  // EB
  int nAveNumDaughtersHadronMother_EB = 0;
  int nAveNumDaughtersISR_EB = 0;
  int nAveNumDaughtersFSR_EB = 0;
  int nAveNumDaughtersFragQuark_EB = 0;
  int nAveNumDaughtersFragGluon_EB = 0;
  // EE
  int nAveNumDaughtersHadronMother_EE = 0;
  int nAveNumDaughtersISR_EE = 0;
  int nAveNumDaughtersFSR_EE = 0;
  int nAveNumDaughtersFragQuark_EE = 0;
  int nAveNumDaughtersFragGluon_EE = 0;
  
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
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonHadronMother;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonHadronMother;
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonISR;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonISR;
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonFSR;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonFSR;
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonOtherFragQuark;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonOtherFragQuark;
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonOtherFragGluon;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonOtherFragGluon;
  std::vector<TH1D*> sIeIeNumeratorEB_fromNoMatch;
  std::vector<TH1D*> sIeIeNumeratorEE_fromNoMatch;
  std::vector<TH1D*> sIeIeNumeratorEB_fromNonPhotonMatch;
  std::vector<TH1D*> sIeIeNumeratorEE_fromNonPhotonMatch;
  std::vector<TH1D*> sIeIeNumeratorEB_fromGenParticleMatch;
  std::vector<TH1D*> sIeIeNumeratorEE_fromGenParticleMatch;
  
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

    TH1D *hEB_numerator_photonHadronMother = new TH1D(Form("sieieEB_numerator_photonHadronMother_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonHadronMother->Sumw2();
    sIeIeNumeratorEB_fromPhotonHadronMother.push_back(hEB_numerator_photonHadronMother);
    TH1D *hEE_numerator_photonHadronMother = new TH1D(Form("sieieEE_numerator_photonHadronMother_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonHadronMother->Sumw2();
    sIeIeNumeratorEE_fromPhotonHadronMother.push_back(hEE_numerator_photonHadronMother);
    
    TH1D *hEB_numerator_photonISR = new TH1D(Form("sieieEB_numerator_photonISR_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonISR->Sumw2();
    sIeIeNumeratorEB_fromPhotonISR.push_back(hEB_numerator_photonISR);
    TH1D *hEE_numerator_photonISR = new TH1D(Form("sieieEE_numerator_photonISR_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonISR->Sumw2();
    sIeIeNumeratorEE_fromPhotonISR.push_back(hEE_numerator_photonISR);

    TH1D *hEB_numerator_photonFSR = new TH1D(Form("sieieEB_numerator_photonFSR_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonFSR->Sumw2();
    sIeIeNumeratorEB_fromPhotonFSR.push_back(hEB_numerator_photonFSR);
    TH1D *hEE_numerator_photonFSR = new TH1D(Form("sieieEE_numerator_photonFSR_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonFSR->Sumw2();
    sIeIeNumeratorEE_fromPhotonFSR.push_back(hEE_numerator_photonFSR);
    
    TH1D *hEB_numerator_photonOtherFragQuark = new TH1D(Form("sieieEB_numerator_photonOtherFragQuark_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonOtherFragQuark->Sumw2();
    sIeIeNumeratorEB_fromPhotonOtherFragQuark.push_back(hEB_numerator_photonOtherFragQuark);
    TH1D *hEE_numerator_photonOtherFragQuark = new TH1D(Form("sieieEE_numerator_photonOtherFragQuark_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonOtherFragQuark->Sumw2();
    sIeIeNumeratorEE_fromPhotonOtherFragQuark.push_back(hEE_numerator_photonOtherFragQuark);
    
    TH1D *hEB_numerator_photonOtherFragGluon = new TH1D(Form("sieieEB_numerator_photonOtherFragGluon_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonOtherFragGluon->Sumw2();
    sIeIeNumeratorEB_fromPhotonOtherFragGluon.push_back(hEB_numerator_photonOtherFragGluon);
    TH1D *hEE_numerator_photonOtherFragGluon = new TH1D(Form("sieieEE_numerator_photonOtherFragGluon_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonOtherFragGluon->Sumw2();
    sIeIeNumeratorEE_fromPhotonOtherFragGluon.push_back(hEE_numerator_photonOtherFragGluon);
    
    TH1D *hEB_numerator_noMatch = new TH1D(Form("sieieEB_numerator_noMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_noMatch->Sumw2();
    sIeIeNumeratorEB_fromNoMatch.push_back(hEB_numerator_noMatch);
    TH1D *hEE_numerator_noMatch = new TH1D(Form("sieieEE_numerator_noMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_noMatch->Sumw2();
    sIeIeNumeratorEE_fromNoMatch.push_back(hEE_numerator_noMatch);
    
    TH1D *hEB_numerator_nonPhotonMatch = new TH1D(Form("sieieEB_numerator_nonPhotonMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_nonPhotonMatch->Sumw2();
    sIeIeNumeratorEB_fromNonPhotonMatch.push_back(hEB_numerator_nonPhotonMatch);
    TH1D *hEE_numerator_nonPhotonMatch = new TH1D(Form("sieieEE_numerator_nonPhotonMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_nonPhotonMatch->Sumw2();
    sIeIeNumeratorEE_fromNonPhotonMatch.push_back(hEE_numerator_nonPhotonMatch);
    
    TH1D *hEB_numerator_genParticleMatch = new TH1D(Form("sieieEB_numerator_genParticleMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_genParticleMatch->Sumw2();
    sIeIeNumeratorEB_fromGenParticleMatch.push_back(hEB_numerator_genParticleMatch);
    TH1D *hEE_numerator_genParticleMatch = new TH1D(Form("sieieEE_numerator_genParticleMatch_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_genParticleMatch->Sumw2();
    sIeIeNumeratorEE_fromGenParticleMatch.push_back(hEE_numerator_genParticleMatch);
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

    // reals -- photon ISR and photon FSR (deltaR cut for now)
    bool reals = PhotonGenMatch_matchCategory == 1 && ( (PhotonGenMatch_matchType == 2 && PhotonGenMatch_deltaR_FSR > 0.3) || PhotonGenMatch_matchType == 3);
    // fakes -- photon hadron mothers (for now)
    bool fakes = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 1;
    
    // photonHadronMother -- photon hadron mothers 
    bool photonHadronMother = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 1;
    // photonISR -- photon ISR
    bool photonISR = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 3;
    // photonFSR -- photon FSR
    bool photonFSR = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 2;
    // photonOtherFragQuark -- other photon fragmentation with quark mother
    bool photonOtherFragQuark = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 5;
    // photonOtherFragGluon -- other photon fragmentation with quark gluon
    bool photonOtherFragGluon = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 4;
    // noMatch -- no matches
    bool noMatch = PhotonGenMatch_matchCategory == 0;
    // nonPhotonMatch -- non-photon matches
    bool nonPhotonMatch = PhotonGenMatch_matchCategory == 2;
    // genParticleMatch -- gen particle matches
    bool genParticleMatch = PhotonGenMatch_matchCategory == 3 || PhotonGenMatch_matchCategory == 4;

    //if (!Photon_passSieie) continue;
    
    // count number of numberator objects -- only numerator objects are filled in fTreeFake tree
    nEvents+=Event_weight;
    
    // EB
    if (fabs(Photon_scEta) < 1.4442) {
      nEvents_EB+=Event_weight;
      if (fakes) {
	if (Photon_passHighPtID) {
	  phoPtEB_passHighPtID_varbin.Fill(Photon_pt,Event_weight);
	}
      }
      // 0 - no match
      if (PhotonGenMatch_matchCategory == 0) {
	nNoMatch_EB+=Event_weight;
      }
      // 1 - final state photon match
      if (PhotonGenMatch_matchCategory == 1) {
	nFinalStatePhotonMatch_EB+=Event_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStatePhotonNoMatch_EB+=Event_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) {
	  nFinalStatePhotonHadronMother_EB+=Event_weight;
	  nAveNumDaughtersHadronMother_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 2 - FSR
	if (PhotonGenMatch_matchType == 2) {
	  nFinalStatePhotonFSR_EB+=Event_weight;
	  nAveNumDaughtersFSR_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 3 - ISR
	if (PhotonGenMatch_matchType == 3) {
	  nFinalStatePhotonISR_EB+=Event_weight;
	  nAveNumDaughtersISR_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 4 - other fragmentation gluon
	if (PhotonGenMatch_matchType == 4) {
	  nFinalStatePhotonOtherFragmentationGluon_EB+=Event_weight;
	  nAveNumDaughtersFragGluon_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 5 - other fragmentation quark
	if (PhotonGenMatch_matchType == 5) {
	  nFinalStatePhotonOtherFragmentationQuark_EB+=Event_weight;
	  nAveNumDaughtersFragQuark_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
      } // end final state photon matches
	// 2 - final state non-photon match
      if (PhotonGenMatch_matchCategory == 2) {
	nFinalStateNonPhotonMatch_EB+=Event_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStateNonPhotonNoMatch_EB+=Event_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) nFinalStateNonPhotonHadronMother_EB+=Event_weight;
	// 5 - electron pair
	if (PhotonGenMatch_matchType == 6) nFinalStateNonPhotonElectronPair_EB+=Event_weight;
      } // end final state non-photon matches
	// 3 - gen particle photon match
      if (PhotonGenMatch_matchCategory == 3) {
	nGenParticlePhotonMatch_EB+=Event_weight;
      } // end gen particle photon matches
	// 4 - gen particle non-photon match
      if (PhotonGenMatch_matchCategory == 4) {
	nGenParticleNonPhotonMatch_EB+=Event_weight;
      } // end gen particle non-photon matches
    } // end EB
    // EE
    else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
      nEvents_EE+=Event_weight;
      if (fakes) {
	if (Photon_passHighPtID) {
	  phoPtEE_passHighPtID_varbin.Fill(Photon_pt,Event_weight);
	}
      }
      // 0 - no match
      if (PhotonGenMatch_matchCategory == 0) {
	nNoMatch_EE+=Event_weight;
      }
      // 1 - final state photon match
      if (PhotonGenMatch_matchCategory == 1) {
	nFinalStatePhotonMatch_EE+=Event_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStatePhotonNoMatch_EE+=Event_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) {
	  nFinalStatePhotonHadronMother_EE+=Event_weight;
	  nAveNumDaughtersHadronMother_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 2 - FSR
	if (PhotonGenMatch_matchType == 2) {
	  nFinalStatePhotonFSR_EE+=Event_weight;
	  nAveNumDaughtersFSR_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 3 - ISR
	if (PhotonGenMatch_matchType == 3) {
	  nFinalStatePhotonISR_EE+=Event_weight;
	  nAveNumDaughtersISR_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 4 - other fragmentation gluon
	if (PhotonGenMatch_matchType == 4) {
	  nFinalStatePhotonOtherFragmentationGluon_EE+=Event_weight;
	  nAveNumDaughtersFragGluon_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 5 - other fragmentation quark
	if (PhotonGenMatch_matchType == 5) {
	  nFinalStatePhotonOtherFragmentationQuark_EE+=Event_weight;
	  nAveNumDaughtersFragQuark_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
      } // end final state photon matches
	// 2 - final state non-photon match
      if (PhotonGenMatch_matchCategory == 2) {
	nFinalStateNonPhotonMatch_EE+=Event_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStateNonPhotonNoMatch_EE+=Event_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) nFinalStateNonPhotonHadronMother_EE+=Event_weight;
	// 5 - electron pair
	if (PhotonGenMatch_matchType == 6) nFinalStateNonPhotonElectronPair_EE+=Event_weight;
      } // end final state non-photon matches
	// 3 - gen particle photon match
      if (PhotonGenMatch_matchCategory == 3) {
	nGenParticlePhotonMatch_EE+=Event_weight;
      } // end gen particle photon matches
	// 4 - gen particle non-photon match
      if (PhotonGenMatch_matchCategory == 4) {
	nGenParticleNonPhotonMatch_EE+=Event_weight;
      } // end gen particle non-photon matches
    } // end EE
    
    // loop over bin edges
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      
      // pt cut
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {

	// fill numerator histograms -- only numberator objects are filled in this tree anyway
	if (isNumeratorObj) {

	  // fake photons
	  if (fakes) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // real photons
	  if (reals) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  
	  // photonHadronMother photons
	  if (photonHadronMother) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonHadronMother.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonHadronMother.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // photonISR photons
	  if (photonISR) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonISR.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonISR.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // photonFSR photons
	  if (photonFSR) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonFSR.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonFSR.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // photonOtherFragQuark photons
	  if (photonOtherFragQuark) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonOtherFragQuark.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonOtherFragQuark.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // photonOtherFragGluon photons
	  if (photonOtherFragGluon) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonOtherFragGluon.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonOtherFragGluon.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // noMatch photons
	  if (noMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromNoMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromNoMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // nonPhotonMatch photons
	  if (nonPhotonMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromNonPhotonMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromNonPhotonMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
	  // genParticleMatch photons
	  if (genParticleMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromGenParticleMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromGenParticleMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  }
     	  
	} // end numerator obj

      } // end pt cut
      
    } // end loop over pt bins for fake template
    
  } // end loop over entries

  cout << endl;
  cout << "Number of numerator objects (passing sipip cut): " << nEvents << endl;
  cout << endl;
  cout << "--------------------------------------EB------------------------------------------ " << endl;
  cout << "Number of numerator objects              : " << nEvents_EB << endl;
  cout << endl;
  cout << "Number of final state photon matches     : " << nFinalStatePhotonMatch_EB << endl;
  cout << "Number of final state non-photon matches : " << nFinalStateNonPhotonMatch_EB << endl;
  cout << "Number of gen particle photon matches    : " << nGenParticlePhotonMatch_EB << endl;
  cout << "Number of gen particle non-photon matches: " << nGenParticleNonPhotonMatch_EB << endl;
  cout << "Number of no matches                     : " << nNoMatch_EB << endl;
  cout << "Sum of 5 match categories                : " << nFinalStatePhotonMatch_EB+nFinalStateNonPhotonMatch_EB+nGenParticlePhotonMatch_EB+nGenParticleNonPhotonMatch_EB+nNoMatch_EB << endl;
  cout << endl;
  cout << "Number of final state photon hadron mothers                        : " << nFinalStatePhotonHadronMother_EB << endl;
  cout << "Number of final state photon FSR                                   : " << nFinalStatePhotonFSR_EB << endl;
  cout << "Number of final state photon ISR                                   : " << nFinalStatePhotonISR_EB << endl;
  cout << "Number of final state other photon fragmentation with gluon mothers: " << nFinalStatePhotonOtherFragmentationGluon_EB << endl;
  cout << "Number of final state other photon fragmentation with quark mothers: " << nFinalStatePhotonOtherFragmentationQuark_EB << endl;
  cout << "Number final state photon no matches                               : " << nFinalStatePhotonNoMatch_EB << endl;
  cout << "Sum of 6 match types                                               : " << nFinalStatePhotonHadronMother_EB+nFinalStatePhotonFSR_EB+nFinalStatePhotonISR_EB+
    nFinalStatePhotonOtherFragmentationGluon_EB+nFinalStatePhotonOtherFragmentationQuark_EB+nFinalStatePhotonNoMatch_EB << endl;
  cout << endl;
  cout << "Number of final state non-photon hadron mothers: " << nFinalStateNonPhotonHadronMother_EB << endl;
  cout << "Number of final state non-photon electron pairs: " << nFinalStateNonPhotonElectronPair_EB << endl;
  cout << "Number final state non-photon no matches       : " << nFinalStateNonPhotonNoMatch_EB << endl;
  cout << "Sum of 3 match types                           : " << nFinalStateNonPhotonHadronMother_EB+nFinalStateNonPhotonElectronPair_EB+nFinalStateNonPhotonNoMatch_EB << endl;
  cout << endl;
  cout << "Average number of daughters for hadron mother case: " << nAveNumDaughtersHadronMother_EB/(double)nFinalStatePhotonHadronMother_EB << endl;
  cout << "Average number of daughters for FSR case          : " << nAveNumDaughtersFSR_EB/(double)nFinalStatePhotonFSR_EB << endl;
  cout << "Average number of daughters for ISR case          : " << nAveNumDaughtersISR_EB/(double)nFinalStatePhotonISR_EB << endl;
  cout << "Average number of daughters for quark frag. case  : " << nAveNumDaughtersFragQuark_EB/(double)nFinalStatePhotonOtherFragmentationQuark_EB << endl;
  cout << "Average number of daughters for gluon frag. case  : " << nAveNumDaughtersFragGluon_EB/(double)nFinalStatePhotonOtherFragmentationGluon_EB << endl;
  cout << endl;
  cout << "--------------------------------------EE------------------------------------------ " << endl;
  cout << "Number of numerator objects              : " << nEvents_EE << endl;
  cout << endl;
  cout << "Number of final state photon matches     : " << nFinalStatePhotonMatch_EE << endl;
  cout << "Number of final state non-photon matches : " << nFinalStateNonPhotonMatch_EE << endl;
  cout << "Number of gen particle photon matches    : " << nGenParticlePhotonMatch_EE << endl;
  cout << "Number of gen particle non-photon matches: " << nGenParticleNonPhotonMatch_EE << endl;
  cout << "Number of no matches                     : " << nNoMatch_EE << endl;
  cout << "Sum of 5 match categories                : " << nFinalStatePhotonMatch_EE+nFinalStateNonPhotonMatch_EE+nGenParticlePhotonMatch_EE+nGenParticleNonPhotonMatch_EE+nNoMatch_EE << endl;
  cout << endl;
  cout << "Number of final state photon hadron mothers                        : " << nFinalStatePhotonHadronMother_EE << endl;
  cout << "Number of final state photon FSR                                   : " << nFinalStatePhotonFSR_EE << endl;
  cout << "Number of final state photon ISR                                   : " << nFinalStatePhotonISR_EE << endl;
  cout << "Number of final state other photon fragmentation with gluon mothers: " << nFinalStatePhotonOtherFragmentationGluon_EE << endl;
  cout << "Number of final state other photon fragmentation with quark mothers: " << nFinalStatePhotonOtherFragmentationQuark_EE << endl;
  cout << "Number final state photon no matches                               : " << nFinalStatePhotonNoMatch_EE << endl;
  cout << "Sum of 6 match types                                               : " << nFinalStatePhotonHadronMother_EE+nFinalStatePhotonFSR_EE+nFinalStatePhotonISR_EE+
    nFinalStatePhotonOtherFragmentationGluon_EE+nFinalStatePhotonOtherFragmentationQuark_EE+nFinalStatePhotonNoMatch_EE << endl;
  cout << endl;
  cout << "Number of final state non-photon hadron mothers: " << nFinalStateNonPhotonHadronMother_EE << endl;
  cout << "Number of final state non-photon electron pairs: " << nFinalStateNonPhotonElectronPair_EE << endl;
  cout << "Number final state non-photon no matches       : " << nFinalStateNonPhotonNoMatch_EE << endl;
  cout << "Sum of 3 match types                           : " << nFinalStateNonPhotonHadronMother_EE+nFinalStateNonPhotonElectronPair_EE+nFinalStateNonPhotonNoMatch_EE << endl;
  cout << endl;
  cout << "Average number of daughters for hadron mother case: " << nAveNumDaughtersHadronMother_EE/(double)nFinalStatePhotonHadronMother_EE << endl;
  cout << "Average number of daughters for FSR case          : " << nAveNumDaughtersFSR_EE/(double)nFinalStatePhotonFSR_EE << endl;
  cout << "Average number of daughters for ISR case          : " << nAveNumDaughtersISR_EE/(double)nFinalStatePhotonISR_EE << endl;
  cout << "Average number of daughters for quark frag. case  : " << nAveNumDaughtersFragQuark_EE/(double)nFinalStatePhotonOtherFragmentationQuark_EE << endl;
  cout << "Average number of daughters for gluon frag. case  : " << nAveNumDaughtersFragGluon_EE/(double)nFinalStatePhotonOtherFragmentationGluon_EE << endl;
  cout << endl;
  
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
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonHadronMother.begin() ; it != sIeIeNumeratorEB_fromPhotonHadronMother.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonHadronMother.begin() ; it != sIeIeNumeratorEE_fromPhotonHadronMother.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonISR.begin() ; it != sIeIeNumeratorEB_fromPhotonISR.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonISR.begin() ; it != sIeIeNumeratorEE_fromPhotonISR.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonFSR.begin() ; it != sIeIeNumeratorEB_fromPhotonFSR.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonFSR.begin() ; it != sIeIeNumeratorEE_fromPhotonFSR.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonOtherFragQuark.begin() ; it != sIeIeNumeratorEB_fromPhotonOtherFragQuark.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonOtherFragQuark.begin() ; it != sIeIeNumeratorEE_fromPhotonOtherFragQuark.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonOtherFragGluon.begin() ; it != sIeIeNumeratorEB_fromPhotonOtherFragGluon.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonOtherFragGluon.begin() ; it != sIeIeNumeratorEE_fromPhotonOtherFragGluon.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromNoMatch.begin() ; it != sIeIeNumeratorEB_fromNoMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromNoMatch.begin() ; it != sIeIeNumeratorEE_fromNoMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromNonPhotonMatch.begin() ; it != sIeIeNumeratorEB_fromNonPhotonMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromNonPhotonMatch.begin() ; it != sIeIeNumeratorEE_fromNonPhotonMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromGenParticleMatch.begin() ; it != sIeIeNumeratorEB_fromGenParticleMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromGenParticleMatch.begin() ; it != sIeIeNumeratorEE_fromGenParticleMatch.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  
  file_out.ls();
  file_out.Close();
  
} // end of Loop()
