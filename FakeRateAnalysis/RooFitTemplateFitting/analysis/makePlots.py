print "loading ROOT..."
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
        # h.SetBinError(i+1,binErrors[i])
    return h
def TH1DToTGraphAsymmErrors(h,xValues,graphName,):
    g = TGraphAsymmErrors()
    g.SetName(graphName)
    for i in range(1,h.GetNbinsX()+1):
        g.SetPoint(i-1,xValues[i],h.GetBinContent(i))
        exl = xValues[i] - h.GetBinLowEdge(i)
        exh = h.GetBinLowEdge(i+1) - xValues[i]
        ey = h.GetBinError(i)
        g.SetPointError(i-1,exl,exh,ey,ey)
    return g

def formatGraph(graph, graphNum):
    colors = [ kGreen+2, kRed, kBlue, kBlack, kMagenta, kOrange+2, kCyan ]
    graphColor = colors[graphNum % 7]
    lineStyle = (graphNum % 11) + 1
    graph.SetLineColor(graphColor)
    graph.SetLineStyle(lineStyle)
    graph.SetLineWidth(2)

def getDist(fFile,fGraphName):
    f = TFile(fFile,"read")
    h = f.Get(fGraphName)
    h2 = h.Clone()
    f.Close()
    return h2

def plotFakeRateDists(graphs,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.56,.69,.86,.82)
    legend.SetBorderSize(0)
    legend.SetFillColor(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.021)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        drawString = "AL"
        if graphCounter>0:
            drawString="L"
        graph.Draw(drawString)
        graphCounter += 1

    legend.Draw()
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)

# or any other TH1D comparison
def plotFakeRateRatios(graphs,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.56,.69,.86,.82)
    legend.SetBorderSize(0)
    legend.SetFillColor(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.021)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        drawString = ""
        if graphCounter>0:
            drawString="same"
        graph.Draw(drawString)
        graphCounter += 1

    legend.Draw()
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)

def plotFakeTemplates(graphs,labels,outname):
    plotFakeRateDists(graphs,labels,outname,False)

# def divideTGraphs(a,b):
#     for i in range(a.GetN()):


def makeRatioPlot(graphNum,graphDenom,ratioName):
    # convert to TH1D because for some strange reason you can't divide two TGraphAsymmErrors
    histNum = TGraphAsymmErrorsToTH1D(graphNum,graphNum.GetName())
    histDenom = TGraphAsymmErrorsToTH1D(graphDenom,graphDenom.GetName())

    ratio = histNum.Clone()
    ratio.SetName(ratioName)
    ratio.Divide(histDenom)
    ratio.SetStats(0)
    return ratio



