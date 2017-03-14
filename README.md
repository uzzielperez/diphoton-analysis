# EXO DiPhoton Analysis Code

## To build

```
# select cmssw environment
## bash
### 2015
export SCRAM_ARCH=slc6_amd64_gcc493  
export CMSSW_VERSION=CMSSW_7_6_4 
### 2016
export SCRAM_ARCH=slc6_amd64_gcc530  
export CMSSW_VERSION=CMSSW_8_0_25 
## tcsh
### 2015
setenv SCRAM_ARCH slc6_amd64_gcc493  
setenv CMSSW_VERSION CMSSW_7_6_4  
### 2016
setenv SCRAM_ARCH slc6_amd64_gcc530  
setenv CMSSW_VERSION CMSSW_8_0_25  

# setup cmssw release
cmsrel $CMSSW_VERSION  
cd $CMSSW_BASE/src  
cmsenv  

# clone repository
git clone git@github.com:cms-exotica-diphotons/diphoton-analysis  

# compile code
cd diphoton-analysis  
scram b -j 16
```
