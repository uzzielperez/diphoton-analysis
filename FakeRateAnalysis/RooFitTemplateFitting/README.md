# Determining the fake rate

## Inputs
Inputs needed to determine fake rate:  
1. Histograms from data (numerator, denominator, and fake templates)  
2. Histograms from MC (real templates)

Inputs needed for closure test:  
1. Histograms from treating data as MC (numerator, denominator, and fake templates)  
2. Histograms from MC (real templates)

## Edit scripts to provide inputs
Edit these files to specify correct root files:
```
analysis/rooFitFakeRateProducer_pTBinLoop.C  
scripts/fakeRateCalculation.C
```

## Run code
```
cd analysis  
root ../scripts/fakeRateCalculation.C  
```

## Outputs
RooFit template fits and fake rate distributions:  
```
fakeRatePlots.root
```

## Fake rate function
