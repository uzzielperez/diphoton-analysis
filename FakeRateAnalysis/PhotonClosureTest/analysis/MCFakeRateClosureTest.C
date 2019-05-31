#define MCFakeRateClosureTest_cxx
#include "MCFakeRateClosureTest.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MCFakeRateClosureTest::Loop()
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

  // input what sample is being run on
  TString sample = "";
  cout << "Enter sample being run on (QCD, GJets, GGJets, or all): ";
  cin >> sample;
  if (sample != "QCD" && sample != "GJets" && sample != "GGJets" && sample != "all") {
    cout << "Invalid choice!" << endl;
    return;
  }
  cout << "\nUsing sample: " << sample << endl;

  // output filename
  TString filename = "";
  if (sample == "QCD")    filename = "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_76X_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root";
  if (sample == "all")    filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root";
  cout << "Output filename: " << filename << endl << endl;

  // count number of numerator photons
  int nNumerator              = 0;
  int nNumerator_passSipipCut = 0;

  // define number of bin edges
  //const int nBins = 10;
  //double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };
  const int nBins = 6;
  double ptBinArray[nBins] = { 50., 70., 90., 130., 200., 600. };

  // vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  chIsoSidebands.push_back( std::make_pair(6.,11.) );
  chIsoSidebands.push_back( std::make_pair(7.,12.) );
  chIsoSidebands.push_back( std::make_pair(8.,13.) );
  chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  chIsoSidebands.push_back( std::make_pair(10.,20.) );

  // vector of sieie sidebands
  // EB
  std::vector< std::pair<double,double> > sieie_EB_sidebands;
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,1.0000) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0105,0.0150) );
  sieie_EB_sidebands.push_back( std::make_pair(0.0150,0.0200) );
  // EE
  std::vector< std::pair<double,double> > sieie_EE_sidebands;
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,1.000) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0280,0.040) );
  sieie_EE_sidebands.push_back( std::make_pair(0.0400,0.060) );

  // vector of nPV regions
  std::vector< std::pair<int,int> > nPV_regions;
  nPV_regions.push_back( std::make_pair(0,100000) ); // no cut
  nPV_regions.push_back( std::make_pair(0,13) );
  nPV_regions.push_back( std::make_pair(14,17) );
  nPV_regions.push_back( std::make_pair(18,20) );
  nPV_regions.push_back( std::make_pair(21,24) );
  nPV_regions.push_back( std::make_pair(25,100000) ); // 25-Inf

  // pt spectrum of denominator objects
  // variable binned
  TH1D phoPtEB_denominator_varbin("phoPtEB_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE_denominator_varbin("phoPtEE_denominator_varbin","",nBins-1,ptBinArray);
  phoPtEB_denominator_varbin.Sumw2();
  phoPtEE_denominator_varbin.Sumw2();
  // all objects
  TH1D *photon_pt_denominator_EB = new TH1D("photon_pt_denominator_EB","",50,0,2000);
  TH1D *photon_pt_denominator_EE = new TH1D("photon_pt_denominator_EE","",50,0,2000);
  photon_pt_denominator_EB->Sumw2();
  photon_pt_denominator_EE->Sumw2();
  TH1D *photon_eta_denominator_EB = new TH1D("photon_eta_denominator_EB","",25,-5,5);
  TH1D *photon_eta_denominator_EE = new TH1D("photon_eta_denominator_EE","",25,-5,5);
  photon_eta_denominator_EB->Sumw2();
  photon_eta_denominator_EE->Sumw2();
  TH1D *photon_phi_denominator_EB = new TH1D("photon_phi_denominator_EB","",25,-5,5);
  TH1D *photon_phi_denominator_EE = new TH1D("photon_phi_denominator_EE","",25,-5,5);
  photon_phi_denominator_EB->Sumw2();
  photon_phi_denominator_EE->Sumw2();
  // weighted by fake rake objects
  TH1D *photon_pt_denominator_fake_rate_weighted_EB = new TH1D("photon_pt_denominator_fake_rate_weighted_EB","",50,0,2000);
  TH1D *photon_pt_denominator_fake_rate_weighted_EE = new TH1D("photon_pt_denominator_fake_rate_weighted_EE","",50,0,2000);
  photon_pt_denominator_fake_rate_weighted_EB->Sumw2();
  photon_pt_denominator_fake_rate_weighted_EE->Sumw2();
  TH1D *photon_eta_denominator_fake_rate_weighted_EB = new TH1D("photon_eta_denominator_fake_rate_weighted_EB","",25,-5,5);
  TH1D *photon_eta_denominator_fake_rate_weighted_EE = new TH1D("photon_eta_denominator_fake_rate_weighted_EE","",25,-5,5);
  photon_eta_denominator_fake_rate_weighted_EB->Sumw2();
  photon_eta_denominator_fake_rate_weighted_EE->Sumw2();
  TH1D *photon_phi_denominator_fake_rate_weighted_EB = new TH1D("photon_phi_denominator_fake_rate_weighted_EB","",25,-5,5);
  TH1D *photon_phi_denominator_fake_rate_weighted_EE = new TH1D("photon_phi_denominator_fake_rate_weighted_EE","",25,-5,5);
  photon_phi_denominator_fake_rate_weighted_EB->Sumw2();
  photon_phi_denominator_fake_rate_weighted_EE->Sumw2();

  // fake templates for each pt bin and each sideband definition
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEB;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE;
  std::vector< std::vector<TH1D*> > chIsoFakeTemplatesEB;
  std::vector< std::vector<TH1D*> > chIsoFakeTemplatesEE;
  // create empty vectors to hold all the templates
  for (int i = 0; i < nBins-1; i++) {
    std::vector<TH1D*> ebvec;
    std::vector<TH1D*> eevec;
    sIeIeFakeTemplatesEB.push_back(ebvec);
    sIeIeFakeTemplatesEE.push_back(eevec);
    chIsoFakeTemplatesEB.push_back(ebvec);
    chIsoFakeTemplatesEE.push_back(ebvec);
  }

  // numerator histogram vector for each pt bin
  std::vector<TH1D*> sIeIeNumeratorEB;
  std::vector<TH1D*> sIeIeNumeratorEE;
  std::vector<TH1D*> chIsoNumeratorEB;
  std::vector<TH1D*> chIsoNumeratorEE;

  // denominator histogram vector for each pt bin
  std::vector<TH1D*> denomPtEB;
  std::vector<TH1D*> denomPtEE;

  // loop over pT bins and book histograms
  for (int i = 0; i < nBins-1; i++) {

    // get bin edges
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];

    // form sieie histograms with chIso sideband
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* sieieEB_faketemplate = new TH1D(Form( "sieieEB_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",20,0.,0.03);
      sieieEB_faketemplate->Sumw2();
      sIeIeFakeTemplatesEB.at(i).push_back( sieieEB_faketemplate );
      TH1D* sieieEE_faketemplate = new TH1D(Form( "sieieEE_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",20,0.,0.08);
      sieieEE_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE.at(i).push_back( sieieEE_faketemplate );
    } // end loop over chIso sidebands

    // form chIso histograms with sieie sideband
    // EB
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EB_sidebands.begin(); it != sieie_EB_sidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* chIsoEB_faketemplate = new TH1D(Form( "chIsoEB_faketemplate_pt%dTo%d_sieie%1.4fTo%1.4f",(int)binLowEdge,(int)binUpperEdge,sidebandLow,sidebandHigh ),"",10,0.,10.);
      chIsoEB_faketemplate->Sumw2();
      chIsoFakeTemplatesEB.at(i).push_back( chIsoEB_faketemplate );
    } // end loop over sieie EB sidebands
    // EE
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EE_sidebands.begin(); it != sieie_EE_sidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* chIsoEE_faketemplate = new TH1D(Form( "chIsoEE_faketemplate_pt%dTo%d_sieie%1.4fTo%1.4f",(int)binLowEdge,(int)binUpperEdge,sidebandLow,sidebandHigh ),"",10,0.,10.);
      chIsoEE_faketemplate->Sumw2();
      chIsoFakeTemplatesEE.at(i).push_back( chIsoEE_faketemplate );
    } // end loop over sieie EE sidebands

    // book sieie numberator histograms
    TH1D *hEB_sieie_numerator = new TH1D(Form("sieieEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",20,0.,0.03);
    hEB_sieie_numerator->Sumw2();
    sIeIeNumeratorEB.push_back(hEB_sieie_numerator);
    TH1D *hEE_sieie_numerator = new TH1D(Form("sieieEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",20,0.,0.08);
    hEE_sieie_numerator->Sumw2();
    sIeIeNumeratorEE.push_back(hEE_sieie_numerator);

    // book chIso numberator histograms
    TH1D *hEB_chIso_numerator = new TH1D(Form("chIsoEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"chIsoEB",10,0.,10.);
    hEB_chIso_numerator->Sumw2();
    chIsoNumeratorEB.push_back(hEB_chIso_numerator);
    TH1D *hEE_chIso_numerator = new TH1D(Form("chIsoEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"chIsoEE",10,0.,10.);
    hEE_chIso_numerator->Sumw2();
    chIsoNumeratorEE.push_back(hEE_chIso_numerator);

    // book denominator histograms
    TH1D *hEB_denominator = new TH1D(Form("PtEB_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEB",50,binLowEdge,binUpperEdge);
    hEB_denominator->Sumw2();
    denomPtEB.push_back(hEB_denominator);
    TH1D *hEE_denominator = new TH1D(Form("PtEE_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE",50,binLowEdge,binUpperEdge);
    hEE_denominator->Sumw2();
    denomPtEE.push_back(hEE_denominator);
  } // end loop over pt bins

  // histograms in PV bins
  std::vector<TH1D*> photonIsoEB;
  std::vector<TH1D*> photonIsoEB1;
  std::vector<TH1D*> photonIsoEB2;
  std::vector<TH1D*> photonIsoEE;
  std::vector<TH1D*> photonIsoEE1;
  std::vector<TH1D*> photonIsoEE2;
  std::vector<TH1D*> corPhotonIsoEB;
  std::vector<TH1D*> corPhotonIsoEB1;
  std::vector<TH1D*> corPhotonIsoEB2;
  std::vector<TH1D*> corPhotonIsoEE;
  std::vector<TH1D*> corPhotonIsoEE1;
  std::vector<TH1D*> corPhotonIsoEE2;

  for (std::vector<std::pair<int,int> >::const_iterator it = nPV_regions.begin(); it != nPV_regions.end(); ++it) {

    int pv_low = it->first;
    int pv_high = it->second;

    // photon isolation
    TH1D* photon_iso_EB = new TH1D(Form( "photonIso_EB_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EB->Sumw2();
    photonIsoEB.push_back( photon_iso_EB );
    TH1D* photon_iso_EB1 = new TH1D(Form( "photonIso_EB1_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EB1->Sumw2();
    photonIsoEB1.push_back( photon_iso_EB1 );
    TH1D* photon_iso_EB2 = new TH1D(Form( "photonIso_EB2_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EB2->Sumw2();
    photonIsoEB2.push_back( photon_iso_EB2 );
    TH1D* photon_iso_EE = new TH1D(Form( "photonIso_EE_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EE->Sumw2();
    photonIsoEE.push_back( photon_iso_EE );
    TH1D* photon_iso_EE1 = new TH1D(Form( "photonIso_EE1_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EE1->Sumw2();
    photonIsoEE1.push_back( photon_iso_EE1 );
    TH1D* photon_iso_EE2 = new TH1D(Form( "photonIso_EE2_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EE2->Sumw2();
    photonIsoEE2.push_back( photon_iso_EE2 );

    // corrected photon isolation
    TH1D* cor_photon_iso_EB = new TH1D(Form( "corPhotonIso_EB_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EB->Sumw2();
    corPhotonIsoEB.push_back( cor_photon_iso_EB );
    TH1D* cor_photon_iso_EB1 = new TH1D(Form( "corPhotonIso_EB1_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EB1->Sumw2();
    corPhotonIsoEB1.push_back( cor_photon_iso_EB1 );
    TH1D* cor_photon_iso_EB2 = new TH1D(Form( "corPhotonIso_EB2_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EB2->Sumw2();
    corPhotonIsoEB2.push_back( cor_photon_iso_EB2 );
    TH1D* cor_photon_iso_EE = new TH1D(Form( "corPhotonIso_EE_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EE->Sumw2();
    corPhotonIsoEE.push_back( cor_photon_iso_EE );
    TH1D* cor_photon_iso_EE1 = new TH1D(Form( "corPhotonIso_EE1_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EE1->Sumw2();
    corPhotonIsoEE1.push_back( cor_photon_iso_EE1 );
    TH1D* cor_photon_iso_EE2 = new TH1D(Form( "corPhotonIso_EE2_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EE2->Sumw2();
    corPhotonIsoEE2.push_back( cor_photon_iso_EE2 );

  } // end loop over pv bins

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
    bool is_sieie_numerator_object = Photon_isNumeratorObjCand && Photon_passChIso;
    bool is_chIso_numerator_object = Photon_isNumeratorObjCand && Photon_passSieie;
    bool is_denominator_object = Photon_isDenominatorObj && Photon_hadronicOverEm < 0.1;

    if (is_sieie_numerator_object) nNumerator++;

    // reject beam halo
    // if (Event_beamHaloIDTight2015) continue;
    if (Photon_sigmaIphiIphi5x5 < 0.009) continue;

    if (is_sieie_numerator_object) nNumerator_passSipipCut++;

    // photon pt cut (already applied in the analyzer)
    if (Photon_pt < 50.) continue;

    // calculate nPV
    int nPV_after_cut = 0;
    for (unsigned int i = 0; i < VertexCollInfo_vx->size(); i++) {
      int ndof = VertexCollInfo_ndof->at(i);
      double absZ = fabs(VertexCollInfo_vz->at(i));
      double d0 = VertexCollInfo_d0->at(i);
      if ( (ndof >= 4) && (absZ <= 24.) && (d0 <= 2.) )
        nPV_after_cut++;
    }

    // high-pT ID photons
    if (Photon_passHighPtID) {
      // PV cuts
      for (std::vector< std::pair<int,int> >::const_iterator it = nPV_regions.begin(); it != nPV_regions.end(); ++it) {
	int pv_low = it->first;
	int pv_high = it->second;
	auto pos = it - nPV_regions.begin();
	if (pv_low <= nPV_after_cut && nPV_after_cut <= pv_high) {
	  // EB
	  if (fabs(Photon_scEta) < 1.4442) {
	    photonIsoEB.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEB.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EB1
	  if (fabs(Photon_scEta) < 0.7221) {
	    photonIsoEB1.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEB1.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EB2
	  if (0.7221 < fabs(Photon_scEta) && fabs(Photon_scEta) < 1.4442) {
	    photonIsoEB2.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEB2.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE
	  if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	    photonIsoEE.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE1
	  if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.033) {
	    photonIsoEE1.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE1.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE2
	  if (2.033 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	    photonIsoEE2.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE2.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	} // end if pV cuts
      } // end for loop over PV regions
    } // end if high-pT ID photons

    // denominator objects not in pt bins
    if (is_denominator_object) {
      // EB
      if (fabs(Photon_scEta) < 1.4442) {
	phoPtEB_denominator_varbin.Fill(Photon_pt,Event_weightAll);
	photon_pt_denominator_EB->Fill(Photon_pt,Event_weightAll);
	photon_pt_denominator_fake_rate_weighted_EB->Fill(Photon_pt,Event_weightAll*FakeRateEB(Photon_pt));
	photon_eta_denominator_EB->Fill(Photon_eta,Event_weightAll);
	photon_eta_denominator_fake_rate_weighted_EB->Fill(Photon_eta,Event_weightAll*FakeRateEB(Photon_pt));
	photon_phi_denominator_EB->Fill(Photon_phi,Event_weightAll);
	photon_phi_denominator_fake_rate_weighted_EB->Fill(Photon_phi,Event_weightAll*FakeRateEB(Photon_pt));
      } // end EB
      // EE
      if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	phoPtEE_denominator_varbin.Fill(Photon_pt,Event_weightAll);
	photon_pt_denominator_EE->Fill(Photon_pt,Event_weightAll);
	photon_pt_denominator_fake_rate_weighted_EE->Fill(Photon_pt,Event_weightAll*FakeRateEE(Photon_pt));
	photon_eta_denominator_EE->Fill(Photon_eta,Event_weightAll);
	photon_eta_denominator_fake_rate_weighted_EE->Fill(Photon_eta,Event_weightAll*FakeRateEE(Photon_pt));
	photon_phi_denominator_EE->Fill(Photon_phi,Event_weightAll);
	photon_phi_denominator_fake_rate_weighted_EE->Fill(Photon_phi,Event_weightAll*FakeRateEE(Photon_pt));
      } // end EE
    } // end if denominator object

    // fill pt binned histograms
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      // pt cut
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {
	// fill sieie numerator histograms
      	if (is_sieie_numerator_object) {
      	  if (fabs(Photon_scEta) < 1.4442)
	    sIeIeNumeratorEB.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
      	  else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	    sIeIeNumeratorEE.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
      	} // end if sieie numerator object
	// fill chIso numerator histograms
      	if (is_chIso_numerator_object) {
      	  if (fabs(Photon_scEta) < 1.4442)
	    chIsoNumeratorEB.at(i)->Fill(Photon_chargedHadIso03,Event_weightAll);
      	  else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	    chIsoNumeratorEE.at(i)->Fill(Photon_chargedHadIso03,Event_weightAll);
      	} // end if chIso numerator object
	// fill denominator histograms
	if (is_denominator_object) {
	  if (fabs(Photon_scEta) < 1.4442)
	    denomPtEB.at(i)->Fill(Photon_pt,Event_weightAll);
	  else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	    denomPtEE.at(i)->Fill(Photon_pt,Event_weightAll);
	} // end if denominator object
	// fill fake templates with chIso sidebands
        for (unsigned int j = 0; j < chIsoSidebands.size(); j++) {
          double sidebandLow = chIsoSidebands.at(j).first;
          double sidebandHigh = chIsoSidebands.at(j).second;
          bool in_chIso_sideband = (sidebandLow < Photon_chargedHadIso03) && (Photon_chargedHadIso03 < sidebandHigh);
          bool is_sieie_fake_template_object = Photon_isNumeratorObjCand && in_chIso_sideband;
	  // remove real template photons from fake templates
          if (is_sieie_fake_template_object /*&& PhotonRealMatch == 0*/) {
            if (fabs(Photon_scEta) < 1.4442)
	      sIeIeFakeTemplatesEB.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
            else if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	      sIeIeFakeTemplatesEE.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          } // end if fake template object
        } // end for loop over chIso sidebands for fake templates
	// fill fake templates with sieie sidebands in EB
	for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EB_sidebands.begin(); it != sieie_EB_sidebands.end(); ++it) {
	  auto pos = it - sieie_EB_sidebands.begin();
	  double sidebandLow = it->first;
	  double sidebandHigh = it->second;
	  bool in_sieie_sideband = (sidebandLow < Photon_sigmaIetaIeta5x5) && (Photon_sigmaIetaIeta5x5 < sidebandHigh);
	  bool is_chIso_fake_template_object = Photon_isNumeratorObjCand && in_sieie_sideband;
	  if (is_chIso_fake_template_object /*&& PhotonRealMatch == 0*/)
	    if (fabs(Photon_scEta) < 1.4442)
	      chIsoFakeTemplatesEB.at(i).at(pos)->Fill(Photon_chargedHadIso03,Event_weightAll);
	} // end for loop over sieie sidebands for fake templates EE
	// fill fake templates with sieie sidebands in EE
	for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EE_sidebands.begin(); it != sieie_EE_sidebands.end(); ++it) {
	  auto pos = it - sieie_EE_sidebands.begin();
	  double sidebandLow = it->first;
	  double sidebandHigh = it->second;
	  bool in_sieie_sideband = (sidebandLow < Photon_sigmaIetaIeta5x5) && (Photon_sigmaIetaIeta5x5 < sidebandHigh);
	  bool is_chIso_fake_template_object = Photon_isNumeratorObjCand && in_sieie_sideband;
	  if (is_chIso_fake_template_object /*&& PhotonRealMatch == 0*/)
	    if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	      chIsoFakeTemplatesEE.at(i).at(pos)->Fill(Photon_chargedHadIso03,Event_weightAll);
	} // end for loop over sieie sidebands for fake templates EE
      } // end if pt cut
    } // end for loop over pt bins

  } // end loop over entries

  cout << endl;
  cout << "Number of numerator photons: " << nNumerator << endl;
  cout << " ...passing sipip cut      : " << nNumerator_passSipipCut << endl;
  cout << endl;

  // create output file
  TFile file_out(filename,"RECREATE");

  // write denominator histograms
  // variable binned
  phoPtEB_denominator_varbin.Write();
  phoPtEE_denominator_varbin.Write();
  cout << phoPtEB_denominator_varbin.GetName() << "\t integral: " << phoPtEB_denominator_varbin.Integral() << endl;
  cout << phoPtEE_denominator_varbin.GetName() << "\t integral: " << phoPtEE_denominator_varbin.Integral() << endl;
  // all objects
  photon_pt_denominator_EB->Write();
  photon_pt_denominator_EE->Write();
  cout << photon_pt_denominator_EB->GetName() << "\t integral: " << photon_pt_denominator_EB->Integral() << endl;
  cout << photon_pt_denominator_EE->GetName() << "\t integral: " << photon_pt_denominator_EE->Integral() << endl;
  photon_eta_denominator_EB->Write();
  photon_eta_denominator_EE->Write();
  cout << photon_eta_denominator_EB->GetName() << "\t integral: " << photon_eta_denominator_EB->Integral() << endl;
  cout << photon_eta_denominator_EE->GetName() << "\t integral: " << photon_eta_denominator_EE->Integral() << endl;
  photon_phi_denominator_EB->Write();
  photon_phi_denominator_EE->Write();
  cout << photon_phi_denominator_EB->GetName() << "\t integral: " << photon_phi_denominator_EB->Integral() << endl;
  cout << photon_phi_denominator_EE->GetName() << "\t integral: " << photon_phi_denominator_EE->Integral() << endl;
  // fake rate weighted
  photon_pt_denominator_fake_rate_weighted_EB->Write();
  photon_pt_denominator_fake_rate_weighted_EE->Write();
  cout << photon_pt_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EB->Integral() << endl;
  cout << photon_pt_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EE->Integral() << endl;
  photon_eta_denominator_fake_rate_weighted_EB->Write();
  photon_eta_denominator_fake_rate_weighted_EE->Write();
  cout << photon_eta_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EB->Integral() << endl;
  cout << photon_eta_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EE->Integral() << endl;
  photon_phi_denominator_fake_rate_weighted_EB->Write();
  photon_phi_denominator_fake_rate_weighted_EE->Write();
  cout << photon_phi_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EB->Integral() << endl;
  cout << photon_phi_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EE->Integral() << endl;

  // write sieie numerator histograms
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEB.begin() ; it != sIeIeNumeratorEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = sIeIeNumeratorEE.begin() ; it != sIeIeNumeratorEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }

  // write chIso numerator histograms
  for (vector<TH1D*>::iterator it = chIsoNumeratorEB.begin() ; it != chIsoNumeratorEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = chIsoNumeratorEE.begin() ; it != chIsoNumeratorEE.end(); ++it) {
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

  // write PV histograms
  //
  // photonIso
  for (vector<TH1D*>::iterator it = photonIsoEB.begin() ; it != photonIsoEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = photonIsoEB1.begin() ; it != photonIsoEB1.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = photonIsoEB2.begin() ; it != photonIsoEB2.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = photonIsoEE.begin() ; it != photonIsoEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = photonIsoEE1.begin() ; it != photonIsoEE1.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = photonIsoEE2.begin() ; it != photonIsoEE2.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  // corPhotonIso
  for (vector<TH1D*>::iterator it = corPhotonIsoEB.begin() ; it != corPhotonIsoEB.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = corPhotonIsoEB1.begin() ; it != corPhotonIsoEB1.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = corPhotonIsoEB2.begin() ; it != corPhotonIsoEB2.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = corPhotonIsoEE.begin() ; it != corPhotonIsoEE.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = corPhotonIsoEE1.begin() ; it != corPhotonIsoEE1.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }
  for (vector<TH1D*>::iterator it = corPhotonIsoEE2.begin() ; it != corPhotonIsoEE2.end(); ++it) {
    cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << endl;
    (*it)->Write();
  }

  // write sieie fake template histograms
  for (int i = 0; i < nBins-1; i++) {
    for (unsigned int j = 0; j < chIsoSidebands.size(); j++) {
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

  // write chIso fake template histograms
  for (int i = 0; i < nBins-1; i++) {
    // EB
    for (unsigned int j = 0; j < sieie_EB_sidebands.size(); j++) {
      TH1D* tempHistEB = chIsoFakeTemplatesEB.at(i).at(j);
      cout << tempHistEB->GetName() << "\t integral: " << tempHistEB->Integral() << endl;
      tempHistEB->Scale(1./tempHistEB->Integral());
      tempHistEB->Write();
    }
    // EE
    for (unsigned int j = 0; j < sieie_EE_sidebands.size(); j++) {
      TH1D* tempHistEE = chIsoFakeTemplatesEE.at(i).at(j);
      cout << tempHistEE->GetName() << "\t integral: " << tempHistEE->Integral() << endl;
      tempHistEE->Scale(1./tempHistEE->Integral());
      tempHistEE->Write();
    }
  }

  file_out.ls();
  file_out.Close();

} // end of Loop()


double MCFakeRateClosureTest::FakeRateEB(double pt) {
  double p0 = 0.00401543257042;
  double p1 = 85.57002275698491;
  double p2 = 1.71203116120994;
  return p0+p1/std::pow(pt,p2);
}

double MCFakeRateClosureTest::FakeRateEE(double pt) {
  // if (pt < 135.0) {
  //   double p0 = 0.03690596612126;
  //   double p1 = 0.00008030430975;
  //   double p2 = 0.00000940893255;
  //   return p0+p1*(pt-135)+p2*std::pow(pt-135,2);
  // }
  // else if (pt >= 135.0) {
  //   double p0 = 0.02606488430528; // yint
  //   double p1 = 0.00008030430975; // slope
  //   return p0+p1*pt; // pol1
  // }
  // else return 0;
  double p0 = -0.15299002741780;
  double p1 = 0.63378808277185;
  double p2 = 0.21130650931470;
  return p0+p1/std::pow(pt,p2);
}
