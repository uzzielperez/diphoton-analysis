#!/bin/bash

MASS="60To200 200To500 500To1000 1000To2000 2000To4000 4000To6000 6000To8000 8000To13000"

#for i in `seq 500 250 3000`; do 
for i in `echo $MASS`; do
    #echo $i
    root -l -b -q ../scripts/diphoton_tree_looper.C'("'$i'")'
done