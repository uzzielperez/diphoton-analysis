## Template file for CRAB submission. The script generate_crab_config.py 
## replaces the following two lines with the appropriate values
## Do not edit manually!
dataset = 'DATASETNAME'
nevents = NEVENTS

# CRAB3 task names can no longer be greater than 100 characters; need to shorten task name
taskname = dataset[1:].replace('/','__').replace('RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2','MiniAODv2').replace('TuneCUETP8M1_13TeV-madgraphMLM-pythia8','13TeV-MG-PY8')
taskname = taskname.replace('RunIISpring15MiniAODv2-Asympt25ns_74X_mcRun2_asymptotic_v2','MiniAODv2')
taskname = taskname.replace('RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016','80XMiniAODv1')
taskname = taskname.replace(':','___')
if(len(taskname)>100): taskname = taskname[0:99]

datasetID = dataset.replace('/','',1).replace('/', '_', 1)
datasetID = datasetID[0:datasetID.find('/')]

from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = taskname
config.General.workArea = 'out_crab'
config.General.transferOutputs = True
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'diphoton-analysis/ExoDiPhotonMCFakeRateClosureTestAnalyzer/test/diphoton_mcFakeRateClosureTest_cfg.py'
config.JobType.pyCfgParams = ['nEventsSample=' + str(nevents), 'outputFileName=out_' + datasetID + '.root']

config.section_("Data")
config.Data.inputDataset = dataset
config.Data.inputDBS = 'global'
config.Data.outLFNDirBase = '/store/user/abuccill/DiPhotonAnalysis/FakeRateClosureTest'
config.Data.publication = False
if "Run2016" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 100
    config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions16/13TeV/Cert_271036-274421_13TeV_PromptReco_Collisions16_JSON.txt'
if "Run2015" in taskname:
    config.Data.splitting = 'LumiBased'
    config.Data.unitsPerJob = 100
    config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_Silver_v2.txt'
else:
    config.Data.splitting = 'FileBased'
    config.Data.unitsPerJob = 20


config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.blacklist = ['T1_RU_JINR']
