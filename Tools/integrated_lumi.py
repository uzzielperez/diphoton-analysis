#!/bin/env python
'''Output luminosity for 2015 and 2016 data samples.
   Note that this script only works on lxplus.'''
import os

# set PATH according to option 1 here: 
# http://cms-service-lumi.web.cern.ch/cms-service-lumi/brilwsdoc.html#prerequisite
os.environ["PATH"] = os.environ["HOME"] + "/.local/bin:/afs/cern.ch/cms/lumi/brilconda-1.1.7/bin:" + os.environ["PATH"]

CMD_BASE = "brilcalc lumi -u /fb"
NORMTAG_BASE = "/afs/cern.ch/user/l/lumipro/public/Normtags"
NORMTAGS = {'2015': NORMTAG_BASE + "/normtag_PHYSICS.json",
            '2016': NORMTAG_BASE + "/normtag_DATACERT.json"}

DATASETS = []
DATASETS.append('DoubleEG__Run2015C_25ns-16Dec2015-v1')
DATASETS.append('DoubleEG__Run2015D-16Dec2015-v2')

DATASETS.append('DoubleEG__Run2016B-03Feb2017_ver2-v2')
DATASETS.append('DoubleEG__Run2016C-03Feb2017-v1')
DATASETS.append('DoubleEG__Run2016D-03Feb2017-v1')
DATASETS.append('DoubleEG__Run2016E-03Feb2017-v1')
DATASETS.append('DoubleEG__Run2016F-03Feb2017-v1')
DATASETS.append('DoubleEG__Run2016G-03Feb2017-v1')
DATASETS.append('DoubleEG__Run2016H-03Feb2017_ver2-v1')
DATASETS.append('DoubleEG__Run2016H-03Feb2017_ver3-v1')
# pre-re-miniAOD
#DATASETS.append('DoubleEG__Run2016B-23Sep2016-v3')
#DATASETS.append('DoubleEG__Run2016C-23Sep2016-v1')
#DATASETS.append('DoubleEG__Run2016D-23Sep2016-v1')
#DATASETS.append('DoubleEG__Run2016E-23Sep2016-v1')
#DATASETS.append('DoubleEG__Run2016F-23Sep2016-v1')
#DATASETS.append('DoubleEG__Run2016G-23Sep2016-v1')
#DATASETS.append('DoubleEG__Run2016H-PromptReco-v2')
#DATASETS.append('DoubleEG__Run2016H-PromptReco-v3')

for dataset in DATASETS:
    json = "json/processedLumis_" + dataset + ".json"
    normtag = ''
    if '2015' in dataset:
        normtag = NORMTAGS['2015']
    if '2016' in dataset:
        normtag = NORMTAGS['2016']
    cmd = CMD_BASE + " --normtag " + normtag + " -i " + json
    print cmd
    os.system(cmd)
