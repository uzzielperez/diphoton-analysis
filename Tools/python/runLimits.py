#! /bin/env python
''' Run limits for ADD diphoton analysis'''
import os

preFitNuisances = True

dict = {'NED-2_KK-1': {3000, 3500, 4000, 4500, 5000, 5500, 6000}, 
        'NED-4_KK-1': {3000, 3500, 4000, 4500, 5000, 5500, 6000}, 
        'NED-2_KK-4': {3000, 3500, 4000, 4500, 5000, 5500, 6000}}

dimensions = {'NED-2_KK-1', 'NED-4_KK-1', 'NED-2_KK-4'}

extraOptions = "--rMax 2"
if preFitNuisances:
    extraOptions += " -t -1 "

regions = {"BB", "BE"}
years = {"2017", "2018"}
for idim in dimensions:
    for i in dict[idim]:
        name = 'ADDGravToGG_MS-' + str(i) + '_' + idim
        fulldatacardcmd = "combineCards.py "
        outputdatacard = "datacards/" + name + ".dat"
        # combine datacards
        for year in years:
            for region in regions:
                fulldatacardcmd += "datacards/" + name + "_" + year + "_" + region + ".dat "
        fulldatacardcmd += " > " + outputdatacard
        print fulldatacardcmd
        # output combined datacard
        os.system(fulldatacardcmd)
        # hack to avoid bug in combineCards.py
        cmd = "sed -i 's|datacards/datacards|datacards|g' " + outputdatacard
        print cmd
        os.system(cmd)
        cmd = 'combine -M AsymptoticLimits ' + outputdatacard + ' ' + extraOptions + ' -n ' + name
        print cmd
        os.system(cmd)
