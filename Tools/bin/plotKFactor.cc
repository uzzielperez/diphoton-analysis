// plots k-factor determined from 2gNNLO and Sherpa
#include "/afs/cern.ch/user/c/cawest/public/tdrstyle.C"

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
void plotOneType(int histType, const TString& region);
template <typename Type> 
void meanAndSigma(const std::vector<Type> &variables, const std::vector<Type> &errors, double &mean, double &sigma);
double crossSection(TH1D * hist);

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

  for(int iHist=1; iHist<12; iHist++) {
    plotOneType(iHist, region);
  }
}

void plotOneType(int histType, const TString& region)
{

  TString submitDir("/afs/cern.ch/user/c/cawest/work/2gsubmit/CMSSW_7_4_6/2gsubmit/JOBSUBMISSION");
  //  TString timestamp("2016-09-05-17-43-31");
  //  TString timestamp("2016-09-02-10-21-16");
  TString timestamp("2016-09-05-17-43-31");

  //  std::vector<TString> scales = {"R0p5F0p5", "R1F1", "R2F2"};
  std::vector<TString> scales = {"R1F1"};
  std::vector<TString> orders = {"BORN", "NLO", "NNLO"};
  //  std::vector<TString> orders = {"BORN", "NLO", "NLO"};
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


  for(auto iscale : scales) {
    for(int iorder=0; iorder<3; iorder++) {     
      if(iorder==0) jobids = jobidsLO;
      else if(iorder==1) jobids=jobidsNLO;
      else jobids = jobidsNNLO;
      std::vector<TFile*> files;
      for(auto ijob : jobids) {
	TString file(Form("%s/%s/%s_%s_%s_Mass0p23To2TeV_13TeV/Job%d/bin/ReRoot.root", 
			  submitDir.Data(), timestamp.Data(), region.Data(), orders.at(iorder).Data(), iscale.Data(), ijob));
	
	TFile * f = TFile::Open(file);
	// skip over corrupt files
	if(f==nullptr) continue;
	files.push_back(f);
	TH1D *tempHist;
	f->GetObject(Form("hist%d", histType), tempHist);
	if(tempHist==nullptr) continue;
	// need to change default output of 2gNNLO
	TString yAxisTitle(tempHist->GetYaxis()->GetTitle());
	yAxisTitle.ReplaceAll("fb", "pb");
	tempHist->GetYaxis()->SetTitle(yAxisTitle);
	double binWidth = (tempHist->GetXaxis()->GetXmax()-tempHist->GetXaxis()->GetXmin())/tempHist->GetNbinsX();
	tempHist->Scale(1/binWidth);
	//      tempHist->Rebin();
	hists[iorder].push_back(tempHist);
      }
      averages.push_back(averageHist(hists[iorder]));
      
      if(iorder==0) averages.back()->Draw();
      else averages.back()->Draw("same");
      
      std::cout << "cross section (pb): " << crossSection(averages.back()) << std::endl;

      //      for(auto ifile : files) ifile->Close();
    }
    
  averages.at(0)->SetMaximum(std::max(1.2*averages.at(0)->GetMaximum(), 1.2*averages.at(2)->GetMaximum()));
  if(histType==4 || histType==7)   averages.at(0)->SetMinimum(0.5*averages.at(2)->GetMinimum());
  if(histType==3)   averages.at(0)->SetMinimum(1e-10);
  averages.at(0)->SetMarkerColor(kBlack);
  averages.at(1)->SetMarkerColor(kBlue);
  averages.at(2)->SetMarkerColor(kRed);
  
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
      std::cout << "cross section (pb): " << crossSection(sherpaHist) << std::endl;
    }
  else {
    sherpaHist = 0;
  }

  TLegend *legend = new TLegend(0.6, 0.5, 0.9, 0.9);
  legend->AddEntry(averages.at(2), "2gNNLO (NNLO)", "EP");
  legend->AddEntry(averages.at(1), "2gNNLO (NLO)", "EP");
  legend->AddEntry(averages.at(0), "2gNNLO (LO)", "EP");
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
  if(sherpaHist) kfactorNNLOtoSherpa->Divide(sherpaHist);
  
  kfactorNNLOtoSherpa->SetFillColor(kRed);
  kfactorNNLOtoSherpa->SetFillStyle(3001);
  kfactorNNLOtoSherpa->GetXaxis()->SetNdivisions(505);
  kfactorNNLOtoSherpa->GetYaxis()->SetRangeUser(0, 3);
  kfactorNNLOtoSherpa->GetYaxis()->SetNdivisions(505);
  kfactorNNLOtoSherpa->GetYaxis()->SetLabelSize(0.06);
  kfactorNNLOtoSherpa->SetLabelSize(0.15, "XY");
  kfactorNNLOtoSherpa->SetTitleSize(0.16, "XY");
  kfactorNNLOtoSherpa->GetYaxis()->SetTitle("#splitline{NNLO/}{Sherpa}");
  kfactorNNLOtoSherpa->GetYaxis()->SetTitleOffset(0.35);
  kfactorNNLOtoSherpa->SetTitleOffset(1.0);
  kfactorNNLOtoSherpa->Draw();
  if(sherpaHist) {
    kfactorNNLOtoSherpa->SetMarkerColor(kRed);
    if(histType==1) {
      TFitResultPtr fitResult = kfactorNNLOtoSherpa->Fit("pol1", "vs");
      fitResult->Print("v");
      TF1 *fittedFunction = kfactorNNLOtoSherpa->GetFunction("pol1");
      fittedFunction->Print("v");
      TFile *kfactorOutput = new TFile(Form("data/kfactor_%s.root", region.Data()), "recreate");
      fittedFunction->Write();
      kfactorOutput->Close();
      delete kfactorOutput;
    }
    kfactorNNLOtoSherpa->Draw("same");
    TLine *atOne = new TLine(kfactorNNLOtoSherpa->GetXaxis()->GetXmin(), 1,
			     kfactorNNLOtoSherpa->GetXaxis()->GetXmax(), 1);
    atOne->SetLineStyle(kDashed);
    atOne->SetLineColor(kRed);
    atOne->Draw();
  }

  c->Print(Form("plots/%s_hist%d_%s.pdf", region.Data(), histType, iscale.Data()));
  }
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

double crossSection(TH1D * hist)
{
  double binWidth = (hist->GetXaxis()->GetXmax()-hist->GetXaxis()->GetXmin())/hist->GetNbinsX();
  return hist->Integral()*binWidth;
}
