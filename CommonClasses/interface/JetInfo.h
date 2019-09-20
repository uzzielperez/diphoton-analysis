#ifndef JET_INFO_INC
#define JET_INFO_INC

#include "DataFormats/PatCandidates/interface/Jet.h"

namespace ExoDiPhotons
{
  // sort two jets by highest pt
  bool compareJetsByPt(const pat::Jet& jet1, const pat::Jet& jet2) {
    return(jet1.pt()>=jet2.pt());
  }

  struct jetInfo_t {
    float jetHT;
    float leadingJetPt;
    float leadingJetEta;
    float leadingJetPhi;
    float leadingJetMass;
    float secondleadingJetPt;
    float secondleadingJetEta;
    float secondleadingJetPhi;
    float secondleadingJetMass;
    float thirdleadingJetPt;
    float thirdleadingJetEta;
    float thirdleadingJetPhi;
    float thirdleadingJetMass;
    int nJets;
  };

  const std::string jetBranchDefString("jetHT/F:leadingJetPt:leadingJetEta:leadingJetPhi:leadingJetMass:secondleadingJetPt:secondleadingJetEta:secondleadingJetPhi:secondleadingJetMass:thirdleadingJetPt:thirdleadingJetEta:thirdleadingJetPhi:thirdleadingJetMass:nJets/I");

  void InitJetInfo(jetInfo_t &jetInfo) {
    jetInfo.jetHT = -99999.99;
    jetInfo.leadingJetPt = -99999.99;
    jetInfo.leadingJetEta = -99999.99;
    jetInfo.leadingJetPhi = -99999.99;
    jetInfo.leadingJetMass = -99999.99;
    jetInfo.secondleadingJetPt = -99999.99;
    jetInfo.secondleadingJetEta = -99999.99;
    jetInfo.secondleadingJetPhi = -99999.99;
    jetInfo.secondleadingJetMass = -99999.99;
    jetInfo.thirdleadingJetPt = -99999.99;
    jetInfo.thirdleadingJetEta = -99999.99;
    jetInfo.thirdleadingJetPhi = -99999.99;
    jetInfo.thirdleadingJetMass = -99999.99;
    jetInfo.nJets = (int) -99999.99;
  }


  void FillJetInfo(jetInfo_t &jetInfo, const edm::View<pat::Jet> *jets, double ptThreshold, double etaThreshold) {

    using namespace std;

    // make new jet collection where all jets pass pT and eta cuts
    std::vector<pat::Jet> goodJets;
    for (auto &j : *jets){
      double jetPt = j.pt();
      double jetAbsEta = fabs( j.eta() );
      if (jetPt > ptThreshold && jetAbsEta < etaThreshold ) goodJets.push_back(j);
    }

    // let std::sort do the work instead
    sort(goodJets.begin(),goodJets.end(),ExoDiPhotons::compareJetsByPt);

    // calculate jet HT
    float jetHT = 0.;
    for (auto &j : goodJets)
      jetHT += (float)j.pt();

    jetInfo.nJets = (int)goodJets.size();
    jetInfo.jetHT = jetHT;
    if (jetInfo.nJets >= 3){
      jetInfo.leadingJetPt = goodJets.at(0).pt();
      jetInfo.leadingJetEta = goodJets.at(0).eta();
      jetInfo.leadingJetPhi = goodJets.at(0).phi();
      jetInfo.leadingJetMass = goodJets.at(0).mass();
      jetInfo.secondleadingJetPt = goodJets.at(1).pt();
      jetInfo.secondleadingJetEta = goodJets.at(1).eta();
      jetInfo.secondleadingJetPhi = goodJets.at(1).phi();
      jetInfo.secondleadingJetMass = goodJets.at(1).mass();
      jetInfo.thirdleadingJetPt = goodJets.at(2).pt();
      jetInfo.thirdleadingJetEta = goodJets.at(2).eta();
      jetInfo.thirdleadingJetPhi = goodJets.at(2).phi();
      jetInfo.thirdleadingJetMass = goodJets.at(2).mass();

    }
    else if (jetInfo.nJets == 2){
      jetInfo.leadingJetPt = goodJets.at(0).pt();
      jetInfo.leadingJetEta = goodJets.at(0).eta();
      jetInfo.leadingJetPhi = goodJets.at(0).phi();
      jetInfo.leadingJetMass = goodJets.at(0).mass();
      jetInfo.secondleadingJetPt = goodJets.at(1).pt();
      jetInfo.secondleadingJetEta = goodJets.at(1).eta();
      jetInfo.secondleadingJetPhi = goodJets.at(1).phi();
      jetInfo.secondleadingJetMass = goodJets.at(1).mass();
    }
    else if (jetInfo.nJets == 1){
      jetInfo.leadingJetPt = goodJets.at(0).pt();
      jetInfo.leadingJetEta = goodJets.at(0).eta();
      jetInfo.leadingJetPhi = goodJets.at(0).phi();
      jetInfo.leadingJetMass = goodJets.at(0).mass();

    }

  } // end FillJetInfo method
  
}

#endif
