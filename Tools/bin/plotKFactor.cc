// plots k-factor determined from 2gNNLO and Sherpa
#include "diphoton-analysis/Tools/interface/sampleList.hh"
#include "diphoton-analysis/Tools/interface/utilities.hh"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TLine.h"
#include "TPad.h"
#include "TROOT.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TF1.h"

#include <vector>
#include <algorithm>
#include <iostream>

TH1D* averageHist(const std::vector<TH1D*>& hists);
void plotOneType(int histType, const TString& region, const TString& scale);
template <typename Type> 
void meanAndSigma(const std::vector<Type> &variables, const std::vector<Type> &errors, double &mean, double &sigma);
double crossSection(TH1D * hist, double& error);

int main(int argc, char *argv[])
{
  TString region;

  if(argc!=2) {
    std::cout << "Syntax: plotKFactor.exe [BB/BE]" << std::endl;
    return -1;
  }
  else {
    region = argv[1];
    if(region!="BB" and region!="BE") {
      std::cout << "Only 'BB' and 'BE' are allowed input parameters. " << std::endl;
      return -1;
    }
  }

  setTDRStyle();
  gROOT->ForceStyle();

  std::vector<TString> scales = {"R0p5F0p5", "R1F1", "R2F2"};
  for(auto iscale : scales ) {
    for(int iHist=1; iHist<12; iHist++) {
      plotOneType(iHist, region, iscale);
    }
  }
}

