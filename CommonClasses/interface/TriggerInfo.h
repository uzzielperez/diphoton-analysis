#ifndef TRIGGER_INFO_INC
#define TRIGGER_INFO_INC

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "L1Trigger/L1TGlobal/interface/L1TGlobalUtil.h"

namespace ExoDiPhotons
{
  
  struct l1Info_t{
    int L1_SingleEG40;
    int L1_SingleTau100er;
    int L1_SingleJet170;
  };

  struct triggerInfo_t {

    // holders for trigger bits or prescales
    int HLT_AK4PFDJet60_Eta2p1ForPPRef;
    int HLT_AK4PFDJet80_Eta2p1ForPPRef;
    int HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45;
    int HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20;
    int HLT_AK8DiPFJet250_200_TrimMass30;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45;
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20;
    int HLT_AK8DiPFJet280_200_TrimMass30;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20;
    int HLT_AK8PFHT650_TrimR0p1PT0p03Mass50;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50;
    int HLT_AK8PFJet140;
    int HLT_AK8PFJet200;
    int HLT_AK8PFJet260;
    int HLT_AK8PFJet320;
    int HLT_AK8PFJet360TrimMod_Mass30;
    int HLT_AK8PFJet360_TrimMass30;
    int HLT_AK8PFJet400;
    int HLT_AK8PFJet40;
    int HLT_AK8PFJet450;
    int HLT_AK8PFJet500;
    int HLT_AK8PFJet60;
    int HLT_AK8PFJet80;
    int HLT_BTagMu_DiJet110_Mu5;
    int HLT_BTagMu_DiJet20_Mu5;
    int HLT_BTagMu_DiJet40_Mu5;
    int HLT_BTagMu_DiJet70_Mu5;
    int HLT_BTagMu_Jet300_Mu5;
    int HLT_CaloJet500_NoJetID;
    int HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7;
    int HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose;
    int HLT_DiCaloJetAve140;
    int HLT_DiCaloJetAve200;
    int HLT_DiCaloJetAve260;
    int HLT_DiCaloJetAve320;
    int HLT_DiCaloJetAve400;
    int HLT_DiCaloJetAve40;
    int HLT_DiCaloJetAve500;
    int HLT_DiCaloJetAve60;
    int HLT_DiCaloJetAve80;
    int HLT_DiCentralPFJet170_CFMax0p1;
    int HLT_DiCentralPFJet170;
    int HLT_DiCentralPFJet220_CFMax0p3;
    int HLT_DiCentralPFJet330_CFMax0p5;
    int HLT_DiCentralPFJet430;
    int HLT_DiCentralPFJet70_PFMET120_NoiseCleaned;
    int HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
    int HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140;
    int HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80;
    int HLT_DiPFJetAve100_HFJEC;
    int HLT_DiPFJetAve140;
    int HLT_DiPFJetAve160_HFJEC;
    int HLT_DiPFJetAve200;
    int HLT_DiPFJetAve220_HFJEC;
    int HLT_DiPFJetAve260;
    int HLT_DiPFJetAve300_HFJEC;
    int HLT_DiPFJetAve30_HFJEC;
    int HLT_DiPFJetAve320;
    int HLT_DiPFJetAve400;
    int HLT_DiPFJetAve40;
    int HLT_DiPFJetAve500;
    int HLT_DiPFJetAve60_HFJEC;
    int HLT_DiPFJetAve60;
    int HLT_DiPFJetAve80_HFJEC;
    int HLT_DiPFJetAve80;
    int HLT_Dimuon0_Jpsi_Muon;
    int HLT_Dimuon0_Upsilon_Muon;
    int HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing;
    int HLT_Dimuon0er16_Jpsi_NoVertexing;
    int HLT_Dimuon13_PsiPrime;
    int HLT_Dimuon13_Upsilon;
    int HLT_Dimuon20_Jpsi;
    int HLT_Dimuon6_Jpsi_NoVertexing;
    int HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
    int HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
    int HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55;
    int HLT_DoubleEle24_22_eta2p1_WP85_Gsf;
    int HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf;
    int HLT_DoubleEle25_CaloIdL_GsfTrkIdVL;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;
    int HLT_DoubleEle33_CaloIdL_MW;
    int HLT_DoubleEle33_CaloIdL;
    int HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL;
    int HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300;
    int HLT_DoubleIsoMu17_eta2p1;
    int HLT_DoubleJet90_Double30_DoubleCSV0p5;
    int HLT_DoubleJet90_Double30_TripleCSV0p5;
    int HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
    int HLT_DoubleMu23NoFiltersNoVtxDisplaced;
    int HLT_DoubleMu28NoFiltersNoVtxDisplaced;
    int HLT_DoubleMu33NoFiltersNoVtx;
    int HLT_DoubleMu38NoFiltersNoVtx;
    int HLT_DoubleMu4_3_Bs;
    int HLT_DoubleMu4_3_Jpsi_Displaced;
    int HLT_DoubleMu4_JpsiTrk_Displaced;
    int HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
    int HLT_DoubleMu4_PsiPrimeTrk_Displaced;
    int HLT_DoubleMu8_Mass8_PFHT300;
    int HLT_DoublePhoton40;
    int HLT_DoublePhoton50;
    int HLT_DoublePhoton60;
    int HLT_DoublePhoton85;
    int HLT_ECALHT800;
    int HLT_Ele105_CaloIdVT_GsfTrkIdT;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13;
    int HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL;
    int HLT_Ele12_CaloIdM_TrackIdM_PFJet30;
    int HLT_Ele12_CaloId_TrackId_Iso_PFJet30;
    int HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400;
    int HLT_Ele15_IsoVVVL_PFHT400_PFMET70;
    int HLT_Ele15_IsoVVVL_PFHT600;
    int HLT_Ele15_PFHT300;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
    int HLT_Ele17_CaloIdL_GsfTrkIdVL;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL;
    int HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL;
    int HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele18_CaloIdM_TrackIdM_PFJet30;
    int HLT_Ele18_CaloId_TrackId_Iso_PFJet30;
    int HLT_Ele20WP60_Ele8_Mass55;
    int HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20;
    int HLT_Ele22_eta2p1_WP85_Gsf;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL;
    int HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
    int HLT_Ele23_CaloId_TrackId_Iso_PFJet30;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
    int HLT_Ele25WP60_SC4_Mass55;
    int HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW;
    int HLT_Ele27_HighEta_Ele20_Mass55;
    int HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
    int HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
    int HLT_Ele27_eta2p1_WP85_Gsf_HT200;
    int HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20;
    int HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40;
    int HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
    int HLT_Ele27_eta2p1_WP85_Gsf;
    int HLT_Ele30WP60_Ele8_Mass55;
    int HLT_Ele30WP60_SC4_Mass55;
    int HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV;
    int HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg;
    int HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20;
    int HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40;
    int HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35;
    int HLT_Ele32_eta2p1_WP85_Gsf;
    int HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele33_CaloIdM_TrackIdM_PFJet30;
    int HLT_Ele33_CaloId_TrackId_Iso_PFJet30;
    int HLT_Ele35_eta2p1_WP85_Gsf;
    int HLT_Ele40_eta2p1_WP85_Gsf;
    int HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50;
    int HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
    int HLT_HT2000;
    int HLT_HT200_DiJet90_AlphaT0p57;
    int HLT_HT200;
    int HLT_HT2500;
    int HLT_HT250_DiJet90_AlphaT0p55;
    int HLT_HT250_DisplacedDijet40_DisplacedTrack;
    int HLT_HT250;
    int HLT_HT275;
    int HLT_HT300_DiJet90_AlphaT0p53;
    int HLT_HT300;
    int HLT_HT325;
    int HLT_HT350_DiJet90_AlphaT0p52;
    int HLT_HT350_DisplacedDijet40_DisplacedTrack;
    int HLT_HT350_DisplacedDijet80_DisplacedTrack;
    int HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack;
    int HLT_HT350;
    int HLT_HT400_DiJet90_AlphaT0p51;
    int HLT_HT400_DisplacedDijet40_Inclusive;
    int HLT_HT400;
    int HLT_HT425;
    int HLT_HT500_DisplacedDijet40_Inclusive;
    int HLT_HT550_DisplacedDijet40_Inclusive;
    int HLT_HT575;
    int HLT_HT650_DisplacedDijet80_Inclusive;
    int HLT_HT750_DisplacedDijet80_Inclusive;
    int HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1;
    int HLT_IsoMu16_eta2p1_CaloMET30;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
    int HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg;
    int HLT_IsoMu17_eta2p1;
    int HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV;
    int HLT_IsoMu20_eta2p1_TriCentralPFJet40;
    int HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35;
    int HLT_IsoMu20_eta2p1;
    int HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV;
    int HLT_IsoMu24_eta2p1_LooseIsoPFTau20;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet40;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35;
    int HLT_IsoMu24_eta2p1;
    int HLT_IsoMu27;
    int HLT_IsoTkMu20_eta2p1;
    int HLT_IsoTkMu24_eta2p1;
    int HLT_IsoTkMu27;
    int HLT_JetE30_NoBPTX3BX_NoHalo;
    int HLT_JetE30_NoBPTX;
    int HLT_JetE50_NoBPTX3BX_NoHalo;
    int HLT_JetE70_NoBPTX3BX_NoHalo;
    int HLT_L1_TripleJet_VBF;
    int HLT_L2DoubleMu23_NoVertex;
    int HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10;
    int HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10;
    int HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo;
    int HLT_L2Mu10_NoVertex_NoBPTX;
    int HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo;
    int HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo;
    int HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120;
    int HLT_LooseIsoPFTau50_Trk30_eta2p1;
    int HLT_MET75_IsoTrk50;
    int HLT_MET90_IsoTrk50;
    int HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned;
    int HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned;
    int HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned;
    int HLT_Mu10_CentralPFJet40_BTagCSV;
    int HLT_Mu12_Photon25_CaloIdL_L1ISO;
    int HLT_Mu12_Photon25_CaloIdL_L1OR;
    int HLT_Mu12_Photon25_CaloIdL;
    int HLT_Mu14er_PFMET120_NoiseCleaned;
    int HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400;
    int HLT_Mu15_IsoVVVL_PFHT400_PFMET70;
    int HLT_Mu15_IsoVVVL_PFHT600;
    int HLT_Mu15_PFHT300;
    int HLT_Mu16_eta2p1_CaloMET30;
    int HLT_Mu17_Mu8_DZ;
    int HLT_Mu17_Mu8_SameSign_DPhi;
    int HLT_Mu17_Mu8_SameSign;
    int HLT_Mu17_Photon30_CaloIdL_L1ISO;
    int HLT_Mu17_Photon35_CaloIdL_L1ISO;
    int HLT_Mu17_TkMu8_DZ;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
    int HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
    int HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
    int HLT_Mu17_TrkIsoVVL;
    int HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
    int HLT_Mu24_TrkIsoVVL;
    int HLT_Mu24_eta2p1;
    int HLT_Mu25_TkMu0_dEta18_Onia;
    int HLT_Mu27;
    int HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL;
    int HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL;
    int HLT_Mu30_TkMu11;
    int HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL;
    int HLT_Mu34_TrkIsoVVL;
    int HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL;
    int HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned;
    int HLT_Mu40_eta2p1_PFJet200_PFJet50;
    int HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL;
    int HLT_Mu45_eta2p1;
    int HLT_Mu50;
    int HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07;
    int HLT_Mu6_PFHT200_PFMET125_NoiseCleaned;
    int HLT_Mu7p5_L2Mu2_Jpsi;
    int HLT_Mu7p5_L2Mu2_Upsilon;
    int HLT_Mu7p5_Track2_Jpsi;
    int HLT_Mu7p5_Track2_Upsilon;
    int HLT_Mu7p5_Track3p5_Jpsi;
    int HLT_Mu7p5_Track3p5_Upsilon;
    int HLT_Mu7p5_Track7_Jpsi;
    int HLT_Mu7p5_Track7_Upsilon;
    int HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
    int HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300;
    int HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
    int HLT_Mu8_TrkIsoVVL;
    int HLT_PFHT125;
    int HLT_PFHT200;
    int HLT_PFHT250;
    int HLT_PFHT300;
    int HLT_PFHT350_PFMET120_NoiseCleaned;
    int HLT_PFHT350;
    int HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72;
    int HLT_PFHT400_SixJet30_DoubleBTagCSV_p056;
    int HLT_PFHT400_SixJet30;
    int HLT_PFHT400;
    int HLT_PFHT450_SixJet40_BTagCSV_p056;
    int HLT_PFHT450_SixJet40_PFBTagCSV0p72;
    int HLT_PFHT450_SixJet40;
    int HLT_PFHT475;
    int HLT_PFHT550_4JetPt50;
    int HLT_PFHT550_4Jet;
    int HLT_PFHT600;
    int HLT_PFHT650_4JetPt50;
    int HLT_PFHT650_4Jet;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5;
    int HLT_PFHT650;
    int HLT_PFHT750_4JetPt50;
    int HLT_PFHT750_4Jet;
    int HLT_PFHT800;
    int HLT_PFHT900;
    int HLT_PFJet140;
    int HLT_PFJet200;
    int HLT_PFJet260;
    int HLT_PFJet320;
    int HLT_PFJet400;
    int HLT_PFJet40;
    int HLT_PFJet450;
    int HLT_PFJet500;
    int HLT_PFJet60;
    int HLT_PFJet80;
    int HLT_PFMET120_NoiseCleaned_BTagCSV07;
    int HLT_PFMET120_NoiseCleaned_Mu5;
    int HLT_PFMET120_PFMHT120_IDLoose;
    int HLT_PFMET170_NoiseCleaned;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon120_R9Id90_HE10_Iso40;
    int HLT_Photon120_R9Id90_HE10_IsoM;
    int HLT_Photon120;
    int HLT_Photon125;
    int HLT_Photon135_PFMET100_NoiseCleaned;
    int HLT_Photon135_PFMET100;
    int HLT_Photon135_PFMET40;
    int HLT_Photon135_VBF;
    int HLT_Photon150;
    int HLT_Photon155_R9Id90_HE10_Iso40;
    int HLT_Photon165_HE10;
    int HLT_Photon165_R9Id90_HE10_IsoM;
    int HLT_Photon175;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon22_R9Id90_HE10_Iso40;
    int HLT_Photon22_R9Id90_HE10_IsoM;
    int HLT_Photon22;
    int HLT_Photon250_NoHE;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60;
    int HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5;
    int HLT_Photon300_NoHE;
    int HLT_Photon30_R9Id90_HE10_Iso40;
    int HLT_Photon30_R9Id90_HE10_IsoM;
    int HLT_Photon30;
    int HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30;
    int HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon36_R9Id90_HE10_Iso40;
    int HLT_Photon36_R9Id90_HE10_IsoM;
    int HLT_Photon36;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15;
    int HLT_Photon500;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon50_R9Id90_HE10_Iso40;
    int HLT_Photon50_R9Id90_HE10_IsoM;
    int HLT_Photon50;
    int HLT_Photon600;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon75_R9Id90_HE10_Iso40;
    int HLT_Photon75_R9Id90_HE10_IsoM;
    int HLT_Photon75;
    int HLT_Photon90_CaloIdL_HT300;
    int HLT_Photon90_CaloIdL_PFHT500;
    int HLT_Photon90_CaloIdL_PFHT600;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF;
    int HLT_Photon90_R9Id90_HE10_Iso40;
    int HLT_Photon90_R9Id90_HE10_IsoM;
    int HLT_Photon90;
    int HLT_Physics;
    int HLT_PixelTracks_Multiplicity110;
    int HLT_PixelTracks_Multiplicity135;
    int HLT_PixelTracks_Multiplicity160;
    int HLT_PixelTracks_Multiplicity60;
    int HLT_PixelTracks_Multiplicity85;
    int HLT_QuadJet45_DoubleCSV0p5;
    int HLT_QuadJet45_TripleCSV0p5;
    int HLT_QuadMuon0_Dimuon0_Jpsi;
    int HLT_QuadMuon0_Dimuon0_Upsilon;
    int HLT_QuadPFJet_BTagCSV_VBF;
    int HLT_QuadPFJet_VBF;
    int HLT_Rsq0p36;
    int HLT_RsqMR260_Rsq0p09_MR200_4jet;
    int HLT_RsqMR260_Rsq0p09_MR200;
    int HLT_RsqMR300_Rsq0p09_MR200_4jet;
    int HLT_RsqMR300_Rsq0p09_MR200;
    int HLT_SingleCentralPFJet170_CFMax0p1;
    int HLT_TkMu24_eta2p1;
    int HLT_TkMu27;
    int HLT_TripleMu_12_10_5;
    int HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5;
    int HLT_VBF_DisplacedJet40_DisplacedTrack;
    int HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack;
    int HLT_VBF_DisplacedJet40_Hadronic;
    int HLT_VBF_DisplacedJet40_TightID_DisplacedTrack;
    int HLT_VBF_DisplacedJet40_TightID_Hadronic;
    int HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack;
    int HLT_VBF_DisplacedJet40_VTightID_Hadronic;
    int HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack;
    int HLT_VBF_DisplacedJet40_VVTightID_Hadronic;
    int HLT_ZeroBias;




  };

