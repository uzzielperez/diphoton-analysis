//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jun 14 00:53:15 2016 by ROOT version 6.02/13
// from TTree fTree/PhotonTree
// found on file: root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/GGJets_M-200To500_incomplete.root
//////////////////////////////////////////////////////////

#ifndef MCFakeRateAnalysis_h
#define MCFakeRateAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MCFakeRateAnalysis {
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
   Float_t         Event_weight0;
   Float_t         Event_weight;
   Int_t           Event_interactingParton1PdgId;
   Int_t           Event_interactingParton2PdgId;
   Bool_t          Event_beamHaloIDLoose;
   Bool_t          Event_beamHaloIDTight;
   Bool_t          Event_beamHaloIDTight2015;
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
   Int_t           TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3;
   Int_t           TriggerBit_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2;
   Int_t           TriggerBit_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2;
   Int_t           TriggerBit_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3;
   Int_t           TriggerBit_HLT_AK8PFJet360_TrimMass30_v3;
   Int_t           TriggerBit_HLT_CaloJet500_NoJetID_v2;
   Int_t           TriggerBit_HLT_DiCaloJetAve140_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve200_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve260_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve320_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve400_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve40_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve500_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve60_v1;
   Int_t           TriggerBit_HLT_DiCaloJetAve80_v1;
   Int_t           TriggerBit_HLT_DiPFJetAve100_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve140_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve160_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve200_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve220_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve260_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve300_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve30_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve320_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve400_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve40_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve500_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve60_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve60_v2;
   Int_t           TriggerBit_HLT_DiPFJetAve80_HFJEC_v3;
   Int_t           TriggerBit_HLT_DiPFJetAve80_v2;
   Int_t           TriggerBit_HLT_HT2000_v1;
   Int_t           TriggerBit_HLT_HT200_v1;
   Int_t           TriggerBit_HLT_HT2500_v1;
   Int_t           TriggerBit_HLT_HT275_v1;
   Int_t           TriggerBit_HLT_HT325_v1;
   Int_t           TriggerBit_HLT_HT425_v1;
   Int_t           TriggerBit_HLT_HT575_v1;
   Int_t           TriggerBit_HLT_L1_TripleJet_VBF_v4;
   Int_t           TriggerBit_HLT_PFHT200_v2;
   Int_t           TriggerBit_HLT_PFHT250_v2;
   Int_t           TriggerBit_HLT_PFHT300_v2;
   Int_t           TriggerBit_HLT_PFHT350_v3;
   Int_t           TriggerBit_HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3;
   Int_t           TriggerBit_HLT_PFHT400_SixJet30_v3;
   Int_t           TriggerBit_HLT_PFHT400_v2;
   Int_t           TriggerBit_HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3;
   Int_t           TriggerBit_HLT_PFHT450_SixJet40_v3;
   Int_t           TriggerBit_HLT_PFHT475_v2;
   Int_t           TriggerBit_HLT_PFHT550_4JetPt50_v1;
   Int_t           TriggerBit_HLT_PFHT600_v3;
   Int_t           TriggerBit_HLT_PFHT650_4JetPt50_v1;
   Int_t           TriggerBit_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3;
   Int_t           TriggerBit_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3;
   Int_t           TriggerBit_HLT_PFHT650_v3;
   Int_t           TriggerBit_HLT_PFHT750_4JetPt50_v3;
   Int_t           TriggerBit_HLT_PFHT800_v2;
   Int_t           TriggerBit_HLT_PFJet140_v4;
   Int_t           TriggerBit_HLT_PFJet200_v4;
   Int_t           TriggerBit_HLT_PFJet260_v4;
   Int_t           TriggerBit_HLT_PFJet320_v4;
   Int_t           TriggerBit_HLT_PFJet400_v4;
   Int_t           TriggerBit_HLT_PFJet40_v4;
   Int_t           TriggerBit_HLT_PFJet450_v4;
   Int_t           TriggerBit_HLT_PFJet500_v4;
   Int_t           TriggerBit_HLT_PFJet60_v4;
   Int_t           TriggerBit_HLT_PFJet80_v4;
   Int_t           TriggerBit_HLT_QuadPFJet_VBF_v4;
   Int_t           TriggerBit_HLT_DoubleIsoMu17_eta2p1_v3;
   Int_t           TriggerBit_HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1;
   Int_t           TriggerBit_HLT_IsoMu16_eta2p1_MET30_v1;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5;
   Int_t           TriggerBit_HLT_IsoMu17_eta2p1_v3;
   Int_t           TriggerBit_HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2;
   Int_t           TriggerBit_HLT_IsoMu18_TriCentralPFJet50_40_30_v2;
   Int_t           TriggerBit_HLT_IsoMu18_v2;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3;
   Int_t           TriggerBit_HLT_IsoMu20_eta2p1_v4;
   Int_t           TriggerBit_HLT_IsoMu20_v3;
   Int_t           TriggerBit_HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2;
   Int_t           TriggerBit_HLT_IsoMu22_TriCentralPFJet50_40_30_v2;
   Int_t           TriggerBit_HLT_IsoMu22_v2;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4;
   Int_t           TriggerBit_HLT_IsoMu24_eta2p1_v3;
   Int_t           TriggerBit_HLT_IsoMu27_v3;
   Int_t           TriggerBit_HLT_IsoTkMu18_v2;
   Int_t           TriggerBit_HLT_IsoTkMu20_eta2p1_v3;
   Int_t           TriggerBit_HLT_IsoTkMu20_v4;
   Int_t           TriggerBit_HLT_IsoTkMu22_v2;
   Int_t           TriggerBit_HLT_IsoTkMu24_eta2p1_v3;
   Int_t           TriggerBit_HLT_IsoTkMu27_v3;
   Int_t           TriggerBit_HLT_L1SingleMu16_v1;
   Int_t           TriggerBit_HLT_L1SingleMuOpen_v2;
   Int_t           TriggerBit_HLT_L2Mu10_v1;
   Int_t           TriggerBit_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_PFHT350_v2;
   Int_t           TriggerBit_HLT_Mu15_IsoVVVL_PFHT600_v3;
   Int_t           TriggerBit_HLT_Mu16_eta2p1_MET30_v1;
   Int_t           TriggerBit_HLT_Mu20_v2;
   Int_t           TriggerBit_HLT_Mu24_eta2p1_v2;
   Int_t           TriggerBit_HLT_Mu27_v2;
   Int_t           TriggerBit_HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2;
   Int_t           TriggerBit_HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2;
   Int_t           TriggerBit_HLT_Mu300_v1;
   Int_t           TriggerBit_HLT_Mu30_eta2p1_PFJet150_PFJet50_v1;
   Int_t           TriggerBit_HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2;
   Int_t           TriggerBit_HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2;
   Int_t           TriggerBit_HLT_Mu350_v1;
   Int_t           TriggerBit_HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2;
   Int_t           TriggerBit_HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2;
   Int_t           TriggerBit_HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2;
   Int_t           TriggerBit_HLT_Mu40_eta2p1_PFJet200_PFJet50_v3;
   Int_t           TriggerBit_HLT_Mu45_eta2p1_v2;
   Int_t           TriggerBit_HLT_Mu50_v2;
   Int_t           TriggerBit_HLT_Mu55_v1;
   Int_t           TriggerBit_HLT_OldIsoMu18_v1;
   Int_t           TriggerBit_HLT_OldIsoTkMu18_v2;
   Int_t           TriggerBit_HLT_TkMu20_v2;
   Int_t           TriggerBit_HLT_TkMu24_eta2p1_v2;
   Int_t           TriggerBit_HLT_TkMu27_v2;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon120_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon120_v3;
   Int_t           TriggerBit_HLT_Photon125_v1;
   Int_t           TriggerBit_HLT_Photon135_PFMET100_v1;
   Int_t           TriggerBit_HLT_Photon150_v1;
   Int_t           TriggerBit_HLT_Photon165_HE10_v3;
   Int_t           TriggerBit_HLT_Photon165_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon175_v3;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon22_R9Id90_HE10_IsoM_v2;
   Int_t           TriggerBit_HLT_Photon22_v2;
   Int_t           TriggerBit_HLT_Photon250_NoHE_v2;
   Int_t           TriggerBit_HLT_Photon300_NoHE_v2;
   Int_t           TriggerBit_HLT_Photon30_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon30_v3;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon36_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon36_v3;
   Int_t           TriggerBit_HLT_Photon500_v1;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon50_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon50_v3;
   Int_t           TriggerBit_HLT_Photon600_v1;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon75_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon75_v3;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_HT300_v1;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_PFHT500_v3;
   Int_t           TriggerBit_HLT_Photon90_CaloIdL_PFHT600_v2;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerBit_HLT_Photon90_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerBit_HLT_Photon90_v3;
   Int_t           TriggerBit_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
   Int_t           TriggerBit_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
   Int_t           TriggerBit_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1;
   Int_t           TriggerBit_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1;
   Int_t           TriggerBit_HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1;
   Int_t           TriggerBit_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2;
   Int_t           TriggerBit_HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3;
   Int_t           TriggerBit_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3;
   Int_t           TriggerBit_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1;
   Int_t           TriggerBit_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4;
   Int_t           TriggerBit_HLT_DoublePhoton40_v1;
   Int_t           TriggerBit_HLT_DoublePhoton50_v1;
   Int_t           TriggerBit_HLT_DoublePhoton60_v1;
   Int_t           TriggerBit_HLT_DoublePhoton85_v2;
   Int_t           TriggerBit_HLT_ECALHT800_v2;
   Int_t           TriggerBit_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3;
   Int_t           TriggerBit_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerBit_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3;
   Int_t           TriggerBit_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2;
   Int_t           TriggerBit_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
   Int_t           TriggerBit_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerBit_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerBit_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
   Int_t           TriggerBit_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerBit_HLT_Ele30WP60_Ele8_Mass55_v2;
   Int_t           TriggerBit_HLT_Ele30WP60_SC4_Mass55_v3;
   Int_t           TriggerBit_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerBit_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerBit_HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2;
   Int_t           TriggerBit_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2;
   Int_t           TriggerBit_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2;
   Int_t           TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3;
   Int_t           TriggerPrescale_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2;
   Int_t           TriggerPrescale_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2;
   Int_t           TriggerPrescale_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3;
   Int_t           TriggerPrescale_HLT_AK8PFJet360_TrimMass30_v3;
   Int_t           TriggerPrescale_HLT_CaloJet500_NoJetID_v2;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve140_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve200_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve260_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve320_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve400_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve40_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve500_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve60_v1;
   Int_t           TriggerPrescale_HLT_DiCaloJetAve80_v1;
   Int_t           TriggerPrescale_HLT_DiPFJetAve100_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve140_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve160_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve200_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve220_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve260_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve300_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve30_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve320_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve400_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve40_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve500_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve60_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve60_v2;
   Int_t           TriggerPrescale_HLT_DiPFJetAve80_HFJEC_v3;
   Int_t           TriggerPrescale_HLT_DiPFJetAve80_v2;
   Int_t           TriggerPrescale_HLT_HT2000_v1;
   Int_t           TriggerPrescale_HLT_HT200_v1;
   Int_t           TriggerPrescale_HLT_HT2500_v1;
   Int_t           TriggerPrescale_HLT_HT275_v1;
   Int_t           TriggerPrescale_HLT_HT325_v1;
   Int_t           TriggerPrescale_HLT_HT425_v1;
   Int_t           TriggerPrescale_HLT_HT575_v1;
   Int_t           TriggerPrescale_HLT_L1_TripleJet_VBF_v4;
   Int_t           TriggerPrescale_HLT_PFHT200_v2;
   Int_t           TriggerPrescale_HLT_PFHT250_v2;
   Int_t           TriggerPrescale_HLT_PFHT300_v2;
   Int_t           TriggerPrescale_HLT_PFHT350_v3;
   Int_t           TriggerPrescale_HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3;
   Int_t           TriggerPrescale_HLT_PFHT400_SixJet30_v3;
   Int_t           TriggerPrescale_HLT_PFHT400_v2;
   Int_t           TriggerPrescale_HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3;
   Int_t           TriggerPrescale_HLT_PFHT450_SixJet40_v3;
   Int_t           TriggerPrescale_HLT_PFHT475_v2;
   Int_t           TriggerPrescale_HLT_PFHT550_4JetPt50_v1;
   Int_t           TriggerPrescale_HLT_PFHT600_v3;
   Int_t           TriggerPrescale_HLT_PFHT650_4JetPt50_v1;
   Int_t           TriggerPrescale_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3;
   Int_t           TriggerPrescale_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3;
   Int_t           TriggerPrescale_HLT_PFHT650_v3;
   Int_t           TriggerPrescale_HLT_PFHT750_4JetPt50_v3;
   Int_t           TriggerPrescale_HLT_PFHT800_v2;
   Int_t           TriggerPrescale_HLT_PFJet140_v4;
   Int_t           TriggerPrescale_HLT_PFJet200_v4;
   Int_t           TriggerPrescale_HLT_PFJet260_v4;
   Int_t           TriggerPrescale_HLT_PFJet320_v4;
   Int_t           TriggerPrescale_HLT_PFJet400_v4;
   Int_t           TriggerPrescale_HLT_PFJet40_v4;
   Int_t           TriggerPrescale_HLT_PFJet450_v4;
   Int_t           TriggerPrescale_HLT_PFJet500_v4;
   Int_t           TriggerPrescale_HLT_PFJet60_v4;
   Int_t           TriggerPrescale_HLT_PFJet80_v4;
   Int_t           TriggerPrescale_HLT_QuadPFJet_VBF_v4;
   Int_t           TriggerPrescale_HLT_DoubleIsoMu17_eta2p1_v3;
   Int_t           TriggerPrescale_HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1;
   Int_t           TriggerPrescale_HLT_IsoMu16_eta2p1_MET30_v1;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5;
   Int_t           TriggerPrescale_HLT_IsoMu17_eta2p1_v3;
   Int_t           TriggerPrescale_HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2;
   Int_t           TriggerPrescale_HLT_IsoMu18_TriCentralPFJet50_40_30_v2;
   Int_t           TriggerPrescale_HLT_IsoMu18_v2;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3;
   Int_t           TriggerPrescale_HLT_IsoMu20_eta2p1_v4;
   Int_t           TriggerPrescale_HLT_IsoMu20_v3;
   Int_t           TriggerPrescale_HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2;
   Int_t           TriggerPrescale_HLT_IsoMu22_TriCentralPFJet50_40_30_v2;
   Int_t           TriggerPrescale_HLT_IsoMu22_v2;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4;
   Int_t           TriggerPrescale_HLT_IsoMu24_eta2p1_v3;
   Int_t           TriggerPrescale_HLT_IsoMu27_v3;
   Int_t           TriggerPrescale_HLT_IsoTkMu18_v2;
   Int_t           TriggerPrescale_HLT_IsoTkMu20_eta2p1_v3;
   Int_t           TriggerPrescale_HLT_IsoTkMu20_v4;
   Int_t           TriggerPrescale_HLT_IsoTkMu22_v2;
   Int_t           TriggerPrescale_HLT_IsoTkMu24_eta2p1_v3;
   Int_t           TriggerPrescale_HLT_IsoTkMu27_v3;
   Int_t           TriggerPrescale_HLT_L1SingleMu16_v1;
   Int_t           TriggerPrescale_HLT_L1SingleMuOpen_v2;
   Int_t           TriggerPrescale_HLT_L2Mu10_v1;
   Int_t           TriggerPrescale_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_PFHT350_v2;
   Int_t           TriggerPrescale_HLT_Mu15_IsoVVVL_PFHT600_v3;
   Int_t           TriggerPrescale_HLT_Mu16_eta2p1_MET30_v1;
   Int_t           TriggerPrescale_HLT_Mu20_v2;
   Int_t           TriggerPrescale_HLT_Mu24_eta2p1_v2;
   Int_t           TriggerPrescale_HLT_Mu27_v2;
   Int_t           TriggerPrescale_HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2;
   Int_t           TriggerPrescale_HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2;
   Int_t           TriggerPrescale_HLT_Mu300_v1;
   Int_t           TriggerPrescale_HLT_Mu30_eta2p1_PFJet150_PFJet50_v1;
   Int_t           TriggerPrescale_HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2;
   Int_t           TriggerPrescale_HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2;
   Int_t           TriggerPrescale_HLT_Mu350_v1;
   Int_t           TriggerPrescale_HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2;
   Int_t           TriggerPrescale_HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2;
   Int_t           TriggerPrescale_HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2;
   Int_t           TriggerPrescale_HLT_Mu40_eta2p1_PFJet200_PFJet50_v3;
   Int_t           TriggerPrescale_HLT_Mu45_eta2p1_v2;
   Int_t           TriggerPrescale_HLT_Mu50_v2;
   Int_t           TriggerPrescale_HLT_Mu55_v1;
   Int_t           TriggerPrescale_HLT_OldIsoMu18_v1;
   Int_t           TriggerPrescale_HLT_OldIsoTkMu18_v2;
   Int_t           TriggerPrescale_HLT_TkMu20_v2;
   Int_t           TriggerPrescale_HLT_TkMu24_eta2p1_v2;
   Int_t           TriggerPrescale_HLT_TkMu27_v2;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon120_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon120_v3;
   Int_t           TriggerPrescale_HLT_Photon125_v1;
   Int_t           TriggerPrescale_HLT_Photon135_PFMET100_v1;
   Int_t           TriggerPrescale_HLT_Photon150_v1;
   Int_t           TriggerPrescale_HLT_Photon165_HE10_v3;
   Int_t           TriggerPrescale_HLT_Photon165_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon175_v3;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon22_R9Id90_HE10_IsoM_v2;
   Int_t           TriggerPrescale_HLT_Photon22_v2;
   Int_t           TriggerPrescale_HLT_Photon250_NoHE_v2;
   Int_t           TriggerPrescale_HLT_Photon300_NoHE_v2;
   Int_t           TriggerPrescale_HLT_Photon30_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon30_v3;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon36_v3;
   Int_t           TriggerPrescale_HLT_Photon500_v1;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon50_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon50_v3;
   Int_t           TriggerPrescale_HLT_Photon600_v1;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon75_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon75_v3;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_HT300_v1;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_PFHT500_v3;
   Int_t           TriggerPrescale_HLT_Photon90_CaloIdL_PFHT600_v2;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
   Int_t           TriggerPrescale_HLT_Photon90_R9Id90_HE10_IsoM_v3;
   Int_t           TriggerPrescale_HLT_Photon90_v3;
   Int_t           TriggerPrescale_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
   Int_t           TriggerPrescale_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1;
   Int_t           TriggerPrescale_HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1;
   Int_t           TriggerPrescale_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2;
   Int_t           TriggerPrescale_HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3;
   Int_t           TriggerPrescale_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3;
   Int_t           TriggerPrescale_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1;
   Int_t           TriggerPrescale_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4;
   Int_t           TriggerPrescale_HLT_DoublePhoton40_v1;
   Int_t           TriggerPrescale_HLT_DoublePhoton50_v1;
   Int_t           TriggerPrescale_HLT_DoublePhoton60_v1;
   Int_t           TriggerPrescale_HLT_DoublePhoton85_v2;
   Int_t           TriggerPrescale_HLT_ECALHT800_v2;
   Int_t           TriggerPrescale_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerPrescale_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3;
   Int_t           TriggerPrescale_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2;
   Int_t           TriggerPrescale_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
   Int_t           TriggerPrescale_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerPrescale_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerPrescale_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
   Int_t           TriggerPrescale_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
   Int_t           TriggerPrescale_HLT_Ele30WP60_Ele8_Mass55_v2;
   Int_t           TriggerPrescale_HLT_Ele30WP60_SC4_Mass55_v3;
   Int_t           TriggerPrescale_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3;
   Int_t           TriggerPrescale_HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2;
   Int_t           TriggerPrescale_HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2;
   Int_t           TriggerPrescale_HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2;
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
   Int_t           PhotonGenMatch_status;
   Int_t           PhotonGenMatch_motherStatus;
   Int_t           PhotonGenMatch_grandmotherStatus;
   Int_t           PhotonGenMatch_pdgId;
   Int_t           PhotonGenMatch_motherPdgId;
   Int_t           PhotonGenMatch_grandmotherPdgId;
   Int_t           PhotonGenMatch_matchCategory;
   Int_t           PhotonGenMatch_matchType;
   Double_t        PhotonGenMatch_deltaR_match;
   Double_t        PhotonGenMatch_deltaR_FSR;
   Double_t        PhotonGenMatch_pt;
   Double_t        PhotonGenMatch_eta;
   Double_t        PhotonGenMatch_phi;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_Jet;   //!
   TBranch        *b_TriggerBit;   //!
   TBranch        *b_TriggerPrescale;   //!
   TBranch        *b_Photon;   //!
   TBranch        *b_PhotonGenMatch;   //!

   MCFakeRateAnalysis(TTree *tree=0);
   virtual ~MCFakeRateAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(const Char_t*);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MCFakeRateAnalysis_cxx
MCFakeRateAnalysis::MCFakeRateAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/GGJets_M-200To500_incomplete.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/GGJets_M-200To500_incomplete.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRate/crab3_morejets/GGJets_M-200To500_incomplete.root:/diphoton");
      dir->GetObject("fTree",tree);

   }
   Init(tree);
}

MCFakeRateAnalysis::~MCFakeRateAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MCFakeRateAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MCFakeRateAnalysis::LoadTree(Long64_t entry)
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

void MCFakeRateAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_run, &b_Event);
   fChain->SetBranchAddress("Jet", &Jet_jetHT, &b_Jet);
   fChain->SetBranchAddress("TriggerBit", &TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3, &b_TriggerBit);
   fChain->SetBranchAddress("TriggerPrescale", &TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3, &b_TriggerPrescale);
   fChain->SetBranchAddress("Photon", &Photon_pt, &b_Photon);
   fChain->SetBranchAddress("PhotonGenMatch", &PhotonGenMatch_status, &b_PhotonGenMatch);
   Notify();
}

Bool_t MCFakeRateAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MCFakeRateAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MCFakeRateAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MCFakeRateAnalysis_cxx
