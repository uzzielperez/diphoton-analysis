#ifndef PHOTON_ID_FakeRate_INC
#define PHOTON_ID_FakeRate_INC

// for pat::Photons
#include "DataFormats/PatCandidates/interface/Photon.h"

// for saturation
#include "RecoCaloTools/Navigation/interface/CaloNavigator.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"

namespace ExoDiPhotons{

  // why is this needed? if(it != recHitsEB->end())
  // checking for saturated photons in 5x5 around seed crystal
  // considered saturated if any crystal is marked as saturated
  bool isSaturated(const pat::Photon *photon, const EcalRecHitCollection *recHitsEB, const EcalRecHitCollection *recHitsEE,
		   const CaloSubdetectorTopology* subDetTopologyEB_, const CaloSubdetectorTopology* subDetTopologyEE_) {
    using namespace std;
    
    bool isSat = false;
    DetId seedDetId = ((photon->superCluster())->seed())->seed();
    
    // check EB
    if (seedDetId.subdetId()==EcalBarrel) {
      CaloNavigator<DetId> cursor = CaloNavigator<DetId>(seedDetId,subDetTopologyEB_);
      for (int i = -2; i <= 2; ++i) {
      	for (int j = -2; j <= 2; ++j) {
      	  cursor.home();
      	  cursor.offsetBy(i,j);
      	  EcalRecHitCollection::const_iterator it = recHitsEB->find(*cursor);
      	  if(it != recHitsEB->end()) {
      	    cout << "Energy of (" << i << ", " << j << "): " << it-> energy()
      		 << ", kSaturated: " << it->checkFlag(EcalRecHit::kSaturated)
      		 << ", kDead: " << it->checkFlag(EcalRecHit::kDead)
      		 << ", kKilled: " << it->checkFlag(EcalRecHit::kKilled)
      		 << endl;
      	    if (it->checkFlag(EcalRecHit::kSaturated) && !it->checkFlag(EcalRecHit::kDead) && !it->checkFlag(EcalRecHit::kKilled)) {
      	      isSat = true;
      	    }
      	  }	  
      	}
      }
    }
    // check EE
    else if (seedDetId.subdetId()==EcalEndcap) {
      CaloNavigator<DetId> cursor = CaloNavigator<DetId>(seedDetId,subDetTopologyEE_);
      for (int i = -2; i <= 2; ++i) {
      	for (int j = -2; j <= 2; ++j) {
      	  cursor.home();
      	  cursor.offsetBy(i,j);
      	  EcalRecHitCollection::const_iterator it = recHitsEE->find(*cursor);
      	  if(it != recHitsEE->end()) {
      	    cout << "Energy of (" << i << ", " << j << "): " << it->energy()
      		 << ", kSaturated: " << it->checkFlag(EcalRecHit::kSaturated)
      		 << ", kDead: " << it->checkFlag(EcalRecHit::kDead)
      		 << ", kKilled: " << it->checkFlag(EcalRecHit::kKilled)
      		 << endl;
      	    if (it->checkFlag(EcalRecHit::kSaturated) && !it->checkFlag(EcalRecHit::kDead) && !it->checkFlag(EcalRecHit::kKilled)) {
      	      isSat = true;
      	    }
      	  }
      	}
      }
    }
    return isSat;
  }
  
  bool passHadTowerOverEmCut(const pat::Photon* photon) {

    double hOverE = photon->hadTowOverEm();
    
    // the cut value doesn't depend on eta
    if (hOverE < 0.05) return true;
    else return false;

  }

