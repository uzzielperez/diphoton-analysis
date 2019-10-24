print "loading ROOT..."
from ROOT import *
import numpy as np
print "done."

gROOT.SetBatch()
tdrStyle = None

def setTDRStyle():
    global tdrStyle
    tdrStyle = TStyle("tdrStyle","Style for P-TDR")
    # For the canvas:
    tdrStyle.SetCanvasBorderMode(0)
    tdrStyle.SetCanvasColor(kWhite)
    tdrStyle.SetCanvasDefH(700) #Height of canvas
    tdrStyle.SetCanvasDefW(850) #Width of canvas
    tdrStyle.SetCanvasDefX(400)   #POsition on screen
    tdrStyle.SetCanvasDefY(0)

    # For the Pad:
    tdrStyle.SetPadBorderMode(0)
    # tdrStyle.SetPadBorderSize(Width_t size = 1)
    tdrStyle.SetPadColor(kWhite)
    tdrStyle.SetPadGridX(False)
    tdrStyle.SetPadGridY(False)
    tdrStyle.SetGridColor(0)
    tdrStyle.SetGridStyle(3)
    tdrStyle.SetGridWidth(1)

    # For the frame:
    tdrStyle.SetFrameBorderMode(0)
    tdrStyle.SetFrameBorderSize(1)
    tdrStyle.SetFrameFillColor(0)
    tdrStyle.SetFrameFillStyle(0)
    tdrStyle.SetFrameLineColor(1)
    tdrStyle.SetFrameLineStyle(1)
    tdrStyle.SetFrameLineWidth(1)

    # For the histo:
    # tdrStyle.SetHistFillColor(1)
    # tdrStyle.SetHistFillStyle(0)
    tdrStyle.SetHistLineColor(1)
    tdrStyle.SetHistLineStyle(0)
    tdrStyle.SetHistLineWidth(1)
    # tdrStyle.SetLegoInnerR(Float_t rad = 0.5)
    # tdrStyle.SetNumberContours(Int_t number = 20)

    tdrStyle.SetEndErrorSize(2)
    #  tdrStyle.SetErrorMarker(20)
    tdrStyle.SetErrorX(0.)

    tdrStyle.SetMarkerStyle(20)

    #For the fit/function:
    tdrStyle.SetOptFit(1)
    tdrStyle.SetFitFormat("5.4g")
    tdrStyle.SetFuncColor(2)
    tdrStyle.SetFuncStyle(1)
    tdrStyle.SetFuncWidth(1)

    #For the date:
    tdrStyle.SetOptDate(0)
    # tdrStyle.SetDateX(Float_t x = 0.01)
    # tdrStyle.SetDateY(Float_t y = 0.01)

    # For the statistics box:
    tdrStyle.SetOptFile(0)
    tdrStyle.SetOptStat(0) # To display the mean and RMS:   SetOptStat("mr")
    tdrStyle.SetStatColor(kWhite)
    tdrStyle.SetStatFont(42)
    tdrStyle.SetStatFontSize(0.025)
    tdrStyle.SetStatTextColor(1)
    tdrStyle.SetStatFormat("6.4g")
    tdrStyle.SetStatBorderSize(1)
    tdrStyle.SetStatH(0.1)
    tdrStyle.SetStatW(0.15)
    # tdrStyle.SetStatStyle(Style_t style = 1001)
    # tdrStyle.SetStatX(Float_t x = 0)
    # tdrStyle.SetStatY(Float_t y = 0)

    # Margins:
    tdrStyle.SetPadTopMargin(0.07)
    tdrStyle.SetPadBottomMargin(0.13)
    tdrStyle.SetPadLeftMargin(0.17)
    tdrStyle.SetPadRightMargin(0.03)

    # For the Global title:
    tdrStyle.SetOptTitle(0)
    tdrStyle.SetTitleFont(42)
    tdrStyle.SetTitleColor(1)
    tdrStyle.SetTitleTextColor(1)
    tdrStyle.SetTitleFillColor(10)
    tdrStyle.SetTitleFontSize(0.065)
    tdrStyle.SetTitleH(0.07) # Set the height of the title box
    tdrStyle.SetTitleW(0.80) # Set the width of the title box
    tdrStyle.SetTitleX(0.15) # Set the position of the title box
    tdrStyle.SetTitleY(1.00) # Set the position of the title box
    # tdrStyle.SetTitleStyle(Style_t style = 1001)
    tdrStyle.SetTitleBorderSize(1)

    # For the axis titles:
    tdrStyle.SetTitleColor(1, "XYZ")
    tdrStyle.SetTitleFont(42, "XYZ")
    tdrStyle.SetTitleSize(0.06, "XYZ")
    # tdrStyle.SetTitleXSize(Float_t size = 0.02) # Another way to set the size?
    # tdrStyle.SetTitleYSize(Float_t size = 0.02)
    tdrStyle.SetTitleXOffset(0.95)
    tdrStyle.SetTitleYOffset(1.2)
    # tdrStyle.SetTitleOffset(1.1, "Y") # Another way to set the Offset

    # For the axis labels:
    tdrStyle.SetLabelColor(1, "XYZ")
    tdrStyle.SetLabelFont(42, "XYZ")
    tdrStyle.SetLabelOffset(0.007, "XYZ")
    tdrStyle.SetLabelSize(0.044, "XYZ")

    # For the axis:
    tdrStyle.SetAxisColor(1, "XYZ")
    tdrStyle.SetStripDecimals(True)
    tdrStyle.SetTickLength(0.03, "XYZ")
    tdrStyle.SetNdivisions(510, "XYZ")
    tdrStyle.SetPadTickX(1)  # To get tick marks on the opposite side of the frame
    tdrStyle.SetPadTickY(1)

    # Change for log plots:
    tdrStyle.SetOptLogx(0)
    tdrStyle.SetOptLogy(0)
    tdrStyle.SetOptLogz(0)

    # Postscript options:
    tdrStyle.SetPaperSize(20.,20.)
    # tdrStyle.SetLineScalePS(Float_t scale = 3)
    # tdrStyle.SetLineStyleString(Int_t i, const char* text)
    # tdrStyle.SetHeaderPS(const char* header)
    # tdrStyle.SetTitlePS(const char* pstitle)

    # tdrStyle.SetBarOffset(Float_t baroff = 0.5)
    # tdrStyle.SetBarWidth(Float_t barwidth = 0.5)
    # tdrStyle.SetPaintTextFormat(const char* format = "g")
    # tdrStyle.SetPalette(Int_t ncolors = 0, Int_t* colors = 0)
    # tdrStyle.SetTimeOffset(Double_t toffset)
    # tdrStyle.SetHistMinimumZero(True)
    tdrStyle.cd()

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
    # colors = [ kGreen+2, kRed, kBlue, kBlack, kMagenta, kOrange+2, kCyan, kYellow+1 ]
    # graphColor = colors[graphNum % 8]
    # lineStyle = (graphNum % 11) + 1
    colors = [ kGreen+2, kRed, kBlue, kPink-8, kBlack, kMagenta, kOrange+2, kCyan, kViolet+7, kYellow+2 ]
    graphColor = colors[graphNum % 10]
    lineStyle = (graphNum % 9) + 1
    if lineStyle == 1:
        lineStyle = 5
    graph.SetLineColor(graphColor)
    graph.SetLineStyle(lineStyle)
    graph.SetLineWidth(2)

