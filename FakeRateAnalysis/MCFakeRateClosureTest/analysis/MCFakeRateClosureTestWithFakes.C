#define MCFakeRateClosureTestWithFakes_cxx
#include "MCFakeRateClosureTestWithFakes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MCFakeRateClosureTestWithFakes::Loop()
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
  int nFinalStatePhotonISRfromProton_EB = 0;
  int nFinalStateOtherPhotonRadiation_EB = 0;
  int nFinalStatePhotonGluonMotherPhotonFrag_EB = 0;
  int nFinalStatePhotonOtherPhotonFragmentation_EB = 0;
  // EE
  int nFinalStatePhotonNoMatch_EE = 0;
  int nFinalStatePhotonHadronMother_EE = 0;
  int nFinalStatePhotonISRfromProton_EE = 0;
  int nFinalStateOtherPhotonRadiation_EE = 0;
  int nFinalStatePhotonGluonMotherPhotonFrag_EE = 0;
  int nFinalStatePhotonOtherPhotonFragmentation_EE = 0;
  
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
  int nAveNumDaughtersISRfromProton_EB = 0;
  int nAveNumDaughtersOtherPhotonRadiation_EB = 0;
  int nAveNumDaughtersGluonMotherPhotonFrag_EB = 0;
  int nAveNumDaughtersOtherPhotonFragmentation_EB = 0;
  // EE
  int nAveNumDaughtersHadronMother_EE = 0;
  int nAveNumDaughtersISRfromProton_EE = 0;
  int nAveNumDaughtersOtherPhotonRadiation_EE = 0;
  int nAveNumDaughtersGluonMotherPhotonFrag_EE = 0;
  int nAveNumDaughtersOtherPhotonFragmentation_EE = 0;
  
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
  std::vector<TH1D*> sIeIeNumeratorEB_fromPhotonISRfromProton;
  std::vector<TH1D*> sIeIeNumeratorEE_fromPhotonISRfromProton;
  std::vector<TH1D*> sIeIeNumeratorEB_fromOtherPhotonRadiation;
  std::vector<TH1D*> sIeIeNumeratorEE_fromOtherPhotonRadiation;
  std::vector<TH1D*> sIeIeNumeratorEB_fromGluonMotherPhotonFrag;
  std::vector<TH1D*> sIeIeNumeratorEE_fromGluonMotherPhotonFrag;
  std::vector<TH1D*> sIeIeNumeratorEB_fromOtherPhotonFragmentation;
  std::vector<TH1D*> sIeIeNumeratorEE_fromOtherPhotonFragmentation;
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
    
    TH1D *hEB_numerator_photonISRfromProton = new TH1D(Form("sieieEB_numerator_photonISRfromProton_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_photonISRfromProton->Sumw2();
    sIeIeNumeratorEB_fromPhotonISRfromProton.push_back(hEB_numerator_photonISRfromProton);
    TH1D *hEE_numerator_photonISRfromProton = new TH1D(Form("sieieEE_numerator_photonISRfromProton_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_photonISRfromProton->Sumw2();
    sIeIeNumeratorEE_fromPhotonISRfromProton.push_back(hEE_numerator_photonISRfromProton);

    TH1D *hEB_numerator_otherPhotonRadiation = new TH1D(Form("sieieEB_numerator_otherPhotonRadiation_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_otherPhotonRadiation->Sumw2();
    sIeIeNumeratorEB_fromOtherPhotonRadiation.push_back(hEB_numerator_otherPhotonRadiation);
    TH1D *hEE_numerator_otherPhotonRadiation = new TH1D(Form("sieieEE_numerator_otherPhotonRadiation_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_otherPhotonRadiation->Sumw2();
    sIeIeNumeratorEE_fromOtherPhotonRadiation.push_back(hEE_numerator_otherPhotonRadiation);
    
    TH1D *hEB_numerator_gluonMotherPhotonFrag = new TH1D(Form("sieieEB_numerator_gluonMotherPhotonFrag_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_gluonMotherPhotonFrag->Sumw2();
    sIeIeNumeratorEB_fromGluonMotherPhotonFrag.push_back(hEB_numerator_gluonMotherPhotonFrag);
    TH1D *hEE_numerator_gluonMotherPhotonFrag = new TH1D(Form("sieieEE_numerator_gluonMotherPhotonFrag_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_gluonMotherPhotonFrag->Sumw2();
    sIeIeNumeratorEE_fromGluonMotherPhotonFrag.push_back(hEE_numerator_gluonMotherPhotonFrag);
    
    TH1D *hEB_numerator_otherPhotonFragmentation = new TH1D(Form("sieieEB_numerator_otherPhotonFragmentation_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator_otherPhotonFragmentation->Sumw2();
    sIeIeNumeratorEB_fromOtherPhotonFragmentation.push_back(hEB_numerator_otherPhotonFragmentation);
    TH1D *hEE_numerator_otherPhotonFragmentation = new TH1D(Form("sieieEE_numerator_otherPhotonFragmentation_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator_otherPhotonFragmentation->Sumw2();
    sIeIeNumeratorEE_fromOtherPhotonFragmentation.push_back(hEE_numerator_otherPhotonFragmentation);
    
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

    // numerator photons
    bool isNumeratorObj = Photon_isNumeratorObjCand && Photon_passChIso;
    // sideband photons
    //bool isNumeratorObj = Photon_isNumeratorObjCand && (5.0 < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < 10.);
    
    // reject beam halo
    //if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;

    // reals -- photon radiation (ISRfromProton and OtherPhotonRadiation)
    bool reals = PhotonGenMatch_matchCategory == 1 && (PhotonGenMatch_matchType == 2 || PhotonGenMatch_matchType == 3);
    // fakes -- photon hadron mothers and all non-photon
    bool fakes = (PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 1) || (PhotonGenMatch_matchCategory == 2);
          
    
    // photonHadronMother -- photon hadron mothers 
    bool photonHadronMother = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 1;
    // photonISRfromProton -- photon ISR from proton
    bool photonISRfromProton = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 2;
    // otherPhotonRadiation -- other photon radiation
    bool otherPhotonRadiation = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 3;
    // gluonMotherPhotonFrag -- photon fragmentation from gluon mother
    bool gluonMotherPhotonFrag = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 4;
    // otherPhotonFragmentation -- other photon fragmentation
    bool otherPhotonFragmentation = PhotonGenMatch_matchCategory == 1 && PhotonGenMatch_matchType == 5;
    // noMatch -- no matches
    bool noMatch = PhotonGenMatch_matchCategory == 0;
    // nonPhotonMatch -- non-photon matches
    bool nonPhotonMatch = PhotonGenMatch_matchCategory == 2;
    // genParticleMatch -- gen particle matches
    bool genParticleMatch = PhotonGenMatch_matchCategory == 3 || PhotonGenMatch_matchCategory == 4;

    //if (!Photon_passSieie) continue;

    // apply event weights to counting of objects (currently set to 1, unweighted)
    double event_counting_weight = 1; //Event_weightAll
    
    // count number of numberator objects -- only numerator objects are filled in fTreeFake tree
    nEvents+=event_counting_weight;
    
    // EB
    if (fabs(Photon_scEta) < 1.4442) {
      nEvents_EB+=event_counting_weight;
      if (fakes) {
	if (Photon_passHighPtID) {
	  phoPtEB_passHighPtID_varbin.Fill(Photon_pt,Event_weightAll);
	}
      }
      // 0 - no match
      if (PhotonGenMatch_matchCategory == 0) {
	nNoMatch_EB+=event_counting_weight;
      }
      // 1 - final state photon match
      if (PhotonGenMatch_matchCategory == 1) {
	nFinalStatePhotonMatch_EB+=event_counting_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStatePhotonNoMatch_EB+=event_counting_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) {
	  nFinalStatePhotonHadronMother_EB+=event_counting_weight;
	  nAveNumDaughtersHadronMother_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 2 - photon ISR from photon
	if (PhotonGenMatch_matchType == 2) {
	  nFinalStatePhotonISRfromProton_EB+=event_counting_weight;
	  nAveNumDaughtersISRfromProton_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 3 - other photon radiation
	if (PhotonGenMatch_matchType == 3) {
	  nFinalStateOtherPhotonRadiation_EB+=event_counting_weight;
	  nAveNumDaughtersOtherPhotonRadiation_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 4 - photon fragmentation from gluon mother
	if (PhotonGenMatch_matchType == 4) {
	  nFinalStatePhotonGluonMotherPhotonFrag_EB+=event_counting_weight;
	  nAveNumDaughtersGluonMotherPhotonFrag_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 5 - other photon fragmentation
	if (PhotonGenMatch_matchType == 5) {
	  nFinalStatePhotonOtherPhotonFragmentation_EB+=event_counting_weight;
	  nAveNumDaughtersOtherPhotonFragmentation_EB+=PhotonGenMatch_nPhotonMotherDaughters;
	}
      } // end final state photon matches
      // 2 - final state non-photon match
      if (PhotonGenMatch_matchCategory == 2) {
	nFinalStateNonPhotonMatch_EB+=event_counting_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStateNonPhotonNoMatch_EB+=event_counting_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) nFinalStateNonPhotonHadronMother_EB+=event_counting_weight;
	// 6 - electron pair
	if (PhotonGenMatch_matchType == 6) nFinalStateNonPhotonElectronPair_EB+=event_counting_weight;
      } // end final state non-photon matches
      // 3 - gen particle photon match
      if (PhotonGenMatch_matchCategory == 3) {
	nGenParticlePhotonMatch_EB+=event_counting_weight;
      } // end gen particle photon matches
      // 4 - gen particle non-photon match
      if (PhotonGenMatch_matchCategory == 4) {
	nGenParticleNonPhotonMatch_EB+=event_counting_weight;
      } // end gen particle non-photon matches
    } // end EB
    // EE
    else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
      nEvents_EE+=event_counting_weight;
      if (fakes) {
	if (Photon_passHighPtID) {
	  phoPtEE_passHighPtID_varbin.Fill(Photon_pt,Event_weightAll);
	}
      }
      // 0 - no match
      if (PhotonGenMatch_matchCategory == 0) {
	nNoMatch_EE+=event_counting_weight;
      }
      // 1 - final state photon match
      if (PhotonGenMatch_matchCategory == 1) {
	nFinalStatePhotonMatch_EE+=event_counting_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStatePhotonNoMatch_EE+=event_counting_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) {
	  nFinalStatePhotonHadronMother_EE+=event_counting_weight;
	  nAveNumDaughtersHadronMother_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 2 - photon ISR from proton
	if (PhotonGenMatch_matchType == 2) {
	  nFinalStatePhotonISRfromProton_EE+=event_counting_weight;
	  nAveNumDaughtersISRfromProton_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 3 - other photon radiation
	if (PhotonGenMatch_matchType == 3) {
	  nFinalStateOtherPhotonRadiation_EE+=event_counting_weight;
	  nAveNumDaughtersOtherPhotonRadiation_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 4 - photon fragmentation from gluon mother
	if (PhotonGenMatch_matchType == 4) {
	  nFinalStatePhotonGluonMotherPhotonFrag_EE+=event_counting_weight;
	  nAveNumDaughtersGluonMotherPhotonFrag_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
	// 5 - other photon fragmentation
	if (PhotonGenMatch_matchType == 5) {
	  nFinalStatePhotonOtherPhotonFragmentation_EE+=event_counting_weight;
	  nAveNumDaughtersOtherPhotonFragmentation_EE+=PhotonGenMatch_nPhotonMotherDaughters;
	}
      } // end final state photon matches
      // 2 - final state non-photon match
      if (PhotonGenMatch_matchCategory == 2) {
	nFinalStateNonPhotonMatch_EE+=event_counting_weight;
	// 0 - no match
	if (PhotonGenMatch_matchType == 0) nFinalStateNonPhotonNoMatch_EE+=event_counting_weight;
	// 1 - hadron mother
	if (PhotonGenMatch_matchType == 1) nFinalStateNonPhotonHadronMother_EE+=event_counting_weight;
	// 6 - electron pair
	if (PhotonGenMatch_matchType == 6) nFinalStateNonPhotonElectronPair_EE+=event_counting_weight;
      } // end final state non-photon matches
      // 3 - gen particle photon match
      if (PhotonGenMatch_matchCategory == 3) {
	nGenParticlePhotonMatch_EE+=event_counting_weight;
      } // end gen particle photon matches
      // 4 - gen particle non-photon match
      if (PhotonGenMatch_matchCategory == 4) {
	nGenParticleNonPhotonMatch_EE+=event_counting_weight;
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
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromFakes.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // real photons
	  if (reals) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromReal.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  
	  // photonHadronMother photons
	  if (photonHadronMother) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonHadronMother.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonHadronMother.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // photonISRfromProton photons
	  if (photonISRfromProton) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromPhotonISRfromProton.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromPhotonISRfromProton.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // otherPhotonRadiation photons
	  if (otherPhotonRadiation) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromOtherPhotonRadiation.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromOtherPhotonRadiation.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // gluonMotherPhotonFrag photons
	  if (gluonMotherPhotonFrag) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromGluonMotherPhotonFrag.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromGluonMotherPhotonFrag.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // otherPhotonFragmentation photons
	  if (otherPhotonFragmentation) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromOtherPhotonFragmentation.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromOtherPhotonFragmentation.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // noMatch photons
	  if (noMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromNoMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromNoMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // nonPhotonMatch photons
	  if (nonPhotonMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromNonPhotonMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromNonPhotonMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
	  // genParticleMatch photons
	  if (genParticleMatch) {
	    if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB_fromGenParticleMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	    else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE_fromGenParticleMatch.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
	  }
     	  
	} // end numerator obj

      } // end pt cut
      
    } // end loop over pt bins for fake template
    
  } // end loop over entries

  cout << endl;
  cout << "Not applying event or sample weights for these object numbers." << endl;
  cout << endl;
  cout << "Number of numerator objects (passing sipip cut): " << nEvents << endl;
  cout << endl;
  cout << "--------------------------------------EB------------------------------------------ " << endl;
  cout << "Number of numerator objects              : " << nEvents_EB << endl;
  cout << endl;
  cout << "Number of final state photon matches     : " << nFinalStatePhotonMatch_EB << setw(2) << "(" << setprecision(2) << fixed << (nFinalStatePhotonMatch_EB*100./nEvents_EB) << "%)" << endl;
  cout << "Number of final state non-photon matches : " << nFinalStateNonPhotonMatch_EB << setw(2) << "(" << setprecision(2) << fixed << (nFinalStateNonPhotonMatch_EB*100./nEvents_EB) << "%)" << endl;
  cout << "Number of gen particle photon matches    : " << nGenParticlePhotonMatch_EB << setw(2) << "(" << setprecision(2) << fixed <<  (nGenParticlePhotonMatch_EB*100./nEvents_EB) << "%)" << endl;
  cout << "Number of gen particle non-photon matches: " << nGenParticleNonPhotonMatch_EB << setw(2) << "(" << setprecision(2) << fixed << (nGenParticleNonPhotonMatch_EB*100./nEvents_EB) << "%)" << endl;
  cout << "Number of no matches                     : " << nNoMatch_EB << setw(2) << "(" << setprecision(2) << fixed << (nNoMatch_EB*100./nEvents_EB) << "%)" << endl;
  cout << "Sum of 5 match categories                : " << nFinalStatePhotonMatch_EB+nFinalStateNonPhotonMatch_EB+nGenParticlePhotonMatch_EB+nGenParticleNonPhotonMatch_EB+nNoMatch_EB << endl;
  cout << endl;
  cout << "Number of final state photon - hadron mothers                 : " << nFinalStatePhotonHadronMother_EB << endl;
  cout << "Number of final state photon - ISR from proton                : " << nFinalStatePhotonISRfromProton_EB << endl;
  cout << "Number of final state photon - other photon radiation         : " << nFinalStateOtherPhotonRadiation_EB << endl;
  cout << "Number of final state photon - fragmentation from gluon mother: " << nFinalStatePhotonGluonMotherPhotonFrag_EB << endl;
  cout << "Number of final state photon - other photon fragmentation     : " << nFinalStatePhotonOtherPhotonFragmentation_EB << endl;
  cout << "Number of final state photon - no matches                     : " << nFinalStatePhotonNoMatch_EB << endl;
  cout << "Sum of 6 match types                                          : " << nFinalStatePhotonHadronMother_EB+nFinalStatePhotonISRfromProton_EB+nFinalStateOtherPhotonRadiation_EB+
    nFinalStatePhotonOtherPhotonFragmentation_EB+nFinalStatePhotonGluonMotherPhotonFrag_EB+nFinalStatePhotonNoMatch_EB << endl;
  cout << endl;
  cout << "Number of final state non-photon - hadron mothers: " << nFinalStateNonPhotonHadronMother_EB << endl;
  cout << "Number of final state non-photon - electron pairs: " << nFinalStateNonPhotonElectronPair_EB << endl;
  cout << "Number of final state non-photon - no matches    : " << nFinalStateNonPhotonNoMatch_EB << endl;
  cout << "Sum of 3 match types                             : " << nFinalStateNonPhotonHadronMother_EB+nFinalStateNonPhotonElectronPair_EB+nFinalStateNonPhotonNoMatch_EB << endl;
  cout << endl;
  cout << "Average number of daughters - hadron mother case     : " << nAveNumDaughtersHadronMother_EB/(double)nFinalStatePhotonHadronMother_EB << endl;
  cout << "Average number of daughters - ISR from proton        : " << nAveNumDaughtersISRfromProton_EB/(double)nFinalStatePhotonISRfromProton_EB << endl;
  cout << "Average number of daughters - other radiation        : " << nAveNumDaughtersOtherPhotonRadiation_EB/(double)nFinalStateOtherPhotonRadiation_EB << endl;
  cout << "Average number of daughters - frag. from gluon mother: " << nAveNumDaughtersGluonMotherPhotonFrag_EB/(double)nFinalStatePhotonGluonMotherPhotonFrag_EB << endl;
  cout << "Average number of daughters - other fragmentation    : " << nAveNumDaughtersOtherPhotonFragmentation_EB/(double)nFinalStatePhotonOtherPhotonFragmentation_EB << endl;
  cout << endl;
  cout << "--------------------------------------EE------------------------------------------ " << endl;
  cout << "Number of numerator objects              : " << nEvents_EE << endl;
  cout << endl;
  cout << "Number of final state photon matches     : " << nFinalStatePhotonMatch_EE << setw(2) << "(" << setprecision(2) << fixed << (nFinalStatePhotonMatch_EE*100./nEvents_EE) << "%)" << endl;
  cout << "Number of final state non-photon matches : " << nFinalStateNonPhotonMatch_EE << setw(2) << "(" << setprecision(2) << fixed << (nFinalStateNonPhotonMatch_EE*100./nEvents_EE) << "%)" << endl;
  cout << "Number of gen particle photon matches    : " << nGenParticlePhotonMatch_EE << setw(2) << "(" << setprecision(2) << fixed <<  (nGenParticlePhotonMatch_EE*100./nEvents_EE) << "%)" << endl;
  cout << "Number of gen particle non-photon matches: " << nGenParticleNonPhotonMatch_EE << setw(2) << "(" << setprecision(2) << fixed << (nGenParticleNonPhotonMatch_EE*100./nEvents_EE) << "%)" << endl;
  cout << "Number of no matches                     : " << nNoMatch_EE << setw(2) << "(" << setprecision(2) << fixed << (nNoMatch_EE*100./nEvents_EE) << "%)" << endl;
  cout << "Sum of 5 match categories                : " << nFinalStatePhotonMatch_EE+nFinalStateNonPhotonMatch_EE+nGenParticlePhotonMatch_EE+nGenParticleNonPhotonMatch_EE+nNoMatch_EE << endl;
  cout << endl;
  cout << "Number of final state photon - hadron mothers                 : " << nFinalStatePhotonHadronMother_EE << endl;
  cout << "Number of final state photon - ISR from proton                : " << nFinalStatePhotonISRfromProton_EE << endl;
  cout << "Number of final state photon - other photon radiation         : " << nFinalStateOtherPhotonRadiation_EE << endl;
  cout << "Number of final state photon - fragmentation from gluon mother: " << nFinalStatePhotonGluonMotherPhotonFrag_EE << endl;
  cout << "Number of final state photon - other photon fragmentation     : " << nFinalStatePhotonOtherPhotonFragmentation_EE << endl;
  cout << "Number of final state photon - no matches                     : " << nFinalStatePhotonNoMatch_EE << endl;
  cout << "Sum of 6 match types                                          : " << nFinalStatePhotonHadronMother_EE+nFinalStatePhotonISRfromProton_EE+nFinalStateOtherPhotonRadiation_EE+
    nFinalStatePhotonOtherPhotonFragmentation_EE+nFinalStatePhotonGluonMotherPhotonFrag_EE+nFinalStatePhotonNoMatch_EE << endl;
  cout << endl;
  cout << "Number of final state non-photon - hadron mothers: " << nFinalStateNonPhotonHadronMother_EE << endl;
  cout << "Number of final state non-photon - electron pairs: " << nFinalStateNonPhotonElectronPair_EE << endl;
  cout << "Number of final state non-photon - no matches    : " << nFinalStateNonPhotonNoMatch_EE << endl;
  cout << "Sum of 3 match types                             : " << nFinalStateNonPhotonHadronMother_EE+nFinalStateNonPhotonElectronPair_EE+nFinalStateNonPhotonNoMatch_EE << endl;
  cout << endl;
  cout << "Average number of daughters - hadron mother case     : " << nAveNumDaughtersHadronMother_EE/(double)nFinalStatePhotonHadronMother_EE << endl;
  cout << "Average number of daughters - ISR from proton        : " << nAveNumDaughtersISRfromProton_EE/(double)nFinalStatePhotonISRfromProton_EE << endl;
  cout << "Average number of daughters - other radiation        : " << nAveNumDaughtersOtherPhotonRadiation_EE/(double)nFinalStateOtherPhotonRadiation_EE << endl;
  cout << "Average number of daughters - frag. from gluon mother: " << nAveNumDaughtersGluonMotherPhotonFrag_EE/(double)nFinalStatePhotonGluonMotherPhotonFrag_EE << endl;
  cout << "Average number of daughters - other fragmentation    : " << nAveNumDaughtersOtherPhotonFragmentation_EE/(double)nFinalStatePhotonOtherPhotonFragmentation_EE << endl;
  cout << endl;
  
  TString filename = "diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
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
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromPhotonISRfromProton.begin() ; it != sIeIeNumeratorEB_fromPhotonISRfromProton.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromPhotonISRfromProton.begin() ; it != sIeIeNumeratorEE_fromPhotonISRfromProton.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromOtherPhotonRadiation.begin() ; it != sIeIeNumeratorEB_fromOtherPhotonRadiation.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromOtherPhotonRadiation.begin() ; it != sIeIeNumeratorEE_fromOtherPhotonRadiation.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromGluonMotherPhotonFrag.begin() ; it != sIeIeNumeratorEB_fromGluonMotherPhotonFrag.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromGluonMotherPhotonFrag.begin() ; it != sIeIeNumeratorEE_fromGluonMotherPhotonFrag.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB_fromOtherPhotonFragmentation.begin() ; it != sIeIeNumeratorEB_fromOtherPhotonFragmentation.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE_fromOtherPhotonFragmentation.begin() ; it != sIeIeNumeratorEE_fromOtherPhotonFragmentation.end(); ++it) {
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
