#ifndef TRIGGER_INFO_INC
#define TRIGGER_INFO_INC

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

namespace ExoDiPhotons
{
  
  struct triggerInfo_t {

    // holders for trigger bits or prescales
    int HLT_AK4PFDJet60_Eta2p1ForPPRef_v1;
    int HLT_AK4PFDJet60_Eta2p1ForPPRef_v2;
    int HLT_AK4PFDJet60_Eta2p1ForPPRef_v3;
    int HLT_AK4PFDJet80_Eta2p1ForPPRef_v1;
    int HLT_AK4PFDJet80_Eta2p1ForPPRef_v2;
    int HLT_AK4PFDJet80_Eta2p1ForPPRef_v3;
    int HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2;
    int HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2;
    int HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3;
    int HLT_AK8DiPFJet250_200_TrimMass30_v2;
    int HLT_AK8DiPFJet250_200_TrimMass30_v3;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3;
    int HLT_AK8DiPFJet280_200_TrimMass30_v2;
    int HLT_AK8DiPFJet280_200_TrimMass30_v3;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4;
    int HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2;
    int HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3;
    int HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6;
    int HLT_AK8PFJet140_v1;
    int HLT_AK8PFJet140_v2;
    int HLT_AK8PFJet200_v1;
    int HLT_AK8PFJet200_v2;
    int HLT_AK8PFJet260_v1;
    int HLT_AK8PFJet260_v2;
    int HLT_AK8PFJet320_v1;
    int HLT_AK8PFJet320_v2;
    int HLT_AK8PFJet360TrimMod_Mass30_v1;
    int HLT_AK8PFJet360_TrimMass30_v3;
    int HLT_AK8PFJet360_TrimMass30_v4;
    int HLT_AK8PFJet360_TrimMass30_v5;
    int HLT_AK8PFJet400_v1;
    int HLT_AK8PFJet400_v2;
    int HLT_AK8PFJet40_v1;
    int HLT_AK8PFJet40_v3;
    int HLT_AK8PFJet450_v1;
    int HLT_AK8PFJet450_v2;
    int HLT_AK8PFJet500_v1;
    int HLT_AK8PFJet500_v2;
    int HLT_AK8PFJet60_v1;
    int HLT_AK8PFJet60_v2;
    int HLT_AK8PFJet80_v1;
    int HLT_AK8PFJet80_v2;
    int HLT_BTagMu_DiJet110_Mu5_v1;
    int HLT_BTagMu_DiJet20_Mu5_v1;
    int HLT_BTagMu_DiJet40_Mu5_v1;
    int HLT_BTagMu_DiJet70_Mu5_v1;
    int HLT_BTagMu_Jet300_Mu5_v1;
    int HLT_CaloJet500_NoJetID_v1;
    int HLT_CaloJet500_NoJetID_v2;
    int HLT_CaloJet500_NoJetID_v3;
    int HLT_CaloJet500_NoJetID_v4;
    int HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1;
    int HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1;
    int HLT_DiCaloJetAve140_v1;
    int HLT_DiCaloJetAve200_v1;
    int HLT_DiCaloJetAve260_v1;
    int HLT_DiCaloJetAve320_v1;
    int HLT_DiCaloJetAve400_v1;
    int HLT_DiCaloJetAve40_v1;
    int HLT_DiCaloJetAve500_v1;
    int HLT_DiCaloJetAve60_v1;
    int HLT_DiCaloJetAve80_v1;
    int HLT_DiCentralPFJet170_CFMax0p1_v1;
    int HLT_DiCentralPFJet170_CFMax0p1_v3;
    int HLT_DiCentralPFJet170_v1;
    int HLT_DiCentralPFJet170_v3;
    int HLT_DiCentralPFJet220_CFMax0p3_v1;
    int HLT_DiCentralPFJet220_CFMax0p3_v3;
    int HLT_DiCentralPFJet330_CFMax0p5_v1;
    int HLT_DiCentralPFJet330_CFMax0p5_v3;
    int HLT_DiCentralPFJet430_v1;
    int HLT_DiCentralPFJet430_v3;
    int HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1;
    int HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1;
    int HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1;
    int HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1;
    int HLT_DiPFJetAve100_HFJEC_v1;
    int HLT_DiPFJetAve100_HFJEC_v3;
    int HLT_DiPFJetAve100_HFJEC_v4;
    int HLT_DiPFJetAve100_HFJEC_v6;
    int HLT_DiPFJetAve140_v2;
    int HLT_DiPFJetAve140_v3;
    int HLT_DiPFJetAve140_v5;
    int HLT_DiPFJetAve160_HFJEC_v1;
    int HLT_DiPFJetAve160_HFJEC_v3;
    int HLT_DiPFJetAve160_HFJEC_v4;
    int HLT_DiPFJetAve160_HFJEC_v6;
    int HLT_DiPFJetAve200_v2;
    int HLT_DiPFJetAve200_v3;
    int HLT_DiPFJetAve200_v5;
    int HLT_DiPFJetAve220_HFJEC_v1;
    int HLT_DiPFJetAve220_HFJEC_v3;
    int HLT_DiPFJetAve220_HFJEC_v4;
    int HLT_DiPFJetAve220_HFJEC_v6;
    int HLT_DiPFJetAve260_v2;
    int HLT_DiPFJetAve260_v3;
    int HLT_DiPFJetAve260_v5;
    int HLT_DiPFJetAve300_HFJEC_v1;
    int HLT_DiPFJetAve300_HFJEC_v3;
    int HLT_DiPFJetAve300_HFJEC_v4;
    int HLT_DiPFJetAve300_HFJEC_v6;
    int HLT_DiPFJetAve30_HFJEC_v1;
    int HLT_DiPFJetAve30_HFJEC_v3;
    int HLT_DiPFJetAve30_HFJEC_v4;
    int HLT_DiPFJetAve30_HFJEC_v5;
    int HLT_DiPFJetAve320_v2;
    int HLT_DiPFJetAve320_v3;
    int HLT_DiPFJetAve320_v5;
    int HLT_DiPFJetAve400_v2;
    int HLT_DiPFJetAve400_v3;
    int HLT_DiPFJetAve400_v5;
    int HLT_DiPFJetAve40_v2;
    int HLT_DiPFJetAve40_v3;
    int HLT_DiPFJetAve40_v6;
    int HLT_DiPFJetAve500_v2;
    int HLT_DiPFJetAve500_v3;
    int HLT_DiPFJetAve500_v5;
    int HLT_DiPFJetAve60_HFJEC_v1;
    int HLT_DiPFJetAve60_HFJEC_v3;
    int HLT_DiPFJetAve60_HFJEC_v4;
    int HLT_DiPFJetAve60_HFJEC_v6;
    int HLT_DiPFJetAve60_v2;
    int HLT_DiPFJetAve60_v3;
    int HLT_DiPFJetAve60_v6;
    int HLT_DiPFJetAve80_HFJEC_v1;
    int HLT_DiPFJetAve80_HFJEC_v3;
    int HLT_DiPFJetAve80_HFJEC_v4;
    int HLT_DiPFJetAve80_HFJEC_v6;
    int HLT_DiPFJetAve80_v2;
    int HLT_DiPFJetAve80_v3;
    int HLT_DiPFJetAve80_v5;
    int HLT_Dimuon0_Jpsi_Muon_v1;
    int HLT_Dimuon0_Upsilon_Muon_v1;
    int HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1;
    int HLT_Dimuon0er16_Jpsi_NoVertexing_v1;
    int HLT_Dimuon13_PsiPrime_v1;
    int HLT_Dimuon13_Upsilon_v1;
    int HLT_Dimuon20_Jpsi_v1;
    int HLT_Dimuon6_Jpsi_NoVertexing_v1;
    int HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
    int HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2;
    int HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6;
    int HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
    int HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2;
    int HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1;
    int HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1;
    int HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2;
    int HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6;
    int HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1;
    int HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2;
    int HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3;
    int HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7;
    int HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1;
    int HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2;
    int HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8;
    int HLT_DoubleEle33_CaloIdL_MW_v2;
    int HLT_DoubleEle33_CaloIdL_MW_v6;
    int HLT_DoubleEle33_CaloIdL_v2;
    int HLT_DoubleEle33_CaloIdL_v6;
    int HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2;
    int HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6;
    int HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8;
    int HLT_DoubleIsoMu17_eta2p1_v1;
    int HLT_DoubleJet90_Double30_DoubleCSV0p5_v1;
    int HLT_DoubleJet90_Double30_TripleCSV0p5_v1;
    int HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1;
    int HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1;
    int HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1;
    int HLT_DoubleMu33NoFiltersNoVtx_v1;
    int HLT_DoubleMu38NoFiltersNoVtx_v1;
    int HLT_DoubleMu4_3_Bs_v1;
    int HLT_DoubleMu4_3_Jpsi_Displaced_v1;
    int HLT_DoubleMu4_JpsiTrk_Displaced_v1;
    int HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1;
    int HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1;
    int HLT_DoubleMu8_Mass8_PFHT300_v1;
    int HLT_DoublePhoton40_v1;
    int HLT_DoublePhoton50_v1;
    int HLT_DoublePhoton60_v1;
    int HLT_DoublePhoton60_v2;
    int HLT_DoublePhoton60_v6;
    int HLT_DoublePhoton85_v1;
    int HLT_DoublePhoton85_v2;
    int HLT_DoublePhoton85_v3;
    int HLT_DoublePhoton85_v7;
    int HLT_ECALHT800_v2;
    int HLT_ECALHT800_v3;
    int HLT_ECALHT800_v4;
    int HLT_Ele105_CaloIdVT_GsfTrkIdT_v1;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5;
    int HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7;
    int HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4;
    int HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7;
    int HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1;
    int HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1;
    int HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1;
    int HLT_Ele15_IsoVVVL_PFHT600_v1;
    int HLT_Ele15_PFHT300_v1;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7;
    int HLT_Ele17_CaloIdL_GsfTrkIdVL_v2;
    int HLT_Ele17_CaloIdL_GsfTrkIdVL_v5;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6;
    int HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2;
    int HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8;
    int HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1;
    int HLT_Ele20WP60_Ele8_Mass55_v1;
    int HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1;
    int HLT_Ele22_eta2p1_WP85_Gsf_v1;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7;
    int HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4;
    int HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7;
    int HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8;
    int HLT_Ele25WP60_SC4_Mass55_v1;
    int HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1;
    int HLT_Ele27_HighEta_Ele20_Mass55_v2;
    int HLT_Ele27_HighEta_Ele20_Mass55_v6;
    int HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1;
    int HLT_Ele27_eta2p1_WP85_Gsf_v1;
    int HLT_Ele30WP60_Ele8_Mass55_v2;
    int HLT_Ele30WP60_Ele8_Mass55_v3;
    int HLT_Ele30WP60_Ele8_Mass55_v7;
    int HLT_Ele30WP60_SC4_Mass55_v3;
    int HLT_Ele30WP60_SC4_Mass55_v4;
    int HLT_Ele30WP60_SC4_Mass55_v8;
    int HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1;
    int HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1;
    int HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1;
    int HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1;
    int HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1;
    int HLT_Ele32_eta2p1_WP85_Gsf_v1;
    int HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1;
    int HLT_Ele35_eta2p1_WP85_Gsf_v1;
    int HLT_Ele40_eta2p1_WP85_Gsf_v1;
    int HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1;
    int HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2;
    int HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7;
    int HLT_HT2000_v1;
    int HLT_HT2000_v2;
    int HLT_HT2000_v3;
    int HLT_HT200_DiJet90_AlphaT0p57_v1;
    int HLT_HT200_v1;
    int HLT_HT2500_v1;
    int HLT_HT2500_v2;
    int HLT_HT2500_v3;
    int HLT_HT250_DiJet90_AlphaT0p55_v1;
    int HLT_HT250_DisplacedDijet40_DisplacedTrack_v2;
    int HLT_HT250_v1;
    int HLT_HT275_v1;
    int HLT_HT300_DiJet90_AlphaT0p53_v1;
    int HLT_HT300_v1;
    int HLT_HT325_v1;
    int HLT_HT350_DiJet90_AlphaT0p52_v1;
    int HLT_HT350_DisplacedDijet40_DisplacedTrack_v2;
    int HLT_HT350_DisplacedDijet80_DisplacedTrack_v1;
    int HLT_HT350_DisplacedDijet80_DisplacedTrack_v2;
    int HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1;
    int HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2;
    int HLT_HT350_v1;
    int HLT_HT400_DiJet90_AlphaT0p51_v1;
    int HLT_HT400_DisplacedDijet40_Inclusive_v2;
    int HLT_HT400_v1;
    int HLT_HT425_v1;
    int HLT_HT500_DisplacedDijet40_Inclusive_v2;
    int HLT_HT550_DisplacedDijet40_Inclusive_v2;
    int HLT_HT575_v1;
    int HLT_HT650_DisplacedDijet80_Inclusive_v1;
    int HLT_HT650_DisplacedDijet80_Inclusive_v2;
    int HLT_HT750_DisplacedDijet80_Inclusive_v1;
    int HLT_HT750_DisplacedDijet80_Inclusive_v2;
    int HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1;
    int HLT_IsoMu16_eta2p1_CaloMET30_v1;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1;
    int HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1;
    int HLT_IsoMu17_eta2p1_v1;
    int HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1;
    int HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1;
    int HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1;
    int HLT_IsoMu20_eta2p1_v1;
    int HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1;
    int HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1;
    int HLT_IsoMu24_eta2p1_v1;
    int HLT_IsoMu27_v1;
    int HLT_IsoTkMu20_eta2p1_v1;
    int HLT_IsoTkMu24_eta2p1_v1;
    int HLT_IsoTkMu27_v1;
    int HLT_JetE30_NoBPTX3BX_NoHalo_v1;
    int HLT_JetE30_NoBPTX_v1;
    int HLT_JetE50_NoBPTX3BX_NoHalo_v1;
    int HLT_JetE70_NoBPTX3BX_NoHalo_v1;
    int HLT_L1_TripleJet_VBF_v1;
    int HLT_L1_TripleJet_VBF_v4;
    int HLT_L1_TripleJet_VBF_v5;
    int HLT_L2DoubleMu23_NoVertex_v1;
    int HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1;
    int HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1;
    int HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1;
    int HLT_L2Mu10_NoVertex_NoBPTX_v1;
    int HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1;
    int HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1;
    int HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1;
    int HLT_LooseIsoPFTau50_Trk30_eta2p1_v1;
    int HLT_MET75_IsoTrk50_v1;
    int HLT_MET90_IsoTrk50_v1;
    int HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1;
    int HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1;
    int HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1;
    int HLT_Mu10_CentralPFJet40_BTagCSV_v1;
    int HLT_Mu12_Photon25_CaloIdL_L1ISO_v1;
    int HLT_Mu12_Photon25_CaloIdL_L1OR_v1;
    int HLT_Mu12_Photon25_CaloIdL_v1;
    int HLT_Mu14er_PFMET120_NoiseCleaned_v1;
    int HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1;
    int HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1;
    int HLT_Mu15_IsoVVVL_PFHT600_v1;
    int HLT_Mu15_PFHT300_v1;
    int HLT_Mu16_eta2p1_CaloMET30_v1;
    int HLT_Mu17_Mu8_DZ_v1;
    int HLT_Mu17_Mu8_SameSign_DPhi_v1;
    int HLT_Mu17_Mu8_SameSign_v1;
    int HLT_Mu17_Photon30_CaloIdL_L1ISO_v1;
    int HLT_Mu17_Photon35_CaloIdL_L1ISO_v1;
    int HLT_Mu17_TkMu8_DZ_v1;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1;
    int HLT_Mu17_TrkIsoVVL_v1;
    int HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1;
    int HLT_Mu24_TrkIsoVVL_v1;
    int HLT_Mu24_eta2p1_v1;
    int HLT_Mu25_TkMu0_dEta18_Onia_v1;
    int HLT_Mu27_v1;
    int HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1;
    int HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1;
    int HLT_Mu30_TkMu11_v1;
    int HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1;
    int HLT_Mu34_TrkIsoVVL_v1;
    int HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1;
    int HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1;
    int HLT_Mu40_eta2p1_PFJet200_PFJet50_v1;
    int HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1;
    int HLT_Mu45_eta2p1_v1;
    int HLT_Mu50_v1;
    int HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1;
    int HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1;
    int HLT_Mu7p5_L2Mu2_Jpsi_v1;
    int HLT_Mu7p5_L2Mu2_Upsilon_v1;
    int HLT_Mu7p5_Track2_Jpsi_v1;
    int HLT_Mu7p5_Track2_Upsilon_v1;
    int HLT_Mu7p5_Track3p5_Jpsi_v1;
    int HLT_Mu7p5_Track3p5_Upsilon_v1;
    int HLT_Mu7p5_Track7_Jpsi_v1;
    int HLT_Mu7p5_Track7_Upsilon_v1;
    int HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1;
    int HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1;
    int HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1;
    int HLT_Mu8_TrkIsoVVL_v1;
    int HLT_PFHT125_v2;
    int HLT_PFHT125_v3;
    int HLT_PFHT200_v2;
    int HLT_PFHT200_v3;
    int HLT_PFHT200_v4;
    int HLT_PFHT250_v2;
    int HLT_PFHT250_v3;
    int HLT_PFHT250_v4;
    int HLT_PFHT300_v2;
    int HLT_PFHT300_v3;
    int HLT_PFHT300_v5;
    int HLT_PFHT350_PFMET120_NoiseCleaned_v1;
    int HLT_PFHT350_v1;
    int HLT_PFHT350_v3;
    int HLT_PFHT350_v4;
    int HLT_PFHT350_v6;
    int HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3;
    int HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2;
    int HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3;
    int HLT_PFHT400_SixJet30_v3;
    int HLT_PFHT400_SixJet30_v4;
    int HLT_PFHT400_SixJet30_v5;
    int HLT_PFHT400_v2;
    int HLT_PFHT400_v3;
    int HLT_PFHT400_v5;
    int HLT_PFHT450_SixJet40_BTagCSV_p056_v2;
    int HLT_PFHT450_SixJet40_BTagCSV_p056_v3;
    int HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3;
    int HLT_PFHT450_SixJet40_v3;
    int HLT_PFHT450_SixJet40_v4;
    int HLT_PFHT450_SixJet40_v5;
    int HLT_PFHT475_v2;
    int HLT_PFHT475_v3;
    int HLT_PFHT475_v5;
    int HLT_PFHT550_4JetPt50_v1;
    int HLT_PFHT550_4JetPt50_v2;
    int HLT_PFHT550_4JetPt50_v4;
    int HLT_PFHT550_4Jet_v1;
    int HLT_PFHT600_v1;
    int HLT_PFHT600_v3;
    int HLT_PFHT600_v4;
    int HLT_PFHT600_v6;
    int HLT_PFHT650_4JetPt50_v1;
    int HLT_PFHT650_4JetPt50_v2;
    int HLT_PFHT650_4JetPt50_v4;
    int HLT_PFHT650_4Jet_v1;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6;
    int HLT_PFHT650_v1;
    int HLT_PFHT650_v3;
    int HLT_PFHT650_v4;
    int HLT_PFHT650_v6;
    int HLT_PFHT750_4JetPt50_v3;
    int HLT_PFHT750_4JetPt50_v4;
    int HLT_PFHT750_4JetPt50_v6;
    int HLT_PFHT750_4Jet_v1;
    int HLT_PFHT800_v2;
    int HLT_PFHT800_v3;
    int HLT_PFHT800_v5;
    int HLT_PFHT900_v1;
    int HLT_PFHT900_v2;
    int HLT_PFHT900_v4;
    int HLT_PFJet140_v1;
    int HLT_PFJet140_v4;
    int HLT_PFJet140_v5;
    int HLT_PFJet140_v6;
    int HLT_PFJet200_v1;
    int HLT_PFJet200_v4;
    int HLT_PFJet200_v5;
    int HLT_PFJet200_v6;
    int HLT_PFJet260_v1;
    int HLT_PFJet260_v4;
    int HLT_PFJet260_v5;
    int HLT_PFJet260_v6;
    int HLT_PFJet320_v1;
    int HLT_PFJet320_v4;
    int HLT_PFJet320_v5;
    int HLT_PFJet320_v6;
    int HLT_PFJet400_v1;
    int HLT_PFJet400_v4;
    int HLT_PFJet400_v5;
    int HLT_PFJet400_v6;
    int HLT_PFJet40_v1;
    int HLT_PFJet40_v4;
    int HLT_PFJet40_v5;
    int HLT_PFJet40_v7;
    int HLT_PFJet450_v1;
    int HLT_PFJet450_v4;
    int HLT_PFJet450_v5;
    int HLT_PFJet450_v6;
    int HLT_PFJet500_v1;
    int HLT_PFJet500_v4;
    int HLT_PFJet500_v5;
    int HLT_PFJet500_v6;
    int HLT_PFJet60_v1;
    int HLT_PFJet60_v4;
    int HLT_PFJet60_v5;
    int HLT_PFJet60_v7;
    int HLT_PFJet80_v1;
    int HLT_PFJet80_v4;
    int HLT_PFJet80_v5;
    int HLT_PFJet80_v6;
    int HLT_PFMET120_NoiseCleaned_BTagCSV07_v1;
    int HLT_PFMET120_NoiseCleaned_Mu5_v1;
    int HLT_PFMET120_PFMHT120_IDLoose_v1;
    int HLT_PFMET170_NoiseCleaned_v1;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon120_R9Id90_HE10_Iso40_v1;
    int HLT_Photon120_R9Id90_HE10_IsoM_v3;
    int HLT_Photon120_R9Id90_HE10_IsoM_v4;
    int HLT_Photon120_R9Id90_HE10_IsoM_v7;
    int HLT_Photon120_v1;
    int HLT_Photon120_v3;
    int HLT_Photon120_v4;
    int HLT_Photon120_v6;
    int HLT_Photon125_v1;
    int HLT_Photon125_v2;
    int HLT_Photon125_v4;
    int HLT_Photon135_PFMET100_NoiseCleaned_v1;
    int HLT_Photon135_PFMET100_v1;
    int HLT_Photon135_PFMET100_v2;
    int HLT_Photon135_PFMET100_v6;
    int HLT_Photon135_PFMET40_v1;
    int HLT_Photon135_VBF_v1;
    int HLT_Photon150_v1;
    int HLT_Photon150_v2;
    int HLT_Photon150_v4;
    int HLT_Photon155_R9Id90_HE10_Iso40_v1;
    int HLT_Photon165_HE10_v1;
    int HLT_Photon165_HE10_v3;
    int HLT_Photon165_HE10_v4;
    int HLT_Photon165_HE10_v7;
    int HLT_Photon165_R9Id90_HE10_IsoM_v3;
    int HLT_Photon165_R9Id90_HE10_IsoM_v4;
    int HLT_Photon165_R9Id90_HE10_IsoM_v8;
    int HLT_Photon175_v1;
    int HLT_Photon175_v3;
    int HLT_Photon175_v4;
    int HLT_Photon175_v7;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon22_R9Id90_HE10_Iso40_v1;
    int HLT_Photon22_R9Id90_HE10_IsoM_v2;
    int HLT_Photon22_R9Id90_HE10_IsoM_v3;
    int HLT_Photon22_R9Id90_HE10_IsoM_v6;
    int HLT_Photon22_v1;
    int HLT_Photon22_v2;
    int HLT_Photon22_v3;
    int HLT_Photon22_v5;
    int HLT_Photon250_NoHE_v1;
    int HLT_Photon250_NoHE_v2;
    int HLT_Photon250_NoHE_v3;
    int HLT_Photon250_NoHE_v6;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7;
    int HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1;
    int HLT_Photon300_NoHE_v1;
    int HLT_Photon300_NoHE_v2;
    int HLT_Photon300_NoHE_v3;
    int HLT_Photon300_NoHE_v6;
    int HLT_Photon30_R9Id90_HE10_Iso40_v1;
    int HLT_Photon30_R9Id90_HE10_IsoM_v3;
    int HLT_Photon30_R9Id90_HE10_IsoM_v4;
    int HLT_Photon30_R9Id90_HE10_IsoM_v7;
    int HLT_Photon30_v1;
    int HLT_Photon30_v3;
    int HLT_Photon30_v4;
    int HLT_Photon30_v6;
    int HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1;
    int HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon36_R9Id90_HE10_Iso40_v1;
    int HLT_Photon36_R9Id90_HE10_IsoM_v3;
    int HLT_Photon36_R9Id90_HE10_IsoM_v4;
    int HLT_Photon36_R9Id90_HE10_IsoM_v7;
    int HLT_Photon36_v1;
    int HLT_Photon36_v3;
    int HLT_Photon36_v4;
    int HLT_Photon36_v6;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7;
    int HLT_Photon500_v1;
    int HLT_Photon500_v2;
    int HLT_Photon500_v5;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon50_R9Id90_HE10_Iso40_v1;
    int HLT_Photon50_R9Id90_HE10_IsoM_v3;
    int HLT_Photon50_R9Id90_HE10_IsoM_v4;
    int HLT_Photon50_R9Id90_HE10_IsoM_v7;
    int HLT_Photon50_v1;
    int HLT_Photon50_v3;
    int HLT_Photon50_v4;
    int HLT_Photon50_v6;
    int HLT_Photon600_v1;
    int HLT_Photon600_v2;
    int HLT_Photon600_v5;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon75_R9Id90_HE10_Iso40_v1;
    int HLT_Photon75_R9Id90_HE10_IsoM_v3;
    int HLT_Photon75_R9Id90_HE10_IsoM_v4;
    int HLT_Photon75_R9Id90_HE10_IsoM_v7;
    int HLT_Photon75_v1;
    int HLT_Photon75_v3;
    int HLT_Photon75_v4;
    int HLT_Photon75_v6;
    int HLT_Photon90_CaloIdL_HT300_v1;
    int HLT_Photon90_CaloIdL_HT300_v2;
    int HLT_Photon90_CaloIdL_HT300_v4;
    int HLT_Photon90_CaloIdL_PFHT500_v1;
    int HLT_Photon90_CaloIdL_PFHT500_v3;
    int HLT_Photon90_CaloIdL_PFHT500_v4;
    int HLT_Photon90_CaloIdL_PFHT500_v7;
    int HLT_Photon90_CaloIdL_PFHT600_v2;
    int HLT_Photon90_CaloIdL_PFHT600_v3;
    int HLT_Photon90_CaloIdL_PFHT600_v6;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6;
    int HLT_Photon90_R9Id90_HE10_Iso40_v1;
    int HLT_Photon90_R9Id90_HE10_IsoM_v3;
    int HLT_Photon90_R9Id90_HE10_IsoM_v4;
    int HLT_Photon90_R9Id90_HE10_IsoM_v7;
    int HLT_Photon90_v1;
    int HLT_Photon90_v3;
    int HLT_Photon90_v4;
    int HLT_Photon90_v6;
    int HLT_Physics_v1;
    int HLT_PixelTracks_Multiplicity110_v1;
    int HLT_PixelTracks_Multiplicity135_v1;
    int HLT_PixelTracks_Multiplicity160_v1;
    int HLT_PixelTracks_Multiplicity60_v1;
    int HLT_PixelTracks_Multiplicity85_v1;
    int HLT_QuadJet45_DoubleCSV0p5_v1;
    int HLT_QuadJet45_TripleCSV0p5_v1;
    int HLT_QuadMuon0_Dimuon0_Jpsi_v1;
    int HLT_QuadMuon0_Dimuon0_Upsilon_v1;
    int HLT_QuadPFJet_BTagCSV_VBF_v1;
    int HLT_QuadPFJet_VBF_v1;
    int HLT_QuadPFJet_VBF_v4;
    int HLT_QuadPFJet_VBF_v5;
    int HLT_QuadPFJet_VBF_v6;
    int HLT_Rsq0p36_v1;
    int HLT_RsqMR260_Rsq0p09_MR200_4jet_v1;
    int HLT_RsqMR260_Rsq0p09_MR200_v1;
    int HLT_RsqMR300_Rsq0p09_MR200_4jet_v1;
    int HLT_RsqMR300_Rsq0p09_MR200_v1;
    int HLT_SingleCentralPFJet170_CFMax0p1_v1;
    int HLT_SingleCentralPFJet170_CFMax0p1_v3;
    int HLT_TkMu24_eta2p1_v1;
    int HLT_TkMu27_v1;
    int HLT_TripleMu_12_10_5_v1;
    int HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2;
    int HLT_VBF_DisplacedJet40_DisplacedTrack_v2;
    int HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2;
    int HLT_VBF_DisplacedJet40_Hadronic_v2;
    int HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2;
    int HLT_VBF_DisplacedJet40_TightID_Hadronic_v2;
    int HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2;
    int HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2;
    int HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2;
    int HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2;
    int HLT_ZeroBias_v1;



  };

