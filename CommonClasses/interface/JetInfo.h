#ifndef JET_INFO_INC
#define JET_INFO_INC

#include "DataFormats/PatCandidates/interface/Jet.h"

namespace ExoDiPhotons
{

  struct jetInfo_t {
    float jetHT;
    int nJets;
  };

  std::string jetBranchDefString("jetHT/F:nJets/I");

  void InitJetInfo(jetInfo_t &jetInfo) {
    jetInfo.jetHT = -99999.99;
    jetInfo.nJets = (int) -99999.99;
  }


  void FillJetInfo(jetInfo_t &jetInfo, const edm::View<pat::Jet> *jets, double ptThreshold, double etaThreshold) {
    int nJets = 0;
    double jetHT = 0.;
    for (auto &j : *jets){
      double jetPt = j.pt();
      double jetEta = fabs( j.eta() );
      if (jetPt > ptThreshold && jetEta < etaThreshold ){
	nJets++;
	jetHT += jetPt;
      }
    }
    jetInfo.nJets = nJets;
    jetInfo.jetHT = jetHT;
  }
  
}

#endif
