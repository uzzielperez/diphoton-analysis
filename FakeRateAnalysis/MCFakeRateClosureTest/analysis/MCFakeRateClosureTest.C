#define MCFakeRateClosureTest_cxx
#include "MCFakeRateClosureTest.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MCFakeRateClosureTest::Loop(const Char_t * iMass)
{
//   In a ROOT session, you can do:
//      root> .L MCFakeRateClosureTest.C
//      root> MCFakeRateClosureTest t
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
  
  double ptBinArray[nBins] = { 30., 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // make vector of sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );

  // pt spectrum of denominator objects
  TH1D phoPtEB_denominator_varbin("phoPtEB_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE_denominator_varbin("phoPtEE_denominator_varbin","",nBins-1,ptBinArray);
  phoPtEB_denominator_varbin.Sumw2();
  phoPtEE_denominator_varbin.Sumw2();
  
  // numerator and template histograms
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEB; // for each pT bin, there will be a vector of templates, one for each chIso sideband definition
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE;

  // create empty vectors to hold all the templates.  One vector for each pT bin
  for (int i=0; i<nBins-1; i++){
    std::vector<TH1D*> ebvec;
    std::vector<TH1D*> eevec;
    sIeIeFakeTemplatesEB.push_back(ebvec);
    sIeIeFakeTemplatesEE.push_back(eevec);
  }
  
  std::vector<TH1D*> sIeIeNumeratorEB;
  std::vector<TH1D*> sIeIeNumeratorEE;
  std::vector<TH1D*> denomPtEB;
  std::vector<TH1D*> denomPtEE;
  
  // loop over bins increments and create histograms
  for (int i = 0; i < nBins-1; i++) {
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];  
    
    // TH1D *hEB_fakeTemplate = new TH1D(Form("sieieEB_faketemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    // hEB_fakeTemplate->Sumw2();
    // sIeIeFakeTemplateEB.push_back(hEB_fakeTemplate);
    
    // TH1D *hEE_fakeTemplate = new TH1D(Form("sieieEE_faketemplate_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    // hEE_fakeTemplate->Sumw2();
    // sIeIeFakeTemplateEE.push_back(hEE_fakeTemplate);

    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it){
      
      double sidebandLow = it->first;
      double sidebandHigh = it->second;

      TH1D* sieieEB_faketemplate = new TH1D(Form( "sieieEB_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",200,0.,0.1);
      sieieEB_faketemplate->Sumw2();
      sIeIeFakeTemplatesEB.at(i).push_back( sieieEB_faketemplate );

      TH1D* sieieEE_faketemplate = new TH1D(Form( "sieieEE_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",200,0.,0.1);
      sieieEE_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE.at(i).push_back( sieieEE_faketemplate );

    } // end loop over sidebands

    TH1D *hEB_numerator = new TH1D(Form("sieieEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",200,0.,0.1);
    hEB_numerator->Sumw2();
    sIeIeNumeratorEB.push_back(hEB_numerator);

    TH1D *hEE_numerator = new TH1D(Form("sieieEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",200,0.,0.1);
    hEE_numerator->Sumw2();
    sIeIeNumeratorEE.push_back(hEE_numerator);

    // pt binned denominator histograms
    TH1D *hEB_denominator = new TH1D(Form("PtEB_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEB",100,binLowEdge,binUpperEdge);
    hEB_denominator->Sumw2();
    denomPtEB.push_back(hEB_denominator);

    TH1D *hEE_denominator = new TH1D(Form("PtEE_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE",100,binLowEdge,binUpperEdge);
    hEE_denominator->Sumw2();
    denomPtEE.push_back(hEE_denominator);
  }

  // loop over all entries
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry % 100000 == 0)
      std::cout << "Number of entries looped over: " << jentry << std::endl;

    // fake rate object definitions
    bool isNumeratorObj = Photon_isNumeratorObjCand && Photon_passChIso;
    // bool inChIsoSideband = (sidebandLow < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < sidebandHigh);
    // bool isFakeTemplateObj = Photon_isNumeratorObjCand && inChIsoSideband;
    
    // reject beam halo
    //if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;

    // EB
    if (fabs(Photon_scEta) < 1.4442) {
      if (Photon_isDenominatorObj) {
	phoPtEB_denominator_varbin.Fill(Photon_pt,Event_weight);
      }
    } // end EB
    
    // EE
    else if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
      if (Photon_isDenominatorObj) {
	phoPtEE_denominator_varbin.Fill(Photon_pt,Event_weight);
      }
    } // end EE
    
    // loop over bin edges
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      
      // pt cut
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {

      	// fill fake template histograms

      	// if (isFakeTemplateObj) {
      	//   if (fabs(Photon_scEta) < 1.4442) sIeIeFakeTemplateEB.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
      	//   else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeFakeTemplateEE.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
      	// } // end fake template obj
        for (unsigned int j=0; j < chIsoSidebands.size(); j++){
          double sidebandLow = chIsoSidebands.at(j).first;
          double sidebandHigh = chIsoSidebands.at(j).second;
          bool inChIsoSideband = (sidebandLow < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < sidebandHigh);
          bool isFakeTemplateObj = Photon_isNumeratorObjCand && inChIsoSideband;

          if (isFakeTemplateObj){
            if (fabs(Photon_scEta) < 1.4442) sIeIeFakeTemplatesEB.at(i).at(j)->Fill( Photon_sigmaIetaIeta5x5, Event_weight );
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeFakeTemplatesEE.at(i).at(j)->Fill( Photon_sigmaIetaIeta5x5, Event_weight );
          }
        } // end loop over sidebands to fill fake templates

      	// fill numerator histograms
      	if (isNumeratorObj) {
      	  if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
      	  else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) sIeIeNumeratorEE.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weight);
      	} // end numerator obj

	// fill denominator histograms
	if (Photon_isDenominatorObj) {
	  if (fabs(Photon_scEta) < 1.4442) denomPtEB.at(i)->Fill(Photon_pt,Event_weight);
	  else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ) denomPtEE.at(i)->Fill(Photon_pt,Event_weight);
	}
	
      } // end pt cut
      
    } // end loop over pt bins for fake template
    
  } // end loop over entries
  
  // create output file containing histograms
  TString filename;
  if (strcmp(iMass,"all") == 0) filename = "diphoton_fakeRate_QCD_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  else filename = TString::Format("diphoton_fakeRate_QCD_Pt_%s_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root",iMass);
  TFile file_out(filename,"RECREATE");

  // write denominator histograms
  phoPtEB_denominator_varbin.Write();
  phoPtEE_denominator_varbin.Write();
  cout << phoPtEB_denominator_varbin.GetName() << "\t integral: " << phoPtEB_denominator_varbin.Integral() << endl;
  cout << phoPtEE_denominator_varbin.GetName() << "\t integral: " << phoPtEE_denominator_varbin.Integral() << endl;
  
  // write numerator histograms
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB.begin() ; it != sIeIeNumeratorEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE.begin() ; it != sIeIeNumeratorEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }

  // write denominator histograms
  for (vector<TH1D*>::iterator it = denomPtEB.begin() ; it != denomPtEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = denomPtEE.begin() ; it != denomPtEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  
  // scale fake template histograms to unity and write to file
  // for (vector<TH1D*>::iterator it = sIeIeFakeTemplateEB.begin() ; it != sIeIeFakeTemplateEB.end(); ++it) {
  //   cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
  //   (*it)->Scale(1.0/(*it)->Integral());
  //   (*it)->Write();
  // }
  // for (vector<TH1D*>::iterator it = sIeIeFakeTemplateEE.begin() ; it != sIeIeFakeTemplateEE.end(); ++it) {
  //   cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
  //   (*it)->Scale(1.0/(*it)->Integral());
  //   (*it)->Write();
  // }
  for (int i = 0; i < nBins-1; i++){
    for (unsigned int j=0; j < chIsoSidebands.size(); j++){
      TH1D* tempHistEB = sIeIeFakeTemplatesEB.at(i).at(j);
      TH1D* tempHistEE = sIeIeFakeTemplatesEE.at(i).at(j);

      cout << tempHistEB->GetName() << "\t integral: " << tempHistEB->Integral() << endl;
      tempHistEB->Scale(1./tempHistEB->Integral());
      tempHistEB->Write();

      cout << tempHistEE->GetName() << "\t integral: " << tempHistEE->Integral() << endl;
      tempHistEE->Scale(1./tempHistEE->Integral());
      tempHistEE->Write();
    }
  }
  
  file_out.ls();
  file_out.Close();
  
} // end of Loop()
