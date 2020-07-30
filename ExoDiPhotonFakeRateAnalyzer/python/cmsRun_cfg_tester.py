# runtime options
import FWCore.ParameterSet.Config as cms
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
from FWCore.ParameterSet.VarParsing import VarParsing
from os.path import basename
import os
import importlib
submit_utils = importlib.import_module("diphoton-analysis.CommonClasses.submit_utils")

inputFile = 'INPUTFILE'
outName = 'OUTPUTFILE'

#------------------------------------------
print 'Configuration file Run with the following settings: '
print 'processing ', inputFile
print 'Writing output to file ', outName
#------------------------------------------

options = VarParsing ('python')
options.parseArguments()

options.register('nEventsSample',
                 #61125, #100,
                 NEVTS,
                 VarParsing.multiplicity.singleton,
                 VarParsing.varType.int,
                 "Total number of events in dataset for event weight calculation.")

process = cms.Process("ExoDiPhoton")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )



# for global tag
globalTag = submit_utils.get_global_tag(outName)
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = globalTag
print("Using global tag: " + globalTag)

process.load("FWCore.MessageService.MessageLogger_cfi")

globalTag = submit_utils.get_global_tag(outName)

reapplyJEC = False
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

process.load("FWCore.MessageService.MessageLogger_cfi")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( options.maxEvents ) )

# for input file
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        inputFile
    )
)

# for global tag
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = globalTag
print("Using global tag: " + globalTag)

# geometry for saturation
process.load("Configuration.StandardSequences.GeometryDB_cff")

# for output file
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ExoDiphotonAnalyzer.root")
    )
## update AK4PFchs jet collection in MiniAOD JECs

from PhysicsTools.PatAlgos.tools.jetTools import updateJetCollection

updateJetCollection(
   process,
   jetSource = cms.InputTag('slimmedJets'),
   labelName = 'UpdatedJEC',
   jetCorrections = ('AK4PFchs', JEC, 'None')  # Do not forget 'L2L3Residual' on data!
)

# summary of information needed for e/gamma corrections
egm_info = submit_utils.egamma_info(outName)
setupEgammaPostRecoSeq(process,
                       applyEnergyCorrections=True,
                       applyVIDOnCorrectedEgamma=True,
                       runVID=True,
                       runEnergyCorrections=True,
                       era=egm_info['era'])
# analyzer and inputs
process.diphoton = cms.EDAnalyzer(
    'ExoDiPhotonFakeRateAnalyzer',
    # photon tag
    photonsMiniAOD = cms.InputTag("slimmedPhotons"),
    # ak4 jets
    jetsMiniAOD = cms.InputTag(jetCollection),
    jetPtThreshold = cms.double(30.),
    jetEtaThreshold = cms.double(2.5),
    # rho tag
    rho = cms.InputTag("fixedGridRhoAll"),
    # EGM eff. areas
    effAreaChHadFile = cms.FileInPath(egm_info['effAreaChHad']),
    effAreaNeuHadFile = cms.FileInPath(egm_info['effAreaNeuHad']),
    effAreaPhoFile = cms.FileInPath(egm_info['effAreaPhoHad']),
    # EGM ID decisions
    phoLooseIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['loosePhoId']),
    phoMediumIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['mediumPhoId']),
    phoTightIdMap = cms.InputTag("egmPhotonIDs:" + egm_info['tightPhoId']),
    # output file name
    outputFile = cms.string(outName),
    isReMINIAOD = cms.bool(True)
    )

if reapplyJEC:
    process.p = cms.Path(process.egammaPostRecoSeq * process.patJetCorrFactorsUpdatedJEC * process.updatedPatJetsUpdatedJEC * process.diphoton)
else:
    process.p = cms.Path(process.egammaPostRecoSeq * process.diphoton)