def getDist(fFile,fGraphName):
    f = TFile(fFile,"read")
    h = f.Get(fGraphName)
    h2 = h.Clone()
    f.Close()
    return h2
def getDist2(fFile,fGraphName):
    f = TFile(fFile,"read")
    h = f.Get(fGraphName)
    h2 = h.Clone()
    print type(h)
    print type(h2)
    f.Close()

    h3 = TH1D("h3","",10,0.,10.)
    h3.Fill(3.)
    return h2
    # c = TCanvas()
    # h.Draw()
    # raw_input("adsfadsf")
    # h2 = h.Clone()
    # f.Close()
    # return h
def getDist3(fFile,fGraphNames):
    f = TFile(fFile,"read")
    h = f.Get(fGraphNames[0])
    h2 = f.Get(fGraphNames[1])
    hclone = h.Clone()
    h2clone = h2.Clone()
    # print type(h)
    # print type(h2)
    f.Close()

    # h3 = TH1D("h3","",10,0.,10.)
    # h3.Fill(3.)
    return hclone,h2clone
    # c = TCanvas()
    # h.Draw()
    # raw_input("adsfadsf")
    # h2 = h.Clone()
    # f.Close()
    # return h
def getHist(fFile,fGraphName):
    fFile.cd()
    h = fFile.Get(fGraphName)
    h2 = h.Clone()
    h2.SetDirectory(0)
    return h2
def plotNormTH1Ds(graphs,legendheader,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.58,.69,.88,.88)
    legend.SetBorderSize(0)
    legend.SetFillColor(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.028)
    legend.SetHeader(legendheader)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        graph.SetLineStyle(1) #override
        drawString = "hist"
        if graphCounter>0:
            drawString="hist same"
        graph.Scale(1./graph.Integral())
        # if "EB" in outname and drawString == "hist":
            # graph.GetYaxis().SetRangeUser(1e-6,0.55)
        if "EE" in outname and drawString == "hist":
#            graph.GetYaxis().SetRangeUser(0.,0.105)
            graph.GetYaxis().SetRangeUser(1e-6,0.6)
        graph.Draw(drawString)
        # graph.DrawNormalized(drawString)
        graphCounter += 1

    legend.Draw()
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)
def plotFakeRateDists2015(graphs,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.66,.69,.96,.90)
    legend.SetBorderSize(0)
    # legend.SetFillColor(0)
    # legend.SetFillStyle(0)
    # legend.SetTextFont(42)
    # legend.SetTextSize(0.028)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        # print graph.GetName()
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        # print graph.GetLineColor()
        x = Double()
        y = Double()
        graph.GetPoint(1,x,y)
        # print x,y
        drawString = "AL"
        if graphCounter>0:
            drawString="L"
        c.cd()
        graph.Draw(drawString)
        graphCounter += 1
    c.cd()
    legend.Draw()
    tl = TLatex()
    tl.SetNDC()
    tl.SetTextSize(0.042)
    txt = "CMS Preliminary   L = 2.6 fb^{-1}   #sqrt{s}=13 TeV"
    tl.DrawLatex(0.17,0.94,txt)
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)
def plotFakeRateDists(graphs,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.66,.69,.96,.90)
    legend.SetBorderSize(0)
    # legend.SetFillColor(0)
    # legend.SetFillStyle(0)
    # legend.SetTextFont(42)
    # legend.SetTextSize(0.028)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        # print graph.GetName()
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        # print graph.GetLineColor()
        x = Double()
        y = Double()
        graph.GetPoint(1,x,y)
        # print x,y
        drawString = "AL"
        if graphCounter>0:
            drawString="L"
        c.cd()
        graph.Draw(drawString)
        graphCounter += 1
    c.cd()
    legend.Draw()
    tl = TLatex()
    tl.SetNDC()
    tl.SetTextSize(0.042)
    txt = "CMS Preliminary   L = 35.9 fb^{-1}   #sqrt{s}=13 TeV"
    tl.DrawLatex(0.17,0.94,txt)
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)

# or any other TH1D comparison
def plotFakeRateRatios(graphs,legendheader,labels,outname,logy=False):
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
    legend.SetHeader(legendheader)

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

def makeRatioToFitPlot(num,fit,ratioName):

    ratio = num.Clone()
    ratio.SetName(ratioName)
    for i in range( ratio.GetN() ):
        x = Double()
        y = Double()
        ratio.GetPoint(i,x,y)
        fitAtX = fit.Eval(x)
        ratio.SetPoint(i, x, y/fitAtX )
    return ratio


def makePlots():
    fName = "diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histogramsTEMP.root"
    f = TFile(fName,'read')
    # f.Print()
    # f.ls()
 

    hists = []
    labels = []

    for cut in ("","noChIso","noPhoIso","noSieie","noHoverE","noCSEV","noChIsoLoose","noPhoIsoLoose"):
        histname = "phoPtEE_denominator_%s"%cut
        l = cut
        if cut == "":
            l = "all cuts"
            histname = "phoPtEE_denominator"
        h = f.Get(histname)
        h.GetXaxis().SetTitle("Photon p_{T} (GeV)")
        h.GetXaxis().SetRangeUser(0.,500.)
        h.GetYaxis().SetTitle("Normalized Units")
        h.GetYaxis().SetTitleOffset(1.4)
        h.Scale(1./h.Integral())

        hists.append(h)
        labels.append(l)

    plotFakeRateRatios(hists,labels,"denomCutComp.pdf",True)



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


