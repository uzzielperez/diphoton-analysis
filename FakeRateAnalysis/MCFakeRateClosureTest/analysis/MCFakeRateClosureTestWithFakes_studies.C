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
  
  // match category counters
  int nNoMatch = 0;
  int nFinalStatePhotonMatch = 0;
  int nFinalStateNonPhotonMatch = 0;
  int nGenParticlePhotonMatch = 0;
  int nGenParticleNonPhotonMatch = 0;
  
  // final state photon type counters
  int nFinalStatePhotonNoMatch = 0;
  int nFinalStatePhotonHadronMother = 0;
  int nFinalStatePhotonFSR = 0;
  int nFinalStatePhotonISR = 0;
  int nFinalStatePhotonOtherFragmentation = 0;

  // final state non-photon type counters
  int nFinalStateNonPhotonNoMatch = 0;
  int nFinalStateNonPhotonHadronMother = 0;
  int nFinalStateNonPhotonElectronPair = 0;
  
  //TH1D *h_finalState_FSR_deltaR  = new TH1D("h_finalState_FSR_deltaR","",100,0.,10.);
  //TH1D *h_genParticle_FSR_deltaR = new TH1D("h_genParticle_FSR_deltaR","",100,0.,10.);
  
  int nFinalStatePhotonFSRDeltaRIn03 = 0;
  int nFinalStatePhotonISRDeltaRIn03 = 0;
  int nFinalStatePhotonFSRDeltaRIn07 = 0;
  int nFinalStatePhotonISRDeltaRIn07 = 0;

  int nGluonFakes = 0;
  int nQuarkFakes = 0;
  int nUnknownFakes = 0;

  double ptCut = 50.;
  int nPassPtCut = 0;

  TH1D *h_numeratorPhotonPt_all     = new TH1D("h_numeratorPhotonPt_all","",500,0.,1000.);
  TH1D *h_numeratorPhotonPt_noMatch = new TH1D("h_numeratorPhotonPt_noMatch","",500,0.,1000.);

  TH1D *h_finalState_deltaR = new TH1D("h_finalState_deltaR","",100,0,1);
  TH1D *h_genParticle_deltaR = new TH1D("h_genParticle_deltaR","",100,0,1);
				       
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    h_numeratorPhotonPt_all->Fill(Photon_pt,Event_weight);
    if (PhotonGenMatch_matchCategory == 0) h_numeratorPhotonPt_noMatch->Fill(Photon_pt,Event_weight);

    if (PhotonGenMatch_matchCategory == 1 || PhotonGenMatch_matchCategory == 2) h_finalState_deltaR->Fill(PhotonGenMatch_deltaR_match); // event weight?
    if (PhotonGenMatch_matchCategory == 3 || PhotonGenMatch_matchCategory == 4) h_genParticle_deltaR->Fill(PhotonGenMatch_deltaR_match); // event weight?
    
    if (Photon_pt < ptCut) continue;

    nPassPtCut++;
    
    // 0 - no match
    if (PhotonGenMatch_matchCategory == 0) nNoMatch++;
    
    // 1 - final state photon match
    if (PhotonGenMatch_matchCategory == 1) {
      nFinalStatePhotonMatch++;
      // 0 - no match
      if (PhotonGenMatch_matchType == 0) nFinalStatePhotonNoMatch++;
      // 1 - hadron mother
      if (PhotonGenMatch_matchType == 1) {
	nFinalStatePhotonHadronMother++;
	if (PhotonGenMatch_pdgId == 21) nGluonFakes++;
	else if (-9 < PhotonGenMatch_pdgId && PhotonGenMatch_pdgId < 9) nQuarkFakes++;
	else nUnknownFakes++;
      }
      // 2 - FSR
      if (PhotonGenMatch_matchType == 2) {
	nFinalStatePhotonFSR++;
	if (PhotonGenMatch_deltaR_FSR <= 0.3) nFinalStatePhotonFSRDeltaRIn03++;
	if (PhotonGenMatch_deltaR_FSR <= 0.7) nFinalStatePhotonFSRDeltaRIn07++;
      }
      // 3 - ISR
      if (PhotonGenMatch_matchType == 3) {
	nFinalStatePhotonISR++;
	if (PhotonGenMatch_deltaR_FSR <= 0.3) nFinalStatePhotonISRDeltaRIn03++;
	if (PhotonGenMatch_deltaR_FSR <= 0.7) nFinalStatePhotonISRDeltaRIn07++;
      }
      // 4 - other fragmentation
      if (PhotonGenMatch_matchType == 4) {
	nFinalStatePhotonOtherFragmentation++;
	if (PhotonGenMatch_pdgId == 21) nGluonFakes++;
	else if (-9 < PhotonGenMatch_pdgId && PhotonGenMatch_pdgId < 9) nQuarkFakes++;
	else nUnknownFakes++;
      }
    }
    
    // 2 - final state non-photon match
    if (PhotonGenMatch_matchCategory == 2) {
      nFinalStateNonPhotonMatch++;
      // 0 - no match
      if (PhotonGenMatch_matchType == 0) nFinalStateNonPhotonNoMatch++;
      // 1 - hadron mother
      if (PhotonGenMatch_matchType == 1) {
	nFinalStateNonPhotonHadronMother++;
	if (PhotonGenMatch_pdgId == 21) nGluonFakes++;
	else if (-9 < PhotonGenMatch_pdgId && PhotonGenMatch_pdgId < 9) nQuarkFakes++;
	else nUnknownFakes++;
      }
      // 5 - electron pair
      if (PhotonGenMatch_matchType == 5) nFinalStateNonPhotonElectronPair++;
    }
    
    // 3 - gen particle photon match
    if (PhotonGenMatch_matchCategory == 3) {
      nGenParticlePhotonMatch++;
    }

    // 4 - gen particle non-phootn match
    if (PhotonGenMatch_matchCategory == 4) {
      nGenParticleNonPhotonMatch++;
    }

  } // end for loop
  
  cout << endl;
  cout << "Number of numerator photons             : " << nentries << endl;
  cout << "Number of numerator photons with pt > " << ptCut << ": " << nPassPtCut << endl;
  cout << endl;
  cout << "Number of final state photon matches     : " << nFinalStatePhotonMatch << endl;
  cout << "Number of final state non-photon matches : " << nFinalStateNonPhotonMatch << endl;
  cout << "Number of gen particle photon matches    : " << nGenParticlePhotonMatch << endl;
  cout << "Number of gen particle non-photon matches: " << nGenParticleNonPhotonMatch << endl;
  cout << "Number of no matches                     : " << nNoMatch << endl;
  cout << "Sum of 5 match categories                : " << nFinalStatePhotonMatch+nFinalStateNonPhotonMatch+nGenParticlePhotonMatch+nGenParticleNonPhotonMatch+nNoMatch << endl;
  cout << endl;
  cout << "Number of final state photon hadron mothers     : " << nFinalStatePhotonHadronMother << endl;
  cout << "Number of final state photon FSR                : " << nFinalStatePhotonFSR << endl;
  cout << "Number of final state photon ISR                : " << nFinalStatePhotonISR << endl;
  cout << "Number of final state photon other fragmentation: " << nFinalStatePhotonOtherFragmentation << endl;
  cout << "Number final state photon no matches            : " << nFinalStatePhotonNoMatch << endl;
  cout << "Sum of 5 match types                            : "
       << nFinalStatePhotonHadronMother+nFinalStatePhotonFSR+nFinalStatePhotonISR+nFinalStatePhotonOtherFragmentation+nFinalStatePhotonNoMatch << endl;
  cout << endl;
  cout << "Number of final state non-photon hadron mothers: " << nFinalStateNonPhotonHadronMother << endl;
  cout << "Number of final state non-photon electron pairs: " << nFinalStateNonPhotonElectronPair << endl;
  cout << "Number final state non-photon no matches       : " << nFinalStateNonPhotonNoMatch << endl;
  cout << "Sum of 3 match types                           : " << nFinalStateNonPhotonHadronMother+nFinalStateNonPhotonElectronPair+nFinalStateNonPhotonNoMatch << endl;
  cout << endl;
  cout << "Number of final state photon FSR with DeltaR <= 0.3: " << nFinalStatePhotonFSRDeltaRIn03 << endl;
  cout << "Number of final state photon ISR with DeltaR <= 0.3: " << nFinalStatePhotonISRDeltaRIn03 << endl;
  cout << "Number of final state photon FSR with DeltaR <= 0.7: " << nFinalStatePhotonFSRDeltaRIn07 << endl;
  cout << "Number of final state photon ISR with DeltaR <= 0.7: " << nFinalStatePhotonISRDeltaRIn07 << endl;
  cout << endl;
  cout << "Number of quark fakes  : " << nQuarkFakes << endl;
  cout << "Number of gluon fakes  : " << nGluonFakes << endl;
  cout << "Number of unknown fakes: " << nUnknownFakes << endl;
  cout << "Sum of 3 fake types    : " << nQuarkFakes+nGluonFakes+nUnknownFakes << endl;
  cout << endl;
  cout << "Total number of fake photon matches   : " << nFinalStatePhotonHadronMother+nFinalStatePhotonOtherFragmentation+nFinalStateNonPhotonHadronMother << endl;
  cout << "Total number of real photon matches   : " << nFinalStatePhotonFSR+nFinalStatePhotonISR << endl;
  cout << "Total number of unknown photon matches: "
       << nGenParticlePhotonMatch+nGenParticleNonPhotonMatch+nNoMatch+nFinalStatePhotonNoMatch+nFinalStateNonPhotonNoMatch+nFinalStateNonPhotonElectronPair << endl; 
  cout << endl;

  TString sample = (TString) iMass;
  
  TCanvas *c_pt = new TCanvas("c_pt","",800,600);
  h_numeratorPhotonPt_all->Draw();
  h_numeratorPhotonPt_noMatch->Draw("same");
  h_numeratorPhotonPt_noMatch->SetLineColor(kRed);
  gPad->SetLogy();
  c_pt->SaveAs("pt_comparison_all_vs_noMatches_no_ptCut_sample_"+sample+".png");

  TCanvas *c_deltaR_fs = new TCanvas("c_deltaR_fs","",800,600);
  h_finalState_deltaR->Draw();
  c_deltaR_fs->SaveAs("final_state_match_deltaR_no_ptCut_sample_"+sample+".png");

  TCanvas *c_deltaR_gp = new TCanvas("c_deltaR_gp","",800,600);
  h_genParticle_deltaR->Draw();
  c_deltaR_gp->SaveAs("gen_particle_match_deltaR_no_ptCut_sample_"+sample+".png");
  
} // end Loop method
