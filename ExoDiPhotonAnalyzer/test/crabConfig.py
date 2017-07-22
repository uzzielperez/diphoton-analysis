from WMCore.Configuration import Configuration
config = Configuration()

#config.General.requestName = 'July2017_Diphoton_analysis'
#config.General.workArea = 'crab_diphoton_projects'

config.section_('General')
config.General.requestName = "DiphotonGGJets"
config.General.workArea = 'out_crab'
config.General.transferLogs = True

config.section_('JobType')
config.JobType.psetName = 'diphoton_cfg.py'
config.JobType.pluginName = 'Analysis'
#config.JobType.outputFiles = ['TriphotonAnalyzer.root']
#config.JobType.pyCfgParams = ['nEventsSample=' + str(nevents), 'outputFile=out_' + datasetID + '.root']

config.section_("Data")
#config.Data.inputDataset = dataset

config.JobType.pyCfgParams = ['noprint']
#config.section_('Data')
config.Data.inputDataset = '/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
config.Data.inputDBS = 'global'

config.Data.unitsPerJob = 100
config.Data.splitting = 'LumiBased'

#config.section_('User')
config.section_('Site')
#config.Site.blacklist = ['T0', 'T1']
config.Site.storageSite = 'T2_US_Nebraska'
