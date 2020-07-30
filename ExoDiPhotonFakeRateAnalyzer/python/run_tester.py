#!/usr/bin/env python
"""Process several files locally"""
import subprocess
import json
import os
import re

DATASET = []

xsecdict = {}
nevtsdict = {}

islocal = 'False'
isDAS = 'True' # Centrally Produced
# inputFile_ = '/store/mc/RunIIFall17MiniAODv2/GGJets_M-200To500_Pt-50_13TeV-sherpa/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/00000/FCBF2E5A-DC44-E811-984D-B496910A9790.root'
# inputFile_ = 'file:/uscms/home/cuperez/nobackup/tribosons/triphoton/CMSSW_10_3_0/src/GGJets_M-200To500_Pt-50_13TeV-sherpa_sample.root'
# outputFile_ = "GGJets_M-200To500_Pt-50_13TeV-sherpa_sampleOUT.root"
# nevts = 69803 # Found in DAS

cmssw_base = os.getenv("CMSSW_BASE")
#templatefile = cmssw_base + "/src/diphoton-analysis/FakeAnalyzer/python/cmsRun_cfg_phoEff_tester.py"


templatefile = cmssw_base + "/src/diphoton-analysis/ExoDiPhotonFakeRateAnalyzer/python/cmsRun_cfg_tester.py"
inputFile_ = 'file:'+cmssw_base+'/src/localDatasets/GGJets_M-60To200_Pt-50_13TeV-sherpa_RunIIFall17MiniAODv2.root'
outputFile_ = "GGJets_M-60To200_Pt-50_13TeV-sherpa_RunIIFall17MiniAODv2_FRNtuples.root"
nevts = 46815

# inputFile_ = 'file:'+ cmssw_base + '/src/localDatasets/GGJets_M60To200_Pt50_13TeV-sherpa_RunIIFall17MiniAODv2.root'
# outputFile_ = "GGJets_M60To200_Pt50_13TeV-sherpa_RunIIFall17MiniAODv2_FRNtuples.root"
nevts = 70000
xsec = 1.00
# xsec =  6.278e+00 #pb
print 'Processing ', inputFile_

ConfigFile = 'cmsRun_localNtuples.py'

#xsec = 99.8801 # pb #GGGJets

genParticles_ = "prunedGenParticles" # genParticles for GEN only
genInfo = "SIM"
#genInfo = "HLT"
# maxEvents_ = 10
idmode_ = "NOid"
# idmode_ = "highPTID"
# idmode_ = "MEDIUM" # LOOSE, MEDIUM or TIGHT
# idmode_ = "LOOSE"
# idmode_ = "TIGHT"


s = open(templatefile).read()
s = s.replace('ISLOCAL', islocal)
s = s.replace('ISDAS', isDAS)
s = s.replace('INPUTFILE', inputFile_)
s = s.replace('CROSSSECTION', str(xsec))
s = s.replace('NEVTS', str(nevts))
s = s.replace('GENPARTICLES', str(genParticles_))
s = s.replace('GENINFO', str(genInfo))
s = s.replace('OUTPUTFILE', str(outputFile_))
s = s.replace('IDMODE', str(idmode_))
f = open(ConfigFile, 'w')
f.write(s)
f.close()

print "Wrote local configuration file ", ConfigFile

cmd = "cmsRun " + ConfigFile
# cmd="cmsRun %s inputFiles=%s maxEvents=%d skipEvents=%d outputFile=%s"%(cfg,inputFiles_,maxEvents_,skipEvents_, outputFile_)
# cmd="cmsRun %s maxEvents=%d"%(ConfigFile, maxEvents_)

os.system(cmd)
