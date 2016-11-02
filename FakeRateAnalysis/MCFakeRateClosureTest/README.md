# Fake Rate Closure Test

## Produce updated headers if necessary
If your ntuple tree structure has changed, run TTree::MakeClass():  
```
cd scripts  
./make_class.sh
```  
The macro `diphoton_makeClass.C` should point to one of the updated ntuples. 
Note: Do not overwrite the .C files in analysis directory.

## Merge ntuples
Merge ntuples (modify as needed):  
``` 
cd scripts  
./hadd_script.sh 
```  

## Trees
`fTree` is used for treating the MC as data  
`fTreeFake` is used for matching in the MC

## Produce historgrams
```
cd analysis  
root ../scripts/diphoton_looper.C
```

## Outputs
Treading MC as data:  
`diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root`  
For matching:  
`diphoton_fake_rate_closure_test_matching_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root`  
If desired, outputted histograms from these two files can be combined by running:
```
cd analysis  
root combine_fake_rate_histograms.C
```

# Plots
In addition to the closure test outputs, you need the real template outputs, outputs from data, and outputs from RooFit.  
Plot closure test:  
```
cd plots  
root -q -b plot_closure_test_fake_rate.C
```
Compare templates between data and MC:
```
cd plots  
root -q -b plot_fake_rate_template_comparison.C
```
Compare templates between different matching categories:
```
cd plots  
root -q -b plot_fake_matching_templates.C
```
  
