#define FakeRateAnalysis_cxx
#include "FakeRateAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void FakeRateAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L FakeRateAnalysis.C
//      root> FakeRateAnalysis t
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

   // book histograms

   // pt spectrum of all photon objects
   TH1D phoPtEB("phoPtEB","",5000,0,5000);
   TH1D phoPtEE("phoPtEE","",5000,0,5000);

   // pt spectrum of denominator objects;
   TH1D phoPtEB_denominator("phoPtEB_denominator","",5000,0,5000);
   TH1D phoPtEE_denominator("phoPtEE_denominator","",5000,0,5000);

   // pt spectrum of all objects passing fake template criteria
   TH1D phoPtEB_faketemplate("TH1D phoptEB_faketemplate","",5000,0,5000);
   TH1D phoPtEE_faketemplate("TH1D phoptEE_faketemplate","",5000,0,5000);

   // template histograms
   std::vector<TH1D*> fakeTemplHistVec;
   double ptBinArray[11] = { 20., 40., 60., 80., 100., 120., 200., 300., 400., 600., 14.e3 };

   TH1D* sieieEB_faketemplate_pt20To40 = new TH1D("sieieEB_faketemplate_pt20To40","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt20To40);
   TH1D* sieieEB_faketemplate_pt40To60 = new TH1D("sieieEB_faketemplate_pt40To60","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt40To60);
   TH1D* sieieEB_faketemplate_pt60To80 = new TH1D("sieieEB_faketemplate_pt60To80","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt60To80);
   TH1D* sieieEB_faketemplate_pt80To100 = new TH1D("sieieEB_faketemplate_pt80To100","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt80To100);
   TH1D* sieieEB_faketemplate_pt100To120 = new TH1D("sieieEB_faketemplate_pt100To120","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt100To120);
   TH1D* sieieEB_faketemplate_pt120To200 = new TH1D("sieieEB_faketemplate_pt120To200","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt120To200);
   TH1D* sieieEB_faketemplate_pt200To300 = new TH1D("sieieEB_faketemplate_pt200To300","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt200To300);
   TH1D* sieieEB_faketemplate_pt300To400 = new TH1D("sieieEB_faketemplate_pt300To400","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt300To400);
   TH1D* sieieEB_faketemplate_pt400To600 = new TH1D("sieieEB_faketemplate_pt400To600","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt400To600);
   TH1D* sieieEB_faketemplate_pt600ToInf = new TH1D("sieieEB_faketemplate_pt600ToInf","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt600ToInf);
   TH1D* sieieEE_faketemplate_pt20To40 = new TH1D("sieieEE_faketemplate_pt20To40","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt20To40);
   TH1D* sieieEE_faketemplate_pt40To60 = new TH1D("sieieEE_faketemplate_pt40To60","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt40To60);
   TH1D* sieieEE_faketemplate_pt60To80 = new TH1D("sieieEE_faketemplate_pt60To80","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt60To80);
   TH1D* sieieEE_faketemplate_pt80To100 = new TH1D("sieieEE_faketemplate_pt80To100","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt80To100);
   TH1D* sieieEE_faketemplate_pt100To120 = new TH1D("sieieEE_faketemplate_pt100To120","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt100To120);
   TH1D* sieieEE_faketemplate_pt120To200 = new TH1D("sieieEE_faketemplate_pt120To200","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt120To200);
   TH1D* sieieEE_faketemplate_pt200To300 = new TH1D("sieieEE_faketemplate_pt200To300","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt200To300);
   TH1D* sieieEE_faketemplate_pt300To400 = new TH1D("sieieEE_faketemplate_pt300To400","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt300To400);
   TH1D* sieieEE_faketemplate_pt400To600 = new TH1D("sieieEE_faketemplate_pt400To600","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt400To600);
   TH1D* sieieEE_faketemplate_pt600ToInf = new TH1D("sieieEE_faketemplate_pt600ToInf","",100,0.,0.5);
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt600ToInf);
   
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry % 100000 == 0)
	std::cout << "Number of entries looped over: " << jentry << std::endl;

      // plot fake templates
      bool inChIsoSideband = (10. < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < 15.); //maybe add in sideband at runtime in the future?

      if (fabs(Photon_scEta) < 1.4442) {
         phoPtEB.Fill( Photon_pt );
         if (Photon_isDenominatorObj) phoPtEB_denominator.Fill(Photon_pt);
         if (Photon_isFakeTemplateObjCand && inChIsoSideband) phoPtEB_faketemplate.Fill(Photon_pt);
      }

      else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
         phoPtEE.Fill( Photon_pt );
         if (Photon_isDenominatorObj) phoPtEE_denominator.Fill(Photon_pt);
         if (Photon_isFakeTemplateObjCand && inChIsoSideband) phoPtEE_faketemplate.Fill(Photon_pt);
      }

      // fake template phoPt spectrum

      //loop over pt bin low edges (also equal to or half of hist vector entry numbers)
      for (int i = 0; i<10; i++){
         double binLowEdge = ptBinArray[i];
         double binUpperEdge = ptBinArray[i+1];

         if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && Photon_isFakeTemplateObjCand && inChIsoSideband ){

            if (fabs(Photon_scEta) < 1.4442) fakeTemplHistVec.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) fakeTemplHistVec.at(i+10)->Fill( Photon_sigmaIetaIeta5x5 );

         }

      } // end loop over pt bins for fake template
   } // end loop over entries

   TFile file_out("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","RECREATE");

   // sigmaIetaIetaEB->Write();
   // sigmaIetaIetaEE->Write();
   file_out.cd();
   phoPtEB.Write();
   phoPtEE.Write();
   phoPtEB_denominator.Write();
   phoPtEE_denominator.Write();
   phoPtEB_faketemplate.Write();
   phoPtEE_faketemplate.Write();
   sieieEB_faketemplate_pt20To40->Write();
   sieieEB_faketemplate_pt40To60->Write();
   sieieEB_faketemplate_pt60To80->Write();
   sieieEB_faketemplate_pt80To100->Write();
   sieieEB_faketemplate_pt100To120->Write();
   sieieEB_faketemplate_pt120To200->Write();
   sieieEB_faketemplate_pt200To300->Write();
   sieieEB_faketemplate_pt300To400->Write();
   sieieEB_faketemplate_pt400To600->Write();
   sieieEB_faketemplate_pt600ToInf->Write();
   sieieEE_faketemplate_pt20To40->Write();
   sieieEE_faketemplate_pt40To60->Write();
   sieieEE_faketemplate_pt60To80->Write();
   sieieEE_faketemplate_pt80To100->Write();
   sieieEE_faketemplate_pt100To120->Write();
   sieieEE_faketemplate_pt120To200->Write();
   sieieEE_faketemplate_pt200To300->Write();
   sieieEE_faketemplate_pt300To400->Write();
   sieieEE_faketemplate_pt400To600->Write();
   sieieEE_faketemplate_pt600ToInf->Write();
   
   file_out.ls();
   file_out.Close();
   
} // end Loop()
