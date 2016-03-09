#ifndef PHOTON_INFO_INC
#define PHOTON_INFO_INC

#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"

// for EGM ID
#include "RecoEgamma/EgammaTools/interface/EffectiveAreas.h"

namespace ExoDiPhotons
{
  struct photonInfo_t {
    // kinematics
    double pt; // filled
    double eta; // filled
    double phi; // filled
    double scEta; // filled
    double scPhi; // filled

    // isolation
    double rho; // filled
    double chargedHadIso03; // filled
    double neutralHadIso03; // filled
    double photonIso03; // filled
    double rhoCorChargedHadIso03; // filled
    double rhoCorNeutralHadIso03; // filled
    double rhoCorPhotonIso03; // filled
    double corPhotonIso03; // filled
    double hadTowerOverEm; // filled

    // shower shape variables
    double r9; // filled
    double sigmaIetaIeta; // filled
    double sigmaIetaIeta5x5; // filled
    double sigmaEtaEta; // filled
    double sigmaIphiIphi;
    double sigmaPhiPhi;
    double maxEnergyXtal; // filled

    // high pT ID
    double alphaHighPtID; // filled
    double kappaHighPtID; // filled
    double phoEAHighPtID; // filled

    // EGM ID
    double chEAegmID; // filled
    double nhEAegmID; // filled
    double phoEAegamID; // filled

    // for fake template
    double sideBandLow;
    double sideBandHigh;

    bool passEGMLooseID;
    bool passEGMMediumID;
    bool passEGMTightID;
    
    // fiducial flags
    bool isEB; // filled
    bool isEE; // filled
    bool isEBEtaGap; // filled
    bool isEBPhiGap; // filled
    bool isEERingGap; // filled
    bool isEEDeeGap; // filled
    bool isEBEEGap; // filled

    // electron veto and high pT ID checks
    bool passElectronVeto; // filled
    bool passHTowOverE; // filled
    bool passChIso; // filled
    bool passCorPhoIso; // filled
    bool passSieie; // filled
    bool passHighPtID; // filled

    // for fake rate
    bool passChIsoDenom; // filled
    bool passCorPhoIsoDenom; // filled
    bool isFakeable;
    bool isNumeratorObj; // filled
    bool isDenominatorObj; // filled

    // for fake rate numerator sideband
    bool passChIsoSideband;
    bool isNumeratorWithSidebandObj;

    // saturation
    bool isSaturated; // filled in analyzer and passed to FillPhotonIDInfo
  };

  std::string photonBranchDefString("pt/D:eta:phi:scEta:scPhi:rho:chargedHadIso03:neutralHadIso03:photonIso03:rhoCorChargedHadIso03:rhoCorNeutralHadIso03:rhoCorPhotonIso03:corPhotonIso03:hadTowerOverEm:r9:sigmaIetaIeta:sigmaIetaIeta5x5:sigmaEtaEta:sigmaIphiIphi:sigmaPhiPhi:maxEnergyXtal:alphaHighPtID:kappaHighPtID:phoEAHighPtID:chEAegmID:nhEAegmID:phoEAegmID:sideBandLow:sideBandHigh:passEGMLooseID/O:passEGMMediumID:passEGMTightID:isEB:isEE:isEBEtaGap:isEBPhiGap:isEERingGap:isEEDeeGap:isEBEEGap:passElectronVeto:passHTowOverE:passChIso:passCorPhoIso:passSieie:passHighPtID:passChIsoDenom:passCorPhoIsoDenom:isFakeable:isNumeratorObj:isDenominatorObj:passChIsoSideband:isNumeratorWithSidebandObj:isSaturated");

  void InitPhotonInfo(photonInfo_t &photonInfo)
  {
    // kinematics
    photonInfo.pt    = -9999.99;
    photonInfo.eta   = -9999.99;
    photonInfo.phi   = -9999.99;
    photonInfo.scEta = -9999.99;
    photonInfo.scPhi = -9999.99;

    // isolation
    photonInfo.rho                   = -9999.99;
    photonInfo.chargedHadIso03       = -9999.99;
    photonInfo.neutralHadIso03       = -9999.99;
    photonInfo.photonIso03           = -9999.99;
    photonInfo.rhoCorChargedHadIso03 = -9999.99;
    photonInfo.rhoCorNeutralHadIso03 = -9999.99;
    photonInfo.rhoCorPhotonIso03     = -9999.99;
    photonInfo.corPhotonIso03        = -9999.99;
    photonInfo.hadTowerOverEm        = -9999.99;

    // shower shape variables 
    photonInfo.r9               = -9999.99;
    photonInfo.sigmaIetaIeta    = -9999.99;
    photonInfo.sigmaIetaIeta5x5 = -9999.99;
    photonInfo.sigmaEtaEta      = -9999.99;
    photonInfo.sigmaIphiIphi    = -9999.99;
    photonInfo.sigmaPhiPhi      = -9999.99;
    photonInfo.maxEnergyXtal    = -9999.99;

    // high pT ID
    photonInfo.alphaHighPtID = -9999.99;
    photonInfo.kappaHighPtID = -9999.99;
    photonInfo.phoEAHighPtID = -9999.99;

    // EGM ID
    photonInfo.chEAegmID       = -9999.99;
    photonInfo.nhEAegmID       = -9999.99;
    photonInfo.phoEAegamID     = -9999.99;
    photonInfo.passEGMLooseID  = false;
    photonInfo.passEGMMediumID = false;
    photonInfo.passEGMTightID  = false;
    
    // fiducial flags 
    photonInfo.isEB        = false;        
    photonInfo.isEE        = false;   
    photonInfo.isEBEtaGap  = false;   
    photonInfo.isEBPhiGap  = false;   
    photonInfo.isEERingGap = false; 
    photonInfo.isEEDeeGap  = false;   
    photonInfo.isEBEEGap   = false;

    // electron veto and high pT ID checks
    photonInfo.passElectronVeto = false;
    photonInfo.passHTowOverE    = false;
    photonInfo.passChIso        = false;
    photonInfo.passCorPhoIso    = false;
    photonInfo.passSieie        = false;
    photonInfo.passHighPtID     = false;

    // for fake rate
    photonInfo.passChIsoDenom             = false;
    photonInfo.passCorPhoIsoDenom         = false;
    photonInfo.isFakeable                 = false;
    photonInfo.isNumeratorObj             = false;
    photonInfo.isDenominatorObj           = false;
    photonInfo.passChIsoSideband          = false;
    photonInfo.isNumeratorWithSidebandObj = false;
    photonInfo.sideBandLow                = -9999.99;
    photonInfo.sideBandHigh               = -9999.99;

    // saturation
    photonInfo.isSaturated = false;
  }
  
