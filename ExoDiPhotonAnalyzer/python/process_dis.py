#!/usr/bin/env python
"""Process several files locally"""
import subprocess
import json
import os

doADD = True

DATASET = []
if doADD:
    DATASET.append("TestADD_NI-1_LambdaT-10000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-11000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-13000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-4000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-4500_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-5000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-5500_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-6000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-6500_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-7000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-7500_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-8000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-8500_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")
    DATASET.append("TestADD_NI-1_LambdaT-9000_M-1000_TuneCUEP8M1_13TeV_py_GEN.root")


for dset in DATASET:

    print 'Processing ', dset
    cmssw_base = os.getenv("CMSSW_BASE")
    templatefile = cmssw_base + "/src/multiphoton-analysis/nPhotonAnalyzer/python/cmsRun_cfg_template.py"
    ConfigFile = "cmsRun_cfg_" + dset + ".py"

    s = open(templatefile).read()
    s = s.replace('DATASETNAME', dset)
    f = open(ConfigFile, 'w')
    f.write(s)
    f.close()
    print "Wrote local configuration file ", ConfigFile

    cmd = "cmsRun " + ConfigFile
    os.system(cmd)
    print "Running ", dset
