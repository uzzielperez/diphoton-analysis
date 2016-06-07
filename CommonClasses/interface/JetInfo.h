#ifndef JET_INFO_INC
#define JET_INFO_INC

#include "DataFormats/PatCandidates/interface/Jet.h"

namespace ExoDiPhotons
{

  struct jetInfo_t {
    float jetHT;
    float leadingJetPt;
    float leadingJetEta;
    float leadingJetPhi;
    float leadingJetMass;
    int nJets;
  };

  std::string jetBranchDefString("jetHT/F:leadingJetPt:leadingJetEta:leadingJetPhi:leadingJetMass:nJets/I");

  void InitJetInfo(jetInfo_t &jetInfo) {
    jetInfo.jetHT = -99999.99;
    jetInfo.leadingJetPt = -99999.99;
    jetInfo.leadingJetEta = -99999.99;
    jetInfo.leadingJetPhi = -99999.99;
    jetInfo.leadingJetMass = -99999.99;
    jetInfo.nJets = (int) -99999.99;
  }


  void FillJetInfo(jetInfo_t &jetInfo, const edm::View<pat::Jet> *jets, double ptThreshold, double etaThreshold) {
    int nJets = 0;
    float jetHT = 0.;
    float leadingPt = -1.;
    float leadingEta = -1.;
    float leadingPhi = -1.;
    float leadingMass = -1.;
    for (auto &j : *jets){
      double jetPt = j.pt();
      double jetAbsEta = fabs( j.eta() );
      if (jetPt > ptThreshold && jetAbsEta < etaThreshold ){
        nJets++;
        jetHT += (float)jetPt;
        // find the leading jet
        if (jetPt > leadingPt){
          leadingPt = (float)jetPt;
          leadingEta = (float)j.eta();
          leadingPhi = (float)j.phi();
          leadingMass = (float)j.mass();
        }
      } // end pT and eta condition on jets
    } // end loop over jets
    jetInfo.nJets = nJets;
    jetInfo.jetHT = jetHT;
    jetInfo.leadingJetPt = leadingPt;
    jetInfo.leadingJetEta = leadingEta;
    jetInfo.leadingJetPhi = leadingPhi;
    jetInfo.leadingJetMass = leadingMass;
  }
  
}

#endif
