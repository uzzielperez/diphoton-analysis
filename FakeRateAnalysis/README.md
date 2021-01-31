# EXO DiPhoton Fake Rate Analysis Code

## Introduction

Offline analysis and plotting code used to determine the photon fake rate.

Inputs needed in pT bins:
1. Numerator distribution of template variable
2. Real templates
3. Fake templates using sideband definition
4. Denominator distribution

Numerator, denominator, and fake templates are determined from data, while real templates are determined from MC.

## Inputs from Data
See DataFakeRateAnalysis

## Inputs from MC
See MCFakeRateAnalysis

## Determining the fake rate
See RooFitTemplateFitting

## Closure test
See MCFakeRateClosureTest

### Full 2016/2017/2018 Closure Test Pipeline

Summary:
* Make Fake Templates, Real, MC Truth templates
* Run Template Fitting Code to get the fake rates
* Propagate Fake Rates to Kinematics Plots

To make templates

```
cmsenv
scram b
photon_closure_test.exe [2016/2017/2018] [QCD/GJets/GGJets/all] [fakes/truth]
```

See Templates

To run:

```
cd FakeRateAnalysis/ClosureTestTemplateFits
python plot_sidebands_comparisons.py -e 2016

```

To run RooFit Template Fitting:
```
# Output from previous step expected in CMSSW_BASE/src
mkdir plots
closure_test_rooFit.exe all sieie [2016/2017/2018] 0 200
```

To plot Fake Rate vs MC truth
```
# Output TGraphAsymmErrors expected in CMSSW_BASE/src
cd diphoton-analysis/FakeRateAnalysis/ClosureTestTemplateFits
root -l 'compareToMCTruth.C(2018)'
```

To plot reweighted kinematics
```
# Must rerun Template making code after fitting code to reweight
# Output templates expected in CMSSW_BASE/src
cd diphoton-analysis/FakeRateAnalysis/PhotonClosureTest/plots
root -l 'plot_kinematics_with_ratio.C("all", "2016")'
```


#### Legacy Fitting code
 See ClosureTestTemplateFit

 To run:

 ```
 # General use root -l 'fit.C(ERA)'
 root -l 'fit.C("2016")'

 ```
