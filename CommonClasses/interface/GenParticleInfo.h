#ifndef GEN_PARTICLE_INFO
#define GEN_PARTICLE_INFO

namespace ExoDiPhotons
{
  struct genParticleInfo_t {
    // gen info
    int status;
    int motherStatus;
    int grandmotherStatus;
    int pdgId;
    int motherPdgId;
    int grandmotherPdgId;

    // kinematics
    double pt;
    double eta;
    double phi;
  };

  std::string genParticleBranchDefString("status/I:motherStatus:grandmotherStatus:pdgId:motherPdgId:grandmotherPdgId:pt/D:eta:phi");

  void InitGenParticleInfo(genParticleInfo_t &genParticleInfo) {
    // gen info
    genParticleInfo.status            = -999999;
    genParticleInfo.motherStatus      = -999999;
    genParticleInfo.grandmotherStatus = -999999;
    genParticleInfo.pdgId             = -999999;
    genParticleInfo.motherPdgId       = -999999;
    genParticleInfo.grandmotherPdgId  = -999999;

    // kinematics
    genParticleInfo.pt  = -999999.99;
    genParticleInfo.eta = -999999.99;
    genParticleInfo.phi = -999999.99;
  }

  void FillGenParticleInfo(genParticleInfo_t &genParticleInfo, const reco::GenParticle *genParticle) {
    // gen info
    genParticleInfo.status = genParticle->status();
    genParticleInfo.pdgId  = genParticle->pdgId();


    // gen info
    // mother and grandmother info
    double minMotherDeltaR      = 100000; // consider all mothers
    double minGrandmotherDeltaR = 100000;
    int motherIndex      = 0;
    int grandmotherIndex = 0;

    // if mother exists
    if (genParticle->numberOfMothers() > 0) {
      // find best match in deltaR among all mothers
      for (unsigned int j = 0; j < genParticle->numberOfMothers(); j++) {
	double deltaR = reco::deltaR(genParticle->eta(),genParticle->phi(),genParticle->mother(j)->eta(),genParticle->mother(j)->phi());
	if (deltaR < minMotherDeltaR) {
	  minMotherDeltaR = deltaR;
	  motherIndex = j;
	}
      }
      genParticleInfo.motherStatus = genParticle->mother(motherIndex)->status();
      genParticleInfo.motherPdgId  = genParticle->mother(motherIndex)->pdgId();

      // if grandMother exists
      if (genParticle->mother(motherIndex)->numberOfMothers() > 0) {
	// find best match in deltaR among all mothers
	for (unsigned int j = 0; j < genParticle->mother(motherIndex)->numberOfMothers(); j++) {
	  double deltaR = reco::deltaR(genParticle->mother(motherIndex)->eta(),genParticle->mother(motherIndex)->phi(),
				       genParticle->mother(motherIndex)->mother(j)->eta(),genParticle->mother(motherIndex)->mother(j)->phi());
	  if (deltaR < minGrandmotherDeltaR) {
	    minGrandmotherDeltaR = deltaR;
	    grandmotherIndex = j;
	  }
	}
	genParticleInfo.grandmotherStatus = genParticle->mother(motherIndex)->mother(grandmotherIndex)->status();
	genParticleInfo.grandmotherPdgId  = genParticle->mother(motherIndex)->mother(grandmotherIndex)->pdgId();
      }
      else {
	genParticleInfo.grandmotherStatus = -9999999;
	genParticleInfo.grandmotherPdgId  = -9999999;
      }
    }
    else {
      genParticleInfo.motherStatus      = -9999999;
      genParticleInfo.grandmotherStatus = -9999999;
      genParticleInfo.motherPdgId       = -9999999;
      genParticleInfo.grandmotherPdgId  = -9999999;
    }
    
    // kinematics
    genParticleInfo.pt  = genParticle->pt();
    genParticleInfo.eta = genParticle->eta();
    genParticleInfo.phi = genParticle->phi();

  }
  
}

#endif
