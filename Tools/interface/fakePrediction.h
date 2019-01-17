#ifndef FAKEPREDICTION_HH
#define FAKEPREDICTION_HH

// needed to get default implementations from base class
#define ntupleAnalyzerBase_cxx

//#include "ntupleAnalyzerBase.h"
//#include "ntupleAnalyzerBase2016.h"
//#include "ntupleAnalyzerBase2017.h"
#include "ntupleAnalyzerBase2018.h"

#include "TGraphAsymmErrors.h"

// this is not defined in default MakeClass headers
// and so it needs a definition to avoid compilation errors
void ntupleAnalyzerBase::Loop() {};

class fakePrediction : public ntupleAnalyzerBase {

  bool isBarrelBarrel(double eta1, double eta2);
  bool isBarrelEndcap(double eta1, double eta2);

 public:
  using ntupleAnalyzerBase::ntupleAnalyzerBase;
  void Loop(int year, const std::string&);
  void setIsMC(bool mc) { isMC = mc; };
  bool isMC;
  void fakeRateInit(int year, std::string fakeRateType);
  double getFakeRate(double pt, int region);
 private:
  std::map<std::string, TGraphAsymmErrors*> m_fakeRates;
  std::string m_fakeRateType;
};

#endif
