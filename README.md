# EXO DiPhoton Analysis Code

## Instructions for Fake Rate Analyzer

export SCRAM_ARCH=slc6_amd64_gcc493 (bash)

cmsrel CMSSW_7_6_3_patch2  
cd CMSSW_7_6_3_patch2/src  
cmsenv  
git clone git@github.com:cms-exotica-diphotons/DiPhotonAnalysis  
cd DiPhotonAnalysis  
git checkout fakerate  
cd ExoDiPhotonFakeRateAnalyzer  
scram b -j 8  
