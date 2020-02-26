#! /bin/env python
''' Run limits for ADD diphoton analysis'''
import os

preFitNuisances = True

ms_values = {'NED-2_KK-1': {3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000, 9000, 10000},
             'NED-4_KK-1': {3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000, 9000, 10000},
             'NED-2_KK-4': {3000, 3500, 4000, 4500, 5000, 5500, 6000}}

dimensions = {'NED-2_KK-1', 'NED-4_KK-1', 'NED-2_KK-4'}

extraOptions = "--rMax 2"
if preFitNuisances:
    extraOptions += " --run blind"

regions = {"BB", "BE"}
years = {"2016", "2017", "2018"}
for dimension in dimensions:
    for ms_value in ms_values[dimension]:
        name = 'ADDGravToGG_MS-' + str(ms_value) + '_' + dimension
        name_no_ms = 'ADDGravToGG_' + dimension
        fulldatacardcmd = "combineCards.py "
        outputdatacard = "datacards/" + name + ".dat"
        # combine datacards
        for year in years:
            for region in regions:
                fulldatacardcmd += region + "_" + year + "=datacards/" + name + "_" + year + "_" + region + ".dat "
        fulldatacardcmd += " > " + outputdatacard
        print fulldatacardcmd
        # output combined datacard
        os.system(fulldatacardcmd)
        # hack to avoid bug in combineCards.py
        cmd = "sed -i 's|datacards/datacards|datacards|g' " + outputdatacard
        print cmd
        os.system(cmd)
        cmd = 'combine -M AsymptoticLimits ' + outputdatacard + ' ' + extraOptions + ' -n ' + name_no_ms + ' -m ' + str(ms_value)
        print cmd
        os.system(cmd)
