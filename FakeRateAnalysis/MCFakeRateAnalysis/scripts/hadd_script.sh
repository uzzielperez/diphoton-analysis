#!/bin/tcsh  

# delete all pervious ntuples, so only one CRAB3 date directory (e.g. 161025_234618) exists
# change input_base (and possibly ntuple_path) and out_path accordingly

if ( "$1" != "GGJets" && "$1" != "GJets") then
    echo " "
    echo "Set argument 1 as: GGJets or GJets"
    echo " "
    exit 1
endif

set sample = $1

echo " "
echo "Merging samples:" $sample
echo " "

set input_base = "/store/user/abuccill/DiPhotonAnalysis/RealTemplates"


set grep_string = ""

if ( $sample == "GGJets" ) then
	set grep_string = "GGJets_M"
    else if ( $sample == "GJets" ) then
	set grep_string = "GJets_H"
    else 
	set grep_string = $sample
endif

foreach dir (`eosls $input_base | grep  $grep_string`)
    echo $dir
    set ntuple_path = "$input_base/$dir"
    set ntuple_path = "$ntuple_path/`eosls $ntuple_path | grep $sample`"
    set ntuple_path = "$ntuple_path/`eosls $ntuple_path | grep 1`"
    set ntuple_path = "$ntuple_path/`eosls $ntuple_path | grep 00`"
    set out_path = "/store/user/abuccill/diphoton-analysis/fake_rate_real_templates/diphoton_fake_rate_real_templates_${dir}_76X_MiniAOD_merged.root"
    hadd -f root://cmseos.fnal.gov/$out_path `xrdfsls -u $ntuple_path/ | grep \.root`
    echo " "
end