  std::string l1BranchDefString("L1_SingleEG40/I:L1_SingleTau100er:L1_SingleJet170");

  std::string triggerBranchDefString("HLT_AK4PFDJet60_Eta2p1ForPPRef/I:HLT_AK4PFDJet80_Eta2p1ForPPRef:HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45:HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20:HLT_AK8DiPFJet250_200_TrimMass30:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45:HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20:HLT_AK8DiPFJet280_200_TrimMass30:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20:HLT_AK8PFHT650_TrimR0p1PT0p03Mass50:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50:HLT_AK8PFJet140:HLT_AK8PFJet200:HLT_AK8PFJet260:HLT_AK8PFJet320:HLT_AK8PFJet360TrimMod_Mass30:HLT_AK8PFJet360_TrimMass30:HLT_AK8PFJet400:HLT_AK8PFJet40:HLT_AK8PFJet450:HLT_AK8PFJet500:HLT_AK8PFJet60:HLT_AK8PFJet80:HLT_BTagMu_DiJet110_Mu5:HLT_BTagMu_DiJet20_Mu5:HLT_BTagMu_DiJet40_Mu5:HLT_BTagMu_DiJet70_Mu5:HLT_BTagMu_Jet300_Mu5:HLT_CaloJet500_NoJetID:HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7:HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose:HLT_DiCaloJetAve140:HLT_DiCaloJetAve200:HLT_DiCaloJetAve260:HLT_DiCaloJetAve320:HLT_DiCaloJetAve400:HLT_DiCaloJetAve40:HLT_DiCaloJetAve500:HLT_DiCaloJetAve60:HLT_DiCaloJetAve80:HLT_DiCentralPFJet170_CFMax0p1:HLT_DiCentralPFJet170:HLT_DiCentralPFJet220_CFMax0p3:HLT_DiCentralPFJet330_CFMax0p5:HLT_DiCentralPFJet430:HLT_DiCentralPFJet70_PFMET120_NoiseCleaned:HLT_DiMu9_Ele9_CaloIdL_TrackIdL:HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140:HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80:HLT_DiPFJetAve100_HFJEC:HLT_DiPFJetAve140:HLT_DiPFJetAve160_HFJEC:HLT_DiPFJetAve200:HLT_DiPFJetAve220_HFJEC:HLT_DiPFJetAve260:HLT_DiPFJetAve300_HFJEC:HLT_DiPFJetAve30_HFJEC:HLT_DiPFJetAve320:HLT_DiPFJetAve400:HLT_DiPFJetAve40:HLT_DiPFJetAve500:HLT_DiPFJetAve60_HFJEC:HLT_DiPFJetAve60:HLT_DiPFJetAve80_HFJEC:HLT_DiPFJetAve80:HLT_Dimuon0_Jpsi_Muon:HLT_Dimuon0_Upsilon_Muon:HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing:HLT_Dimuon0er16_Jpsi_NoVertexing:HLT_Dimuon13_PsiPrime:HLT_Dimuon13_Upsilon:HLT_Dimuon20_Jpsi:HLT_Dimuon6_Jpsi_NoVertexing:HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55:HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95:HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55:HLT_DoubleEle24_22_eta2p1_WP85_Gsf:HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf:HLT_DoubleEle25_CaloIdL_GsfTrkIdVL:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL:HLT_DoubleEle33_CaloIdL_MW:HLT_DoubleEle33_CaloIdL:HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL:HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300:HLT_DoubleIsoMu17_eta2p1:HLT_DoubleJet90_Double30_DoubleCSV0p5:HLT_DoubleJet90_Double30_TripleCSV0p5:HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg:HLT_DoubleMu23NoFiltersNoVtxDisplaced:HLT_DoubleMu28NoFiltersNoVtxDisplaced:HLT_DoubleMu33NoFiltersNoVtx:HLT_DoubleMu38NoFiltersNoVtx:HLT_DoubleMu4_3_Bs:HLT_DoubleMu4_3_Jpsi_Displaced:HLT_DoubleMu4_JpsiTrk_Displaced:HLT_DoubleMu4_LowMassNonResonantTrk_Displaced:HLT_DoubleMu4_PsiPrimeTrk_Displaced:HLT_DoubleMu8_Mass8_PFHT300:HLT_DoublePhoton40:HLT_DoublePhoton50:HLT_DoublePhoton60:HLT_DoublePhoton85:HLT_ECALHT800:HLT_Ele105_CaloIdVT_GsfTrkIdT:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13:HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele12_CaloIdL_TrackIdL_IsoVL:HLT_Ele12_CaloIdM_TrackIdM_PFJet30:HLT_Ele12_CaloId_TrackId_Iso_PFJet30:HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400:HLT_Ele15_IsoVVVL_PFHT400_PFMET70:HLT_Ele15_IsoVVVL_PFHT600:HLT_Ele15_PFHT300:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL:HLT_Ele17_CaloIdL_GsfTrkIdVL:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele17_CaloIdL_TrackIdL_IsoVL:HLT_Ele17_CaloIdM_TrackIdM_PFJet30:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL:HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele18_CaloIdM_TrackIdM_PFJet30:HLT_Ele18_CaloId_TrackId_Iso_PFJet30:HLT_Ele20WP60_Ele8_Mass55:HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20:HLT_Ele22_eta2p1_WP85_Gsf:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele23_CaloIdL_TrackIdL_IsoVL:HLT_Ele23_CaloIdM_TrackIdM_PFJet30:HLT_Ele23_CaloId_TrackId_Iso_PFJet30:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL:HLT_Ele25WP60_SC4_Mass55:HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW:HLT_Ele27_HighEta_Ele20_Mass55:HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV:HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg:HLT_Ele27_eta2p1_WP85_Gsf_HT200:HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20:HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40:HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35:HLT_Ele27_eta2p1_WP85_Gsf:HLT_Ele30WP60_Ele8_Mass55:HLT_Ele30WP60_SC4_Mass55:HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV:HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg:HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20:HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40:HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35:HLT_Ele32_eta2p1_WP85_Gsf:HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele33_CaloIdM_TrackIdM_PFJet30:HLT_Ele33_CaloId_TrackId_Iso_PFJet30:HLT_Ele35_eta2p1_WP85_Gsf:HLT_Ele40_eta2p1_WP85_Gsf:HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50:HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30:HLT_Ele8_CaloIdM_TrackIdM_PFJet30:HLT_HT2000:HLT_HT200_DiJet90_AlphaT0p57:HLT_HT200:HLT_HT2500:HLT_HT250_DiJet90_AlphaT0p55:HLT_HT250_DisplacedDijet40_DisplacedTrack:HLT_HT250:HLT_HT275:HLT_HT300_DiJet90_AlphaT0p53:HLT_HT300:HLT_HT325:HLT_HT350_DiJet90_AlphaT0p52:HLT_HT350_DisplacedDijet40_DisplacedTrack:HLT_HT350_DisplacedDijet80_DisplacedTrack:HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack:HLT_HT350:HLT_HT400_DiJet90_AlphaT0p51:HLT_HT400_DisplacedDijet40_Inclusive:HLT_HT400:HLT_HT425:HLT_HT500_DisplacedDijet40_Inclusive:HLT_HT550_DisplacedDijet40_Inclusive:HLT_HT575:HLT_HT650_DisplacedDijet80_Inclusive:HLT_HT750_DisplacedDijet80_Inclusive:HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1:HLT_IsoMu16_eta2p1_CaloMET30:HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1:HLT_IsoMu17_eta2p1_LooseIsoPFTau20:HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg:HLT_IsoMu17_eta2p1:HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV:HLT_IsoMu20_eta2p1_TriCentralPFJet40:HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35:HLT_IsoMu20_eta2p1:HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV:HLT_IsoMu24_eta2p1_LooseIsoPFTau20:HLT_IsoMu24_eta2p1_TriCentralPFJet40:HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35:HLT_IsoMu24_eta2p1:HLT_IsoMu27:HLT_IsoTkMu20_eta2p1:HLT_IsoTkMu24_eta2p1:HLT_IsoTkMu27:HLT_JetE30_NoBPTX3BX_NoHalo:HLT_JetE30_NoBPTX:HLT_JetE50_NoBPTX3BX_NoHalo:HLT_JetE70_NoBPTX3BX_NoHalo:HLT_L1_TripleJet_VBF:HLT_L2DoubleMu23_NoVertex:HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10:HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10:HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo:HLT_L2Mu10_NoVertex_NoBPTX:HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo:HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo:HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120:HLT_LooseIsoPFTau50_Trk30_eta2p1:HLT_MET75_IsoTrk50:HLT_MET90_IsoTrk50:HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned:HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned:HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned:HLT_Mu10_CentralPFJet40_BTagCSV:HLT_Mu12_Photon25_CaloIdL_L1ISO:HLT_Mu12_Photon25_CaloIdL_L1OR:HLT_Mu12_Photon25_CaloIdL:HLT_Mu14er_PFMET120_NoiseCleaned:HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400:HLT_Mu15_IsoVVVL_PFHT400_PFMET70:HLT_Mu15_IsoVVVL_PFHT600:HLT_Mu15_PFHT300:HLT_Mu16_eta2p1_CaloMET30:HLT_Mu17_Mu8_DZ:HLT_Mu17_Mu8_SameSign_DPhi:HLT_Mu17_Mu8_SameSign:HLT_Mu17_Photon30_CaloIdL_L1ISO:HLT_Mu17_Photon35_CaloIdL_L1ISO:HLT_Mu17_TkMu8_DZ:HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ:HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL:HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ:HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL:HLT_Mu17_TrkIsoVVL:HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL:HLT_Mu24_TrkIsoVVL:HLT_Mu24_eta2p1:HLT_Mu25_TkMu0_dEta18_Onia:HLT_Mu27:HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL:HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL:HLT_Mu30_TkMu11:HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL:HLT_Mu34_TrkIsoVVL:HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL:HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned:HLT_Mu40_eta2p1_PFJet200_PFJet50:HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL:HLT_Mu45_eta2p1:HLT_Mu50:HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07:HLT_Mu6_PFHT200_PFMET125_NoiseCleaned:HLT_Mu7p5_L2Mu2_Jpsi:HLT_Mu7p5_L2Mu2_Upsilon:HLT_Mu7p5_Track2_Jpsi:HLT_Mu7p5_Track2_Upsilon:HLT_Mu7p5_Track3p5_Jpsi:HLT_Mu7p5_Track3p5_Upsilon:HLT_Mu7p5_Track7_Jpsi:HLT_Mu7p5_Track7_Upsilon:HLT_Mu8_DiEle12_CaloIdL_TrackIdL:HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300:HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL:HLT_Mu8_TrkIsoVVL:HLT_PFHT125:HLT_PFHT200:HLT_PFHT250:HLT_PFHT300:HLT_PFHT350_PFMET120_NoiseCleaned:HLT_PFHT350:HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72:HLT_PFHT400_SixJet30_DoubleBTagCSV_p056:HLT_PFHT400_SixJet30:HLT_PFHT400:HLT_PFHT450_SixJet40_BTagCSV_p056:HLT_PFHT450_SixJet40_PFBTagCSV0p72:HLT_PFHT450_SixJet40:HLT_PFHT475:HLT_PFHT550_4JetPt50:HLT_PFHT550_4Jet:HLT_PFHT600:HLT_PFHT650_4JetPt50:HLT_PFHT650_4Jet:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5:HLT_PFHT650:HLT_PFHT750_4JetPt50:HLT_PFHT750_4Jet:HLT_PFHT800:HLT_PFHT900:HLT_PFJet140:HLT_PFJet200:HLT_PFJet260:HLT_PFJet320:HLT_PFJet400:HLT_PFJet40:HLT_PFJet450:HLT_PFJet500:HLT_PFJet60:HLT_PFJet80:HLT_PFMET120_NoiseCleaned_BTagCSV07:HLT_PFMET120_NoiseCleaned_Mu5:HLT_PFMET120_PFMHT120_IDLoose:HLT_PFMET170_NoiseCleaned:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon120_R9Id90_HE10_Iso40:HLT_Photon120_R9Id90_HE10_IsoM:HLT_Photon120:HLT_Photon125:HLT_Photon135_PFMET100_NoiseCleaned:HLT_Photon135_PFMET100:HLT_Photon135_PFMET40:HLT_Photon135_VBF:HLT_Photon150:HLT_Photon155_R9Id90_HE10_Iso40:HLT_Photon165_HE10:HLT_Photon165_R9Id90_HE10_IsoM:HLT_Photon175:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon22_R9Id90_HE10_Iso40:HLT_Photon22_R9Id90_HE10_IsoM:HLT_Photon22:HLT_Photon250_NoHE:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60:HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5:HLT_Photon300_NoHE:HLT_Photon30_R9Id90_HE10_Iso40:HLT_Photon30_R9Id90_HE10_IsoM:HLT_Photon30:HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30:HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon36_R9Id90_HE10_Iso40:HLT_Photon36_R9Id90_HE10_IsoM:HLT_Photon36:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15:HLT_Photon500:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon50_R9Id90_HE10_Iso40:HLT_Photon50_R9Id90_HE10_IsoM:HLT_Photon50:HLT_Photon600:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon75_R9Id90_HE10_Iso40:HLT_Photon75_R9Id90_HE10_IsoM:HLT_Photon75:HLT_Photon90_CaloIdL_HT300:HLT_Photon90_CaloIdL_PFHT500:HLT_Photon90_CaloIdL_PFHT600:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF:HLT_Photon90_R9Id90_HE10_Iso40:HLT_Photon90_R9Id90_HE10_IsoM:HLT_Photon90:HLT_Physics:HLT_PixelTracks_Multiplicity110:HLT_PixelTracks_Multiplicity135:HLT_PixelTracks_Multiplicity160:HLT_PixelTracks_Multiplicity60:HLT_PixelTracks_Multiplicity85:HLT_QuadJet45_DoubleCSV0p5:HLT_QuadJet45_TripleCSV0p5:HLT_QuadMuon0_Dimuon0_Jpsi:HLT_QuadMuon0_Dimuon0_Upsilon:HLT_QuadPFJet_BTagCSV_VBF:HLT_QuadPFJet_VBF:HLT_Rsq0p36:HLT_RsqMR260_Rsq0p09_MR200_4jet:HLT_RsqMR260_Rsq0p09_MR200:HLT_RsqMR300_Rsq0p09_MR200_4jet:HLT_RsqMR300_Rsq0p09_MR200:HLT_SingleCentralPFJet170_CFMax0p1:HLT_TkMu24_eta2p1:HLT_TkMu27:HLT_TripleMu_12_10_5:HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5:HLT_VBF_DisplacedJet40_DisplacedTrack:HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack:HLT_VBF_DisplacedJet40_Hadronic:HLT_VBF_DisplacedJet40_TightID_DisplacedTrack:HLT_VBF_DisplacedJet40_TightID_Hadronic:HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack:HLT_VBF_DisplacedJet40_VTightID_Hadronic:HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack:HLT_VBF_DisplacedJet40_VVTightID_Hadronic:HLT_ZeroBias");
  
