# runtime options
import FWCore.ParameterSet.Config as cms
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
from FWCore.ParameterSet.VarParsing import VarParsing
from os.path import basename
import os
import importlib
submit_utils = importlib.import_module("multiphoton-analysis.CommonClasses.submit_utils")

#Configure
isMC           = True
islocal        = bool(False)
isDAS          = bool(True)

inputFile = 'file:/uscms_data/d3/cuperez/tribosons/CMSSW_10_2_10/src/localDatasets/GGGJets_TuneCUETP8M1_13TeV_madgraphMLM_pythia8_spring.root'
outName = 'GGGJets_TuneCUETP8M1_13TeV_madgraphMLM_pythia8_RunIIFall17MiniAODv2_PhotonEfficiency.root'

#------------------------------------------
print 'Configuration file Run with the following settings: '
print 'isMC = ', isMC
if islocal:
    print 'Pythia GEN'
if isDAS:
    print 'DAS GEN'
print 'processing ', inputFile
print 'Writing output to file ', outName
#------------------------------------------

options = VarParsing ('python')
options.register('nEventsSample',
                 #61125, #100,
                 70000,
                 VarParsing.multiplicity.singleton,
                 VarParsing.varType.int,
                 "Total number of events in dataset for event weight calculation.")

# options.parseArguments()
print 'nEventsSample: ', options.nEventsSample
process = cms.Process("Demo")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #'file:myfile.root'
        #'file:/afs/cern.ch/user/c/ciperez/Generation/CMSSW_9_3_8/src/ADDGravToGG_NED-4_LambdaT-4000_M-500_13TeV-pythia8_cff_py_GEN.root'
        inputFile
    )
)


# for global tag
globalTag = submit_utils.get_global_tag(outName)
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = globalTag
print("Using global tag: " + globalTag)

process.load("FWCore.MessageService.MessageLogger_cfi")


# geometry for saturation
process.load("Configuration.StandardSequences.GeometryDB_cff")

# Setup JEC
reapplyJEC = False #Jet Energy Corrections
jetCollection = "slimmedJets"
JEC = cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual'])
if reapplyJEC:
    jetCollection = "updatedPatJetsUpdatedJEC"
isMC = True
# data always has "Run201" in its filename
if "Run201" in outName:
    isMC = False
# override options for MC
if isMC:
    JEC = cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute'])

# geometry for saturation
process.load("Configuration.StandardSequences.GeometryDB_cff")

# for output file
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string(outName)
    )

## update AK4PFchs jet collection in MiniAOD JECs
from PhysicsTools.PatAlgos.tools.jetTools import updateJetCollection

updateJetCollection(
   process,
   jetSource = cms.InputTag('slimmedJets'),
   labelName = 'UpdatedJEC',
   jetCorrections = ('AK4PFchs', JEC, 'None')  # Do not forget 'L2L3Residual' on data!
)

jetLabel = "updatedPatJetsUpdatedJEC"

# summary of information needed for e/gamma corrections
egm_info = submit_utils.egamma_info(outName)
setupEgammaPostRecoSeq(process,
                       applyEnergyCorrections=True,
                       applyVIDOnCorrectedEgamma=True,
                       runVID=True,
                       runEnergyCorrections=True,
                       era=egm_info['era'])
print egm_info

# analyzer and inputs
process.demo = cms.EDAnalyzer(
    'FakeAnalyzer',
    # photon tag
    photonsMiniAOD = cms.InputTag("slimmedPhotons"),
    # ak4 jets
    jetsMiniAOD = cms.InputTag(jetCollection),
    jetPtThreshold = cms.double(30.),
    jetEtaThreshold = cms.double(2.5),
    # rho tag
    rho = cms.InputTag("fixedGridRhoAll"),
    # EGM eff. areas
    # effAreaChHadFile = cms.FileInPath(egm_info['effAreaChHad']),
    # effAreaNeuHadFile = cms.FileInPath(egm_info['effAreaNeuHad']),
    # effAreaPhoFile = cms.FileInPath(egm_info['effAreaPhoHad']),
    # EGM ID decisions
    # phoLooseIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['loosePhoId']),
    # phoMediumIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['mediumPhoId']),
    # phoTightIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['tightPhoId']),
    # output file name
    outputFile = cms.string(outName),
    isReMINIAOD = cms.bool(True)
    )

process.p = cms.Path(process.egammaPostRecoSeq * process.demo)
# if reapplyJEC:
#     process.p = cms.Path(process.egammaPostRecoSeq * process.patJetCorrFactorsUpdatedJEC * process.updatedPatJetsUpdatedJEC * process.demo)
# else:
#     process.p = cms.Path(process.egammaPostRecoSeq * process.demo)
