# Fake Rate Closure Test

## Produce updated headers if necessary
If your ntuple tree structure has changed, run TTree::MakeClass():  
```
cd analysis  
root ../scripts/diphoton_makeClass.C  
```  
This script should point to one of the updated ntuples. 
Note: Do not overwrite the .C files in analysis directory (rename them first, then change them back after).
Edit the .h files so that Loop() take the following argument
```
virtual void Loop(const Char_t *);
```

## Merge ntuples
Merge ntuples (modify as needed):  
``` 
cd scripts  
./hadd_script.sh 
```  

## Trees
fTree is used for treating the MC as data  
fTreeFake is used for matching in the MC

## Produce historgrams
```
cd analysis  
./../scripts/bash_launcher.sh 
```

For a single binned MC sample run:  
```
cd analysis
# x = fTree or fTreeFake
root  
.L ../scripts/diphoton_x_looper.C  
diphoton_x_looper("300to470")  
```

## Outputs
Treading MC as data:  
diphoton_fakeRate_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root  
For matching:  
diphoton_fakeRate_matchedFakes_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root  
If desired, outputted histograms can be combined by running:
```
cd analysis  
root combine_mc_and_mc_matching_histograms_to_file.C
```

# Plots
In addition, to the closure test outputs, you need the real template outputs, outputs from data, and outputs from RooFit.  
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
  
