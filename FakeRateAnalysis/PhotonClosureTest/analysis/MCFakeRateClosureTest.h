//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar  1 10:11:41 2017 by ROOT version 6.02/13
// from TTree fTree/PhotonTree
// found on file: root://cmseos.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_closure_test/QCD_merged_ntuples/diphoton_fake_rate_closure_test_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root
//////////////////////////////////////////////////////////

#ifndef MCFakeRateClosureTest_h
#define MCFakeRateClosureTest_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class MCFakeRateClosureTestBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Long64_t        Event_run;
   Long64_t        Event_LS;
   Long64_t        Event_evnum;
   Long64_t        Event_processid;
   Long64_t        Event_bx;
   Long64_t        Event_orbit;
   Float_t         Event_ptHat;
   Float_t         Event_alphaqcd;
   Float_t         Event_alphaqed;
   Float_t         Event_qscale;
   Float_t         Event_x1;
   Float_t         Event_x2;
   Float_t         Event_pdf1;
   Float_t         Event_pdf2;
   Float_t         Event_weight0;
   Float_t         Event_weight;
   Float_t         Event_weightPuUp;
   Float_t         Event_weightPu;
   Float_t         Event_weightPuDown;
   Float_t         Event_weightLumi;
   Float_t         Event_weightAll;
   Int_t           Event_interactingParton1PdgId;
   Int_t           Event_interactingParton2PdgId;
   Int_t           Event_pdf_id1;
   Int_t           Event_pdf_id2;
   Int_t           Event_npv_true;
   Bool_t          Event_beamHaloIDLoose;
   Bool_t          Event_beamHaloIDTight;
   Bool_t          Event_beamHaloIDTight2015;
   Int_t           TriggerBit_HLT_AK4PFDJet60_Eta2p1ForPPRef;
   Int_t           TriggerBit_HLT_AK4PFDJet80_Eta2p1ForPPRef;
   Int_t           TriggerBit_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45;
   Int_t           TriggerBit_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20;
   Int_t           TriggerBit_HLT_AK8DiPFJet250_200_TrimMass30;
   Int_t           TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3;
   Int_t           TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45;
   Int_t           TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20;
   Int_t           TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30;
   Int_t           TriggerBit_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45;
   Int_t           TriggerBit_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20;
   Int_t           TriggerBit_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50;
   Int_t           TriggerBit_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50;
   Int_t           TriggerBit_HLT_AK8PFJet140;
   Int_t           TriggerBit_HLT_AK8PFJet200;
   Int_t           TriggerBit_HLT_AK8PFJet260;
   Int_t           TriggerBit_HLT_AK8PFJet320;
   Int_t           TriggerBit_HLT_AK8PFJet360TrimMod_Mass30;
   Int_t           TriggerBit_HLT_AK8PFJet360_TrimMass30;
   Int_t           TriggerBit_HLT_AK8PFJet400;
   Int_t           TriggerBit_HLT_AK8PFJet40;
   Int_t           TriggerBit_HLT_AK8PFJet450;
   Int_t           TriggerBit_HLT_AK8PFJet500;
   Int_t           TriggerBit_HLT_AK8PFJet60;
   Int_t           TriggerBit_HLT_AK8PFJet80;
   Int_t           TriggerBit_HLT_BTagMu_DiJet110_Mu5;
   Int_t           TriggerBit_HLT_BTagMu_DiJet20_Mu5;
   Int_t           TriggerBit_HLT_BTagMu_DiJet40_Mu5;
   Int_t           TriggerBit_HLT_BTagMu_DiJet70_Mu5;
   Int_t           TriggerBit_HLT_BTagMu_Jet300_Mu5;
   Int_t           TriggerBit_HLT_CaloJet500_NoJetID;
   Int_t           TriggerBit_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7;
   Int_t           TriggerBit_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose;
   Int_t           TriggerBit_HLT_DiCaloJetAve140;
   Int_t           TriggerBit_HLT_DiCaloJetAve200;
   Int_t           TriggerBit_HLT_DiCaloJetAve260;
   Int_t           TriggerBit_HLT_DiCaloJetAve320;
   Int_t           TriggerBit_HLT_DiCaloJetAve400;
   Int_t           TriggerBit_HLT_DiCaloJetAve40;
   Int_t           TriggerBit_HLT_DiCaloJetAve500;
   Int_t           TriggerBit_HLT_DiCaloJetAve60;
   Int_t           TriggerBit_HLT_DiCaloJetAve80;
   Int_t           TriggerBit_HLT_DiCentralPFJet170_CFMax0p1;
   Int_t           TriggerBit_HLT_DiCentralPFJet170;
   Int_t           TriggerBit_HLT_DiCentralPFJet220_CFMax0p3;
   Int_t           TriggerBit_HLT_DiCentralPFJet330_CFMax0p5;
   Int_t           TriggerBit_HLT_DiCentralPFJet430;
   Int_t           TriggerBit_HLT_DiCentralPFJet70_PFMET120_NoiseCleaned;
   Int_t           TriggerBit_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Int_t           TriggerBit_HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140;
   Int_t           TriggerBit_HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80;
   Int_t           TriggerBit_HLT_DiPFJetAve100_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve140;
   Int_t           TriggerBit_HLT_DiPFJetAve160_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve200;
   Int_t           TriggerBit_HLT_DiPFJetAve220_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve260;
   Int_t           TriggerBit_HLT_DiPFJetAve300_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve30_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve320;
   Int_t           TriggerBit_HLT_DiPFJetAve400;
   Int_t           TriggerBit_HLT_DiPFJetAve40;
   Int_t           TriggerBit_HLT_DiPFJetAve500;
   Int_t           TriggerBit_HLT_DiPFJetAve60_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve60;
   Int_t           TriggerBit_HLT_DiPFJetAve80_HFJEC;
   Int_t           TriggerBit_HLT_DiPFJetAve80;
   Int_t           TriggerBit_HLT_Dimuon0_Jpsi_Muon;
   Int_t           TriggerBit_HLT_Dimuon0_Upsilon_Muon;
   Int_t           TriggerBit_HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing;
   Int_t           TriggerBit_HLT_Dimuon0er16_Jpsi_NoVertexing;
   Int_t           TriggerBit_HLT_Dimuon13_PsiPrime;
   Int_t           TriggerBit_HLT_Dimuon13_Upsilon;
   Int_t           TriggerBit_HLT_Dimuon20_Jpsi;
   Int_t           TriggerBit_HLT_Dimuon6_Jpsi_NoVertexing;
   Int_t           TriggerBit_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
   Int_t           TriggerBit_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
   Int_t           TriggerBit_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70;
   Int_t           TriggerBit_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Int_t           TriggerBit_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Int_t           TriggerBit_HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55;
   Int_t           TriggerBit_HLT_DoubleEle24_22_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf;
   Int_t           TriggerBit_HLT_DoubleEle25_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL_MW;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL;
   Int_t           TriggerBit_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerBit_HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300;
   Int_t           TriggerBit_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250;
   Int_t           TriggerBit_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300;
   Int_t           TriggerBit_HLT_DoubleIsoMu17_eta2p1;
   Int_t           TriggerBit_HLT_DoubleJet90_Double30_DoubleCSV0p5;
   Int_t           TriggerBit_HLT_DoubleJet90_Double30_TripleCSV0p5;
   Int_t           TriggerBit_HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerBit_HLT_DoubleMu23NoFiltersNoVtxDisplaced;
   Int_t           TriggerBit_HLT_DoubleMu28NoFiltersNoVtxDisplaced;
   Int_t           TriggerBit_HLT_DoubleMu33NoFiltersNoVtx;
   Int_t           TriggerBit_HLT_DoubleMu38NoFiltersNoVtx;
   Int_t           TriggerBit_HLT_DoubleMu4_3_Bs;
   Int_t           TriggerBit_HLT_DoubleMu4_3_Jpsi_Displaced;
   Int_t           TriggerBit_HLT_DoubleMu4_JpsiTrk_Displaced;
   Int_t           TriggerBit_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
   Int_t           TriggerBit_HLT_DoubleMu4_PsiPrimeTrk_Displaced;
   Int_t           TriggerBit_HLT_DoubleMu8_Mass8_PFHT300;
   Int_t           TriggerBit_HLT_DoublePhoton40;
   Int_t           TriggerBit_HLT_DoublePhoton50;
   Int_t           TriggerBit_HLT_DoublePhoton60;
   Int_t           TriggerBit_HLT_DoublePhoton85;
   Int_t           TriggerBit_HLT_ECALHT800;
   Int_t           TriggerBit_HLT_Ele105_CaloIdVT_GsfTrkIdT;
   Int_t           TriggerBit_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF;
   Int_t           TriggerBit_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13;
   Int_t           TriggerBit_HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV;
   Int_t           TriggerBit_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Ele12_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_Ele12_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerBit_HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400;
   Int_t           TriggerBit_HLT_Ele15_IsoVVVL_PFHT400_PFMET70;
   Int_t           TriggerBit_HLT_Ele15_IsoVVVL_PFHT600;
   Int_t           TriggerBit_HLT_Ele15_PFHT300;
   Int_t           TriggerBit_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Int_t           TriggerBit_HLT_Ele17_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerBit_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele17_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           TriggerBit_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele18_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_Ele18_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerBit_HLT_Ele20WP60_Ele8_Mass55;
   Int_t           TriggerBit_HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerBit_HLT_Ele22_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele23_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_Ele23_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerBit_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded;
   Int_t           TriggerBit_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           TriggerBit_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Ele25WP60_SC4_Mass55;
   Int_t           TriggerBit_HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW;
   Int_t           TriggerBit_HLT_Ele27_HighEta_Ele20_Mass55;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_HT200;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
   Int_t           TriggerBit_HLT_Ele27_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_Ele30WP60_Ele8_Mass55;
   Int_t           TriggerBit_HLT_Ele30WP60_SC4_Mass55;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
   Int_t           TriggerBit_HLT_Ele32_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele33_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_Ele33_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerBit_HLT_Ele35_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_Ele40_eta2p1_WP85_Gsf;
   Int_t           TriggerBit_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50;
   Int_t           TriggerBit_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerBit_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerBit_HLT_HT2000;
   Int_t           TriggerBit_HLT_HT200_DiJet90_AlphaT0p57;
   Int_t           TriggerBit_HLT_HT200;
   Int_t           TriggerBit_HLT_HT2500;
   Int_t           TriggerBit_HLT_HT250_DiJet90_AlphaT0p55;
   Int_t           TriggerBit_HLT_HT250_DisplacedDijet40_DisplacedTrack;
   Int_t           TriggerBit_HLT_HT250;
   Int_t           TriggerBit_HLT_HT275;
   Int_t           TriggerBit_HLT_HT300_DiJet90_AlphaT0p53;
   Int_t           TriggerBit_HLT_HT300;
   Int_t           TriggerBit_HLT_HT325;
   Int_t           TriggerBit_HLT_HT350_DiJet90_AlphaT0p52;
   Int_t           TriggerBit_HLT_HT350_DisplacedDijet40_DisplacedTrack;
   Int_t           TriggerBit_HLT_HT350_DisplacedDijet80_DisplacedTrack;
   Int_t           TriggerBit_HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack;
   Int_t           TriggerBit_HLT_HT350;
   Int_t           TriggerBit_HLT_HT400_DiJet90_AlphaT0p51;
   Int_t           TriggerBit_HLT_HT400_DisplacedDijet40_Inclusive;
   Int_t           TriggerBit_HLT_HT400;
   Int_t           TriggerBit_HLT_HT425;
   Int_t           TriggerBit_HLT_HT500_DisplacedDijet40_Inclusive;
   Int_t           TriggerBit_HLT_HT550_DisplacedDijet40_Inclusive;
   Int_t           TriggerBit_HLT_HT575;
   Int_t           TriggerBit_HLT_HT650_DisplacedDijet80_Inclusive;
   Int_t           TriggerBit_HLT_HT750_DisplacedDijet80_Inclusive;
   Int_t           TriggerBit_HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1;
   Int_t           TriggerBit_HLT_IsoMu16_eta2p1_CaloMET30;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1_TriCentralPFJet40;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_LooseIsoPFTau20;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_TriCentralPFJet40;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1;
   Int_t           TriggerBit_HLT_IsoMu27;
   Int_t           TriggerBit_HLT_IsoTkMu20_eta2p1;
   Int_t           TriggerBit_HLT_IsoTkMu24_eta2p1;
   Int_t           TriggerBit_HLT_IsoTkMu27;
   Int_t           TriggerBit_HLT_JetE30_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_JetE30_NoBPTX;
   Int_t           TriggerBit_HLT_JetE50_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_JetE70_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_L1_TripleJet_VBF;
   Int_t           TriggerBit_HLT_L2DoubleMu23_NoVertex;
   Int_t           TriggerBit_HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10;
   Int_t           TriggerBit_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10;
   Int_t           TriggerBit_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_L2Mu10_NoVertex_NoBPTX;
   Int_t           TriggerBit_HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo;
   Int_t           TriggerBit_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120;
   Int_t           TriggerBit_HLT_LooseIsoPFTau50_Trk30_eta2p1;
   Int_t           TriggerBit_HLT_MET75_IsoTrk50;
   Int_t           TriggerBit_HLT_MET90_IsoTrk50;
   Int_t           TriggerBit_HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned;
   Int_t           TriggerBit_HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned;
   Int_t           TriggerBit_HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned;
   Int_t           TriggerBit_HLT_Mu10_CentralPFJet40_BTagCSV;
   Int_t           TriggerBit_HLT_Mu12_Photon25_CaloIdL_L1ISO;
   Int_t           TriggerBit_HLT_Mu12_Photon25_CaloIdL_L1OR;
   Int_t           TriggerBit_HLT_Mu12_Photon25_CaloIdL;
   Int_t           TriggerBit_HLT_Mu14er_PFMET120_NoiseCleaned;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_PFHT400_PFMET70;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_PFHT600;
   Int_t           TriggerBit_HLT_Mu15_PFHT300;
   Int_t           TriggerBit_HLT_Mu16_eta2p1_CaloMET30;
   Int_t           TriggerBit_HLT_Mu17_Mu8_DZ;
   Int_t           TriggerBit_HLT_Mu17_Mu8_SameSign_DPhi;
   Int_t           TriggerBit_HLT_Mu17_Mu8_SameSign;
   Int_t           TriggerBit_HLT_Mu17_Photon30_CaloIdL_L1ISO;
   Int_t           TriggerBit_HLT_Mu17_Photon35_CaloIdL_L1ISO;
   Int_t           TriggerBit_HLT_Mu17_TkMu8_DZ;
   Int_t           TriggerBit_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Int_t           TriggerBit_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Int_t           TriggerBit_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
   Int_t           TriggerBit_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
   Int_t           TriggerBit_HLT_Mu17_TrkIsoVVL;
   Int_t           TriggerBit_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Mu24_TrkIsoVVL;
   Int_t           TriggerBit_HLT_Mu24_eta2p1;
   Int_t           TriggerBit_HLT_Mu25_TkMu0_dEta18_Onia;
   Int_t           TriggerBit_HLT_Mu27;
   Int_t           TriggerBit_HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL;
   Int_t           TriggerBit_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerBit_HLT_Mu30_TkMu11;
   Int_t           TriggerBit_HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL;
   Int_t           TriggerBit_HLT_Mu34_TrkIsoVVL;
   Int_t           TriggerBit_HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL;
   Int_t           TriggerBit_HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned;
   Int_t           TriggerBit_HLT_Mu40_eta2p1_PFJet200_PFJet50;
   Int_t           TriggerBit_HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL;
   Int_t           TriggerBit_HLT_Mu45_eta2p1;
   Int_t           TriggerBit_HLT_Mu50;
   Int_t           TriggerBit_HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07;
   Int_t           TriggerBit_HLT_Mu6_PFHT200_PFMET125_NoiseCleaned;
   Int_t           TriggerBit_HLT_Mu7p5_L2Mu2_Jpsi;
   Int_t           TriggerBit_HLT_Mu7p5_L2Mu2_Upsilon;
   Int_t           TriggerBit_HLT_Mu7p5_Track2_Jpsi;
   Int_t           TriggerBit_HLT_Mu7p5_Track2_Upsilon;
   Int_t           TriggerBit_HLT_Mu7p5_Track3p5_Jpsi;
   Int_t           TriggerBit_HLT_Mu7p5_Track3p5_Upsilon;
   Int_t           TriggerBit_HLT_Mu7p5_Track7_Jpsi;
   Int_t           TriggerBit_HLT_Mu7p5_Track7_Upsilon;
   Int_t           TriggerBit_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Int_t           TriggerBit_HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300;
   Int_t           TriggerBit_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerBit_HLT_Mu8_TrkIsoVVL;
   Int_t           TriggerBit_HLT_PFHT125;
   Int_t           TriggerBit_HLT_PFHT200;
   Int_t           TriggerBit_HLT_PFHT250;
   Int_t           TriggerBit_HLT_PFHT300;
   Int_t           TriggerBit_HLT_PFHT350_PFMET120_NoiseCleaned;
   Int_t           TriggerBit_HLT_PFHT350;
   Int_t           TriggerBit_HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72;
   Int_t           TriggerBit_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056;
   Int_t           TriggerBit_HLT_PFHT400_SixJet30;
   Int_t           TriggerBit_HLT_PFHT400;
   Int_t           TriggerBit_HLT_PFHT450_SixJet40_BTagCSV_p056;
   Int_t           TriggerBit_HLT_PFHT450_SixJet40_PFBTagCSV0p72;
   Int_t           TriggerBit_HLT_PFHT450_SixJet40;
   Int_t           TriggerBit_HLT_PFHT475;
   Int_t           TriggerBit_HLT_PFHT550_4JetPt50;
   Int_t           TriggerBit_HLT_PFHT550_4Jet;
   Int_t           TriggerBit_HLT_PFHT600;
   Int_t           TriggerBit_HLT_PFHT650_4JetPt50;
   Int_t           TriggerBit_HLT_PFHT650_4Jet;
   Int_t           TriggerBit_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5;
   Int_t           TriggerBit_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5;
   Int_t           TriggerBit_HLT_PFHT650;
   Int_t           TriggerBit_HLT_PFHT750_4JetPt50;
   Int_t           TriggerBit_HLT_PFHT750_4Jet;
   Int_t           TriggerBit_HLT_PFHT800;
   Int_t           TriggerBit_HLT_PFHT900;
   Int_t           TriggerBit_HLT_PFJet140;
   Int_t           TriggerBit_HLT_PFJet200;
   Int_t           TriggerBit_HLT_PFJet260;
   Int_t           TriggerBit_HLT_PFJet320;
   Int_t           TriggerBit_HLT_PFJet400;
   Int_t           TriggerBit_HLT_PFJet40;
   Int_t           TriggerBit_HLT_PFJet450;
   Int_t           TriggerBit_HLT_PFJet500;
   Int_t           TriggerBit_HLT_PFJet60;
   Int_t           TriggerBit_HLT_PFJet80;
   Int_t           TriggerBit_HLT_PFMET120_NoiseCleaned_BTagCSV07;
   Int_t           TriggerBit_HLT_PFMET120_NoiseCleaned_Mu5;
   Int_t           TriggerBit_HLT_PFMET120_PFMHT120_IDLoose;
   Int_t           TriggerBit_HLT_PFMET170_NoiseCleaned;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon120;
   Int_t           TriggerBit_HLT_Photon125;
   Int_t           TriggerBit_HLT_Photon135_PFMET100_NoiseCleaned;
   Int_t           TriggerBit_HLT_Photon135_PFMET100;
   Int_t           TriggerBit_HLT_Photon135_PFMET40;
   Int_t           TriggerBit_HLT_Photon135_VBF;
   Int_t           TriggerBit_HLT_Photon150;
   Int_t           TriggerBit_HLT_Photon155_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon165_HE10;
   Int_t           TriggerBit_HLT_Photon165_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon175;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon22;
   Int_t           TriggerBit_HLT_Photon250_NoHE;
   Int_t           TriggerBit_HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60;
   Int_t           TriggerBit_HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5;
   Int_t           TriggerBit_HLT_Photon300_NoHE;
   Int_t           TriggerBit_HLT_Photon30_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon30_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon30;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon36;
   Int_t           TriggerBit_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65;
   Int_t           TriggerBit_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15;
   Int_t           TriggerBit_HLT_Photon500;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon50;
   Int_t           TriggerBit_HLT_Photon600;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon75;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_HT300;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_PFHT500;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_PFHT600;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_Iso40;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_IsoM;
   Int_t           TriggerBit_HLT_Photon90;
   Int_t           TriggerBit_HLT_Physics;
   Int_t           TriggerBit_HLT_PixelTracks_Multiplicity110;
   Int_t           TriggerBit_HLT_PixelTracks_Multiplicity135;
   Int_t           TriggerBit_HLT_PixelTracks_Multiplicity160;
   Int_t           TriggerBit_HLT_PixelTracks_Multiplicity60;
   Int_t           TriggerBit_HLT_PixelTracks_Multiplicity85;
   Int_t           TriggerBit_HLT_QuadJet45_DoubleCSV0p5;
   Int_t           TriggerBit_HLT_QuadJet45_TripleCSV0p5;
   Int_t           TriggerBit_HLT_QuadMuon0_Dimuon0_Jpsi;
   Int_t           TriggerBit_HLT_QuadMuon0_Dimuon0_Upsilon;
   Int_t           TriggerBit_HLT_QuadPFJet_BTagCSV_VBF;
   Int_t           TriggerBit_HLT_QuadPFJet_VBF;
   Int_t           TriggerBit_HLT_Rsq0p36;
   Int_t           TriggerBit_HLT_RsqMR260_Rsq0p09_MR200_4jet;
   Int_t           TriggerBit_HLT_RsqMR260_Rsq0p09_MR200;
   Int_t           TriggerBit_HLT_RsqMR300_Rsq0p09_MR200_4jet;
   Int_t           TriggerBit_HLT_RsqMR300_Rsq0p09_MR200;
   Int_t           TriggerBit_HLT_SingleCentralPFJet170_CFMax0p1;
   Int_t           TriggerBit_HLT_TkMu24_eta2p1;
   Int_t           TriggerBit_HLT_TkMu27;
   Int_t           TriggerBit_HLT_TripleMu_12_10_5;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_DisplacedTrack;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_Hadronic;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_TightID_DisplacedTrack;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_TightID_Hadronic;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_VTightID_Hadronic;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack;
   Int_t           TriggerBit_HLT_VBF_DisplacedJet40_VVTightID_Hadronic;
   Int_t           TriggerBit_HLT_ZeroBias;
   Int_t           TriggerPrescale_HLT_AK4PFDJet60_Eta2p1ForPPRef;
   Int_t           TriggerPrescale_HLT_AK4PFDJet80_Eta2p1ForPPRef;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet250_200_TrimMass30;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30;
   Int_t           TriggerPrescale_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45;
   Int_t           TriggerPrescale_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20;
   Int_t           TriggerPrescale_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50;
   Int_t           TriggerPrescale_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50;
   Int_t           TriggerPrescale_HLT_AK8PFJet140;
   Int_t           TriggerPrescale_HLT_AK8PFJet200;
   Int_t           TriggerPrescale_HLT_AK8PFJet260;
   Int_t           TriggerPrescale_HLT_AK8PFJet320;
   Int_t           TriggerPrescale_HLT_AK8PFJet360TrimMod_Mass30;
   Int_t           TriggerPrescale_HLT_AK8PFJet360_TrimMass30;
   Int_t           TriggerPrescale_HLT_AK8PFJet400;
   Int_t           TriggerPrescale_HLT_AK8PFJet40;
   Int_t           TriggerPrescale_HLT_AK8PFJet450;
   Int_t           TriggerPrescale_HLT_AK8PFJet500;
   Int_t           TriggerPrescale_HLT_AK8PFJet60;
   Int_t           TriggerPrescale_HLT_AK8PFJet80;
   Int_t           TriggerPrescale_HLT_BTagMu_DiJet110_Mu5;
   Int_t           TriggerPrescale_HLT_BTagMu_DiJet20_Mu5;
   Int_t           TriggerPrescale_HLT_BTagMu_DiJet40_Mu5;
   Int_t           TriggerPrescale_HLT_BTagMu_DiJet70_Mu5;
   Int_t           TriggerPrescale_HLT_BTagMu_Jet300_Mu5;
   Int_t           TriggerPrescale_HLT_CaloJet500_NoJetID;
   Int_t           TriggerPrescale_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7;
   Int_t           TriggerPrescale_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve140;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve200;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve260;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve320;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve400;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve40;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve500;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve60;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve80;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet170_CFMax0p1;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet170;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet220_CFMax0p3;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet330_CFMax0p5;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet430;
   Int_t           TriggerPrescale_HLT_DiCentralPFJet70_PFMET120_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Int_t           TriggerPrescale_HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140;
   Int_t           TriggerPrescale_HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80;
   Int_t           TriggerPrescale_HLT_DiPFJetAve100_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve140;
   Int_t           TriggerPrescale_HLT_DiPFJetAve160_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve200;
   Int_t           TriggerPrescale_HLT_DiPFJetAve220_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve260;
   Int_t           TriggerPrescale_HLT_DiPFJetAve300_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve30_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve320;
   Int_t           TriggerPrescale_HLT_DiPFJetAve400;
   Int_t           TriggerPrescale_HLT_DiPFJetAve40;
   Int_t           TriggerPrescale_HLT_DiPFJetAve500;
   Int_t           TriggerPrescale_HLT_DiPFJetAve60_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve60;
   Int_t           TriggerPrescale_HLT_DiPFJetAve80_HFJEC;
   Int_t           TriggerPrescale_HLT_DiPFJetAve80;
   Int_t           TriggerPrescale_HLT_Dimuon0_Jpsi_Muon;
   Int_t           TriggerPrescale_HLT_Dimuon0_Upsilon_Muon;
   Int_t           TriggerPrescale_HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing;
   Int_t           TriggerPrescale_HLT_Dimuon0er16_Jpsi_NoVertexing;
   Int_t           TriggerPrescale_HLT_Dimuon13_PsiPrime;
   Int_t           TriggerPrescale_HLT_Dimuon13_Upsilon;
   Int_t           TriggerPrescale_HLT_Dimuon20_Jpsi;
   Int_t           TriggerPrescale_HLT_Dimuon6_Jpsi_NoVertexing;
   Int_t           TriggerPrescale_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
   Int_t           TriggerPrescale_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55;
   Int_t           TriggerPrescale_HLT_DoubleEle24_22_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf;
   Int_t           TriggerPrescale_HLT_DoubleEle25_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL_MW;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL;
   Int_t           TriggerPrescale_HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerPrescale_HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300;
   Int_t           TriggerPrescale_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250;
   Int_t           TriggerPrescale_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300;
   Int_t           TriggerPrescale_HLT_DoubleIsoMu17_eta2p1;
   Int_t           TriggerPrescale_HLT_DoubleJet90_Double30_DoubleCSV0p5;
   Int_t           TriggerPrescale_HLT_DoubleJet90_Double30_TripleCSV0p5;
   Int_t           TriggerPrescale_HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerPrescale_HLT_DoubleMu23NoFiltersNoVtxDisplaced;
   Int_t           TriggerPrescale_HLT_DoubleMu28NoFiltersNoVtxDisplaced;
   Int_t           TriggerPrescale_HLT_DoubleMu33NoFiltersNoVtx;
   Int_t           TriggerPrescale_HLT_DoubleMu38NoFiltersNoVtx;
   Int_t           TriggerPrescale_HLT_DoubleMu4_3_Bs;
   Int_t           TriggerPrescale_HLT_DoubleMu4_3_Jpsi_Displaced;
   Int_t           TriggerPrescale_HLT_DoubleMu4_JpsiTrk_Displaced;
   Int_t           TriggerPrescale_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
   Int_t           TriggerPrescale_HLT_DoubleMu4_PsiPrimeTrk_Displaced;
   Int_t           TriggerPrescale_HLT_DoubleMu8_Mass8_PFHT300;
   Int_t           TriggerPrescale_HLT_DoublePhoton40;
   Int_t           TriggerPrescale_HLT_DoublePhoton50;
   Int_t           TriggerPrescale_HLT_DoublePhoton60;
   Int_t           TriggerPrescale_HLT_DoublePhoton85;
   Int_t           TriggerPrescale_HLT_ECALHT800;
   Int_t           TriggerPrescale_HLT_Ele105_CaloIdVT_GsfTrkIdT;
   Int_t           TriggerPrescale_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF;
   Int_t           TriggerPrescale_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13;
   Int_t           TriggerPrescale_HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele12_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400;
   Int_t           TriggerPrescale_HLT_Ele15_IsoVVVL_PFHT400_PFMET70;
   Int_t           TriggerPrescale_HLT_Ele15_IsoVVVL_PFHT600;
   Int_t           TriggerPrescale_HLT_Ele15_PFHT300;
   Int_t           TriggerPrescale_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Int_t           TriggerPrescale_HLT_Ele17_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerPrescale_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele17_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           TriggerPrescale_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele18_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele18_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele20WP60_Ele8_Mass55;
   Int_t           TriggerPrescale_HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerPrescale_HLT_Ele22_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele23_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded;
   Int_t           TriggerPrescale_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           TriggerPrescale_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Ele25WP60_SC4_Mass55;
   Int_t           TriggerPrescale_HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW;
   Int_t           TriggerPrescale_HLT_Ele27_HighEta_Ele20_Mass55;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_HT200;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
   Int_t           TriggerPrescale_HLT_Ele27_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_Ele30WP60_Ele8_Mass55;
   Int_t           TriggerPrescale_HLT_Ele30WP60_SC4_Mass55;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
   Int_t           TriggerPrescale_HLT_Ele32_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele33_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele33_CaloId_TrackId_Iso_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele35_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_Ele40_eta2p1_WP85_Gsf;
   Int_t           TriggerPrescale_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50;
   Int_t           TriggerPrescale_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Int_t           TriggerPrescale_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Int_t           TriggerPrescale_HLT_HT2000;
   Int_t           TriggerPrescale_HLT_HT200_DiJet90_AlphaT0p57;
   Int_t           TriggerPrescale_HLT_HT200;
   Int_t           TriggerPrescale_HLT_HT2500;
   Int_t           TriggerPrescale_HLT_HT250_DiJet90_AlphaT0p55;
   Int_t           TriggerPrescale_HLT_HT250_DisplacedDijet40_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_HT250;
   Int_t           TriggerPrescale_HLT_HT275;
   Int_t           TriggerPrescale_HLT_HT300_DiJet90_AlphaT0p53;
   Int_t           TriggerPrescale_HLT_HT300;
   Int_t           TriggerPrescale_HLT_HT325;
   Int_t           TriggerPrescale_HLT_HT350_DiJet90_AlphaT0p52;
   Int_t           TriggerPrescale_HLT_HT350_DisplacedDijet40_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_HT350_DisplacedDijet80_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_HT350;
   Int_t           TriggerPrescale_HLT_HT400_DiJet90_AlphaT0p51;
   Int_t           TriggerPrescale_HLT_HT400_DisplacedDijet40_Inclusive;
   Int_t           TriggerPrescale_HLT_HT400;
   Int_t           TriggerPrescale_HLT_HT425;
   Int_t           TriggerPrescale_HLT_HT500_DisplacedDijet40_Inclusive;
   Int_t           TriggerPrescale_HLT_HT550_DisplacedDijet40_Inclusive;
   Int_t           TriggerPrescale_HLT_HT575;
   Int_t           TriggerPrescale_HLT_HT650_DisplacedDijet80_Inclusive;
   Int_t           TriggerPrescale_HLT_HT750_DisplacedDijet80_Inclusive;
   Int_t           TriggerPrescale_HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoMu16_eta2p1_CaloMET30;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1_TriCentralPFJet40;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_LooseIsoPFTau20;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_TriCentralPFJet40;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoMu27;
   Int_t           TriggerPrescale_HLT_IsoTkMu20_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoTkMu24_eta2p1;
   Int_t           TriggerPrescale_HLT_IsoTkMu27;
   Int_t           TriggerPrescale_HLT_JetE30_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_JetE30_NoBPTX;
   Int_t           TriggerPrescale_HLT_JetE50_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_JetE70_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_L1_TripleJet_VBF;
   Int_t           TriggerPrescale_HLT_L2DoubleMu23_NoVertex;
   Int_t           TriggerPrescale_HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10;
   Int_t           TriggerPrescale_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10;
   Int_t           TriggerPrescale_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_L2Mu10_NoVertex_NoBPTX;
   Int_t           TriggerPrescale_HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo;
   Int_t           TriggerPrescale_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120;
   Int_t           TriggerPrescale_HLT_LooseIsoPFTau50_Trk30_eta2p1;
   Int_t           TriggerPrescale_HLT_MET75_IsoTrk50;
   Int_t           TriggerPrescale_HLT_MET90_IsoTrk50;
   Int_t           TriggerPrescale_HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Mu10_CentralPFJet40_BTagCSV;
   Int_t           TriggerPrescale_HLT_Mu12_Photon25_CaloIdL_L1ISO;
   Int_t           TriggerPrescale_HLT_Mu12_Photon25_CaloIdL_L1OR;
   Int_t           TriggerPrescale_HLT_Mu12_Photon25_CaloIdL;
   Int_t           TriggerPrescale_HLT_Mu14er_PFMET120_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_PFHT400_PFMET70;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_PFHT600;
   Int_t           TriggerPrescale_HLT_Mu15_PFHT300;
   Int_t           TriggerPrescale_HLT_Mu16_eta2p1_CaloMET30;
   Int_t           TriggerPrescale_HLT_Mu17_Mu8_DZ;
   Int_t           TriggerPrescale_HLT_Mu17_Mu8_SameSign_DPhi;
   Int_t           TriggerPrescale_HLT_Mu17_Mu8_SameSign;
   Int_t           TriggerPrescale_HLT_Mu17_Photon30_CaloIdL_L1ISO;
   Int_t           TriggerPrescale_HLT_Mu17_Photon35_CaloIdL_L1ISO;
   Int_t           TriggerPrescale_HLT_Mu17_TkMu8_DZ;
   Int_t           TriggerPrescale_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Int_t           TriggerPrescale_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
   Int_t           TriggerPrescale_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_Mu17_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Mu24_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_Mu24_eta2p1;
   Int_t           TriggerPrescale_HLT_Mu25_TkMu0_dEta18_Onia;
   Int_t           TriggerPrescale_HLT_Mu27;
   Int_t           TriggerPrescale_HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL;
   Int_t           TriggerPrescale_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL;
   Int_t           TriggerPrescale_HLT_Mu30_TkMu11;
   Int_t           TriggerPrescale_HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL;
   Int_t           TriggerPrescale_HLT_Mu34_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL;
   Int_t           TriggerPrescale_HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Mu40_eta2p1_PFJet200_PFJet50;
   Int_t           TriggerPrescale_HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL;
   Int_t           TriggerPrescale_HLT_Mu45_eta2p1;
   Int_t           TriggerPrescale_HLT_Mu50;
   Int_t           TriggerPrescale_HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07;
   Int_t           TriggerPrescale_HLT_Mu6_PFHT200_PFMET125_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Mu7p5_L2Mu2_Jpsi;
   Int_t           TriggerPrescale_HLT_Mu7p5_L2Mu2_Upsilon;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track2_Jpsi;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track2_Upsilon;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track3p5_Jpsi;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track3p5_Upsilon;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track7_Jpsi;
   Int_t           TriggerPrescale_HLT_Mu7p5_Track7_Upsilon;
   Int_t           TriggerPrescale_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Int_t           TriggerPrescale_HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300;
   Int_t           TriggerPrescale_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Int_t           TriggerPrescale_HLT_Mu8_TrkIsoVVL;
   Int_t           TriggerPrescale_HLT_PFHT125;
   Int_t           TriggerPrescale_HLT_PFHT200;
   Int_t           TriggerPrescale_HLT_PFHT250;
   Int_t           TriggerPrescale_HLT_PFHT300;
   Int_t           TriggerPrescale_HLT_PFHT350_PFMET120_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_PFHT350;
   Int_t           TriggerPrescale_HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72;
   Int_t           TriggerPrescale_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056;
   Int_t           TriggerPrescale_HLT_PFHT400_SixJet30;
   Int_t           TriggerPrescale_HLT_PFHT400;
   Int_t           TriggerPrescale_HLT_PFHT450_SixJet40_BTagCSV_p056;
   Int_t           TriggerPrescale_HLT_PFHT450_SixJet40_PFBTagCSV0p72;
   Int_t           TriggerPrescale_HLT_PFHT450_SixJet40;
   Int_t           TriggerPrescale_HLT_PFHT475;
   Int_t           TriggerPrescale_HLT_PFHT550_4JetPt50;
   Int_t           TriggerPrescale_HLT_PFHT550_4Jet;
   Int_t           TriggerPrescale_HLT_PFHT600;
   Int_t           TriggerPrescale_HLT_PFHT650_4JetPt50;
   Int_t           TriggerPrescale_HLT_PFHT650_4Jet;
   Int_t           TriggerPrescale_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5;
   Int_t           TriggerPrescale_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5;
   Int_t           TriggerPrescale_HLT_PFHT650;
   Int_t           TriggerPrescale_HLT_PFHT750_4JetPt50;
   Int_t           TriggerPrescale_HLT_PFHT750_4Jet;
   Int_t           TriggerPrescale_HLT_PFHT800;
   Int_t           TriggerPrescale_HLT_PFHT900;
   Int_t           TriggerPrescale_HLT_PFJet140;
   Int_t           TriggerPrescale_HLT_PFJet200;
   Int_t           TriggerPrescale_HLT_PFJet260;
   Int_t           TriggerPrescale_HLT_PFJet320;
   Int_t           TriggerPrescale_HLT_PFJet400;
   Int_t           TriggerPrescale_HLT_PFJet40;
   Int_t           TriggerPrescale_HLT_PFJet450;
   Int_t           TriggerPrescale_HLT_PFJet500;
   Int_t           TriggerPrescale_HLT_PFJet60;
   Int_t           TriggerPrescale_HLT_PFJet80;
   Int_t           TriggerPrescale_HLT_PFMET120_NoiseCleaned_BTagCSV07;
   Int_t           TriggerPrescale_HLT_PFMET120_NoiseCleaned_Mu5;
   Int_t           TriggerPrescale_HLT_PFMET120_PFMHT120_IDLoose;
   Int_t           TriggerPrescale_HLT_PFMET170_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon120;
   Int_t           TriggerPrescale_HLT_Photon125;
   Int_t           TriggerPrescale_HLT_Photon135_PFMET100_NoiseCleaned;
   Int_t           TriggerPrescale_HLT_Photon135_PFMET100;
   Int_t           TriggerPrescale_HLT_Photon135_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon135_VBF;
   Int_t           TriggerPrescale_HLT_Photon150;
   Int_t           TriggerPrescale_HLT_Photon155_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon165_HE10;
   Int_t           TriggerPrescale_HLT_Photon165_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon175;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon22;
   Int_t           TriggerPrescale_HLT_Photon250_NoHE;
   Int_t           TriggerPrescale_HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60;
   Int_t           TriggerPrescale_HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5;
   Int_t           TriggerPrescale_HLT_Photon300_NoHE;
   Int_t           TriggerPrescale_HLT_Photon30_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon30_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon30;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon36;
   Int_t           TriggerPrescale_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65;
   Int_t           TriggerPrescale_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15;
   Int_t           TriggerPrescale_HLT_Photon500;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon50;
   Int_t           TriggerPrescale_HLT_Photon600;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon75;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_HT300;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_PFHT500;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_PFHT600;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_Iso40;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_IsoM;
   Int_t           TriggerPrescale_HLT_Photon90;
   Int_t           TriggerPrescale_HLT_Physics;
   Int_t           TriggerPrescale_HLT_PixelTracks_Multiplicity110;
   Int_t           TriggerPrescale_HLT_PixelTracks_Multiplicity135;
   Int_t           TriggerPrescale_HLT_PixelTracks_Multiplicity160;
   Int_t           TriggerPrescale_HLT_PixelTracks_Multiplicity60;
   Int_t           TriggerPrescale_HLT_PixelTracks_Multiplicity85;
   Int_t           TriggerPrescale_HLT_QuadJet45_DoubleCSV0p5;
   Int_t           TriggerPrescale_HLT_QuadJet45_TripleCSV0p5;
   Int_t           TriggerPrescale_HLT_QuadMuon0_Dimuon0_Jpsi;
   Int_t           TriggerPrescale_HLT_QuadMuon0_Dimuon0_Upsilon;
   Int_t           TriggerPrescale_HLT_QuadPFJet_BTagCSV_VBF;
   Int_t           TriggerPrescale_HLT_QuadPFJet_VBF;
   Int_t           TriggerPrescale_HLT_Rsq0p36;
   Int_t           TriggerPrescale_HLT_RsqMR260_Rsq0p09_MR200_4jet;
   Int_t           TriggerPrescale_HLT_RsqMR260_Rsq0p09_MR200;
   Int_t           TriggerPrescale_HLT_RsqMR300_Rsq0p09_MR200_4jet;
   Int_t           TriggerPrescale_HLT_RsqMR300_Rsq0p09_MR200;
   Int_t           TriggerPrescale_HLT_SingleCentralPFJet170_CFMax0p1;
   Int_t           TriggerPrescale_HLT_TkMu24_eta2p1;
   Int_t           TriggerPrescale_HLT_TkMu27;
   Int_t           TriggerPrescale_HLT_TripleMu_12_10_5;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_Hadronic;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_TightID_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_TightID_Hadronic;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_VTightID_Hadronic;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack;
   Int_t           TriggerPrescale_HLT_VBF_DisplacedJet40_VVTightID_Hadronic;
   Int_t           TriggerPrescale_HLT_ZeroBias;
   Float_t         Jet_jetHT;
   Float_t         Jet_leadingJetPt;
   Float_t         Jet_leadingJetEta;
   Float_t         Jet_leadingJetPhi;
   Float_t         Jet_leadingJetMass;
   Float_t         Jet_secondleadingJetPt;
   Float_t         Jet_secondleadingJetEta;
   Float_t         Jet_secondleadingJetPhi;
   Float_t         Jet_secondleadingJetMass;
   Float_t         Jet_thirdleadingJetPt;
   Float_t         Jet_thirdleadingJetEta;
   Float_t         Jet_thirdleadingJetPhi;
   Float_t         Jet_thirdleadingJetMass;
   Int_t           Jet_nJets;
   Double_t        Photon_pt;
   Double_t        Photon_eta;
   Double_t        Photon_phi;
   Double_t        Photon_scEta;
   Double_t        Photon_scPhi;
   Double_t        Photon_rho;
   Double_t        Photon_chargedHadIso03;
   Double_t        Photon_neutralHadIso03;
   Double_t        Photon_photonIso03;
   Double_t        Photon_rhoCorChargedHadIso03;
   Double_t        Photon_rhoCorNeutralHadIso03;
   Double_t        Photon_rhoCorPhotonIso03;
   Double_t        Photon_corPhotonIso03;
   Double_t        Photon_hadTowerOverEm;
   Double_t        Photon_hadronicOverEm;
   Double_t        Photon_r9;
   Double_t        Photon_r9_5x5;
   Double_t        Photon_sigmaIetaIeta;
   Double_t        Photon_sigmaIetaIeta5x5;
   Double_t        Photon_sigmaEtaEta;
   Double_t        Photon_sigmaIphiIphi;
   Double_t        Photon_sigmaIphiIphi5x5;
   Double_t        Photon_sigmaIetaIphi;
   Double_t        Photon_sigmaIetaIphi5x5;
   Double_t        Photon_maxEnergyXtal;
   Double_t        Photon_iEta;
   Double_t        Photon_iPhi;
   Double_t        Photon_alphaHighPtID;
   Double_t        Photon_kappaHighPtID;
   Double_t        Photon_phoEAHighPtID;
   Double_t        Photon_chEAegmID;
   Double_t        Photon_nhEAegmID;
   Double_t        Photon_phoEAegmID;
   Bool_t          Photon_passEGMLooseID;
   Bool_t          Photon_passEGMMediumID;
   Bool_t          Photon_passEGMTightID;
   Bool_t          Photon_isEB;
   Bool_t          Photon_isEE;
   Bool_t          Photon_isEBEtaGap;
   Bool_t          Photon_isEBPhiGap;
   Bool_t          Photon_isEERingGap;
   Bool_t          Photon_isEEDeeGap;
   Bool_t          Photon_isEBEEGap;
   Bool_t          Photon_passElectronVeto;
   Bool_t          Photon_passHTowOverE;
   Bool_t          Photon_passChIso;
   Bool_t          Photon_passCorPhoIso;
   Bool_t          Photon_passSieie;
   Bool_t          Photon_passHighPtID;
   Bool_t          Photon_passChIsoDenom;
   Bool_t          Photon_passCorPhoIsoDenom;
   Bool_t          Photon_isFakeable;
   Bool_t          Photon_isNumeratorObjCand;
   Bool_t          Photon_isDenominatorObj;
   Bool_t          Photon_isSaturated;
   Int_t           PhotonRealMatch;
   std::vector<double>  *VertexCollInfo_vx;
   std::vector<double>  *VertexCollInfo_vy;
   std::vector<double>  *VertexCollInfo_vz;
   std::vector<double>  *VertexCollInfo_vxError;
   std::vector<double>  *VertexCollInfo_vyError;
   std::vector<double>  *VertexCollInfo_vzError;
   std::vector<double>  *VertexCollInfo_ndof;
   std::vector<double>  *VertexCollInfo_d0;
   std::vector<int>     *VertexCollInfo_nTracks;
   std::vector<int>     *VertexCollInfo_isFake;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_TriggerBit;   //!
   TBranch        *b_TriggerPrescale;   //!
   TBranch        *b_Jet;   //!
   TBranch        *b_Photon;   //!
   TBranch        *b_is_real_template_photon;   //!
   TBranch        *b_VertexCollInfo_vx;   //!
   TBranch        *b_VertexCollInfo_vy;   //!
   TBranch        *b_VertexCollInfo_vz;   //!
   TBranch        *b_VertexCollInfo_vxError;   //!
   TBranch        *b_VertexCollInfo_vyError;   //!
   TBranch        *b_VertexCollInfo_vzError;   //!
   TBranch        *b_VertexCollInfo_ndof;   //!
   TBranch        *b_VertexCollInfo_d0;   //!
   TBranch        *b_VertexCollInfo_nTracks;   //!
   TBranch        *b_VertexCollInfo_isFake;   //!

   MCFakeRateClosureTestBase(TTree *tree=0);
   virtual ~MCFakeRateClosureTestBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MCFakeRateClosureTest_cxx