  void FillBasicPhotonInfo(photonInfo_t &photonInfo, const pat::Photon *photon)
  {
    // kinematics
    photonInfo.pt          = photon->pt();
    photonInfo.eta         = photon->eta();
    photonInfo.phi         = photon->phi();
    photonInfo.scEta       = photon->superCluster()->eta();
    photonInfo.scPhi       = photon->superCluster()->phi();

    // fiducial flags
    photonInfo.isEB        = photon->isEB();        
    photonInfo.isEE        = photon->isEE();   
    photonInfo.isEBEtaGap  = photon->isEBEtaGap();   
    photonInfo.isEBPhiGap  = photon->isEBPhiGap();   
    photonInfo.isEERingGap = photon->isEERingGap(); 
    photonInfo.isEEDeeGap  = photon->isEEDeeGap();   
    photonInfo.isEBEEGap   = photon->isEBEEGap();
  }

  void FillPhotonIDInfo(photonInfo_t &photonInfo, const pat::Photon *photon, double rho, double isSat)
  {
    // isolation
    photonInfo.rho              = rho;
    photonInfo.chargedHadIso03  = photon->chargedHadronIso();
    photonInfo.neutralHadIso03  = photon->neutralHadronIso();
    photonInfo.photonIso03      = photon->photonIso();
    photonInfo.corPhotonIso03   = ExoDiPhotons::corPhoIsoHighPtID(photon,rho);
    photonInfo.hadTowerOverEm   = photon->hadTowOverEm();

    // shower shape variables
    photonInfo.r9               = photon->r9();
    photonInfo.sigmaIetaIeta    = photon->sigmaIetaIeta();
    photonInfo.sigmaIetaIeta5x5 = photon->full5x5_sigmaIetaIeta();
    photonInfo.sigmaEtaEta      = photon->sigmaEtaEta();
    photonInfo.maxEnergyXtal    = photon->maxEnergyXtal();

    // high pT ID
    photonInfo.alphaHighPtID    = ExoDiPhotons::phoAlphaHighPtID(photon);
    photonInfo.kappaHighPtID    = ExoDiPhotons::phoKappaHighPtID(photon);
    photonInfo.phoEAHighPtID    = ExoDiPhotons::phoEAHighPtID(photon);
    
    // electron veto and high pT ID checks
    photonInfo.passElectronVeto = photon->passElectronVeto();
    photonInfo.passHTowOverE    = ExoDiPhotons::passHadTowerOverEmCut(photon);
    photonInfo.passChIso        = ExoDiPhotons::passChargedHadronCut(photon);
    photonInfo.passCorPhoIso    = ExoDiPhotons::passCorPhoIsoHighPtID(photon,rho);
    photonInfo.passSieie        = ExoDiPhotons::passSigmaIetaIetaCut(photon,isSat);
    photonInfo.passHighPtID     = ExoDiPhotons::passHighPtID(photon,rho,isSat);

    // for fake rate
    photonInfo.passChIsoDenom     = ExoDiPhotons::passChargedHadronDenomCut(photon);
    photonInfo.passCorPhoIsoDenom = ExoDiPhotons::passCorPhoIsoDenom(photon,rho);
    photonInfo.isNumeratorObj     = ExoDiPhotons::passLooseNumeratorCut(photon,rho,isSat);
    photonInfo.isDenominatorObj   = ExoDiPhotons::passDenominatorCut(photon,rho,isSat);
  }

  void FillPhotonEGMidInfo(photonInfo_t &photonInfo, const pat::Photon *photon, double rho, EffectiveAreas eaCH, EffectiveAreas eaNH, EffectiveAreas eaPho)
  {
    double chEA  = eaCH.getEffectiveArea(fabs(photon->superCluster()->eta()));
    double nhEA  = eaNH.getEffectiveArea(fabs(photon->superCluster()->eta()));
    double phoEA = eaPho.getEffectiveArea(fabs(photon->superCluster()->eta()));
    
    photonInfo.chEAegmID   = chEA;
    photonInfo.nhEAegmID   = nhEA;
    photonInfo.phoEAegamID = phoEA;

    photonInfo.rhoCorChargedHadIso03 = std::max((double)0.0, (double)photon->chargedHadronIso()-rho*chEA);
    photonInfo.rhoCorNeutralHadIso03 = std::max((double)0.0, (double)photon->neutralHadronIso()-rho*nhEA);
    photonInfo.rhoCorPhotonIso03     = std::max((double)0.0, (double)photon->photonIso()       -rho*phoEA);
  }
  
} // end of namespace

#endif
