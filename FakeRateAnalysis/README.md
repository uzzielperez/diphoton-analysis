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

#### Plot templates comparison
See ClosureTestTemplateFit

To run:

```
python plot_sidebands_comparisons.py -e 2016

```
#### Legacy Fitting code
 See ClosureTestTemplateFit

 To run:

 ```
 # General use root -l 'fit.C(ERA)'
 root -l 'fit.C("2016")'

 ```

Template base are in $CMSSW_BASE/src

#### Kinematics

```

cd PhotonClosureTest/plots
# General use root -l 'plot_kinematics_with_ratio.C(samples, ERA)'
root -l 'plot_kinematics_with_ratio.C("all", "2018")'

```
