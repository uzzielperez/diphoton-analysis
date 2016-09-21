# runtime options
from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('python')

options.register('globalTag',
                 #'76X_dataRun2_v15',
                 '76X_dataRun2_16Dec2015_v0',
                 VarParsing.multiplicity.singleton,
                 VarParsing.varType.string,
                 "global tag to use when running"
                 )

## 'maxEvents' is already registered by the Framework, changing default value
options.setDefault('maxEvents', 1000)

options.parseArguments()

import FWCore.ParameterSet.Config as cms

process = cms.Process("ExoDiPhoton")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

# for input file
process.source = cms.Source(
    "PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        # 'file:failevent_MiniAOD_HoverELT005.root'
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_1.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_2.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_3.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_4.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_5.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_6.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_7.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_8.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_9.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_10.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_11.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_12.root',
        'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/passevents/JetHT/crab_pickEvents/160915_195723/0000/pickevents_13.root'

        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_1.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_2.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_3.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_4.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_5.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_6.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_7.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_8.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_9.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_10.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_11.root',
        # 'root://eoscms.cern.ch//store/group/phys_exotica/diphoton/triggerstudy/failevents/JetHT/crab_pickEvents/160915_195949/0000/pickevents_12.root'

        # "root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/jethtpickevents/JetHT/crab_pickEvents/160830_210824/0000/pickevents_1.root",
        # "root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/jethtpickevents/JetHT/crab_pickEvents/160830_210824/0000/pickevents_2.root"
        # 'file:pickevents.root'
         # 'root://cmsxrootd.fnal.gov//store/data/Run2015D/DoubleEG/MINIAOD/16Dec2015-v2/00000/000298CD-87A6-E511-9E56-002590593878.root'
        #'root://cmsxrootd.fnal.gov//store/data/Run2016B/DoubleEG/MINIAOD/PromptReco-v2/000/275/074/00000/AA970B76-6535-E611-AAAC-02163E0142FC.root'
        )
    )

# for global tag
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = options.globalTag
print options.globalTag

# geometry for saturation
process.load("Configuration.StandardSequences.GeometryDB_cff")

# for output file
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("ExoDiphotonAnalyzer.root")
    )

process.primaryVertexFilter = cms.EDFilter("GoodVertexFilter",
                                           vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                           minimumNDOF = cms.uint32(4),
                                           maxAbsZ = cms.double(24),    
                                           maxd0 = cms.double(2)    
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
    'ExoDiPhotonDataAnalyzer',
    # photon tag
    photonsMiniAOD = cms.InputTag("slimmedPhotons"),
    minPhotonPt = cms.double(50.),
    # vertex tag
    vertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
    # beam spot tag
    beamSpot = cms.InputTag("offlineBeamSpot", "", "RECO"),
    # ak4 jets
    jetsMiniAOD = cms.InputTag("selectedUpdatedPatJetsUpdatedJEC"),
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
    AlgInputTag = cms.InputTag("gtStage2Digis"),
    l1tAlgBlkInputTag = cms.InputTag("gtStage2Digis"),
    l1tExtBlkInputTag = cms.InputTag("gtStage2Digis")
    )

process.p = cms.Path(process.primaryVertexFilter*process.egmPhotonIDSequence*
                     process.diphoton)
