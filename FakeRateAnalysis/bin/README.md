## Closure Test

### Make Templates

For list of commands.

```bash

create_templates_closure.py

```

The source code can be traced from `fake_templates_closure.cc`.
The real templates have to be produced separately using `real_templates.exe`.

### Fitting code

As of 08/11/20:

For testing, we use the following input files for now:
* `diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root`
* `GJets_fakerate_2018_pV38-200_newDenomDef.root`


```bash

cmsrel CMSSW_10_2_18
cd CMSSW_10_2_18/src
cmsenv
scram b -j 16
python diphoton-analysis/FakeRateAnalysis/bin/fit_histos_closure.py
fit_closure_test.exe GGJets sieie 2018 0 200
```
