## Template file for CRAB submission. The script generate_crab_config.py 
## replaces the following two lines with the appropriate values
## Do not edit manually!
import os
import subprocess

dataset = 'DATASETNAME'
nevents = NEVENTS
user = os.environ['USER']

# CRAB3 task names can no longer be greater than 100 characters; need to shorten task name
taskname = dataset[1:].replace('/','__').replace('RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2','MiniAODv2').replace('TuneCUETP8M1_13TeV-madgraphMLM-pythia8','13TeV-MG-PY8')
taskname = taskname.replace('RunIISpring15MiniAODv2-Asympt25ns_74X_mcRun2_asymptotic_v2','MiniAODv2')
taskname = taskname.replace('RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016','80XMiniAODv1')
taskname = taskname.replace('RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1','80XMiniAODv2')
taskname = taskname.replace('RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2','80XMiniAODv2')
taskname = taskname.replace('RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1','80XMiniAODv2-ext1')
taskname = taskname.replace('RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2','80XMiniAODv2-ext1')
taskname = taskname.replace(':','___')
if(len(taskname)>100): taskname = taskname[0:99]

datasetID = dataset.replace('/','',1).replace('/', '_', 1)
datasetID = datasetID[0:datasetID.find('/')]

from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = taskname
config.General.workArea = 'out_crab_real_templates'
config.General.transferOutputs = True
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'diphoton-analysis/ExoDiPhotonMCFakeRateRealTemplateAnalyzer/test/diphoton_mcFakeRate_cfg.py'
config.JobType.pyCfgParams = ['nEventsSample=' + str(nevents), 'outputFile=out_' + datasetID + '.root']

config.section_("Data")
config.Data.inputDataset = dataset
config.Data.inputDBS = 'global'
config.Data.publication = False
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5
if user == "cawest":
    cmssw_base = os.environ['CMSSW_BASE']
    commit_hash = subprocess.check_output(['git', '--git-dir=' + cmssw_base + '/src/diphoton-analysis/.git',  'rev-parse', '--short', 'HEAD']).replace('\n', '')
    config.Data.outLFNDirBase = '/store/user/' + user + '/diphoton_fake/' + commit_hash



config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.blacklist = ['T1_RU_JINR']
