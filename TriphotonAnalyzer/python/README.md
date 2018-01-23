#To Run CRAB

cmsenv
cmsRun ConfFile_cfg.py


##Configure Configuration file 

#number of events (default -1 for "all") 
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#output filename 
process.TFileService = cms.Service("TFileService", fileName = cms.string('0TriphotonOut2018.root')
                                                          )

