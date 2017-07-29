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


# geometry for saturation
#process.load("Configuration.StandardSequences.GeometryDB_cff")
#process.load("Geometry.CaloEventSetup.CaloTopology_cfi");
#process.CaloTopologyBuilder = cms.ESProducer("CaloTopologyBuilder")
#process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi");
#process.load("Geometry.CaloEventSetup.CaloGeometry_cfi");

#main analyzer and inputs
process.demo = cms.EDAnalyzer('TriphotonAnalyzer',
    #rho tag
    rho = cms.InputTag("fixedGridRhoAll")
)

process.TFileService = cms.Service("TFileService", fileName = cms.string('0TriphotonOut2017.root')
                                                        )

process.p = cms.Path(process.demo)
