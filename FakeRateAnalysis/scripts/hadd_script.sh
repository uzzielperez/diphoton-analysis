#!/bin/tcsh  

# input directory : /eos/uscms/store/user/abuccill/DiPhotonAnalysis/FakeRate
# output directory: /eos/uscms/store/user/abuccill/DiPhotonAnalysis/FakeRateMerged

foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/FakeRate`)
    echo $dir
    hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/FakeRateMerged/diphoton_fakeRate_${dir}_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/FakeRate/${dir}/ | grep \.root`
    echo " "
end
