##________________________________________________________________________________||

from WMCore.Configuration import Configuration
config = Configuration()

##________________________________________________________________________________||

config.section_('General')
#config.General.workArea        = 'DoubleEG_2015_Data'
config.General.transferOutputs = True

##________________________________________________________________________________||

config.section_('JobType')
config.JobType.psetName = 'diphoton_mcFakeRateClosureTest_cfg.py'
#config.JobType.pyCfgParams = ['globalTag=76X_dataRun2_16Dec2015_v0','useAOD=False']
config.JobType.pluginName = 'Analysis'
#config.JobType.inputFiles = ['PileupDataAug10thHistogram.root', 'PileUpMC.root', 'Cert_13TeV_16Dec2015ReReco_Collisions15_25ns_JSON_Silver_v2.txt']
#config.JobType.outputFiles = ['ExoDiPhotonAnalyzer.root']

##________________________________________________________________________________||

config.section_('Data')
#config.Data.inputDataset = '/QCD_Pt_20_30_EMEnriched_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM'
#config.Data.outputDatasetTag = ''
config.Data.inputDBS      = 'global'
config.Data.outLFNDirBase = '/store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD_EMEnriched'
config.Data.publication   = False
config.Data.unitsPerJob   = 5
#config.Data.totalUnits    = -1
config.Data.splitting     = 'FileBased'

##________________________________________________________________________________||

config.section_('User')

##________________________________________________________________________________||

config.section_('Site')
#config.Site.whitelist  = ["T0_CH_CERN_Disk"] 
config.Site.storageSite = 'T3_US_FNALLPC'

##________________________________________________________________________________||

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'crab_QCD_EMEnriched_ClosureTest_Jobs'

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "Failed submitting task: %s" % (cle)

    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################
    
    config.General.requestName = 'QCD_Pt-15to20_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-15to20_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)

    config.General.requestName = 'QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD'
    config.Data.inputDataset = '/QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
    submit(config)