void plotOneType(int histType, const TString& region, const TString& scale)
{
  bool useMCFM = true;

  TString submitDir("/afs/cern.ch/user/c/cawest/work/2gsubmit/CMSSW_7_4_6/2gsubmit/JOBSUBMISSION");
  //  TString timestamp("2016-09-05-17-43-31");
  //  TString timestamp("2016-09-02-10-21-16");
  TString timestamp("2016-09-05-17-43-31");

  std::vector<TString> orders = {"BORN", "NLO", "NNLO"};
  std::vector<int> jobids;
  std::vector<int> jobidsLO = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> jobidsNLO;
  std::vector<int> jobidsNNLO;
  for(unsigned int i=1; i<=10; i++) jobidsNLO.push_back(i);
  for(unsigned int i=1; i<=50; i++) jobidsNNLO.push_back(i);

  std::vector<TH1D*> hists[3];
  std::vector<TH1D*> averages;
  averages.reserve(3);

  TCanvas *c = new TCanvas;
  TPad *pad1, *pad2;
  pad1 = new TPad("pad1", "pad1", 0, 0.3, 1,1);
  pad1->SetBottomMargin(0.01);
  if(histType!=11 && histType!=12) pad1->SetLogy();
  pad1->Draw();
      
  pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.3);;
  pad2->SetBottomMargin(0.4);
  pad2->SetTopMargin(0.05);
  pad2->Draw();
    
  pad1->cd();

  for(int iorder=0; iorder<3; iorder++) {
    if(iorder==0) jobids = jobidsLO;
    else if(iorder==1) jobids=jobidsNLO;
    else jobids = jobidsNNLO;
    averages.push_back(getHists("/afs/cern.ch/user/c/cawest/work/2gsubmit/CMSSW_7_4_6/2gsubmit/JOBSUBMISSION/2016-09-05-17-43-31",
				region.Data(), orders.at(iorder).Data()));
    // need to change default output of 2gNNLO
    TString yAxisTitle(averages.back()->GetYaxis()->GetTitle());
    yAxisTitle.ReplaceAll("fb", "pb");
    averages.back()->GetYaxis()->SetTitle(yAxisTitle);
    double binWidth = (averages.back()->GetXaxis()->GetXmax()-averages.back()->GetXaxis()->GetXmin())/averages.back()->GetNbinsX();
    averages.back()->Scale(1/binWidth);

    if(!useMCFM) {
      if(iorder==0) averages.back()->Draw();
      else averages.back()->Draw("same");
    }
    
    double xsec;
    double xsecError = 0.0;
    xsec = crossSection(averages.back(), xsecError);
    std::cout << "cross section (pb): " << xsec << " +/-" << xsecError << std::endl;
  }

  averages.at(0)->SetMaximum(std::max(1.2*averages.at(0)->GetMaximum(), 1.2*averages.at(2)->GetMaximum()));
  if(histType==4 || histType==7)   averages.at(0)->SetMinimum(0.5*averages.at(2)->GetMinimum());
  if(histType==3)   averages.at(0)->SetMinimum(1e-10);
  
  TH1D* sherpaHist = 0;
  if(histType < 13) {
      TFile *sherpa = TFile::Open("data/sherpa.root");
      TString histName(Form("%s/hist%d", region.Data(), histType));
      sherpaHist = static_cast<TH1D*>(sherpa->Get(histName));
      sherpaHist->SetMarkerColor(kMagenta);
      double binWidth = (sherpaHist->GetXaxis()->GetXmax()-sherpaHist->GetXaxis()->GetXmin())/sherpaHist->GetNbinsX();
      sherpaHist->Scale(1/binWidth);
      //    sherpaHist->Rebin();
      sherpaHist->Draw("same");

      double xsec;
      double xsecError = 0.0;
      xsec = crossSection(sherpaHist, xsecError);
      std::cout << "cross section (pb): " << xsec << " +/-" << xsecError << std::endl;
    }
  else {
    sherpaHist = 0;
  }

  if(useMCFM) {
    if(histType==1 && region=="BB") {
      std::string base("/afs/cern.ch/user/c/cawest/work/CMSSW_8_0_7_patch2/mcfm/MCFM-8.0/Bin");
      if(scale == "R0p5F0p5") {
      averages.at(0) = getHistsMCFM(base, "gamgam_lo_CT10.LH_0.50_0.50_lo_CT10_scaledown");
      averages.at(1) = getHistsMCFM(base, "gamgam_nlo_CT10nlo_0.50_0.50_nlo_CT10_scaledown");
      averages.at(2) = getHistsMCFM(base, "gamgam_nnlo_CT10nnl_0.50_0.50_1.E-3_nnlo_CT10_scaledown");
      }
      else if(scale == "R1F1") {
	averages.at(0) = getHistsMCFM(base, "gamgam_lo_CT10.LH_1.00_1.00_lo_CT10");
	averages.at(1) = getHistsMCFM(base, "gamgam_nlo_CT10nlo_1.00_1.00_nlo_CT10");
	averages.at(2) = getHistsMCFM(base, "gamgam_nnlo_CT10nnl_1.00_1.00_1.E-3_nnlo_CT10");
      }
      else if(scale == "R2F2") {
	averages.at(0) = getHistsMCFM(base, "gamgam_lo_CT10.LH_2.00_2.00_lo_CT10_scaleup");
	averages.at(1) = getHistsMCFM(base, "gamgam_nlo_CT10nlo_2.00_2.00_nlo_CT10_scaleup");
	averages.at(2) = getHistsMCFM(base, "gamgam_nnlo_CT10nnl_2.00_2.00_1.E-3_nnlo_CT10_scaleup");
      }
      averages.at(0)->Scale(1/20.);
      averages.at(1)->Scale(1/20.);
      averages.at(2)->Scale(1/20.);
    }
  }

  averages.at(0)->SetMarkerColor(kBlack);
  averages.at(1)->SetMarkerColor(kBlue);
  averages.at(2)->SetMarkerColor(kRed);
  std::cout << averages.at(0)->GetYaxis()->GetTitle() << std::endl;
  averages.at(0)->SetMaximum(std::max(1.2*averages.at(0)->GetMaximum(), 1.2*averages.at(2)->GetMaximum()));
  averages.at(0)->GetYaxis()->SetTitle("d#sigma/dM_{#gamma#gamma} [pb/GeV]");
  averages.at(0)->Draw();
  averages.at(1)->Draw("same");
  averages.at(2)->Draw("same");
  sherpaHist->Draw("same");

  TLegend *legend = new TLegend(0.6, 0.5, 0.9, 0.9);
  if(useMCFM) {
    legend->AddEntry(averages.at(2), "MCFM (NNLO)", "EP");
    legend->AddEntry(averages.at(1), "MCFM (NLO)", "EP");
    legend->AddEntry(averages.at(0), "MCFM (LO)", "EP");
  }
  else {
    legend->AddEntry(averages.at(2), "2gNNLO (NNLO)", "EP");
    legend->AddEntry(averages.at(1), "2gNNLO (NLO)", "EP");
    legend->AddEntry(averages.at(0), "2gNNLO (LO)", "EP");
  }
  legend->AddEntry(sherpaHist, "Sherpa", "EP");
  legend->SetBorderSize(0);
  legend->SetFillStyle(0);
  legend->Draw();
  
  
    
  pad2->cd();
  gStyle->SetOptStat(0);
  TH1D *kfactorNNLOtoNLO = static_cast<TH1D*>(averages.at(2)->Clone());
  kfactorNNLOtoNLO->Divide(averages.at(1));
  TH1D *kfactorNLOtoLO = static_cast<TH1D*>(averages.at(1)->Clone());
  kfactorNLOtoLO->Divide(averages.at(0));
  TH1D *kfactorNNLOtoSherpa = static_cast<TH1D*>(averages.at(2)->Clone());
  TH1D *kfactorNLOtoSherpa = static_cast<TH1D*>(averages.at(1)->Clone());
  TH1D *kfactorLOtoSherpa = static_cast<TH1D*>(averages.at(0)->Clone());
  if(sherpaHist) {
    kfactorNNLOtoSherpa->Divide(sherpaHist);
    kfactorNLOtoSherpa->Divide(sherpaHist);
    kfactorLOtoSherpa->Divide(sherpaHist);
  }
  
  kfactorNNLOtoSherpa->SetFillColor(kRed);
  kfactorNNLOtoSherpa->SetFillStyle(3001);
  kfactorNNLOtoSherpa->GetXaxis()->SetNdivisions(505);
  kfactorNNLOtoSherpa->GetYaxis()->SetRangeUser(0, 3.9);
  kfactorNNLOtoSherpa->GetYaxis()->SetNdivisions(505);
  kfactorNNLOtoSherpa->GetYaxis()->SetLabelSize(0.06);
  kfactorNNLOtoSherpa->SetLabelSize(0.15, "XY");
  kfactorNNLOtoSherpa->SetTitleSize(0.16, "XY");
  kfactorNNLOtoSherpa->GetXaxis()->SetTitle("m_{#gamma#gamma} (GeV)");
  kfactorNNLOtoSherpa->GetYaxis()->SetTitle("#splitline{MCFM/}{Sherpa}");
  if(useMCFM) kfactorNNLOtoSherpa->GetYaxis()->SetTitle("#splitline{MCFM/}{Sherpa}");
  else kfactorNNLOtoSherpa->GetYaxis()->SetTitle("#splitline{2gNNLO/}{Sherpa}");
  kfactorNNLOtoSherpa->GetYaxis()->SetTitleOffset(0.35);
  kfactorNNLOtoSherpa->SetTitleOffset(1.0);
  kfactorNNLOtoSherpa->Draw();

  kfactorNLOtoSherpa->SetFillColor(kBlue);
  kfactorNLOtoSherpa->SetFillStyle(3001);
  kfactorNLOtoSherpa->Draw("same");

  kfactorLOtoSherpa->SetFillColor(kBlack);
  kfactorLOtoSherpa->SetFillStyle(3001);
  kfactorLOtoSherpa->Draw("same");

  if(sherpaHist) {
    kfactorNNLOtoSherpa->SetMarkerColor(kRed);
    if(histType==1) {
      TString func("pol3");
      TFitResultPtr fitResult = kfactorNNLOtoSherpa->Fit(func, "vse", "", 500, 2500);
      fitResult->Print("v");
      TF1 *fittedFunction = kfactorNNLOtoSherpa->GetFunction(func);
      fittedFunction->Print("v");

      TFitResultPtr fitResult_NLO = kfactorNLOtoSherpa->Fit(func, "vs", "", 500, 2500);
      fitResult_NLO->Print("v");
      TF1 *fittedFunction_NLO = kfactorNLOtoSherpa->GetFunction(func);
      fittedFunction_NLO->Print("v");
      fittedFunction_NLO->SetName(func + "_NLO");
      fittedFunction_NLO->SetTitle(func + "_NLO");

      TFitResultPtr fitResult_LO = kfactorLOtoSherpa->Fit(func, "vs", "", 500, 2500);
      fitResult_LO->Print("v");
      TF1 *fittedFunction_LO = kfactorLOtoSherpa->GetFunction(func);
      fittedFunction_LO->Print("v");
      fittedFunction_LO->SetName(func + "_LO");
      fittedFunction_LO->SetTitle(func + "_LO");

      TFile *kfactorOutput = new TFile(Form("data/kfactor_%s_%s.root", region.Data(), scale.Data()), "recreate");
      fittedFunction->Write();
      fitResult->Write();
      fittedFunction_NLO->Write();
      fittedFunction_LO->Write();
      kfactorOutput->Close();
      delete kfactorOutput;

      // TF1 *diphox_scaleup = new TF1("diphox_scaleup", "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x", 0, 2500);
      // diphox_scaleup->SetParameters();
      // diphox_scaleup->SetLineColor(kBlack);

      TF1 *diphox = new TF1("diphox", "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x", 0, 2500);
      diphox->SetParameters(8.90218e-01, 5.19225e-04, -1.37800e-07, 1.97496e-11, -1.04218e-15);
      diphox->SetLineColor(kBlack);

      // TF1 *diphox_scaledown = new TF1("diphox_scaledown", "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x", 0, 2500);
      // diphox_scaledown->SetParameters();
      // diphox_scaledown->SetLineColor(kBlack);

      //      diphox->Draw("same");
    }
    kfactorNNLOtoSherpa->Draw("same");
    TLine *atOne = new TLine(kfactorNNLOtoSherpa->GetXaxis()->GetXmin(), 1,
			     kfactorNNLOtoSherpa->GetXaxis()->GetXmax(), 1);
    atOne->SetLineStyle(kDashed);
    atOne->SetLineColor(kRed);
    atOne->Draw();
  }

  c->Print(Form("plots/%s_hist%d_%s.pdf", region.Data(), histType, scale.Data()));

}

