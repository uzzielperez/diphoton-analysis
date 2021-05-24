#define MCFakeRateClosureTest_cxx
#include "MCFakeRateClosureTest.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "diphoton-analysis/FakeRateAnalysis/interface/utilities.hh"
#include "diphoton-analysis/Tools/interface/fakeRates.hh"

#include <memory>

void MCFakeRateClosureTestBase::Loop() {};

class MCFakeRateClosureTest : public MCFakeRateClosureTestBase {

public:
  using MCFakeRateClosureTestBase::MCFakeRateClosureTestBase;
  void Loop() {};
  void Loop(TString run, TString sample);
  double FakeRateEB(double pt);
  double FakeRateEE(double pt);
  int m_year;
  // std::unique_ptr<fakeRatesClosureTest> m_fakeRate;
  // std::unique_ptr<float> m_fakeRate;
  std::unique_ptr<fakeRates> m_fakeRate;
};


void MCFakeRateClosureTest::Loop(TString run, TString sample)
{
  m_year = run.Atoi();
  // m_fakeRate = std::make_unique<fakeRates>("average", m_year);
  // m_fakeRatesClosureTest = std::make_unique<fakeRatesClosureTest>("all", m_year,);
  // m_fakeRate = std::make_unique<float>();
  m_fakeRate = std::make_unique<fakeRates>("all", m_year);

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

  // output filename
  TString filename = "";
  if (sample == "QCD")    filename = "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_" + cmssw_version(m_year) + "_MiniAOD_histograms.root";
  if (sample == "GJets")  filename = "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_" + cmssw_version(m_year) + "_MiniAOD_histograms.root";
  if (sample == "GGJets") filename = "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_" + cmssw_version(m_year) + "_MiniAOD_histograms.root";
  if (sample == "all")    filename = "diphoton_fake_rate_closure_test_all_samples_" + cmssw_version(m_year) + "_MiniAOD_histograms.root";
  std::cout << "Output filename: " << filename << std::endl << std::endl;

  // count number of numerator photons
  int nNumerator              = 0;
  int nNumerator_passSipipCut = 0;

  // define number of bin edges
  const int nBins = 10;
  double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

  // vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  // chIsoSidebands.push_back( std::make_pair(0.,5.) );
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
  // granular: 1- inner, 2- outer
  TH1D phoPtEB1_denominator_varbin("phoPtEB1_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE1_denominator_varbin("phoPtEE1_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEB2_denominator_varbin("phoPtEB2_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE2_denominator_varbin("phoPtEE2_denominator_varbin","",nBins-1,ptBinArray);
  TH1D phoPtEE3_denominator_varbin("phoPtEE3_denominator_varbin","",nBins-1,ptBinArray);
  // fake templates granular 1- inner, 2- outer (EE, 1-inner, 2-middle, 3-outer)
  phoPtEB1_denominator_varbin.Sumw2();
  phoPtEE1_denominator_varbin.Sumw2();
  phoPtEB2_denominator_varbin.Sumw2();
  phoPtEE2_denominator_varbin.Sumw2();
  phoPtEE3_denominator_varbin.Sumw2();

  // all objects
  TH1D *photon_pt_denominator_EB = new TH1D("photon_pt_denominator_EB","",200,0,2000);
  TH1D *photon_pt_denominator_EE = new TH1D("photon_pt_denominator_EE","",200,0,2000);
  photon_pt_denominator_EB->Sumw2();
  photon_pt_denominator_EE->Sumw2();
  TH1D *photon_eta_denominator_EB = new TH1D("photon_eta_denominator_EB","",100,-5,5);
  TH1D *photon_eta_denominator_EE = new TH1D("photon_eta_denominator_EE","",100,-5,5);
  photon_eta_denominator_EB->Sumw2();
  photon_eta_denominator_EE->Sumw2();
  TH1D *photon_phi_denominator_EB = new TH1D("photon_phi_denominator_EB","",100,-5,5);
  TH1D *photon_phi_denominator_EE = new TH1D("photon_phi_denominator_EE","",100,-5,5);
  photon_phi_denominator_EB->Sumw2();
  photon_phi_denominator_EE->Sumw2();
  // weighted by fake rake objects
  TH1D *photon_pt_denominator_fake_rate_weighted_EB = new TH1D("photon_pt_denominator_fake_rate_weighted_EB","",200,0,2000);
  TH1D *photon_pt_denominator_fake_rate_weighted_EE = new TH1D("photon_pt_denominator_fake_rate_weighted_EE","",200,0,2000);
  photon_pt_denominator_fake_rate_weighted_EB->Sumw2();
  photon_pt_denominator_fake_rate_weighted_EE->Sumw2();
  TH1D *photon_eta_denominator_fake_rate_weighted_EB = new TH1D("photon_eta_denominator_fake_rate_weighted_EB","",100,-5,5);
  TH1D *photon_eta_denominator_fake_rate_weighted_EE = new TH1D("photon_eta_denominator_fake_rate_weighted_EE","",100,-5,5);
  photon_eta_denominator_fake_rate_weighted_EB->Sumw2();
  photon_eta_denominator_fake_rate_weighted_EE->Sumw2();
  TH1D *photon_phi_denominator_fake_rate_weighted_EB = new TH1D("photon_phi_denominator_fake_rate_weighted_EB","",100,-5,5);
  TH1D *photon_phi_denominator_fake_rate_weighted_EE = new TH1D("photon_phi_denominator_fake_rate_weighted_EE","",100,-5,5);
  photon_phi_denominator_fake_rate_weighted_EB->Sumw2();
  photon_phi_denominator_fake_rate_weighted_EE->Sumw2();

  // fake templates for each pt bin and each sideband definition
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEB;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE;
  std::vector< std::vector<TH1D*> > chIsoFakeTemplatesEB;
  std::vector< std::vector<TH1D*> > chIsoFakeTemplatesEE;
  // fake templates granular 1- inner, 2- outer
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEB1;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEB2;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE1;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE2;
  std::vector< std::vector<TH1D*> > sIeIeFakeTemplatesEE3;

  // create empty vectors to hold all the templates
  for (int i = 0; i < nBins-1; i++) {
    std::vector<TH1D*> ebvec;
    std::vector<TH1D*> eevec;
    sIeIeFakeTemplatesEB.push_back(ebvec);
    sIeIeFakeTemplatesEE.push_back(eevec);
    chIsoFakeTemplatesEB.push_back(ebvec);
    chIsoFakeTemplatesEE.push_back(ebvec);

    // for granular
    std::vector<TH1D*> eb1vec;
    std::vector<TH1D*> eb2vec;
    std::vector<TH1D*> ee1vec;
    std::vector<TH1D*> ee2vec;
    std::vector<TH1D*> ee3vec;
    sIeIeFakeTemplatesEB1.push_back(eb1vec);
    sIeIeFakeTemplatesEB2.push_back(eb2vec);
    sIeIeFakeTemplatesEE1.push_back(ee1vec);
    sIeIeFakeTemplatesEE2.push_back(ee2vec);
    sIeIeFakeTemplatesEE3.push_back(ee3vec);
  }

  // numerator histogram vector for each pt bin
  std::vector<TH1D*> sIeIeNumeratorEB;
  std::vector<TH1D*> sIeIeNumeratorEE;
  std::vector<TH1D*> chIsoNumeratorEB;
  std::vector<TH1D*> chIsoNumeratorEE;

  // numerator for granular
  std::vector<TH1D*> sIeIeNumeratorEB1;
  std::vector<TH1D*> sIeIeNumeratorEB2;
  std::vector<TH1D*> sIeIeNumeratorEE1;
  std::vector<TH1D*> sIeIeNumeratorEE2;
  std::vector<TH1D*> sIeIeNumeratorEE3;


  // denominator histogram vector for each pt bin
  std::vector<TH1D*> denomPtEB;
  std::vector<TH1D*> denomPtEE;

  // // denominator for granular
  std::vector<TH1D*> denomPtEB1;
  std::vector<TH1D*> denomPtEB2;
  std::vector<TH1D*> denomPtEE1;
  std::vector<TH1D*> denomPtEE2;
  std::vector<TH1D*> denomPtEE3;

  // loop over pT bins and book histograms
  for (int i = 0; i < nBins-1; i++) {

    // get bin edges
    double binLowEdge = ptBinArray[i];
    double binUpperEdge = ptBinArray[i+1];

    // form sieie histograms with chIso sideband
    for (chIsoIt it = chIsoSidebands.begin(); it != chIsoSidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* sieieEB_faketemplate = new TH1D(Form( "sieieEB_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",50,0.,0.1);
      sieieEB_faketemplate->Sumw2();
      sIeIeFakeTemplatesEB.at(i).push_back( sieieEB_faketemplate );
      TH1D* sieieEE_faketemplate = new TH1D(Form( "sieieEE_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",25,0.,0.1);
      sieieEE_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE.at(i).push_back( sieieEE_faketemplate );

      // granular
      TH1D* sieieEB1_faketemplate = new TH1D(Form( "sieieEB1_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",50,0.,0.1);
      sieieEB1_faketemplate->Sumw2();
      sIeIeFakeTemplatesEB1.at(i).push_back( sieieEB1_faketemplate );
      TH1D* sieieEB2_faketemplate = new TH1D(Form( "sieieEB2_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",50,0.,0.1);
      sieieEB2_faketemplate->Sumw2();
      sIeIeFakeTemplatesEB2.at(i).push_back( sieieEB2_faketemplate );

      TH1D* sieieEE1_faketemplate = new TH1D(Form( "sieieEE1_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",25,0.,0.1);
      sieieEE1_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE1.at(i).push_back( sieieEE1_faketemplate );
      TH1D* sieieEE2_faketemplate = new TH1D(Form( "sieieEE2_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",25,0.,0.1);
      sieieEE2_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE2.at(i).push_back( sieieEE2_faketemplate );

      TH1D* sieieEE3_faketemplate = new TH1D(Form( "sieieEE3_faketemplate_pt%dTo%d_chIso%dTo%d",(int)binLowEdge,(int)binUpperEdge,(int)sidebandLow,(int)sidebandHigh ),"",25,0.,0.1);
      sieieEE3_faketemplate->Sumw2();
      sIeIeFakeTemplatesEE3.at(i).push_back( sieieEE3_faketemplate );

    } // end loop over chIso sidebands

    // form chIso histograms with sieie sideband
    // EB
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EB_sidebands.begin(); it != sieie_EB_sidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* chIsoEB_faketemplate = new TH1D(Form( "chIsoEB_faketemplate_pt%dTo%d_sieie%1.4fTo%1.4f",(int)binLowEdge,(int)binUpperEdge,sidebandLow,sidebandHigh ),"",50,0.,50.);
      chIsoEB_faketemplate->Sumw2();
      chIsoFakeTemplatesEB.at(i).push_back( chIsoEB_faketemplate );
    } // end loop over sieie EB sidebands
    // EE
    for (std::vector< std::pair<double,double> >::const_iterator it = sieie_EE_sidebands.begin(); it != sieie_EE_sidebands.end(); ++it) {
      double sidebandLow = it->first;
      double sidebandHigh = it->second;
      TH1D* chIsoEE_faketemplate = new TH1D(Form( "chIsoEE_faketemplate_pt%dTo%d_sieie%1.4fTo%1.4f",(int)binLowEdge,(int)binUpperEdge,sidebandLow,sidebandHigh ),"",50,0.,50.);
      chIsoEE_faketemplate->Sumw2();
      chIsoFakeTemplatesEE.at(i).push_back( chIsoEE_faketemplate );
    } // end loop over sieie EE sidebands

    // book sieie numberator histograms
    TH1D *hEB_sieie_numerator = new TH1D(Form("sieieEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB",50,0.,0.1);
    hEB_sieie_numerator->Sumw2();
    sIeIeNumeratorEB.push_back(hEB_sieie_numerator);
    TH1D *hEE_sieie_numerator = new TH1D(Form("sieieEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE",25,0.,0.1);
    hEE_sieie_numerator->Sumw2();
    sIeIeNumeratorEE.push_back(hEE_sieie_numerator);

    // granular sieie numerator histograms
    TH1D *hEB1_sieie_numerator = new TH1D(Form("sieieEB1_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB1",50,0.,0.1);
    hEB1_sieie_numerator->Sumw2();
    sIeIeNumeratorEB1.push_back(hEB1_sieie_numerator);
    TH1D *hEB2_sieie_numerator = new TH1D(Form("sieieEB2_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEB2",50,0.,0.1);
    hEB2_sieie_numerator->Sumw2();
    sIeIeNumeratorEB2.push_back(hEB2_sieie_numerator);
    TH1D *hEE1_sieie_numerator = new TH1D(Form("sieieEE1_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE1",25,0.,0.1);
    hEE1_sieie_numerator->Sumw2();
    sIeIeNumeratorEE1.push_back(hEE1_sieie_numerator);
    TH1D *hEE2_sieie_numerator = new TH1D(Form("sieieEE2_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE2",25,0.,0.1);
    hEE2_sieie_numerator->Sumw2();
    sIeIeNumeratorEE2.push_back(hEE2_sieie_numerator);

    TH1D *hEE3_sieie_numerator = new TH1D(Form("sieieEE3_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"sigmaIetaIetaEE3",25,0.,0.1);
    hEE3_sieie_numerator->Sumw2();
    sIeIeNumeratorEE3.push_back(hEE3_sieie_numerator);

    // book chIso numberator histograms
    TH1D *hEB_chIso_numerator = new TH1D(Form("chIsoEB_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"chIsoEB",50,0.,50.);
    hEB_chIso_numerator->Sumw2();
    chIsoNumeratorEB.push_back(hEB_chIso_numerator);
    TH1D *hEE_chIso_numerator = new TH1D(Form("chIsoEE_numerator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"chIsoEE",50,0.,50.);
    hEE_chIso_numerator->Sumw2();
    chIsoNumeratorEE.push_back(hEE_chIso_numerator);

    // book denominator histograms
    TH1D *hEB_denominator = new TH1D(Form("PtEB_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEB",100,binLowEdge,binUpperEdge);
    hEB_denominator->Sumw2();
    denomPtEB.push_back(hEB_denominator);
    TH1D *hEE_denominator = new TH1D(Form("PtEE_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE",100,binLowEdge,binUpperEdge);
    hEE_denominator->Sumw2();
    denomPtEE.push_back(hEE_denominator);

    // granular denominator histograms
    TH1D *hEB1_denominator = new TH1D(Form("PtEB1_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEB1",100,binLowEdge,binUpperEdge);
    hEB1_denominator->Sumw2();
    denomPtEB1.push_back(hEB1_denominator);
    TH1D *hEB2_denominator = new TH1D(Form("PtEB2_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEB2",100,binLowEdge,binUpperEdge);
    hEB2_denominator->Sumw2();
    denomPtEB2.push_back(hEB2_denominator);
    TH1D *hEE1_denominator = new TH1D(Form("PtEE1_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE1",100,binLowEdge,binUpperEdge);
    hEE1_denominator->Sumw2();
    denomPtEE1.push_back(hEE1_denominator);
    TH1D *hEE2_denominator = new TH1D(Form("PtEE2_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE2",100,binLowEdge,binUpperEdge);
    hEE2_denominator->Sumw2();
    denomPtEE2.push_back(hEE2_denominator);

    TH1D *hEE3_denominator = new TH1D(Form("PtEE3_denominator_pt%dTo%d",(int)binLowEdge,(int)binUpperEdge),"PtEE3",100,binLowEdge,binUpperEdge);
    hEE3_denominator->Sumw2();
    denomPtEE3.push_back(hEE3_denominator);

  } // end loop over pt bins

  // histograms in PV bins
  std::vector<TH1D*> photonIsoEB;
  std::vector<TH1D*> photonIsoEB1;
  std::vector<TH1D*> photonIsoEB2;
  std::vector<TH1D*> photonIsoEE;
  std::vector<TH1D*> photonIsoEE1;
  std::vector<TH1D*> photonIsoEE2;
  std::vector<TH1D*> photonIsoEE3;
  std::vector<TH1D*> corPhotonIsoEB;
  std::vector<TH1D*> corPhotonIsoEB1;
  std::vector<TH1D*> corPhotonIsoEB2;
  std::vector<TH1D*> corPhotonIsoEE;
  std::vector<TH1D*> corPhotonIsoEE1;
  std::vector<TH1D*> corPhotonIsoEE2;
  std::vector<TH1D*> corPhotonIsoEE3;

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
    TH1D* photon_iso_EE3 = new TH1D(Form( "photonIso_EE3_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    photon_iso_EE3->Sumw2();
     photonIsoEE3.push_back( photon_iso_EE3 );

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
    TH1D* cor_photon_iso_EE3 = new TH1D(Form( "corPhotonIso_EE3_nPV%dTo%d",(int)pv_low,(int)pv_high),"",80,-20,20);
    cor_photon_iso_EE3->Sumw2();
    corPhotonIsoEE3.push_back( cor_photon_iso_EE3 );

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
    // if (Photon_pt < 50.) continue;
    // Apply Higher pT cut 125 GeV
    // if (Photon_pt < 125.) continue;

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
	  // if (fabs(Photon_scEta) < 0.7221) {
    if (fabs(Photon_scEta) < 1.000) {
	    photonIsoEB1.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEB1.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EB2
	  // if (0.7221 < fabs(Photon_scEta) && fabs(Photon_scEta) < 1.4442) {
    if (1.000 < fabs(Photon_scEta) && fabs(Photon_scEta) < 1.4442) {
	    photonIsoEB2.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEB2.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE
	  if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	    photonIsoEE.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE1
	  // if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.033) {
    if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 1.8773) {
	    photonIsoEE1.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE1.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
	  // EE2
	  // if (2.033 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
    if (1.8773 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.1887) {
	    photonIsoEE2.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
	    corPhotonIsoEE2.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
	  }
    // EE3
    if (2.1887 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
      photonIsoEE3.at(pos)->Fill(Photon_photonIso03,Event_weightAll);
      corPhotonIsoEE3.at(pos)->Fill(Photon_corPhotonIso03,Event_weightAll);
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

      // granular 1-inner, 2-outer
      // if ( fabs(Photon_scEta) < 0.7221 ) phoPtEB1_denominator_varbin.Fill(Photon_pt,Event_weightAll);
      // if ( (0.7221 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) phoPtEB2_denominator_varbin.Fill(Photon_pt,Event_weightAll);
      // if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.033) )  phoPtEE1_denominator_varbin.Fill(Photon_pt,Event_weightAll);
      // if ( (2.033 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  phoPtEE2_denominator_varbin.Fill(Photon_pt,Event_weightAll);

      // granular 1-inner, 2-outer (EE: 1-inner, 2-middle, 3-outer)
     if ( fabs(Photon_scEta) < 1.000 ) phoPtEB1_denominator_varbin.Fill(Photon_pt,Event_weightAll);
     if ( (1.000 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) phoPtEB2_denominator_varbin.Fill(Photon_pt,Event_weightAll);
     if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.8773) )  phoPtEE1_denominator_varbin.Fill(Photon_pt,Event_weightAll);
     if ( (1.8773 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.1887) )  phoPtEE2_denominator_varbin.Fill(Photon_pt,Event_weightAll);
     if ( (2.1887 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  phoPtEE3_denominator_varbin.Fill(Photon_pt,Event_weightAll);
    } // end if denominator object

    // fill pt binned histograms
    for (int i = 0; i < nBins-1; i++) {
      double binLowEdge = ptBinArray[i];
      double binUpperEdge = ptBinArray[i+1];
      // pt cut
      if (binLowEdge < Photon_pt && Photon_pt < binUpperEdge) {
	// fill sieie numerator histograms
      	if (is_sieie_numerator_object) {
      	  if (fabs(Photon_scEta) < 1.4442) sIeIeNumeratorEB.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
      	  if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  sIeIeNumeratorEE.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          // // granular 1-inner, 2-outer
          // if ( fabs(Photon_scEta) < 0.7221 ) sIeIeNumeratorEB1.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          // if ( (0.7221 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) sIeIeNumeratorEB2.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          // if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.033) )  sIeIeNumeratorEE1.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          // if ( (2.033 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  sIeIeNumeratorEE2.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);

          // granular 1-inner, 2-outer (EE: 1-inner, 2-middle, 3-outer)
          if ( fabs(Photon_scEta) < 1.000 ) sIeIeNumeratorEB1.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.000 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) sIeIeNumeratorEB2.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.8773) )  sIeIeNumeratorEE1.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.8773 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.1887) )  sIeIeNumeratorEE2.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (2.1887 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  sIeIeNumeratorEE3.at(i)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);

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
	  if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	    denomPtEE.at(i)->Fill(Photon_pt,Event_weightAll);
    // // granular 1-inner, 2-outer
    // if ( fabs(Photon_scEta) < 0.7221 ) denomPtEB1.at(i)->Fill(Photon_pt,Event_weightAll);
    // if ( (0.7221 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) denomPtEB2.at(i)->Fill(Photon_pt,Event_weightAll);
    // if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.033) )  denomPtEE1.at(i)->Fill(Photon_pt,Event_weightAll);
    // if ( (2.033 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  denomPtEE2.at(i)->Fill(Photon_pt,Event_weightAll);

    // granular 1-inner, 2-outer (EE: 1-inner, 2-middle, 3-outer)
    if ( fabs(Photon_scEta) < 1.000 ) denomPtEB1.at(i)->Fill(Photon_pt,Event_weightAll);
    if ( (1.000 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) denomPtEB2.at(i)->Fill(Photon_pt,Event_weightAll);
    if ( (1.566  < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.8773) )  denomPtEE1.at(i)->Fill(Photon_pt,Event_weightAll);
    if ( (1.8773 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.1887) )  denomPtEE2.at(i)->Fill(Photon_pt,Event_weightAll);
    if ( (2.1887 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  denomPtEE3.at(i)->Fill(Photon_pt,Event_weightAll);

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
            if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )
	      sIeIeFakeTemplatesEE.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
        // // granular: 1- inner, 2- outer
        //     if ( fabs(Photon_scEta) < 0.7221 ) sIeIeFakeTemplatesEB1.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
        //     if ( (0.7221 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) sIeIeFakeTemplatesEB2.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
        //     if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.033) )  sIeIeFakeTemplatesEE1.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
        //     if ( (2.033 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  sIeIeFakeTemplatesEE2.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);

          // granular 1-inner, 2-outer (EE: 1-inner, 2-middle, 3-outer)
          if ( fabs(Photon_scEta) < 1.000 ) sIeIeFakeTemplatesEB1.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.000 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ) sIeIeFakeTemplatesEB2.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.8773) )  sIeIeFakeTemplatesEE1.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (1.8773 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.1887) )  sIeIeFakeTemplatesEE2.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
          if ( (2.1887 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) )  sIeIeFakeTemplatesEE3.at(i).at(j)->Fill(Photon_sigmaIetaIeta5x5,Event_weightAll);
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

  std::cout << std::endl;
  std::cout << "Number of numerator photons: " << nNumerator << std::endl;
  std::cout << " ...passing sipip cut      : " << nNumerator_passSipipCut << std::endl;
  std::cout << std::endl;

  // create output file
  TFile file_out(filename,"RECREATE");

  // write denominator histograms
  // variable binned
  phoPtEB_denominator_varbin.Write();
  phoPtEE_denominator_varbin.Write();
  std::cout << phoPtEB_denominator_varbin.GetName() << "\t integral: " << phoPtEB_denominator_varbin.Integral() << std::endl;
  std::cout << phoPtEE_denominator_varbin.GetName() << "\t integral: " << phoPtEE_denominator_varbin.Integral() << std::endl;
  // granular: 1- inner , 2- outer
  phoPtEB1_denominator_varbin.Write();
  phoPtEB2_denominator_varbin.Write();
  phoPtEE1_denominator_varbin.Write();
  phoPtEE2_denominator_varbin.Write();
  phoPtEE3_denominator_varbin.Write();
  std::cout << phoPtEB1_denominator_varbin.GetName() << "\t integral: " << phoPtEB1_denominator_varbin.Integral() << std::endl;
  std::cout << phoPtEE1_denominator_varbin.GetName() << "\t integral: " << phoPtEE1_denominator_varbin.Integral() << std::endl;
  std::cout << phoPtEB2_denominator_varbin.GetName() << "\t integral: " << phoPtEB2_denominator_varbin.Integral() << std::endl;
  std::cout << phoPtEE2_denominator_varbin.GetName() << "\t integral: " << phoPtEE2_denominator_varbin.Integral() << std::endl;
  std::cout << phoPtEE3_denominator_varbin.GetName() << "\t integral: " << phoPtEE3_denominator_varbin.Integral() << std::endl;
  // all objects
  photon_pt_denominator_EB->Write();
  photon_pt_denominator_EE->Write();
  std::cout << photon_pt_denominator_EB->GetName() << "\t integral: " << photon_pt_denominator_EB->Integral() << std::endl;
  std::cout << photon_pt_denominator_EE->GetName() << "\t integral: " << photon_pt_denominator_EE->Integral() << std::endl;
  photon_eta_denominator_EB->Write();
  photon_eta_denominator_EE->Write();
  std::cout << photon_eta_denominator_EB->GetName() << "\t integral: " << photon_eta_denominator_EB->Integral() << std::endl;
  std::cout << photon_eta_denominator_EE->GetName() << "\t integral: " << photon_eta_denominator_EE->Integral() << std::endl;
  photon_phi_denominator_EB->Write();
  photon_phi_denominator_EE->Write();
  std::cout << photon_phi_denominator_EB->GetName() << "\t integral: " << photon_phi_denominator_EB->Integral() << std::endl;
  std::cout << photon_phi_denominator_EE->GetName() << "\t integral: " << photon_phi_denominator_EE->Integral() << std::endl;
  // fake rate weighted
  photon_pt_denominator_fake_rate_weighted_EB->Write();
  photon_pt_denominator_fake_rate_weighted_EE->Write();
  std::cout << photon_pt_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EB->Integral() << std::endl;
  std::cout << photon_pt_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EE->Integral() << std::endl;
  photon_eta_denominator_fake_rate_weighted_EB->Write();
  photon_eta_denominator_fake_rate_weighted_EE->Write();
  std::cout << photon_eta_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EB->Integral() << std::endl;
  std::cout << photon_eta_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EE->Integral() << std::endl;
  photon_phi_denominator_fake_rate_weighted_EB->Write();
  photon_phi_denominator_fake_rate_weighted_EE->Write();
  std::cout << photon_phi_denominator_fake_rate_weighted_EB->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EB->Integral() << std::endl;
  std::cout << photon_phi_denominator_fake_rate_weighted_EE->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EE->Integral() << std::endl;

  // write sieie numerator histograms
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEB.begin() ; it != sIeIeNumeratorEB.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEE.begin() ; it != sIeIeNumeratorEE.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  // granular sieie numerator histograms
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEB1.begin() ; it != sIeIeNumeratorEB1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEB2.begin() ; it != sIeIeNumeratorEB2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEE1.begin() ; it != sIeIeNumeratorEE1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEE2.begin() ; it != sIeIeNumeratorEE2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = sIeIeNumeratorEE3.begin() ; it != sIeIeNumeratorEE2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }

  // write chIso numerator histograms
  for (std::vector<TH1D*>::iterator it = chIsoNumeratorEB.begin() ; it != chIsoNumeratorEB.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = chIsoNumeratorEE.begin() ; it != chIsoNumeratorEE.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }

  // write denominator histograms
  for (std::vector<TH1D*>::iterator it = denomPtEB.begin() ; it != denomPtEB.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = denomPtEE.begin() ; it != denomPtEE.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }

  // write granular
  for (std::vector<TH1D*>::iterator it = denomPtEB1.begin() ; it != denomPtEB1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = denomPtEB2.begin() ; it != denomPtEB2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = denomPtEE1.begin() ; it != denomPtEE1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = denomPtEE2.begin() ; it != denomPtEE2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = denomPtEE3.begin() ; it != denomPtEE3.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }



  // write PV histograms
  //
  // photonIso
  for (std::vector<TH1D*>::iterator it = photonIsoEB.begin() ; it != photonIsoEB.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEB1.begin() ; it != photonIsoEB1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEB2.begin() ; it != photonIsoEB2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEE.begin() ; it != photonIsoEE.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEE1.begin() ; it != photonIsoEE1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEE2.begin() ; it != photonIsoEE2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = photonIsoEE3.begin() ; it != photonIsoEE3.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  // corPhotonIso
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEB.begin() ; it != corPhotonIsoEB.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEB1.begin() ; it != corPhotonIsoEB1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEB2.begin() ; it != corPhotonIsoEB2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEE.begin() ; it != corPhotonIsoEE.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEE1.begin() ; it != corPhotonIsoEE1.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }
  for (std::vector<TH1D*>::iterator it = corPhotonIsoEE2.begin() ; it != corPhotonIsoEE2.end(); ++it) {
    std::cout << (*it)->GetName() << "\t integral: " << (*it)->Integral() << std::endl;
    (*it)->Write();
  }

  // write sieie fake template histograms
  for (int i = 0; i < nBins-1; i++) {
    for (unsigned int j = 0; j < chIsoSidebands.size(); j++) {
      TH1D* tempHistEB = sIeIeFakeTemplatesEB.at(i).at(j);
      TH1D* tempHistEE = sIeIeFakeTemplatesEE.at(i).at(j);

      std::cout << tempHistEB->GetName() << "\t integral: " << tempHistEB->Integral() << std::endl;
      tempHistEB->Scale(1./tempHistEB->Integral());
      tempHistEB->Write();
      std::cout << tempHistEE->GetName() << "\t integral: " << tempHistEE->Integral() << std::endl;
      tempHistEE->Scale(1./tempHistEE->Integral());
      tempHistEE->Write();

      // granular 1-inner; 2-outer
      TH1D* tempHistEB1 = sIeIeFakeTemplatesEB1.at(i).at(j);
      TH1D* tempHistEB2 = sIeIeFakeTemplatesEB2.at(i).at(j);
      TH1D* tempHistEE1 = sIeIeFakeTemplatesEE1.at(i).at(j);
      TH1D* tempHistEE2 = sIeIeFakeTemplatesEE2.at(i).at(j);
      TH1D* tempHistEE3 = sIeIeFakeTemplatesEE3.at(i).at(j);

      std::cout << tempHistEB1->GetName() << "\t integral: " << tempHistEB1->Integral() << std::endl;
      tempHistEB1->Scale(1./tempHistEB1->Integral());
      tempHistEB1->Write();
      std::cout << tempHistEB2->GetName() << "\t integral: " << tempHistEB2->Integral() << std::endl;
      tempHistEB2->Scale(1./tempHistEB2->Integral());
      tempHistEB2->Write();
      std::cout << tempHistEE1->GetName() << "\t integral: " << tempHistEE1->Integral() << std::endl;
      tempHistEE1->Scale(1./tempHistEE1->Integral());
      tempHistEE1->Write();
      std::cout << tempHistEE2->GetName() << "\t integral: " << tempHistEE2->Integral() << std::endl;
      tempHistEE2->Scale(1./tempHistEE2->Integral());
      tempHistEE2->Write();
      std::cout << tempHistEE3->GetName() << "\t integral: " << tempHistEE3->Integral() << std::endl;
      tempHistEE3->Scale(1./tempHistEE3->Integral());
      tempHistEE3->Write();

    }
  }

  // write chIso fake template histograms
  for (int i = 0; i < nBins-1; i++) {
    // EB
    for (unsigned int j = 0; j < sieie_EB_sidebands.size(); j++) {
      TH1D* tempHistEB = chIsoFakeTemplatesEB.at(i).at(j);
      std::cout << tempHistEB->GetName() << "\t integral: " << tempHistEB->Integral() << std::endl;
      tempHistEB->Scale(1./tempHistEB->Integral());
      tempHistEB->Write();
    }
    // EE
    for (unsigned int j = 0; j < sieie_EE_sidebands.size(); j++) {
      TH1D* tempHistEE = chIsoFakeTemplatesEE.at(i).at(j);
      std::cout << tempHistEE->GetName() << "\t integral: " << tempHistEE->Integral() << std::endl;
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
  // add getFakeRate method from Chris (2016, 2017, 2018)
  if (m_year == 2016 or m_year == 2017 or m_year == 2018){
    return m_fakeRate->getFakeRateClosureTest(pt, "EB", m_year);
  }
  return p0+p1/std::pow(pt,p2);
}

double MCFakeRateClosureTest::FakeRateEE(double pt) {
  double p0 = -0.15299002741780;
  double p1 = 0.63378808277185;
  double p2 = 0.21130650931470;
  // add getFakeRate method from Chris (2016, 2017, 2018)
  if (m_year == 2016 or m_year == 2017 or m_year == 2018){
    return m_fakeRate->getFakeRateClosureTest(pt, "EE", m_year);
  }
  return p0+p1/std::pow(pt,p2);
}
