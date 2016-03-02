#ifndef PHOTON_INFO_FAKERATE_INC
#define PHOTON_INFO_FAKERATE_INC

#include "DataFormats/PatCandidates/interface/Photon.h"

namespace ExoDiPhotons
{
  struct photonInfo_t {
    double pt;
    double eta;
    double phi;
    double scEta;
    double scPhi;
  };

  std::string photonBranchDefString("pt/D:eta:phi:scEta:scPhi");

  void FillPhotonInfo(photonInfo_t &photonInfo, const pat::Photon *photon)
  {
    photonInfo.pt = photon->pt();
    photonInfo.eta = photon->eta();
    photonInfo.phi = photon->phi();
    photonInfo.scEta = photon->superCluster()->eta();
    photonInfo.scPhi = photon->superCluster()->phi();
  }

  void InitPhotonInfo(photonInfo_t &photonInfo)
  {
    photonInfo.pt = -9999.99;
    photonInfo.eta = -9999.99;
    photonInfo.phi = -9999.99;
    photonInfo.scEta = -9999.99;
    photonInfo.scPhi = -9999.99;
  }

} // end of namespace

#endif
