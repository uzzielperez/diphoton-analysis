import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(50) )

# for input file
process.source = cms.Source(
    "PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:myfile.root'
        'root://cmsxrootd.fnal.gov//store/relval/CMSSW_7_6_2/JetHT/MINIAOD/76X_dataRun2_v15_rerecoGT_RelVal_jetHT2015D-v1/00000/4A19845F-EE9C-E511-9E4A-0025905964A6.root'
        )
    )

# for global tag
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = '76X_dataRun2_v15'

# geometry for saturation
process.load("Configuration.StandardSequences.GeometryDB_cff")

# for output file
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ExoDiphotonAnalyzer.root")
    )

# analyzer and inputs
process.demo = cms.EDAnalyzer(
    'ExoDiPhotonFakeRateAnalyzer',
    # photon tag
    photonsMiniAOD = cms.InputTag("slimmedPhotons"),
    # rho tag (use fixedGridRhoAll?)
    rho = cms.InputTag("fixedGridRhoFastjetAll")
    )

process.p = cms.Path(process.demo)
