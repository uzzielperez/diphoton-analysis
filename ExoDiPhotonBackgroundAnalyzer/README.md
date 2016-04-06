# EXO DiPhoton Analysis Code

## Instructions for background analyzer

## To build

export SCRAM_ARCH=slc6_amd64_gcc493 (bash)  
setenv SCRAM_ARCH slc6_amd64_gcc493 (tcsh)

cmsrel CMSSW_7_6_3_patch2  
cd CMSSW_7_6_3_patch2/src  
cmsenv  
git clone git@github.com:cms-exotica-diphotons/diphoton-analysis  
cd diphoton-analysis   
cd ExoDiPhotonBackgroundAnalyzer  
scram b -j 8  

## To run

cd ExoDiPhotonBackgroundAnalyzer/test  
cmsRun diphoton_background_cfg.py