def makePlots2():
    fname0 = "./denom0plots/fakeRatePlots.root"
    fname1 = "./denom1plots/fakeRatePlots.root"
    fname2 = "./denom2plots/fakeRatePlots.root"

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
            label = "Denominator Definition %i"%i
            fakerate = getDist(fnamedict[i],fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.2)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.15)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            else:
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)

    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"fakeRateDenomComparisonEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"fakeRateDenomComparisonEE.pdf")

def getHadronicOverEMFilename(num):
    if num == "000":
        return "./jethtvanillaplots/fakeRatePlots.root"
    else:
        return "./denomHadronicOverEm%s/fakeRatePlots.root"%num
def cutStrToNum(cut):
    newStr=""
    newStr += cut[0]
    newStr += "."
    newStr += cut[1]
    newStr += cut[2]
    return newStr
def makeChIsoComps():
    fName = "./denomHadronicOverEm010_mergedbins/fakeRatePlots.root"
    sidebands = (
        (5,10),
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
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        for sideband in sidebands:
            fakeratename = "fakeRate"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
            label = "Iso_{Ch} %iTo%i"%(sideband[0],sideband[1])

            fakerate = getDist(fName,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.2)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"fakeRateHEM010SidebandComparisonEB_mergedbins.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"fakeRateHEM010SidebandComparisonEE_mergedbins.pdf")

def makeChIsoRatios():
    fName = "./2015_newrealtemplate/fakeRatePlots.root"
    sidebands = (
        (5,10),
        (6,11),
        (7,12),
        (8,13),
        (9,14),
        (10,15),
        (15,20),
        (10,20)
    )

    fitEB = TF1("fitEB","[0]+[1]/x^[2]",0.001,13000.)
    fitEB.SetParameter(0,0.02878633423508)
    fitEB.SetParameter(1,1248.75225193085475)
    fitEB.SetParameter(2,2.46913565253256)


    fitEE = TF1("fitEE","(x<175)*([0]+[1]*(x-175)+[2]*(x-175)^2) + (x>=175)*([3]+[4]*x)",0.001,13000.)

    fitEE.SetParameter(0,0.07583552284680)
    fitEE.SetParameter(1,0.00006673122662)
    fitEE.SetParameter(2,0.00000287201688)
    fitEE.SetParameter(3,0.06415755818806)
    fitEE.SetParameter(4,0.00006673122662)

    ratiosEB=[]
    ratiosEE=[]
    labelsEB=[]
    labelsEE=[]

    for etaBin in ("EB","EE",):
        for sideband in sidebands:
            fakeratename = "fakeRate"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
            label = "Iso_{Ch} %iTo%i"%(sideband[0],sideband[1])

            fakerate = getDist(fName,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Ratio To Fit")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)

            # fakerate.GetYaxis().SetRangeUser(0.,0.12)
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.2)

            if etaBin == "EB":
                ratio = makeRatioToFitPlot(fakerate,fitEB,label)
                ratio.GetYaxis().SetRangeUser(0.6,1.2)
                ratio.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                ratiosEB.append(ratio)
                labelsEB.append(label)
                ## printout info for systematics
                if sideband[0] == 15:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(ratio.GetN()-1,x,y)
                    print "EB low:",y
                if sideband[0] == 5:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(ratio.GetN()-2,x,y)
                    print "EB high:",y

            if etaBin == "EE":
                ratio = makeRatioToFitPlot(fakerate,fitEE,label)
                ratio.GetYaxis().SetRangeUser(0.6,1.2)
                ratio.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                ratiosEE.append(ratio)
                labelsEE.append(label)
                if sideband[0] == 15:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(2,x,y)
                    print "EE low:",y
                if sideband[0] == 5:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(3,x,y)
                    print "EE high:",y
    plotFakeRateDists(ratiosEB,labelsEB,"fakeRateRatioToFitEB2015.pdf")
    plotFakeRateDists(ratiosEE,labelsEE,"fakeRateRatioToFitEE2015.pdf")

def makeChIsoRatios2016():
    fName = "./2016_newrealtemplate/fakeRatePlots.root"
    sidebands = (
        (5,10),
        (6,11),
        (7,12),
        (8,13),
        (9,14),
        (10,15),
        (15,20),
        (10,20)
    )

    fitEB = TF1("fitEB","[0]+[1]/x^[2]",0.001,13000.)
    fitEB.SetParameter(0,0.02878633423508)
    fitEB.SetParameter(1,1248.75225193085475)
    fitEB.SetParameter(2,2.46913565253256)


    fitEE = TF1("fitEE","[0]+[1]/x^[2]",0.001,13000.)

    fitEE.SetParameter(0,0.06879254775539)
    fitEE.SetParameter(1,23.26897380891171)
    fitEE.SetParameter(2,1.58780425789786)

    ratiosEB=[]
    ratiosEE=[]
    labelsEB=[]
    labelsEE=[]

    for etaBin in ("EB","EE",):
        for sideband in sidebands:
            fakeratename = "fakeRate"+etaBin+"_chIso%iTo%i"%(sideband[0],sideband[1])
            label = "Iso_{Ch} %iTo%i"%(sideband[0],sideband[1])

            fakerate = getDist(fName,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Ratio To Fit")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)

            # fakerate.GetYaxis().SetRangeUser(0.,0.12)
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.2)

            if etaBin == "EB":
                ratio = makeRatioToFitPlot(fakerate,fitEB,label)
                ratio.GetYaxis().SetRangeUser(0.6,1.4)
                ratio.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                ratiosEB.append(ratio)
                labelsEB.append(label)
                ## printout info for systematics
                if sideband[0] == 15:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(ratio.GetN()-1,x,y)
                    print "EB low:",y
                if sideband[0] == 5:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(ratio.GetN()-2,x,y)
                    print "EB high:",y

            if etaBin == "EE":
                ratio = makeRatioToFitPlot(fakerate,fitEE,label)
                ratio.GetYaxis().SetRangeUser(0.6,1.2)
                ratio.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                ratiosEE.append(ratio)
                labelsEE.append(label)
                if sideband[0] == 15:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(1,x,y)
                    print "EE low:",y
                if sideband[0] == 5:
                    x = Double()
                    y = Double()
                    ratio.GetPoint(5,x,y)
                    print "EE high:",y
    plotFakeRateDists(ratiosEB,labelsEB,"fakeRateRatioToFitEB2016.pdf")
    plotFakeRateDists(ratiosEE,labelsEE,"fakeRateRatioToFitEE2016.pdf")
def makeJetPtComps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        for ptcut in ("none","175","300"):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "leading jet pT > %s GeV"%ptcut
            if ptcut == "none":
                label = "leading jet pT > 30 GeV"
            fileloc = "./denomHadronicOverEm010_leadJetPtGT%s/fakeRatePlots.root"%ptcut
            if ptcut == "none":
                fileloc = "./denomHadronicOverEm010/fakeRatePlots.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.2)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"leadJetPtCompEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"leadJetPtCompEE.pdf")
