print "loading ROOT..."
from ROOT import *
print "done."

gROOT.SetBatch()

infile = TFile("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root","read")

numEBPt = infile.Get("phoPtEB_numerator")
numEEPt = infile.Get("phoPtEE_numerator")

denomEBPt = infile.Get("phoPtEB_denominator")
denomEEPt = infile.Get("phoPtEE_denominator")

dataEB = infile.Get("sieieEB_numerator_pt90To110")
dataEE = infile.Get("sieieEE_numerator_pt90To110")

fakeEB = infile.Get("sieieEB_faketemplate_pt90To110")
fakeEE = infile.Get("sieieEE_faketemplate_pt90To110")

for h in (numEBPt,numEEPt,denomEBPt,denomEEPt):
    h.GetXaxis().SetTitle("Candidate pT (GeV)")
    h.GetYaxis().SetTitle("Number of Objects Passing Selection")
    h.GetYaxis().SetTitleOffset(1.1)

for h in (dataEE,dataEB):
    h.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
    h.GetYaxis().SetTitle("Number of Objects Passing Selection")
    h.GetYaxis().SetTitleOffset(1.5)

for h in (fakeEE,fakeEB):
    h.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
    h.GetYaxis().SetTitle("Normalized Entries")
    h.GetYaxis().SetTitleOffset(1.5)

for i,h in enumerate((numEBPt,numEEPt,denomEBPt,denomEEPt,dataEE,dataEB,fakeEE,fakeEB)):
    c = TCanvas("c","",800,800)
    if i <= 3:
        c.SetLogy()
    if i > 3:
        h.GetXaxis().SetRangeUser(0.,0.1)
    name = h.GetName()
    h.Draw()
    c.SaveAs("%s.pdf"%name)