  std::string triggerBranchDefString("HLT_AK4PFDJet60_Eta2p1ForPPRef_v1/I:HLT_AK4PFDJet60_Eta2p1ForPPRef_v2:HLT_AK4PFDJet60_Eta2p1ForPPRef_v3:HLT_AK4PFDJet80_Eta2p1ForPPRef_v1:HLT_AK4PFDJet80_Eta2p1ForPPRef_v2:HLT_AK4PFDJet80_Eta2p1ForPPRef_v3:HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2:HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2:HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3:HLT_AK8DiPFJet250_200_TrimMass30_v2:HLT_AK8DiPFJet250_200_TrimMass30_v3:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3:HLT_AK8DiPFJet280_200_TrimMass30_v2:HLT_AK8DiPFJet280_200_TrimMass30_v3:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4:HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2:HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3:HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6:HLT_AK8PFJet140_v1:HLT_AK8PFJet140_v2:HLT_AK8PFJet200_v1:HLT_AK8PFJet200_v2:HLT_AK8PFJet260_v1:HLT_AK8PFJet260_v2:HLT_AK8PFJet320_v1:HLT_AK8PFJet320_v2:HLT_AK8PFJet360TrimMod_Mass30_v1:HLT_AK8PFJet360_TrimMass30_v3:HLT_AK8PFJet360_TrimMass30_v4:HLT_AK8PFJet360_TrimMass30_v5:HLT_AK8PFJet400_v1:HLT_AK8PFJet400_v2:HLT_AK8PFJet40_v1:HLT_AK8PFJet40_v3:HLT_AK8PFJet450_v1:HLT_AK8PFJet450_v2:HLT_AK8PFJet500_v1:HLT_AK8PFJet500_v2:HLT_AK8PFJet60_v1:HLT_AK8PFJet60_v2:HLT_AK8PFJet80_v1:HLT_AK8PFJet80_v2:HLT_BTagMu_DiJet110_Mu5_v1:HLT_BTagMu_DiJet20_Mu5_v1:HLT_BTagMu_DiJet40_Mu5_v1:HLT_BTagMu_DiJet70_Mu5_v1:HLT_BTagMu_Jet300_Mu5_v1:HLT_CaloJet500_NoJetID_v1:HLT_CaloJet500_NoJetID_v2:HLT_CaloJet500_NoJetID_v3:HLT_CaloJet500_NoJetID_v4:HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1:HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1:HLT_DiCaloJetAve140_v1:HLT_DiCaloJetAve200_v1:HLT_DiCaloJetAve260_v1:HLT_DiCaloJetAve320_v1:HLT_DiCaloJetAve400_v1:HLT_DiCaloJetAve40_v1:HLT_DiCaloJetAve500_v1:HLT_DiCaloJetAve60_v1:HLT_DiCaloJetAve80_v1:HLT_DiCentralPFJet170_CFMax0p1_v1:HLT_DiCentralPFJet170_CFMax0p1_v3:HLT_DiCentralPFJet170_v1:HLT_DiCentralPFJet170_v3:HLT_DiCentralPFJet220_CFMax0p3_v1:HLT_DiCentralPFJet220_CFMax0p3_v3:HLT_DiCentralPFJet330_CFMax0p5_v1:HLT_DiCentralPFJet330_CFMax0p5_v3:HLT_DiCentralPFJet430_v1:HLT_DiCentralPFJet430_v3:HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1:HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1:HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1:HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1:HLT_DiPFJetAve100_HFJEC_v1:HLT_DiPFJetAve100_HFJEC_v3:HLT_DiPFJetAve100_HFJEC_v4:HLT_DiPFJetAve100_HFJEC_v6:HLT_DiPFJetAve140_v2:HLT_DiPFJetAve140_v3:HLT_DiPFJetAve140_v5:HLT_DiPFJetAve160_HFJEC_v1:HLT_DiPFJetAve160_HFJEC_v3:HLT_DiPFJetAve160_HFJEC_v4:HLT_DiPFJetAve160_HFJEC_v6:HLT_DiPFJetAve200_v2:HLT_DiPFJetAve200_v3:HLT_DiPFJetAve200_v5:HLT_DiPFJetAve220_HFJEC_v1:HLT_DiPFJetAve220_HFJEC_v3:HLT_DiPFJetAve220_HFJEC_v4:HLT_DiPFJetAve220_HFJEC_v6:HLT_DiPFJetAve260_v2:HLT_DiPFJetAve260_v3:HLT_DiPFJetAve260_v5:HLT_DiPFJetAve300_HFJEC_v1:HLT_DiPFJetAve300_HFJEC_v3:HLT_DiPFJetAve300_HFJEC_v4:HLT_DiPFJetAve300_HFJEC_v6:HLT_DiPFJetAve30_HFJEC_v1:HLT_DiPFJetAve30_HFJEC_v3:HLT_DiPFJetAve30_HFJEC_v4:HLT_DiPFJetAve30_HFJEC_v5:HLT_DiPFJetAve320_v2:HLT_DiPFJetAve320_v3:HLT_DiPFJetAve320_v5:HLT_DiPFJetAve400_v2:HLT_DiPFJetAve400_v3:HLT_DiPFJetAve400_v5:HLT_DiPFJetAve40_v2:HLT_DiPFJetAve40_v3:HLT_DiPFJetAve40_v6:HLT_DiPFJetAve500_v2:HLT_DiPFJetAve500_v3:HLT_DiPFJetAve500_v5:HLT_DiPFJetAve60_HFJEC_v1:HLT_DiPFJetAve60_HFJEC_v3:HLT_DiPFJetAve60_HFJEC_v4:HLT_DiPFJetAve60_HFJEC_v6:HLT_DiPFJetAve60_v2:HLT_DiPFJetAve60_v3:HLT_DiPFJetAve60_v6:HLT_DiPFJetAve80_HFJEC_v1:HLT_DiPFJetAve80_HFJEC_v3:HLT_DiPFJetAve80_HFJEC_v4:HLT_DiPFJetAve80_HFJEC_v6:HLT_DiPFJetAve80_v2:HLT_DiPFJetAve80_v3:HLT_DiPFJetAve80_v5:HLT_Dimuon0_Jpsi_Muon_v1:HLT_Dimuon0_Upsilon_Muon_v1:HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1:HLT_Dimuon0er16_Jpsi_NoVertexing_v1:HLT_Dimuon13_PsiPrime_v1:HLT_Dimuon13_Upsilon_v1:HLT_Dimuon20_Jpsi_v1:HLT_Dimuon6_Jpsi_NoVertexing_v1:HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1:HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2:HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6:HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1:HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2:HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1:HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1:HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2:HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6:HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1:HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2:HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3:HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7:HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1:HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2:HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8:HLT_DoubleEle33_CaloIdL_MW_v2:HLT_DoubleEle33_CaloIdL_MW_v6:HLT_DoubleEle33_CaloIdL_v2:HLT_DoubleEle33_CaloIdL_v6:HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2:HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6:HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8:HLT_DoubleIsoMu17_eta2p1_v1:HLT_DoubleJet90_Double30_DoubleCSV0p5_v1:HLT_DoubleJet90_Double30_TripleCSV0p5_v1:HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1:HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1:HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1:HLT_DoubleMu33NoFiltersNoVtx_v1:HLT_DoubleMu38NoFiltersNoVtx_v1:HLT_DoubleMu4_3_Bs_v1:HLT_DoubleMu4_3_Jpsi_Displaced_v1:HLT_DoubleMu4_JpsiTrk_Displaced_v1:HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1:HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1:HLT_DoubleMu8_Mass8_PFHT300_v1:HLT_DoublePhoton40_v1:HLT_DoublePhoton50_v1:HLT_DoublePhoton60_v1:HLT_DoublePhoton60_v2:HLT_DoublePhoton60_v6:HLT_DoublePhoton85_v1:HLT_DoublePhoton85_v2:HLT_DoublePhoton85_v3:HLT_DoublePhoton85_v7:HLT_ECALHT800_v2:HLT_ECALHT800_v3:HLT_ECALHT800_v4:HLT_Ele105_CaloIdVT_GsfTrkIdT_v1:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5:HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7:HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4:HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7:HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1:HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1:HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1:HLT_Ele15_IsoVVVL_PFHT600_v1:HLT_Ele15_PFHT300_v1:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7:HLT_Ele17_CaloIdL_GsfTrkIdVL_v2:HLT_Ele17_CaloIdL_GsfTrkIdVL_v5:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6:HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2:HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8:HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1:HLT_Ele20WP60_Ele8_Mass55_v1:HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1:HLT_Ele22_eta2p1_WP85_Gsf_v1:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7:HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4:HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7:HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8:HLT_Ele25WP60_SC4_Mass55_v1:HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1:HLT_Ele27_HighEta_Ele20_Mass55_v2:HLT_Ele27_HighEta_Ele20_Mass55_v6:HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1:HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1:HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1:HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1:HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1:HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1:HLT_Ele27_eta2p1_WP85_Gsf_v1:HLT_Ele30WP60_Ele8_Mass55_v2:HLT_Ele30WP60_Ele8_Mass55_v3:HLT_Ele30WP60_Ele8_Mass55_v7:HLT_Ele30WP60_SC4_Mass55_v3:HLT_Ele30WP60_SC4_Mass55_v4:HLT_Ele30WP60_SC4_Mass55_v8:HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1:HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1:HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1:HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1:HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1:HLT_Ele32_eta2p1_WP85_Gsf_v1:HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1:HLT_Ele35_eta2p1_WP85_Gsf_v1:HLT_Ele40_eta2p1_WP85_Gsf_v1:HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1:HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2:HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5:HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4:HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7:HLT_HT2000_v1:HLT_HT2000_v2:HLT_HT2000_v3:HLT_HT200_DiJet90_AlphaT0p57_v1:HLT_HT200_v1:HLT_HT2500_v1:HLT_HT2500_v2:HLT_HT2500_v3:HLT_HT250_DiJet90_AlphaT0p55_v1:HLT_HT250_DisplacedDijet40_DisplacedTrack_v2:HLT_HT250_v1:HLT_HT275_v1:HLT_HT300_DiJet90_AlphaT0p53_v1:HLT_HT300_v1:HLT_HT325_v1:HLT_HT350_DiJet90_AlphaT0p52_v1:HLT_HT350_DisplacedDijet40_DisplacedTrack_v2:HLT_HT350_DisplacedDijet80_DisplacedTrack_v1:HLT_HT350_DisplacedDijet80_DisplacedTrack_v2:HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1:HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2:HLT_HT350_v1:HLT_HT400_DiJet90_AlphaT0p51_v1:HLT_HT400_DisplacedDijet40_Inclusive_v2:HLT_HT400_v1:HLT_HT425_v1:HLT_HT500_DisplacedDijet40_Inclusive_v2:HLT_HT550_DisplacedDijet40_Inclusive_v2:HLT_HT575_v1:HLT_HT650_DisplacedDijet80_Inclusive_v1:HLT_HT650_DisplacedDijet80_Inclusive_v2:HLT_HT750_DisplacedDijet80_Inclusive_v1:HLT_HT750_DisplacedDijet80_Inclusive_v2:HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1:HLT_IsoMu16_eta2p1_CaloMET30_v1:HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1:HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1:HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1:HLT_IsoMu17_eta2p1_v1:HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1:HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1:HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1:HLT_IsoMu20_eta2p1_v1:HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1:HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1:HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1:HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1:HLT_IsoMu24_eta2p1_v1:HLT_IsoMu27_v1:HLT_IsoTkMu20_eta2p1_v1:HLT_IsoTkMu24_eta2p1_v1:HLT_IsoTkMu27_v1:HLT_JetE30_NoBPTX3BX_NoHalo_v1:HLT_JetE30_NoBPTX_v1:HLT_JetE50_NoBPTX3BX_NoHalo_v1:HLT_JetE70_NoBPTX3BX_NoHalo_v1:HLT_L1_TripleJet_VBF_v1:HLT_L1_TripleJet_VBF_v4:HLT_L1_TripleJet_VBF_v5:HLT_L2DoubleMu23_NoVertex_v1:HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1:HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1:HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1:HLT_L2Mu10_NoVertex_NoBPTX_v1:HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1:HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1:HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1:HLT_LooseIsoPFTau50_Trk30_eta2p1_v1:HLT_MET75_IsoTrk50_v1:HLT_MET90_IsoTrk50_v1:HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1:HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1:HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1:HLT_Mu10_CentralPFJet40_BTagCSV_v1:HLT_Mu12_Photon25_CaloIdL_L1ISO_v1:HLT_Mu12_Photon25_CaloIdL_L1OR_v1:HLT_Mu12_Photon25_CaloIdL_v1:HLT_Mu14er_PFMET120_NoiseCleaned_v1:HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1:HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1:HLT_Mu15_IsoVVVL_PFHT600_v1:HLT_Mu15_PFHT300_v1:HLT_Mu16_eta2p1_CaloMET30_v1:HLT_Mu17_Mu8_DZ_v1:HLT_Mu17_Mu8_SameSign_DPhi_v1:HLT_Mu17_Mu8_SameSign_v1:HLT_Mu17_Photon30_CaloIdL_L1ISO_v1:HLT_Mu17_Photon35_CaloIdL_L1ISO_v1:HLT_Mu17_TkMu8_DZ_v1:HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1:HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1:HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1:HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1:HLT_Mu17_TrkIsoVVL_v1:HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1:HLT_Mu24_TrkIsoVVL_v1:HLT_Mu24_eta2p1_v1:HLT_Mu25_TkMu0_dEta18_Onia_v1:HLT_Mu27_v1:HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1:HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1:HLT_Mu30_TkMu11_v1:HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1:HLT_Mu34_TrkIsoVVL_v1:HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1:HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1:HLT_Mu40_eta2p1_PFJet200_PFJet50_v1:HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1:HLT_Mu45_eta2p1_v1:HLT_Mu50_v1:HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1:HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1:HLT_Mu7p5_L2Mu2_Jpsi_v1:HLT_Mu7p5_L2Mu2_Upsilon_v1:HLT_Mu7p5_Track2_Jpsi_v1:HLT_Mu7p5_Track2_Upsilon_v1:HLT_Mu7p5_Track3p5_Jpsi_v1:HLT_Mu7p5_Track3p5_Upsilon_v1:HLT_Mu7p5_Track7_Jpsi_v1:HLT_Mu7p5_Track7_Upsilon_v1:HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1:HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1:HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1:HLT_Mu8_TrkIsoVVL_v1:HLT_PFHT125_v2:HLT_PFHT125_v3:HLT_PFHT200_v2:HLT_PFHT200_v3:HLT_PFHT200_v4:HLT_PFHT250_v2:HLT_PFHT250_v3:HLT_PFHT250_v4:HLT_PFHT300_v2:HLT_PFHT300_v3:HLT_PFHT300_v5:HLT_PFHT350_PFMET120_NoiseCleaned_v1:HLT_PFHT350_v1:HLT_PFHT350_v3:HLT_PFHT350_v4:HLT_PFHT350_v6:HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3:HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2:HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3:HLT_PFHT400_SixJet30_v3:HLT_PFHT400_SixJet30_v4:HLT_PFHT400_SixJet30_v5:HLT_PFHT400_v2:HLT_PFHT400_v3:HLT_PFHT400_v5:HLT_PFHT450_SixJet40_BTagCSV_p056_v2:HLT_PFHT450_SixJet40_BTagCSV_p056_v3:HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3:HLT_PFHT450_SixJet40_v3:HLT_PFHT450_SixJet40_v4:HLT_PFHT450_SixJet40_v5:HLT_PFHT475_v2:HLT_PFHT475_v3:HLT_PFHT475_v5:HLT_PFHT550_4JetPt50_v1:HLT_PFHT550_4JetPt50_v2:HLT_PFHT550_4JetPt50_v4:HLT_PFHT550_4Jet_v1:HLT_PFHT600_v1:HLT_PFHT600_v3:HLT_PFHT600_v4:HLT_PFHT600_v6:HLT_PFHT650_4JetPt50_v1:HLT_PFHT650_4JetPt50_v2:HLT_PFHT650_4JetPt50_v4:HLT_PFHT650_4Jet_v1:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6:HLT_PFHT650_v1:HLT_PFHT650_v3:HLT_PFHT650_v4:HLT_PFHT650_v6:HLT_PFHT750_4JetPt50_v3:HLT_PFHT750_4JetPt50_v4:HLT_PFHT750_4JetPt50_v6:HLT_PFHT750_4Jet_v1:HLT_PFHT800_v2:HLT_PFHT800_v3:HLT_PFHT800_v5:HLT_PFHT900_v1:HLT_PFHT900_v2:HLT_PFHT900_v4:HLT_PFJet140_v1:HLT_PFJet140_v4:HLT_PFJet140_v5:HLT_PFJet140_v6:HLT_PFJet200_v1:HLT_PFJet200_v4:HLT_PFJet200_v5:HLT_PFJet200_v6:HLT_PFJet260_v1:HLT_PFJet260_v4:HLT_PFJet260_v5:HLT_PFJet260_v6:HLT_PFJet320_v1:HLT_PFJet320_v4:HLT_PFJet320_v5:HLT_PFJet320_v6:HLT_PFJet400_v1:HLT_PFJet400_v4:HLT_PFJet400_v5:HLT_PFJet400_v6:HLT_PFJet40_v1:HLT_PFJet40_v4:HLT_PFJet40_v5:HLT_PFJet40_v7:HLT_PFJet450_v1:HLT_PFJet450_v4:HLT_PFJet450_v5:HLT_PFJet450_v6:HLT_PFJet500_v1:HLT_PFJet500_v4:HLT_PFJet500_v5:HLT_PFJet500_v6:HLT_PFJet60_v1:HLT_PFJet60_v4:HLT_PFJet60_v5:HLT_PFJet60_v7:HLT_PFJet80_v1:HLT_PFJet80_v4:HLT_PFJet80_v5:HLT_PFJet80_v6:HLT_PFMET120_NoiseCleaned_BTagCSV07_v1:HLT_PFMET120_NoiseCleaned_Mu5_v1:HLT_PFMET120_PFMHT120_IDLoose_v1:HLT_PFMET170_NoiseCleaned_v1:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon120_R9Id90_HE10_Iso40_v1:HLT_Photon120_R9Id90_HE10_IsoM_v3:HLT_Photon120_R9Id90_HE10_IsoM_v4:HLT_Photon120_R9Id90_HE10_IsoM_v7:HLT_Photon120_v1:HLT_Photon120_v3:HLT_Photon120_v4:HLT_Photon120_v6:HLT_Photon125_v1:HLT_Photon125_v2:HLT_Photon125_v4:HLT_Photon135_PFMET100_NoiseCleaned_v1:HLT_Photon135_PFMET100_v1:HLT_Photon135_PFMET100_v2:HLT_Photon135_PFMET100_v6:HLT_Photon135_PFMET40_v1:HLT_Photon135_VBF_v1:HLT_Photon150_v1:HLT_Photon150_v2:HLT_Photon150_v4:HLT_Photon155_R9Id90_HE10_Iso40_v1:HLT_Photon165_HE10_v1:HLT_Photon165_HE10_v3:HLT_Photon165_HE10_v4:HLT_Photon165_HE10_v7:HLT_Photon165_R9Id90_HE10_IsoM_v3:HLT_Photon165_R9Id90_HE10_IsoM_v4:HLT_Photon165_R9Id90_HE10_IsoM_v8:HLT_Photon175_v1:HLT_Photon175_v3:HLT_Photon175_v4:HLT_Photon175_v7:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon22_R9Id90_HE10_Iso40_v1:HLT_Photon22_R9Id90_HE10_IsoM_v2:HLT_Photon22_R9Id90_HE10_IsoM_v3:HLT_Photon22_R9Id90_HE10_IsoM_v6:HLT_Photon22_v1:HLT_Photon22_v2:HLT_Photon22_v3:HLT_Photon22_v5:HLT_Photon250_NoHE_v1:HLT_Photon250_NoHE_v2:HLT_Photon250_NoHE_v3:HLT_Photon250_NoHE_v6:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7:HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1:HLT_Photon300_NoHE_v1:HLT_Photon300_NoHE_v2:HLT_Photon300_NoHE_v3:HLT_Photon300_NoHE_v6:HLT_Photon30_R9Id90_HE10_Iso40_v1:HLT_Photon30_R9Id90_HE10_IsoM_v3:HLT_Photon30_R9Id90_HE10_IsoM_v4:HLT_Photon30_R9Id90_HE10_IsoM_v7:HLT_Photon30_v1:HLT_Photon30_v3:HLT_Photon30_v4:HLT_Photon30_v6:HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1:HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon36_R9Id90_HE10_Iso40_v1:HLT_Photon36_R9Id90_HE10_IsoM_v3:HLT_Photon36_R9Id90_HE10_IsoM_v4:HLT_Photon36_R9Id90_HE10_IsoM_v7:HLT_Photon36_v1:HLT_Photon36_v3:HLT_Photon36_v4:HLT_Photon36_v6:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7:HLT_Photon500_v1:HLT_Photon500_v2:HLT_Photon500_v5:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon50_R9Id90_HE10_Iso40_v1:HLT_Photon50_R9Id90_HE10_IsoM_v3:HLT_Photon50_R9Id90_HE10_IsoM_v4:HLT_Photon50_R9Id90_HE10_IsoM_v7:HLT_Photon50_v1:HLT_Photon50_v3:HLT_Photon50_v4:HLT_Photon50_v6:HLT_Photon600_v1:HLT_Photon600_v2:HLT_Photon600_v5:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon75_R9Id90_HE10_Iso40_v1:HLT_Photon75_R9Id90_HE10_IsoM_v3:HLT_Photon75_R9Id90_HE10_IsoM_v4:HLT_Photon75_R9Id90_HE10_IsoM_v7:HLT_Photon75_v1:HLT_Photon75_v3:HLT_Photon75_v4:HLT_Photon75_v6:HLT_Photon90_CaloIdL_HT300_v1:HLT_Photon90_CaloIdL_HT300_v2:HLT_Photon90_CaloIdL_HT300_v4:HLT_Photon90_CaloIdL_PFHT500_v1:HLT_Photon90_CaloIdL_PFHT500_v3:HLT_Photon90_CaloIdL_PFHT500_v4:HLT_Photon90_CaloIdL_PFHT500_v7:HLT_Photon90_CaloIdL_PFHT600_v2:HLT_Photon90_CaloIdL_PFHT600_v3:HLT_Photon90_CaloIdL_PFHT600_v6:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6:HLT_Photon90_R9Id90_HE10_Iso40_v1:HLT_Photon90_R9Id90_HE10_IsoM_v3:HLT_Photon90_R9Id90_HE10_IsoM_v4:HLT_Photon90_R9Id90_HE10_IsoM_v7:HLT_Photon90_v1:HLT_Photon90_v3:HLT_Photon90_v4:HLT_Photon90_v6:HLT_Physics_v1:HLT_PixelTracks_Multiplicity110_v1:HLT_PixelTracks_Multiplicity135_v1:HLT_PixelTracks_Multiplicity160_v1:HLT_PixelTracks_Multiplicity60_v1:HLT_PixelTracks_Multiplicity85_v1:HLT_QuadJet45_DoubleCSV0p5_v1:HLT_QuadJet45_TripleCSV0p5_v1:HLT_QuadMuon0_Dimuon0_Jpsi_v1:HLT_QuadMuon0_Dimuon0_Upsilon_v1:HLT_QuadPFJet_BTagCSV_VBF_v1:HLT_QuadPFJet_VBF_v1:HLT_QuadPFJet_VBF_v4:HLT_QuadPFJet_VBF_v5:HLT_QuadPFJet_VBF_v6:HLT_Rsq0p36_v1:HLT_RsqMR260_Rsq0p09_MR200_4jet_v1:HLT_RsqMR260_Rsq0p09_MR200_v1:HLT_RsqMR300_Rsq0p09_MR200_4jet_v1:HLT_RsqMR300_Rsq0p09_MR200_v1:HLT_SingleCentralPFJet170_CFMax0p1_v1:HLT_SingleCentralPFJet170_CFMax0p1_v3:HLT_TkMu24_eta2p1_v1:HLT_TkMu27_v1:HLT_TripleMu_12_10_5_v1:HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2:HLT_VBF_DisplacedJet40_DisplacedTrack_v2:HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2:HLT_VBF_DisplacedJet40_Hadronic_v2:HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2:HLT_VBF_DisplacedJet40_TightID_Hadronic_v2:HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2:HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2:HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2:HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2:HLT_ZeroBias_v1");
  
