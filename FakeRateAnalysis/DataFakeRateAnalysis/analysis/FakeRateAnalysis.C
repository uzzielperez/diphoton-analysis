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
  
  // define number of bin edges
  const int nBins = 11;
  
  // double ptBinArray[17] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 350., 400., 450., 500., 550., 600., 14.e3 };
  double ptBinArray[nBins] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 14.e3 };

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
  std::vector<TH1D*> sIeIeFakeTemplateEB;
  std::vector<TH1D*> sIeIeFakeTemplateEE;
  std::vector<TH1D*> sIeIeNumeratorEB;
  std::vector<TH1D*> sIeIeNumeratorEE;

  // loop over bins increments and create histograms
  for (int i = 0; i < nBins-1; i++) {
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];  
    
    TH1D *hEB_fakeTemplate = new TH1D(Form("sieieEB_faketemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_fakeTemplate->Sumw2();
    sIeIeFakeTemplateEB.push_back(hEB_fakeTemplate);
    
    TH1D *hEE_fakeTemplate = new TH1D(Form("sieieEE_faketemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_fakeTemplate->Sumw2();
    sIeIeFakeTemplateEE.push_back(hEE_fakeTemplate);

    TH1D *hEB_numerator = new TH1D(Form("sieieEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator->Sumw2();
    sIeIeNumeratorEB.push_back(hEB_numerator);

    TH1D *hEE_numerator = new TH1D(Form("sieieEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator->Sumw2();
    sIeIeNumeratorEE.push_back(hEE_numerator);
  }

  // loop over all entries
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry % 100000 == 0) std::cout << "Number of entries looped over: " << jentry << std::endl;

    // reject beam halo
    //if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;
      
    // plot fake templates
    bool inChIsoSideband = (10. < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < 15.); //maybe add in sideband at runtime in the future?
    bool isNumeratorObj = Photon_isNumeratorObjCand && Photon_passChIso;
    bool isFakeTemplateObj = Photon_isNumeratorObjCand && inChIsoSideband;

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
    for (int i = 0; i < nBins-1; i++){
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];

      // fill fake templates
      if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && isFakeTemplateObj ){

	if (fabs(Photon_scEta) < 1.4442) sIeIeFakeTemplateEB.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
	else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeFakeTemplateEE.at(i)->Fill( Photon_sigmaIetaIeta5x5 );

      }

      // fill numerator histograms
      if ( (binLowEdge < Photon_pt) && (Photon_pt < binUpperEdge) && isNumeratorObj ){

	if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB.at(i)->Fill( Photon_sigmaIetaIeta5x5 );
	else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE.at(i)->Fill( Photon_sigmaIetaIeta5x5 );

      }

    } // end loop over pt bins for fake template
  } // end loop over entries

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
  phoPtEB_numerator_varbin.Write();
  phoPtEE_numerator_varbin.Write();
  phoPtEB_denominator_varbin.Write();
  phoPtEE_denominator_varbin.Write();
  phoPtEB_faketemplate_varbin.Write();
  phoPtEE_faketemplate_varbin.Write();

  // write numerator histograms
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB.begin() ; it != sIeIeNumeratorEB.end(); ++it) {
    //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE.begin() ; it != sIeIeNumeratorEE.end(); ++it) {
    //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }

  // scale fake template histograms to unity and write to file
  for (vector<TH1D*>::iterator it = sIeIeFakeTemplateEB.begin() ; it != sIeIeFakeTemplateEB.end(); ++it) {
    //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Scale(1.0/(*it)->Integral());
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeFakeTemplateEE.begin() ; it != sIeIeFakeTemplateEE.end(); ++it) {
    //cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Scale(1.0/(*it)->Integral());
    (*it)->Write();
  }
  
  file_out.ls();
  file_out.Close();
   
} // end Loop()
