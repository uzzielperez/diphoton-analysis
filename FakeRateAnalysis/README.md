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

### The Closure Test in steps
1. Testing the Fake Template Derived using the Sideband Definition <br>

Create the fake and denominator templates.
```bash

cd PhotonClosureTest/scripts
root -l diphoton_looper.C

```
Create the real templates.

```bash

cd RealTemplateAnalysis/scripts
root -l diphoton_looper.C

```
Create MCtruth info templates. 
```bash

cd RealTemplateAnalysis/scripts
root -l diphoton_looper.C

```

The binning and the histograms are defined in analysis/ directory.