  void InitTriggerInfo(triggerInfo_t &triggerInfo) {
    triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v1 = -1;
    triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v2 = -1;
    triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v3 = -1;
    triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v1 = -1;
    triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v2 = -1;
    triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v3 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v2 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v3 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v2 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v3 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4 = -1;
    triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = -1;
    triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3 = -1;
    triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6 = -1;
    triggerInfo.HLT_AK8PFJet140_v1 = -1;
    triggerInfo.HLT_AK8PFJet140_v2 = -1;
    triggerInfo.HLT_AK8PFJet200_v1 = -1;
    triggerInfo.HLT_AK8PFJet200_v2 = -1;
    triggerInfo.HLT_AK8PFJet260_v1 = -1;
    triggerInfo.HLT_AK8PFJet260_v2 = -1;
    triggerInfo.HLT_AK8PFJet320_v1 = -1;
    triggerInfo.HLT_AK8PFJet320_v2 = -1;
    triggerInfo.HLT_AK8PFJet360TrimMod_Mass30_v1 = -1;
    triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = -1;
    triggerInfo.HLT_AK8PFJet360_TrimMass30_v4 = -1;
    triggerInfo.HLT_AK8PFJet360_TrimMass30_v5 = -1;
    triggerInfo.HLT_AK8PFJet400_v1 = -1;
    triggerInfo.HLT_AK8PFJet400_v2 = -1;
    triggerInfo.HLT_AK8PFJet40_v1 = -1;
    triggerInfo.HLT_AK8PFJet40_v3 = -1;
    triggerInfo.HLT_AK8PFJet450_v1 = -1;
    triggerInfo.HLT_AK8PFJet450_v2 = -1;
    triggerInfo.HLT_AK8PFJet500_v1 = -1;
    triggerInfo.HLT_AK8PFJet500_v2 = -1;
    triggerInfo.HLT_AK8PFJet60_v1 = -1;
    triggerInfo.HLT_AK8PFJet60_v2 = -1;
    triggerInfo.HLT_AK8PFJet80_v1 = -1;
    triggerInfo.HLT_AK8PFJet80_v2 = -1;
    triggerInfo.HLT_BTagMu_DiJet110_Mu5_v1 = -1;
    triggerInfo.HLT_BTagMu_DiJet20_Mu5_v1 = -1;
    triggerInfo.HLT_BTagMu_DiJet40_Mu5_v1 = -1;
    triggerInfo.HLT_BTagMu_DiJet70_Mu5_v1 = -1;
    triggerInfo.HLT_BTagMu_Jet300_Mu5_v1 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID_v1 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID_v2 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID_v3 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID_v4 = -1;
    triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1 = -1;
    triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve140_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve200_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve260_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve320_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve400_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve40_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve500_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve60_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve80_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v3 = -1;
    triggerInfo.HLT_DiCentralPFJet170_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet170_v3 = -1;
    triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v3 = -1;
    triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v3 = -1;
    triggerInfo.HLT_DiCentralPFJet430_v1 = -1;
    triggerInfo.HLT_DiCentralPFJet430_v3 = -1;
    triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1 = -1;
    triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1 = -1;
    triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve140_v2 = -1;
    triggerInfo.HLT_DiPFJetAve140_v3 = -1;
    triggerInfo.HLT_DiPFJetAve140_v5 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve200_v2 = -1;
    triggerInfo.HLT_DiPFJetAve200_v3 = -1;
    triggerInfo.HLT_DiPFJetAve200_v5 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve260_v2 = -1;
    triggerInfo.HLT_DiPFJetAve260_v3 = -1;
    triggerInfo.HLT_DiPFJetAve260_v5 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC_v5 = -1;
    triggerInfo.HLT_DiPFJetAve320_v2 = -1;
    triggerInfo.HLT_DiPFJetAve320_v3 = -1;
    triggerInfo.HLT_DiPFJetAve320_v5 = -1;
    triggerInfo.HLT_DiPFJetAve400_v2 = -1;
    triggerInfo.HLT_DiPFJetAve400_v3 = -1;
    triggerInfo.HLT_DiPFJetAve400_v5 = -1;
    triggerInfo.HLT_DiPFJetAve40_v2 = -1;
    triggerInfo.HLT_DiPFJetAve40_v3 = -1;
    triggerInfo.HLT_DiPFJetAve40_v6 = -1;
    triggerInfo.HLT_DiPFJetAve500_v2 = -1;
    triggerInfo.HLT_DiPFJetAve500_v3 = -1;
    triggerInfo.HLT_DiPFJetAve500_v5 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve60_v2 = -1;
    triggerInfo.HLT_DiPFJetAve60_v3 = -1;
    triggerInfo.HLT_DiPFJetAve60_v6 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC_v1 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC_v4 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC_v6 = -1;
    triggerInfo.HLT_DiPFJetAve80_v2 = -1;
    triggerInfo.HLT_DiPFJetAve80_v3 = -1;
    triggerInfo.HLT_DiPFJetAve80_v5 = -1;
    triggerInfo.HLT_Dimuon0_Jpsi_Muon_v1 = -1;
    triggerInfo.HLT_Dimuon0_Upsilon_Muon_v1 = -1;
    triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1 = -1;
    triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing_v1 = -1;
    triggerInfo.HLT_Dimuon13_PsiPrime_v1 = -1;
    triggerInfo.HLT_Dimuon13_Upsilon_v1 = -1;
    triggerInfo.HLT_Dimuon20_Jpsi_v1 = -1;
    triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing_v1 = -1;
    triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = -1;
    triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = -1;
    triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = -1;
    triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = -1;
    triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = -1;
    triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2 = -1;
    triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7 = -1;
    triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = -1;
    triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2 = -1;
    triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v2 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v6 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_v2 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_v6 = -1;
    triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2 = -1;
    triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8 = -1;
    triggerInfo.HLT_DoubleIsoMu17_eta2p1_v1 = -1;
    triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5_v1 = -1;
    triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5_v1 = -1;
    triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = -1;
    triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1 = -1;
    triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1 = -1;
    triggerInfo.HLT_DoubleMu33NoFiltersNoVtx_v1 = -1;
    triggerInfo.HLT_DoubleMu38NoFiltersNoVtx_v1 = -1;
    triggerInfo.HLT_DoubleMu4_3_Bs_v1 = -1;
    triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced_v1 = -1;
    triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced_v1 = -1;
    triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1 = -1;
    triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1 = -1;
    triggerInfo.HLT_DoubleMu8_Mass8_PFHT300_v1 = -1;
    triggerInfo.HLT_DoublePhoton40_v1 = -1;
    triggerInfo.HLT_DoublePhoton50_v1 = -1;
    triggerInfo.HLT_DoublePhoton60_v1 = -1;
    triggerInfo.HLT_DoublePhoton60_v2 = -1;
    triggerInfo.HLT_DoublePhoton60_v6 = -1;
    triggerInfo.HLT_DoublePhoton85_v1 = -1;
    triggerInfo.HLT_DoublePhoton85_v2 = -1;
    triggerInfo.HLT_DoublePhoton85_v3 = -1;
    triggerInfo.HLT_DoublePhoton85_v7 = -1;
    triggerInfo.HLT_ECALHT800_v2 = -1;
    triggerInfo.HLT_ECALHT800_v3 = -1;
    triggerInfo.HLT_ECALHT800_v4 = -1;
    triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT_v1 = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2 = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5 = -1;
    triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7 = -1;
    triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4 = -1;
    triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7 = -1;
    triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_PFHT600_v1 = -1;
    triggerInfo.HLT_Ele15_PFHT300_v1 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v2 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v5 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6 = -1;
    triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2 = -1;
    triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = -1;
    triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1 = -1;
    triggerInfo.HLT_Ele20WP60_Ele8_Mass55_v1 = -1;
    triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = -1;
    triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7 = -1;
    triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4 = -1;
    triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7 = -1;
    triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = -1;
    triggerInfo.HLT_Ele25WP60_SC4_Mass55_v1 = -1;
    triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1 = -1;
    triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v2 = -1;
    triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v6 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = -1;
    triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v3 = -1;
    triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v7 = -1;
    triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = -1;
    triggerInfo.HLT_Ele30WP60_SC4_Mass55_v4 = -1;
    triggerInfo.HLT_Ele30WP60_SC4_Mass55_v8 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1 = -1;
    triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf_v1 = -1;
    triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1 = -1;
    triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = -1;
    triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = -1;
    triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4 = -1;
    triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7 = -1;
    triggerInfo.HLT_HT2000_v1 = -1;
    triggerInfo.HLT_HT2000_v2 = -1;
    triggerInfo.HLT_HT2000_v3 = -1;
    triggerInfo.HLT_HT200_DiJet90_AlphaT0p57_v1 = -1;
    triggerInfo.HLT_HT200_v1 = -1;
    triggerInfo.HLT_HT2500_v1 = -1;
    triggerInfo.HLT_HT2500_v2 = -1;
    triggerInfo.HLT_HT2500_v3 = -1;
    triggerInfo.HLT_HT250_DiJet90_AlphaT0p55_v1 = -1;
    triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_HT250_v1 = -1;
    triggerInfo.HLT_HT275_v1 = -1;
    triggerInfo.HLT_HT300_DiJet90_AlphaT0p53_v1 = -1;
    triggerInfo.HLT_HT300_v1 = -1;
    triggerInfo.HLT_HT325_v1 = -1;
    triggerInfo.HLT_HT350_DiJet90_AlphaT0p52_v1 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v1 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_HT350_v1 = -1;
    triggerInfo.HLT_HT400_DiJet90_AlphaT0p51_v1 = -1;
    triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive_v2 = -1;
    triggerInfo.HLT_HT400_v1 = -1;
    triggerInfo.HLT_HT425_v1 = -1;
    triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive_v2 = -1;
    triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive_v2 = -1;
    triggerInfo.HLT_HT575_v1 = -1;
    triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v1 = -1;
    triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v2 = -1;
    triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v1 = -1;
    triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v2 = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_v1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoMu27_v1 = -1;
    triggerInfo.HLT_IsoTkMu20_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoTkMu24_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoTkMu27_v1 = -1;
    triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_JetE30_NoBPTX_v1 = -1;
    triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_L1_TripleJet_VBF_v1 = -1;
    triggerInfo.HLT_L1_TripleJet_VBF_v4 = -1;
    triggerInfo.HLT_L1_TripleJet_VBF_v5 = -1;
    triggerInfo.HLT_L2DoubleMu23_NoVertex_v1 = -1;
    triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1 = -1;
    triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1 = -1;
    triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX_v1 = -1;
    triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = -1;
    triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1 = -1;
    triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_v1 = -1;
    triggerInfo.HLT_MET75_IsoTrk50_v1 = -1;
    triggerInfo.HLT_MET90_IsoTrk50_v1 = -1;
    triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV_v1 = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO_v1 = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR_v1 = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL_v1 = -1;
    triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v1 = -1;
    triggerInfo.HLT_Mu15_PFHT300_v1 = -1;
    triggerInfo.HLT_Mu16_eta2p1_CaloMET30_v1 = -1;
    triggerInfo.HLT_Mu17_Mu8_DZ_v1 = -1;
    triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi_v1 = -1;
    triggerInfo.HLT_Mu17_Mu8_SameSign_v1 = -1;
    triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO_v1 = -1;
    triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO_v1 = -1;
    triggerInfo.HLT_Mu17_TkMu8_DZ_v1 = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1 = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1 = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = -1;
    triggerInfo.HLT_Mu24_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_Mu24_eta2p1_v1 = -1;
    triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia_v1 = -1;
    triggerInfo.HLT_Mu27_v1 = -1;
    triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1 = -1;
    triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1 = -1;
    triggerInfo.HLT_Mu30_TkMu11_v1 = -1;
    triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1 = -1;
    triggerInfo.HLT_Mu34_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1 = -1;
    triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v1 = -1;
    triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1 = -1;
    triggerInfo.HLT_Mu45_eta2p1_v1 = -1;
    triggerInfo.HLT_Mu50_v1 = -1;
    triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1 = -1;
    triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi_v1 = -1;
    triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track2_Jpsi_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track2_Upsilon_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track3p5_Jpsi_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track3p5_Upsilon_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track7_Jpsi_v1 = -1;
    triggerInfo.HLT_Mu7p5_Track7_Upsilon_v1 = -1;
    triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1 = -1;
    triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = -1;
    triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = -1;
    triggerInfo.HLT_Mu8_TrkIsoVVL_v1 = -1;
    triggerInfo.HLT_PFHT125_v2 = -1;
    triggerInfo.HLT_PFHT125_v3 = -1;
    triggerInfo.HLT_PFHT200_v2 = -1;
    triggerInfo.HLT_PFHT200_v3 = -1;
    triggerInfo.HLT_PFHT200_v4 = -1;
    triggerInfo.HLT_PFHT250_v2 = -1;
    triggerInfo.HLT_PFHT250_v3 = -1;
    triggerInfo.HLT_PFHT250_v4 = -1;
    triggerInfo.HLT_PFHT300_v2 = -1;
    triggerInfo.HLT_PFHT300_v3 = -1;
    triggerInfo.HLT_PFHT300_v5 = -1;
    triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_PFHT350_v1 = -1;
    triggerInfo.HLT_PFHT350_v3 = -1;
    triggerInfo.HLT_PFHT350_v4 = -1;
    triggerInfo.HLT_PFHT350_v6 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_v3 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_v4 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_v5 = -1;
    triggerInfo.HLT_PFHT400_v2 = -1;
    triggerInfo.HLT_PFHT400_v3 = -1;
    triggerInfo.HLT_PFHT400_v5 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v2 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v3 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_v3 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_v4 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_v5 = -1;
    triggerInfo.HLT_PFHT475_v2 = -1;
    triggerInfo.HLT_PFHT475_v3 = -1;
    triggerInfo.HLT_PFHT475_v5 = -1;
    triggerInfo.HLT_PFHT550_4JetPt50_v1 = -1;
    triggerInfo.HLT_PFHT550_4JetPt50_v2 = -1;
    triggerInfo.HLT_PFHT550_4JetPt50_v4 = -1;
    triggerInfo.HLT_PFHT550_4Jet_v1 = -1;
    triggerInfo.HLT_PFHT600_v1 = -1;
    triggerInfo.HLT_PFHT600_v3 = -1;
    triggerInfo.HLT_PFHT600_v4 = -1;
    triggerInfo.HLT_PFHT600_v6 = -1;
    triggerInfo.HLT_PFHT650_4JetPt50_v1 = -1;
    triggerInfo.HLT_PFHT650_4JetPt50_v2 = -1;
    triggerInfo.HLT_PFHT650_4JetPt50_v4 = -1;
    triggerInfo.HLT_PFHT650_4Jet_v1 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6 = -1;
    triggerInfo.HLT_PFHT650_v1 = -1;
    triggerInfo.HLT_PFHT650_v3 = -1;
    triggerInfo.HLT_PFHT650_v4 = -1;
    triggerInfo.HLT_PFHT650_v6 = -1;
    triggerInfo.HLT_PFHT750_4JetPt50_v3 = -1;
    triggerInfo.HLT_PFHT750_4JetPt50_v4 = -1;
    triggerInfo.HLT_PFHT750_4JetPt50_v6 = -1;
    triggerInfo.HLT_PFHT750_4Jet_v1 = -1;
    triggerInfo.HLT_PFHT800_v2 = -1;
    triggerInfo.HLT_PFHT800_v3 = -1;
    triggerInfo.HLT_PFHT800_v5 = -1;
    triggerInfo.HLT_PFHT900_v1 = -1;
    triggerInfo.HLT_PFHT900_v2 = -1;
    triggerInfo.HLT_PFHT900_v4 = -1;
    triggerInfo.HLT_PFJet140_v1 = -1;
    triggerInfo.HLT_PFJet140_v4 = -1;
    triggerInfo.HLT_PFJet140_v5 = -1;
    triggerInfo.HLT_PFJet140_v6 = -1;
    triggerInfo.HLT_PFJet200_v1 = -1;
    triggerInfo.HLT_PFJet200_v4 = -1;
    triggerInfo.HLT_PFJet200_v5 = -1;
    triggerInfo.HLT_PFJet200_v6 = -1;
    triggerInfo.HLT_PFJet260_v1 = -1;
    triggerInfo.HLT_PFJet260_v4 = -1;
    triggerInfo.HLT_PFJet260_v5 = -1;
    triggerInfo.HLT_PFJet260_v6 = -1;
    triggerInfo.HLT_PFJet320_v1 = -1;
    triggerInfo.HLT_PFJet320_v4 = -1;
    triggerInfo.HLT_PFJet320_v5 = -1;
    triggerInfo.HLT_PFJet320_v6 = -1;
    triggerInfo.HLT_PFJet400_v1 = -1;
    triggerInfo.HLT_PFJet400_v4 = -1;
    triggerInfo.HLT_PFJet400_v5 = -1;
    triggerInfo.HLT_PFJet400_v6 = -1;
    triggerInfo.HLT_PFJet40_v1 = -1;
    triggerInfo.HLT_PFJet40_v4 = -1;
    triggerInfo.HLT_PFJet40_v5 = -1;
    triggerInfo.HLT_PFJet40_v7 = -1;
    triggerInfo.HLT_PFJet450_v1 = -1;
    triggerInfo.HLT_PFJet450_v4 = -1;
    triggerInfo.HLT_PFJet450_v5 = -1;
    triggerInfo.HLT_PFJet450_v6 = -1;
    triggerInfo.HLT_PFJet500_v1 = -1;
    triggerInfo.HLT_PFJet500_v4 = -1;
    triggerInfo.HLT_PFJet500_v5 = -1;
    triggerInfo.HLT_PFJet500_v6 = -1;
    triggerInfo.HLT_PFJet60_v1 = -1;
    triggerInfo.HLT_PFJet60_v4 = -1;
    triggerInfo.HLT_PFJet60_v5 = -1;
    triggerInfo.HLT_PFJet60_v7 = -1;
    triggerInfo.HLT_PFJet80_v1 = -1;
    triggerInfo.HLT_PFJet80_v4 = -1;
    triggerInfo.HLT_PFJet80_v5 = -1;
    triggerInfo.HLT_PFJet80_v6 = -1;
    triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07_v1 = -1;
    triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5_v1 = -1;
    triggerInfo.HLT_PFMET120_PFMHT120_IDLoose_v1 = -1;
    triggerInfo.HLT_PFMET170_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon120_v1 = -1;
    triggerInfo.HLT_Photon120_v3 = -1;
    triggerInfo.HLT_Photon120_v4 = -1;
    triggerInfo.HLT_Photon120_v6 = -1;
    triggerInfo.HLT_Photon125_v1 = -1;
    triggerInfo.HLT_Photon125_v2 = -1;
    triggerInfo.HLT_Photon125_v4 = -1;
    triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned_v1 = -1;
    triggerInfo.HLT_Photon135_PFMET100_v1 = -1;
    triggerInfo.HLT_Photon135_PFMET100_v2 = -1;
    triggerInfo.HLT_Photon135_PFMET100_v6 = -1;
    triggerInfo.HLT_Photon135_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon135_VBF_v1 = -1;
    triggerInfo.HLT_Photon150_v1 = -1;
    triggerInfo.HLT_Photon150_v2 = -1;
    triggerInfo.HLT_Photon150_v4 = -1;
    triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon165_HE10_v1 = -1;
    triggerInfo.HLT_Photon165_HE10_v3 = -1;
    triggerInfo.HLT_Photon165_HE10_v4 = -1;
    triggerInfo.HLT_Photon165_HE10_v7 = -1;
    triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v8 = -1;
    triggerInfo.HLT_Photon175_v1 = -1;
    triggerInfo.HLT_Photon175_v3 = -1;
    triggerInfo.HLT_Photon175_v4 = -1;
    triggerInfo.HLT_Photon175_v7 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v6 = -1;
    triggerInfo.HLT_Photon22_v1 = -1;
    triggerInfo.HLT_Photon22_v2 = -1;
    triggerInfo.HLT_Photon22_v3 = -1;
    triggerInfo.HLT_Photon22_v5 = -1;
    triggerInfo.HLT_Photon250_NoHE_v1 = -1;
    triggerInfo.HLT_Photon250_NoHE_v2 = -1;
    triggerInfo.HLT_Photon250_NoHE_v3 = -1;
    triggerInfo.HLT_Photon250_NoHE_v6 = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1 = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3 = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7 = -1;
    triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1 = -1;
    triggerInfo.HLT_Photon300_NoHE_v1 = -1;
    triggerInfo.HLT_Photon300_NoHE_v2 = -1;
    triggerInfo.HLT_Photon300_NoHE_v3 = -1;
    triggerInfo.HLT_Photon300_NoHE_v6 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon30_v1 = -1;
    triggerInfo.HLT_Photon30_v3 = -1;
    triggerInfo.HLT_Photon30_v4 = -1;
    triggerInfo.HLT_Photon30_v6 = -1;
    triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon36_v1 = -1;
    triggerInfo.HLT_Photon36_v3 = -1;
    triggerInfo.HLT_Photon36_v4 = -1;
    triggerInfo.HLT_Photon36_v6 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7 = -1;
    triggerInfo.HLT_Photon500_v1 = -1;
    triggerInfo.HLT_Photon500_v2 = -1;
    triggerInfo.HLT_Photon500_v5 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon50_v1 = -1;
    triggerInfo.HLT_Photon50_v3 = -1;
    triggerInfo.HLT_Photon50_v4 = -1;
    triggerInfo.HLT_Photon50_v6 = -1;
    triggerInfo.HLT_Photon600_v1 = -1;
    triggerInfo.HLT_Photon600_v2 = -1;
    triggerInfo.HLT_Photon600_v5 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon75_v1 = -1;
    triggerInfo.HLT_Photon75_v3 = -1;
    triggerInfo.HLT_Photon75_v4 = -1;
    triggerInfo.HLT_Photon75_v6 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_HT300_v2 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_HT300_v4 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v1 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v4 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v7 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v3 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v6 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_v1 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v4 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v7 = -1;
    triggerInfo.HLT_Photon90_v1 = -1;
    triggerInfo.HLT_Photon90_v3 = -1;
    triggerInfo.HLT_Photon90_v4 = -1;
    triggerInfo.HLT_Photon90_v6 = -1;
    triggerInfo.HLT_Physics_v1 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity110_v1 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity135_v1 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity160_v1 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity60_v1 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity85_v1 = -1;
    triggerInfo.HLT_QuadJet45_DoubleCSV0p5_v1 = -1;
    triggerInfo.HLT_QuadJet45_TripleCSV0p5_v1 = -1;
    triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi_v1 = -1;
    triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon_v1 = -1;
    triggerInfo.HLT_QuadPFJet_BTagCSV_VBF_v1 = -1;
    triggerInfo.HLT_QuadPFJet_VBF_v1 = -1;
    triggerInfo.HLT_QuadPFJet_VBF_v4 = -1;
    triggerInfo.HLT_QuadPFJet_VBF_v5 = -1;
    triggerInfo.HLT_QuadPFJet_VBF_v6 = -1;
    triggerInfo.HLT_Rsq0p36_v1 = -1;
    triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet_v1 = -1;
    triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_v1 = -1;
    triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet_v1 = -1;
    triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_v1 = -1;
    triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v1 = -1;
    triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v3 = -1;
    triggerInfo.HLT_TkMu24_eta2p1_v1 = -1;
    triggerInfo.HLT_TkMu27_v1 = -1;
    triggerInfo.HLT_TripleMu_12_10_5_v1 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2 = -1;
    triggerInfo.HLT_ZeroBias_v1 = -1;


  }

  
  
