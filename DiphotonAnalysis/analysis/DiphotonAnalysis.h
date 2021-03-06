//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 10 06:42:31 2016 by ROOT version 6.02/13
// from TTree fTightTightTree/DiPhotonTightTightTree
// found on file: root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root
//////////////////////////////////////////////////////////

#ifndef DiphotonAnalysis_h
#define DiphotonAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DiphotonAnalysis {
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
   Double_t        BeamSpot_x0;
   Double_t        BeamSpot_y0;
   Double_t        BeamSpot_z0;
   Double_t        BeamSpot_sigmaZ;
   Double_t        BeamSpot_x0error;
   Double_t        BeamSpot_y0error;
   Double_t        BeamSpot_z0error;
   Double_t        BeamSpot_sigmaZ0error;
   Double_t        Vertex0_vx;
   Double_t        Vertex0_vy;
   Double_t        Vertex0_vz;
   Double_t        Vertex0_vxError;
   Double_t        Vertex0_vyError;
   Double_t        Vertex0_vzError;
   Double_t        Vertex0_ndof;
   Double_t        Vertex0_d0;
   Int_t           Vertex0_nTracks;
   Bool_t          Vertex0_isFake;
   Double_t        PrimaryVertex_vx;
   Double_t        PrimaryVertex_vy;
   Double_t        PrimaryVertex_vz;
   Double_t        PrimaryVertex_vxError;
   Double_t        PrimaryVertex_vyError;
   Double_t        PrimaryVertex_vzError;
   Double_t        PrimaryVertex_ndof;
   Double_t        PrimaryVertex_d0;
   Int_t           PrimaryVertex_nTracks;
   Bool_t          PrimaryVertex_isFake;
   Float_t         Jet_jetHT;
   Float_t         Jet_leadingJetPt;
   Float_t         Jet_leadingJetEta;
   Float_t         Jet_leadingJetPhi;
   Float_t         Jet_leadingJetMass;
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
   Double_t        Photon1_pt;
   Double_t        Photon1_eta;
   Double_t        Photon1_phi;
   Double_t        Photon1_scEta;
   Double_t        Photon1_scPhi;
   Double_t        Photon1_rho;
   Double_t        Photon1_chargedHadIso03;
   Double_t        Photon1_neutralHadIso03;
   Double_t        Photon1_photonIso03;
   Double_t        Photon1_rhoCorChargedHadIso03;
   Double_t        Photon1_rhoCorNeutralHadIso03;
   Double_t        Photon1_rhoCorPhotonIso03;
   Double_t        Photon1_corPhotonIso03;
   Double_t        Photon1_hadTowerOverEm;
   Double_t        Photon1_r9;
   Double_t        Photon1_r9_5x5;
   Double_t        Photon1_sigmaIetaIeta;
   Double_t        Photon1_sigmaIetaIeta5x5;
   Double_t        Photon1_sigmaEtaEta;
   Double_t        Photon1_sigmaIphiIphi;
   Double_t        Photon1_sigmaIphiIphi5x5;
   Double_t        Photon1_sigmaIetaIphi;
   Double_t        Photon1_sigmaIetaIphi5x5;
   Double_t        Photon1_maxEnergyXtal;
   Double_t        Photon1_iEta;
   Double_t        Photon1_iPhi;
   Double_t        Photon1_alphaHighPtID;
   Double_t        Photon1_kappaHighPtID;
   Double_t        Photon1_phoEAHighPtID;
   Double_t        Photon1_chEAegmID;
   Double_t        Photon1_nhEAegmID;
   Double_t        Photon1_phoEAegmID;
   Bool_t          Photon1_passEGMLooseID;
   Bool_t          Photon1_passEGMMediumID;
   Bool_t          Photon1_passEGMTightID;
   Bool_t          Photon1_isEB;
   Bool_t          Photon1_isEE;
   Bool_t          Photon1_isEBEtaGap;
   Bool_t          Photon1_isEBPhiGap;
   Bool_t          Photon1_isEERingGap;
   Bool_t          Photon1_isEEDeeGap;
   Bool_t          Photon1_isEBEEGap;
   Bool_t          Photon1_passElectronVeto;
   Bool_t          Photon1_passHTowOverE;
   Bool_t          Photon1_passChIso;
   Bool_t          Photon1_passCorPhoIso;
   Bool_t          Photon1_passSieie;
   Bool_t          Photon1_passHighPtID;
   Bool_t          Photon1_passChIsoDenom;
   Bool_t          Photon1_passCorPhoIsoDenom;
   Bool_t          Photon1_isFakeable;
   Bool_t          Photon1_isNumeratorObjCand;
   Bool_t          Photon1_isDenominatorObj;
   Bool_t          Photon1_isSaturated;
   Double_t        Photon2_pt;
   Double_t        Photon2_eta;
   Double_t        Photon2_phi;
   Double_t        Photon2_scEta;
   Double_t        Photon2_scPhi;
   Double_t        Photon2_rho;
   Double_t        Photon2_chargedHadIso03;
   Double_t        Photon2_neutralHadIso03;
   Double_t        Photon2_photonIso03;
   Double_t        Photon2_rhoCorChargedHadIso03;
   Double_t        Photon2_rhoCorNeutralHadIso03;
   Double_t        Photon2_rhoCorPhotonIso03;
   Double_t        Photon2_corPhotonIso03;
   Double_t        Photon2_hadTowerOverEm;
   Double_t        Photon2_r9;
   Double_t        Photon2_r9_5x5;
   Double_t        Photon2_sigmaIetaIeta;
   Double_t        Photon2_sigmaIetaIeta5x5;
   Double_t        Photon2_sigmaEtaEta;
   Double_t        Photon2_sigmaIphiIphi;
   Double_t        Photon2_sigmaIphiIphi5x5;
   Double_t        Photon2_sigmaIetaIphi;
   Double_t        Photon2_sigmaIetaIphi5x5;
   Double_t        Photon2_maxEnergyXtal;
   Double_t        Photon2_iEta;
   Double_t        Photon2_iPhi;
   Double_t        Photon2_alphaHighPtID;
   Double_t        Photon2_kappaHighPtID;
   Double_t        Photon2_phoEAHighPtID;
   Double_t        Photon2_chEAegmID;
   Double_t        Photon2_nhEAegmID;
   Double_t        Photon2_phoEAegmID;
   Bool_t          Photon2_passEGMLooseID;
   Bool_t          Photon2_passEGMMediumID;
   Bool_t          Photon2_passEGMTightID;
   Bool_t          Photon2_isEB;
   Bool_t          Photon2_isEE;
   Bool_t          Photon2_isEBEtaGap;
   Bool_t          Photon2_isEBPhiGap;
   Bool_t          Photon2_isEERingGap;
   Bool_t          Photon2_isEEDeeGap;
   Bool_t          Photon2_isEBEEGap;
   Bool_t          Photon2_passElectronVeto;
   Bool_t          Photon2_passHTowOverE;
   Bool_t          Photon2_passChIso;
   Bool_t          Photon2_passCorPhoIso;
   Bool_t          Photon2_passSieie;
   Bool_t          Photon2_passHighPtID;
   Bool_t          Photon2_passChIsoDenom;
   Bool_t          Photon2_passCorPhoIsoDenom;
   Bool_t          Photon2_isFakeable;
   Bool_t          Photon2_isNumeratorObjCand;
   Bool_t          Photon2_isDenominatorObj;
   Bool_t          Photon2_isSaturated;
   Double_t        Diphoton_Minv;
   Double_t        Diphoton_qt;
   Double_t        Diphoton_deltaPhi;
   Double_t        Diphoton_deltaEta;
   Double_t        Diphoton_deltaR;
   Double_t        Diphoton_deltaROld;
   Double_t        Diphoton_cosThetaStar;
   Double_t        Diphoton_cosThetaStarOld;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_BeamSpot;   //!
   TBranch        *b_Vertex0;   //!
   TBranch        *b_PrimaryVertex;   //!
   TBranch        *b_Jet;   //!
   TBranch        *b_TriggerBit;   //!
   TBranch        *b_TriggerPrescale;   //!
   TBranch        *b_Photon1;   //!
   TBranch        *b_Photon2;   //!
   TBranch        *b_Diphoton;   //!

   DiphotonAnalysis(TTree *tree=0);
   virtual ~DiphotonAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DiphotonAnalysis_cxx
