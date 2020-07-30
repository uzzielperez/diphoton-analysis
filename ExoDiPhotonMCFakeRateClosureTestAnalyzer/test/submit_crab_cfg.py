#!/usr/bin/env python
"""Submit a set of crab jobs, passing the total number
of events in the sample as a parameter to CRAB so that
the event weight can be computed."""

import subprocess
import json
import os

import importlib
das_utils = importlib.import_module("diphoton-analysis.CommonClasses.das_utils")
submit_utils = importlib.import_module("diphoton-analysis.CommonClasses.submit_utils")

do_2015_QCD = False
do_2015_GJets = False
do_2015_GGJets = False
do_2016_GJets = False
do_2016_GGJets = False
do_2017_GJets = False
do_2017_GGJets = False
do_2018_GJets = False
do_2018_GGJets = True

DATASETS = [[]]
# each entry contains a list of datasets, including extensions
# the extensions should be included so that the weight is calculated properly
# datasets with extensions should be added following this example:
#   datasets.append(["/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM",
#                   "/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-Asympt25ns_74X_mcRun2_asymptotic_v2_ext1-v1/MINIAODSIM"])

if do_2015_QCD:
  DATASETS.extend(submit_utils.get_dataset_list('2015_QCD'))
if do_2015_GGJets:
  DATASETS.extend(submit_utils.get_dataset_list('2015_GGJets'))
if do_2015_GJets:
  DATASETS.extend(submit_utils.get_dataset_list('2015_GJets'))
if do_2016_GGJets:
  DATASETS.extend(submit_utils.get_dataset_list('2016_GGJets'))
if do_2016_GJets:
  DATASETS.extend(submit_utils.get_dataset_list('2016_GJets'))
if do_2017_GGJets:
  DATASETS.extend(submit_utils.get_dataset_list('2017_GGJets'))
if do_2017_GJets:
  DATASETS.extend(submit_utils.get_dataset_list('2017_GJets'))
if do_2018_GGJets:
  DATASETS.extend(submit_utils.get_dataset_list('2018_GGJets'))
if do_2018_GJets:
  DATASETS.extend(submit_utils.get_dataset_list('2018_GJets'))

for ilist in DATASETS:
  nevents = 0
  print ""
  for ids in ilist:
    nevents += das_utils.get_number_of_events(ids)
    print("running nevents is " + str(nevents))

  for ids in ilist:
    cmssw_base = os.getenv("CMSSW_BASE")
    datasetID = ids.replace('/', '', 1).replace('/', '_', 1)
    datasetID = datasetID[0:datasetID.find('/')]
    inputfile = cmssw_base + "/src/diphoton-analysis/ExoDiPhotonMCFakeRateClosureTestAnalyzer/test/crab_cfg_template.py"
    outputfile = "crab_cfg_" + datasetID + ".py"

    s = open(inputfile).read()
    s = s.replace('DATASETNAME', ids)
    s = s.replace('NEVENTS', str(nevents))
    f = open(outputfile, 'w')
    f.write(s)
    f.close()
    print("Wrote crab configuration file " + outputfile)

    cmd = "crab submit -c " + outputfile
#    os.system(cmd)
    print "Submitted ", ids

