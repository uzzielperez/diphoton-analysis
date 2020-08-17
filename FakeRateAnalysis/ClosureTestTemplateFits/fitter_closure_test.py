print "importing ROOT..."
from ROOT import *
import numpy as np
print "done."

gROOT.SetBatch()

def TGraphAsymmErrorsToTH1D(g,histName):
    numPoints = g.GetN()
    # xHigh = g.GetErrorXhigh(numPoints-1)
    # xLow = g.GetErrorXlow(0)
    binBoundaries = []
    binContents = []
    binErrors = []
    for i in range(numPoints):
        x = Double()
        y = Double()
        g.GetPoint(i,x,y)
        # print "got point %i %.5f %.5f"%(i,x,y)
        binBoundaries.append( x - g.GetErrorXlow(i) )
        # print "appended %.5f"%( x - g.GetErrorXlow(i) )
        binContents.append( y )
        binErrors.append( g.GetErrorYlow(i) ) #low and high are equal, just picked one
        if i == numPoints-1:
            # binBoundaries.append(x + g.GetErrorXhigh(i)) #get last value also
            binBoundaries.append(600.) #hack because SetRangeUser wasn't working...
            # print "appended %.5f"%(x + g.GetErrorXhigh(i))
    binBoundaries = np.array(binBoundaries)
    h = TH1D(histName,"",len(binContents),binBoundaries)
    for i in range(numPoints):
        h.SetBinContent(i+1,binContents[i])
        h.SetBinError(i+1,binErrors[i])
    return h

infile = TFile("fake_rate_sieie_template_fits.root","read")

# Fake Rate for chIso5To10
plotEB = infile.Get("hEBFakeRate")
# plotEB = infile.Get("hEBRate_chIso5To10")
#plotEBclone = plotorigEB.Clone()
#plotEB = TGraphAsymmErrorsToTH1D(plotEBclone,"plotEB")

plotEE = infile.Get("hEEFakeRate")
# plotEE = infile.Get("hEERate_chIso5To10")
#plotEEclone = plotorigEE.Clone()
#plotEE = TGraphAsymmErrorsToTH1D(plotEEclone,"plotEE")

EBfunc = TF1("EBfunc","[0]+[1]/(x^[2])",0.,600.)
EBfunc.SetParameter(0,0.1)
EBfunc.SetParameter(1,1.)
EBfunc.SetParameter(2,0.1)

EEfunc = TF1("EEfunc","[0]+[1]/(x^[2])",0.,600.)
EEfunc.SetParameter(0,0.1)
EEfunc.SetParameter(1,1.)
EEfunc.SetParameter(2,0.1)

print "********EB FIT************"
resEB = plotEB.Fit(EBfunc,"RS","",0.,600.)
EBfunc.SetLineColor(kRed)
print "chi**2 = %.4f"%resEB.Chi2()
print "ndf = %i"%resEB.Ndf()

print "********EE FIT************"
resEE = plotEE.Fit(EEfunc,"RS","",0.,600.)
EEfunc.SetLineColor(kRed)
print "chi**2 = %.4f"%resEE.Chi2()
print "ndf = %i"%resEE.Ndf()

# print "********EE FIT************"
# EEfuncHigh = TF1("EEfuncHigh","pol1",130.,600.)
# resHigh = plotEE.Fit(EEfuncHigh,"SR")
# EEfuncLow = TF1("EEfuncLow","[0]+[1]*(x-135)+[2]*(x-135)^2",0.,135.)
# EEfuncLow.FixParameter(0,EEfuncHigh.Eval(135.)) # high pT linear fit evaluated at 175
# EEfuncLow.FixParameter(1,EEfuncHigh.GetParameter(1)) # slope of high pT linear fit (to match derivatives at pT=175)
# resLow = plotEE.Fit(EEfuncLow,"SR+")

print "*******EB FIT RESULTS**********"
print "Fit Function: [0]+[1]/(x^[2])"
for i in range(3):
    print "Param %i = %.14f"%(i,EBfunc.GetParameter(i))
print "chi^2 = %.4f"%resEB.Chi2()
print "ndf = %i"%resEB.Ndf()


print "*******EE FIT RESULTS**********"
print "Fit Function: [0]+[1]/(x^[2])"
for i in range(3):
    print "Param %i = %.14f"%(i,EEfunc.GetParameter(i))
print "chi^2 = %.4f"%resEE.Chi2()
print "ndf = %i"%resEE.Ndf()


# print "*******EE FIT RESULTS**********"
# print "Fit Function Below 135 GeV: [0]+[1]*(x-175)+[2]*(x-175)^2"
# for i in range(3):
#     print "Param %i = %.14f"%(i,EEfuncLow.GetParameter(i))
# print "chi^2 = %.4f"%resLow.Chi2()
# print "ndf = %.4f"%resLow.Ndf()
# print "Fit Function Above 135 GeV: pol1"
# print "slope = %.14f"%EEfuncHigh.GetParameter(1)
# print "yint = %.14f"%EEfuncHigh.GetParameter(0)
# print "chi^2 = %.4f"%resHigh.Chi2()
# print "ndf = %.4f"%resHigh.Ndf()

for f in (plotEB,plotEE):
    f.GetXaxis().SetTitle("p_{T} (GeV)")
    f.GetYaxis().SetTitle("fake rate")
    #f.GetYaxis().SetRangeUser(0.,0.4);

gStyle.SetOptStat()
gStyle.SetOptFit()

c = TCanvas("c","",1200,800)
c.cd()
plotEB.Draw()
plotEB.GetYaxis().SetRangeUser(0.,0.2);
c.SaveAs("closure_test_fake_rate_fit_chIso5To10_EB.pdf")

#c.Clear()
plotEE.Draw()
plotEE.GetYaxis().SetRangeUser(0.,0.6);
c.SaveAs("closure_test_fake_rate_fit_chIso5To10_EE.pdf")


# raw_input("enter to quit: ")