DiphotonAnalysis::DiphotonAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmsxrootd.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root:/diphoton");
      dir->GetObject("fTightTightTree",tree);

   }
   Init(tree);
}

DiphotonAnalysis::~DiphotonAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DiphotonAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DiphotonAnalysis::LoadTree(Long64_t entry)
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

void DiphotonAnalysis::Init(TTree *tree)
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
   fChain->SetBranchAddress("BeamSpot", &BeamSpot_x0, &b_BeamSpot);
   fChain->SetBranchAddress("Vertex0", &Vertex0_vx, &b_Vertex0);
   fChain->SetBranchAddress("PrimaryVertex", &PrimaryVertex_vx, &b_PrimaryVertex);
   fChain->SetBranchAddress("Jet", &Jet_jetHT, &b_Jet);
   fChain->SetBranchAddress("TriggerBit", &TriggerBit_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3, &b_TriggerBit);
   fChain->SetBranchAddress("TriggerPrescale", &TriggerPrescale_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3, &b_TriggerPrescale);
   fChain->SetBranchAddress("Photon1", &Photon1_pt, &b_Photon1);
   fChain->SetBranchAddress("Photon2", &Photon2_pt, &b_Photon2);
   fChain->SetBranchAddress("Diphoton", &Diphoton_Minv, &b_Diphoton);
   Notify();
}

Bool_t DiphotonAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DiphotonAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DiphotonAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DiphotonAnalysis_cxx