def makePileupComps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    d = {
    "low":"0-9",
    "med":"10-12",
    "high":"13-100000"
    }

    for etaBin in ("EB","EE",):
        # for pileup in ("none","low","med","high"):
        for pileup in ("low","med","high"):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "nPV %s"%d[pileup]
            if pileup == "high":
                label = "nPV 13-Inf"
            fileloc = "./olddir/denomHadronicOverEm010_%sPU2015/fakeRatePlots.root"%pileup
            if pileup != "none" and etaBin == "EE":
                fileloc = "./jetht_fakerate_2015_nPV%s_phoIsoTight/fakeRatePlots.root"%d[pileup]
            # if pileup == "none" and etaBin == "EB":
            #     fileloc = "./olddir/denomHadronicOverEm010/fakeRatePlots.root"
            # if pileup == "none" and etaBin == "EE":
            #     fileloc = "./jetht_fakerate_2015_phoIsoTight/fakeRatePlots.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)

            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.6)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists2015(fakeratesEB,labels_fakeratesEB,"pileup2015CompEB.pdf")
    plotFakeRateDists2015(fakeratesEE,labels_fakeratesEE,"pileup2015CompEE.pdf")

def makePileup2016Comps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        # for pileup in ("none","0-13","14-17","18-20","21-24","25-Inf"):
        for year in ("2015","2016"):
            pileup = "7-15"
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "%s"%year
            if pileup == "none":
                label = "no pileup cut"
            fileloc = "./denomtightphoiso_%s/fakeRatePlots_PV7-15.root"%(year)
            if pileup == "none":
                fileloc = "./denomHadronicOverEm010_2016/fakeRatePlots.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.4)
            if etaBin == "EB":
                fakerate.GetYaxis().SetRangeUser(0.,0.55)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup20152016Comp_denomtightphoiso_EB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup20152016Comp_denomtightphoiso_EE.pdf")

def makePileup2016Comps2():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    labelMap = {
        "currentDenomDef" : "currentDenomDef (phoIso < 0.2*pT)",
        "phoIsoTight" : "phoIsoNumeratorCut",
        "phoIso5GeV" : "phoIso < 5 GeV",
        "phoIso8GeV" : "phoIso < 8 GeV",
        "phoIso0p05Pt" : "phoIso < 0.05*pT",
        "phoIso0p1Pt" : "phoIso < 0.1*pT"
    }

    yearPUMap = {
    "2015" : "10-13",
    "2016" : "9-12"
    }

    for etaBin in ("EB","EE",):
        for year in ("2015","2016"):
            for denom in ("currentDenomDef","phoIsoTight","phoIso5GeV","phoIso8GeV","phoIso0p05Pt","phoIso0p1Pt"):
                pileup = yearPUMap[year]
                fakeratename = "fakeRate"+etaBin+"_chIso5To10"
                label = "%s %s"%(year,labelMap[denom])
                fileloc = ""
                if denom != "phoIsoTight":
                    fileloc = "./froutput/%s_nPV%s_%s/fakeRatePlots.root"%(year,pileup,denom)
                elif denom == "phoIsoTight" and etaBin == "EB":
                    fileloc = "./froutput/%s_nPV%s_phoIso2p75GeV/fakeRatePlots.root"%(year,pileup)
                elif denom == "phoIsoTight" and etaBin == "EE":
                    fileloc = "./froutput/%s_nPV%s_phoIso2GeV/fakeRatePlots.root"%(year,pileup)
                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.4)
                if etaBin == "EB":
                    fakerate.GetYaxis().SetRangeUser(0.,0.55)
                if denom != "phoIsoTight":
                    fakerate.GetYaxis().SetRangeUser(0.,0.25)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                # if etaBin == "EE":
                #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
                if etaBin == "EB":
                    fakeratesEB.append(fakerate)
                    labels_fakeratesEB.append(label)
                if etaBin == "EE":
                    fakeratesEE.append(fakerate)
                    labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup20152016Comp_denomcomp_EB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup20152016Comp_denomcomp_EE.pdf")

    for etaBin in ("EB","EE",):
        for denom in ("currentDenomDef","phoIsoTight","phoIso5GeV","phoIso8GeV","phoIso0p05Pt","phoIso0p1Pt"):
            frs = []
            lbls = []
            for year in ("2015","2016"):
                pileup = yearPUMap[year]
                fakeratename = "fakeRate"+etaBin+"_chIso5To10"
                label = "%s %s"%(year,labelMap[denom])
                fileloc = ""
                if denom != "phoIsoTight":
                    fileloc = "./froutput/%s_nPV%s_%s/fakeRatePlots.root"%(year,pileup,denom)
                elif denom == "phoIsoTight" and etaBin == "EB":
                    fileloc = "./froutput/%s_nPV%s_phoIso2p75GeV/fakeRatePlots.root"%(year,pileup)
                elif denom == "phoIsoTight" and etaBin == "EE":
                    fileloc = "./froutput/%s_nPV%s_phoIso2GeV/fakeRatePlots.root"%(year,pileup)
                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.4)
                if etaBin == "EB":
                    fakerate.GetYaxis().SetRangeUser(0.,0.55)
                if denom != "phoIsoTight":
                    fakerate.GetYaxis().SetRangeUser(0.,0.25)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                # if etaBin == "EE":
                #     fakerate.GetYaxis().SetRangeUser(0.,0.16)

                frs.append(fakerate)
                lbls.append(label)
            outname = "pileup20152016Comp_denomcomp_"+denom+"_"+etaBin+".pdf"
            plotFakeRateDists(frs,lbls,outname)

