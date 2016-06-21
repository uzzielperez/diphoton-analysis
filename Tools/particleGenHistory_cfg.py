import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.maxEvents = cms.untracked.PSet(
                    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
        fileNames = cms.untracked.vstring('root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/PickEvents/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8/crab_pickEvents/160620_205257/0000/pickEvents_merged.root')
)
process.printEventNumber = cms.OutputModule("AsciiOutputModule")

process.printList = cms.EDAnalyzer(
    "ParticleListDrawer",
    src = cms.InputTag("genParticles"),
    printVertex = cms.untracked.bool(True),
    printOnlyHardInteraction = cms.untracked.bool(False), # Print only status=3 particles. This will not work for Pythia8
    maxEventsToPrint  = cms.untracked.int32(-1)
    )

process.printTree = cms.EDAnalyzer(
    "ParticleTreeDrawer",
    src = cms.InputTag("genParticles"),                                                                 
    printP4 = cms.untracked.bool(False),
    printPtEtaPhi = cms.untracked.bool(False),
    printVertex = cms.untracked.bool(False),
    printStatus = cms.untracked.bool(True),
    printIndex = cms.untracked.bool(False)
    #status = cms.untracked.vint32( 1 )
    )

process.printDecay = cms.EDAnalyzer(
    "ParticleDecayDrawer", # only prints status 3 (?)
    src = cms.InputTag("genParticles"),
    printP4 = cms.untracked.bool(False),
    printPtEtaPhi = cms.untracked.bool(False),
    printVertex = cms.untracked.bool(True)
    )

process.p = cms.Path(process.printList*
                     process.printTree
                     #*process.printDecay
                     )

process.outpath = cms.EndPath(process.printEventNumber)
process.MessageLogger.destinations = cms.untracked.vstring('cout','cerr')
