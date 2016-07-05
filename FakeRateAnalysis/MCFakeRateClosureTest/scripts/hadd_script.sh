#!/bin/tcsh  

# delete all pervious ntuples, so only one "dateDir" exists

# example CRAB3 output 
# /QCD/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8/crab_QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD/160614_130418/0000

# input directory : /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD
# output directory: /eos/uscms/store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD

# choose QCD, QCD_EMEnriched, or GJets
set dataset = "QCD"

if ($dataset == "QCD") then
    foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD | grep QCD`)
	echo $dir
	set dateDir = `eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD/${dir}/crab_${dir}_76X_MiniAOD`
	hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD/diphoton_fakeRate_${dir}_76X_MiniAOD_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD/${dir}/crab_${dir}_76X_MiniAOD/${dateDir}/0000/ | grep \.root`
	echo " "
    end
endif

if ($dataset == "QCD_EMEnriched") then
    foreach dir (`eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD_EMEnriched | grep QCD`)
	echo $dir
	set dateDir = `eosls /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD_EMEnriched/${dir}/crab_${dir}_76X_MiniAOD`
	hadd -f root://cmseos.fnal.gov//store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTestMerged/QCD_EMEnriched/diphoton_fakeRate_${dir}_76X_MiniAOD_merged.root `xrdfsls -u /store/user/abuccill/DiPhotonAnalysis/MCFakeRateClosureTest/QCD_EMEnriched/${dir}/crab_${dir}_76X_MiniAOD/${dateDir}/0000/ | grep \.root`
	echo " "
    end
endif