def makePlots():
    # fName = "./denom2plots/fakeRatePlots.root"
    # fName = "muonFakeRatePlots.root"
    fName = "fakeRatePlots.root"
    sidebands = (
        (6,11),
        (7,12),
        (8,13),
        (9,14),
        (10,15),
        (15,20),
        (10,20)
    )

    fakeratesEB=[]
    fakeratesEE=[]

    faketemplatesEB=[]
    faketemplatesEE=[]

    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    labels_faketemplatesEB=[]
    labels_faketemplatesEE=[]

    fakerateratiosEB = []
    fakerateratiosEE = []

    labels_fakerateratiosEB=[]
    labels_fakerateratiosEE=[]

    # loop over eta bins and sidebands and fill lists with the graphs
    for etaBin in ("EB","EE"):
        centerGraphName = "fakeRate"+etaBin+"_chIso9To14"
        fakeRateCenter = getDist(fName,centerGraphName)
        fakeRateCenter.SetName("fakeRate"+etaBin+"_chIsoMid")
        denom = getDist(fName,"phoPt%s_denominator_varbin"%etaBin)
        for sideband in sidebands:
            # print etaBin,sideband
            fakeratename = "fakeRate"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
            faketemplatename = "bkgvspt"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])

            label = "Iso_{Ch} %iTo%i"%(sideband[0],sideband[1])

            fakerate = getDist(fName,fakeratename)
            faketemplate = getDist(fName,faketemplatename)

            fakerate.GetXaxis().SetTitle("Photon pT (GeV/c)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)

            faketemplate.GetXaxis().SetTitle("Photon pT (GeV/c)")
            faketemplate.GetYaxis().SetTitle("Number of Fake Objects / Bin Size")
            faketemplate.GetYaxis().SetTitleOffset(1.4)
            faketemplate.GetXaxis().SetRangeUser(0.,600.)

            # make ratio plot
            ratioName = "fakeRateRatio"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
            ratio = makeRatioPlot(fakerate,fakeRateCenter,ratioName)
            ratio.GetXaxis().SetTitle("Photon pT (GeV/c)")
            ratio.GetYaxis().SetTitle("FR / FR_{chIso9To14}")
            ratio.GetYaxis().SetTitleOffset(1.4)
            ratio.GetYaxis().SetRangeUser(0.7,1.35)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                faketemplatesEB.append(faketemplate)
                fakerateratiosEB.append(ratio)

                labels_fakeratesEB.append(label)
                labels_faketemplatesEB.append(label)
                labels_fakerateratiosEB.append(label)
            else:
                fakeratesEE.append(fakerate)
                faketemplatesEE.append(faketemplate)
                fakerateratiosEE.append(ratio)

                labels_fakeratesEE.append(label)
                labels_faketemplatesEE.append(label)
                labels_fakerateratiosEE.append(label)

            # addon for numerator-denom comparison
            # if etaBin=="EE" and sideband[0] == 9:
            #     tempfake = TGraphAsymmErrorsToTH1D(faketemplate,"numerator")
            #     tempdenom = denom

            #     # for h in (tempfake,tempdenom):
            #     #     h.Scale( 1./h.Integral() )
            #     #     h.GetXaxis().SetRangeUser(0.,600.)
            #     plotFakeRateRatios([tempfake,tempdenom],["Numerator","Denominator"],"numdenomcomp.pdf")



    # Now make fake rate ratio plots
    # for etaBin in ("EB","EE"):
    #     for sideband in sidebands:
    #         if sideband[0] == 9: # we're using this as the basis for comparing the others, we don't need to divide it by itself...
    #             continue
    #         fakeratename = "fakeRate"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
    #         fakeratename_baseline = "fakeRate"+etaBin+"_chIso9To14"
    #         label = "Iso_{Ch} %iTo%i"%(sideband[0],sideband[1])
    #         fakerate = getDist(fName,fakeratename).Clone()
    #         fakerate_baseline = getDist(fName,fakeratename_baseline).Clone()
    #         fakerate.Divide(fakerate_baseline)

    #         if etaBin == "EB":
    #             fakerateratiosEB.append(fakerate)
    #             labels_fakerateratiosEB.append(label)
    #         else:
    #             fakerateratiosEE.append(fakerate)
    #             labels_fakerateratiosEE.append(label)

    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"fakeRateComparisonEB.png")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"fakeRateComparisonEE.png")

    # plotFakeRateDists(fakerateratiosEB,labels_fakerateratiosEB,"fakeRateRatiosEB.png")
    # plotFakeRateDists(fakerateratiosEE,labels_fakerateratiosEE,"fakeRateRatiosEE.png")

    plotFakeTemplates(faketemplatesEB,labels_faketemplatesEB,"fakeTemplateComparisonEB.png")
    plotFakeTemplates(faketemplatesEE,labels_faketemplatesEE,"fakeTemplateComparisonEE.png")

    plotFakeRateRatios(fakerateratiosEB,labels_fakerateratiosEB,"fakeRateRatioComparisonEB.png")
    plotFakeRateRatios(fakerateratiosEE,labels_fakerateratiosEE,"fakeRateRatioComparisonEE.png")

def makePlots2():
    # fname0 = "./denom0plots/fakeRatePlots.root"
    # fname1 = "./denom1plots/fakeRatePlots.root"
    # fname2 = "./denom2plots/fakeRatePlots.root"

    fname0 = "../../../../../../CMSSW_7_6_3_patch2/src/diphoton-analysis/FakeRateAnalysis/RooFitTemplateFitting/analysis/denom2plots/fakeRatePlots.root"
    fname1 = "./notmatchedDr0p38/fakeRatePlots.root"
    fname2 = "./notmatchedDr0p6/fakeRatePlots.root"

    fnamedict = {
        0 : fname0,
        1 : fname1,
        2 : fname2
    }

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE"):
        for i in (0,1,2):
            fakeratename = "fakeRate"+etaBin+"_chIso9To14"
            label = ""
            if i == 0:
                label = "no jet matching"
            elif i == 1:
                label = "dR(photon,leadingJet)>0.38"
            elif i == 2:
                label = "dR(photon,leadingJet)>0.6"
            fakerate = getDist(fnamedict[i],fakeratename)
            fakerate.GetXaxis().SetTitle("Photon pT (GeV/c)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.11)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.066)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            else:
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)

    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"fakeRateComparisonEB_notmatched.png")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"fakeRateComparisonEE_notmatched.png")


if __name__ == "__main__":
    # makePlots()
    makePlots2()
