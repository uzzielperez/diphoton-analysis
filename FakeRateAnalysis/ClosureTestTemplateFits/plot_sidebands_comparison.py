#!/usr/bin/python

import ROOT
from ROOT import *
import sys

##################
#
# This code overlays Real, Fake and Numerator Templates
# Needs input files from RealTemplateAnalysis/analysis/MCFakeRateAnalysis.C &
# PhotonClosure/analysis/MCFakeRateAnalysis.C
#
#################

import argparse

# Command Line Options
parser = argparse.ArgumentParser(description='plots templates')
parser.add_argument('-e', '--era', help='dummy, 2016, 2017, 2018', default='dummy', type=str)
args = parser.parse_args()

# To supress canvas from popping up. Speeds up plots production
gROOT.SetBatch()
gStyle.SetOptStat(0)

era = args.era
cmssw_version = {
  "2016": "76X",
  "2017": "94X",
  "2018": "102X"
}
base = "/uscms_data/d3/cuperez/tribosons/FakeRate/CMSSW_10_2_18/src/";

if era == "dummy":
    PTBINS = [ 50, 70, 90, 130, 200, 600 ];
else:
    PTBINS = [ 50, 70, 90, 110, 130, 150, 200, 250, 300, 600 ];

# chIsoSidebands = [[5, 7],[10, 15]]
color = []

def GetHistObj(histname, openfile):
    fi = openfile
    obj = "notfound"
    for key in fi.GetListOfKeys():
        keyName = key.GetName()
        hObj = fi.Get(keyName)
        if histname in keyName:
            obj = hObj
            #print key, keyName, hObjName
    if obj != "notfound":
        # print obj
        return obj

def GetHist(ptbin, isEB, type, chIsosideband=None):

  etaBin = ("EE", "EB")[isEB]
  sideband = chIsosideband

  if type == "Real":
      if era == "dummy":
          filename = "diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root"
      else:
          filename = "%sdiphoton_fake_rate_real_templates_all_GGJets_GJets_%s_nPV0-200_MiniAOD_histograms.root" %(base, cmssw_version[era])
      histname = "sieie" + etaBin + "_realtemplate_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      # fillstyle = 3001
      drawAs = "hist, same"
  elif type == "Truth":
      if era == "dummy":
          filename = "diphoton_fake_rate_closure_test_matching_all_samples_80X_MiniAOD_histograms_test.root"
      else:
          filename = "%sdiphoton_fake_rate_closure_test_matching_all_samples_%s_MiniAOD_histograms.root" %(base, cmssw_version[era])
      histname = "sieie" + etaBin + "_numerator_fakes_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      drawAs = "hist, same"
  else:
      if era == "dummy":
          filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root"
      else:
          filename = "%sdiphoton_fake_rate_closure_test_all_samples_%s_MiniAOD_histograms.root" %(base, cmssw_version[era])
  if type == "Numerator":
      histname = "sieie" + etaBin + "_numerator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      drawAs = "e, same"
  if type == "Denominator":
      histname = "sieie" + etaBin + "_denominator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
  if type == "Fake":
      if era == "dummy":
          filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root"
      else:
          filename = "%sdiphoton_fake_rate_closure_test_all_samples_%s_MiniAOD_histograms.root" %(base, cmssw_version[era])
      histname = "sieie" + etaBin + "_faketemplate_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1]) + "_chIso" + sideband;
      drawAs = "hist, same"

  f = ROOT.TFile(filename, "READ")
  h = f.Get(histname)
  h = GetHistObj(histname, f)
  h.SetDirectory(0)
  #h.Draw(drawAs)
  print histname
  return h, histname

def LoopOverPtbinsPlots(isEB):
    # EB Templates
    for ptbin in range(len(PTBINS)-1):
        c = ROOT.TCanvas()

        hNumerator, NumLabel = GetHist(ptbin, isEB, "Numerator")
        hMCTruth, MCTruthlabel = GetHist(ptbin, isEB, "Truth")
        hFake_chIso_5To10, Fakelabel_chIso_5To10 = GetHist(ptbin, isEB, "Fake", "5To10")
        hFake_chIso_10To15, Fakelabel_chIso_10To15 = GetHist(ptbin, isEB, "Fake", "10To15")

        #hMCTruth.SetMaximum(3 * hMCTruth.GetMaximum())
        hMCTruth.SetLineColor(kOrange-5)
        hMCTruth.Scale(1/hMCTruth.Integral())
        hFake_chIso_5To10.SetLineColor(kBlack)
        hFake_chIso_5To10.Scale(1/hFake_chIso_5To10.Integral())
        hFake_chIso_10To15.SetLineColor(kRed)
        hFake_chIso_10To15.Scale(1/hFake_chIso_10To15.Integral())

        hMaxList = []
        hMaxList.append(hMCTruth.GetMaximum())
        hMaxList.append(hFake_chIso_5To10.GetMaximum())
        hMaxList.append(hFake_chIso_10To15.GetMaximum())
        if max(hMaxList)==hMaxList[0]:
            hDrawFirst = hMCTruth
        elif max(hMaxList)==hMaxList[1]:
            hDrawFirst = hFake_chIso_5To10
        elif max(hMaxList)==hMaxList[2]:
            hDrawFirst = hFake_chIso_10To15

        xMax = (0.08, 0.03)[isEB]
        hDrawFirst.GetXaxis().SetTitleOffset(1)
        hDrawFirst.GetXaxis().SetRangeUser(0, xMax)
        hDrawFirst.GetXaxis().SetTitle("#sigma_{i#etai#eta}")
        hDrawFirst.Draw("same,hist")
        hMCTruth.Draw("same,hist")
        hFake_chIso_5To10.Draw("same, hist")
        hMCTruth.Draw("same,hist")
        hFake_chIso_10To15.Draw("same, hist")

        leg = TLegend(0.55, 0.65, 0.75, 0.85)
        leg.SetBorderSize(0)
        leg.SetFillColor(0)
        leg.SetFillStyle(0)
        leg.SetTextFont(42)
        leg.SetTextSize(0.035)
        leg.AddEntry(hMCTruth, "MC Truth", "l")
        leg.AddEntry(hFake_chIso_5To10, "5 < Iso_{Ch} < 10", "l")
        leg.AddEntry(hFake_chIso_10To15, "10 < Iso_{Ch} < 15", "l")
        leg.Draw()

        ##
        postFix = ("endcap", "barrel")[isEB]
        t_label = TLatex()
        t_label.SetTextAlign(12)
        t_label.DrawLatexNDC(0.60,0.50,"ECAL %s"%(postFix));
        # t_label.DrawLatexNDC(0.25,0.70, "#sigma_{i#etai#eta} templates");
        t_label.DrawLatexNDC(0.60,0.45, "pT "+str(PTBINS[ptbin]) + "-" + str(PTBINS[ptbin+1])+ " GeV");
        t_label.SetTextFont(42);

        ##
        postFix = ("EE%s.pdf" %(era), "EB%s.pdf" %(era))[isEB]

        c.Draw()
        c.SaveAs("comp_fake_templates_pT"+str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])+postFix)

# main

LoopOverPtbinsPlots(True)
LoopOverPtbinsPlots(False)
