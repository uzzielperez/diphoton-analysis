#define MCFakeRateAnalysis_cxx
#include "MCFakeRateAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MCFakeRateAnalysis::Loop(const Char_t *iMass)
{
//   In a ROOT session, you can do:
//      root> .L MCFakeRateAnalysis.C
//      root> MCFakeRateAnalysis t
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
  const int nBins = 11;
  
  // define our pT bin increments
  double ptBinArray[nBins] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  
  // define vectors of desired histograms
  vector<TH1D*> sigmaIetaIetaEB;
  vector<TH1D*> sigmaIetaIetaEE;
  
  // loop over bins increments and create histograms
  for (int i = 0; i < nBins-1; i++) {
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];  
    
    TH1D *hEB = new TH1D(Form("sieieEB_realtemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB->Sumw2();
    sigmaIetaIetaEB.push_back(hEB);
    
    TH1D *hEE = new TH1D(Form("sieieEE_realtemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE->Sumw2();
    sigmaIetaIetaEE.push_back(hEE);
  }

  // loop over entries
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry % 100000 == 0)
      std::cout << "Number of entries looped over: " << jentry << std::endl;

    // define our numerator object
    bool isNumeratorObject = Photon_isNumeratorObjCand && Photon_passChIso;

    // reject beam halo
    //if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;
    
    // loop over pT bin increments
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      // use pT bins to cut on photon pT
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {
	// only fill numerator objects
	if (isNumeratorObject) {
	  // EB
	  if (fabs(Photon_scEta) < 1.4442) {
	    sigmaIetaIetaEB.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  } // end EB
	  // EE
	  else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	    sigmaIetaIetaEE.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	  } // end EE
	} // end numerator object
      } // end pt cut
    } // end loop over pt bin increments
    
  } // end loop over entries
  
  TString filename;
  if (strcmp(iMass,"all") == 0) filename = "diphoton_fakeRate_GGJets_all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  else filename = TString::Format("diphoton_fakeRate_GGJets_M-%s_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root",iMass);
  TFile file_out(filename,"RECREATE");

  // write our histograms to file
  for (vector<TH1D*>::iterator it = sigmaIetaIetaEB.begin() ; it != sigmaIetaIetaEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Scale(1.0/(*it)->Integral());
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sigmaIetaIetaEE.begin() ; it != sigmaIetaIetaEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Scale(1.0/(*it)->Integral());
    (*it)->Write();
  }
  
  file_out.ls();
  file_out.Close();
   
} // end of Loop()
