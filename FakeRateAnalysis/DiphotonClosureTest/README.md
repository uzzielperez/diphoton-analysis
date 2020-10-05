# For Analysis Note

To produce templates:

```

#default
`root -l diphoton_looper.C`

```

```

# default 2016 and all samples (QCD, GJets, GGJets)
`root -l diphoton_looper.C`

# plotting code currently set up to read from CMSSW_BASE/src

mv diphoton_fake_rate_diphoton_closure_test_all_samples_76X_MiniAOD_histograms.root $CMSSW_BASE/src

```

For plots

```
cd plots
root -l plot_diphoton_closure_test_with_ratio.C # Default 'all', era = "2016"

# To specify sample and era
root -l 'plot_diphoton_closure_test_with_ratio.C("all", "2016")'
```