  void InitL1Info(l1Info_t &l1Info){
    l1Info.L1_SingleEG40 = -1;
    l1Info.L1_SingleTau100er = -1;
    l1Info.L1_SingleJet170 = -1;
  }

  void InitTriggerInfo(triggerInfo_t &triggerInfo) {
    triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef = -1;
    triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20 = -1;
    triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20 = -1;
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20 = -1;
    triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = -1;
    triggerInfo.HLT_AK8PFJet140 = -1;
    triggerInfo.HLT_AK8PFJet200 = -1;
    triggerInfo.HLT_AK8PFJet260 = -1;
    triggerInfo.HLT_AK8PFJet320 = -1;
    triggerInfo.HLT_AK8PFJet360TrimMod_Mass30 = -1;
    triggerInfo.HLT_AK8PFJet360_TrimMass30 = -1;
    triggerInfo.HLT_AK8PFJet400 = -1;
    triggerInfo.HLT_AK8PFJet40 = -1;
    triggerInfo.HLT_AK8PFJet450 = -1;
    triggerInfo.HLT_AK8PFJet500 = -1;
    triggerInfo.HLT_AK8PFJet60 = -1;
    triggerInfo.HLT_AK8PFJet80 = -1;
    triggerInfo.HLT_BTagMu_DiJet110_Mu5 = -1;
    triggerInfo.HLT_BTagMu_DiJet20_Mu5 = -1;
    triggerInfo.HLT_BTagMu_DiJet40_Mu5 = -1;
    triggerInfo.HLT_BTagMu_DiJet70_Mu5 = -1;
    triggerInfo.HLT_BTagMu_Jet300_Mu5 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID = -1;
    triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7 = -1;
    triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose = -1;
    triggerInfo.HLT_DiCaloJetAve140 = -1;
    triggerInfo.HLT_DiCaloJetAve200 = -1;
    triggerInfo.HLT_DiCaloJetAve260 = -1;
    triggerInfo.HLT_DiCaloJetAve320 = -1;
    triggerInfo.HLT_DiCaloJetAve400 = -1;
    triggerInfo.HLT_DiCaloJetAve40 = -1;
    triggerInfo.HLT_DiCaloJetAve500 = -1;
    triggerInfo.HLT_DiCaloJetAve60 = -1;
    triggerInfo.HLT_DiCaloJetAve80 = -1;
    triggerInfo.HLT_DiCentralPFJet170_CFMax0p1 = -1;
    triggerInfo.HLT_DiCentralPFJet170 = -1;
    triggerInfo.HLT_DiCentralPFJet220_CFMax0p3 = -1;
    triggerInfo.HLT_DiCentralPFJet330_CFMax0p5 = -1;
    triggerInfo.HLT_DiCentralPFJet430 = -1;
    triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned = -1;
    triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL = -1;
    triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140 = -1;
    triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve140 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve200 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve260 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve320 = -1;
    triggerInfo.HLT_DiPFJetAve400 = -1;
    triggerInfo.HLT_DiPFJetAve40 = -1;
    triggerInfo.HLT_DiPFJetAve500 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve60 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC = -1;
    triggerInfo.HLT_DiPFJetAve80 = -1;
    triggerInfo.HLT_Dimuon0_Jpsi_Muon = -1;
    triggerInfo.HLT_Dimuon0_Upsilon_Muon = -1;
    triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing = -1;
    triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing = -1;
    triggerInfo.HLT_Dimuon13_PsiPrime = -1;
    triggerInfo.HLT_Dimuon13_Upsilon = -1;
    triggerInfo.HLT_Dimuon20_Jpsi = -1;
    triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing = -1;
    triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = -1;
    triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = -1;
    triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = -1;
    triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_MW = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL = -1;
    triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = -1;
    triggerInfo.HLT_DoubleIsoMu17_eta2p1 = -1;
    triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5 = -1;
    triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5 = -1;
    triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = -1;
    triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced = -1;
    triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced = -1;
    triggerInfo.HLT_DoubleMu33NoFiltersNoVtx = -1;
    triggerInfo.HLT_DoubleMu38NoFiltersNoVtx = -1;
    triggerInfo.HLT_DoubleMu4_3_Bs = -1;
    triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced = -1;
    triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced = -1;
    triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced = -1;
    triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced = -1;
    triggerInfo.HLT_DoubleMu8_Mass8_PFHT300 = -1;
    triggerInfo.HLT_DoublePhoton40 = -1;
    triggerInfo.HLT_DoublePhoton50 = -1;
    triggerInfo.HLT_DoublePhoton60 = -1;
    triggerInfo.HLT_DoublePhoton85 = -1;
    triggerInfo.HLT_ECALHT800 = -1;
    triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13 = -1;
    triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70 = -1;
    triggerInfo.HLT_Ele15_IsoVVVL_PFHT600 = -1;
    triggerInfo.HLT_Ele15_PFHT300 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = -1;
    triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30 = -1;
    triggerInfo.HLT_Ele20WP60_Ele8_Mass55 = -1;
    triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20 = -1;
    triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Ele25WP60_SC4_Mass55 = -1;
    triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW = -1;
    triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = -1;
    triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_Ele30WP60_Ele8_Mass55 = -1;
    triggerInfo.HLT_Ele30WP60_SC4_Mass55 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = -1;
    triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30 = -1;
    triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf = -1;
    triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50 = -1;
    triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -1;
    triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -1;
    triggerInfo.HLT_HT2000 = -1;
    triggerInfo.HLT_HT200_DiJet90_AlphaT0p57 = -1;
    triggerInfo.HLT_HT200 = -1;
    triggerInfo.HLT_HT2500 = -1;
    triggerInfo.HLT_HT250_DiJet90_AlphaT0p55 = -1;
    triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack = -1;
    triggerInfo.HLT_HT250 = -1;
    triggerInfo.HLT_HT275 = -1;
    triggerInfo.HLT_HT300_DiJet90_AlphaT0p53 = -1;
    triggerInfo.HLT_HT300 = -1;
    triggerInfo.HLT_HT325 = -1;
    triggerInfo.HLT_HT350_DiJet90_AlphaT0p52 = -1;
    triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack = -1;
    triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack = -1;
    triggerInfo.HLT_HT350 = -1;
    triggerInfo.HLT_HT400_DiJet90_AlphaT0p51 = -1;
    triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive = -1;
    triggerInfo.HLT_HT400 = -1;
    triggerInfo.HLT_HT425 = -1;
    triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive = -1;
    triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive = -1;
    triggerInfo.HLT_HT575 = -1;
    triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive = -1;
    triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1 = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg = -1;
    triggerInfo.HLT_IsoMu17_eta2p1 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1 = -1;
    triggerInfo.HLT_IsoMu27 = -1;
    triggerInfo.HLT_IsoTkMu20_eta2p1 = -1;
    triggerInfo.HLT_IsoTkMu24_eta2p1 = -1;
    triggerInfo.HLT_IsoTkMu27 = -1;
    triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_JetE30_NoBPTX = -1;
    triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_L1_TripleJet_VBF = -1;
    triggerInfo.HLT_L2DoubleMu23_NoVertex = -1;
    triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = -1;
    triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10 = -1;
    triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX = -1;
    triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo = -1;
    triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120 = -1;
    triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1 = -1;
    triggerInfo.HLT_MET75_IsoTrk50 = -1;
    triggerInfo.HLT_MET90_IsoTrk50 = -1;
    triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned = -1;
    triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned = -1;
    triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned = -1;
    triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR = -1;
    triggerInfo.HLT_Mu12_Photon25_CaloIdL = -1;
    triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT600 = -1;
    triggerInfo.HLT_Mu15_PFHT300 = -1;
    triggerInfo.HLT_Mu16_eta2p1_CaloMET30 = -1;
    triggerInfo.HLT_Mu17_Mu8_DZ = -1;
    triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi = -1;
    triggerInfo.HLT_Mu17_Mu8_SameSign = -1;
    triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO = -1;
    triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO = -1;
    triggerInfo.HLT_Mu17_TkMu8_DZ = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = -1;
    triggerInfo.HLT_Mu17_TrkIsoVVL = -1;
    triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Mu24_TrkIsoVVL = -1;
    triggerInfo.HLT_Mu24_eta2p1 = -1;
    triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia = -1;
    triggerInfo.HLT_Mu27 = -1;
    triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = -1;
    triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL = -1;
    triggerInfo.HLT_Mu30_TkMu11 = -1;
    triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL = -1;
    triggerInfo.HLT_Mu34_TrkIsoVVL = -1;
    triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL = -1;
    triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned = -1;
    triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50 = -1;
    triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL = -1;
    triggerInfo.HLT_Mu45_eta2p1 = -1;
    triggerInfo.HLT_Mu50 = -1;
    triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07 = -1;
    triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned = -1;
    triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi = -1;
    triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon = -1;
    triggerInfo.HLT_Mu7p5_Track2_Jpsi = -1;
    triggerInfo.HLT_Mu7p5_Track2_Upsilon = -1;
    triggerInfo.HLT_Mu7p5_Track3p5_Jpsi = -1;
    triggerInfo.HLT_Mu7p5_Track3p5_Upsilon = -1;
    triggerInfo.HLT_Mu7p5_Track7_Jpsi = -1;
    triggerInfo.HLT_Mu7p5_Track7_Upsilon = -1;
    triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL = -1;
    triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300 = -1;
    triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = -1;
    triggerInfo.HLT_Mu8_TrkIsoVVL = -1;
    triggerInfo.HLT_PFHT125 = -1;
    triggerInfo.HLT_PFHT200 = -1;
    triggerInfo.HLT_PFHT250 = -1;
    triggerInfo.HLT_PFHT300 = -1;
    triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned = -1;
    triggerInfo.HLT_PFHT350 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = -1;
    triggerInfo.HLT_PFHT400_SixJet30 = -1;
    triggerInfo.HLT_PFHT400 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72 = -1;
    triggerInfo.HLT_PFHT450_SixJet40 = -1;
    triggerInfo.HLT_PFHT475 = -1;
    triggerInfo.HLT_PFHT550_4JetPt50 = -1;
    triggerInfo.HLT_PFHT550_4Jet = -1;
    triggerInfo.HLT_PFHT600 = -1;
    triggerInfo.HLT_PFHT650_4JetPt50 = -1;
    triggerInfo.HLT_PFHT650_4Jet = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = -1;
    triggerInfo.HLT_PFHT650 = -1;
    triggerInfo.HLT_PFHT750_4JetPt50 = -1;
    triggerInfo.HLT_PFHT750_4Jet = -1;
    triggerInfo.HLT_PFHT800 = -1;
    triggerInfo.HLT_PFHT900 = -1;
    triggerInfo.HLT_PFJet140 = -1;
    triggerInfo.HLT_PFJet200 = -1;
    triggerInfo.HLT_PFJet260 = -1;
    triggerInfo.HLT_PFJet320 = -1;
    triggerInfo.HLT_PFJet400 = -1;
    triggerInfo.HLT_PFJet40 = -1;
    triggerInfo.HLT_PFJet450 = -1;
    triggerInfo.HLT_PFJet500 = -1;
    triggerInfo.HLT_PFJet60 = -1;
    triggerInfo.HLT_PFJet80 = -1;
    triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07 = -1;
    triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5 = -1;
    triggerInfo.HLT_PFMET120_PFMHT120_IDLoose = -1;
    triggerInfo.HLT_PFMET170_NoiseCleaned = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon120 = -1;
    triggerInfo.HLT_Photon125 = -1;
    triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned = -1;
    triggerInfo.HLT_Photon135_PFMET100 = -1;
    triggerInfo.HLT_Photon135_PFMET40 = -1;
    triggerInfo.HLT_Photon135_VBF = -1;
    triggerInfo.HLT_Photon150 = -1;
    triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon165_HE10 = -1;
    triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon175 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon22 = -1;
    triggerInfo.HLT_Photon250_NoHE = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60 = -1;
    triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5 = -1;
    triggerInfo.HLT_Photon300_NoHE = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon30 = -1;
    triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30 = -1;
    triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon36 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15 = -1;
    triggerInfo.HLT_Photon500 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon50 = -1;
    triggerInfo.HLT_Photon600 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon75 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_HT300 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT600 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM = -1;
    triggerInfo.HLT_Photon90 = -1;
    triggerInfo.HLT_Physics = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity110 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity135 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity160 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity60 = -1;
    triggerInfo.HLT_PixelTracks_Multiplicity85 = -1;
    triggerInfo.HLT_QuadJet45_DoubleCSV0p5 = -1;
    triggerInfo.HLT_QuadJet45_TripleCSV0p5 = -1;
    triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi = -1;
    triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon = -1;
    triggerInfo.HLT_QuadPFJet_BTagCSV_VBF = -1;
    triggerInfo.HLT_QuadPFJet_VBF = -1;
    triggerInfo.HLT_Rsq0p36 = -1;
    triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet = -1;
    triggerInfo.HLT_RsqMR260_Rsq0p09_MR200 = -1;
    triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet = -1;
    triggerInfo.HLT_RsqMR300_Rsq0p09_MR200 = -1;
    triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1 = -1;
    triggerInfo.HLT_TkMu24_eta2p1 = -1;
    triggerInfo.HLT_TkMu27 = -1;
    triggerInfo.HLT_TripleMu_12_10_5 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5 = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_Hadronic = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack = -1;
    triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic = -1;
    triggerInfo.HLT_ZeroBias = -1;



  }

