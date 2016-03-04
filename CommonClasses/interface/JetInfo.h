#ifndef JET_INFO_INC
#define JET_INFO_INC

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

  
  
}

#endif
