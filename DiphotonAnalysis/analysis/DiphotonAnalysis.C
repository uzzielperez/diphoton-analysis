#define DiphotonAnalysis_cxx
#include "DiphotonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DiphotonAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DiphotonAnalysis.C
//      root> DiphotonAnalysis t
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

  // counters
  int nPassTrigger = 0;
  int nPassPtCut = 0;
  int nEBEB = 0;
  int nEBEBAndMinvCut = 0;
  int nEBEBAndMinv500Cut = 0;
  int nEBEEorEEEB = 0;
  int nEBEEorEEEBAndMinvCut = 0;
  int nEBEEorEEEBAndMinv500Cut = 0;

  // histograms
  TH1D* diphotonMinvEBEB = new TH1D("diphotonMinvEBEB","",80,0.,1600.);
  TH1D* diphotonMinvEBEE = new TH1D("diphotonMinvEBEE","",80,0.,1600.);
  diphotonMinvEBEB->Sumw2();
  diphotonMinvEBEE->Sumw2();
  TH1D* photon1PtEBEB = new TH1D("photon1PtEBEB","",80,0.,1600.);
  TH1D* photon1PtEBEE = new TH1D("photon1PtEBEE","",80,0.,1600.);
  photon1PtEBEB->Sumw2();
  photon1PtEBEE->Sumw2();
  TH1D* photon2PtEBEB = new TH1D("photon2PtEBEB","",80,0.,1600.);
  TH1D* photon2PtEBEE = new TH1D("photon2PtEBEE","",80,0.,1600.);
  photon2PtEBEB->Sumw2();
  photon2PtEBEE->Sumw2();
  
  Long64_t nentries = fChain->GetEntriesFast();   
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry % 100000 == 0) std::cout << "Number of entries looped over: " << jentry << std::endl;

    // trigger cut
    if (!TriggerBit_HLT_DoublePhoton60_v1) continue;
    nPassTrigger++;

    // photon pt cut
    if (Photon1_pt < 75.0 || Photon2_pt < 75.0) continue;
    nPassPtCut++;
    
    // EBEB
    if (fabs(Photon1_scEta) < 1.4442 && fabs(Photon2_scEta) < 1.4442) {
      nEBEB++;
      // diphoton minv cut
      if (Diphoton_Minv > 230) {
	nEBEBAndMinvCut++;
	diphotonMinvEBEB->Fill(Diphoton_Minv);
	photon1PtEBEB->Fill(Photon1_pt);
	photon2PtEBEB->Fill(Photon2_pt);
      } // end Minv cut
      if (Diphoton_Minv > 500) {
	nEBEBAndMinv500Cut++;
      }
    } // end EBEB

    // EBEE or EEBE
    if ((fabs(Photon1_scEta) < 1.4442 && 1.566 < fabs(Photon2_scEta) && fabs(Photon2_scEta) < 2.5) ||
	(fabs(Photon2_scEta) < 1.4442 && 1.566 < fabs(Photon1_scEta) && fabs(Photon1_scEta) < 2.5) ) {
      nEBEEorEEEB++;
      if (Diphoton_Minv > 320) {
	nEBEEorEEEBAndMinvCut++;
	diphotonMinvEBEE->Fill(Diphoton_Minv);
	photon1PtEBEE->Fill(Photon1_pt);
	photon2PtEBEE->Fill(Photon2_pt);
      } // end Minv cut
      if (Diphoton_Minv > 500) {
	nEBEEorEEEBAndMinv500Cut++;
      }
    } // end EBEE
    
  } // end for loop over entries

  cout << endl;
  cout << "Total entries             : " << nentries << endl;
  cout << "Pass trigger selection    : " << nPassTrigger << endl;
  cout << " and photon Pt > 75 cut   : " << nPassPtCut << endl;
  cout << "  and in EBEB             : " << nEBEB << endl;
  cout << "   and diphoton minv > 230: " << nEBEBAndMinvCut << endl;
  cout << "   and diphoton minv > 500: " << nEBEBAndMinv500Cut << endl;
  cout << "  and in EBEE or EEEB     : " << nEBEEorEEEB << endl;
  cout << "   and diphoton minv > 320: " << nEBEEorEEEBAndMinvCut << endl;
  cout << "   and diphoton minv > 500: " << nEBEEorEEEBAndMinv500Cut << endl;
  cout << endl;

  TFile file_out("diphoton_histograms.root","RECREATE");

  diphotonMinvEBEB->Write();
  diphotonMinvEBEE->Write();

  photon1PtEBEB->Write();
  photon2PtEBEB->Write();
  photon1PtEBEE->Write();
  photon2PtEBEE->Write();
  
  file_out.ls();
  file_out.Close();
  
} // end Loop()