def makePileup2016Comps3():

    yearPUMap = {
    "2015" : "10-13",
    "2016" : "9-12"
    }

    for cut in ("PFHT800","PFHT900"):
        fakeratesEB=[]
        fakeratesEE=[]
        labels_fakeratesEB=[]
        labels_fakeratesEE=[]
        for etaBin in ("EB","EE"):
        # for pileup in ("none","0-13","14-17","18-20","21-24","25-Inf"):
            for year in ("2015","2016"):
                pileup = yearPUMap[year]
                fakeratename = "fakeRate"+etaBin+"_chIso5To10"
                label = "%s"%year

                fileloc = ""
                if etaBin == "EB":
                    fileloc = "./%s_PUBin_%s_phoIso2p75GeV/fakeRatePlots.root"%(year,cut)
                if etaBin == "EE":
                    fileloc = "./%s_PUBin_%s_phoIso2GeV/fakeRatePlots.root"%(year,cut)
                
                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.4)
                if etaBin == "EB":
                    fakerate.GetYaxis().SetRangeUser(0.,0.55)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                # if etaBin == "EE":
                #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
                if etaBin == "EB":
                    fakeratesEB.append(fakerate)
                    labels_fakeratesEB.append(label)
                if etaBin == "EE":
                    fakeratesEE.append(fakerate)
                    labels_fakeratesEE.append(label)
        plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup20152016Comp_%s_phoIsoTight_EB.pdf"%cut)
        plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup20152016Comp_%s_phoIsoTight_EE.pdf"%cut)

def makePileup2016Comps4():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]



    for etaBin in ("EB","EE",):
        for pileup in ("0-13","14-17","18-20","21-24","25-100000"):
        # for year in ("2015","2016"):
        #     pileup = "7-15"
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "nPV %s"%pileup
            if pileup == "25-100000":
                label = "nPV 25-Inf"
            fileloc = "./jetht_fakerate_2016_nPV%s_withplots_currentDenomDef/fakeRatePlots.root"%(pileup)

            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.16)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup2016CompEB_oldDenomDef.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup2016CompEE_oldDenomDef.pdf")

def makePileup2016Comps5():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]



    for etaBin in ("EB","EE",):
        for pileup in ("0-13","14-17","18-20","21-24","25-100000"):
        # for year in ("2015","2016"):
        #     pileup = "7-15"
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "nPV %s"%pileup
            if pileup == "25-100000":
                label = "nPV 25-Inf"
            fileloc = "./jetht_fakerate_2016_nPV%s_withplots_currentDenomDef/fakeRatePlots.root"%pileup
            if etaBin == "EE":
                fileloc = "./jetht_fakerate_2016_nPV%s_phoIsoTight/fakeRatePlots.root"%(pileup)

            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.6)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup2016CompEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup2016CompEE.pdf")

def makePileup2016CompsSplitEra():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    labelMap = {
        "currentDenomDef" : "currentDenomDef (phoIso < 0.2*pT)",
        "phoIsoTight" : "phoIsoNumeratorCut",
        "phoIso5GeV" : "phoIso < 5 GeV",
        "phoIso8GeV" : "phoIso < 8 GeV",
        "phoIso0p05Pt" : "phoIso < 0.05*pT",
        "phoIso0p1Pt" : "phoIso < 0.1*pT"
    }

    yearPUMap = {
    "2015" : "10-13",
    "2016BF" : "9-12",
    "2016GH" : "9-12",
    }

    for etaBin in ("EB","EE",):
        for year in ("2015","2016BF","2016GH"):
            for denom in ("currentDenomDef",):
                pileup = yearPUMap[year]
                fakeratename = "fakeRate"+etaBin+"_chIso5To10"
                label = "%s %s"%(year,labelMap[denom])
                fileloc = ""
                if year == "2015":
                    fileloc = "./froutput/2015_nPV%s_%s/fakeRatePlots.root"%(pileup,denom)
                else:
                    fileloc = "./%s/fakeRatePlots.root"%year

                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.4)
                if etaBin == "EB":
                    fakerate.GetYaxis().SetRangeUser(0.,0.55)
                if denom != "phoIsoTight":
                    fakerate.GetYaxis().SetRangeUser(0.,0.15)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                # if etaBin == "EE":
                #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
                if etaBin == "EB":
                    fakeratesEB.append(fakerate)
                    labels_fakeratesEB.append(label)
                if etaBin == "EE":
                    fakeratesEE.append(fakerate)
                    labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup20152016Comp_splitera_EB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup20152016Comp_splitera_EE.pdf")

def makePileup2016EtaBinComps():

    labelMap = {
        "currentDenomDef" : "currentDenomDef (phoIso < 0.2*pT)",
        "phoIsoTight" : "phoIsoNumeratorCut",
        "phoIso5GeV" : "phoIso < 5 GeV",
        "phoIso8GeV" : "phoIso < 8 GeV",
        "phoIso0p05Pt" : "phoIso < 0.05*pT",
        "phoIso0p1Pt" : "phoIso < 0.1*pT"
    }

    yearPUMap = {
    "2015" : "10-13",
    "2016" : "9-12"
    }

    for denom in ("currentDenomDef","phoIsoTight","phoIso5GeV","phoIso8GeV","phoIso0p05Pt","phoIso0p1Pt"):
        fakerates=[]
        labels=[]
        for year in ("2015","2016"):
            for etaBin in ("EB1","EB2","EE1","EE2"):
                pileup = yearPUMap[year]
                fakeratename = "fakeRate"+etaBin[:2]+"_chIso5To10"
                label = "%s %s"%(year,etaBin)
                postFix = "etaFirstHalf"
                if etaBin[-1] == "2":
                    postFix = "etaSecondHalf"
                fileloc = ""
                if denom != "phoIsoTight":
                    fileloc = "./froutput/%s_nPV%s_%s_%s/fakeRatePlots.root"%(year,pileup,denom,postFix)
                elif denom == "phoIsoTight" and "EB" in etaBin:
                    fileloc = "./froutput/%s_nPV%s_phoIso2p75GeV_%s/fakeRatePlots.root"%(year,pileup,postFix)
                elif denom == "phoIsoTight" and "EE" in etaBin:
                    fileloc = "./froutput/%s_nPV%s_phoIso2GeV_%s/fakeRatePlots.root"%(year,pileup,postFix)
                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.4)
                if "EB" in etaBin:
                    fakerate.GetYaxis().SetRangeUser(0.,0.55)
                if denom != "phoIsoTight":
                    fakerate.GetYaxis().SetRangeUser(0.,0.25)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                # if etaBin == "EE":
                #     fakerate.GetYaxis().SetRangeUser(0.,0.16)

                fakerates.append(fakerate)
                labels.append(label)
        plotFakeRateDists(fakerates,labels,"pileup20152016Comp_%s_etasplitting.pdf"%denom)