  void FillL1Info(l1Info_t &l1Info, const l1t::L1TGlobalUtil* l1GtUtils_){
    bool egbit = 0;
    bool taubit = 0;
    bool jetbit = 0;

    l1GtUtils_->getFinalDecisionByName("L1_SingleEG40", egbit);
    l1GtUtils_->getFinalDecisionByName("L1_SingleTau100er", taubit);
    l1GtUtils_->getFinalDecisionByName("L1_SingleJet170", jetbit);

    l1Info.L1_SingleEG40 = egbit;
    l1Info.L1_SingleTau100er = taubit;
    l1Info.L1_SingleJet170 = jetbit;

  }
  
  void FillTriggerBits(triggerInfo_t &triggerInfo, const edm::TriggerResults* triggerResults, const edm::Event& iEvent) {

    using namespace std;
    
    // first clear decisions from previous event
    ExoDiPhotons::InitTriggerInfo(triggerInfo);

    //get trigger names from the event
    std::vector<std::string> trigNames = iEvent.triggerNames(*triggerResults).triggerNames();

    // loop over the trigger names and write trigger bits and prescales
    for (unsigned int i=0; i < trigNames.size(); i++){
        std::string currentTrigger = trigNames.at(i);

      if (currentTrigger.rfind("HLT_AK4PFDJet60_Eta2p1ForPPRef_v") != string::npos)
        triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK4PFDJet80_Eta2p1ForPPRef_v") != string::npos)
        triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v") != string::npos)
        triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v") != string::npos)
        triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet140_v") != string::npos)
        triggerInfo.HLT_AK8PFJet140 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet200_v") != string::npos)
        triggerInfo.HLT_AK8PFJet200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet260_v") != string::npos)
        triggerInfo.HLT_AK8PFJet260 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet320_v") != string::npos)
        triggerInfo.HLT_AK8PFJet320 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet360TrimMod_Mass30_v") != string::npos)
        triggerInfo.HLT_AK8PFJet360TrimMod_Mass30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet360_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8PFJet360_TrimMass30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet400_v") != string::npos)
        triggerInfo.HLT_AK8PFJet400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet40_v") != string::npos)
        triggerInfo.HLT_AK8PFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet450_v") != string::npos)
        triggerInfo.HLT_AK8PFJet450 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet500_v") != string::npos)
        triggerInfo.HLT_AK8PFJet500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet60_v") != string::npos)
        triggerInfo.HLT_AK8PFJet60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet80_v") != string::npos)
        triggerInfo.HLT_AK8PFJet80 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet110_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet110_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet20_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet20_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet40_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet40_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet70_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet70_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_BTagMu_Jet300_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_Jet300_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_CaloJet500_NoJetID_v") != string::npos)
        triggerInfo.HLT_CaloJet500_NoJetID = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v") != string::npos)
        triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v") != string::npos)
        triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve140_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve140 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve200_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve260_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve260 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve320_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve320 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve400_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve40_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve500_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve60_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve80_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve80 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet170_CFMax0p1_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet170_CFMax0p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet170_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet170 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet220_CFMax0p3_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet220_CFMax0p3 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet330_CFMax0p5_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet330_CFMax0p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet430_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet430 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v") != string::npos)
        triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v") != string::npos)
        triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve100_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve100_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve140_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve140 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve160_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve160_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve200_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve220_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve220_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve260_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve260 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve300_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve300_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve30_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve30_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve320_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve320 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve400_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve40_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve500_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve60_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve60_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve60_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve80_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve80_HFJEC = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve80_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve80 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon0_Jpsi_Muon_v") != string::npos)
        triggerInfo.HLT_Dimuon0_Jpsi_Muon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon0_Upsilon_Muon_v") != string::npos)
        triggerInfo.HLT_Dimuon0_Upsilon_Muon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon0er16_Jpsi_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon13_PsiPrime_v") != string::npos)
        triggerInfo.HLT_Dimuon13_PsiPrime = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon13_Upsilon_v") != string::npos)
        triggerInfo.HLT_Dimuon13_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon20_Jpsi_v") != string::npos)
        triggerInfo.HLT_Dimuon20_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Dimuon6_Jpsi_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v") != string::npos)
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_MW_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_MW = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleIsoMu17_eta2p1_v") != string::npos)
        triggerInfo.HLT_DoubleIsoMu17_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleJet90_Double30_DoubleCSV0p5_v") != string::npos)
        triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleJet90_Double30_TripleCSV0p5_v") != string::npos)
        triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu23NoFiltersNoVtxDisplaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu28NoFiltersNoVtxDisplaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu33NoFiltersNoVtx_v") != string::npos)
        triggerInfo.HLT_DoubleMu33NoFiltersNoVtx = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu38NoFiltersNoVtx_v") != string::npos)
        triggerInfo.HLT_DoubleMu38NoFiltersNoVtx = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_3_Bs_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_3_Bs = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_3_Jpsi_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_JpsiTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_PsiPrimeTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoubleMu8_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleMu8_Mass8_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton40_v") != string::npos)
        triggerInfo.HLT_DoublePhoton40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton50_v") != string::npos)
        triggerInfo.HLT_DoublePhoton50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton60_v") != string::npos)
        triggerInfo.HLT_DoublePhoton60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton85_v") != string::npos)
        triggerInfo.HLT_DoublePhoton85 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_ECALHT800_v") != string::npos)
        triggerInfo.HLT_ECALHT800 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele105_CaloIdVT_GsfTrkIdT_v") != string::npos)
        triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_PFHT600 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele15_PFHT300_v") != string::npos)
        triggerInfo.HLT_Ele15_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") != string::npos)
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele20WP60_Ele8_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele20WP60_Ele8_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele22_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele25WP60_SC4_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele25WP60_SC4_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v") != string::npos)
        triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_HighEta_Ele20_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_HT200_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele30WP60_Ele8_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele30WP60_Ele8_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele30WP60_SC4_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele30WP60_SC4_Mass55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele35_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele40_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v") != string::npos)
        triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT2000_v") != string::npos)
        triggerInfo.HLT_HT2000 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT200_DiJet90_AlphaT0p57_v") != string::npos)
        triggerInfo.HLT_HT200_DiJet90_AlphaT0p57 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT200_v") != string::npos)
        triggerInfo.HLT_HT200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT2500_v") != string::npos)
        triggerInfo.HLT_HT2500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT250_DiJet90_AlphaT0p55_v") != string::npos)
        triggerInfo.HLT_HT250_DiJet90_AlphaT0p55 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT250_DisplacedDijet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT250_v") != string::npos)
        triggerInfo.HLT_HT250 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT275_v") != string::npos)
        triggerInfo.HLT_HT275 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT300_DiJet90_AlphaT0p53_v") != string::npos)
        triggerInfo.HLT_HT300_DiJet90_AlphaT0p53 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT300_v") != string::npos)
        triggerInfo.HLT_HT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT325_v") != string::npos)
        triggerInfo.HLT_HT325 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT350_DiJet90_AlphaT0p52_v") != string::npos)
        triggerInfo.HLT_HT350_DiJet90_AlphaT0p52 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet80_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT350_v") != string::npos)
        triggerInfo.HLT_HT350 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT400_DiJet90_AlphaT0p51_v") != string::npos)
        triggerInfo.HLT_HT400_DiJet90_AlphaT0p51 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT400_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT400_v") != string::npos)
        triggerInfo.HLT_HT400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT425_v") != string::npos)
        triggerInfo.HLT_HT425 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT500_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT550_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT575_v") != string::npos)
        triggerInfo.HLT_HT575 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT650_DisplacedDijet80_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_HT750_DisplacedDijet80_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu16_eta2p1_CaloMET30_v") != string::npos)
        triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoMu27_v") != string::npos)
        triggerInfo.HLT_IsoMu27 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu20_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoTkMu20_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoTkMu24_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu27_v") != string::npos)
        triggerInfo.HLT_IsoTkMu27 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_JetE30_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_JetE30_NoBPTX_v") != string::npos)
        triggerInfo.HLT_JetE30_NoBPTX = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_JetE50_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_JetE70_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L1_TripleJet_VBF_v") != string::npos)
        triggerInfo.HLT_L1_TripleJet_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu23_NoVertex_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu23_NoVertex = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2Mu10_NoVertex_NoBPTX_v") != string::npos)
        triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v") != string::npos)
        triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_LooseIsoPFTau50_Trk30_eta2p1_v") != string::npos)
        triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_MET75_IsoTrk50_v") != string::npos)
        triggerInfo.HLT_MET75_IsoTrk50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_MET90_IsoTrk50_v") != string::npos)
        triggerInfo.HLT_MET90_IsoTrk50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu10_CentralPFJet40_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_L1OR_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu14er_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT600 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu15_PFHT300_v") != string::npos)
        triggerInfo.HLT_Mu15_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu16_eta2p1_CaloMET30_v") != string::npos)
        triggerInfo.HLT_Mu16_eta2p1_CaloMET30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_SameSign_DPhi_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_SameSign_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_SameSign = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_Photon30_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_Photon35_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TkMu8_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TkMu8_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu24_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu24_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_Mu24_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu25_TkMu0_dEta18_Onia_v") != string::npos)
        triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu27_v") != string::npos)
        triggerInfo.HLT_Mu27 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu30_TkMu11_v") != string::npos)
        triggerInfo.HLT_Mu30_TkMu11 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu34_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu34_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu40_eta2p1_PFJet200_PFJet50_v") != string::npos)
        triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu45_eta2p1_v") != string::npos)
        triggerInfo.HLT_Mu45_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu50_v") != string::npos)
        triggerInfo.HLT_Mu50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v") != string::npos)
        triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_L2Mu2_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_L2Mu2_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track2_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track2_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track2_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track2_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track3p5_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track3p5_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track3p5_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track3p5_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track7_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track7_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track7_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track7_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Mu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu8_TrkIsoVVL = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT125_v") != string::npos)
        triggerInfo.HLT_PFHT125 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT200_v") != string::npos)
        triggerInfo.HLT_PFHT200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT250_v") != string::npos)
        triggerInfo.HLT_PFHT250 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT300_v") != string::npos)
        triggerInfo.HLT_PFHT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT350_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT350_v") != string::npos)
        triggerInfo.HLT_PFHT350 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT400_v") != string::npos)
        triggerInfo.HLT_PFHT400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_BTagCSV_p056_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_PFBTagCSV0p72_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT475_v") != string::npos)
        triggerInfo.HLT_PFHT475 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT550_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT550_4JetPt50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT550_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT550_4Jet = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT600_v") != string::npos)
        triggerInfo.HLT_PFHT600 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT650_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT650_4JetPt50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT650_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT650_4Jet = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v") != string::npos)
        triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v") != string::npos)
        triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT650_v") != string::npos)
        triggerInfo.HLT_PFHT650 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT750_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT750_4JetPt50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT750_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT750_4Jet = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT800_v") != string::npos)
        triggerInfo.HLT_PFHT800 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFHT900_v") != string::npos)
        triggerInfo.HLT_PFHT900 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet140_v") != string::npos)
        triggerInfo.HLT_PFJet140 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet200_v") != string::npos)
        triggerInfo.HLT_PFJet200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet260_v") != string::npos)
        triggerInfo.HLT_PFJet260 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet320_v") != string::npos)
        triggerInfo.HLT_PFJet320 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet400_v") != string::npos)
        triggerInfo.HLT_PFJet400 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet40_v") != string::npos)
        triggerInfo.HLT_PFJet40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet450_v") != string::npos)
        triggerInfo.HLT_PFJet450 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet500_v") != string::npos)
        triggerInfo.HLT_PFJet500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet60_v") != string::npos)
        triggerInfo.HLT_PFJet60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFJet80_v") != string::npos)
        triggerInfo.HLT_PFJet80 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFMET120_NoiseCleaned_BTagCSV07_v") != string::npos)
        triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFMET120_NoiseCleaned_Mu5_v") != string::npos)
        triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFMET120_PFMHT120_IDLoose_v") != string::npos)
        triggerInfo.HLT_PFMET120_PFMHT120_IDLoose = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PFMET170_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_PFMET170_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon120_v") != string::npos)
        triggerInfo.HLT_Photon120 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon125_v") != string::npos)
        triggerInfo.HLT_Photon125 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET100_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET100_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET100 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon135_VBF_v") != string::npos)
        triggerInfo.HLT_Photon135_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon150_v") != string::npos)
        triggerInfo.HLT_Photon150 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon155_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon165_HE10_v") != string::npos)
        triggerInfo.HLT_Photon165_HE10 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon165_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon175_v") != string::npos)
        triggerInfo.HLT_Photon175 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon22_v") != string::npos)
        triggerInfo.HLT_Photon22 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon250_NoHE_v") != string::npos)
        triggerInfo.HLT_Photon250_NoHE = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v") != string::npos)
        triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v") != string::npos)
        triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon300_NoHE_v") != string::npos)
        triggerInfo.HLT_Photon300_NoHE = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon30_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon30_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon30_v") != string::npos)
        triggerInfo.HLT_Photon30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon36_v") != string::npos)
        triggerInfo.HLT_Photon36 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v") != string::npos)
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v") != string::npos)
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon500_v") != string::npos)
        triggerInfo.HLT_Photon500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon50_v") != string::npos)
        triggerInfo.HLT_Photon50 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon600_v") != string::npos)
        triggerInfo.HLT_Photon600 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon75_v") != string::npos)
        triggerInfo.HLT_Photon75 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_HT300_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_HT300 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_PFHT500_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_PFHT500 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_PFHT600 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Photon90_v") != string::npos)
        triggerInfo.HLT_Photon90 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Physics_v") != string::npos)
        triggerInfo.HLT_Physics = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity110_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity110 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity135_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity135 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity160_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity160 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity60_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity60 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity85_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity85 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadJet45_DoubleCSV0p5_v") != string::npos)
        triggerInfo.HLT_QuadJet45_DoubleCSV0p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadJet45_TripleCSV0p5_v") != string::npos)
        triggerInfo.HLT_QuadJet45_TripleCSV0p5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadMuon0_Dimuon0_Jpsi_v") != string::npos)
        triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadMuon0_Dimuon0_Upsilon_v") != string::npos)
        triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadPFJet_BTagCSV_VBF_v") != string::npos)
        triggerInfo.HLT_QuadPFJet_BTagCSV_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_QuadPFJet_VBF_v") != string::npos)
        triggerInfo.HLT_QuadPFJet_VBF = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_Rsq0p36_v") != string::npos)
        triggerInfo.HLT_Rsq0p36 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_RsqMR260_Rsq0p09_MR200_4jet_v") != string::npos)
        triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_RsqMR260_Rsq0p09_MR200_v") != string::npos)
        triggerInfo.HLT_RsqMR260_Rsq0p09_MR200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_RsqMR300_Rsq0p09_MR200_4jet_v") != string::npos)
        triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_RsqMR300_Rsq0p09_MR200_v") != string::npos)
        triggerInfo.HLT_RsqMR300_Rsq0p09_MR200 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_SingleCentralPFJet170_CFMax0p1_v") != string::npos)
        triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_TkMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_TkMu24_eta2p1 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_TkMu27_v") != string::npos)
        triggerInfo.HLT_TkMu27 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_TripleMu_12_10_5_v") != string::npos)
        triggerInfo.HLT_TripleMu_12_10_5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5 = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_Hadronic = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_TightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VTightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic = triggerResults->accept(i);
      else if (currentTrigger.rfind("HLT_ZeroBias_v") != string::npos)
        triggerInfo.HLT_ZeroBias = triggerResults->accept(i);


    } // end loop over trigger names

  } // end FillTriggerBits function
  void FillTriggerPrescales(triggerInfo_t &triggerInfo, const edm::TriggerResults* triggerResults, const pat::PackedTriggerPrescales* prescales, const edm::Event& iEvent) {

    using namespace std;

    // first clear decisions from previous event
    ExoDiPhotons::InitTriggerInfo(triggerInfo);

    //get trigger names from the event
    std::vector<std::string> trigNames = iEvent.triggerNames(*triggerResults).triggerNames();

    // loop over the trigger names and write trigger bits and prescales
    for (unsigned int i=0; i < trigNames.size(); i++){
      std::string currentTrigger = trigNames.at(i);
      
      if (currentTrigger.rfind("HLT_AK4PFDJet60_Eta2p1ForPPRef_v") != string::npos)
        triggerInfo.HLT_AK4PFDJet60_Eta2p1ForPPRef = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK4PFDJet80_Eta2p1ForPPRef_v") != string::npos)
        triggerInfo.HLT_AK4PFDJet80_Eta2p1ForPPRef = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV0p45 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet250_200_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet250_200_TrimMass30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8DiPFJet280_200_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v") != string::npos)
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v") != string::npos)
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v") != string::npos)
        triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v") != string::npos)
        triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet140_v") != string::npos)
        triggerInfo.HLT_AK8PFJet140 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet200_v") != string::npos)
        triggerInfo.HLT_AK8PFJet200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet260_v") != string::npos)
        triggerInfo.HLT_AK8PFJet260 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet320_v") != string::npos)
        triggerInfo.HLT_AK8PFJet320 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet360TrimMod_Mass30_v") != string::npos)
        triggerInfo.HLT_AK8PFJet360TrimMod_Mass30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet360_TrimMass30_v") != string::npos)
        triggerInfo.HLT_AK8PFJet360_TrimMass30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet400_v") != string::npos)
        triggerInfo.HLT_AK8PFJet400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet40_v") != string::npos)
        triggerInfo.HLT_AK8PFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet450_v") != string::npos)
        triggerInfo.HLT_AK8PFJet450 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet500_v") != string::npos)
        triggerInfo.HLT_AK8PFJet500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet60_v") != string::npos)
        triggerInfo.HLT_AK8PFJet60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_AK8PFJet80_v") != string::npos)
        triggerInfo.HLT_AK8PFJet80 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet110_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet110_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet20_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet20_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet40_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet40_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_BTagMu_DiJet70_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_DiJet70_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_BTagMu_Jet300_Mu5_v") != string::npos)
        triggerInfo.HLT_BTagMu_Jet300_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_CaloJet500_NoJetID_v") != string::npos)
        triggerInfo.HLT_CaloJet500_NoJetID = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v") != string::npos)
        triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v") != string::npos)
        triggerInfo.HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve140_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve140 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve200_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve260_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve260 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve320_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve320 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve400_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve40_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve500_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve60_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCaloJetAve80_v") != string::npos)
        triggerInfo.HLT_DiCaloJetAve80 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet170_CFMax0p1_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet170_CFMax0p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet170_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet170 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet220_CFMax0p3_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet220_CFMax0p3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet330_CFMax0p5_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet330_CFMax0p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet430_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet430 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_DiCentralPFJet70_PFMET120_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_DiMu9_Ele9_CaloIdL_TrackIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v") != string::npos)
        triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v") != string::npos)
        triggerInfo.HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve100_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve100_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve140_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve140 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve160_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve160_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve200_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve220_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve220_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve260_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve260 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve300_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve300_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve30_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve30_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve320_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve320 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve400_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve40_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve500_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve60_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve60_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve60_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve80_HFJEC_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve80_HFJEC = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DiPFJetAve80_v") != string::npos)
        triggerInfo.HLT_DiPFJetAve80 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon0_Jpsi_Muon_v") != string::npos)
        triggerInfo.HLT_Dimuon0_Jpsi_Muon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon0_Upsilon_Muon_v") != string::npos)
        triggerInfo.HLT_Dimuon0_Upsilon_Muon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon0er16_Jpsi_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon0er16_Jpsi_NoVertexing = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon13_PsiPrime_v") != string::npos)
        triggerInfo.HLT_Dimuon13_PsiPrime = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon13_Upsilon_v") != string::npos)
        triggerInfo.HLT_Dimuon13_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon20_Jpsi_v") != string::npos)
        triggerInfo.HLT_Dimuon20_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Dimuon6_Jpsi_NoVertexing_v") != string::npos)
        triggerInfo.HLT_Dimuon6_Jpsi_NoVertexing = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v") != string::npos)
        triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle24_22_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v") != string::npos)
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_MW_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL_MW = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle33_CaloIdL_v") != string::npos)
        triggerInfo.HLT_DoubleEle33_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleIsoMu17_eta2p1_v") != string::npos)
        triggerInfo.HLT_DoubleIsoMu17_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleJet90_Double30_DoubleCSV0p5_v") != string::npos)
        triggerInfo.HLT_DoubleJet90_Double30_DoubleCSV0p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleJet90_Double30_TripleCSV0p5_v") != string::npos)
        triggerInfo.HLT_DoubleJet90_Double30_TripleCSV0p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu23NoFiltersNoVtxDisplaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu23NoFiltersNoVtxDisplaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu28NoFiltersNoVtxDisplaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu28NoFiltersNoVtxDisplaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu33NoFiltersNoVtx_v") != string::npos)
        triggerInfo.HLT_DoubleMu33NoFiltersNoVtx = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu38NoFiltersNoVtx_v") != string::npos)
        triggerInfo.HLT_DoubleMu38NoFiltersNoVtx = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_3_Bs_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_3_Bs = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_3_Jpsi_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_3_Jpsi_Displaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_JpsiTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_JpsiTrk_Displaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_LowMassNonResonantTrk_Displaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu4_PsiPrimeTrk_Displaced_v") != string::npos)
        triggerInfo.HLT_DoubleMu4_PsiPrimeTrk_Displaced = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoubleMu8_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_DoubleMu8_Mass8_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton40_v") != string::npos)
        triggerInfo.HLT_DoublePhoton40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton50_v") != string::npos)
        triggerInfo.HLT_DoublePhoton50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton60_v") != string::npos)
        triggerInfo.HLT_DoublePhoton60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_DoublePhoton85_v") != string::npos)
        triggerInfo.HLT_DoublePhoton85 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_ECALHT800_v") != string::npos)
        triggerInfo.HLT_ECALHT800 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele105_CaloIdVT_GsfTrkIdT_v") != string::npos)
        triggerInfo.HLT_Ele105_CaloIdVT_GsfTrkIdT = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele10_CaloId_TrackIdVL_CentralPFJet40_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele12_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele12_CaloId_TrackId_Iso_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_PFHT400_PFMET70 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele15_IsoVVVL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Ele15_IsoVVVL_PFHT600 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele15_PFHT300_v") != string::npos)
        triggerInfo.HLT_Ele15_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_GsfTrkIdVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") != string::npos)
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele18_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele18_CaloId_TrackId_Iso_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele20WP60_Ele8_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele20WP60_Ele8_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele22_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele22_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele23_CaloId_TrackId_Iso_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele25WP60_SC4_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele25WP60_SC4_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v") != string::npos)
        triggerInfo.HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_HighEta_Ele20_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele27_HighEta_Ele20_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_HT200_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_HT200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_LooseIsoPFTau20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele27_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele27_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele30WP60_Ele8_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele30WP60_Ele8_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele30WP60_SC4_Mass55_v") != string::npos)
        triggerInfo.HLT_Ele30WP60_SC4_Mass55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_CentralPFJet30_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_LooseIsoPFTau20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf_TriCentralPFJet60_50_35 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele32_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele32_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele33_CaloId_TrackId_Iso_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele33_CaloId_TrackId_Iso_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele35_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele35_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele40_eta2p1_WP85_Gsf_v") != string::npos)
        triggerInfo.HLT_Ele40_eta2p1_WP85_Gsf = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v") != string::npos)
        triggerInfo.HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v") != string::npos)
        triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT2000_v") != string::npos)
        triggerInfo.HLT_HT2000 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT200_DiJet90_AlphaT0p57_v") != string::npos)
        triggerInfo.HLT_HT200_DiJet90_AlphaT0p57 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT200_v") != string::npos)
        triggerInfo.HLT_HT200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT2500_v") != string::npos)
        triggerInfo.HLT_HT2500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT250_DiJet90_AlphaT0p55_v") != string::npos)
        triggerInfo.HLT_HT250_DiJet90_AlphaT0p55 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT250_DisplacedDijet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT250_DisplacedDijet40_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT250_v") != string::npos)
        triggerInfo.HLT_HT250 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT275_v") != string::npos)
        triggerInfo.HLT_HT275 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT300_DiJet90_AlphaT0p53_v") != string::npos)
        triggerInfo.HLT_HT300_DiJet90_AlphaT0p53 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT300_v") != string::npos)
        triggerInfo.HLT_HT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT325_v") != string::npos)
        triggerInfo.HLT_HT325 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT350_DiJet90_AlphaT0p52_v") != string::npos)
        triggerInfo.HLT_HT350_DiJet90_AlphaT0p52 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet40_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet80_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet80_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT350_v") != string::npos)
        triggerInfo.HLT_HT350 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT400_DiJet90_AlphaT0p51_v") != string::npos)
        triggerInfo.HLT_HT400_DiJet90_AlphaT0p51 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT400_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT400_DisplacedDijet40_Inclusive = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT400_v") != string::npos)
        triggerInfo.HLT_HT400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT425_v") != string::npos)
        triggerInfo.HLT_HT425 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT500_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT500_DisplacedDijet40_Inclusive = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT550_DisplacedDijet40_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT550_DisplacedDijet40_Inclusive = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT575_v") != string::npos)
        triggerInfo.HLT_HT575 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT650_DisplacedDijet80_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT650_DisplacedDijet80_Inclusive = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_HT750_DisplacedDijet80_Inclusive_v") != string::npos)
        triggerInfo.HLT_HT750_DisplacedDijet80_Inclusive = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu16_eta2p1_CaloMET30_v") != string::npos)
        triggerInfo.HLT_IsoMu16_eta2p1_CaloMET30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu17_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu17_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1_TriCentralPFJet60_50_35 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu20_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu20_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_LooseIsoPFTau20 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_TriCentralPFJet40_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet60_50_35 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoMu24_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoMu27_v") != string::npos)
        triggerInfo.HLT_IsoMu27 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu20_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoTkMu20_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_IsoTkMu24_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_IsoTkMu27_v") != string::npos)
        triggerInfo.HLT_IsoTkMu27 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_JetE30_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE30_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_JetE30_NoBPTX_v") != string::npos)
        triggerInfo.HLT_JetE30_NoBPTX = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_JetE50_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE50_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_JetE70_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_JetE70_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L1_TripleJet_VBF_v") != string::npos)
        triggerInfo.HLT_L1_TripleJet_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu23_NoVertex_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu23_NoVertex = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v") != string::npos)
        triggerInfo.HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2Mu10_NoVertex_NoBPTX_v") != string::npos)
        triggerInfo.HLT_L2Mu10_NoVertex_NoBPTX = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo_v") != string::npos)
        triggerInfo.HLT_L2Mu30_NoVertex_3Sta_NoBPTX3BX_NoHalo = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v") != string::npos)
        triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_LooseIsoPFTau50_Trk30_eta2p1_v") != string::npos)
        triggerInfo.HLT_LooseIsoPFTau50_Trk30_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_MET75_IsoTrk50_v") != string::npos)
        triggerInfo.HLT_MET75_IsoTrk50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_MET90_IsoTrk50_v") != string::npos)
        triggerInfo.HLT_MET90_IsoTrk50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu100_PFMHTNoMu140_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet140_PFMETNoMu140_PFMHTNoMu140_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_MonoCentralPFJet150_PFMETNoMu150_PFMHTNoMu150_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu10_CentralPFJet40_BTagCSV_v") != string::npos)
        triggerInfo.HLT_Mu10_CentralPFJet40_BTagCSV = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1ISO = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_L1OR_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL_L1OR = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu12_Photon25_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu12_Photon25_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu14er_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu14er_PFMET120_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT400_PFMET70 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu15_IsoVVVL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT600 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu15_PFHT300_v") != string::npos)
        triggerInfo.HLT_Mu15_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu16_eta2p1_CaloMET30_v") != string::npos)
        triggerInfo.HLT_Mu16_eta2p1_CaloMET30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_SameSign_DPhi_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_SameSign_DPhi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_Mu8_SameSign_v") != string::npos)
        triggerInfo.HLT_Mu17_Mu8_SameSign = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_Photon30_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu17_Photon30_CaloIdL_L1ISO = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_Photon35_CaloIdL_L1ISO_v") != string::npos)
        triggerInfo.HLT_Mu17_Photon35_CaloIdL_L1ISO = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TkMu8_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TkMu8_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu17_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu17_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu24_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu24_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_Mu24_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu25_TkMu0_dEta18_Onia_v") != string::npos)
        triggerInfo.HLT_Mu25_TkMu0_dEta18_Onia = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu27_v") != string::npos)
        triggerInfo.HLT_Mu27 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v") != string::npos)
        triggerInfo.HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu30_TkMu11_v") != string::npos)
        triggerInfo.HLT_Mu30_TkMu11 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu34_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu34_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu40_eta2p1_PFJet200_PFJet50_v") != string::npos)
        triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v") != string::npos)
        triggerInfo.HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu45_eta2p1_v") != string::npos)
        triggerInfo.HLT_Mu45_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu50_v") != string::npos)
        triggerInfo.HLT_Mu50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v") != string::npos)
        triggerInfo.HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Mu6_PFHT200_PFMET125_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_L2Mu2_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_L2Mu2_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_L2Mu2_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_L2Mu2_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track2_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track2_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track2_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track2_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track3p5_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track3p5_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track3p5_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track3p5_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track7_Jpsi_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track7_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu7p5_Track7_Upsilon_v") != string::npos)
        triggerInfo.HLT_Mu7p5_Track7_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v") != string::npos)
        triggerInfo.HLT_Mu8_DiEle12_CaloIdL_TrackIdL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v") != string::npos)
        triggerInfo.HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v") != string::npos)
        triggerInfo.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Mu8_TrkIsoVVL_v") != string::npos)
        triggerInfo.HLT_Mu8_TrkIsoVVL = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT125_v") != string::npos)
        triggerInfo.HLT_PFHT125 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT200_v") != string::npos)
        triggerInfo.HLT_PFHT200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT250_v") != string::npos)
        triggerInfo.HLT_PFHT250 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT300_v") != string::npos)
        triggerInfo.HLT_PFHT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT350_PFMET120_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_PFHT350_PFMET120_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT350_v") != string::npos)
        triggerInfo.HLT_PFHT350 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT400_SixJet30_v") != string::npos)
        triggerInfo.HLT_PFHT400_SixJet30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT400_v") != string::npos)
        triggerInfo.HLT_PFHT400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_BTagCSV_p056_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40_BTagCSV_p056 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_PFBTagCSV0p72_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT450_SixJet40_v") != string::npos)
        triggerInfo.HLT_PFHT450_SixJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT475_v") != string::npos)
        triggerInfo.HLT_PFHT475 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT550_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT550_4JetPt50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT550_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT550_4Jet = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT600_v") != string::npos)
        triggerInfo.HLT_PFHT600 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT650_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT650_4JetPt50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT650_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT650_4Jet = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v") != string::npos)
        triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v") != string::npos)
        triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT650_v") != string::npos)
        triggerInfo.HLT_PFHT650 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT750_4JetPt50_v") != string::npos)
        triggerInfo.HLT_PFHT750_4JetPt50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT750_4Jet_v") != string::npos)
        triggerInfo.HLT_PFHT750_4Jet = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT800_v") != string::npos)
        triggerInfo.HLT_PFHT800 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFHT900_v") != string::npos)
        triggerInfo.HLT_PFHT900 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet140_v") != string::npos)
        triggerInfo.HLT_PFJet140 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet200_v") != string::npos)
        triggerInfo.HLT_PFJet200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet260_v") != string::npos)
        triggerInfo.HLT_PFJet260 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet320_v") != string::npos)
        triggerInfo.HLT_PFJet320 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet400_v") != string::npos)
        triggerInfo.HLT_PFJet400 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet40_v") != string::npos)
        triggerInfo.HLT_PFJet40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet450_v") != string::npos)
        triggerInfo.HLT_PFJet450 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet500_v") != string::npos)
        triggerInfo.HLT_PFJet500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet60_v") != string::npos)
        triggerInfo.HLT_PFJet60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFJet80_v") != string::npos)
        triggerInfo.HLT_PFJet80 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFMET120_NoiseCleaned_BTagCSV07_v") != string::npos)
        triggerInfo.HLT_PFMET120_NoiseCleaned_BTagCSV07 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFMET120_NoiseCleaned_Mu5_v") != string::npos)
        triggerInfo.HLT_PFMET120_NoiseCleaned_Mu5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFMET120_PFMHT120_IDLoose_v") != string::npos)
        triggerInfo.HLT_PFMET120_PFMHT120_IDLoose = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PFMET170_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_PFMET170_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon120_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon120_v") != string::npos)
        triggerInfo.HLT_Photon120 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon125_v") != string::npos)
        triggerInfo.HLT_Photon125 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET100_NoiseCleaned_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET100_NoiseCleaned = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET100_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET100 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon135_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon135_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon135_VBF_v") != string::npos)
        triggerInfo.HLT_Photon135_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon150_v") != string::npos)
        triggerInfo.HLT_Photon150 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon155_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon155_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon165_HE10_v") != string::npos)
        triggerInfo.HLT_Photon165_HE10 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon165_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon175_v") != string::npos)
        triggerInfo.HLT_Photon175 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon22_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon22_v") != string::npos)
        triggerInfo.HLT_Photon22 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon250_NoHE_v") != string::npos)
        triggerInfo.HLT_Photon250_NoHE = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v") != string::npos)
        triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5_v") != string::npos)
        triggerInfo.HLT_Photon28_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon14_AND_HE10_R9Id65_Mass50_Eta1p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon300_NoHE_v") != string::npos)
        triggerInfo.HLT_Photon300_NoHE = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon30_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon30_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon30_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon30_v") != string::npos)
        triggerInfo.HLT_Photon30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass30 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_AND_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass70 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon18_AND_HE10_R9Id65_Mass95 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon36_v") != string::npos)
        triggerInfo.HLT_Photon36 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_v") != string::npos)
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v") != string::npos)
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon500_v") != string::npos)
        triggerInfo.HLT_Photon500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon50_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon50_v") != string::npos)
        triggerInfo.HLT_Photon50 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon600_v") != string::npos)
        triggerInfo.HLT_Photon600 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon75_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon75_v") != string::npos)
        triggerInfo.HLT_Photon75 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_HT300_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_HT300 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_PFHT500_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_PFHT500 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_CaloIdL_PFHT600_v") != string::npos)
        triggerInfo.HLT_Photon90_CaloIdL_PFHT600 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_Iso40_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_R9Id90_HE10_IsoM_v") != string::npos)
        triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Photon90_v") != string::npos)
        triggerInfo.HLT_Photon90 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Physics_v") != string::npos)
        triggerInfo.HLT_Physics = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity110_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity110 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity135_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity135 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity160_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity160 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity60_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity60 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_PixelTracks_Multiplicity85_v") != string::npos)
        triggerInfo.HLT_PixelTracks_Multiplicity85 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadJet45_DoubleCSV0p5_v") != string::npos)
        triggerInfo.HLT_QuadJet45_DoubleCSV0p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadJet45_TripleCSV0p5_v") != string::npos)
        triggerInfo.HLT_QuadJet45_TripleCSV0p5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadMuon0_Dimuon0_Jpsi_v") != string::npos)
        triggerInfo.HLT_QuadMuon0_Dimuon0_Jpsi = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadMuon0_Dimuon0_Upsilon_v") != string::npos)
        triggerInfo.HLT_QuadMuon0_Dimuon0_Upsilon = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadPFJet_BTagCSV_VBF_v") != string::npos)
        triggerInfo.HLT_QuadPFJet_BTagCSV_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_QuadPFJet_VBF_v") != string::npos)
        triggerInfo.HLT_QuadPFJet_VBF = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_Rsq0p36_v") != string::npos)
        triggerInfo.HLT_Rsq0p36 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_RsqMR260_Rsq0p09_MR200_4jet_v") != string::npos)
        triggerInfo.HLT_RsqMR260_Rsq0p09_MR200_4jet = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_RsqMR260_Rsq0p09_MR200_v") != string::npos)
        triggerInfo.HLT_RsqMR260_Rsq0p09_MR200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_RsqMR300_Rsq0p09_MR200_4jet_v") != string::npos)
        triggerInfo.HLT_RsqMR300_Rsq0p09_MR200_4jet = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_RsqMR300_Rsq0p09_MR200_v") != string::npos)
        triggerInfo.HLT_RsqMR300_Rsq0p09_MR200 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_SingleCentralPFJet170_CFMax0p1_v") != string::npos)
        triggerInfo.HLT_SingleCentralPFJet170_CFMax0p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_TkMu24_eta2p1_v") != string::npos)
        triggerInfo.HLT_TkMu24_eta2p1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_TkMu27_v") != string::npos)
        triggerInfo.HLT_TkMu27 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_TripleMu_12_10_5_v") != string::npos)
        triggerInfo.HLT_TripleMu_12_10_5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_Hadronic = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_TightID_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_TightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_TightID_Hadronic = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VTightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VTightID_Hadronic = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_VBF_DisplacedJet40_VVTightID_Hadronic_v") != string::npos)
        triggerInfo.HLT_VBF_DisplacedJet40_VVTightID_Hadronic = prescales->getPrescaleForIndex(i);
      else if (currentTrigger.rfind("HLT_ZeroBias_v") != string::npos)
        triggerInfo.HLT_ZeroBias = prescales->getPrescaleForIndex(i);



    } // end loop over trigger names
  } // end FillTriggerPrescales function


} // end of namespace

#endif
