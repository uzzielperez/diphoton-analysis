#!/bin/tcsh  

# input directory : /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateRealTemplate
# output directory: /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateMerged

foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateRealTemplate`)
    echo $dir
    hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateMerged/diphoton_fakeRate_${dir}_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/MCFakeRateRealTemplate/${dir}/ | grep \.root`
    echo " "
end