  // will write another method for the sideband cut, this is for the denominator
  bool passChargedHadronCut(const pat::Photon* photon, bool forFakeRateDenom) {

    double chIso = photon->chargedHadronIso();
    
    double chIsoCut = 5.;
    // the cut value doesn't depend on eta
    if (chIso < chIsoCut && !forFakeRateDenom) return true;
    else if ( (chIso < 5.*chIsoCut || chIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
    else return false;

  }

  bool passSigmaIetaIetaCut(const pat::Photon* photon, bool isSaturated) {

    double phoEta = fabs(photon->superCluster()->eta());
    double sIeIe = photon->sigmaIetaIeta();
    double sIeIeCut = -1.;
    
    if (phoEta < 1.4442 && !isSaturated) sIeIeCut = 0.0105; 
    else if (phoEta < 1.4442 && isSaturated) sIeIeCut = 0.0112;
    else if (1.566 < phoEta && phoEta < 2.5 && !isSaturated) sIeIeCut = 0.0280; 
    else if (1.566 < phoEta && phoEta < 2.5 && isSaturated) sIeIeCut = 0.0300;

    if (sIeIe < sIeIeCut) return true;
    else return false;

  }

  double phoAlphaHighPtID(const pat::Photon *photon) {
    
    double phoEta = fabs(photon->superCluster()->eta());
    
    if (phoEta < 1.4442) {
      if (phoEta < 0.9) {
	return 2.5;
      }
      else {
	return 2.5;
      }
    } // end EB
    
    else if (1.566 < phoEta && phoEta < 2.5) {
      if (phoEta < 2.0) {
	return 2.5;
      }
      else if (phoEta < 2.2) {
	return 2.5;
      }
      else {
	return 2.5;
      }
    } // end EE
    
    else {
      return 99999.99;
    }
    
  }
  
  double phoKappaHighPtID(const pat::Photon *photon) {
    
    double phoEta = fabs(photon->superCluster()->eta());
    
    if (phoEta < 1.4442) {
      if (phoEta < 0.9) {
	return 0.0045;
      }
      else {
	return 0.0045;
      }
    } // end EB
    
    else if (1.566 < phoEta && phoEta < 2.5) {
      if (phoEta < 2.0) {
	return 0.0045;
      }
      else if (phoEta < 2.2) {
	return 0.003;
      }
      else {
	return 0.003;
      }
    } // end EE
    
    else {
      return -99999.99;
    }
    
  }
  
  double phoEAHighPtID(const pat::Photon* photon) {
    
    double phoEta = fabs(photon->superCluster()->eta());
    
    if (phoEta < 1.4442) {
      if (phoEta < 0.9) {
	return 0.17;
      }
      else {
	return 0.14;
      }
    } // end EB
    
    else if (1.566 < phoEta && phoEta < 2.5) {
      if (phoEta < 2.0) {
	return 0.11;
      }
      else if (phoEta < 2.2) {
	return 0.14;
      }
      else {
	return 0.22;
      }
    } // end EE
    
    else {
      return -99999.99;
    }
    
  }
  
  double corPhoIsoHighPtID(const pat::Photon* photon, double rho) {

    double phoIso = photon->photonIso();
    
    return (phoAlphaHighPtID(photon) + phoIso - rho*phoEAHighPtID(photon) - phoKappaHighPtID(photon)*photon->pt());
    
  }

  bool passCorPhoIsoHighPtID(const pat::Photon* photon, double rho, bool forFakeRateDenom) {

    double phoEta = fabs(photon->superCluster()->eta());
    
    bool pass = false;
    double corPhoIsoCut = 0.;
    double corPhoIso = corPhoIsoHighPtID(photon,rho);

    if (phoEta < 1.4442) corPhoIsoCut = 2.75;
    if (1.560 < phoEta && phoEta < 2.5) corPhoIsoCut = 2.00;

    if (corPhoIso < corPhoIsoCut && !forFakeRateDenom) return true;
    else if ( (corPhoIso < 5.*corPhoIsoCut || corPhoIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
    else return false;
    
    return pass;
  }

  bool passHighPtID(const pat::Photon* photon, bool isSat, double rho, bool forFakeRateDenom) {
    if (
      passHadTowerOverEmCut(photon) &&
      passChargedHadronCut(photon,forFakeRateDenom) &&
      passSigmaIetaIetaCut(photon,isSat) &&
      passCorPhoIsoHighPtID(photon,rho,forFakeRateDenom) &&
      photon->passElectronVeto()
    ) return true;

    else return false;
  }

  // must pass all cuts in the High pT ID except for the Sieie cut
  bool passLooseNumeratorCut(const pat::Photon* photon, bool isSat, double rho, bool forFakeRateDenom) {

    if (
      passHadTowerOverEmCut(photon) &&
      passChargedHadronCut(photon,forFakeRateDenom) &&
      passCorPhoIsoHighPtID(photon,rho,forFakeRateDenom) &&
      photon->passElectronVeto()
    ) return true;

    else return false;

  }

  bool passDenominatorCut(const pat::Photon* photon, bool isSat, double rho, bool forFakeRateDenom) {

    // first check if the photon fails at least one of the high pT ID cuts
    bool failID = (
      !passHadTowerOverEmCut(photon) ||
      !passChargedHadronCut(photon,forFakeRateDenom) ||
      !passSigmaIetaIetaCut(photon,isSat) ||
      !passCorPhoIsoHighPtID(photon,rho,forFakeRateDenom)
    ); // don't enforce electron veto; do this offline to study the veto's effect on the fake rate

    // now check if it pass the looser ID
    bool passLooseIso = passChargedHadronCut(photon,true) && passCorPhoIsoHighPtID(photon,rho,true);

    if (failID && passLooseIso) return true;
    else return false;
    
  }
  
}

#endif
