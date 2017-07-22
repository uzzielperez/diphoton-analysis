import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
   fileNames = cms.untracked.vstring( 
      'root://cmsxrootd.fnal.gov//store/data/Run2016D/DoubleEG/MINIAOD/03Feb2017-v1/100000/002CE21C-0BEB-E611-8597-001E67E6F8E6.root' 
    
    )
)

process.demo = cms.EDAnalyzer('TriphotonAnalyzer'
)

process.TFileService = cms.Service("TFileService", fileName = cms.string('TriphotonAnalyzer.root')
                                                        )

process.p = cms.Path(process.demo)
