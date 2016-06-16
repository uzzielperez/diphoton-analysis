#!/bin/bash

# QCD_EMEnriched
#MASS="15to20 20to30 30to50 50to80 80to120 120to170 170to300 300toInf"

# QCD
MASS="5to10 10to15 15to30 30to50 50to80 80to120 120to170 170to300 300to470 470to600 600to800 800to1000 1000to1400 1400to1800 1800to2400 2400to3200 3200toInf"

#for i in `seq 500 250 3000`; do 
for i in `echo $MASS`; do
    #echo $i
    root -l -b -q ../scripts/diphoton_fTree_looper.C'("'$i'")'
    root -l -b -q ../scripts/diphoton_fTreeFake_looper.C'("'$i'")'
done