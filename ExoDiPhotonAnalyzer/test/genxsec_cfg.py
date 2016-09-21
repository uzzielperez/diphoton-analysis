import FWCore.ParameterSet.Config as cms

process = cms.Process("xsec")

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
        'file:GGJets_M-1000To2000_Pt-50_13TeV-sherpa.root'
        )
    )

# analyzer to print cross section
process.xsec = cms.EDAnalyzer("GenXSecAnalyzer")

process.p = cms.Path(process.xsec)
