#!/usr/bin/env python
'''
Create templates for closure test
'''
years = [2016, 2017, 2018]
bins = [(0, 200), (0, 22), (23, 27), (28, 32), (33, 37), (38, 200)]
datasets = ["GJets", "GGJets"]
for year in years:
    for bin in bins:
        pu = str(bin[0]) + " " + str(bin[1])
        arguments = str(year) + " all " + pu
        print("real_templates_closure.exe " + arguments)
        for dataset in datasets:
            arguments = str(year) + " " + dataset + " " + pu
            print("fake_templates_closure.exe " + arguments)
