## Closure Test

### Make Templates

For list of commands.

```bash

create_templates_closure.py

```

The source code can be traced from `fake_templates_closure.cc`.
The real templates have to be produced separately using `real_templates.exe`.

### Fitting code

For testing, the following inputFiles are available:
* `diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root`
* `GJets_fakerate_2018_pV38-200_newDenomDef.root`


```bash

fit_histos_closure.py

```

The source code for the fitting code can be traced from `fit_closure_test.cc`.
