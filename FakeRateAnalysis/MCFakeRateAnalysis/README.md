# MC Fake Rate Analysis

## Scripts

Merge ntuples from scripts directory:  
./hadd_script.sh

Make class from analysis directory:  
root ../scripts/diphoton_makeClass.C

Chain ntuples from each root file to loop over from analysis directory:  
root ../scripts/diphoton_chain_looper.C

Run over individual root files from analysis directory:  
root  
.L ../scripts/diphoton_tree_looper.C++ (to compile, if desired)  
diphoton_tree_looper("1000To2000")  

Run over all root files from analysis directory:  
./../scripts/bash_launcher.sh


## Cross sections
analysis/GGJets_Pt-50_13TeV-sherpa_cross_sections_and_events.txt

All events were taken from DAS. The cross sections for all were taken from AN-15-241, expect for  
M-60To200 and M-200To500, where were taken from GenXsecAnalyzer, but using the result from only  
one CRAB job without considering the error.