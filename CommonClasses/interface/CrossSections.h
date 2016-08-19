#ifndef CROSSSECTIONS_INC
#define CROSSSECTIONS_INC

namespace ExoDiPhotons {

  // provides cross sections (in pb) that are used to calculate event weights
  double crossSection(const TString& sample) {
    double xsec=-1.0;
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
    // cross sections and filter efficiencies from MCM
    if(sample.Contains("QCD_Pt-20to30_EMEnriched")) xsec = 557600000*0.0096; // filter efficiency error (MCM): 0.0003
    if(sample.Contains("QCD_Pt-30to50_EMEnriched")) xsec = 136000000*0.073; // filter efficiency error (MCM): 0.015
    if(sample.Contains("QCD_Pt-50to80_EMEnriched")) xsec = 19800000*0.146; // filter efficiency error (MCM): 0.021
    if(sample.Contains("QCD_Pt-80to120_EMEnriched")) xsec = 2800000*0.125; // filter efficiency error (MCM): 0.019
    if(sample.Contains("QCD_Pt-120to170_EMEnriched")) xsec = 477000*0.132; // filter efficiency error (MCM): 0.02
    if(sample.Contains("QCD_Pt-170to300_EMEnriched")) xsec = 114000*0.165; // filter efficiency error (MCM): 0.026
    if(sample.Contains("QCD_Pt-300toInf_EMEnriched")) xsec = 9000*0.15; // filter efficiency error (MCM): 0.036
    if(sample.Contains("QCD_Pt_5to10_TuneCUETP8M1")) xsec = 61018300000;
    if(sample.Contains("QCD_Pt_10to15_TuneCUETP8M1")) xsec = 5887580000;
    if(sample.Contains("QCD_Pt_15to30_TuneCUETP8M1")) xsec = 1837410000;
    if(sample.Contains("QCD_Pt_30to50_TuneCUETP8M1")) xsec = 140932000;
    if(sample.Contains("QCD_Pt_50to80_TuneCUETP8M1")) xsec = 19204300;
    if(sample.Contains("QCD_Pt_80to120_TuneCUETP8M1")) xsec = 2762530;
    if(sample.Contains("QCD_Pt_120to170_TuneCUETP8M1")) xsec = 471100;
    if(sample.Contains("QCD_Pt_170to300_TuneCUETP8M1")) xsec = 117276;
    if(sample.Contains("QCD_Pt_300to470_TuneCUETP8M1")) xsec = 7823;
    if(sample.Contains("QCD_Pt_470to600_TuneCUETP8M1")) xsec = 648.2;
    if(sample.Contains("QCD_Pt_600to800_TuneCUETP8M1")) xsec = 186.9;
    if(sample.Contains("QCD_Pt_800to1000_TuneCUETP8M1")) xsec = 32.293;
    if(sample.Contains("QCD_Pt_1000to1400_TuneCUETP8M1")) xsec = 9.4183;
    if(sample.Contains("QCD_Pt_1400to1800_TuneCUETP8M1")) xsec = 0.84265;
    if(sample.Contains("QCD_Pt_1800to2400_TuneCUETP8M1")) xsec = 0.114943;
    if(sample.Contains("QCD_Pt_2400to3200_TuneCUETP8M1")) xsec = 0.00682981;
    if(sample.Contains("QCD_Pt_3200toInf_TuneCUETP8M1")) xsec = 0.000165445;

    // cross sections from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SummaryTable1G25ns
    if(sample.Contains("WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) xsec = 405.271;
    if(sample.Contains("ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) xsec = 117.864;
    if(sample.Contains("TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8")) xsec = 3.697;
    if(sample.Contains("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) xsec = 1921.8*3;
    // MCM cross sections (NLO)
    if(sample.Contains("WToLNu_0J_13TeV-amcatnloFXFX-pythia8")) xsec = 5.844e+04; // +- 7.676e+01 pb
    if(sample.Contains("WToLNu_1J_13TeV-amcatnloFXFX-pythia8")) xsec = 1.128e+04; // +- 3.873e+02 pb
    if(sample.Contains("WToLNu_2J_13TeV-amcatnloFXFX-pythia8")) xsec = 2.544e+03; // +- 2.485e+02 pb
    // from https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO
    if(sample.Contains("TTJets_")) xsec = 815.96 ;
    // from running GenXsecAnalyzer on full sample
    if(sample.Contains("GGGJets_13TeV-sherpa")) xsec = 1.814e-01;
    
    // do not use weights for data
    
    if(sample.Contains("Run2015") || sample.Contains("Run2016")) xsec=1.0;

    if(xsec<0) throw cms::Exception("Could not determine cross section from output file name");

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

    // Madgraph5_aMC@NLO samples at NLO have a non-zero average weight
    // that should be removed, as well as negative weights
    if(sample.Contains("WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) average = 1.501086e+03*6.283186e-01;
    if(sample.Contains("ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) average = 3.479100e+02*7.019238e-01;
    if(sample.Contains("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8")) average = 2.344342e+04*6.286050e-01;
    if(sample.Contains("WToLNu_0J_13TeV-amcatnloFXFX-pythia8")) average = 7.143788e+04*8.534599e-01;
    if(sample.Contains("WToLNu_1J_13TeV-amcatnloFXFX-pythia8")) average = 9.293282e+04*5.323924e-01;
    if(sample.Contains("WToLNu_2J_13TeV-amcatnloFXFX-pythia8")) average = 7.667901e+04*3.120579e-01;
    if(sample.Contains("TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8")) average = 2.115439e+01*3.198633e-01;

    return average;
  }
}
#endif
