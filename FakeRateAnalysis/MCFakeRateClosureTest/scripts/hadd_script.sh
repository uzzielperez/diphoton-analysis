#!/bin/tcsh  

# Use QCD or GJets samples
# input directory : /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD
# output directory: /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD

foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD`)
    echo $dir
    hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_${dir}_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD/${dir}/ | grep \.root`
    echo " "
end
