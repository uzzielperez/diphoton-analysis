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
    int HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3;
    int HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2;
    int HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2;
    int HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3;
    int HLT_AK8PFJet360_TrimMass30_v3;
    int HLT_CaloJet500_NoJetID_v2;
    int HLT_DiCaloJetAve140_v1;
    int HLT_DiCaloJetAve200_v1;
    int HLT_DiCaloJetAve260_v1;
    int HLT_DiCaloJetAve320_v1;
    int HLT_DiCaloJetAve400_v1;
    int HLT_DiCaloJetAve40_v1;
    int HLT_DiCaloJetAve500_v1;
    int HLT_DiCaloJetAve60_v1;
    int HLT_DiCaloJetAve80_v1;
    int HLT_DiPFJetAve100_HFJEC_v3;
    int HLT_DiPFJetAve140_v2;
    int HLT_DiPFJetAve160_HFJEC_v3;
    int HLT_DiPFJetAve200_v2;
    int HLT_DiPFJetAve220_HFJEC_v3;
    int HLT_DiPFJetAve260_v2;
    int HLT_DiPFJetAve300_HFJEC_v3;
    int HLT_DiPFJetAve30_HFJEC_v3;
    int HLT_DiPFJetAve320_v2;
    int HLT_DiPFJetAve400_v2;
    int HLT_DiPFJetAve40_v2;
    int HLT_DiPFJetAve500_v2;
    int HLT_DiPFJetAve60_HFJEC_v3;
    int HLT_DiPFJetAve60_v2;
    int HLT_DiPFJetAve80_HFJEC_v3;
    int HLT_DiPFJetAve80_v2;
    int HLT_HT2000_v1;
    int HLT_HT200_v1;
    int HLT_HT2500_v1;
    int HLT_HT275_v1;
    int HLT_HT325_v1;
    int HLT_HT425_v1;
    int HLT_HT575_v1;
    int HLT_L1_TripleJet_VBF_v4;
    int HLT_PFHT200_v2;
    int HLT_PFHT250_v2;
    int HLT_PFHT300_v2;
    int HLT_PFHT350_v3;
    int HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3;
    int HLT_PFHT400_SixJet30_v3;
    int HLT_PFHT400_v2;
    int HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3;
    int HLT_PFHT450_SixJet40_v3;
    int HLT_PFHT475_v2;
    int HLT_PFHT550_4JetPt50_v1;
    int HLT_PFHT600_v3;
    int HLT_PFHT650_4JetPt50_v1;
    int HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3;
    int HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3;
    int HLT_PFHT650_v3;
    int HLT_PFHT750_4JetPt50_v3;
    int HLT_PFHT800_v2;
    int HLT_PFJet140_v4;
    int HLT_PFJet200_v4;
    int HLT_PFJet260_v4;
    int HLT_PFJet320_v4;
    int HLT_PFJet400_v4;
    int HLT_PFJet40_v4;
    int HLT_PFJet450_v4;
    int HLT_PFJet500_v4;
    int HLT_PFJet60_v4;
    int HLT_PFJet80_v4;
    int HLT_QuadPFJet_VBF_v4;
    int HLT_DoubleIsoMu17_eta2p1_v3;
    int HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1;
    int HLT_IsoMu16_eta2p1_MET30_v1;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4;
    int HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4;
    int HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3;
    int HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5;
    int HLT_IsoMu17_eta2p1_v3;
    int HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2;
    int HLT_IsoMu18_TriCentralPFJet50_40_30_v2;
    int HLT_IsoMu18_v2;
    int HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3;
    int HLT_IsoMu20_eta2p1_v4;
    int HLT_IsoMu20_v3;
    int HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2;
    int HLT_IsoMu22_TriCentralPFJet50_40_30_v2;
    int HLT_IsoMu22_v2;
    int HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4;
    int HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4;
    int HLT_IsoMu24_eta2p1_v3;
    int HLT_IsoMu27_v3;
    int HLT_IsoTkMu18_v2;
    int HLT_IsoTkMu20_eta2p1_v3;
    int HLT_IsoTkMu20_v4;
    int HLT_IsoTkMu22_v2;
    int HLT_IsoTkMu24_eta2p1_v3;
    int HLT_IsoTkMu27_v3;
    int HLT_L1SingleMu16_v1;
    int HLT_L1SingleMuOpen_v2;
    int HLT_L2Mu10_v1;
    int HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1;
    int HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3;
    int HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2;
    int HLT_Mu15_IsoVVVL_PFHT350_v2;
    int HLT_Mu15_IsoVVVL_PFHT600_v3;
    int HLT_Mu16_eta2p1_MET30_v1;
    int HLT_Mu20_v2;
    int HLT_Mu24_eta2p1_v2;
    int HLT_Mu27_v2;
    int HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2;
    int HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2;
    int HLT_Mu300_v1;
    int HLT_Mu30_eta2p1_PFJet150_PFJet50_v1;
    int HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2;
    int HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2;
    int HLT_Mu350_v1;
    int HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2;
    int HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2;
    int HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2;
    int HLT_Mu40_eta2p1_PFJet200_PFJet50_v3;
    int HLT_Mu45_eta2p1_v2;
    int HLT_Mu50_v2;
    int HLT_Mu55_v1;
    int HLT_OldIsoMu18_v1;
    int HLT_OldIsoTkMu18_v2;
    int HLT_TkMu20_v2;
    int HLT_TkMu24_eta2p1_v2;
    int HLT_TkMu27_v2;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon120_R9Id90_HE10_IsoM_v3;
    int HLT_Photon120_v3;
    int HLT_Photon125_v1;
    int HLT_Photon135_PFMET100_v1;
    int HLT_Photon150_v1;
    int HLT_Photon165_HE10_v3;
    int HLT_Photon165_R9Id90_HE10_IsoM_v3;
    int HLT_Photon175_v3;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon22_R9Id90_HE10_IsoM_v2;
    int HLT_Photon22_v2;
    int HLT_Photon250_NoHE_v2;
    int HLT_Photon300_NoHE_v2;
    int HLT_Photon30_R9Id90_HE10_IsoM_v3;
    int HLT_Photon30_v3;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon36_R9Id90_HE10_IsoM_v3;
    int HLT_Photon36_v3;
    int HLT_Photon500_v1;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon50_R9Id90_HE10_IsoM_v3;
    int HLT_Photon50_v3;
    int HLT_Photon600_v1;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon75_R9Id90_HE10_IsoM_v3;
    int HLT_Photon75_v3;
    int HLT_Photon90_CaloIdL_HT300_v1;
    int HLT_Photon90_CaloIdL_PFHT500_v3;
    int HLT_Photon90_CaloIdL_PFHT600_v2;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3;
    int HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2;
    int HLT_Photon90_R9Id90_HE10_IsoM_v3;
    int HLT_Photon90_v3;
    int HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
    int HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1;
    int HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1;
    int HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1;
    int HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2;
    int HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3;
    int HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1;
    int HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4;
    int HLT_DoublePhoton40_v1;
    int HLT_DoublePhoton50_v1;
    int HLT_DoublePhoton60_v1;
    int HLT_DoublePhoton85_v2;
    int HLT_ECALHT800_v2;
    int HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
    int HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3;
    int HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3;
    int HLT_Ele30WP60_Ele8_Mass55_v2;
    int HLT_Ele30WP60_SC4_Mass55_v3;
    int HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3;
    int HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3;
    int HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2;
    int HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2;
    int HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2;


  };

  std::string triggerBranchDefString("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3/I:HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2:HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2:HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3:HLT_AK8PFJet360_TrimMass30_v3:HLT_CaloJet500_NoJetID_v2:HLT_DiCaloJetAve140_v1:HLT_DiCaloJetAve200_v1:HLT_DiCaloJetAve260_v1:HLT_DiCaloJetAve320_v1:HLT_DiCaloJetAve400_v1:HLT_DiCaloJetAve40_v1:HLT_DiCaloJetAve500_v1:HLT_DiCaloJetAve60_v1:HLT_DiCaloJetAve80_v1:HLT_DiPFJetAve100_HFJEC_v3:HLT_DiPFJetAve140_v2:HLT_DiPFJetAve160_HFJEC_v3:HLT_DiPFJetAve200_v2:HLT_DiPFJetAve220_HFJEC_v3:HLT_DiPFJetAve260_v2:HLT_DiPFJetAve300_HFJEC_v3:HLT_DiPFJetAve30_HFJEC_v3:HLT_DiPFJetAve320_v2:HLT_DiPFJetAve400_v2:HLT_DiPFJetAve40_v2:HLT_DiPFJetAve500_v2:HLT_DiPFJetAve60_HFJEC_v3:HLT_DiPFJetAve60_v2:HLT_DiPFJetAve80_HFJEC_v3:HLT_DiPFJetAve80_v2:HLT_HT2000_v1:HLT_HT200_v1:HLT_HT2500_v1:HLT_HT275_v1:HLT_HT325_v1:HLT_HT425_v1:HLT_HT575_v1:HLT_L1_TripleJet_VBF_v4:HLT_PFHT200_v2:HLT_PFHT250_v2:HLT_PFHT300_v2:HLT_PFHT350_v3:HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3:HLT_PFHT400_SixJet30_v3:HLT_PFHT400_v2:HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3:HLT_PFHT450_SixJet40_v3:HLT_PFHT475_v2:HLT_PFHT550_4JetPt50_v1:HLT_PFHT600_v3:HLT_PFHT650_4JetPt50_v1:HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3:HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3:HLT_PFHT650_v3:HLT_PFHT750_4JetPt50_v3:HLT_PFHT800_v2:HLT_PFJet140_v4:HLT_PFJet200_v4:HLT_PFJet260_v4:HLT_PFJet320_v4:HLT_PFJet400_v4:HLT_PFJet40_v4:HLT_PFJet450_v4:HLT_PFJet500_v4:HLT_PFJet60_v4:HLT_PFJet80_v4:HLT_QuadPFJet_VBF_v4:HLT_DoubleIsoMu17_eta2p1_v3:HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1:HLT_IsoMu16_eta2p1_MET30_v1:HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4:HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4:HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3:HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5:HLT_IsoMu17_eta2p1_v3:HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2:HLT_IsoMu18_TriCentralPFJet50_40_30_v2:HLT_IsoMu18_v2:HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3:HLT_IsoMu20_eta2p1_v4:HLT_IsoMu20_v3:HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2:HLT_IsoMu22_TriCentralPFJet50_40_30_v2:HLT_IsoMu22_v2:HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4:HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4:HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4:HLT_IsoMu24_eta2p1_v3:HLT_IsoMu27_v3:HLT_IsoTkMu18_v2:HLT_IsoTkMu20_eta2p1_v3:HLT_IsoTkMu20_v4:HLT_IsoTkMu22_v2:HLT_IsoTkMu24_eta2p1_v3:HLT_IsoTkMu27_v3:HLT_L1SingleMu16_v1:HLT_L1SingleMuOpen_v2:HLT_L2Mu10_v1:HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1:HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3:HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2:HLT_Mu15_IsoVVVL_PFHT350_v2:HLT_Mu15_IsoVVVL_PFHT600_v3:HLT_Mu16_eta2p1_MET30_v1:HLT_Mu20_v2:HLT_Mu24_eta2p1_v2:HLT_Mu27_v2:HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2:HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2:HLT_Mu300_v1:HLT_Mu30_eta2p1_PFJet150_PFJet50_v1:HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2:HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2:HLT_Mu350_v1:HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2:HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2:HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2:HLT_Mu40_eta2p1_PFJet200_PFJet50_v3:HLT_Mu45_eta2p1_v2:HLT_Mu50_v2:HLT_Mu55_v1:HLT_OldIsoMu18_v1:HLT_OldIsoTkMu18_v2:HLT_TkMu20_v2:HLT_TkMu24_eta2p1_v2:HLT_TkMu27_v2:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon120_R9Id90_HE10_IsoM_v3:HLT_Photon120_v3:HLT_Photon125_v1:HLT_Photon135_PFMET100_v1:HLT_Photon150_v1:HLT_Photon165_HE10_v3:HLT_Photon165_R9Id90_HE10_IsoM_v3:HLT_Photon175_v3:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon22_R9Id90_HE10_IsoM_v2:HLT_Photon22_v2:HLT_Photon250_NoHE_v2:HLT_Photon300_NoHE_v2:HLT_Photon30_R9Id90_HE10_IsoM_v3:HLT_Photon30_v3:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon36_R9Id90_HE10_IsoM_v3:HLT_Photon36_v3:HLT_Photon500_v1:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon50_R9Id90_HE10_IsoM_v3:HLT_Photon50_v3:HLT_Photon600_v1:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon75_R9Id90_HE10_IsoM_v3:HLT_Photon75_v3:HLT_Photon90_CaloIdL_HT300_v1:HLT_Photon90_CaloIdL_PFHT500_v3:HLT_Photon90_CaloIdL_PFHT600_v2:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3:HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2:HLT_Photon90_R9Id90_HE10_IsoM_v3:HLT_Photon90_v3:HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1:HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1:HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1:HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1:HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2:HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3:HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1:HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4:HLT_DoublePhoton40_v1:HLT_DoublePhoton50_v1:HLT_DoublePhoton60_v1:HLT_DoublePhoton85_v2:HLT_ECALHT800_v2:HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3:HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3:HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3:HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3:HLT_Ele30WP60_Ele8_Mass55_v2:HLT_Ele30WP60_SC4_Mass55_v3:HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3:HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3:HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3:HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2:HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2:HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2");
  
  void InitTriggerInfo(triggerInfo_t &triggerInfo) {
    triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = -1;
    triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = -1;
    triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = -1;
    triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = -1;
    triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = -1;
    triggerInfo.HLT_CaloJet500_NoJetID_v2 = -1;
    triggerInfo.HLT_DiCaloJetAve140_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve200_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve260_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve320_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve400_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve40_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve500_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve60_v1 = -1;
    triggerInfo.HLT_DiCaloJetAve80_v1 = -1;
    triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve140_v2 = -1;
    triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve200_v2 = -1;
    triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve260_v2 = -1;
    triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve320_v2 = -1;
    triggerInfo.HLT_DiPFJetAve400_v2 = -1;
    triggerInfo.HLT_DiPFJetAve40_v2 = -1;
    triggerInfo.HLT_DiPFJetAve500_v2 = -1;
    triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve60_v2 = -1;
    triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = -1;
    triggerInfo.HLT_DiPFJetAve80_v2 = -1;
    triggerInfo.HLT_HT2000_v1 = -1;
    triggerInfo.HLT_HT200_v1 = -1;
    triggerInfo.HLT_HT2500_v1 = -1;
    triggerInfo.HLT_HT275_v1 = -1;
    triggerInfo.HLT_HT325_v1 = -1;
    triggerInfo.HLT_HT425_v1 = -1;
    triggerInfo.HLT_HT575_v1 = -1;
    triggerInfo.HLT_L1_TripleJet_VBF_v4 = -1;
    triggerInfo.HLT_PFHT200_v2 = -1;
    triggerInfo.HLT_PFHT250_v2 = -1;
    triggerInfo.HLT_PFHT300_v2 = -1;
    triggerInfo.HLT_PFHT350_v3 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = -1;
    triggerInfo.HLT_PFHT400_SixJet30_v3 = -1;
    triggerInfo.HLT_PFHT400_v2 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = -1;
    triggerInfo.HLT_PFHT450_SixJet40_v3 = -1;
    triggerInfo.HLT_PFHT475_v2 = -1;
    triggerInfo.HLT_PFHT550_4JetPt50_v1 = -1;
    triggerInfo.HLT_PFHT600_v3 = -1;
    triggerInfo.HLT_PFHT650_4JetPt50_v1 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = -1;
    triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = -1;
    triggerInfo.HLT_PFHT650_v3 = -1;
    triggerInfo.HLT_PFHT750_4JetPt50_v3 = -1;
    triggerInfo.HLT_PFHT800_v2 = -1;
    triggerInfo.HLT_PFJet140_v4 = -1;
    triggerInfo.HLT_PFJet200_v4 = -1;
    triggerInfo.HLT_PFJet260_v4 = -1;
    triggerInfo.HLT_PFJet320_v4 = -1;
    triggerInfo.HLT_PFJet400_v4 = -1;
    triggerInfo.HLT_PFJet40_v4 = -1;
    triggerInfo.HLT_PFJet450_v4 = -1;
    triggerInfo.HLT_PFJet500_v4 = -1;
    triggerInfo.HLT_PFJet60_v4 = -1;
    triggerInfo.HLT_PFJet80_v4 = -1;
    triggerInfo.HLT_QuadPFJet_VBF_v4 = -1;
    triggerInfo.HLT_DoubleIsoMu17_eta2p1_v3 = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = -1;
    triggerInfo.HLT_IsoMu16_eta2p1_MET30_v1 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5 = -1;
    triggerInfo.HLT_IsoMu17_eta2p1_v3 = -1;
    triggerInfo.HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2 = -1;
    triggerInfo.HLT_IsoMu18_TriCentralPFJet50_40_30_v2 = -1;
    triggerInfo.HLT_IsoMu18_v2 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3 = -1;
    triggerInfo.HLT_IsoMu20_eta2p1_v4 = -1;
    triggerInfo.HLT_IsoMu20_v3 = -1;
    triggerInfo.HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2 = -1;
    triggerInfo.HLT_IsoMu22_TriCentralPFJet50_40_30_v2 = -1;
    triggerInfo.HLT_IsoMu22_v2 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4 = -1;
    triggerInfo.HLT_IsoMu24_eta2p1_v3 = -1;
    triggerInfo.HLT_IsoMu27_v3 = -1;
    triggerInfo.HLT_IsoTkMu18_v2 = -1;
    triggerInfo.HLT_IsoTkMu20_eta2p1_v3 = -1;
    triggerInfo.HLT_IsoTkMu20_v4 = -1;
    triggerInfo.HLT_IsoTkMu22_v2 = -1;
    triggerInfo.HLT_IsoTkMu24_eta2p1_v3 = -1;
    triggerInfo.HLT_IsoTkMu27_v3 = -1;
    triggerInfo.HLT_L1SingleMu16_v1 = -1;
    triggerInfo.HLT_L1SingleMuOpen_v2 = -1;
    triggerInfo.HLT_L2Mu10_v1 = -1;
    triggerInfo.HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_v2 = -1;
    triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v3 = -1;
    triggerInfo.HLT_Mu16_eta2p1_MET30_v1 = -1;
    triggerInfo.HLT_Mu20_v2 = -1;
    triggerInfo.HLT_Mu24_eta2p1_v2 = -1;
    triggerInfo.HLT_Mu27_v2 = -1;
    triggerInfo.HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2 = -1;
    triggerInfo.HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2 = -1;
    triggerInfo.HLT_Mu300_v1 = -1;
    triggerInfo.HLT_Mu30_eta2p1_PFJet150_PFJet50_v1 = -1;
    triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2 = -1;
    triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2 = -1;
    triggerInfo.HLT_Mu350_v1 = -1;
    triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2 = -1;
    triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2 = -1;
    triggerInfo.HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2 = -1;
    triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v3 = -1;
    triggerInfo.HLT_Mu45_eta2p1_v2 = -1;
    triggerInfo.HLT_Mu50_v2 = -1;
    triggerInfo.HLT_Mu55_v1 = -1;
    triggerInfo.HLT_OldIsoMu18_v1 = -1;
    triggerInfo.HLT_OldIsoTkMu18_v2 = -1;
    triggerInfo.HLT_TkMu20_v2 = -1;
    triggerInfo.HLT_TkMu24_eta2p1_v2 = -1;
    triggerInfo.HLT_TkMu27_v2 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon120_v3 = -1;
    triggerInfo.HLT_Photon125_v1 = -1;
    triggerInfo.HLT_Photon135_PFMET100_v1 = -1;
    triggerInfo.HLT_Photon150_v1 = -1;
    triggerInfo.HLT_Photon165_HE10_v3 = -1;
    triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon175_v3 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = -1;
    triggerInfo.HLT_Photon22_v2 = -1;
    triggerInfo.HLT_Photon250_NoHE_v2 = -1;
    triggerInfo.HLT_Photon300_NoHE_v2 = -1;
    triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon30_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon36_v3 = -1;
    triggerInfo.HLT_Photon500_v1 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon50_v3 = -1;
    triggerInfo.HLT_Photon600_v1 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon75_v3 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = -1;
    triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = -1;
    triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = -1;
    triggerInfo.HLT_Photon90_v3 = -1;
    triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = -1;
    triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = -1;
    triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = -1;
    triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = -1;
    triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = -1;
    triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = -1;
    triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = -1;
    triggerInfo.HLT_DoublePhoton40_v1 = -1;
    triggerInfo.HLT_DoublePhoton50_v1 = -1;
    triggerInfo.HLT_DoublePhoton60_v1 = -1;
    triggerInfo.HLT_DoublePhoton85_v2 = -1;
    triggerInfo.HLT_ECALHT800_v2 = -1;
    triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = -1;
    triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = -1;
    triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = -1;
    triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = -1;
    triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = -1;
    triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = -1;
    triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = -1;
    triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = -1;
    triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = -1;
    triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = -1;

  }

  
  
  void FillTriggerBits(triggerInfo_t &triggerInfo, const edm::TriggerResults* triggerResults, const edm::Event& iEvent) {
    
    // first clear decisions from previous event
    ExoDiPhotons::InitTriggerInfo(triggerInfo);

    //get trigger names from the event
    std::vector<std::string> trigNames = iEvent.triggerNames(*triggerResults).triggerNames();

    // loop over the trigger names and write trigger bits and prescales
    for (unsigned int i=0; i < trigNames.size(); i++){
      std::string currentTrigger = trigNames.at(i);

      if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3")
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2")
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2")
        triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3")
        triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v3")
        triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_CaloJet500_NoJetID_v2")
        triggerInfo.HLT_CaloJet500_NoJetID_v2 = triggerResults->accept(i);
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
      else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve140_v2")
        triggerInfo.HLT_DiPFJetAve140_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve200_v2")
        triggerInfo.HLT_DiPFJetAve200_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve260_v2")
        triggerInfo.HLT_DiPFJetAve260_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve320_v2")
        triggerInfo.HLT_DiPFJetAve320_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve400_v2")
        triggerInfo.HLT_DiPFJetAve400_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve40_v2")
        triggerInfo.HLT_DiPFJetAve40_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve500_v2")
        triggerInfo.HLT_DiPFJetAve500_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve60_v2")
        triggerInfo.HLT_DiPFJetAve60_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DiPFJetAve80_v2")
        triggerInfo.HLT_DiPFJetAve80_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT2000_v1")
        triggerInfo.HLT_HT2000_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT200_v1")
        triggerInfo.HLT_HT200_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT2500_v1")
        triggerInfo.HLT_HT2500_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT275_v1")
        triggerInfo.HLT_HT275_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT325_v1")
        triggerInfo.HLT_HT325_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT425_v1")
        triggerInfo.HLT_HT425_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_HT575_v1")
        triggerInfo.HLT_HT575_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_L1_TripleJet_VBF_v4")
        triggerInfo.HLT_L1_TripleJet_VBF_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT200_v2")
        triggerInfo.HLT_PFHT200_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT250_v2")
        triggerInfo.HLT_PFHT250_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT300_v2")
        triggerInfo.HLT_PFHT300_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT350_v3")
        triggerInfo.HLT_PFHT350_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3")
        triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT400_SixJet30_v3")
        triggerInfo.HLT_PFHT400_SixJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT400_v2")
        triggerInfo.HLT_PFHT400_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3")
        triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT450_SixJet40_v3")
        triggerInfo.HLT_PFHT450_SixJet40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT475_v2")
        triggerInfo.HLT_PFHT475_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT550_4JetPt50_v1")
        triggerInfo.HLT_PFHT550_4JetPt50_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT600_v3")
        triggerInfo.HLT_PFHT600_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT650_4JetPt50_v1")
        triggerInfo.HLT_PFHT650_4JetPt50_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3")
        triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3")
        triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT650_v3")
        triggerInfo.HLT_PFHT650_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT750_4JetPt50_v3")
        triggerInfo.HLT_PFHT750_4JetPt50_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFHT800_v2")
        triggerInfo.HLT_PFHT800_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet140_v4")
        triggerInfo.HLT_PFJet140_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet200_v4")
        triggerInfo.HLT_PFJet200_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet260_v4")
        triggerInfo.HLT_PFJet260_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet320_v4")
        triggerInfo.HLT_PFJet320_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet400_v4")
        triggerInfo.HLT_PFJet400_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet40_v4")
        triggerInfo.HLT_PFJet40_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet450_v4")
        triggerInfo.HLT_PFJet450_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet500_v4")
        triggerInfo.HLT_PFJet500_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet60_v4")
        triggerInfo.HLT_PFJet60_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_PFJet80_v4")
        triggerInfo.HLT_PFJet80_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_QuadPFJet_VBF_v4")
        triggerInfo.HLT_QuadPFJet_VBF_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleIsoMu17_eta2p1_v3")
        triggerInfo.HLT_DoubleIsoMu17_eta2p1_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1")
        triggerInfo.HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu16_eta2p1_MET30_v1")
        triggerInfo.HLT_IsoMu16_eta2p1_MET30_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4")
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4")
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3")
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5")
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_v3")
        triggerInfo.HLT_IsoMu17_eta2p1_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2")
        triggerInfo.HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu18_TriCentralPFJet50_40_30_v2")
        triggerInfo.HLT_IsoMu18_TriCentralPFJet50_40_30_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu18_v2")
        triggerInfo.HLT_IsoMu18_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3")
        triggerInfo.HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu20_eta2p1_v4")
        triggerInfo.HLT_IsoMu20_eta2p1_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu20_v3")
        triggerInfo.HLT_IsoMu20_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2")
        triggerInfo.HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu22_TriCentralPFJet50_40_30_v2")
        triggerInfo.HLT_IsoMu22_TriCentralPFJet50_40_30_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu22_v2")
        triggerInfo.HLT_IsoMu22_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_v3")
        triggerInfo.HLT_IsoMu24_eta2p1_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoMu27_v3")
        triggerInfo.HLT_IsoMu27_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu18_v2")
        triggerInfo.HLT_IsoTkMu18_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu20_eta2p1_v3")
        triggerInfo.HLT_IsoTkMu20_eta2p1_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu20_v4")
        triggerInfo.HLT_IsoTkMu20_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu22_v2")
        triggerInfo.HLT_IsoTkMu22_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu24_eta2p1_v3")
        triggerInfo.HLT_IsoTkMu24_eta2p1_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_IsoTkMu27_v3")
        triggerInfo.HLT_IsoTkMu27_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_L1SingleMu16_v1")
        triggerInfo.HLT_L1SingleMu16_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_L1SingleMuOpen_v2")
        triggerInfo.HLT_L1SingleMuOpen_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_L2Mu10_v1")
        triggerInfo.HLT_L2Mu10_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1")
        triggerInfo.HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3")
        triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT350_v2")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT600_v3")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu16_eta2p1_MET30_v1")
        triggerInfo.HLT_Mu16_eta2p1_MET30_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu20_v2")
        triggerInfo.HLT_Mu20_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu24_eta2p1_v2")
        triggerInfo.HLT_Mu24_eta2p1_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu27_v2")
        triggerInfo.HLT_Mu27_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2")
        triggerInfo.HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2")
        triggerInfo.HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu300_v1")
        triggerInfo.HLT_Mu300_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu30_eta2p1_PFJet150_PFJet50_v1")
        triggerInfo.HLT_Mu30_eta2p1_PFJet150_PFJet50_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2")
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2")
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu350_v1")
        triggerInfo.HLT_Mu350_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu40_eta2p1_PFJet200_PFJet50_v3")
        triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu45_eta2p1_v2")
        triggerInfo.HLT_Mu45_eta2p1_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu50_v2")
        triggerInfo.HLT_Mu50_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Mu55_v1")
        triggerInfo.HLT_Mu55_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_OldIsoMu18_v1")
        triggerInfo.HLT_OldIsoMu18_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_OldIsoTkMu18_v2")
        triggerInfo.HLT_OldIsoTkMu18_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_TkMu20_v2")
        triggerInfo.HLT_TkMu20_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_TkMu24_eta2p1_v2")
        triggerInfo.HLT_TkMu24_eta2p1_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_TkMu27_v2")
        triggerInfo.HLT_TkMu27_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon120_v3")
        triggerInfo.HLT_Photon120_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon125_v1")
        triggerInfo.HLT_Photon125_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon135_PFMET100_v1")
        triggerInfo.HLT_Photon135_PFMET100_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon150_v1")
        triggerInfo.HLT_Photon150_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon165_HE10_v3")
        triggerInfo.HLT_Photon165_HE10_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon175_v3")
        triggerInfo.HLT_Photon175_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v2")
        triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon22_v2")
        triggerInfo.HLT_Photon22_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon250_NoHE_v2")
        triggerInfo.HLT_Photon250_NoHE_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon300_NoHE_v2")
        triggerInfo.HLT_Photon300_NoHE_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon30_v3")
        triggerInfo.HLT_Photon30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon36_v3")
        triggerInfo.HLT_Photon36_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon500_v1")
        triggerInfo.HLT_Photon500_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon50_v3")
        triggerInfo.HLT_Photon50_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon600_v1")
        triggerInfo.HLT_Photon600_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon75_v3")
        triggerInfo.HLT_Photon75_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v1")
        triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v3")
        triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v2")
        triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon90_v3")
        triggerInfo.HLT_Photon90_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
        triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
        triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1")
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1")
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1")
        triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2")
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1")
        triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3")
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3")
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1")
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4")
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoublePhoton40_v1")
        triggerInfo.HLT_DoublePhoton40_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoublePhoton50_v1")
        triggerInfo.HLT_DoublePhoton50_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoublePhoton60_v1")
        triggerInfo.HLT_DoublePhoton60_v1 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_DoublePhoton85_v2")
        triggerInfo.HLT_DoublePhoton85_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_ECALHT800_v2")
        triggerInfo.HLT_ECALHT800_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3")
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3")
        triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2")
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v2")
        triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v3")
        triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2")
        triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2")
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = triggerResults->accept(i);
      else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2")
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = triggerResults->accept(i);

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
      if (currentTrigger == "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3")
        triggerInfo.HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2")
        triggerInfo.HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2")
        triggerInfo.HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3")
        triggerInfo.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_AK8PFJet360_TrimMass30_v3")
        triggerInfo.HLT_AK8PFJet360_TrimMass30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_CaloJet500_NoJetID_v2")
        triggerInfo.HLT_CaloJet500_NoJetID_v2 = prescales->getPrescaleForIndex(i);
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
      else if (currentTrigger == "HLT_DiPFJetAve100_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve100_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve140_v2")
        triggerInfo.HLT_DiPFJetAve140_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve160_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve160_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve200_v2")
        triggerInfo.HLT_DiPFJetAve200_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve220_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve220_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve260_v2")
        triggerInfo.HLT_DiPFJetAve260_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve300_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve300_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve30_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve30_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve320_v2")
        triggerInfo.HLT_DiPFJetAve320_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve400_v2")
        triggerInfo.HLT_DiPFJetAve400_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve40_v2")
        triggerInfo.HLT_DiPFJetAve40_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve500_v2")
        triggerInfo.HLT_DiPFJetAve500_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve60_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve60_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve60_v2")
        triggerInfo.HLT_DiPFJetAve60_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve80_HFJEC_v3")
        triggerInfo.HLT_DiPFJetAve80_HFJEC_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DiPFJetAve80_v2")
        triggerInfo.HLT_DiPFJetAve80_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT2000_v1")
        triggerInfo.HLT_HT2000_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT200_v1")
        triggerInfo.HLT_HT200_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT2500_v1")
        triggerInfo.HLT_HT2500_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT275_v1")
        triggerInfo.HLT_HT275_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT325_v1")
        triggerInfo.HLT_HT325_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT425_v1")
        triggerInfo.HLT_HT425_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_HT575_v1")
        triggerInfo.HLT_HT575_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_L1_TripleJet_VBF_v4")
        triggerInfo.HLT_L1_TripleJet_VBF_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT200_v2")
        triggerInfo.HLT_PFHT200_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT250_v2")
        triggerInfo.HLT_PFHT250_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT300_v2")
        triggerInfo.HLT_PFHT300_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT350_v3")
        triggerInfo.HLT_PFHT350_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3")
        triggerInfo.HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT400_SixJet30_v3")
        triggerInfo.HLT_PFHT400_SixJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT400_v2")
        triggerInfo.HLT_PFHT400_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3")
        triggerInfo.HLT_PFHT450_SixJet40_PFBTagCSV0p72_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT450_SixJet40_v3")
        triggerInfo.HLT_PFHT450_SixJet40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT475_v2")
        triggerInfo.HLT_PFHT475_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT550_4JetPt50_v1")
        triggerInfo.HLT_PFHT550_4JetPt50_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT600_v3")
        triggerInfo.HLT_PFHT600_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT650_4JetPt50_v1")
        triggerInfo.HLT_PFHT650_4JetPt50_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3")
        triggerInfo.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3")
        triggerInfo.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT650_v3")
        triggerInfo.HLT_PFHT650_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT750_4JetPt50_v3")
        triggerInfo.HLT_PFHT750_4JetPt50_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFHT800_v2")
        triggerInfo.HLT_PFHT800_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet140_v4")
        triggerInfo.HLT_PFJet140_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet200_v4")
        triggerInfo.HLT_PFJet200_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet260_v4")
        triggerInfo.HLT_PFJet260_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet320_v4")
        triggerInfo.HLT_PFJet320_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet400_v4")
        triggerInfo.HLT_PFJet400_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet40_v4")
        triggerInfo.HLT_PFJet40_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet450_v4")
        triggerInfo.HLT_PFJet450_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet500_v4")
        triggerInfo.HLT_PFJet500_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet60_v4")
        triggerInfo.HLT_PFJet60_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_PFJet80_v4")
        triggerInfo.HLT_PFJet80_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_QuadPFJet_VBF_v4")
        triggerInfo.HLT_QuadPFJet_VBF_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleIsoMu17_eta2p1_v3")
        triggerInfo.HLT_DoubleIsoMu17_eta2p1_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1")
        triggerInfo.HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu16_eta2p1_MET30_v1")
        triggerInfo.HLT_IsoMu16_eta2p1_MET30_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4")
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4")
        triggerInfo.HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3")
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau35_Trk1_eta2p1_Reg_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5")
        triggerInfo.HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v5 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu17_eta2p1_v3")
        triggerInfo.HLT_IsoMu17_eta2p1_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2")
        triggerInfo.HLT_IsoMu18_CentralPFJet30_BTagCSV07_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu18_TriCentralPFJet50_40_30_v2")
        triggerInfo.HLT_IsoMu18_TriCentralPFJet50_40_30_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu18_v2")
        triggerInfo.HLT_IsoMu18_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3")
        triggerInfo.HLT_IsoMu20_eta2p1_LooseIsoPFTau20_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu20_eta2p1_v4")
        triggerInfo.HLT_IsoMu20_eta2p1_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu20_v3")
        triggerInfo.HLT_IsoMu20_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2")
        triggerInfo.HLT_IsoMu22_CentralPFJet30_BTagCSV07_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu22_TriCentralPFJet50_40_30_v2")
        triggerInfo.HLT_IsoMu22_TriCentralPFJet50_40_30_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu22_v2")
        triggerInfo.HLT_IsoMu22_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet30_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4")
        triggerInfo.HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu24_eta2p1_v3")
        triggerInfo.HLT_IsoMu24_eta2p1_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoMu27_v3")
        triggerInfo.HLT_IsoMu27_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu18_v2")
        triggerInfo.HLT_IsoTkMu18_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu20_eta2p1_v3")
        triggerInfo.HLT_IsoTkMu20_eta2p1_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu20_v4")
        triggerInfo.HLT_IsoTkMu20_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu22_v2")
        triggerInfo.HLT_IsoTkMu22_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu24_eta2p1_v3")
        triggerInfo.HLT_IsoTkMu24_eta2p1_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_IsoTkMu27_v3")
        triggerInfo.HLT_IsoTkMu27_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_L1SingleMu16_v1")
        triggerInfo.HLT_L1SingleMu16_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_L1SingleMuOpen_v2")
        triggerInfo.HLT_L1SingleMuOpen_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_L2Mu10_v1")
        triggerInfo.HLT_L2Mu10_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1")
        triggerInfo.HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3")
        triggerInfo.HLT_Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT350_v2")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT350_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu15_IsoVVVL_PFHT600_v3")
        triggerInfo.HLT_Mu15_IsoVVVL_PFHT600_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu16_eta2p1_MET30_v1")
        triggerInfo.HLT_Mu16_eta2p1_MET30_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu20_v2")
        triggerInfo.HLT_Mu20_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu24_eta2p1_v2")
        triggerInfo.HLT_Mu24_eta2p1_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu27_v2")
        triggerInfo.HLT_Mu27_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2")
        triggerInfo.HLT_Mu28NoFiltersNoVtx_CentralCaloJet40_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2")
        triggerInfo.HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu300_v1")
        triggerInfo.HLT_Mu300_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu30_eta2p1_PFJet150_PFJet50_v1")
        triggerInfo.HLT_Mu30_eta2p1_PFJet150_PFJet50_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2")
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2")
        triggerInfo.HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu350_v1")
        triggerInfo.HLT_Mu350_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2")
        triggerInfo.HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu40_eta2p1_PFJet200_PFJet50_v3")
        triggerInfo.HLT_Mu40_eta2p1_PFJet200_PFJet50_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu45_eta2p1_v2")
        triggerInfo.HLT_Mu45_eta2p1_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu50_v2")
        triggerInfo.HLT_Mu50_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Mu55_v1")
        triggerInfo.HLT_Mu55_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_OldIsoMu18_v1")
        triggerInfo.HLT_OldIsoMu18_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_OldIsoTkMu18_v2")
        triggerInfo.HLT_OldIsoTkMu18_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_TkMu20_v2")
        triggerInfo.HLT_TkMu20_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_TkMu24_eta2p1_v2")
        triggerInfo.HLT_TkMu24_eta2p1_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_TkMu27_v2")
        triggerInfo.HLT_TkMu27_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon120_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon120_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon120_v3")
        triggerInfo.HLT_Photon120_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon125_v1")
        triggerInfo.HLT_Photon125_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon135_PFMET100_v1")
        triggerInfo.HLT_Photon135_PFMET100_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon150_v1")
        triggerInfo.HLT_Photon150_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon165_HE10_v3")
        triggerInfo.HLT_Photon165_HE10_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon165_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon165_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon175_v3")
        triggerInfo.HLT_Photon175_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon22_R9Id90_HE10_IsoM_v2")
        triggerInfo.HLT_Photon22_R9Id90_HE10_IsoM_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon22_v2")
        triggerInfo.HLT_Photon22_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon250_NoHE_v2")
        triggerInfo.HLT_Photon250_NoHE_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon300_NoHE_v2")
        triggerInfo.HLT_Photon300_NoHE_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon30_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon30_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon30_v3")
        triggerInfo.HLT_Photon30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon36_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon36_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon36_v3")
        triggerInfo.HLT_Photon36_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon500_v1")
        triggerInfo.HLT_Photon500_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon50_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon50_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon50_v3")
        triggerInfo.HLT_Photon50_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon600_v1")
        triggerInfo.HLT_Photon600_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon75_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon75_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon75_v3")
        triggerInfo.HLT_Photon75_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_HT300_v1")
        triggerInfo.HLT_Photon90_CaloIdL_HT300_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT500_v3")
        triggerInfo.HLT_Photon90_CaloIdL_PFHT500_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_CaloIdL_PFHT600_v2")
        triggerInfo.HLT_Photon90_CaloIdL_PFHT600_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3")
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2")
        triggerInfo.HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_R9Id90_HE10_IsoM_v3")
        triggerInfo.HLT_Photon90_R9Id90_HE10_IsoM_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon90_v3")
        triggerInfo.HLT_Photon90_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
        triggerInfo.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1")
        triggerInfo.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1")
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1")
        triggerInfo.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1")
        triggerInfo.HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2")
        triggerInfo.HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1")
        triggerInfo.HLT_DoubleEle25_CaloIdL_GsfTrkIdVL_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3")
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3")
        triggerInfo.HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1")
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4")
        triggerInfo.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v4 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoublePhoton40_v1")
        triggerInfo.HLT_DoublePhoton40_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoublePhoton50_v1")
        triggerInfo.HLT_DoublePhoton50_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoublePhoton60_v1")
        triggerInfo.HLT_DoublePhoton60_v1 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_DoublePhoton85_v2")
        triggerInfo.HLT_DoublePhoton85_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_ECALHT800_v2")
        triggerInfo.HLT_ECALHT800_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3")
        triggerInfo.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3")
        triggerInfo.HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2")
        triggerInfo.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3")
        triggerInfo.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele30WP60_Ele8_Mass55_v2")
        triggerInfo.HLT_Ele30WP60_Ele8_Mass55_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele30WP60_SC4_Mass55_v3")
        triggerInfo.HLT_Ele30WP60_SC4_Mass55_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3")
        triggerInfo.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3")
        triggerInfo.HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v3 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2")
        triggerInfo.HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2")
        triggerInfo.HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v2 = prescales->getPrescaleForIndex(i);
      else if (currentTrigger == "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2")
        triggerInfo.HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v2 = prescales->getPrescaleForIndex(i);

    } // end loop over trigger names
  } // end FillTriggerPrescales function


} // end of namespace

#endif
