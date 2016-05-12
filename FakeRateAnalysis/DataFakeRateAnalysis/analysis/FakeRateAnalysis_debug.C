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

   // double ptBinArray[17] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 350., 400., 450., 500., 550., 600., 14.e3 };
   double ptBinArray[11] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

   // pt spectrum of all photon objects
   TH1D phoPtEB("phoPtEB","",1000,0.,2500.);
   TH1D phoPtEE("phoPtEE","",1000,0.,2500.);

   // pt spectrum of all numerator objects
   TH1D phoPtEB_numerator("phoPtEB_numerator","",1000,0.,2500.);
   TH1D phoPtEE_numerator("phoPtEE_numerator","",1000,0.,2500.);
   TH1D phoPtEB_numerator_varbin("phoPtEB_numerator_varbin","",10,ptBinArray);
   TH1D phoPtEE_numerator_varbin("phoPtEE_numerator_varbin","",10,ptBinArray);

   // pt spectrum of denominator objects
   TH1D phoPtEB_denominator("phoPtEB_denominator","",1000,0.,2500.);
   TH1D phoPtEE_denominator("phoPtEE_denominator","",1000,0.,2500.);
   TH1D phoPtEB_denominator_varbin("phoPtEB_denominator_varbin","",10,ptBinArray);
   TH1D phoPtEE_denominator_varbin("phoPtEE_denominator_varbin","",10,ptBinArray);

   // pt spectrum of all objects passing fake template criteria
   TH1D phoPtEB_faketemplate("phoPtEB_faketemplate","",1000,0.,2500.);
   TH1D phoPtEE_faketemplate("phoPtEE_faketemplate","",1000,0.,2500.);
   TH1D phoPtEB_faketemplate_varbin("phoPtEB_faketemplate_varbin","",10,ptBinArray);
   TH1D phoPtEE_faketemplate_varbin("phoPtEE_faketemplate_varbin","",10,ptBinArray);

   phoPtEB.Sumw2();
   phoPtEE.Sumw2();
   phoPtEB_numerator_varbin.Sumw2();
   phoPtEE_numerator_varbin.Sumw2();
   phoPtEB_denominator_varbin.Sumw2();
   phoPtEE_denominator_varbin.Sumw2();
   phoPtEB_faketemplate_varbin.Sumw2();
   phoPtEE_faketemplate_varbin.Sumw2();

   // numerator and template histograms
   std::vector<TH1D*> fakeTemplHistVec;
   std::vector<TH1D*> numeratorHistVec;

   TH1D* sieieEB_faketemplate_pt30To50 = new TH1D("sieieEB_faketemplate_pt30To50","",200,0.,0.1);
   sieieEB_faketemplate_pt30To50->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt30To50);
   TH1D* sieieEB_numerator_pt30To50 = new TH1D("sieieEB_numerator_pt30To50","",200,0.,0.1);
   sieieEB_numerator_pt30To50->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt30To50);
   TH1D* sieieEB_faketemplate_pt50To70 = new TH1D("sieieEB_faketemplate_pt50To70","",200,0.,0.1);
   sieieEB_faketemplate_pt50To70->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt50To70);
   TH1D* sieieEB_numerator_pt50To70 = new TH1D("sieieEB_numerator_pt50To70","",200,0.,0.1);
   sieieEB_numerator_pt50To70->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt50To70);
   TH1D* sieieEB_faketemplate_pt70To90 = new TH1D("sieieEB_faketemplate_pt70To90","",200,0.,0.1);
   sieieEB_faketemplate_pt70To90->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt70To90);
   TH1D* sieieEB_numerator_pt70To90 = new TH1D("sieieEB_numerator_pt70To90","",200,0.,0.1);
   sieieEB_numerator_pt70To90->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt70To90);
   TH1D* sieieEB_faketemplate_pt90To110 = new TH1D("sieieEB_faketemplate_pt90To110","",200,0.,0.1);
   sieieEB_faketemplate_pt90To110->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt90To110);
   TH1D* sieieEB_numerator_pt90To110 = new TH1D("sieieEB_numerator_pt90To110","",200,0.,0.1);
   sieieEB_numerator_pt90To110->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt90To110);
   TH1D* sieieEB_faketemplate_pt110To130 = new TH1D("sieieEB_faketemplate_pt110To130","",200,0.,0.1);
   sieieEB_faketemplate_pt110To130->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt110To130);
   TH1D* sieieEB_numerator_pt110To130 = new TH1D("sieieEB_numerator_pt110To130","",200,0.,0.1);
   sieieEB_numerator_pt110To130->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt110To130);
   TH1D* sieieEB_faketemplate_pt130To150 = new TH1D("sieieEB_faketemplate_pt130To150","",200,0.,0.1);
   sieieEB_faketemplate_pt130To150->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt130To150);
   TH1D* sieieEB_numerator_pt130To150 = new TH1D("sieieEB_numerator_pt130To150","",200,0.,0.1);
   sieieEB_numerator_pt130To150->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt130To150);
   TH1D* sieieEB_faketemplate_pt150To200 = new TH1D("sieieEB_faketemplate_pt150To200","",200,0.,0.1);
   sieieEB_faketemplate_pt150To200->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt150To200);
   TH1D* sieieEB_numerator_pt150To200 = new TH1D("sieieEB_numerator_pt150To200","",200,0.,0.1);
   sieieEB_numerator_pt150To200->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt150To200);
   TH1D* sieieEB_faketemplate_pt200To250 = new TH1D("sieieEB_faketemplate_pt200To250","",200,0.,0.1);
   sieieEB_faketemplate_pt200To250->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt200To250);
   TH1D* sieieEB_numerator_pt200To250 = new TH1D("sieieEB_numerator_pt200To250","",200,0.,0.1);
   sieieEB_numerator_pt200To250->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt200To250);
   TH1D* sieieEB_faketemplate_pt250To300 = new TH1D("sieieEB_faketemplate_pt250To300","",200,0.,0.1);
   sieieEB_faketemplate_pt250To300->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt250To300);
   TH1D* sieieEB_numerator_pt250To300 = new TH1D("sieieEB_numerator_pt250To300","",200,0.,0.1);
   sieieEB_numerator_pt250To300->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt250To300);
   TH1D* sieieEB_faketemplate_pt300ToInf = new TH1D("sieieEB_faketemplate_pt300ToInf","",200,0.,0.1);
   sieieEB_faketemplate_pt300ToInf->Sumw2();
   fakeTemplHistVec.push_back(sieieEB_faketemplate_pt300ToInf);
   TH1D* sieieEB_numerator_pt300ToInf = new TH1D("sieieEB_numerator_pt300ToInf","",200,0.,0.1);
   sieieEB_numerator_pt300ToInf->Sumw2();
   numeratorHistVec.push_back(sieieEB_numerator_pt300ToInf);
   TH1D* sieieEE_faketemplate_pt30To50 = new TH1D("sieieEE_faketemplate_pt30To50","",200,0.,0.1);
   sieieEE_faketemplate_pt30To50->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt30To50);
   TH1D* sieieEE_numerator_pt30To50 = new TH1D("sieieEE_numerator_pt30To50","",200,0.,0.1);
   sieieEE_numerator_pt30To50->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt30To50);
   TH1D* sieieEE_faketemplate_pt50To70 = new TH1D("sieieEE_faketemplate_pt50To70","",200,0.,0.1);
   sieieEE_faketemplate_pt50To70->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt50To70);
   TH1D* sieieEE_numerator_pt50To70 = new TH1D("sieieEE_numerator_pt50To70","",200,0.,0.1);
   sieieEE_numerator_pt50To70->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt50To70);
   TH1D* sieieEE_faketemplate_pt70To90 = new TH1D("sieieEE_faketemplate_pt70To90","",200,0.,0.1);
   sieieEE_faketemplate_pt70To90->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt70To90);
   TH1D* sieieEE_numerator_pt70To90 = new TH1D("sieieEE_numerator_pt70To90","",200,0.,0.1);
   sieieEE_numerator_pt70To90->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt70To90);
   TH1D* sieieEE_faketemplate_pt90To110 = new TH1D("sieieEE_faketemplate_pt90To110","",200,0.,0.1);
   sieieEE_faketemplate_pt90To110->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt90To110);
   TH1D* sieieEE_numerator_pt90To110 = new TH1D("sieieEE_numerator_pt90To110","",200,0.,0.1);
   sieieEE_numerator_pt90To110->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt90To110);
   TH1D* sieieEE_faketemplate_pt110To130 = new TH1D("sieieEE_faketemplate_pt110To130","",200,0.,0.1);
   sieieEE_faketemplate_pt110To130->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt110To130);
   TH1D* sieieEE_numerator_pt110To130 = new TH1D("sieieEE_numerator_pt110To130","",200,0.,0.1);
   sieieEE_numerator_pt110To130->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt110To130);
   TH1D* sieieEE_faketemplate_pt130To150 = new TH1D("sieieEE_faketemplate_pt130To150","",200,0.,0.1);
   sieieEE_faketemplate_pt130To150->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt130To150);
   TH1D* sieieEE_numerator_pt130To150 = new TH1D("sieieEE_numerator_pt130To150","",200,0.,0.1);
   sieieEE_numerator_pt130To150->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt130To150);
   TH1D* sieieEE_faketemplate_pt150To200 = new TH1D("sieieEE_faketemplate_pt150To200","",200,0.,0.1);
   sieieEE_faketemplate_pt150To200->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt150To200);
   TH1D* sieieEE_numerator_pt150To200 = new TH1D("sieieEE_numerator_pt150To200","",200,0.,0.1);
   sieieEE_numerator_pt150To200->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt150To200);
   TH1D* sieieEE_faketemplate_pt200To250 = new TH1D("sieieEE_faketemplate_pt200To250","",200,0.,0.1);
   sieieEE_faketemplate_pt200To250->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt200To250);
   TH1D* sieieEE_numerator_pt200To250 = new TH1D("sieieEE_numerator_pt200To250","",200,0.,0.1);
   sieieEE_numerator_pt200To250->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt200To250);
   TH1D* sieieEE_faketemplate_pt250To300 = new TH1D("sieieEE_faketemplate_pt250To300","",200,0.,0.1);
   sieieEE_faketemplate_pt250To300->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt250To300);
   TH1D* sieieEE_numerator_pt250To300 = new TH1D("sieieEE_numerator_pt250To300","",200,0.,0.1);
   sieieEE_numerator_pt250To300->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt250To300);
   TH1D* sieieEE_faketemplate_pt300ToInf = new TH1D("sieieEE_faketemplate_pt300ToInf","",200,0.,0.1);
   sieieEE_faketemplate_pt300ToInf->Sumw2();
   fakeTemplHistVec.push_back(sieieEE_faketemplate_pt300ToInf);
   TH1D* sieieEE_numerator_pt300ToInf = new TH1D("sieieEE_numerator_pt300ToInf","",200,0.,0.1);
   sieieEE_numerator_pt300ToInf->Sumw2();
   numeratorHistVec.push_back(sieieEE_numerator_pt300ToInf);

   TH2D* sipipVSsieieEE_numerator_pT300ToInf = new TH2D("sipipVSsieieEE_numerator_pT300ToInf","Photon pT > 300",200,0.,0.1,1000,0.,0.1);
   TH2D* bhidVSsieieEE_numerator_pT300ToInf = new TH2D("bhidVSsieieEE_numerator_pT300ToInf","Photon pT > 300",200,0.,0.1,2,-0.5,1.5);
   TH1D* scPhi_sieieEEHighPtTail = new TH1D("scPhi_sieieEEHighPtTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",300,-3.141593,3.141593);
   scPhi_sieieEEHighPtTail->GetXaxis()->SetTitle("Supercluster #varphi");
   TH1D* scEta_sieieEEHighPtTail = new TH1D("scEta_sieieEEHighPtTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",200,-2.5,2.5);
   scEta_sieieEEHighPtTail->GetXaxis()->SetTitle("Supercluster #eta");
   TH1D* pT_sieieEEHighPtTail = new TH1D("pT_sieieEEHighPtTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",20000,300.,50000.);
   pT_sieieEEHighPtTail->GetXaxis()->SetTitle("pT (GeV/c)");

   TH1D* iEta_sieieEEHighPtTail = new TH1D("iEta_sieieEEHighPtTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",100,0.5,100.5);
   iEta_sieieEEHighPtTail->GetXaxis()->SetTitle("i#eta");
   TH1D* iPhi_sieieEEHighPtTail = new TH1D("iPhi_sieieEEHighPtTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",100,0.5,100.5);
   iPhi_sieieEEHighPtTail->GetXaxis()->SetTitle("i#varphi");

   TH2D* iPhiVSiEta_sieieEEHighPTTail = new TH2D("iPhiVSiEta_sieieEEHighPTTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} > 0.04",100,0.5,100.5,100,0.5,100.5);
   iPhiVSiEta_sieieEEHighPTTail->GetXaxis()->SetTitle("i#eta");
   iPhiVSiEta_sieieEEHighPTTail->GetYaxis()->SetTitle("i#varphi");

   TH2D* iPhiVSiEta_NOTsieieEEHighPTTail = new TH2D("iPhiVSiEta_NOTsieieEEHighPTTail","Numerator Objects with pT > 300 GeV and #sigma_{i#etai#eta} < 0.04",100,0.5,100.5,100,0.5,100.5);
   iPhiVSiEta_NOTsieieEEHighPTTail->GetXaxis()->SetTitle("i#eta");
   iPhiVSiEta_NOTsieieEEHighPTTail->GetYaxis()->SetTitle("i#varphi");

   // std::map<long,std::map<long,int>> runMap;
   std::ofstream runOut("runsd.txt");
      
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry % 100000 == 0) std::cout << "Number of entries looped over: " << jentry << std::endl;

      //if (Event_beamHaloIDTight2015) continue;
      if (Photon_sigmaIphiIphi5x5 < 0.009) continue;
      
      // plot fake templates
      bool inChIsoSideband = (10. < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < 15.); //maybe add in sideband at runtime in the future?
      bool isNumeratorObj = Photon_isNumeratorObjCand && Photon_passChIso;
      bool isFakeTemplateObj = Photon_isNumeratorObjCand && inChIsoSideband;

      //debug plots
      if ( Photon_pt > 300. && isNumeratorObj && 1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5 ){
         sipipVSsieieEE_numerator_pT300ToInf->Fill( Photon_sigmaIetaIeta5x5, Photon_sigmaIphiIphi5x5 );
         bhidVSsieieEE_numerator_pT300ToInf->Fill( Photon_sigmaIetaIeta5x5, Event_beamHaloIDTight2015 );
         if (Photon_sigmaIetaIeta5x5 > 0.04){
            scEta_sieieEEHighPtTail->Fill(Photon_scEta);
            scPhi_sieieEEHighPtTail->Fill(Photon_scPhi);
            pT_sieieEEHighPtTail->Fill(Photon_pt);
            iEta_sieieEEHighPtTail->Fill(Photon_iEta);
            iPhi_sieieEEHighPtTail->Fill(Photon_iPhi);
            iPhiVSiEta_sieieEEHighPTTail->Fill(Photon_iEta,Photon_iPhi);

            // fill maps
            // if (runMap.count(Event_run) > 0) runMap[Event_run]++;
            // else runMap[Event_run] = 1;

            // if (lsMap.count(Event_LS) > 0) lsMap[Event_LS]++;
            // else lsMap[Event_LS] = 1;

            if (Photon_pt > 13000.) runOut << Event_run << ":" << Event_LS << ":" << Event_evnum << "\n";
         }
         else if (Photon_sigmaIetaIeta5x5 < 0.04) iPhiVSiEta_NOTsieieEEHighPTTail->Fill(Photon_iEta,Photon_iPhi);
      }

      if (fabs(Photon_scEta) < 1.4442) {
         phoPtEB.Fill( Photon_pt );
         if (isNumeratorObj){
            phoPtEB_numerator.Fill(Photon_pt);
            phoPtEB_numerator_varbin.Fill(Photon_pt);
         }
         if (Photon_isDenominatorObj){
            phoPtEB_denominator.Fill(Photon_pt);
            phoPtEB_denominator_varbin.Fill(Photon_pt);
         }
         if (isFakeTemplateObj){
            phoPtEB_faketemplate.Fill(Photon_pt);
            phoPtEB_faketemplate_varbin.Fill(Photon_pt);
         }
      }

      else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
         phoPtEE.Fill( Photon_pt );
         if (isNumeratorObj){
            phoPtEE_numerator.Fill(Photon_pt);
            phoPtEE_numerator_varbin.Fill(Photon_pt);
         }
         if (Photon_isDenominatorObj){
            phoPtEE_denominator.Fill(Photon_pt);
            phoPtEE_denominator_varbin.Fill(Photon_pt);
         }
         if (isFakeTemplateObj){
            phoPtEE_faketemplate.Fill(Photon_pt);
            phoPtEE_faketemplate_varbin.Fill(Photon_pt);
         }
      }

      // fake template phoPt spectrum

      //loop over pt bin low edges (also equal to or half of hist vector entry numbers) to fill numerator and fake templates
      for (int i = 0; i<10; i++){
         double binLowEdge = ptBinArray[i];
         double binUpperEdge = ptBinArray[i+1];

         // fill fake templates
         if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && isFakeTemplateObj ){

            if (fabs(Photon_scEta) < 1.4442) fakeTemplHistVec.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) fakeTemplHistVec.at(i+10)->Fill( Photon_sigmaIetaIeta5x5 );

         }

         // fill numerator histograms

         if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && isNumeratorObj ){

            if (fabs(Photon_scEta) < 1.4442) numeratorHistVec.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ){
               numeratorHistVec.at(i+10)->Fill( Photon_sigmaIetaIeta5x5 );
            }

         }

      } // end loop over pt bins for fake template
   } // end loop over entries

   // print text files
   // std::ofstream runOut("runs.txt");
   // std::ofstream lsOut("lss.txt");

   // for(std::map<long,int>::iterator it=runMap.begin(); it != runMap.end(); ++it){
   //    long runNum = it->first;
   //    long count = it->second;
   //    runOut << runNum << " " << count << "\n";
   // }
   runOut.close();

   // for(std::map<long,int>::iterator it=lsMap.begin(); it != lsMap.end(); ++it){
   //    long lsNum = it->first;
   //    long count = it->second;
   //    lsOut << lsNum << " " << count << "\n";
   // }
   // lsOut.close();

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
   sieieEB_faketemplate_pt300ToInf->Scale(1./sieieEB_faketemplate_pt300ToInf->Integral());
   sieieEE_faketemplate_pt30To50->Scale(1./sieieEE_faketemplate_pt30To50->Integral());
   sieieEE_faketemplate_pt50To70->Scale(1./sieieEE_faketemplate_pt50To70->Integral());
   sieieEE_faketemplate_pt70To90->Scale(1./sieieEE_faketemplate_pt70To90->Integral());
   sieieEE_faketemplate_pt90To110->Scale(1./sieieEE_faketemplate_pt90To110->Integral());
   sieieEE_faketemplate_pt110To130->Scale(1./sieieEE_faketemplate_pt110To130->Integral());
   sieieEE_faketemplate_pt130To150->Scale(1./sieieEE_faketemplate_pt130To150->Integral());
   sieieEE_faketemplate_pt150To200->Scale(1./sieieEE_faketemplate_pt150To200->Integral());
   sieieEE_faketemplate_pt200To250->Scale(1./sieieEE_faketemplate_pt200To250->Integral());
   sieieEE_faketemplate_pt250To300->Scale(1./sieieEE_faketemplate_pt250To300->Integral());
   sieieEE_faketemplate_pt300ToInf->Scale(1./sieieEE_faketemplate_pt300ToInf->Integral());
   
   // write histograms out to root files
   
   TFile file_out("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms_newbinning3.root","RECREATE");
   // TFile file_out("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","RECREATE");

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
   phoPtEB_numerator_varbin.Write();
   phoPtEE_numerator_varbin.Write();
   phoPtEB_denominator_varbin.Write();
   phoPtEE_denominator_varbin.Write();
   phoPtEB_faketemplate_varbin.Write();
   phoPtEE_faketemplate_varbin.Write();
   sieieEB_numerator_pt30To50->Write();
   sieieEB_numerator_pt50To70->Write();
   sieieEB_numerator_pt70To90->Write();
   sieieEB_numerator_pt90To110->Write();
   sieieEB_numerator_pt110To130->Write();
   sieieEB_numerator_pt130To150->Write();
   sieieEB_numerator_pt150To200->Write();
   sieieEB_numerator_pt200To250->Write();
   sieieEB_numerator_pt250To300->Write();
   sieieEB_numerator_pt300ToInf->Write();
   sieieEE_numerator_pt30To50->Write();
   sieieEE_numerator_pt50To70->Write();
   sieieEE_numerator_pt70To90->Write();
   sieieEE_numerator_pt90To110->Write();
   sieieEE_numerator_pt110To130->Write();
   sieieEE_numerator_pt130To150->Write();
   sieieEE_numerator_pt150To200->Write();
   sieieEE_numerator_pt200To250->Write();
   sieieEE_numerator_pt250To300->Write();
   sieieEE_numerator_pt300ToInf->Write();
   sipipVSsieieEE_numerator_pT300ToInf->Write();
   bhidVSsieieEE_numerator_pT300ToInf->Write();
   pT_sieieEEHighPtTail->Write();
   scEta_sieieEEHighPtTail->Write();
   scPhi_sieieEEHighPtTail->Write();
   iEta_sieieEEHighPtTail->Write();
   iPhi_sieieEEHighPtTail->Write();
   iPhiVSiEta_sieieEEHighPTTail->Write();
   iPhiVSiEta_NOTsieieEEHighPTTail->Write();
   sieieEB_faketemplate_pt30To50->Write();
   sieieEB_faketemplate_pt50To70->Write();
   sieieEB_faketemplate_pt70To90->Write();
   sieieEB_faketemplate_pt90To110->Write();
   sieieEB_faketemplate_pt110To130->Write();
   sieieEB_faketemplate_pt130To150->Write();
   sieieEB_faketemplate_pt150To200->Write();
   sieieEB_faketemplate_pt200To250->Write();
   sieieEB_faketemplate_pt250To300->Write();
   sieieEB_faketemplate_pt300ToInf->Write();
   sieieEE_faketemplate_pt30To50->Write();
   sieieEE_faketemplate_pt50To70->Write();
   sieieEE_faketemplate_pt70To90->Write();
   sieieEE_faketemplate_pt90To110->Write();
   sieieEE_faketemplate_pt110To130->Write();
   sieieEE_faketemplate_pt130To150->Write();
   sieieEE_faketemplate_pt150To200->Write();
   sieieEE_faketemplate_pt200To250->Write();
   sieieEE_faketemplate_pt250To300->Write();
   sieieEE_faketemplate_pt300ToInf->Write();

   
   file_out.ls();
   file_out.Close();
   
} // end Loop()
