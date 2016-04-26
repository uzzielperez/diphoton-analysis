#!/bin/bash

MASS="15to20 20to30 30to50 50to80 80to120 120to170 170to300 300toInf"

#for i in `seq 500 250 3000`; do 
for i in `echo $MASS`; do
    #echo $i
    root -l -b -q ../scripts/diphoton_fTree_looper.C'("'$i'")'
    root -l -b -q ../scripts/diphoton_fTreeFake_looper.C'("'$i'")'
done