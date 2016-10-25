# EXO DiPhoton Analysis Code

## Instructions for EXO DiPhoton analyzer

## To run

```
cd ExoDiPhotonAnalyzer/test  
cmsRun diphoton_cfg.py inputFiles=file:filename.root
```
Where `filename.root` must contain a string that's matched to crossSection() in `CommonClasses/interface/CrossSections.h`.

## To submit CRAB jobs

If necessary to change the site to which the outputs should stage out, modify `config.Site.storageSite` in `ExoDiPhotonAnalyzer/test/crab_cfg_template.py`. Then:

```
cd $CMSSW_BASE
source /cvmfs/cms.cern.ch/crab3/crab.sh
voms-proxy-init -voms cms -rfc
./ExoDiPhotonAnalyzer/test/submit_crab_cfg.py
```

This will submit jobs to generate all 2015 data and MC ntuples.
