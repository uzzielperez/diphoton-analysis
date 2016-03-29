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
   
   vector<TH1D*> sigmaIetaIetaEB_pt20;  
   for (int i = 30; i<140; i=i+20) {
     TH1D *h = new TH1D(Form("sieieEB_realtemplate_pt%dTo%d",i,i+20),"sigmaIetaIetaEB",200,0.,0.1);
     h->Sumw2();
     sigmaIetaIetaEB_pt20.push_back(h);
   }
   vector<TH1D*> sigmaIetaIetaEB_pt50;  
   for (int i = 150; i<300; i=i+50) {
     TH1D *h = new TH1D(Form("sieieEB_realtemplate_pt%dTo%d",i,i+50),"sigmaIetaIetaEB",200,0.,0.1);
     h->Sumw2();
     sigmaIetaIetaEB_pt50.push_back(h);
   }
   // add 300ToInf
   TH1D *sieieEB_realtemplate_pt300ToInf = new TH1D("sieieEB_realtemplate_pt300ToInf","sigmaIetaIetaEB",200,0.,0.1);
   sieieEB_realtemplate_pt300ToInf->Sumw2();

   vector<TH1D*> sigmaIetaIetaEE_pt20;  
   for (int i = 30; i<140; i=i+20) {
     TH1D *h = new TH1D(Form("sieieEE_realtemplate_pt%dTo%d",i,i+20),"sigmaIetaIetaEE",200,0.,0.1);
     h->Sumw2();
     sigmaIetaIetaEE_pt20.push_back(h);
   }
   vector<TH1D*> sigmaIetaIetaEE_pt50;  
   for (int i = 150; i<300; i=i+50) {
     TH1D *h = new TH1D(Form("sieieEE_realtemplate_pt%dTo%d",i,i+50),"sigmaIetaIetaEE",200,0.,0.1);
     h->Sumw2();
     sigmaIetaIetaEE_pt50.push_back(h);
   }
   // add 300ToInf
   TH1D *sieieEE_realtemplate_pt300ToInf = new TH1D("sieieEE_realtemplate_pt300ToInf","sigmaIetaIetaEE",200,0.,0.1);
   sieieEE_realtemplate_pt300ToInf->Sumw2();
   
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry % 100000 == 0)
	std::cout << "Number of entries looped over: " << jentry << std::endl;

      //if (Event_beamHaloIDTight2015) continue;
      if (Photon_sigmaIphiIphi5x5 < 0.009) continue;
      
      // EB
      if (fabs(Photon_scEta) < 1.4442) {
	for (int i = 30; i<140; i=i+20) {
	  if (i < Photon_pt && Photon_pt < i+20) {
	    if (Photon_isNumeratorObjCand && Photon_passChIso) {
	      sigmaIetaIetaEB_pt20[(i-30)/20]->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    }
	  }
	}
	for (int i = 150; i<350; i=i+50) {
	  if ( i == 300 ){ // last catch-all bin
      if (i < Photon_pt && Photon_pt < 14.e3){
        if (Photon_isNumeratorObjCand && Photon_passChIso){
          sieieEB_realtemplate_pt300ToInf->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
        }
      }
    }
    else if (i < 300){
      if (i < Photon_pt && Photon_pt < i+50) {
  	    if (Photon_isNumeratorObjCand && Photon_passChIso) {
  	      sigmaIetaIetaEB_pt50[(i-150)/50]->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
  	    }
  	  }
    }
	}
      } // end EB
      
      // EE
      if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	for (int i = 30; i<140; i=i+20) {
	  if (i < Photon_pt && Photon_pt < i+20) {
	    if (Photon_isNumeratorObjCand && Photon_passChIso) {
	      sigmaIetaIetaEE_pt20[(i-30)/20]->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
	    }
	  }
	}
	for (int i = 150; i<350; i=i+50) {
    if (i == 300){
      if (i < Photon_pt && Photon_pt < 14.e3){
        if (Photon_isNumeratorObjCand && Photon_passChIso){
          sieieEE_realtemplate_pt300ToInf->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
        }
      }
    }
    else if (i < 300){
  	  if (i < Photon_pt && Photon_pt < i+50) {
  	    if (Photon_isNumeratorObjCand && Photon_passChIso) {
  	      sigmaIetaIetaEE_pt50[(i-150)/50]->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
  	    }
  	  }
    }
	}
      } // end EE
      
   } // end loop over entries

   TString filename;
   // if (strcmp(iMass,"all") == 0) filename = "diphoton_fakeRate_GGJets_all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
   // else filename = TString::Format("diphoton_fakeRate_GGJets_M-%s_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root",iMass);
   if (strcmp(iMass,"all") == 0) filename = "diphoton_fakeRate_GGJets_all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms_newbinning.root";
   else filename = TString::Format("diphoton_fakeRate_GGJets_M-%s_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms_newbinning.root",iMass);
   TFile file_out(filename,"RECREATE");

   for (vector<TH1D*>::iterator it = sigmaIetaIetaEB_pt20.begin() ; it != sigmaIetaIetaEB_pt20.end(); ++it) {
     (*it)->Scale(1.0/(*it)->Integral());
     (*it)->Write();
     //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
   }
   for (vector<TH1D*>::iterator it = sigmaIetaIetaEB_pt50.begin() ; it != sigmaIetaIetaEB_pt50.end(); ++it) {
     (*it)->Scale(1.0/(*it)->Integral());
     (*it)->Write();
     //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
   }
   sieieEB_realtemplate_pt300ToInf->Scale(1./sieieEB_realtemplate_pt300ToInf->Integral());
   sieieEB_realtemplate_pt300ToInf->Write();
   for (vector<TH1D*>::iterator it = sigmaIetaIetaEE_pt20.begin() ; it != sigmaIetaIetaEE_pt20.end(); ++it) {
     (*it)->Scale(1.0/(*it)->Integral());
     (*it)->Write();
     //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
   }
   for (vector<TH1D*>::iterator it = sigmaIetaIetaEE_pt50.begin() ; it != sigmaIetaIetaEE_pt50.end(); ++it) {
     (*it)->Scale(1.0/(*it)->Integral());
     (*it)->Write();
     //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
   }
   sieieEE_realtemplate_pt300ToInf->Scale(1./sieieEE_realtemplate_pt300ToInf->Integral());
   sieieEE_realtemplate_pt300ToInf->Write();
   

   file_out.ls();
   file_out.Close();
   
} // end of Loop()
