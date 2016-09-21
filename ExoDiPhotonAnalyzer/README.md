# EXO DiPhoton Analysis Code

## Instructions for background analyzer

## To run

```
cd ExoDiPhotonBackgroundAnalyzer/test  
cmsRun diphoton_background_cfg.py
```

## To submit CRAB jobs

If necessary to change the site to which the outputs should stage out, modify `config.Site.storageSite` in `ExoDiPhotonBackgroundAnalyzer/test/crab_cfg_template.py`. Then:

```
cd $CMSSW_BASE
source /cvmfs/cms.cern.ch/crab3/crab.sh
voms-proxy-init -voms cms -rfc
./ExoDiPhotonBackgroundAnalyzer/test/generate_crab_cfg.py
```

This will submit jobs to generate all 2015 data and MC ntuples.
