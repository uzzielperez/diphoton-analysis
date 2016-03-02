#ifndef PFPHOTON_ID_INC
#define PFPHOTON_ID_INC

// for pat::Photons
#include "DataFormats/PatCandidates/interface/Photon.h"

namespace ExoDiPhotons{

    bool passesHadTowerOverEmCut(const pat::Photon* photon){

        double hOverE = photon->hadTowOverEm();
        
        // the cut value doesn't depend on eta
        if (hOverE < 0.05) return true;
        else return false;

    }

    // will write another method for the sideband cut, this is for the numerator
    bool passesChargedHadronCut(const pat::Photon* photon, double rhocorPFChargedHadronIso, bool forFakeRateDenom = false){

        double chIsoCut = 5.
        // the cut value doesn't depend on eta
        if (rhocorPFChargedHadronIso < chIsoCut && !forFakeRateDenom) return true;
        else if ( (rhocorPFChargedHadronIso < 5.*chIsoCut || rhocorPFChargedHadronIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
        else return false;

    }

    bool passesSigmaIetaIetaCut(const pat::Photon* photon, double full5x5SigmaIetaIeta, bool isSaturated){

        double scEta = fabs( photon->superCluster()->eta() );
        double sieieCut = -1.
        if (photon->isEB() && !isSaturated) sieieCut = 0.0105; 
        else if (photon->isEB() && isSaturated) sieieCut = 0.0112;
        else if (photon->isEE() && !isSaturated) sieieCut = 0.0280; 
        else if (photon->isEE() && isSaturated) sieieCut = 0.0300;

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
        else if ( (corPhoIso < 5.*chIsoCut || corPhoIso < 0.2*photon->pt()) && forFakeRateDenom ) return true;
        else return false;
        
        return pass;
    }

    bool passHighPtID(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){
        if (
            passesHadTowerOverEmCut(photon) &&
            passesChargedHadronCut(photon, chIso) &&
            passesSigmaIetaIetaCut(photon, sigIeIe) &&
            passCorPhoIsoHighPtID(photon,phoIso,rho) &&
            passCSEV
        ) return true;

        else return false;
    }


    bool passLooseNumeratorCut(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){

        if (
            passesHadTowerOverEmCut(photon) &&
            passesChargedHadronCut(photon, chIso) &&
            passCorPhoIsoHighPtID(photon,phoIso,rho) &&
            passCSEV
        ) return true;

        else return false;

    }

    bool passDenominatorCut(const pat::Photon* photon, double chIso, double phoIso, double sigIeIe, double rho, bool passCSEV, bool isSat){

        // first check if the photon fails at least one of the high pT ID cuts
        bool failID = !passHighPtID(photon,chIso,phoIso,sigIeIe,rho,passCSEV,isSat);

        // now check if it passes the looser ID
        bool passLooseIso = passesChargedHadronCut(photon, chIso, true) && passCorPhoIsoHighPtID(photon,phoIso,rho, true);

        if (failID && passLooseIso) return true;
        else return false;

    }

}