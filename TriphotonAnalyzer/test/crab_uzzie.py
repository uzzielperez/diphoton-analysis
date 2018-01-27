from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = "GGJets_M_500To1000_Pt_50_13TeV_sherpa_80X_MiniAODv2"
config.General.workArea = 'out_crab'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ConfFile_cfg.py'

config.section_("Data")
config.Data.outLFNDirBase = '/store/user/ciperez/DiPhotonAnalysis'

config.Data.inputDataset = "/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5
config.Data.publication = False

config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.blacklist = ['T1_RU_JINR', 'T2_US_Vanderbilt']
