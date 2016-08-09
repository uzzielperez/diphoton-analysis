#ifndef CROSSSECTIONS_INC
#define CROSSSECTIONS_INC

namespace ExoDiPhotons {

  // provides cross sections that are used to calculate event weights
  double crossSection(const TString& sample) {
    double xsec=1.0;
    if(sample.Contains("GGJets_M-60To200_Pt-50_13TeV-sherpa")) xsec = 5.785e+00;
    if(sample.Contains("GGJets_M-200To500_Pt-50_13TeV-sherpa")) xsec = 2.244e+00;
    if(sample.Contains("GGJets_M-500To1000_Pt-50_13TeV-sherpa")) xsec = 1.510e-01;
    if(sample.Contains("GGJets_M-1000To2000_Pt-50_13TeV-sherpa")) xsec = 1.084e-02;
    if(sample.Contains("GGJets_M-2000To4000_Pt-50_13TeV-sherpa")) xsec = 3.690e-04;
    if(sample.Contains("GGJets_M-4000To6000_Pt-50_13TeV-sherpa")) xsec = 2.451e-06;
    if(sample.Contains("GGJets_M-6000To8000_Pt-50_13TeV-sherpa")) xsec = 1.753e-08;
    if(sample.Contains("GGJets_M-8000To13000_Pt-50_13TeV-sherpa")) xsec = 7.053e-11;
    // cross sections from Table 2 of AN2015_241
    if(sample.Contains("GJets_HT-40To100")) xsec = 2.121e+04;
    if(sample.Contains("GJets_HT-100To200")) xsec = 9.863e+03;
    if(sample.Contains("GJets_HT-200To400")) xsec = 2.298e+03;
    if(sample.Contains("GJets_HT-400To600")) xsec = 2.816e+02;
    if(sample.Contains("GJets_HT-600ToInf")) xsec = 9.465e+01;
    
    // do not use weights for data
    
    if(sample.Contains("Run2015") || sample.Contains("Run2016")) xsec=1.0;

    std::cout << "Using cross section " << xsec << " for sample " << sample << std::endl;
    
    return xsec;
  }

  double averageWeight(const TString& sample) {
    double average=1.0;

    // average weight is non-zero for these samples because 
    // of the njet weighting in Sherpa
    if(sample.Contains("GGJets_M-60To200_Pt-50_13TeV-sherpa")) average = 3.895719e-01;
    if(sample.Contains("GGJets_M-200To500_Pt-50_13TeV-sherpa")) average = 2.818643e-01;
    if(sample.Contains("GGJets_M-500To1000_Pt-50_13TeV-sherpa")) average = 2.094533e-01;
    if(sample.Contains("GGJets_M-1000To2000_Pt-50_13TeV-sherpa")) average = 1.749053e-01;
    if(sample.Contains("GGJets_M-2000To4000_Pt-50_13TeV-sherpa")) average = 1.638999e-01;
    if(sample.Contains("GGJets_M-4000To6000_Pt-50_13TeV-sherpa")) average = 1.673106e-01;
    if(sample.Contains("GGJets_M-6000To8000_Pt-50_13TeV-sherpa")) average = 1.816810e-01;
    if(sample.Contains("GGJets_M-8000To13000_Pt-50_13TeV-sherpa")) average = 1.972643e-01;

    return average;
  }
}
#endif