TH1D* averageHist(const std::vector<TH1D*>& hists)
{
  if(hists.size()==0) {
    std::cout << "Need to specify at least one histogram" << std::endl;
    exit(-1);
  }
  TH1D* average = static_cast<TH1D*>(hists.at(0)->Clone());

  for(int iBin=0; iBin<=hists.at(0)->GetNbinsX()+1; iBin++) {
    std::vector<double> entries, errors;
    for(unsigned int iHist=0; iHist<hists.size(); iHist++) {
      entries.push_back(hists.at(iHist)->GetBinContent(iBin));
      errors.push_back(0.05*hists.at(iHist)->GetBinError(iBin));
    }
    double mean = 0.0;
    double sigma = 0.0;
    meanAndSigma(entries, errors, mean, sigma);
    average->SetBinContent(iBin, mean);
    average->SetBinError(iBin, sigma);
  }    
  

  return average;
}

template <typename Type>
void meanAndSigma(const std::vector<Type> &variables, const std::vector<Type> &errors, double &mean, double &sigma)
{

  // calculate weighted average
  double weightNumerator = 0.0;
  double weightDenominator = 0.0;
  for(unsigned int i=0; i<variables.size(); i++) {
    if(errors.at(i) > 0.0) {
      weightNumerator += variables.at(i)/pow(errors.at(i), 2);
      weightDenominator += 1/pow(errors.at(i), 2);
    }
  }
  if(weightDenominator==0.0) mean = sigma = 0.0;
  else {
    mean = weightNumerator/weightDenominator;
    sigma = 1./sqrt(weightDenominator);
  }
}

double crossSection(TH1D * hist, double& error)
{
  double binWidth = (hist->GetXaxis()->GetXmax()-hist->GetXaxis()->GetXmin())/hist->GetNbinsX();
  return hist->IntegralAndError(0, hist->GetNbinsX(), error)*binWidth;
}
