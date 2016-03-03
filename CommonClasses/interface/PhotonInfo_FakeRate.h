#ifndef PHOTON_INFO_FAKERATE_INC
#define PHOTON_INFO_FAKERATE_INC

#include "DataFormats/PatCandidates/interface/Photon.h"

namespace ExoDiPhotons
{
  struct photonInfo_t {
    // kinematics
    double pt;
    double eta;
    double phi;
    double scEta;
    double scPhi;

    // isolation
    double rho;
    double PFIsoCharged03;
    double PFIsoNeutral03;
    double PFIsoPhoton03;
    double rhocorPFIsoCharged03;
    double rhocorPFIsoNeutral03;
    double rhocorPFIsoPhoton03;
    double hadTowerOverEm;

    // shower shape variables
    double r9;
    double sigmaIetaIeta;
    double sigmaEtaEta;
    double sigmaIphiIphi;
    double sigmaPhiPhi;
    double maxEnergyXtal;

    //fiducial flags
    bool isEB; //Photon is in EB
    bool isEE; //Photon is in EE
    bool isEBEtaGap; //Photon is in supermodule/supercrystal eta gap in EB
    bool isEBPhiGap; //Photon is in supermodule/supercrystal phi gap in EB
    bool isEERingGap; //Photon is in crystal ring gap in EE
    bool isEEDeeGap; //Photon is in crystal dee gap in EE
    bool isEBEEGap; //Photon is in border between EB and EE.

    // electron veto and high pT ID checks
    bool passedElectronVeto;
    bool passedHoverE;
    bool passedChIso;
    bool passedPhoIso;
    bool passedSieie;
    bool passedHighPtID;

    // for fake rate
    bool isFakeable;
    bool isNumeratorObj;
    bool isDenominatorObj;

    // saturation
    bool isSaturated;

  };

  std::string photonBranchDefString("pt/D:eta:phi:scEta:scPhi:rho:PFIsoCharged03:PFIsoNeutral03:PFIsoPhoton03:rhocorPFIsoCharged03:rhocorPFIsoNeutral03:rhocorPFIsoPhoton03:hadTowerOverEm:r9:sigmaIetaIeta:sigmaEtaEta:sigmaIphiIphi:sigmaPhiPhi:maxEnergyXtal:isEB/O:isEE:isEBEtaGap:isEBPhiGap:isEERingGap:isEEDeeGap:isEBEEGap:passedElectronVeto:passedHoverE:passedChIso:passedPhoIso:passedSieie:passedHighPtID:isFakeable:isNumeratorObj:isDenominatorObj:isSaturated");

  void FillPhotonInfo(photonInfo_t &photonInfo, const pat::Photon *photon)
  {
    photonInfo.pt = photon->pt();
    photonInfo.eta = photon->eta();
    photonInfo.phi = photon->phi();
    photonInfo.scEta = photon->superCluster()->eta();
    photonInfo.scPhi = photon->superCluster()->phi();

    photonInfo.isEB        = photon->isEB();        
    photonInfo.isEE        = photon->isEE();   
    photonInfo.isEBEtaGap  = photon->isEBEtaGap();   
    photonInfo.isEBPhiGap  = photon->isEBPhiGap();   
    photonInfo.isEERingGap = photon->isEERingGap(); 
    photonInfo.isEEDeeGap  = photon->isEEDeeGap();   
    photonInfo.isEBEEGap   = photon->isEBEEGap();

    photonInfo.passedElectronVeto = photon->passElectronVeto();
    photonInfo.passedHoverE = ExoDiPhotons::passesHadTowerOverEmCut(photon);
  }

  void InitPhotonInfo(photonInfo_t &photonInfo)
  {
    photonInfo.pt = -9999.99;
    photonInfo.eta = -9999.99;
    photonInfo.phi = -9999.99;
    photonInfo.scEta = -9999.99;
    photonInfo.scPhi = -9999.99;

    photonInfo.rho = -9999.99;
    photonInfo.PFIsoCharged03 = -9999.99;
    photonInfo.PFIsoNeutral03 = -9999.99;
    photonInfo.PFIsoPhoton03 = -9999.99;
    photonInfo.rhocorPFIsoCharged03 = -9999.99;
    photonInfo.rhocorPFIsoNeutral03 = -9999.99;
    photonInfo.rhocorPFIsoPhoton03 = -9999.99;
    photonInfo.hadTowerOverEm = -9999.99;

    photonInfo.r9 = -9999.99;
    photonInfo.sigmaIetaIeta = -9999.99;
    photonInfo.sigmaEtaEta = -9999.99;
    photonInfo.sigmaIphiIphi = -9999.99;
    photonInfo.sigmaPhiPhi = -9999.99;
    photonInfo.maxEnergyXtal = -9999.99;

    photonInfo.isEB        = false;        
    photonInfo.isEE        = false;   
    photonInfo.isEBEtaGap  = false;   
    photonInfo.isEBPhiGap  = false;   
    photonInfo.isEERingGap = false; 
    photonInfo.isEEDeeGap  = false;   
    photonInfo.isEBEEGap   = false;
  }

} // end of namespace

#endif
