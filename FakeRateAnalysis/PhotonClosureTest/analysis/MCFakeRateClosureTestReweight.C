#define MCFakeRateClosureTestReweight_cxx
#include "MCFakeRateClosureTestReweight.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "diphoton-analysis/FakeRateAnalysis/interface/utilities.hh"
#include "diphoton-analysis/Tools/interface/fakeRates.hh"

#include <memory>

void MCFakeRateClosureTestReweightBase::Loop() {};

class MCFakeRateClosureTestReweight : public MCFakeRateClosureTestReweightBase {

public:
  using MCFakeRateClosureTestReweightBase::MCFakeRateClosureTestReweightBase;
  void Loop() {};
  void Loop(TString run, TString sample);
  double FakeRateEB(double pt);
  double FakeRateEE(double pt);
  double FakeRateEtaBinned(double pt, std::string region);
  int m_year;
  // std::unique_ptr<fakeRatesClosureTest> m_fakeRate;
  // std::unique_ptr<float> m_fakeRate;
  std::unique_ptr<fakeRates> m_fakeRate;
};

void MCFakeRateClosureTestReweight::Loop(TString run, TString sample)
{
  m_year = run.Atoi();
  // m_fakeRate = std::make_unique<fakeRates>("average", m_year);
  // m_fakeRatesClosureTest = std::make_unique<fakeRatesClosureTest>("all", m_year,);
  // m_fakeRate = std::make_unique<float>();
  m_fakeRate = std::make_unique<fakeRates>("all", m_year);

  if (fChain == 0) return;

  // output filename
  TString filename = "";
  if (sample == "QCD")    filename = "diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_" + cmssw_version(m_year) + "_MiniAOD_histograms_reweighted.root";
  if (sample == "GJets")  filename = "diphoton_fake_rate_closure_test_GJets_HT-all_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_" + cmssw_version(m_year) + "_MiniAOD_histograms_reweighted.root";
  if (sample == "GGJets") filename = "diphoton_fake_rate_closure_test_GGJets_M-all_Pt-50_13TeV-sherpa_" + cmssw_version(m_year) + "_MiniAOD_histograms_reweighted.root";
  if (sample == "all")    filename = "diphoton_fake_rate_closure_test_all_samples_" + cmssw_version(m_year) + "_MiniAOD_histograms_reweighted.root";
  std::cout << "Output filename: " << filename << std::endl << std::endl;

  // count number of numerator photons
  int nNumerator              = 0;
  int nNumerator_passSipipCut = 0;

  // define number of bin edges
  // const int nBins = 10;
  // double ptBinArray[nBins] = { 50., 70., 90., 110., 130., 150., 200., 250., 300., 600. };

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


  // weighted by fake rate objects
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

  // weighted with granular eta binned fakeRates
  TH1D *photon_pt_denominator_fake_rate_weighted_EB1 = new TH1D("photon_pt_denominator_fake_rate_weighted_EB1","",200,0,2000);
  TH1D *photon_pt_denominator_fake_rate_weighted_EE1 = new TH1D("photon_pt_denominator_fake_rate_weighted_EE1","",200,0,2000);
  photon_pt_denominator_fake_rate_weighted_EB1->Sumw2();
  photon_pt_denominator_fake_rate_weighted_EE1->Sumw2();
  TH1D *photon_pt_denominator_fake_rate_weighted_EB2 = new TH1D("photon_pt_denominator_fake_rate_weighted_EB2","",200,0,2000);
  TH1D *photon_pt_denominator_fake_rate_weighted_EE2 = new TH1D("photon_pt_denominator_fake_rate_weighted_EE2","",200,0,2000);
  photon_pt_denominator_fake_rate_weighted_EB2->Sumw2();
  photon_pt_denominator_fake_rate_weighted_EE2->Sumw2();

  TH1D *photon_eta_denominator_fake_rate_weighted_EB1 = new TH1D("photon_eta_denominator_fake_rate_weighted_EB1","",200,0,2000);
  TH1D *photon_eta_denominator_fake_rate_weighted_EE1 = new TH1D("photon_eta_denominator_fake_rate_weighted_EE1","",200,0,2000);
  photon_eta_denominator_fake_rate_weighted_EB1->Sumw2();
  photon_eta_denominator_fake_rate_weighted_EE1->Sumw2();
  TH1D *photon_eta_denominator_fake_rate_weighted_EB2 = new TH1D("photon_eta_denominator_fake_rate_weighted_EB2","",200,0,2000);
  TH1D *photon_eta_denominator_fake_rate_weighted_EE2 = new TH1D("photon_eta_denominator_fake_rate_weighted_EE2","",200,0,2000);
  photon_eta_denominator_fake_rate_weighted_EB2->Sumw2();
  photon_eta_denominator_fake_rate_weighted_EE2->Sumw2();

  TH1D *photon_phi_denominator_fake_rate_weighted_EB1 = new TH1D("photon_phi_denominator_fake_rate_weighted_EB1","",200,0,2000);
  TH1D *photon_phi_denominator_fake_rate_weighted_EE1 = new TH1D("photon_phi_denominator_fake_rate_weighted_EE1","",200,0,2000);
  photon_phi_denominator_fake_rate_weighted_EB1->Sumw2();
  photon_phi_denominator_fake_rate_weighted_EE1->Sumw2();
  TH1D *photon_phi_denominator_fake_rate_weighted_EB2 = new TH1D("photon_phi_denominator_fake_rate_weighted_EB2","",200,0,2000);
  TH1D *photon_phi_denominator_fake_rate_weighted_EE2 = new TH1D("photon_phi_denominator_fake_rate_weighted_EE2","",200,0,2000);
  photon_phi_denominator_fake_rate_weighted_EB2->Sumw2();
  photon_phi_denominator_fake_rate_weighted_EE2->Sumw2();

  // Single Histogram for EB / EE but granular eta-binned fake rates
  TH1D *photon_pt_denominator_fake_rate_weighted_gran_EB = new TH1D("photon_pt_denominator_fake_rate_weighted_gran_EB","",200,0,2000);
  TH1D *photon_pt_denominator_fake_rate_weighted_gran_EE = new TH1D("photon_pt_denominator_fake_rate_weighted_gran_EE","",200,0,2000);
  photon_pt_denominator_fake_rate_weighted_gran_EB->Sumw2();
  photon_pt_denominator_fake_rate_weighted_gran_EE->Sumw2();
  TH1D *photon_eta_denominator_fake_rate_weighted_gran_EB = new TH1D("photon_eta_denominator_fake_rate_weighted_gran_EB","",100,-5,5);
  TH1D *photon_eta_denominator_fake_rate_weighted_gran_EE = new TH1D("photon_eta_denominator_fake_rate_weighted_gran_EE","",100,-5,5);
  photon_eta_denominator_fake_rate_weighted_gran_EB->Sumw2();
  photon_eta_denominator_fake_rate_weighted_gran_EE->Sumw2();
  TH1D *photon_phi_denominator_fake_rate_weighted_gran_EB = new TH1D("photon_phi_denominator_fake_rate_weighted_gran_EB","",100,-5,5);
  TH1D *photon_phi_denominator_fake_rate_weighted_gran_EE = new TH1D("photon_phi_denominator_fake_rate_weighted_gran_EE","",100,-5,5);
  photon_phi_denominator_fake_rate_weighted_gran_EB->Sumw2();
  photon_phi_denominator_fake_rate_weighted_gran_EE->Sumw2();

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
    // bool is_chIso_numerator_object = Photon_isNumeratorObjCand && Photon_passSieie;
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

    // denominator objects not in pt bins
    if (is_denominator_object) {
      // EB
      if (fabs(Photon_scEta) < 1.4442) {
	       photon_pt_denominator_fake_rate_weighted_EB->Fill(Photon_pt,Event_weightAll*FakeRateEB(Photon_pt));
	       photon_eta_denominator_fake_rate_weighted_EB->Fill(Photon_eta,Event_weightAll*FakeRateEB(Photon_pt));
	       photon_phi_denominator_fake_rate_weighted_EB->Fill(Photon_phi,Event_weightAll*FakeRateEB(Photon_pt));
      }
      // EE
      if (1.566 < fabs(Photon_scEta) && fabs(Photon_scEta) < 2.5) {
	       photon_pt_denominator_fake_rate_weighted_EE->Fill(Photon_pt,Event_weightAll*FakeRateEE(Photon_pt));
	       photon_eta_denominator_fake_rate_weighted_EE->Fill(Photon_eta,Event_weightAll*FakeRateEE(Photon_pt));
	       photon_phi_denominator_fake_rate_weighted_EE->Fill(Photon_phi,Event_weightAll*FakeRateEE(Photon_pt));
      }
      // Granular Eta-binned FakeRate Reweighting
      // EB1 - inner barrel
      // if ( fabs(Photon_scEta) < 0.7221 ){
      //   photon_pt_denominator_fake_rate_weighted_EB1->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      //   photon_eta_denominator_fake_rate_weighted_EB1->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      //   photon_phi_denominator_fake_rate_weighted_EB1->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      //
      //   photon_pt_denominator_fake_rate_weighted_gran_EB->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      //   photon_eta_denominator_fake_rate_weighted_gran_EB->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      //   photon_phi_denominator_fake_rate_weighted_gran_EB->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      // }
      // if ( (0.7221 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ){
      //   photon_pt_denominator_fake_rate_weighted_EB2->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      //   photon_eta_denominator_fake_rate_weighted_EB2->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      //   photon_phi_denominator_fake_rate_weighted_EB2->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      //
      //   photon_pt_denominator_fake_rate_weighted_gran_EB->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      //   photon_eta_denominator_fake_rate_weighted_gran_EB->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      //   photon_phi_denominator_fake_rate_weighted_gran_EB->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      // }
      // if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.033) ){
      //   photon_pt_denominator_fake_rate_weighted_EE1->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      //   photon_eta_denominator_fake_rate_weighted_EE1->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      //   photon_phi_denominator_fake_rate_weighted_EE1->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      //
      //   photon_pt_denominator_fake_rate_weighted_gran_EE->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      //   photon_eta_denominator_fake_rate_weighted_gran_EE->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      //   photon_phi_denominator_fake_rate_weighted_gran_EE->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      // }
      // if ( (2.033 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ){
      //   photon_pt_denominator_fake_rate_weighted_EE2->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      //   photon_eta_denominator_fake_rate_weighted_EE2->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      //   photon_phi_denominator_fake_rate_weighted_EE2->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      //
      //   photon_pt_denominator_fake_rate_weighted_gran_EE->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      //   photon_eta_denominator_fake_rate_weighted_gran_EE->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      //   photon_phi_denominator_fake_rate_weighted_gran_EE->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      // } // end EE2

      // Granular Eta-binned FakeRate Reweighting V2
      // EE - split into inner, middle, outer
      // EB mildly adjusted split inner, outer
      if ( fabs(Photon_scEta) < 1.000 ){
        photon_pt_denominator_fake_rate_weighted_gran_EB->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
        photon_eta_denominator_fake_rate_weighted_gran_EB->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
        photon_phi_denominator_fake_rate_weighted_gran_EB->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB1" ));
      } // EB inner
      if ( (1.000 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.4442) ){
        photon_pt_denominator_fake_rate_weighted_gran_EB->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
        photon_eta_denominator_fake_rate_weighted_gran_EB->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
        photon_phi_denominator_fake_rate_weighted_gran_EB->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EB2" ));
      } // EB outer
      if ( (1.566 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 1.8773) ){
        photon_pt_denominator_fake_rate_weighted_gran_EE->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
        photon_eta_denominator_fake_rate_weighted_gran_EE->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
        photon_phi_denominator_fake_rate_weighted_gran_EE->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE1" ));
      } // EE inner
      if ( (1.8773 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.1887) ){
        photon_pt_denominator_fake_rate_weighted_gran_EE->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
        photon_eta_denominator_fake_rate_weighted_gran_EE->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
        photon_phi_denominator_fake_rate_weighted_gran_EE->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE2" ));
      } // EE middle
      if ( (2.1887 < fabs(Photon_scEta)) && (fabs(Photon_scEta) < 2.5) ){
        photon_pt_denominator_fake_rate_weighted_gran_EE->Fill(Photon_pt,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE3" ));
        photon_eta_denominator_fake_rate_weighted_gran_EE->Fill(Photon_eta,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE3" ));
        photon_phi_denominator_fake_rate_weighted_gran_EE->Fill(Photon_phi,Event_weightAll*FakeRateEtaBinned(Photon_pt, "EE3" ));
      } // EE outer

    } // end if denominator object
  } // end loop over entries

  std::cout << std::endl;
  std::cout << "Number of numerator photons: " << nNumerator << std::endl;
  std::cout << " ...passing sipip cut      : " << nNumerator_passSipipCut << std::endl;
  std::cout << std::endl;

  // create output file
  TFile file_out(filename,"RECREATE");

  // write denominator histograms
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

  // granular eta-binned fake rate
  photon_pt_denominator_fake_rate_weighted_EB1->Write();
  photon_pt_denominator_fake_rate_weighted_EE1->Write();
  std::cout << photon_pt_denominator_fake_rate_weighted_EB1->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EB1->Integral() << std::endl;
  std::cout << photon_pt_denominator_fake_rate_weighted_EE1->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EE1->Integral() << std::endl;
  photon_eta_denominator_fake_rate_weighted_EB1->Write();
  photon_eta_denominator_fake_rate_weighted_EE1->Write();
  std::cout << photon_eta_denominator_fake_rate_weighted_EB1->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EB1->Integral() << std::endl;
  std::cout << photon_eta_denominator_fake_rate_weighted_EE1->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EE1->Integral() << std::endl;
  photon_phi_denominator_fake_rate_weighted_EB1->Write();
  photon_phi_denominator_fake_rate_weighted_EE1->Write();
  std::cout << photon_phi_denominator_fake_rate_weighted_EB1->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EB1->Integral() << std::endl;
  std::cout << photon_phi_denominator_fake_rate_weighted_EE1->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EE1->Integral() << std::endl;

  photon_pt_denominator_fake_rate_weighted_EB2->Write();
  photon_pt_denominator_fake_rate_weighted_EE2->Write();
  std::cout << photon_pt_denominator_fake_rate_weighted_EB2->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EB2->Integral() << std::endl;
  std::cout << photon_pt_denominator_fake_rate_weighted_EE2->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_EE2->Integral() << std::endl;
  photon_eta_denominator_fake_rate_weighted_EB2->Write();
  photon_eta_denominator_fake_rate_weighted_EE2->Write();
  std::cout << photon_eta_denominator_fake_rate_weighted_EB2->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EB2->Integral() << std::endl;
  std::cout << photon_eta_denominator_fake_rate_weighted_EE2->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_EE2->Integral() << std::endl;
  photon_phi_denominator_fake_rate_weighted_EB2->Write();
  photon_phi_denominator_fake_rate_weighted_EE2->Write();
  std::cout << photon_phi_denominator_fake_rate_weighted_EB2->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EB2->Integral() << std::endl;
  std::cout << photon_phi_denominator_fake_rate_weighted_EE2->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_EE2->Integral() << std::endl;

  // granular eta-binned fake rate combined
  photon_pt_denominator_fake_rate_weighted_gran_EB->Write();
  photon_pt_denominator_fake_rate_weighted_gran_EE->Write();
  std::cout << photon_pt_denominator_fake_rate_weighted_gran_EB->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_gran_EB->Integral() << std::endl;
  std::cout << photon_pt_denominator_fake_rate_weighted_gran_EE->GetName() << "\t integral: " << photon_pt_denominator_fake_rate_weighted_gran_EE->Integral() << std::endl;
  photon_eta_denominator_fake_rate_weighted_gran_EB->Write();
  photon_eta_denominator_fake_rate_weighted_gran_EE->Write();
  std::cout << photon_eta_denominator_fake_rate_weighted_gran_EB->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_gran_EB->Integral() << std::endl;
  std::cout << photon_eta_denominator_fake_rate_weighted_gran_EE->GetName() << "\t integral: " << photon_eta_denominator_fake_rate_weighted_gran_EE->Integral() << std::endl;
  photon_phi_denominator_fake_rate_weighted_gran_EB->Write();
  photon_phi_denominator_fake_rate_weighted_gran_EE->Write();
  std::cout << photon_phi_denominator_fake_rate_weighted_gran_EB->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_gran_EB->Integral() << std::endl;
  std::cout << photon_phi_denominator_fake_rate_weighted_gran_EE->GetName() << "\t integral: " << photon_phi_denominator_fake_rate_weighted_gran_EE->Integral() << std::endl;

  file_out.ls();
  file_out.Close();

} // end of Loop()


double MCFakeRateClosureTestReweight::FakeRateEB(double pt) {
  double p0 = 0.00401543257042;
  double p1 = 85.57002275698491;
  double p2 = 1.71203116120994;
  // add getFakeRate method from Chris (2016, 2017, 2018)
  if (m_year == 2016 or m_year == 2017 or m_year == 2018){
    return m_fakeRate->getFakeRateClosureTest(pt, "EB", m_year);
  }
  return p0+p1/std::pow(pt,p2);
}

double MCFakeRateClosureTestReweight::FakeRateEE(double pt) {
  double p0 = -0.15299002741780;
  double p1 = 0.63378808277185;
  double p2 = 0.21130650931470;
  // add getFakeRate method from Chris (2016, 2017, 2018)
  if (m_year == 2016 or m_year == 2017 or m_year == 2018){
    return m_fakeRate->getFakeRateClosureTest(pt, "EE", m_year);
  }
  return p0+p1/std::pow(pt,p2);
}

double MCFakeRateClosureTestReweight::FakeRateEtaBinned(double pt, std::string region) {
  return m_fakeRate->getFakeRateClosureTest(pt, region, m_year);
}
