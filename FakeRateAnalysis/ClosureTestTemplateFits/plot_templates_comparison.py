#!/usr/bin/python

import ROOT
from ROOT import TClass,TKey, TIter,TCanvas, TPad, TFile, TPaveText, TColor, TGaxis, TH1F, TPad, TH1D, TLegend
from ROOT import kBlack, kBlue, kRed
from ROOT import gBenchmark, gStyle, gROOT, gDirectory
import sys


##################
#
# This code overlays Real, Fake and Numerator Templates
# Needs input files from RealTemplateAnalysis/analysis/MCFakeRateAnalysis.C &
# PhotonClosure/analysis/MCFakeRateAnalysis.C
#
#################


PTBINS = [ 50, 70, 90, 130, 200, 600 ];
color = []

# def performFit( hData, hBkg1, hBkg2, frac, frace):
#     minuit = TMinuit()
#     minuit.SetErrorDef(0.5)
#     minuit.SetPrintLevel(1)
#     minuit.Command("SET STR 2")
#     minuit.DefineParameter(0, "FRAC", 0.5, 0.01, 0.0, 1.0)
#
#     for(int i=1; i<=theData->GetNbinsX(); i++){
#         param = "BB" + i
#         minuit.DefineParameter(i, param, 0, 0.1, -7.0, 7.0)
#     }

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

def GetHist(ptbin, isEB, type):

  etaBin = ("EE", "EB")[isEB]

  if type == "Real":
      filename = "diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root"
      histname = "sieie" + etaBin + "_realtemplate_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      fillstyle = 3001
      drawAs = "hist, same"
  elif type == "Truth":
      filename = "diphoton_fake_rate_closure_test_matching_all_samples_80X_MiniAOD_histograms_test.root"
      histname = "sieie" + etaBin + "_numerator_fakes_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
      color = kRed
      drawAs = "hist, same"
  else:
      filename = "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root"
      if type == "Fake":
          histname = "sieie" + etaBin + "_faketemplate_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
          drawAs = "hist, same"
      if type == "Numerator":
          histname = "sieie" + etaBin + "_numerator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])
          drawAs = "e, same"
      if type == "Denominator":
          histname = "sieie" + etaBin + "_denominator_pt" + str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])

  f = ROOT.TFile(filename, "READ")
  #h = f.Get(histname)

  h = GetHistObj(histname, f)
  h.SetDirectory(0)
  # h.Draw(drawAs)
  print h
  return h, histname

# EB Templates
for ptbin in range(len(PTBINS)-1):
    c = ROOT.TCanvas()
    # isEB = True
    hReal, hRealLabel           = GetHist(ptbin, True, "Real")
    hNum, hNumLabel             = GetHist(ptbin, True, "Numerator")
    # hDen, hDenLabel           = GetHist(ptbin, True, "Denominator")
    hFake, hFakeLabel           = GetHist(ptbin, True, "Fake")
    hFakeTruth, hFakeTruthLabel = GetHist(ptbin, True, "Truth")

    #hReal.Scale(hNum.Integral()/hReal.Integral())
    norm1 = hNum.Integral()/hReal.Integral()
    norm2 = hNum.Integral()/hFake.Integral()
    hReal.Scale(norm1)
    hFake.Scale(norm2)
    hReal.SetFillColor(kBlue)
    hReal.SetFillStyle(3001)
    hFake.SetFillColor(kRed)
    hFake.SetFillStyle(3002)
    #
    hReal.Draw("hist")
    hFake.Draw("hist, Same")
    hNum.Draw("e, same")

    c.Draw()
    c.SaveAs("fake_templates_pT"+str(PTBINS[ptbin]) + "To" + str(PTBINS[ptbin+1])+"EB.pdf")

# To-do
# we have to do the fit and get the error
# Worth learning: https://root-forum.cern.ch/t/pyroot-and-minuit/1107/6
