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

For testing, the following inputFiles are available in `/store/user/cuperez`:
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

Currently crashes with error messages:
```bash

Starting Closure test code...

Using template variable: sieie
Opening Fake Template File: GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root
Fake Template source: GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root
Real Template source: diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Starting rooFitFakeRateProducer
Using GGJets, sieie, EB, pt 50To70, 5 < sideband < 10
Processing: root://cmseos.fnal.gov//store/user/cuperez/GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root

Opening Data Template File: root://cmseos.fnal.gov//store/user/cuperez/GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root
Error in <TFile::Open>: no url specified

Opening Real MC Template File: root://cmseos.fnal.gov//store/user/cuperez/diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root
Getting sieieEB_faketemplate_pt50To70_chIso5To10
TFile: name=root://cmseos.fnal.gov//store/user/cuperez/GGJets_fakerate_closuretest_2018_pV0-200_newDenomDef.root, title=, option=READ

 *** Break *** segmentation violation

 ```