def makePileup2016CompsMuon():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        for pileup in ("none","0-13","14-17","18-20","21-24","25-Inf"):
        # for year in ("2015","2016"):
        #     pileup = "7-15"
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "%s"%pileup
            if pileup == "none":
                label = "no pileup cut"
            fileloc = "./pvfiles_muon_numfr/fakeRatePlots_PV%s.root"%(pileup)
            if pileup == "none":
                fileloc = "./pvfiles_muon_numfr/fakeRatePlots_noPVCut.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.16)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"pileup2016MuonCompEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"pileup2016MuonCompEE.pdf")

def makePileup2016Ratios():

    ratiosEB=[]
    ratiosEE=[]
    labelsEB=[]
    labelsEE=[]

    for etaBin in ("EB","EE",):
        for pileup in ("none","0-13","14-17","18-20","21-24","25-Inf"):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "nPV %s "%pileup
            nomloc = "./denomHadronicOverEm010_2016/fakeRatePlots.root"
            if pileup == "none":
                label = "no pileup cut"
            fileloc = "./denomHadronicOverEm010_PV%s_2016/fakeRatePlots.root"%pileup
            if pileup == "none":
                fileloc = nomloc
            fakerate = getDist(fileloc,fakeratename)
            fakeratenom = getDist(nomloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            ratio = makeRatioPlot(fakerate,fakeratenom,"")
            ratio.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            ratio.GetYaxis().SetTitle("FR / Nominal FR")
            # fakerate.GetYaxis().SetRangeUser(0.,0.16)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.16)
            if etaBin == "EB":
                ratiosEB.append(ratio)
                labelsEB.append(label)
            if etaBin == "EE":
                ratiosEE.append(ratio)
                labelsEE.append(label)
    plotFakeRateRatios(ratiosEB,"",labelsEB,"pileup2016RatiosEB.pdf")
    plotFakeRateRatios(ratiosEE,"",labelsEE,"pileup2016RatiosEE.pdf")

def makeRealTemplateComparisonPU():

    templatesEB=[]
    templatesEE=[]
    labelsEB=[]
    labelsEE=[]

    for etaBin in ("EB","EE",):
        for pileup in ("none","0-13","14-17","18-20","21-24","25-Inf"):
            templatename = "sieie"+etaBin+"_realtemplate_pt50To70"
            label = "nPV %s "%pileup
            nomloc = "../../MCFakeRateAnalysis/analysis/GGJets_M-200To500_vanilla.root"
            if pileup == "none":
                label = "no pileup cut"
            fileloc = "../../MCFakeRateAnalysis/analysis/GGJets_M-200To500_PV%s.root"%pileup
            if pileup == "none":
                fileloc = nomloc
            f = TFile(fileloc,"read")
            # template = getDist(fileloc,templatename)
            template = getHist(f,templatename)
            # template.SetDirectory(0)
            # print etaBin,pileup,template.GetName()
            template.SetTitle("")
            template.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
            template.GetYaxis().SetTitle("Arbitrary Units")
            template.GetYaxis().SetTitleOffset(1.4)
            template.GetXaxis().SetRangeUser(0.,0.02)
            if etaBin == "EE":
                template.GetXaxis().SetRangeUser(0.01,0.04)
            if etaBin == "EB":
                templatesEB.append(template)
                labelsEB.append(label)
            if etaBin == "EE":
                templatesEE.append(template)
                labelsEE.append(label)
    plotFakeRateRatios(templatesEB,"",labelsEB,"realtemplatecompEB.pdf")
    plotFakeRateRatios(templatesEE,"",labelsEE,"realtemplatecompEE.pdf")


def makeTriggerComps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        for level in ("none","singleJetLow","singleJetHigh","htLow","htHigh"):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "%s"%level
            if level == "none":
                label = "no trigger cut"
            fileloc = "./denomHadronicOverEm010_%s/fakeRatePlots.root"%level
            if level == "none":
                fileloc = "./denomHadronicOverEm010_2016/fakeRatePlots.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            # if etaBin == "EE":
            #     fakerate.GetYaxis().SetRangeUser(0.,0.2)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"triggerCompEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"triggerCompEE.pdf")


def makeJetMatchingComps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        for match in ("none","Leading","Subleading","ThirdLeading"):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "Matched to %s Jet"%match
            if match == "none":
                label = "No Jet Matching Performed"
            fileloc = "./denomHadronicOverEm010_matchedTo%sJet/fakeRatePlots.root"%match
            if match == "none":
                fileloc = "./denomHadronicOverEm010/fakeRatePlots.root"
            fakerate = getDist(fileloc,fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            # c = TCanvas()
            # fakerate.Draw("AL")
            # raw_input("Enter to continue: ")
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.2)
            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"jetMatchCompEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"jetMatchCompEE.pdf")

def makeJetMatchingMuonComps():

    for trig in ("","_PFHT900"):
        fakeratesEB=[]
        fakeratesEE=[]
        labels_fakeratesEB=[]
        labels_fakeratesEE=[]
        for etaBin in ("EB","EE",):
            for match in ("DoubleMuon","Leading","Subleading"):
                if match == "Subleading":
                    continue
                fakeratename = "fakeRate"+etaBin+"_chIso5To10"
                label = "Matched to %s Jet"%match
                if match == "DoubleMuon":
                    label = match
                fileloc = "./jetht_fakerate_2016_matchedto%sJet%s/fakeRatePlots.root"%(match,trig)
                if match == "DoubleMuon":
                    fileloc = "./doublemuon_fakerate_2016/fakeRatePlots.root"
                fakerate = getDist(fileloc,fakeratename)
                fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
                fakerate.GetYaxis().SetTitle("Fake Rate")
                fakerate.GetYaxis().SetTitleOffset(1.4)
                fakerate.GetXaxis().SetRangeUser(0.,600.)
                fakerate.GetYaxis().SetRangeUser(0.,0.12)
                # c = TCanvas()
                # fakerate.Draw("AL")
                # raw_input("Enter to continue: ")
                if etaBin == "EE":
                    fakerate.GetYaxis().SetRangeUser(0.,0.5)
                if etaBin == "EB":
                    fakeratesEB.append(fakerate)
                    labels_fakeratesEB.append(label)
                if etaBin == "EE":
                    fakeratesEE.append(fakerate)
                    labels_fakeratesEE.append(label)
        plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"jetMatchMuonCompEB%s.pdf"%trig)
        plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"jetMatchMuonCompEE%s.pdf"%trig)
