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

   double ptBinArray[17] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 350., 400., 450., 500., 550., 600., 14.e3 };

   // pt spectrum of all photon objects
   TH1D phoPtEB("phoPtEB","",16,ptBinArray);
   TH1D phoPtEE("phoPtEE","",16,ptBinArray);

   TH1D phoPtEB_numerator("phoPtEB_numerator","",16,ptBinArray);
   TH1D phoPtEE_numerator("phoPtEE_numerator","",16,ptBinArray);

   // pt spectrum of denominator objects;
   TH1D phoPtEB_denominator("phoPtEB_denominator","",16,ptBinArray);
   TH1D phoPtEE_denominator("phoPtEE_denominator","",16,ptBinArray);

   // pt spectrum of all objects passing fake template criteria
   TH1D phoPtEB_faketemplate("phoptEB_faketemplate","",16,ptBinArray);
   TH1D phoPtEE_faketemplate("phoptEE_faketemplate","",16,ptBinArray);

   phoPtEB.Sumw2();
   phoPtEE.Sumw2();
   phoPtEB_numerator.Sumw2();
   phoPtEE_numerator.Sumw2();
   phoPtEB_denominator.Sumw2();
   phoPtEE_denominator.Sumw2();
   phoPtEB_faketemplate.Sumw2();
   phoPtEE_faketemplate.Sumw2();

   // template histograms
   std::vector<TH1D*> fakeTemplHistVec;

   TH1D* sieieEB_faketemplate_pt30To50 = new TH1D("sieieEB_faketemplate_pt30To50","",1000,0.,0.5);
   sieieEB_faketemplate_pt30To50->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt30To50);
   TH1D* sieieEB_faketemplate_pt50To70 = new TH1D("sieieEB_faketemplate_pt50To70","",1000,0.,0.5);
   sieieEB_faketemplate_pt50To70->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt50To70);
   TH1D* sieieEB_faketemplate_pt70To90 = new TH1D("sieieEB_faketemplate_pt70To90","",1000,0.,0.5);
   sieieEB_faketemplate_pt70To90->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt70To90);
   TH1D* sieieEB_faketemplate_pt90To110 = new TH1D("sieieEB_faketemplate_pt90To110","",1000,0.,0.5);
   sieieEB_faketemplate_pt90To110->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt90To110);
   TH1D* sieieEB_faketemplate_pt110To130 = new TH1D("sieieEB_faketemplate_pt110To130","",1000,0.,0.5);
   sieieEB_faketemplate_pt110To130->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt110To130);
   TH1D* sieieEB_faketemplate_pt130To150 = new TH1D("sieieEB_faketemplate_pt130To150","",1000,0.,0.5);
   sieieEB_faketemplate_pt130To150->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt130To150);
   TH1D* sieieEB_faketemplate_pt150To200 = new TH1D("sieieEB_faketemplate_pt150To200","",1000,0.,0.5);
   sieieEB_faketemplate_pt150To200->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt150To200);
   TH1D* sieieEB_faketemplate_pt200To250 = new TH1D("sieieEB_faketemplate_pt200To250","",1000,0.,0.5);
   sieieEB_faketemplate_pt200To250->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt200To250);
   TH1D* sieieEB_faketemplate_pt250To300 = new TH1D("sieieEB_faketemplate_pt250To300","",1000,0.,0.5);
   sieieEB_faketemplate_pt250To300->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt250To300);
   TH1D* sieieEB_faketemplate_pt300To350 = new TH1D("sieieEB_faketemplate_pt300To350","",1000,0.,0.5);
   sieieEB_faketemplate_pt300To350->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt300To350);
   TH1D* sieieEB_faketemplate_pt350To400 = new TH1D("sieieEB_faketemplate_pt350To400","",1000,0.,0.5);
   sieieEB_faketemplate_pt350To400->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt350To400);
   TH1D* sieieEB_faketemplate_pt400To450 = new TH1D("sieieEB_faketemplate_pt400To450","",1000,0.,0.5);
   sieieEB_faketemplate_pt400To450->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt400To450);
   TH1D* sieieEB_faketemplate_pt450To500 = new TH1D("sieieEB_faketemplate_pt450To500","",1000,0.,0.5);
   sieieEB_faketemplate_pt450To500->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt450To500);
   TH1D* sieieEB_faketemplate_pt500To550 = new TH1D("sieieEB_faketemplate_pt500To550","",1000,0.,0.5);
   sieieEB_faketemplate_pt500To550->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt500To550);
   TH1D* sieieEB_faketemplate_pt550To600 = new TH1D("sieieEB_faketemplate_pt550To600","",1000,0.,0.5);
   sieieEB_faketemplate_pt550To600->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt550To600);
   TH1D* sieieEB_faketemplate_pt600ToInf = new TH1D("sieieEB_faketemplate_pt600ToInf","",1000,0.,0.5);
   sieieEB_faketemplate_pt600ToInf->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt600ToInf);
   TH1D* sieieEE_faketemplate_pt30To50 = new TH1D("sieieEE_faketemplate_pt30To50","",1000,0.,0.5);
   sieieEE_faketemplate_pt30To50->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt30To50);
   TH1D* sieieEE_faketemplate_pt50To70 = new TH1D("sieieEE_faketemplate_pt50To70","",1000,0.,0.5);
   sieieEE_faketemplate_pt50To70->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt50To70);
   TH1D* sieieEE_faketemplate_pt70To90 = new TH1D("sieieEE_faketemplate_pt70To90","",1000,0.,0.5);
   sieieEE_faketemplate_pt70To90->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt70To90);
   TH1D* sieieEE_faketemplate_pt90To110 = new TH1D("sieieEE_faketemplate_pt90To110","",1000,0.,0.5);
   sieieEE_faketemplate_pt90To110->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt90To110);
   TH1D* sieieEE_faketemplate_pt110To130 = new TH1D("sieieEE_faketemplate_pt110To130","",1000,0.,0.5);
   sieieEE_faketemplate_pt110To130->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt110To130);
   TH1D* sieieEE_faketemplate_pt130To150 = new TH1D("sieieEE_faketemplate_pt130To150","",1000,0.,0.5);
   sieieEE_faketemplate_pt130To150->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt130To150);
   TH1D* sieieEE_faketemplate_pt150To200 = new TH1D("sieieEE_faketemplate_pt150To200","",1000,0.,0.5);
   sieieEE_faketemplate_pt150To200->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt150To200);
   TH1D* sieieEE_faketemplate_pt200To250 = new TH1D("sieieEE_faketemplate_pt200To250","",1000,0.,0.5);
   sieieEE_faketemplate_pt200To250->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt200To250);
   TH1D* sieieEE_faketemplate_pt250To300 = new TH1D("sieieEE_faketemplate_pt250To300","",1000,0.,0.5);
   sieieEE_faketemplate_pt250To300->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt250To300);
   TH1D* sieieEE_faketemplate_pt300To350 = new TH1D("sieieEE_faketemplate_pt300To350","",1000,0.,0.5);
   sieieEE_faketemplate_pt300To350->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt300To350);
   TH1D* sieieEE_faketemplate_pt350To400 = new TH1D("sieieEE_faketemplate_pt350To400","",1000,0.,0.5);
   sieieEE_faketemplate_pt350To400->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt350To400);
   TH1D* sieieEE_faketemplate_pt400To450 = new TH1D("sieieEE_faketemplate_pt400To450","",1000,0.,0.5);
   sieieEE_faketemplate_pt400To450->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt400To450);
   TH1D* sieieEE_faketemplate_pt450To500 = new TH1D("sieieEE_faketemplate_pt450To500","",1000,0.,0.5);
   sieieEE_faketemplate_pt450To500->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt450To500);
   TH1D* sieieEE_faketemplate_pt500To550 = new TH1D("sieieEE_faketemplate_pt500To550","",1000,0.,0.5);
   sieieEE_faketemplate_pt500To550->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt500To550);
   TH1D* sieieEE_faketemplate_pt550To600 = new TH1D("sieieEE_faketemplate_pt550To600","",1000,0.,0.5);
   sieieEE_faketemplate_pt550To600->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt550To600);
   TH1D* sieieEE_faketemplate_pt600ToInf = new TH1D("sieieEE_faketemplate_pt600ToInf","",1000,0.,0.5);
   sieieEE_faketemplate_pt600ToInf->Sumw2();
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
         if (Photon_isNumeratorObj) phoPtEB_numerator.Fill(Photon_pt);
         if (Photon_isDenominatorObj) phoPtEB_denominator.Fill(Photon_pt);
         if (Photon_isFakeTemplateObjCand && inChIsoSideband) phoPtEB_faketemplate.Fill(Photon_pt);
      }

      else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
         phoPtEE.Fill( Photon_pt );
         if (Photon_isNumeratorObj) phoPtEE_numerator.Fill(Photon_pt);
         if (Photon_isDenominatorObj) phoPtEE_denominator.Fill(Photon_pt);
         if (Photon_isFakeTemplateObjCand && inChIsoSideband) phoPtEE_faketemplate.Fill(Photon_pt);
      }

      // fake template phoPt spectrum

      //loop over pt bin low edges (also equal to or half of hist vector entry numbers)
      for (int i = 0; i<16; i++){
         double binLowEdge = ptBinArray[i];
         double binUpperEdge = ptBinArray[i+1];

         if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && Photon_isFakeTemplateObjCand && inChIsoSideband ){

            if (fabs(Photon_scEta) < 1.4442) fakeTemplHistVec.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) fakeTemplHistVec.at(i+16)->Fill( Photon_sigmaIetaIeta5x5 );

         }

      } // end loop over pt bins for fake template
   } // end loop over entries

   // scale fake templates

   sieieEB_faketemplate_pt30To50->Scale(1./sieieEB_faketemplate_pt30To50->Integral());
   sieieEB_faketemplate_pt50To70->Scale(1./sieieEB_faketemplate_pt50To70->Integral());
   sieieEB_faketemplate_pt70To90->Scale(1./sieieEB_faketemplate_pt70To90->Integral());
   sieieEB_faketemplate_pt90To110->Scale(1./sieieEB_faketemplate_pt90To110->Integral());
   sieieEB_faketemplate_pt110To130->Scale(1./sieieEB_faketemplate_pt110To130->Integral());
   sieieEB_faketemplate_pt130To150->Scale(1./sieieEB_faketemplate_pt130To150->Integral());
   sieieEB_faketemplate_pt150To200->Scale(1./sieieEB_faketemplate_pt150To200->Integral());
   sieieEB_faketemplate_pt200To250->Scale(1./sieieEB_faketemplate_pt200To250->Integral());
   sieieEB_faketemplate_pt250To300->Scale(1./sieieEB_faketemplate_pt250To300->Integral());
   sieieEB_faketemplate_pt300To350->Scale(1./sieieEB_faketemplate_pt300To350->Integral());
   sieieEB_faketemplate_pt350To400->Scale(1./sieieEB_faketemplate_pt350To400->Integral());
   sieieEB_faketemplate_pt400To450->Scale(1./sieieEB_faketemplate_pt400To450->Integral());
   sieieEB_faketemplate_pt450To500->Scale(1./sieieEB_faketemplate_pt450To500->Integral());
   sieieEB_faketemplate_pt500To550->Scale(1./sieieEB_faketemplate_pt500To550->Integral());
   sieieEB_faketemplate_pt550To600->Scale(1./sieieEB_faketemplate_pt550To600->Integral());
   sieieEB_faketemplate_pt600ToInf->Scale(1./sieieEB_faketemplate_pt600ToInf->Integral());
   sieieEE_faketemplate_pt30To50->Scale(1./sieieEE_faketemplate_pt30To50->Integral());
   sieieEE_faketemplate_pt50To70->Scale(1./sieieEE_faketemplate_pt50To70->Integral());
   sieieEE_faketemplate_pt70To90->Scale(1./sieieEE_faketemplate_pt70To90->Integral());
   sieieEE_faketemplate_pt90To110->Scale(1./sieieEE_faketemplate_pt90To110->Integral());
   sieieEE_faketemplate_pt110To130->Scale(1./sieieEE_faketemplate_pt110To130->Integral());
   sieieEE_faketemplate_pt130To150->Scale(1./sieieEE_faketemplate_pt130To150->Integral());
   sieieEE_faketemplate_pt150To200->Scale(1./sieieEE_faketemplate_pt150To200->Integral());
   sieieEE_faketemplate_pt200To250->Scale(1./sieieEE_faketemplate_pt200To250->Integral());
   sieieEE_faketemplate_pt250To300->Scale(1./sieieEE_faketemplate_pt250To300->Integral());
   sieieEE_faketemplate_pt300To350->Scale(1./sieieEE_faketemplate_pt300To350->Integral());
   sieieEE_faketemplate_pt350To400->Scale(1./sieieEE_faketemplate_pt350To400->Integral());
   sieieEE_faketemplate_pt400To450->Scale(1./sieieEE_faketemplate_pt400To450->Integral());
   sieieEE_faketemplate_pt450To500->Scale(1./sieieEE_faketemplate_pt450To500->Integral());
   sieieEE_faketemplate_pt500To550->Scale(1./sieieEE_faketemplate_pt500To550->Integral());
   sieieEE_faketemplate_pt550To600->Scale(1./sieieEE_faketemplate_pt550To600->Integral());
   sieieEE_faketemplate_pt600ToInf->Scale(1./sieieEE_faketemplate_pt600ToInf->Integral());

   // write histograms out to root files

   TFile file_out("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","RECREATE");

   // sigmaIetaIetaEB->Write();
   // sigmaIetaIetaEE->Write();
   file_out.cd();
   phoPtEB.Write();
   phoPtEE.Write();
   phoPtEB_numerator.Write();
   phoPtEE_numerator.Write();
   phoPtEB_denominator.Write();
   phoPtEE_denominator.Write();
   phoPtEB_faketemplate.Write();
   phoPtEE_faketemplate.Write();
   sieieEB_faketemplate_pt30To50->Write();
   sieieEB_faketemplate_pt50To70->Write();
   sieieEB_faketemplate_pt70To90->Write();
   sieieEB_faketemplate_pt90To110->Write();
   sieieEB_faketemplate_pt110To130->Write();
   sieieEB_faketemplate_pt130To150->Write();
   sieieEB_faketemplate_pt150To200->Write();
   sieieEB_faketemplate_pt200To250->Write();
   sieieEB_faketemplate_pt250To300->Write();
   sieieEB_faketemplate_pt300To350->Write();
   sieieEB_faketemplate_pt350To400->Write();
   sieieEB_faketemplate_pt400To450->Write();
   sieieEB_faketemplate_pt450To500->Write();
   sieieEB_faketemplate_pt500To550->Write();
   sieieEB_faketemplate_pt550To600->Write();
   sieieEB_faketemplate_pt600ToInf->Write();
   sieieEE_faketemplate_pt30To50->Write();
   sieieEE_faketemplate_pt50To70->Write();
   sieieEE_faketemplate_pt70To90->Write();
   sieieEE_faketemplate_pt90To110->Write();
   sieieEE_faketemplate_pt110To130->Write();
   sieieEE_faketemplate_pt130To150->Write();
   sieieEE_faketemplate_pt150To200->Write();
   sieieEE_faketemplate_pt200To250->Write();
   sieieEE_faketemplate_pt250To300->Write();
   sieieEE_faketemplate_pt300To350->Write();
   sieieEE_faketemplate_pt350To400->Write();
   sieieEE_faketemplate_pt400To450->Write();
   sieieEE_faketemplate_pt450To500->Write();
   sieieEE_faketemplate_pt500To550->Write();
   sieieEE_faketemplate_pt550To600->Write();
   sieieEE_faketemplate_pt600ToInf->Write();
   
   file_out.ls();
   file_out.Close();
   
} // end Loop()
