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

# To supress canvas from popping up. Speeds up plots production
gROOT.SetBatch()

PTBINS = [ 50, 70, 90, 130, 200, 600 ];
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
      filename = "diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root"
      histname = "sieie" + etaBin + "_realtemplate_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      # fillstyle = 3001
      drawAs = "hist, same"
  elif type == "Truth":
      filename = "diphoton_fake_rate_closure_test_matching_all_samples_80X_MiniAOD_histograms_test.root"
      histname = "sieie" + etaBin + "_numerator_fakes_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      drawAs = "hist, same"
  else:
      filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root"
  if type == "Numerator":
      histname = "sieie" + etaBin + "_numerator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      drawAs = "e, same"
  if type == "Denominator":
      histname = "sieie" + etaBin + "_denominator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
  if type == "Fake":
      filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root"
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

        hMCTruth.SetLineColor(kOrange-5)
        hMCTruth.Scale(1/hMCTruth.Integral())
        hFake_chIso_5To10.SetLineColor(kBlack)
        hFake_chIso_5To10.Scale(1/hFake_chIso_5To10.Integral())
        hFake_chIso_10To15.SetLineColor(kRed)
        hFake_chIso_10To15.Scale(1/hFake_chIso_10To15.Integral())

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

        postFix = ("EE.pdf", "EB.pdf")[isEB]

        c.Draw()
        c.SaveAs("comp_fake_templates_pT"+str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])+postFix)

# main

LoopOverPtbinsPlots(True)
LoopOverPtbinsPlots(False)