def makeHadronicOverEMComps():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        hemcuts = reversed(("000","005","006","007","008","009","010","011","012","013","014","015"))
        for hemcut in hemcuts:
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "hadronicOverEm < %s"%cutStrToNum(hemcut)
            if hemcut == "000":
                label = "current denominator definition"
            fakerate = getDist(getHadronicOverEMFilename(hemcut),fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.2)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"EB.pdf") # I screwed this up but hopefully fixed it. Change the filenames if you use this again
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"EE.pdf")

def makeHadronicOverEMComps2():

    fakeratesEB=[]
    fakeratesEE=[]
    labels_fakeratesEB=[]
    labels_fakeratesEE=[]

    for etaBin in ("EB","EE",):
        hemcuts = (0.,0.10,0.10,)
        fdict = {
            0 : "./jethtvanillaplots/fakeRatePlots.root",
            1 : "./denomHadronicOverEm010/fakeRatePlots.root",
            2 : "./denomHadronicOverEm010_mergedbins/fakeRatePlots.root"
        }
        # hemcuts = reversed(("000","005","006","007","008","009","010","011","012","013","014","015"))
        for i,hemcut in enumerate(hemcuts):
            fakeratename = "fakeRate"+etaBin+"_chIso5To10"
            label = "hadronicOverEm < %s"%str(hemcut)
            if hemcut <0.05:
                label = "current denominator definition"
            elif i==2:
                label = "hadronicOverEm < 0.10 (merged bins)"


            fakerate = getDist(fdict[i],fakeratename)
            fakerate.GetXaxis().SetTitle("Photon p_{T} (GeV)")
            fakerate.GetYaxis().SetTitle("Fake Rate")
            fakerate.GetYaxis().SetTitleOffset(1.4)
            fakerate.GetXaxis().SetRangeUser(0.,600.)
            fakerate.GetYaxis().SetRangeUser(0.,0.12)
            if etaBin == "EE":
                fakerate.GetYaxis().SetRangeUser(0.,0.2)

            if etaBin == "EB":
                fakeratesEB.append(fakerate)
                labels_fakeratesEB.append(label)
            if etaBin == "EE":
                fakeratesEE.append(fakerate)
                labels_fakeratesEE.append(label)
    plotFakeRateDists(fakeratesEB,labels_fakeratesEB,"fakeRateHEM010ComparisonEB.pdf")
    plotFakeRateDists(fakeratesEE,labels_fakeratesEE,"fakeRateHEM010ComparisonEE.pdf")


def makeSieieComps():
    
    fname0 = "./jetht_denom2.root"
    fname1 = "./muondatahists.root"

    f0 = TFile(fname0)
    f1 = TFile(fname1)

    fnamedict = {
        0 : f0,
        1 : f1
    }
    ptarraydict = {
        0 : [ 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 600 ],
        1 : [ 30, 50, 70, 90, 110, 130, 150, 200, 250, 300, 14000 ]
    }

    # # f = TFile(fname0,"read")
    # # g = f.Get("sieieEB_faketemplate_pt110To130_chIso9To14")
    # # g= getDist2(fname0,"sieieEB_faketemplate_pt110To130_chIso9To14")
    # # g = getDist2("../../RooFitTemplateFitting/analysis/singlejettriggerplots/fakeRatePlots_SingleJetTriggers.root","fakeRateEB_chIso9To14")
    # f = TFile("../../RooFitTemplateFitting/analysis/singlejettriggerplots/fakeRatePlots_SingleJetTriggers.root")
    # g2 = getHist(f,"fakeRateEB_chIso9To14")
    # # g,g2 = getDist3("../../RooFitTemplateFitting/analysis/singlejettriggerplots/fakeRatePlots_SingleJetTriggers.root",("fakeRateEB_chIso9To14","phoPtEB_denominator_varbin"))
    # # print type(g)
    # print type(g2)
    # # c = TCanvas()
    # # g.Draw()
    # c2 = TCanvas()
    # c2.cd()
    # g2.Draw()
    # raw_input("enter to quit: ")

    nBins = len(ptarraydict[0])-1
    sieieEB_jet = []
    sieieEE_jet = []

    sieieEB_muon = []
    sieieEE_muon = []

    for etaBin in ("EB","EE"):
        for i in (0,1):
            for iBin in range(nBins):
                ptStr = "%iTo%i"%(ptarraydict[i][iBin],ptarraydict[i][iBin+1])
                fullStr = "sieie%s_faketemplate_pt%s_chIso6To11"%(etaBin,ptStr)
                # f = TFile(fnamedict[i])
                plot = getHist(fnamedict[i],fullStr)
                # print type(plot)
                if etaBin == "EB" and i==0:
                    sieieEB_jet.append(plot)
                elif etaBin == "EB" and i==1:
                    sieieEB_muon.append(plot)
                elif etaBin == "EE" and i==0:
                    sieieEE_jet.append(plot)
                elif etaBin == "EE" and i==1:
                    sieieEE_muon.append(plot)
                # f.Close()
    # c = TCanvas()
    # sieieEB_jet[0].Draw()
    # raw_input("enter: ")
    for iBin in range( len(sieieEB_jet) ):
        ptStr = "%iTo%i"%(ptarraydict[0][iBin],ptarraydict[0][iBin+1])
        # plotFakeRateRatios([ sieieEB_jet[iBin],sieieEB_muon[iBin] ], ["JetHT","SingleMuon"],"fakeTemplateCompEB_pT%s_linearY.pdf"%ptStr)
        # plotFakeRateRatios([sieieEE_jet[iBin],sieieEE_muon[iBin]], ["JetHT","SingleMuon"],"fakeTemplateCompEE_pT%s_linearY.pdf"%ptStr)
        # plotFakeRateRatios([ sieieEB_jet[iBin],sieieEB_muon[iBin] ], ["JetHT","SingleMuon"],"fakeTemplateCompEB_pT%s_logY.pdf"%ptStr,True)
        # plotFakeRateRatios([sieieEE_jet[iBin],sieieEE_muon[iBin]], ["JetHT","SingleMuon"],"fakeTemplateCompEE_pT%s_logY.pdf"%ptStr,True)
        plotFakeRateRatios([ sieieEB_jet[iBin],sieieEB_muon[iBin] ],"EB_pT"+ptStr, ["JetHT","SingleMuon"],"fakeTemplateCompEB_pT%s_linearY.pdf"%ptStr)
        plotFakeRateRatios([sieieEE_jet[iBin],sieieEE_muon[iBin]], "EE_pT"+ptStr,["JetHT","SingleMuon"],"fakeTemplateCompEE_pT%s_linearY.pdf"%ptStr)
        plotFakeRateRatios([ sieieEB_jet[iBin],sieieEB_muon[iBin] ],"EB_pT"+ptStr, ["JetHT","SingleMuon"],"fakeTemplateCompEB_pT%s_logY.pdf"%ptStr,True)
        plotFakeRateRatios([sieieEE_jet[iBin],sieieEE_muon[iBin]], "EE_pT"+ptStr,["JetHT","SingleMuon"],"fakeTemplateCompEE_pT%s_logY.pdf"%ptStr,True)

