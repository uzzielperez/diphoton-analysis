# runtime options

import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
from os.path import basename

options = VarParsing ('python')
options.parseArguments()

outName = options.outputFile
print("Default output name: " + outName)
if "output" in outName: # if an input file name is specified, event weights can be determined
    outName = "out_" + basename(options.inputFiles[0])
    print("Output root file name: " + outName)
else:
    options.inputFiles = "file:GGJets_M-1000To2000_Pt-50_13TeV-sherpa.root"

reapplyJEC = False
jetCollection = "slimmedJets"
if reapplyJEC:
    jetCollection = "updatedPatJetsUpdatedJEC"
if "Run2016" in outName:
    globalTag = "94X_dataRun2_v10"
elif "Run2017" in outName:
    globalTag = "94X_dataRun2_v11"
elif "Run2018" in outName:
    if "17Sep2018" in outName:
        globalTag = "102X_dataRun2_v11"
    else:
        globalTag = "102X_dataRun2_Prompt_v14"
process = cms.Process("ExoDiPhoton")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( options.maxEvents ) )

# for input file
process.source = cms.Source(
    "PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        options.inputFiles
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

# Setup VID for EGM ID
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
switchOnVIDPhotonIdProducer(process, DataFormat.MiniAOD)
# define which IDs we want to produce
my_id_modules = ['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Spring15_25ns_V1_cff']
#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)

## update AK4PFchs jet collection in MiniAOD JECs

from PhysicsTools.PatAlgos.tools.jetTools import updateJetCollection

updateJetCollection(
   process,
   jetSource = cms.InputTag('slimmedJets'),
   labelName = 'UpdatedJEC',
   jetCorrections = ('AK4PFchs', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual']), 'None')  # Do not forget 'L2L3Residual' on data!
)

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
    effAreaChHadFile = cms.FileInPath("RecoEgamma/PhotonIdentification/data/Spring15/effAreaPhotons_cone03_pfChargedHadrons_25ns_NULLcorrection.txt"),
    effAreaNeuHadFile = cms.FileInPath("RecoEgamma/PhotonIdentification/data/Spring15/effAreaPhotons_cone03_pfNeutralHadrons_25ns_90percentBased.txt"),
    effAreaPhoFile = cms.FileInPath("RecoEgamma/PhotonIdentification/data/Spring15/effAreaPhotons_cone03_pfPhotons_25ns_90percentBased.txt"),
    # EGM ID decisions
    phoLooseIdMap = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-loose"),
    phoMediumIdMap = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-medium"),
    phoTightIdMap = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-tight"),
    # output file name
    outputFile = cms.string(outName),
    isReMINIAOD = cms.bool(True)
    )

if reapplyJEC:
    process.p = cms.Path(process.patJetCorrFactorsUpdatedJEC * process.updatedPatJetsUpdatedJEC * process.egmPhotonIDSequence * process.diphoton)
else:
    process.p = cms.Path(process.egmPhotonIDSequence * process.diphoton)
