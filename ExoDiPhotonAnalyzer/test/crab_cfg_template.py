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
taskname = taskname.replace('RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14', 'Fall17_PU2017')
taskname = taskname.replace('RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15', 'Autumn18')
taskname = taskname.replace(':','___')
if(len(taskname)>100): taskname = taskname[0:99]

datasetID = dataset.replace('/','',1).replace('/', '_', 1)
datasetID = datasetID[0:datasetID.find('/')]

from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = taskname
config.General.workArea = 'out_crab'
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'diphoton-analysis/ExoDiPhotonAnalyzer/test/diphoton_cfg.py'
config.JobType.pyCfgParams = ['nEventsSample=' + str(nevents), 'outputFile=out_' + datasetID + '.root']

config.section_("Data")
config.Data.inputDataset = dataset
config.Data.inputDBS = 'global'
if user == "cawest":
    cmssw_base = os.environ['CMSSW_BASE']
    commit_hash = subprocess.check_output(['git', '--git-dir=' + cmssw_base + '/src/diphoton-analysis/.git',  'rev-parse', '--short', 'HEAD']).replace('\n', '')
    config.Data.outLFNDirBase = '/store/user/' + user + '/diphoton/' + commit_hash
else:
    config.Data.outLFNDirBase = '/store/user/ciperez/DiPhotonAnalysis/ExoANDiphoton'

if "Run2018" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 10
    if "Run2018D" in taskname:
        config.Data.unitsPerJob = 15
    config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions18/13TeV/ReReco/Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt'
elif "Run2017" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 100
    if "31Mar2018" in taskname:
        config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/ReReco/Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON_v1.txt'
    else:
        config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/PromptReco/Cert_294927-306126_13TeV_PromptReco_Collisions17_JSON.txt'
elif "Run2016" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 100
    if "Prompt" in taskname:
        config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions16/13TeV/Final/Cert_271036-284044_13TeV_PromptReco_Collisions16_JSON.txt'
    # otherwise, assume Re-Reco
    else:
        config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
elif "Run2015" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 100
    # only use 16Dec2015 ReReco
    config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/Reprocessing/Cert_13TeV_16Dec2015ReReco_Collisions15_25ns_JSON_Silver_v2.txt'
else:
    config.Data.splitting = 'FileBased'
    config.Data.unitsPerJob = 5

config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.blacklist = ['T1_RU_JINR', 'T2_US_Vanderbilt']
