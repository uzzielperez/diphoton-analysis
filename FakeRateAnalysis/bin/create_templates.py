#!/usr/bin/env python
'''
Create templates for real photon contributions
'''
years = [2016, 2017, 2018]
bins = [(0, 22), (23, 27), (28, 32), (33, 37), (38, 200)]

for year in years:
    for bin in bins:
        arguments = str(year) + " all " + str(bin[0]) + " " + str(bin[1])
        print("real_templates.exe " + arguments)
