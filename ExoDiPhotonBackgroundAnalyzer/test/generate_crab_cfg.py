#!/usr/bin/env python
"""Submit a set of crab jobs, passing the total number
of events in the sample as a parameter to CRAB so that
the event weight can be computed."""

import das_client as das
import json
import os

def get_number_of_events(dataset):
  """Get number of events for dataset from DAS"""
  query = "file dataset=" + dataset + " | sum(file.nevents)"

  data = das.get_data(query)
  if isinstance(data, basestring):
    dasjson = json.loads(data)
  else:
    dasjson = data
  status  = dasjson.get('status')
  if  status == 'ok':
    data = dasjson.get('data')
    sumevents = 0
    for idata in data:
      sumevents += idata.get('result').get('value')
    return sumevents

DATASETS = [[]]
# each entry contains a list of datasets, including extensions
# the extensions should be included so that the weight is calculated properly
# datasets with extensions should be added following this example:
#   datasets.append(["/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/MINIAODSIM",
#                   "/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring15MiniAODv2-Asympt25ns_74X_mcRun2_asymptotic_v2_ext1-v1/MINIAODSIM"])

# diphoton samples
DATASETS.append(["/GGJets_M-60To200_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-200To500_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
DATASETS.append(["/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])

for ilist in DATASETS:
  nevents = 0
  print ""
  for ids in ilist:
    nevents += get_number_of_events(ids)
    print "running nevents is " + str(nevents)

  for ids in ilist:
    cmssw_base = os.getenv("CMSSW_BASE")
    datasetID = ids.replace('/', '', 1).replace('/', '_', 1)
    datasetID = datasetID[0:datasetID.find('/')]
    inputfile = cmssw_base + "/src/diphoton-analysis/ExoDiPhotonBackgroundAnalyzer/test/crab_cfg_template.py"
    outputfile = "crab_cfg_" + datasetID + ".py"

    s = open(inputfile).read()
    s = s.replace('DATASETNAME', ids)
    s = s.replace('NEVENTS', str(nevents))
    f = open(outputfile, 'w')
    f.write(s)
    f.close()
    print "Wrote crab configuration file " + outputfile

    cmd = "crab submit -c " + outputfile
    os.system(cmd)
    print "Submitted ", ids