def toToRange(t):
    r = t.replace("To"," < p_{T} < ")
    r = r + "GeV"
    return r
def makeFakeTemplateComparison(dataset, year):

    templatesEB=[]
    templatesEE=[]
    labelsEB=[]
    labelsEE=[]
    ptBins = {"jetht" : ("50To70","110To130","200To250","300To600"),
              "doublemuon": ("50To70","110To130","150To600")}

    gStyle.SetOptStat(0)

    for etaBin in ("EB","EE",):
        for ptBin in ptBins[dataset]:
            templatename = "sieie"+etaBin+"_faketemplate_pt"+ptBin+"_chIso5To10"
#            fileloc = "../../DataFakeRateAnalysis/analysis/jetht_fakerate_2016_matchedtoLeadingJet_newDenomDef.root"
#            fileloc = "../../DataFakeRateAnalysis/analysis/" + dataset + "_fakerate_2018_newDenomDef.root"
            fileloc = "/eos/uscms/store/user/cawest/fake_rate/" + dataset + "_fakerate_" + year + "_nPV0-200_newDenomDef.root"
            f = TFile(fileloc,"read")
            # template = getDist(fileloc,templatename)
            template = getHist(f,templatename)
            # template.SetDirectory(0)
            # print etaBin,pileup,template.GetName()
            label = toToRange(ptBin)
            template.SetTitle("")
            template.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
            template.GetYaxis().SetTitle("Arbitrary Units")
            template.GetYaxis().SetTitleOffset(1.4)
            template.GetXaxis().SetRangeUser(0.,0.03)
            template.GetYaxis().SetRangeUser(0.,0.22)
            if etaBin == "EE":
                template.GetXaxis().SetRangeUser(0.,0.07)
                template.GetYaxis().SetRangeUser(0.,0.1)
            if etaBin == "EB":
                templatesEB.append(template)
                labelsEB.append(label)
            if etaBin == "EE":
                templatesEE.append(template)
                labelsEE.append(label)
    plotNormTH1Ds(templatesEB,"",labelsEB,"faketemplatecompEB_" + dataset + "_" + year + ".pdf", True)
    plotNormTH1Ds(templatesEE,"",labelsEE,"faketemplatecompEE_" + dataset + "_" + year + ".pdf", True)

def makeRealTemplateComparison(year):

    templatesEB=[]
    templatesEE=[]
    labelsEB=[]
    labelsEE=[]
    cmssw = {"2016" : "76X", "2016" : "76X", "2017" : "94X", "2018" : "102X"}

    gStyle.SetOptStat(0)

    for etaBin in ("EB","EE",):
        for ptBin in ("50To70","110To130","200To250","300To600"):
            templatename = "sieie"+etaBin+"_realtemplate_pt"+ptBin
#            fileloc = "../../RealTemplateAnalysis/analysis/diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms_JetHT.root"
            fileloc = "../../RealTemplateAnalysis/analysis/diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_MiniAOD_histograms.root"
            fileloc = "/eos/uscms/store/user/cawest/fake_rate/diphoton_fake_rate_real_templates_all_GGJets_GJets_" + cmssw[year] + "_nPV0-200_MiniAOD_histograms.root"

            f = TFile(fileloc,"read")
            # template = getDist(fileloc,templatename)
            template = getHist(f,templatename)
            # template.SetDirectory(0)
            # print etaBin,pileup,template.GetName()
            label = toToRange(ptBin)
            template.SetTitle("")
            template.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
            template.GetYaxis().SetTitle("Arbitrary Units")
            template.GetYaxis().SetTitleOffset(1.4)
            template.GetXaxis().SetRangeUser(0.,0.02)
            template.GetXaxis().SetNdivisions(4+(5*100))
            # template.GetYaxis().SetRangeUser(0.,0.55)

            # TGaxis.SetMaxDigits(2);

            if etaBin == "EE":
                template.GetXaxis().SetRangeUser(0.,0.07)
                template.GetXaxis().SetNdivisions(7+(5*100))
                template.GetYaxis().SetRangeUser(0.000001,0.6)
            if etaBin == "EB":
                templatesEB.append(template)
                labelsEB.append(label)
            if etaBin == "EE":
                templatesEE.append(template)
                labelsEE.append(label)
    plotNormTH1Ds(templatesEB,"",labelsEB,"realtemplatecompEB_" + year + ".pdf",True)
    plotNormTH1Ds(templatesEE,"",labelsEE,"realtemplatecompEE_" + year + ".pdf",True)

if __name__ == "__main__":
    # setTDRStyle()
    # gStyle.SetMarkerStyle()
    # gROOT.ForceStyle()
    # makePlots()
    # makePlots2()
    # makeChIsoComps()
    # makeChIsoRatios()
    # makeHadronicOverEMComps2()
    # makeSieieComps()
    # makeJetPtComps()
    # makePileup2016Comps()
    # makeTriggerComps()
    # makePileup2016Ratios()
    # makePileup2016Comps()
    # makePileup2016Comps2()
    # makePileup2016Comps3()
    # makeChIsoRatios()
    # makeChIsoRatios2016()
    # makeJetMatchingMuonComps()
    # makePileup2016Comps4()
    # makePileup2016Comps5()
    # makePileupComps()
    # makePileup2016CompsSplitEra()
    # makePileup2016EtaBinComps()
    # makeJetMatchingComps()
    # makeRealTemplateComparisonPU()
    # makePileup2016CompsMuon()
    makeFakeTemplateComparison("jetht", "2016")
    makeFakeTemplateComparison("jetht", "2017")
    makeFakeTemplateComparison("jetht", "2018")
    makeFakeTemplateComparison("doublemuon", "2016")
    makeFakeTemplateComparison("doublemuon", "2017")
    makeFakeTemplateComparison("doublemuon", "2018")
    makeRealTemplateComparison("2016")
    makeRealTemplateComparison("2017")
    makeRealTemplateComparison("2018")
