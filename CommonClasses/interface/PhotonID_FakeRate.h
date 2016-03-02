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
  
  
    bool passesHadTowerOverEmCut(const pat::Photon* photon){

        double hOverE = photon->hadTowOverEm();
        
        // the cut value doesn't depend on eta
        if (hOverE < 0.05) return true;
        else return false;

    }

    // will write another method for the sideband cut, this is for the numerator
    bool passesChargedHadronCut(const pat::Photon* photon, double rhocorPFChargedHadronIso, bool forFakeRateDenom = false){
      
      double chIsoCut = 5.;
        // the cut value doesn't depend on eta
        if (rhocorPFChargedHadronIso < chIsoCut && !forFakeRateDenom) return true;
        else if ( (rhocorPFChargedHadronIso < 5.*chIsoCut || rhocorPFChargedHadronIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
        else return false;

    }

    bool passesSigmaIetaIetaCut(const pat::Photon* photon, double full5x5SigmaIetaIeta, bool isSaturated){

        double phoEta = fabs( photon->superCluster()->eta() );
        double sieieCut = -1.;
        if (phoEta < 1.4442 && !isSaturated) sieieCut = 0.0105; 
        else if (phoEta < 1.4442 && isSaturated) sieieCut = 0.0112;
        else if (1.566 < phoEta && phoEta < 2.5 && !isSaturated) sieieCut = 0.0280; 
        else if (1.566 < phoEta && phoEta < 2.5 && isSaturated) sieieCut = 0.0300;

        if (full5x5SigmaIetaIeta < sieieCut) return true;
        else return false;

    }

      double alphaPhotonHighPtID(const pat::Photon *photon){

        double alpha = 0;

        // 1.560 or 1.566?
        if (fabs(photon->superCluster()->eta()) < 0.9)                                                    {alpha = 2.5;}
        if (0.9 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 1.4442 ) {alpha = 2.5;}
        if (1.560 < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.0 )    {alpha = 2.5;}
        if (2.0 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 2.2 )    {alpha = 2.5;}
        if (2.2 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 2.5 )    {alpha = 2.5;}

        return alpha;
      }

      double kappaPhotonHighPtID(const pat::Photon *photon){

        double kappa = 0;

        // 1.560 or 1.566?
        if (fabs(photon->superCluster()->eta()) < 0.9)                                                    {kappa = 0.0045;}
        if (0.9 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 1.4442 ) {kappa = 0.0045;}
        if (1.560 < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.0 )    {kappa = 0.0045;}
        if (2.0 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 2.2 )    {kappa = 0.0030;}
        if (2.2 < fabs(photon->superCluster()->eta())   && fabs(photon->superCluster()->eta()) < 2.5 )    {kappa = 0.0030;}

        return kappa;

      }



    std::vector<double> EffectiveAreas(const pat::Photon* photon){

        std::vector<double> effarea;
        effarea.reserve(3);

        double effareaCH = 0.;
        double effareaNH = 0.;
        double effareaPH = 0.;

          if (fabs(photon->superCluster()->eta()) < 0.9) 
                                {effareaPH = 0.17;}
          if (0.9   < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 1.4442) {effareaPH = 0.14;}
          if (1.560 < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.0)    {effareaPH = 0.11;}
          if (2.0   < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.2)    {effareaPH = 0.14;}
          if (2.2   < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.5)    {effareaPH = 0.22;}

        effarea.push_back(effareaCH);
        effarea.push_back(effareaNH);
        effarea.push_back(effareaPH);

        return effarea;
    }



    double corPhoIsoHighPtID(const pat::Photon* photon, double phoIso, double rho){
        std::vector<double> EA = EffectiveAreas(photon);
        double corPhoIso = alphaPhotonHighPtID(photon) + phoIso - rho*EA[2] - kappaPhotonHighPtID(photon)*photon->pt();
        
        return corPhoIso;
    }

    bool passCorPhoIsoHighPtID(const pat::Photon* photon, double phoIso, double rho, bool forFakeRateDenom = false){

        bool pass = false;
        double corPhoIsoCut = 0.;
        double corPhoIso = corPhoIsoHighPtID(photon, phoIso, rho);

        if (fabs(photon->superCluster()->eta()) < 1.4442) corPhoIsoCut = 2.75;
        if (1.560 < fabs(photon->superCluster()->eta()) && fabs(photon->superCluster()->eta()) < 2.5) corPhoIsoCut = 2.00;

        if (corPhoIso < corPhoIsoCut && !forFakeRateDenom) return true;
        else if ( (corPhoIso < 5.*corPhoIsoCut || corPhoIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
        else return false;
        
        return pass;
    }

    bool passHighPtID(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){
        if (
            passesHadTowerOverEmCut(photon) &&
            passesChargedHadronCut(photon,chIso) &&
            passesSigmaIetaIetaCut(photon,sigIeIe,isSat) &&
            passCorPhoIsoHighPtID(photon,phoIso,rho) &&
            passCSEV
        ) return true;

        else return false;
    }

    // must pass all cuts in the High pT ID except for the Sieie cut
    bool passLooseNumeratorCut(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){

        if (
            passesHadTowerOverEmCut(photon) &&
            passesChargedHadronCut(photon,chIso) &&
            passCorPhoIsoHighPtID(photon,phoIso,rho) &&
            passCSEV
        ) return true;

        else return false;

    }

    bool passDenominatorCut(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){

        // first check if the photon fails at least one of the high pT ID cuts
        bool failID = (
            !passesHadTowerOverEmCut(photon) ||
            !passesChargedHadronCut(photon, chIso) ||
            !passesSigmaIetaIetaCut(photon, sigIeIe, isSat) ||
            !passCorPhoIsoHighPtID(photon,phoIso,rho)
        ); // don't enforce electron veto; do this offline to study the veto's effect on the fake rate

        // now check if it passes the looser ID
        bool passLooseIso = passesChargedHadronCut(photon, chIso, true) && passCorPhoIsoHighPtID(photon,phoIso,rho, true);

        if (failID && passLooseIso) return true;
        else return false;

    }

}

#endif
