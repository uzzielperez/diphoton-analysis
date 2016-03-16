import ROOT as r
import numpy
from math import *
from sys import argv
from ROOT import TMath 
from array import array 

r.gROOT.SetBatch()

def GetMedian(hist):
	nbin = hist.GetNbinsX()
	x =[]
	for i in range(1,nbin):
		if(hist.GetBinContent(i)!=0):
			for j in range(1,int(hist.GetBinContent(i))):
				x.append(hist.GetBinCenter(i))
	return numpy.median(numpy.array(x))

#filename = "FullData_FinalFit.root"
#filename = "Plot_StOpt_SBextra.root"
#filename = "TestFix_plot.root"
#filename = "StOpt_SBextra_plot.root"
#filename = "StOpt_SBextra_edited_plot.root"
#filename = "StOpt_BH_plot.root"
#filename = "StOpt_BHtest_sorted_plot.root"
#filename = "StOpt_BHtest_plot.root"
filename = argv[1]
file=r.TFile.Open(filename)
output = filename.split(".")[0]+".pdf"
	
#c1.Divide(2,2)

nPages = 0
nPad   = 1
IsLast = False
i      = 1 
#r.gStyle.SetOptStat(0)

print "Found %i items" % len(file.GetListOfKeys())

nItems = 0
for key in file.GetListOfKeys():
	hist_name =key.GetName()
	nItems +=1
print "Printing %i histograms" % nItems

c1 = r.TCanvas("c1","c1",800,600)

# Loop over all histograms
for key in file.GetListOfKeys():
	key_name = key.GetName()
	#print key_name
	if not "mg" in filename:
		if ("Zbi" in key_name):
			continue
		if ("StOpt" in key_name):
			continue
		if ("NOpt" in key_name):
			continue
	key_Obj  = file.Get(key_name)
	if "Canvas" in key.GetClassName():
		c1 = file.Get(key_name)
	if "Graph" in key.GetClassName():
#		key_Obj.Draw("ALP*")
		continue
	if "2D" in key.GetClassName():
		key_Obj.Draw("COLZ")
	if "TH1" in key.GetClassName():
		key_Obj.Draw()
	#print type(histo)
	#histo.Draw("ALP*")
	# Open a new page
	if(nPages==0): c1.Print(output+"(","pdf")
	if(i == nItems):
		c1.Print(output+")","pdf")
		IsLast = True
	else:
		if(nPages!=0 and IsLast==False):
			 c1.Print(output,"pdf")
	nPages+=1
	nPad = 1
	c1.Clear()
if(IsLast==False): 
	c1.Print(output+")","pdf")
