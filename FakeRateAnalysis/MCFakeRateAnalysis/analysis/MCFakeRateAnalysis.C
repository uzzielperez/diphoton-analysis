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
  TH1D* jetPhoDrEB_realtemplate = new TH1D("jetPhoDrEB_realtemplate","jetPhoDrEB_realtemplate",200,0.,1.);
  TH1D* jetPhoDrEE_realtemplate = new TH1D("jetPhoDrEE_realtemplate","jetPhoDrEE_realtemplate",200,0.,1.);

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

    // evaluate jet trigger groupings
    // bool singleJetFired = TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3==1 || TriggerBit_HLT_AK8PFJet360_TrimMass30_v3==1 || TriggerBit_HLT_CaloJet500_NoJetID_v2==1 || TriggerBit_HLT_DiCaloJetAve140_v1==1 || TriggerBit_HLT_DiCaloJetAve200_v1==1 || TriggerBit_HLT_DiCaloJetAve260_v1==1 || TriggerBit_HLT_DiCaloJetAve320_v1==1 || TriggerBit_HLT_DiCaloJetAve400_v1==1 || TriggerBit_HLT_DiCaloJetAve40_v1==1 || TriggerBit_HLT_DiCaloJetAve500_v1==1 || TriggerBit_HLT_DiCaloJetAve60_v1==1 || TriggerBit_HLT_DiCaloJetAve80_v1==1 || TriggerBit_HLT_DiPFJetAve100_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve140_v2==1 || TriggerBit_HLT_DiPFJetAve160_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve200_v2==1 || TriggerBit_HLT_DiPFJetAve220_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve260_v2==1 || TriggerBit_HLT_DiPFJetAve300_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve30_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve320_v2==1 || TriggerBit_HLT_DiPFJetAve400_v2==1 || TriggerBit_HLT_DiPFJetAve40_v2==1 || TriggerBit_HLT_DiPFJetAve500_v2==1 || TriggerBit_HLT_DiPFJetAve60_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve60_v2==1 || TriggerBit_HLT_DiPFJetAve80_HFJEC_v3==1 || TriggerBit_HLT_DiPFJetAve80_v2==1 || TriggerBit_HLT_PFJet140_v4==1 || TriggerBit_HLT_PFJet200_v4==1 || TriggerBit_HLT_PFJet260_v4==1 || TriggerBit_HLT_PFJet320_v4==1 || TriggerBit_HLT_PFJet400_v4==1 || TriggerBit_HLT_PFJet40_v4==1 || TriggerBit_HLT_PFJet450_v4==1 || TriggerBit_HLT_PFJet500_v4==1 || TriggerBit_HLT_PFJet60_v4==1 || TriggerBit_HLT_PFJet80_v4==1;

    // bool htFired = TriggerBit_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2==1 || TriggerBit_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2==1 || TriggerBit_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3==1 || TriggerBit_HLT_HT2000_v1==1 || TriggerBit_HLT_HT200_v1==1 || TriggerBit_HLT_HT2500_v1==1 || TriggerBit_HLT_HT275_v1==1 || TriggerBit_HLT_HT325_v1==1 || TriggerBit_HLT_HT425_v1==1 || TriggerBit_HLT_HT575_v1==1 || TriggerBit_HLT_L1_TripleJet_VBF_v4==1 || TriggerBit_HLT_PFHT200_v2==1 || TriggerBit_HLT_PFHT250_v2==1 || TriggerBit_HLT_PFHT300_v2==1 || TriggerBit_HLT_PFHT350_v3==1 || TriggerBit_HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3==1 || TriggerBit_HLT_PFHT400_SixJet30_v3==1 || TriggerBit_HLT_PFHT400_v2==1 || TriggerBit_HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3==1 || TriggerBit_HLT_PFHT450_SixJet40_v3==1 || TriggerBit_HLT_PFHT475_v2==1 || TriggerBit_HLT_PFHT550_4JetPt50_v1==1 || TriggerBit_HLT_PFHT600_v3==1 || TriggerBit_HLT_PFHT650_4JetPt50_v1==1 || TriggerBit_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3==1 || TriggerBit_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3==1 || TriggerBit_HLT_PFHT650_v3==1 || TriggerBit_HLT_PFHT750_4JetPt50_v3==1 || TriggerBit_HLT_PFHT800_v2==1 || TriggerBit_HLT_QuadPFJet_VBF_v4==1;

    // bool PFJet80Fired = TriggerBit_HLT_PFJet80_v4 == 1;
    // bool PFJet400Fired = TriggerBit_HLT_PFJet400_v4 == 1;

    // if (!PFJet400Fired) continue;

    TLorentzVector photon;
    TLorentzVector leadingJet;
    TLorentzVector secondleadingJet;
    TLorentzVector thirdleadingJet;

    double photonLeadingJetDr = -1.;
    bool matched = false;

    if (Jet_nJets >= 2){

      photon.SetPtEtaPhiM(Photon_pt,Photon_scEta,Photon_scPhi,0.);
      leadingJet.SetPtEtaPhiM(Jet_leadingJetPt,Jet_leadingJetEta,Jet_leadingJetPhi,Jet_leadingJetMass);
      secondleadingJet.SetPtEtaPhiM(Jet_secondleadingJetPt,Jet_secondleadingJetEta,Jet_secondleadingJetPhi,Jet_secondleadingJetMass);
      // thirdleadingJet.SetPtEtaPhiM(Jet_thirdleadingJetPt,Jet_thirdleadingJetEta,Jet_thirdleadingJetPhi,Jet_thirdleadingJetMass);

      photonLeadingJetDr = photon.DeltaR(leadingJet);
      double photonSecondLeadingJetDr = photon.DeltaR(secondleadingJet);
      // double photonThirdLeadingJetDr = photon.DeltaR(thirdleadingJet);

      double dRCut = 0.6;
      // these will all work because the jet 4 vectors are filled with dummy information, but I'll only use them if they are real jets
      bool matchedToLeadingJet = (photonLeadingJetDr < dRCut);
      bool matchedToSecondLeadingJet = (photonSecondLeadingJetDr < dRCut);
      // bool matchedToThirdLeadingJet = (photonThirdLeadingJetDr < dRCut);

      matched = matchedToSecondLeadingJet;

    }
    
    if (matched) continue;
    
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
  if (strcmp(iMass,"all") == 0) filename = "GGJets_M-200To500_NOTmatchedtosecondleadingjet.root";
  else filename = TString::Format("GGJets_M-%s_NOTmatchedtosecondleadingjet.root",iMass);
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
  jetPhoDrEB_realtemplate->Write();
  jetPhoDrEE_realtemplate->Write();
  
  file_out.ls();
  file_out.Close();
   
} // end of Loop()
