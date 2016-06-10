#!/bin/tcsh  

# input directory : /eos/uscms/store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015/DoubleEG/crab_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD/160609_232349/0000/
# output directory: /eos/uscms/store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged

#foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD`)
    #echo $dir
hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015_Merged/diphoton_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/Data/DoubleEG_Run2015/DoubleEG/crab_DoubleEG_Run2015D-16Dec2015-v2_MiniAOD/160609_232349/0000/ | grep \.root`
    #echo " "
#end