  void FillTriggerBits(triggerInfo_t &triggerInfo, const edm::TriggerResults* triggerResults, const edm::Event& iEvent) {
    
    // first clear decisions from previous event
    ExoDiPhotons::InitTriggerInfo(triggerInfo);

    //get trigger names from the event
    std::vector<std::string> trigNames = iEvent.triggerNames(*triggerResults).triggerNames();

    // loop over the trigger names and write trigger bits and prescales
    for (unsigned int i=0; i < trigNames.size(); i++){
        std::string currentTrigger = trigNames.at(i);

        if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v1")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v2")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v3")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v1")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v2")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v3")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_v3")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_v2")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet140_v1")
          triggerInfo.HLT_AK8PFJet140_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet140_v2")
          triggerInfo.HLT_AK8PFJet140_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet200_v1")
          triggerInfo.HLT_AK8PFJet200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet200_v2")
          triggerInfo.HLT_AK8PFJet200_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet260_v1")
          triggerInfo.HLT_AK8PFJet260_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet260_v2")
          triggerInfo.HLT_AK8PFJet260_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet320_v1")
          triggerInfo.HLT_AK8PFJet320_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet320_v2")
          triggerInfo.HLT_AK8PFJet320_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet360TrimMod_Mass30_v1")
          triggerInfo.HLT_AK8PFJet360TrimMod_Mass30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v3")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v4")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v5")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet400_v1")
          triggerInfo.HLT_AK8PFJet400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet400_v2")
          triggerInfo.HLT_AK8PFJet400_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet40_v1")
          triggerInfo.HLT_AK8PFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet40_v3")
          triggerInfo.HLT_AK8PFJet40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet450_v1")
          triggerInfo.HLT_AK8PFJet450_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet450_v2")
          triggerInfo.HLT_AK8PFJet450_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet500_v1")
          triggerInfo.HLT_AK8PFJet500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet500_v2")
          triggerInfo.HLT_AK8PFJet500_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet60_v1")
          triggerInfo.HLT_AK8PFJet60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet60_v2")
          triggerInfo.HLT_AK8PFJet60_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet80_v1")
          triggerInfo.HLT_AK8PFJet80_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_AK8PFJet80_v2")
          triggerInfo.HLT_AK8PFJet80_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet110_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet110_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet20_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet20_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet40_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet40_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet70_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet70_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_BTagMu_Jet300_Mu5_v1")
          triggerInfo.HLT_BTagMu_Jet300_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v1")
          triggerInfo.HLT_CaloJet500_NoJetID_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v2")
          triggerInfo.HLT_CaloJet500_NoJetID_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v3")
          triggerInfo.HLT_CaloJet500_NoJetID_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v4")
          triggerInfo.HLT_CaloJet500_NoJetID_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1")
          triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1")
          triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve140_v1")
          triggerInfo.HLT_DiCaloJetAve140_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve200_v1")
          triggerInfo.HLT_DiCaloJetAve200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve260_v1")
          triggerInfo.HLT_DiCaloJetAve260_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve320_v1")
          triggerInfo.HLT_DiCaloJetAve320_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve400_v1")
          triggerInfo.HLT_DiCaloJetAve400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve40_v1")
          triggerInfo.HLT_DiCaloJetAve40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve500_v1")
          triggerInfo.HLT_DiCaloJetAve500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve60_v1")
          triggerInfo.HLT_DiCaloJetAve60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCaloJetAve80_v1")
          triggerInfo.HLT_DiCaloJetAve80_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_CFMax0p1_v1")
          triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_CFMax0p1_v3")
          triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_v1")
          triggerInfo.HLT_DiCentralPFJet170_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_v3")
          triggerInfo.HLT_DiCentralPFJet170_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet220_CFMax0p3_v1")
          triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet220_CFMax0p3_v3")
          triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet330_CFMax0p5_v1")
          triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet330_CFMax0p5_v3")
          triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet430_v1")
          triggerInfo.HLT_DiCentralPFJet430_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet430_v3")
          triggerInfo.HLT_DiCentralPFJet430_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1")
          triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1")
          triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v2")
          triggerInfo.HLT_DiPFJetAve140_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v3")
          triggerInfo.HLT_DiPFJetAve140_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v5")
          triggerInfo.HLT_DiPFJetAve140_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v2")
          triggerInfo.HLT_DiPFJetAve200_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v3")
          triggerInfo.HLT_DiPFJetAve200_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v5")
          triggerInfo.HLT_DiPFJetAve200_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v2")
          triggerInfo.HLT_DiPFJetAve260_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v3")
          triggerInfo.HLT_DiPFJetAve260_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v5")
          triggerInfo.HLT_DiPFJetAve260_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v5")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v2")
          triggerInfo.HLT_DiPFJetAve320_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v3")
          triggerInfo.HLT_DiPFJetAve320_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v5")
          triggerInfo.HLT_DiPFJetAve320_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v2")
          triggerInfo.HLT_DiPFJetAve400_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v3")
          triggerInfo.HLT_DiPFJetAve400_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v5")
          triggerInfo.HLT_DiPFJetAve400_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v2")
          triggerInfo.HLT_DiPFJetAve40_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v3")
          triggerInfo.HLT_DiPFJetAve40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v6")
          triggerInfo.HLT_DiPFJetAve40_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v2")
          triggerInfo.HLT_DiPFJetAve500_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v3")
          triggerInfo.HLT_DiPFJetAve500_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v5")
          triggerInfo.HLT_DiPFJetAve500_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v2")
          triggerInfo.HLT_DiPFJetAve60_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v3")
          triggerInfo.HLT_DiPFJetAve60_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v6")
          triggerInfo.HLT_DiPFJetAve60_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v2")
          triggerInfo.HLT_DiPFJetAve80_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v3")
          triggerInfo.HLT_DiPFJetAve80_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v5")
          triggerInfo.HLT_DiPFJetAve80_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon0_Jpsi_Muon_v1")
          triggerInfo.HLT_Dimuon0_Jpsi_Muon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon0_Upsilon_Muon_v1")
          triggerInfo.HLT_Dimuon0_Upsilon_Muon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1")
          triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon0er16_Jpsi_NoVertexing_v1")
          triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon13_PsiPrime_v1")
          triggerInfo.HLT_Dimuon13_PsiPrime_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon13_Upsilon_v1")
          triggerInfo.HLT_Dimuon13_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon20_Jpsi_v1")
          triggerInfo.HLT_Dimuon20_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Dimuon6_Jpsi_NoVertexing_v1")
          triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_MW_v2")
          triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_MW_v6")
          triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_v2")
          triggerInfo.HLT_DoubleEle33_CaloIdL_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_v6")
          triggerInfo.HLT_DoubleEle33_CaloIdL_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6")
          triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1")
          triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleIsoMu17_eta2p1_v1")
          triggerInfo.HLT_DoubleIsoMu17_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleJet90_Double30_DoubleCSV0p5_v1")
          triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleJet90_Double30_TripleCSV0p5_v1")
          triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1")
          triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1")
          triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu33NoFiltersNoVtx_v1")
          triggerInfo.HLT_DoubleMu33NoFiltersNoVtx_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu38NoFiltersNoVtx_v1")
          triggerInfo.HLT_DoubleMu38NoFiltersNoVtx_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu4_3_Bs_v1")
          triggerInfo.HLT_DoubleMu4_3_Bs_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu4_3_Jpsi_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu4_JpsiTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoubleMu8_Mass8_PFHT300_v1")
          triggerInfo.HLT_DoubleMu8_Mass8_PFHT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton40_v1")
          triggerInfo.HLT_DoublePhoton40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton50_v1")
          triggerInfo.HLT_DoublePhoton50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v1")
          triggerInfo.HLT_DoublePhoton60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v2")
          triggerInfo.HLT_DoublePhoton60_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v6")
          triggerInfo.HLT_DoublePhoton60_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v1")
          triggerInfo.HLT_DoublePhoton85_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v2")
          triggerInfo.HLT_DoublePhoton85_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v3")
          triggerInfo.HLT_DoublePhoton85_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v7")
          triggerInfo.HLT_DoublePhoton85_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_ECALHT800_v2")
          triggerInfo.HLT_ECALHT800_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_ECALHT800_v3")
          triggerInfo.HLT_ECALHT800_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_ECALHT800_v4")
          triggerInfo.HLT_ECALHT800_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele105_CaloIdVT_GsfTrkIdT_v1")
          triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1")
          triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_PFHT600_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_PFHT600_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele15_PFHT300_v1")
          triggerInfo.HLT_Ele15_PFHT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_GsfTrkIdVL_v5")
          triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2")
          triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5")
          triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele20WP60_Ele8_Mass55_v1")
          triggerInfo.HLT_Ele20WP60_Ele8_Mass55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele22_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele25WP60_SC4_Mass55_v1")
          triggerInfo.HLT_Ele25WP60_SC4_Mass55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1")
          triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_HighEta_Ele20_Mass55_v2")
          triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_HighEta_Ele20_Mass55_v6")
          triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v2")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v3")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v7")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v3")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v4")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v8")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele35_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele40_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1")
          triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2")
          triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5")
          triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2000_v1")
          triggerInfo.HLT_HT2000_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2000_v2")
          triggerInfo.HLT_HT2000_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2000_v3")
          triggerInfo.HLT_HT2000_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT200_DiJet90_AlphaT0p57_v1")
          triggerInfo.HLT_HT200_DiJet90_AlphaT0p57_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT200_v1")
          triggerInfo.HLT_HT200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2500_v1")
          triggerInfo.HLT_HT2500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2500_v2")
          triggerInfo.HLT_HT2500_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT2500_v3")
          triggerInfo.HLT_HT2500_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT250_DiJet90_AlphaT0p55_v1")
          triggerInfo.HLT_HT250_DiJet90_AlphaT0p55_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT250_DisplacedDijet40_DisplacedTrack_v2")
          triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT250_v1")
          triggerInfo.HLT_HT250_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT275_v1")
          triggerInfo.HLT_HT275_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT300_DiJet90_AlphaT0p53_v1")
          triggerInfo.HLT_HT300_DiJet90_AlphaT0p53_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT300_v1")
          triggerInfo.HLT_HT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT325_v1")
          triggerInfo.HLT_HT325_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DiJet90_AlphaT0p52_v1")
          triggerInfo.HLT_HT350_DiJet90_AlphaT0p52_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet40_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_DisplacedTrack_v1")
          triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1")
          triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT350_v1")
          triggerInfo.HLT_HT350_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT400_DiJet90_AlphaT0p51_v1")
          triggerInfo.HLT_HT400_DiJet90_AlphaT0p51_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT400_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT400_v1")
          triggerInfo.HLT_HT400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT425_v1")
          triggerInfo.HLT_HT425_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT500_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT550_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT575_v1")
          triggerInfo.HLT_HT575_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT650_DisplacedDijet80_Inclusive_v1")
          triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT650_DisplacedDijet80_Inclusive_v2")
          triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT750_DisplacedDijet80_Inclusive_v1")
          triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_HT750_DisplacedDijet80_Inclusive_v2")
          triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1")
          triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu16_eta2p1_CaloMET30_v1")
          triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoMu27_v1")
          triggerInfo.HLT_IsoMu27_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoTkMu20_eta2p1_v1")
          triggerInfo.HLT_IsoTkMu20_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoTkMu24_eta2p1_v1")
          triggerInfo.HLT_IsoTkMu24_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_IsoTkMu27_v1")
          triggerInfo.HLT_IsoTkMu27_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_JetE30_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_JetE30_NoBPTX_v1")
          triggerInfo.HLT_JetE30_NoBPTX_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_JetE50_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_JetE70_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v1")
          triggerInfo.HLT_L1_TripleJet_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v4")
          triggerInfo.HLT_L1_TripleJet_VBF_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v5")
          triggerInfo.HLT_L1_TripleJet_VBF_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2DoubleMu23_NoVertex_v1")
          triggerInfo.HLT_L2DoubleMu23_NoVertex_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1")
          triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1")
          triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2Mu10_NoVertex_NoBPTX_v1")
          triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1")
          triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_LooseIsoPFTau50_Trk30_eta2p1_v1")
          triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_MET75_IsoTrk50_v1")
          triggerInfo.HLT_MET75_IsoTrk50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_MET90_IsoTrk50_v1")
          triggerInfo.HLT_MET90_IsoTrk50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu10_CentralPFJet40_BTagCSV_v1")
          triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_L1OR_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu14er_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT600_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu15_PFHT300_v1")
          triggerInfo.HLT_Mu15_PFHT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu16_eta2p1_CaloMET30_v1")
          triggerInfo.HLT_Mu16_eta2p1_CaloMET30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_DZ_v1")
          triggerInfo.HLT_Mu17_Mu8_DZ_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_SameSign_DPhi_v1")
          triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_SameSign_v1")
          triggerInfo.HLT_Mu17_Mu8_SameSign_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_Photon30_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_Photon35_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TkMu8_DZ_v1")
          triggerInfo.HLT_Mu17_TkMu8_DZ_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu24_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu24_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu24_eta2p1_v1")
          triggerInfo.HLT_Mu24_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu25_TkMu0_dEta18_Onia_v1")
          triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu27_v1")
          triggerInfo.HLT_Mu27_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1")
          triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu30_TkMu11_v1")
          triggerInfo.HLT_Mu30_TkMu11_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1")
          triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu34_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu34_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1")
          triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1")
          triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu40_eta2p1_PFJet200_PFJet50_v1")
          triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1")
          triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu45_eta2p1_v1")
          triggerInfo.HLT_Mu45_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu50_v1")
          triggerInfo.HLT_Mu50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1")
          triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1")
          triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_L2Mu2_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_L2Mu2_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track2_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track2_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track2_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track2_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track3p5_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track3p5_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track3p5_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track3p5_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track7_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track7_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu7p5_Track7_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track7_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1")
          triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Mu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu8_TrkIsoVVL_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT125_v2")
          triggerInfo.HLT_PFHT125_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT125_v3")
          triggerInfo.HLT_PFHT125_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT200_v2")
          triggerInfo.HLT_PFHT200_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT200_v3")
          triggerInfo.HLT_PFHT200_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT200_v4")
          triggerInfo.HLT_PFHT200_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT250_v2")
          triggerInfo.HLT_PFHT250_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT250_v3")
          triggerInfo.HLT_PFHT250_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT250_v4")
          triggerInfo.HLT_PFHT250_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT300_v2")
          triggerInfo.HLT_PFHT300_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT300_v3")
          triggerInfo.HLT_PFHT300_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT300_v5")
          triggerInfo.HLT_PFHT300_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT350_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT350_v1")
          triggerInfo.HLT_PFHT350_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT350_v3")
          triggerInfo.HLT_PFHT350_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT350_v4")
          triggerInfo.HLT_PFHT350_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT350_v6")
          triggerInfo.HLT_PFHT350_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3")
          triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2")
          triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3")
          triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v3")
          triggerInfo.HLT_PFHT400_SixJet30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v4")
          triggerInfo.HLT_PFHT400_SixJet30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v5")
          triggerInfo.HLT_PFHT400_SixJet30_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_v2")
          triggerInfo.HLT_PFHT400_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_v3")
          triggerInfo.HLT_PFHT400_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT400_v5")
          triggerInfo.HLT_PFHT400_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_BTagCSV_p056_v2")
          triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_BTagCSV_p056_v3")
          triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3")
          triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v3")
          triggerInfo.HLT_PFHT450_SixJet40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v4")
          triggerInfo.HLT_PFHT450_SixJet40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v5")
          triggerInfo.HLT_PFHT450_SixJet40_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT475_v2")
          triggerInfo.HLT_PFHT475_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT475_v3")
          triggerInfo.HLT_PFHT475_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT475_v5")
          triggerInfo.HLT_PFHT475_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v1")
          triggerInfo.HLT_PFHT550_4JetPt50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v2")
          triggerInfo.HLT_PFHT550_4JetPt50_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v4")
          triggerInfo.HLT_PFHT550_4JetPt50_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT550_4Jet_v1")
          triggerInfo.HLT_PFHT550_4Jet_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT600_v1")
          triggerInfo.HLT_PFHT600_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT600_v3")
          triggerInfo.HLT_PFHT600_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT600_v4")
          triggerInfo.HLT_PFHT600_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT600_v6")
          triggerInfo.HLT_PFHT600_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v1")
          triggerInfo.HLT_PFHT650_4JetPt50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v2")
          triggerInfo.HLT_PFHT650_4JetPt50_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v4")
          triggerInfo.HLT_PFHT650_4JetPt50_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_4Jet_v1")
          triggerInfo.HLT_PFHT650_4Jet_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_v1")
          triggerInfo.HLT_PFHT650_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_v3")
          triggerInfo.HLT_PFHT650_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_v4")
          triggerInfo.HLT_PFHT650_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT650_v6")
          triggerInfo.HLT_PFHT650_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v3")
          triggerInfo.HLT_PFHT750_4JetPt50_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v4")
          triggerInfo.HLT_PFHT750_4JetPt50_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v6")
          triggerInfo.HLT_PFHT750_4JetPt50_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT750_4Jet_v1")
          triggerInfo.HLT_PFHT750_4Jet_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT800_v2")
          triggerInfo.HLT_PFHT800_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT800_v3")
          triggerInfo.HLT_PFHT800_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT800_v5")
          triggerInfo.HLT_PFHT800_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT900_v1")
          triggerInfo.HLT_PFHT900_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT900_v2")
          triggerInfo.HLT_PFHT900_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFHT900_v4")
          triggerInfo.HLT_PFHT900_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet140_v1")
          triggerInfo.HLT_PFJet140_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet140_v4")
          triggerInfo.HLT_PFJet140_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet140_v5")
          triggerInfo.HLT_PFJet140_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet140_v6")
          triggerInfo.HLT_PFJet140_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet200_v1")
          triggerInfo.HLT_PFJet200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet200_v4")
          triggerInfo.HLT_PFJet200_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet200_v5")
          triggerInfo.HLT_PFJet200_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet200_v6")
          triggerInfo.HLT_PFJet200_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet260_v1")
          triggerInfo.HLT_PFJet260_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet260_v4")
          triggerInfo.HLT_PFJet260_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet260_v5")
          triggerInfo.HLT_PFJet260_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet260_v6")
          triggerInfo.HLT_PFJet260_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet320_v1")
          triggerInfo.HLT_PFJet320_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet320_v4")
          triggerInfo.HLT_PFJet320_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet320_v5")
          triggerInfo.HLT_PFJet320_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet320_v6")
          triggerInfo.HLT_PFJet320_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet400_v1")
          triggerInfo.HLT_PFJet400_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet400_v4")
          triggerInfo.HLT_PFJet400_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet400_v5")
          triggerInfo.HLT_PFJet400_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet400_v6")
          triggerInfo.HLT_PFJet400_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet40_v1")
          triggerInfo.HLT_PFJet40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet40_v4")
          triggerInfo.HLT_PFJet40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet40_v5")
          triggerInfo.HLT_PFJet40_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet40_v7")
          triggerInfo.HLT_PFJet40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet450_v1")
          triggerInfo.HLT_PFJet450_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet450_v4")
          triggerInfo.HLT_PFJet450_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet450_v5")
          triggerInfo.HLT_PFJet450_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet450_v6")
          triggerInfo.HLT_PFJet450_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet500_v1")
          triggerInfo.HLT_PFJet500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet500_v4")
          triggerInfo.HLT_PFJet500_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet500_v5")
          triggerInfo.HLT_PFJet500_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet500_v6")
          triggerInfo.HLT_PFJet500_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet60_v1")
          triggerInfo.HLT_PFJet60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet60_v4")
          triggerInfo.HLT_PFJet60_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet60_v5")
          triggerInfo.HLT_PFJet60_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet60_v7")
          triggerInfo.HLT_PFJet60_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet80_v1")
          triggerInfo.HLT_PFJet80_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet80_v4")
          triggerInfo.HLT_PFJet80_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet80_v5")
          triggerInfo.HLT_PFJet80_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFJet80_v6")
          triggerInfo.HLT_PFJet80_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFMET120_NoiseCleaned_BTagCSV07_v1")
          triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFMET120_NoiseCleaned_Mu5_v1")
          triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFMET120_PFMHT120_IDLoose_v1")
          triggerInfo.HLT_PFMET120_PFMHT120_IDLoose_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PFMET170_NoiseCleaned_v1")
          triggerInfo.HLT_PFMET170_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_v1")
          triggerInfo.HLT_Photon120_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_v3")
          triggerInfo.HLT_Photon120_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_v4")
          triggerInfo.HLT_Photon120_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon120_v6")
          triggerInfo.HLT_Photon120_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon125_v1")
          triggerInfo.HLT_Photon125_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon125_v2")
          triggerInfo.HLT_Photon125_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon125_v4")
          triggerInfo.HLT_Photon125_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_NoiseCleaned_v1")
          triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v1")
          triggerInfo.HLT_Photon135_PFMET100_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v2")
          triggerInfo.HLT_Photon135_PFMET100_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v6")
          triggerInfo.HLT_Photon135_PFMET100_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_PFMET40_v1")
          triggerInfo.HLT_Photon135_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon135_VBF_v1")
          triggerInfo.HLT_Photon135_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon150_v1")
          triggerInfo.HLT_Photon150_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon150_v2")
          triggerInfo.HLT_Photon150_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon150_v4")
          triggerInfo.HLT_Photon150_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon155_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v1")
          triggerInfo.HLT_Photon165_HE10_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v3")
          triggerInfo.HLT_Photon165_HE10_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v4")
          triggerInfo.HLT_Photon165_HE10_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v7")
          triggerInfo.HLT_Photon165_HE10_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v8")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v8 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon175_v1")
          triggerInfo.HLT_Photon175_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon175_v3")
          triggerInfo.HLT_Photon175_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon175_v4")
          triggerInfo.HLT_Photon175_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon175_v7")
          triggerInfo.HLT_Photon175_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v2")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v6")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_v1")
          triggerInfo.HLT_Photon22_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_v2")
          triggerInfo.HLT_Photon22_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_v3")
          triggerInfo.HLT_Photon22_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon22_v5")
          triggerInfo.HLT_Photon22_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v1")
          triggerInfo.HLT_Photon250_NoHE_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v2")
          triggerInfo.HLT_Photon250_NoHE_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v3")
          triggerInfo.HLT_Photon250_NoHE_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v6")
          triggerInfo.HLT_Photon250_NoHE_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1")
          triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v1")
          triggerInfo.HLT_Photon300_NoHE_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v2")
          triggerInfo.HLT_Photon300_NoHE_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v3")
          triggerInfo.HLT_Photon300_NoHE_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v6")
          triggerInfo.HLT_Photon300_NoHE_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_v1")
          triggerInfo.HLT_Photon30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_v3")
          triggerInfo.HLT_Photon30_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_v4")
          triggerInfo.HLT_Photon30_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon30_v6")
          triggerInfo.HLT_Photon30_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1")
          triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1")
          triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_v1")
          triggerInfo.HLT_Photon36_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_v3")
          triggerInfo.HLT_Photon36_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_v4")
          triggerInfo.HLT_Photon36_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon36_v6")
          triggerInfo.HLT_Photon36_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon500_v1")
          triggerInfo.HLT_Photon500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon500_v2")
          triggerInfo.HLT_Photon500_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon500_v5")
          triggerInfo.HLT_Photon500_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_v1")
          triggerInfo.HLT_Photon50_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_v3")
          triggerInfo.HLT_Photon50_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_v4")
          triggerInfo.HLT_Photon50_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon50_v6")
          triggerInfo.HLT_Photon50_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon600_v1")
          triggerInfo.HLT_Photon600_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon600_v2")
          triggerInfo.HLT_Photon600_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon600_v5")
          triggerInfo.HLT_Photon600_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_v1")
          triggerInfo.HLT_Photon75_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_v3")
          triggerInfo.HLT_Photon75_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_v4")
          triggerInfo.HLT_Photon75_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon75_v6")
          triggerInfo.HLT_Photon75_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v1")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v2")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v4")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v1")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v3")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v4")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v7")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v2")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v3")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v6")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v7 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_v1")
          triggerInfo.HLT_Photon90_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_v3")
          triggerInfo.HLT_Photon90_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_v4")
          triggerInfo.HLT_Photon90_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Photon90_v6")
          triggerInfo.HLT_Photon90_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Physics_v1")
          triggerInfo.HLT_Physics_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity110_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity110_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity135_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity135_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity160_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity160_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity60_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity60_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity85_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity85_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadJet45_DoubleCSV0p5_v1")
          triggerInfo.HLT_QuadJet45_DoubleCSV0p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadJet45_TripleCSV0p5_v1")
          triggerInfo.HLT_QuadJet45_TripleCSV0p5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadMuon0_Dimuon0_Jpsi_v1")
          triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadMuon0_Dimuon0_Upsilon_v1")
          triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadPFJet_BTagCSV_VBF_v1")
          triggerInfo.HLT_QuadPFJet_BTagCSV_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v1")
          triggerInfo.HLT_QuadPFJet_VBF_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v4")
          triggerInfo.HLT_QuadPFJet_VBF_v4 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v5")
          triggerInfo.HLT_QuadPFJet_VBF_v5 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v6")
          triggerInfo.HLT_QuadPFJet_VBF_v6 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_Rsq0p36_v1")
          triggerInfo.HLT_Rsq0p36_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_RsqMR260_Rsq0p09_MR200_4jet_v1")
          triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_RsqMR260_Rsq0p09_MR200_v1")
          triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_RsqMR300_Rsq0p09_MR200_4jet_v1")
          triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_RsqMR300_Rsq0p09_MR200_v1")
          triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_SingleCentralPFJet170_CFMax0p1_v1")
          triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_SingleCentralPFJet170_CFMax0p1_v3")
          triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v3 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_TkMu24_eta2p1_v1")
          triggerInfo.HLT_TkMu24_eta2p1_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_TkMu27_v1")
          triggerInfo.HLT_TkMu27_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_TripleMu_12_10_5_v1")
          triggerInfo.HLT_TripleMu_12_10_5_v1 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_TightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2 = triggerResults->accept(i);
        else if (currentTrigger == "HLT_ZeroBias_v1")
          triggerInfo.HLT_ZeroBias_v1 = triggerResults->accept(i);

    } // end loop over trigger names

  } // end FillTriggerBits function
  void FillTriggerPrescales(triggerInfo_t &triggerInfo, const edm::TriggerResults* triggerResults, const pat::PackedTriggerPrescales* prescales, const edm::Event& iEvent) {

    // first clear decisions from previous event
    ExoDiPhotons::InitTriggerInfo(triggerInfo);

    //get trigger names from the event
    std::vector<std::string> trigNames = iEvent.triggerNames(*triggerResults).triggerNames();

    // loop over the trigger names and write trigger bits and prescales
    for (unsigned int i=0; i < trigNames.size(); i++){
      std::string currentTrigger = trigNames.at(i);
      
        if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v1")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v2")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK4PFDJet60_Eta2p1ForPPRef_v3")
          triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v1")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v2")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK4PFDJet80_Eta2p1ForPPRef_v3")
          triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_v2")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet250_200_TrimMass30_v3")
          triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_v2")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_v3")
          triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4")
          triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5")
          triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6")
          triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet140_v1")
          triggerInfo.HLT_AK8PFJet140_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet140_v2")
          triggerInfo.HLT_AK8PFJet140_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet200_v1")
          triggerInfo.HLT_AK8PFJet200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet200_v2")
          triggerInfo.HLT_AK8PFJet200_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet260_v1")
          triggerInfo.HLT_AK8PFJet260_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet260_v2")
          triggerInfo.HLT_AK8PFJet260_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet320_v1")
          triggerInfo.HLT_AK8PFJet320_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet320_v2")
          triggerInfo.HLT_AK8PFJet320_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet360TrimMod_Mass30_v1")
          triggerInfo.HLT_AK8PFJet360TrimMod_Mass30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v3")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v4")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v5")
          triggerInfo.HLT_AK8PFJet360_TrimMass30_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet400_v1")
          triggerInfo.HLT_AK8PFJet400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet400_v2")
          triggerInfo.HLT_AK8PFJet400_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet40_v1")
          triggerInfo.HLT_AK8PFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet40_v3")
          triggerInfo.HLT_AK8PFJet40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet450_v1")
          triggerInfo.HLT_AK8PFJet450_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet450_v2")
          triggerInfo.HLT_AK8PFJet450_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet500_v1")
          triggerInfo.HLT_AK8PFJet500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet500_v2")
          triggerInfo.HLT_AK8PFJet500_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet60_v1")
          triggerInfo.HLT_AK8PFJet60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet60_v2")
          triggerInfo.HLT_AK8PFJet60_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet80_v1")
          triggerInfo.HLT_AK8PFJet80_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_AK8PFJet80_v2")
          triggerInfo.HLT_AK8PFJet80_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet110_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet110_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet20_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet20_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet40_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet40_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_BTagMu_DiJet70_Mu5_v1")
          triggerInfo.HLT_BTagMu_DiJet70_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_BTagMu_Jet300_Mu5_v1")
          triggerInfo.HLT_BTagMu_Jet300_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v1")
          triggerInfo.HLT_CaloJet500_NoJetID_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v2")
          triggerInfo.HLT_CaloJet500_NoJetID_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v3")
          triggerInfo.HLT_CaloJet500_NoJetID_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloJet500_NoJetID_v4")
          triggerInfo.HLT_CaloJet500_NoJetID_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1")
          triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1")
          triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve140_v1")
          triggerInfo.HLT_DiCaloJetAve140_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve200_v1")
          triggerInfo.HLT_DiCaloJetAve200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve260_v1")
          triggerInfo.HLT_DiCaloJetAve260_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve320_v1")
          triggerInfo.HLT_DiCaloJetAve320_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve400_v1")
          triggerInfo.HLT_DiCaloJetAve400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve40_v1")
          triggerInfo.HLT_DiCaloJetAve40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve500_v1")
          triggerInfo.HLT_DiCaloJetAve500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve60_v1")
          triggerInfo.HLT_DiCaloJetAve60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCaloJetAve80_v1")
          triggerInfo.HLT_DiCaloJetAve80_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_CFMax0p1_v1")
          triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_CFMax0p1_v3")
          triggerInfo.HLT_DiCentralPFJet170_CFMax0p1_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_v1")
          triggerInfo.HLT_DiCentralPFJet170_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet170_v3")
          triggerInfo.HLT_DiCentralPFJet170_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet220_CFMax0p3_v1")
          triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet220_CFMax0p3_v3")
          triggerInfo.HLT_DiCentralPFJet220_CFMax0p3_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet330_CFMax0p5_v1")
          triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet330_CFMax0p5_v3")
          triggerInfo.HLT_DiCentralPFJet330_CFMax0p5_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet430_v1")
          triggerInfo.HLT_DiCentralPFJet430_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet430_v3")
          triggerInfo.HLT_DiCentralPFJet430_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1")
          triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1")
          triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve100_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v2")
          triggerInfo.HLT_DiPFJetAve140_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v3")
          triggerInfo.HLT_DiPFJetAve140_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve140_v5")
          triggerInfo.HLT_DiPFJetAve140_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve160_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v2")
          triggerInfo.HLT_DiPFJetAve200_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v3")
          triggerInfo.HLT_DiPFJetAve200_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve200_v5")
          triggerInfo.HLT_DiPFJetAve200_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve220_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v2")
          triggerInfo.HLT_DiPFJetAve260_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v3")
          triggerInfo.HLT_DiPFJetAve260_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve260_v5")
          triggerInfo.HLT_DiPFJetAve260_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve300_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v5")
          triggerInfo.HLT_DiPFJetAve30_HFJEC_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v2")
          triggerInfo.HLT_DiPFJetAve320_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v3")
          triggerInfo.HLT_DiPFJetAve320_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve320_v5")
          triggerInfo.HLT_DiPFJetAve320_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v2")
          triggerInfo.HLT_DiPFJetAve400_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v3")
          triggerInfo.HLT_DiPFJetAve400_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve400_v5")
          triggerInfo.HLT_DiPFJetAve400_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v2")
          triggerInfo.HLT_DiPFJetAve40_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v3")
          triggerInfo.HLT_DiPFJetAve40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve40_v6")
          triggerInfo.HLT_DiPFJetAve40_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v2")
          triggerInfo.HLT_DiPFJetAve500_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v3")
          triggerInfo.HLT_DiPFJetAve500_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve500_v5")
          triggerInfo.HLT_DiPFJetAve500_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve60_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v2")
          triggerInfo.HLT_DiPFJetAve60_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v3")
          triggerInfo.HLT_DiPFJetAve60_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve60_v6")
          triggerInfo.HLT_DiPFJetAve60_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v1")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v3")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v4")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v6")
          triggerInfo.HLT_DiPFJetAve80_HFJEC_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v2")
          triggerInfo.HLT_DiPFJetAve80_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v3")
          triggerInfo.HLT_DiPFJetAve80_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DiPFJetAve80_v5")
          triggerInfo.HLT_DiPFJetAve80_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon0_Jpsi_Muon_v1")
          triggerInfo.HLT_Dimuon0_Jpsi_Muon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon0_Upsilon_Muon_v1")
          triggerInfo.HLT_Dimuon0_Upsilon_Muon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1")
          triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon0er16_Jpsi_NoVertexing_v1")
          triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon13_PsiPrime_v1")
          triggerInfo.HLT_Dimuon13_PsiPrime_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon13_Upsilon_v1")
          triggerInfo.HLT_Dimuon13_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon20_Jpsi_v1")
          triggerInfo.HLT_Dimuon20_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Dimuon6_Jpsi_NoVertexing_v1")
          triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6")
          triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6")
          triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1")
          triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6")
          triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7")
          triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6")
          triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8")
          triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_MW_v2")
          triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_MW_v6")
          triggerInfo.HLT_DoubleEle33_CaloIdL_MW_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_v2")
          triggerInfo.HLT_DoubleEle33_CaloIdL_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_v6")
          triggerInfo.HLT_DoubleEle33_CaloIdL_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6")
          triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1")
          triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8")
          triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleIsoMu17_eta2p1_v1")
          triggerInfo.HLT_DoubleIsoMu17_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleJet90_Double30_DoubleCSV0p5_v1")
          triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleJet90_Double30_TripleCSV0p5_v1")
          triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1")
          triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1")
          triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu33NoFiltersNoVtx_v1")
          triggerInfo.HLT_DoubleMu33NoFiltersNoVtx_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu38NoFiltersNoVtx_v1")
          triggerInfo.HLT_DoubleMu38NoFiltersNoVtx_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu4_3_Bs_v1")
          triggerInfo.HLT_DoubleMu4_3_Bs_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu4_3_Jpsi_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu4_JpsiTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1")
          triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoubleMu8_Mass8_PFHT300_v1")
          triggerInfo.HLT_DoubleMu8_Mass8_PFHT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton40_v1")
          triggerInfo.HLT_DoublePhoton40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton50_v1")
          triggerInfo.HLT_DoublePhoton50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v1")
          triggerInfo.HLT_DoublePhoton60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v2")
          triggerInfo.HLT_DoublePhoton60_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton60_v6")
          triggerInfo.HLT_DoublePhoton60_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v1")
          triggerInfo.HLT_DoublePhoton85_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v2")
          triggerInfo.HLT_DoublePhoton85_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v3")
          triggerInfo.HLT_DoublePhoton85_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_DoublePhoton85_v7")
          triggerInfo.HLT_DoublePhoton85_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_ECALHT800_v2")
          triggerInfo.HLT_ECALHT800_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_ECALHT800_v3")
          triggerInfo.HLT_ECALHT800_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_ECALHT800_v4")
          triggerInfo.HLT_ECALHT800_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele105_CaloIdVT_GsfTrkIdT_v1")
          triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5")
          triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1")
          triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7")
          triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele15_IsoVVVL_PFHT600_v1")
          triggerInfo.HLT_Ele15_IsoVVVL_PFHT600_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele15_PFHT300_v1")
          triggerInfo.HLT_Ele15_PFHT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7")
          triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_GsfTrkIdVL_v2")
          triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_GsfTrkIdVL_v5")
          triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6")
          triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2")
          triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5")
          triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8")
          triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele20WP60_Ele8_Mass55_v1")
          triggerInfo.HLT_Ele20WP60_Ele8_Mass55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele22_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7")
          triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8")
          triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele25WP60_SC4_Mass55_v1")
          triggerInfo.HLT_Ele25WP60_SC4_Mass55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1")
          triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_HighEta_Ele20_Mass55_v2")
          triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_HighEta_Ele20_Mass55_v6")
          triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele27_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v2")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v3")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v7")
          triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v3")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v4")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v8")
          triggerInfo.HLT_Ele30WP60_SC4_Mass55_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele32_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
          triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1")
          triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele35_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele40_eta2p1_WP85_Gsf_v1")
          triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1")
          triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2")
          triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5")
          triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7")
          triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2000_v1")
          triggerInfo.HLT_HT2000_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2000_v2")
          triggerInfo.HLT_HT2000_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2000_v3")
          triggerInfo.HLT_HT2000_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT200_DiJet90_AlphaT0p57_v1")
          triggerInfo.HLT_HT200_DiJet90_AlphaT0p57_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT200_v1")
          triggerInfo.HLT_HT200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2500_v1")
          triggerInfo.HLT_HT2500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2500_v2")
          triggerInfo.HLT_HT2500_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT2500_v3")
          triggerInfo.HLT_HT2500_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT250_DiJet90_AlphaT0p55_v1")
          triggerInfo.HLT_HT250_DiJet90_AlphaT0p55_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT250_DisplacedDijet40_DisplacedTrack_v2")
          triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT250_v1")
          triggerInfo.HLT_HT250_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT275_v1")
          triggerInfo.HLT_HT275_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT300_DiJet90_AlphaT0p53_v1")
          triggerInfo.HLT_HT300_DiJet90_AlphaT0p53_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT300_v1")
          triggerInfo.HLT_HT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT325_v1")
          triggerInfo.HLT_HT325_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DiJet90_AlphaT0p52_v1")
          triggerInfo.HLT_HT350_DiJet90_AlphaT0p52_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet40_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_DisplacedTrack_v1")
          triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1")
          triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2")
          triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT350_v1")
          triggerInfo.HLT_HT350_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT400_DiJet90_AlphaT0p51_v1")
          triggerInfo.HLT_HT400_DiJet90_AlphaT0p51_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT400_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT400_v1")
          triggerInfo.HLT_HT400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT425_v1")
          triggerInfo.HLT_HT425_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT500_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT550_DisplacedDijet40_Inclusive_v2")
          triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT575_v1")
          triggerInfo.HLT_HT575_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT650_DisplacedDijet80_Inclusive_v1")
          triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT650_DisplacedDijet80_Inclusive_v2")
          triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT750_DisplacedDijet80_Inclusive_v1")
          triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_HT750_DisplacedDijet80_Inclusive_v2")
          triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1")
          triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu16_eta2p1_CaloMET30_v1")
          triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu17_eta2p1_v1")
          triggerInfo.HLT_IsoMu17_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu20_eta2p1_v1")
          triggerInfo.HLT_IsoMu20_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu24_eta2p1_v1")
          triggerInfo.HLT_IsoMu24_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoMu27_v1")
          triggerInfo.HLT_IsoMu27_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoTkMu20_eta2p1_v1")
          triggerInfo.HLT_IsoTkMu20_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoTkMu24_eta2p1_v1")
          triggerInfo.HLT_IsoTkMu24_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_IsoTkMu27_v1")
          triggerInfo.HLT_IsoTkMu27_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_JetE30_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_JetE30_NoBPTX_v1")
          triggerInfo.HLT_JetE30_NoBPTX_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_JetE50_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_JetE70_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v1")
          triggerInfo.HLT_L1_TripleJet_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v4")
          triggerInfo.HLT_L1_TripleJet_VBF_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L1_TripleJet_VBF_v5")
          triggerInfo.HLT_L1_TripleJet_VBF_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2DoubleMu23_NoVertex_v1")
          triggerInfo.HLT_L2DoubleMu23_NoVertex_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1")
          triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1")
          triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2Mu10_NoVertex_NoBPTX_v1")
          triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1")
          triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1")
          triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_LooseIsoPFTau50_Trk30_eta2p1_v1")
          triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_MET75_IsoTrk50_v1")
          triggerInfo.HLT_MET75_IsoTrk50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_MET90_IsoTrk50_v1")
          triggerInfo.HLT_MET90_IsoTrk50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1")
          triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu10_CentralPFJet40_BTagCSV_v1")
          triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_L1OR_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu12_Photon25_CaloIdL_v1")
          triggerInfo.HLT_Mu12_Photon25_CaloIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu14er_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT600_v1")
          triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu15_PFHT300_v1")
          triggerInfo.HLT_Mu15_PFHT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu16_eta2p1_CaloMET30_v1")
          triggerInfo.HLT_Mu16_eta2p1_CaloMET30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_DZ_v1")
          triggerInfo.HLT_Mu17_Mu8_DZ_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_SameSign_DPhi_v1")
          triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_Mu8_SameSign_v1")
          triggerInfo.HLT_Mu17_Mu8_SameSign_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_Photon30_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_Photon35_CaloIdL_L1ISO_v1")
          triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TkMu8_DZ_v1")
          triggerInfo.HLT_Mu17_TkMu8_DZ_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu17_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu17_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu24_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu24_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu24_eta2p1_v1")
          triggerInfo.HLT_Mu24_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu25_TkMu0_dEta18_Onia_v1")
          triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu27_v1")
          triggerInfo.HLT_Mu27_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1")
          triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1")
          triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu30_TkMu11_v1")
          triggerInfo.HLT_Mu30_TkMu11_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1")
          triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu34_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu34_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1")
          triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1")
          triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu40_eta2p1_PFJet200_PFJet50_v1")
          triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1")
          triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu45_eta2p1_v1")
          triggerInfo.HLT_Mu45_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu50_v1")
          triggerInfo.HLT_Mu50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1")
          triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1")
          triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_L2Mu2_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_L2Mu2_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track2_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track2_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track2_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track2_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track3p5_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track3p5_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track3p5_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track3p5_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track7_Jpsi_v1")
          triggerInfo.HLT_Mu7p5_Track7_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu7p5_Track7_Upsilon_v1")
          triggerInfo.HLT_Mu7p5_Track7_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1")
          triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1")
          triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1")
          triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Mu8_TrkIsoVVL_v1")
          triggerInfo.HLT_Mu8_TrkIsoVVL_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT125_v2")
          triggerInfo.HLT_PFHT125_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT125_v3")
          triggerInfo.HLT_PFHT125_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT200_v2")
          triggerInfo.HLT_PFHT200_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT200_v3")
          triggerInfo.HLT_PFHT200_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT200_v4")
          triggerInfo.HLT_PFHT200_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT250_v2")
          triggerInfo.HLT_PFHT250_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT250_v3")
          triggerInfo.HLT_PFHT250_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT250_v4")
          triggerInfo.HLT_PFHT250_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT300_v2")
          triggerInfo.HLT_PFHT300_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT300_v3")
          triggerInfo.HLT_PFHT300_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT300_v5")
          triggerInfo.HLT_PFHT300_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT350_PFMET120_NoiseCleaned_v1")
          triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT350_v1")
          triggerInfo.HLT_PFHT350_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT350_v3")
          triggerInfo.HLT_PFHT350_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT350_v4")
          triggerInfo.HLT_PFHT350_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT350_v6")
          triggerInfo.HLT_PFHT350_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3")
          triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2")
          triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3")
          triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v3")
          triggerInfo.HLT_PFHT400_SixJet30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v4")
          triggerInfo.HLT_PFHT400_SixJet30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_SixJet30_v5")
          triggerInfo.HLT_PFHT400_SixJet30_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_v2")
          triggerInfo.HLT_PFHT400_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_v3")
          triggerInfo.HLT_PFHT400_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT400_v5")
          triggerInfo.HLT_PFHT400_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_BTagCSV_p056_v2")
          triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_BTagCSV_p056_v3")
          triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3")
          triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v3")
          triggerInfo.HLT_PFHT450_SixJet40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v4")
          triggerInfo.HLT_PFHT450_SixJet40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT450_SixJet40_v5")
          triggerInfo.HLT_PFHT450_SixJet40_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT475_v2")
          triggerInfo.HLT_PFHT475_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT475_v3")
          triggerInfo.HLT_PFHT475_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT475_v5")
          triggerInfo.HLT_PFHT475_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v1")
          triggerInfo.HLT_PFHT550_4JetPt50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v2")
          triggerInfo.HLT_PFHT550_4JetPt50_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT550_4JetPt50_v4")
          triggerInfo.HLT_PFHT550_4JetPt50_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT550_4Jet_v1")
          triggerInfo.HLT_PFHT550_4Jet_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT600_v1")
          triggerInfo.HLT_PFHT600_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT600_v3")
          triggerInfo.HLT_PFHT600_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT600_v4")
          triggerInfo.HLT_PFHT600_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT600_v6")
          triggerInfo.HLT_PFHT600_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v1")
          triggerInfo.HLT_PFHT650_4JetPt50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v2")
          triggerInfo.HLT_PFHT650_4JetPt50_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_4JetPt50_v4")
          triggerInfo.HLT_PFHT650_4JetPt50_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_4Jet_v1")
          triggerInfo.HLT_PFHT650_4Jet_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6")
          triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6")
          triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_v1")
          triggerInfo.HLT_PFHT650_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_v3")
          triggerInfo.HLT_PFHT650_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_v4")
          triggerInfo.HLT_PFHT650_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT650_v6")
          triggerInfo.HLT_PFHT650_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v3")
          triggerInfo.HLT_PFHT750_4JetPt50_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v4")
          triggerInfo.HLT_PFHT750_4JetPt50_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT750_4JetPt50_v6")
          triggerInfo.HLT_PFHT750_4JetPt50_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT750_4Jet_v1")
          triggerInfo.HLT_PFHT750_4Jet_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT800_v2")
          triggerInfo.HLT_PFHT800_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT800_v3")
          triggerInfo.HLT_PFHT800_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT800_v5")
          triggerInfo.HLT_PFHT800_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT900_v1")
          triggerInfo.HLT_PFHT900_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT900_v2")
          triggerInfo.HLT_PFHT900_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFHT900_v4")
          triggerInfo.HLT_PFHT900_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet140_v1")
          triggerInfo.HLT_PFJet140_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet140_v4")
          triggerInfo.HLT_PFJet140_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet140_v5")
          triggerInfo.HLT_PFJet140_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet140_v6")
          triggerInfo.HLT_PFJet140_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet200_v1")
          triggerInfo.HLT_PFJet200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet200_v4")
          triggerInfo.HLT_PFJet200_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet200_v5")
          triggerInfo.HLT_PFJet200_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet200_v6")
          triggerInfo.HLT_PFJet200_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet260_v1")
          triggerInfo.HLT_PFJet260_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet260_v4")
          triggerInfo.HLT_PFJet260_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet260_v5")
          triggerInfo.HLT_PFJet260_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet260_v6")
          triggerInfo.HLT_PFJet260_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet320_v1")
          triggerInfo.HLT_PFJet320_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet320_v4")
          triggerInfo.HLT_PFJet320_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet320_v5")
          triggerInfo.HLT_PFJet320_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet320_v6")
          triggerInfo.HLT_PFJet320_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet400_v1")
          triggerInfo.HLT_PFJet400_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet400_v4")
          triggerInfo.HLT_PFJet400_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet400_v5")
          triggerInfo.HLT_PFJet400_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet400_v6")
          triggerInfo.HLT_PFJet400_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet40_v1")
          triggerInfo.HLT_PFJet40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet40_v4")
          triggerInfo.HLT_PFJet40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet40_v5")
          triggerInfo.HLT_PFJet40_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet40_v7")
          triggerInfo.HLT_PFJet40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet450_v1")
          triggerInfo.HLT_PFJet450_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet450_v4")
          triggerInfo.HLT_PFJet450_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet450_v5")
          triggerInfo.HLT_PFJet450_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet450_v6")
          triggerInfo.HLT_PFJet450_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet500_v1")
          triggerInfo.HLT_PFJet500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet500_v4")
          triggerInfo.HLT_PFJet500_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet500_v5")
          triggerInfo.HLT_PFJet500_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet500_v6")
          triggerInfo.HLT_PFJet500_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet60_v1")
          triggerInfo.HLT_PFJet60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet60_v4")
          triggerInfo.HLT_PFJet60_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet60_v5")
          triggerInfo.HLT_PFJet60_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet60_v7")
          triggerInfo.HLT_PFJet60_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet80_v1")
          triggerInfo.HLT_PFJet80_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet80_v4")
          triggerInfo.HLT_PFJet80_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet80_v5")
          triggerInfo.HLT_PFJet80_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFJet80_v6")
          triggerInfo.HLT_PFJet80_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFMET120_NoiseCleaned_BTagCSV07_v1")
          triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFMET120_NoiseCleaned_Mu5_v1")
          triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFMET120_PFMHT120_IDLoose_v1")
          triggerInfo.HLT_PFMET120_PFMHT120_IDLoose_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PFMET170_NoiseCleaned_v1")
          triggerInfo.HLT_PFMET170_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_v1")
          triggerInfo.HLT_Photon120_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_v3")
          triggerInfo.HLT_Photon120_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_v4")
          triggerInfo.HLT_Photon120_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon120_v6")
          triggerInfo.HLT_Photon120_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon125_v1")
          triggerInfo.HLT_Photon125_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon125_v2")
          triggerInfo.HLT_Photon125_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon125_v4")
          triggerInfo.HLT_Photon125_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_NoiseCleaned_v1")
          triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v1")
          triggerInfo.HLT_Photon135_PFMET100_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v2")
          triggerInfo.HLT_Photon135_PFMET100_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_PFMET100_v6")
          triggerInfo.HLT_Photon135_PFMET100_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_PFMET40_v1")
          triggerInfo.HLT_Photon135_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon135_VBF_v1")
          triggerInfo.HLT_Photon135_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon150_v1")
          triggerInfo.HLT_Photon150_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon150_v2")
          triggerInfo.HLT_Photon150_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon150_v4")
          triggerInfo.HLT_Photon150_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon155_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v1")
          triggerInfo.HLT_Photon165_HE10_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v3")
          triggerInfo.HLT_Photon165_HE10_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v4")
          triggerInfo.HLT_Photon165_HE10_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_HE10_v7")
          triggerInfo.HLT_Photon165_HE10_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v8")
          triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v8 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon175_v1")
          triggerInfo.HLT_Photon175_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon175_v3")
          triggerInfo.HLT_Photon175_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon175_v4")
          triggerInfo.HLT_Photon175_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon175_v7")
          triggerInfo.HLT_Photon175_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v2")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v6")
          triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_v1")
          triggerInfo.HLT_Photon22_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_v2")
          triggerInfo.HLT_Photon22_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_v3")
          triggerInfo.HLT_Photon22_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon22_v5")
          triggerInfo.HLT_Photon22_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v1")
          triggerInfo.HLT_Photon250_NoHE_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v2")
          triggerInfo.HLT_Photon250_NoHE_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v3")
          triggerInfo.HLT_Photon250_NoHE_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon250_NoHE_v6")
          triggerInfo.HLT_Photon250_NoHE_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7")
          triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1")
          triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v1")
          triggerInfo.HLT_Photon300_NoHE_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v2")
          triggerInfo.HLT_Photon300_NoHE_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v3")
          triggerInfo.HLT_Photon300_NoHE_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon300_NoHE_v6")
          triggerInfo.HLT_Photon300_NoHE_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_v1")
          triggerInfo.HLT_Photon30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_v3")
          triggerInfo.HLT_Photon30_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_v4")
          triggerInfo.HLT_Photon30_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon30_v6")
          triggerInfo.HLT_Photon30_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1")
          triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1")
          triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7")
          triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_v1")
          triggerInfo.HLT_Photon36_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_v3")
          triggerInfo.HLT_Photon36_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_v4")
          triggerInfo.HLT_Photon36_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon36_v6")
          triggerInfo.HLT_Photon36_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7")
          triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon500_v1")
          triggerInfo.HLT_Photon500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon500_v2")
          triggerInfo.HLT_Photon500_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon500_v5")
          triggerInfo.HLT_Photon500_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_v1")
          triggerInfo.HLT_Photon50_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_v3")
          triggerInfo.HLT_Photon50_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_v4")
          triggerInfo.HLT_Photon50_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon50_v6")
          triggerInfo.HLT_Photon50_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon600_v1")
          triggerInfo.HLT_Photon600_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon600_v2")
          triggerInfo.HLT_Photon600_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon600_v5")
          triggerInfo.HLT_Photon600_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_v1")
          triggerInfo.HLT_Photon75_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_v3")
          triggerInfo.HLT_Photon75_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_v4")
          triggerInfo.HLT_Photon75_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon75_v6")
          triggerInfo.HLT_Photon75_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v1")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v2")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v4")
          triggerInfo.HLT_Photon90_CaloIdL_HT300_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v1")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v3")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v4")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v7")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v2")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v3")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v6")
          triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_v1")
          triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v3")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v4")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v7")
          triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v7 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_v1")
          triggerInfo.HLT_Photon90_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_v3")
          triggerInfo.HLT_Photon90_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_v4")
          triggerInfo.HLT_Photon90_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Photon90_v6")
          triggerInfo.HLT_Photon90_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Physics_v1")
          triggerInfo.HLT_Physics_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity110_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity110_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity135_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity135_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity160_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity160_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity60_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity60_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_PixelTracks_Multiplicity85_v1")
          triggerInfo.HLT_PixelTracks_Multiplicity85_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadJet45_DoubleCSV0p5_v1")
          triggerInfo.HLT_QuadJet45_DoubleCSV0p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadJet45_TripleCSV0p5_v1")
          triggerInfo.HLT_QuadJet45_TripleCSV0p5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadMuon0_Dimuon0_Jpsi_v1")
          triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadMuon0_Dimuon0_Upsilon_v1")
          triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadPFJet_BTagCSV_VBF_v1")
          triggerInfo.HLT_QuadPFJet_BTagCSV_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v1")
          triggerInfo.HLT_QuadPFJet_VBF_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v4")
          triggerInfo.HLT_QuadPFJet_VBF_v4 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v5")
          triggerInfo.HLT_QuadPFJet_VBF_v5 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_QuadPFJet_VBF_v6")
          triggerInfo.HLT_QuadPFJet_VBF_v6 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_Rsq0p36_v1")
          triggerInfo.HLT_Rsq0p36_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_RsqMR260_Rsq0p09_MR200_4jet_v1")
          triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_RsqMR260_Rsq0p09_MR200_v1")
          triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_RsqMR300_Rsq0p09_MR200_4jet_v1")
          triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_RsqMR300_Rsq0p09_MR200_v1")
          triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_SingleCentralPFJet170_CFMax0p1_v1")
          triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_SingleCentralPFJet170_CFMax0p1_v3")
          triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1_v3 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_TkMu24_eta2p1_v1")
          triggerInfo.HLT_TkMu24_eta2p1_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_TkMu27_v1")
          triggerInfo.HLT_TkMu27_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_TripleMu_12_10_5_v1")
          triggerInfo.HLT_TripleMu_12_10_5_v1 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_TightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2")
          triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v2 = prescales->getPrescaleForIndex(i);
        else if (currentTrigger == "HLT_ZeroBias_v1")
          triggerInfo.HLT_ZeroBias_v1 = prescales->getPrescaleForIndex(i);


    } // end loop over trigger names
  } // end FillTriggerPrescales function


} // end of namespace

#endif
