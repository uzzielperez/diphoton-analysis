# EXO DiPhoton Analysis Code

## To build

```
# select cmssw environment
## 2015 (bash syntax)
export SCRAM_ARCH=slc6_amd64_gcc493  
export CMSSW_VERSION=CMSSW_7_6_4 
## 2016 + 2017 (tcsh syntax)
setenv SCRAM_ARCH slc6_amd64_gcc630
setenv CMSSW_VERSION CMSSW_9_4_13
## 2018 (bash syntax)
export SCRAM_ARCH=slc6_amd64_gcc700
export CMSSW_VERSION=CMSSW_10_2_16

# setup cmssw release
cmsrel $CMSSW_VERSION  
cd $CMSSW_BASE/src  
cmsenv  

# clone repository
git clone git@github.com:cms-exotica-diphotons/diphoton-analysis  

# compile code
cd diphoton-analysis  
scram b -j 8
```

## For Pull Requests

Make sure to get the latest changes from the master branch and work from there.
```bash
 
 git clone git@github.com:uzzielperez/diphoton-analysis.git
 cd diphoton-analysis
 git remote add upstream git@github.com:cms-exotica-diphotons/diphoton-analysis.git
 git checkout master
 git pull upstream master # pull latest from master
 
 # check diff
 git diff -U0 --color remotes/upstream/master
 
 # to reset
 git reset --hard upstream/master
 
 git push origin master
 
 ```