MCFakeRateClosureTestBase::MCFakeRateClosureTestBase(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_closure_test/QCD_merged_ntuples/diphoton_fake_rate_closure_test_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmseos.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_closure_test/QCD_merged_ntuples/diphoton_fake_rate_closure_test_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmseos.fnal.gov//store/user/abuccill/diphoton-analysis/fake_rate_closure_test/QCD_merged_ntuples/diphoton_fake_rate_closure_test_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_merged.root:/diphoton");
      dir->GetObject("fTree",tree);

   }
   Init(tree);
}

MCFakeRateClosureTestBase::~MCFakeRateClosureTestBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MCFakeRateClosureTestBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MCFakeRateClosureTestBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MCFakeRateClosureTestBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   VertexCollInfo_vx = 0;
   VertexCollInfo_vy = 0;
   VertexCollInfo_vz = 0;
   VertexCollInfo_vxError = 0;
   VertexCollInfo_vyError = 0;
   VertexCollInfo_vzError = 0;
   VertexCollInfo_ndof = 0;
   VertexCollInfo_d0 = 0;
   VertexCollInfo_nTracks = 0;
   VertexCollInfo_isFake = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_run, &b_Event);
   fChain->SetBranchAddress("TriggerBit", &TriggerBit_HLT_AK4PFDJet60_Eta2p1ForPPRef, &b_TriggerBit);
   fChain->SetBranchAddress("TriggerPrescale", &TriggerPrescale_HLT_AK4PFDJet60_Eta2p1ForPPRef, &b_TriggerPrescale);
   fChain->SetBranchAddress("Jet", &Jet_jetHT, &b_Jet);
   fChain->SetBranchAddress("Photon", &Photon_pt, &b_Photon);
   fChain->SetBranchAddress("PhotonRealMatch", &PhotonRealMatch, &b_is_real_template_photon);
   fChain->SetBranchAddress("VertexCollInfo.vx", &VertexCollInfo_vx, &b_VertexCollInfo_vx);
   fChain->SetBranchAddress("VertexCollInfo.vy", &VertexCollInfo_vy, &b_VertexCollInfo_vy);
   fChain->SetBranchAddress("VertexCollInfo.vz", &VertexCollInfo_vz, &b_VertexCollInfo_vz);
   fChain->SetBranchAddress("VertexCollInfo.vxError", &VertexCollInfo_vxError, &b_VertexCollInfo_vxError);
   fChain->SetBranchAddress("VertexCollInfo.vyError", &VertexCollInfo_vyError, &b_VertexCollInfo_vyError);
   fChain->SetBranchAddress("VertexCollInfo.vzError", &VertexCollInfo_vzError, &b_VertexCollInfo_vzError);
   fChain->SetBranchAddress("VertexCollInfo.ndof", &VertexCollInfo_ndof, &b_VertexCollInfo_ndof);
   fChain->SetBranchAddress("VertexCollInfo.d0", &VertexCollInfo_d0, &b_VertexCollInfo_d0);
   fChain->SetBranchAddress("VertexCollInfo.nTracks", &VertexCollInfo_nTracks, &b_VertexCollInfo_nTracks);
   fChain->SetBranchAddress("VertexCollInfo.isFake", &VertexCollInfo_isFake, &b_VertexCollInfo_isFake);
   Notify();
}

Bool_t MCFakeRateClosureTestBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MCFakeRateClosureTestBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MCFakeRateClosureTestBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MCFakeRateClosureTest_cxx
