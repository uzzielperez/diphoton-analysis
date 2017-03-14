# EXO DiPhoton Analysis Code

## To build

```
# set architecture
## bash
### 2015
export SCRAM_ARCH=slc6_amd64_gcc493  
### 2016
export SCRAM_ARCH=slc6_amd64_gcc530  
## tcsh
### 2015
setenv SCRAM_ARCH slc6_amd64_gcc493  
### 2016
setenv SCRAM_ARCH slc6_amd64_gcc530  

# setup cmssw release
## 2015  
cmsrel CMSSW_7_6_4  
## 2016
cmsrel CMSSW_8_0_25  
cd $CMSSW_BASE/src
cmsenv  

# clone repository
git clone git@github.com:cms-exotica-diphotons/diphoton-analysis  

# compile code
cd diphoton-analysis  
scram b -j 16
```
