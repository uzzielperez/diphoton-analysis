from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.section_('JobType')
config.JobType.psetName = 'ConfFile_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['TriphotonAnalyzer.root']
config.JobType.pyCfgParams = ['noprint']
config.section_('Data')
config.Data.inputDataset = '/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
config.Data.unitsPerJob = 50
config.Data.splitting = 'FileBased'
config.section_('User')
config.section_('Site')
#config.Site.blacklist = ['T0', 'T1']
#config.Site.storageSite = 'T2_US_Nebraska'
config.Site.storageSite = 'T3_US_FNALLPC'
