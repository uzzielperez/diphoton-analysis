#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <string.h>

#include <TH1D.h>
#include <TH1.h>
#include <TFile.h>
#include <TString.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TPad.h>
#include <TMath.h>
#include <TMinuit.h>


/*
*
* PhotonClosure/analysis/MCFakeRateAnalysis.C
*
*/

// const int NPTBINS=9;
// const float PTBINS[NPTBINS+1] = { 50, 70, 90, 110, 130, 150, 200, 250, 300, 600 };
const int NPTBINS=6;
const float PTBINS[NPTBINS+1] = { 50, 70, 90, 110, 130, 150, 600 };

enum hist_t { Real, Fake, Truth, Numerator, Denominator };

const int NEBBINS=9;
const double EBBINS[NEBBINS+1] = { 0., 0.0075, 0.009, 0.0105, 0.0120, 0.0135, 0.0150, 0.0165, 0.0180, 0.03};
const int EBSIEIECUTBIN=4;

const int NEEBINS=8;
const double EEBINS[NEEBINS+1] = { 0., 0.016, 0.020, 0.024, 0.028, 0.032, 0.036, 0.040, 0.08 };
const int EESIEIECUTBIN=5;


TFile* rootfile=0;

// histograms used by the fitter
TH1 *theData, *theBkg1, *theBkg2;

using namespace std;

TH1* GetHist(int ptbin, bool isEB, hist_t type, TString sideband="_chIso5To10")
{
  rootfile=0;
  TString run = "2017";
  TString base = "/uscms_data/d3/cuperez/tribosons/FakeRate/CMSSW_10_2_18/src/";
  if(type==Real)
  {
    // Output from RealTemplateAnalysis/analysis/MCFakeRateAnalysis.C
    //rootfile=new TFile("diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_MiniAOD_histograms.root");
    // 2016
    if (run=="2016") rootfile=new TFile(base + "diphoton_fake_rate_real_templates_all_GGJets_GJets_76X_nPV0-200_MiniAOD_histograms.root");
    //2017
    if (run=="2017") rootfile=new TFile(base + "diphoton_fake_rate_real_templates_all_GGJets_GJets_94X_nPV0-200_MiniAOD_histograms.root");
    //2018
    if (run=="2018") rootfile=new TFile(base + "diphoton_fake_rate_real_templates_all_GGJets_GJets_102X_nPV0-200_MiniAOD_histograms.root");
  }
  else if(type==Truth){
    // Output from PhotonClosure/analysis/MCFakeRateClosureTestWithFakes2.C
    //rootfile=new TFile("diphoton_fake_rate_closure_test_matching_all_samples_80X_MiniAOD_histograms_test.root");
    // 2016
    if (run=="2016") rootfile=new TFile(base +"diphoton_fake_rate_closure_test_matching_all_samples_76X_MiniAOD_histograms.root");
    //2017
    if (run=="2017") rootfile=new TFile(base + "diphoton_fake_rate_closure_test_matching_all_samples_94X_MiniAOD_histograms.root");
    //2018
    if (run=="2018") rootfile=new TFile(base + "diphoton_fake_rate_closure_test_matching_all_samples_102X_MiniAOD_histograms.root");
  }
  else
  {
    // Output from PhotonClosure/analysis/MCFakeRateAnalysis.C
    //rootfile=new TFile("diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root");
    // 2016
    if (run=="2016") rootfile=new TFile(base + "diphoton_fake_rate_closure_test_all_samples_76X_MiniAOD_histograms.root");
    //2017
    if (run=="2017") rootfile=new TFile(base + "diphoton_fake_rate_closure_test_all_samples_94X_MiniAOD_histograms.root");
    //2018
    if (run=="2018") rootfile=new TFile(base + "diphoton_fake_rate_closure_test_all_samples_102X_MiniAOD_histograms.root");
  }

  assert(rootfile);
  rootfile->cd();

  ostringstream oss;
  if(type==Real)
    oss << "sieie" << (isEB ? "EB" : "EE") << "_realtemplate_pt" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1];
  else if(type==Fake)
    oss << "sieie" << (isEB ? "EB" : "EE") << "_faketemplate_pt" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1] <<  sideband;
  else if(type==Numerator)
    oss << "sieie" << (isEB ? "EB" : "EE") << "_numerator_pt" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1];
  else if(type==Denominator)
    oss << "Pt" << (isEB ? "EB" : "EE") << "_denominator_pt" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1];
  else if(type==Truth)
    oss << "sieie" << (isEB ? "EB" : "EE") << "_numerator_fakes_pt" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1];

  TH1* h=dynamic_cast<TH1*>( gROOT->FindObject(oss.str().c_str()) );
  if(!h) {
    cout << "Cannot find object " << oss.str().c_str() << " (" << ptbin << ", " << isEB << ", " << type << ")" << endl;
  }
  assert(h);

  if(type!=Denominator) {
    if(isEB)
      h=h->Rebin(NEBBINS, TString(h->GetName())+"_rebin", EBBINS);
    else
      h=h->Rebin(NEEBINS, TString(h->GetName())+"_rebin", EEBINS);
  }

  return h;
}

// Negative log likelihood function for the fitting routine
void NLL(int &, double *, double &f, double *par, int)
{
  double frac=par[0];
  // std::cout << "frac: " << frac << std::endl;
  double norm1=theData->Integral()/theBkg1->Integral();
  double norm2=theData->Integral()/theBkg2->Integral();

  f=0.0;
  for(int i=1; i<=theData->GetNbinsX(); i++) {
    double obs=theData->GetBinContent(i);
    double mu=norm1*frac*theBkg1->GetBinContent(i)+norm2*(1-frac)*theBkg2->GetBinContent(i);
    double mue1=norm1*frac*theBkg1->GetBinError(i);
    double mue2=norm2*(1-frac)*theBkg2->GetBinError(i);
    double mue=sqrt(mue1*mue1+mue2*mue2)*par[i];
    mu+=mue;
    if(mu<=0.0) {
      mu=0.000001;
      std::cout << "Woah!  mu=" << mu << std::endl;
    }
    f += mu-obs*TMath::Log(mu)+par[i]*par[i]/2.;
  }
  return;
}

int performFit(TH1* hData, TH1* hBkg1, TH1* hBkg2, double &frac, double &frace)
{
  theData=hData;
  theBkg1=hBkg1;
  theBkg2=hBkg2;

  TMinuit minuit;
  minuit.SetErrorDef(0.5);
  minuit.SetPrintLevel(1);
  minuit.Command("SET STR 2"); // set strategy

  minuit.DefineParameter(0, "FRAC", 0.5, 0.01, 0.0, 1.0);
  for(int i=1; i<=theData->GetNbinsX(); i++) {
    ostringstream oss;
    oss << "BB" << i;
    //minuit.DefineParameter(i, oss.str().c_str(), 0, 0.1, -7.0, 7.0);
    minuit.DefineParameter(i, oss.str().c_str(), 0, 0.1, 0.0, 7.0);
  }

  minuit.SetFCN(NLL); // set the function
  double tmp[1] = {50000. }; int err;
  minuit.mnexcm("MIGRAD", tmp, 1, err); // execute Minuit with MIGRAD

  // get the parameters
  minuit.GetParameter(0, frac, frace);

  // get the the Minos errors
  double eplus, eminus, eparab, gcc;
  minuit.mnmnos();
  minuit.mnerrs(0, eplus, eminus, eparab, gcc);

  // set the error to the symmetrized minos errors
  frace=(eplus-eminus)/2.0;

  return err;
}

void fitCHIsoSidebands(){
  // To supress canvas from popping up. Speeds up plots production
  gROOT->SetBatch();
  gStyle->SetOptStat(0);

  // make vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  // chIsoSidebands.push_back( std::make_pair(6.,11.) );
  // chIsoSidebands.push_back( std::make_pair(7.,12.) );
  // chIsoSidebands.push_back( std::make_pair(8.,13.) );
  // chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  // chIsoSidebands.push_back( std::make_pair(10.,20.) );

  double EBFake[NPTBINS], EBFakeE[NPTBINS];
  double EEFake[NPTBINS], EEFakeE[NPTBINS];
  int EBFakeStatus[NPTBINS], EEFakeStatus[NPTBINS];

  double EBTruth[NPTBINS], EBTruthE[NPTBINS];
  double EETruth[NPTBINS], EETruthE[NPTBINS];
  int EBTruthStatus[NPTBINS], EETruthStatus[NPTBINS];

  // Set up Canvas for EB and EE
  TCanvas *cEBFakeRateComp=new TCanvas("cEBFakeRateComp", "EBFakeRateComp");
  TCanvas *cEEFakeRateComp=new TCanvas("cEEFakeRateComp", "EEFakeRateComp");

  TH1D* hEBFakeRateTruth=new TH1D("hEBFakeRateTruth", "EB FakeRateTruth", NPTBINS, PTBINS);
  TH1D* hEEFakeRateTruth=new TH1D("hEEFakeRateTruth", "EE FakeRateTruth", NPTBINS, PTBINS);

  hEBFakeRateTruth->SetLineColor(kOrange-5);
  hEEFakeRateTruth->SetLineColor(kOrange-5);

  auto legendFR_EB = new TLegend(0.55, 0.65, 0.75, 0.85);
  auto legendFR_EE = new TLegend(0.55, 0.65, 0.75, 0.85);

  legendFR_EB->AddEntry(hEBFakeRateTruth, "MC truth yields", "ep");
  legendFR_EB->SetBorderSize(0);
  legendFR_EE->AddEntry(hEEFakeRateTruth, "MC truth yields", "ep");
  legendFR_EE->SetBorderSize(0);


for (unsigned int i = 0; i < chIsoSidebands.size(); i++)
{
   double sidebandLow = chIsoSidebands.at(i).first;
   double sidebandHigh = chIsoSidebands.at(i).second;
   TString postFix = "", leglabel = "";
   postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);

  for(int isTruth=0; isTruth<2; isTruth++)
  {
    for(int isEB=0; isEB<2; isEB++)
    {
      for(int ptbin=0; ptbin<NPTBINS; ptbin++)
      {

          // std::cout << "POSTFIX" << postFix << std::endl;

          TH1* hReal=GetHist(ptbin, isEB, Real);
          TH1* hFake= isTruth ? GetHist(ptbin, isEB, Truth) : GetHist(ptbin, isEB, Fake, postFix);
          TH1* hNum=GetHist(ptbin, isEB, Numerator);
          TH1* hDem=GetHist(ptbin, isEB, Denominator);

          double frac, frace;
          int err=performFit(hNum, hReal, hFake, frac, frace);

          double norm1=hNum->Integral()/hReal->Integral();
          double norm2=hNum->Integral()/hFake->Integral();
          hReal->Scale(norm1*frac);
        	hFake->Scale(norm2*(1-frac));


          double num=0.0, nume2=0.0;
          int nbins=isEB ? EBSIEIECUTBIN-1 : EESIEIECUTBIN-1;
          for(int i=1; i<=nbins; i++) {
        	  num += hFake->GetBinContent(i);
        	  nume2 += hFake->GetBinError(i)*hFake->GetBinError(i);
        	}
          double error=sqrt(nume2/num/num+frace*frace/frac/frac)*num;
          double den=hDem->Integral();

          if(!isTruth) {
            if(isEB) { EBFake[ptbin]=num/den; EBFakeE[ptbin]=error/den; EBFakeStatus[ptbin]=err; }
            else     { EEFake[ptbin]=num/den; EEFakeE[ptbin]=error/den; EEFakeStatus[ptbin]=err; }
          } else {
            if(isEB) { EBTruth[ptbin]=num/den; EBTruthE[ptbin]=error/den; EBTruthStatus[ptbin]=err; }
            else     { EETruth[ptbin]=num/den; EETruthE[ptbin]=error/den; EETruthStatus[ptbin]=err; }
          }

        } // end loop over pT bins
      }  // end loop over isEB
    } // end loop over Truth

    std::cout << "Fake Rate Results per pT bin for chIsosideband: " << postFix << endl;
    for(int j=0; j<NPTBINS; j++)
      std::cout << "Fake EB " << j << ": " << EBFake[j] << " +/- " << EBFakeE[j] << " (" << EBFakeE[j]/EBFake[j]*100 << "%; status=" << EBFakeStatus[j] << ")" << std::endl;
    for(int j=0; j<NPTBINS; j++)
      std::cout << "Fake EE " << j << ": " << EEFake[j] << " +/- " << EEFakeE[j] << " (" << EEFakeE[j]/EEFake[j]*100 << "%; status=" << EEFakeStatus[j] << ")" << std::endl;
    for(int j=0; j<NPTBINS; j++)
      std::cout << "Truth EB " << j << ": " << EBTruth[j] << " +/- " << EBTruthE[j] << " (" << EBTruthE[j]/EBTruth[j]*100 << "%; status=" << EBTruthStatus[j] << ")" << std::endl;
    for(int j=0; j<NPTBINS; j++)
      std::cout << "Truth EE " << j << ": " << EETruth[j] << " +/- " << EETruthE[j] << " (" << EETruthE[j]/EETruth[j]*100 << "%; status=" << EETruthStatus[j] << ")" << std::endl;

    // Store the FakeRates in histograms
    TH1D* hEBFakeRate=new TH1D("hEBFakeRate", "EB FakeRate", NPTBINS, PTBINS);
    TH1D* hEEFakeRate=new TH1D("hEEFakeRate", "EE FakeRate", NPTBINS, PTBINS);

    for(int i=0; i<NPTBINS; i++) {
      // MC as data
      std::cout << "EB FakeRate " << i << ": " << EBFake[i]  << " +/- " << EBFakeE[i] << std::endl;
      hEBFakeRate->SetBinContent(i+1, EBFake[i]);
      hEBFakeRate->SetBinError(i+1, EBFakeE[i]);
      std::cout << "EE FakeRate " << i << ": " << EEFake[i]  << " +/- " << EEFakeE[i] << std::endl;
      hEEFakeRate->SetBinContent(i+1, EEFake[i]);
      hEEFakeRate->SetBinError(i+1, EEFakeE[i]);
      // MC as Truth
      std::cout << "EB FakeRateTruth " << i << ": " << EBTruth[i]  << " +/- " << EBTruthE[i] << std::endl;
      hEBFakeRateTruth->SetBinContent(i+1, EBTruth[i]);
      hEBFakeRateTruth->SetBinError(i+1, EBTruthE[i]);
      std::cout << "EE FakeRateTruth " << i << ": " << EETruth[i]  << " +/- " << EETruthE[i] << std::endl;
      hEEFakeRateTruth->SetBinContent(i+1, EETruth[i]);
      hEEFakeRateTruth->SetBinError(i+1, EETruthE[i]);
    }

    // EB
    cEBFakeRateComp->cd();
    hEBFakeRateTruth->Draw("same");

    int iColorEB = i+1;
    hEBFakeRate->SetLineColor(iColorEB);
    hEBFakeRate->Draw("same");

    hEBFakeRate->SetMinimum(0);
    hEBFakeRate->SetMaximum(0.14);
    hEBFakeRateTruth->SetMinimum(0);
    hEBFakeRateTruth->SetMaximum(0.14);

    leglabel = TString::Format("chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);
    legendFR_EB->AddEntry(hEBFakeRate, leglabel, "ep");

    // EE
    cEEFakeRateComp->cd();
    hEEFakeRateTruth->Draw("same");

    int iColorEE = i+1;
    hEEFakeRate->SetLineColor(iColorEE);
    hEEFakeRate->Draw("same");

    hEEFakeRate->SetMinimum(0);
    hEEFakeRate->SetMaximum(0.8);
    hEEFakeRateTruth->SetMinimum(0);
    hEEFakeRateTruth->SetMaximum(0.8);

    legendFR_EE->AddEntry(hEEFakeRate, leglabel, "ep");

    // Update Canvas
    cEBFakeRateComp->Update();
    cEEFakeRateComp->Update();

  } // end loop over chIsoSidebands

  // Draw Label once
  cEBFakeRateComp->cd();
  legendFR_EB->Draw();

  TLatex *t_labelEB = new TLatex();
  t_labelEB->SetTextAlign(12);
  t_labelEB->SetTextAlign(12);
  t_labelEB->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  t_labelEB->DrawLatexNDC(0.25,0.70, "#sigma_{i#etai#eta} templates");
  t_labelEB->SetTextFont(42);


  cEEFakeRateComp->cd();
  legendFR_EE->Draw();

  TLatex *t_labelEE = new TLatex();
  t_labelEE->SetTextAlign(12);
  t_labelEE->SetTextAlign(12);
  t_labelEE->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  t_labelEE->DrawLatexNDC(0.25,0.70, "#sigma_{i#etai#eta} templates");
  t_labelEE->SetTextFont(42);

  // Save Canvas for EB and EE
  cEBFakeRateComp->SaveAs("fake_rate_CompTruth_chIsoEB.pdf");
  cEEFakeRateComp->SaveAs("fake_rate_CompTruth_chIsoEE.pdf");

  return;
}

void fit(void)
{
  // To supress canvas from popping up. Speeds up plots production
  gROOT->SetBatch();
  gStyle->SetOptStat(0);

  // make vector of chIso sidebands
  std::vector< std::pair<double,double> > chIsoSidebands;
  typedef std::vector< std::pair<double,double> >::const_iterator chIsoIt;
  chIsoSidebands.push_back( std::make_pair(5.,10.) );
  // chIsoSidebands.push_back( std::make_pair(6.,11.) );
  // chIsoSidebands.push_back( std::make_pair(7.,12.) );
  // chIsoSidebands.push_back( std::make_pair(8.,13.) );
  // chIsoSidebands.push_back( std::make_pair(9.,14.) );
  chIsoSidebands.push_back( std::make_pair(10.,15.) );
  chIsoSidebands.push_back( std::make_pair(15.,20.) );
  // chIsoSidebands.push_back( std::make_pair(10.,20.) );

  TCanvas *cEB=new TCanvas("EB","EB");
  TCanvas *cEE=new TCanvas("EE","EE");
  TCanvas *cEBTruth=new TCanvas("EBTruth","EB Truth");
  TCanvas *cEETruth=new TCanvas("EETruth","EE Truth");
  cEB->Divide(2,3);
  cEE->Divide(2,3);
  cEBTruth->Divide(2,3);
  cEETruth->Divide(2,3);

  double EBFake[NPTBINS], EBFakeE[NPTBINS];
  double EEFake[NPTBINS], EEFakeE[NPTBINS];
  int EBFakeStatus[NPTBINS], EEFakeStatus[NPTBINS];

  double EBTruth[NPTBINS], EBTruthE[NPTBINS];
  double EETruth[NPTBINS], EETruthE[NPTBINS];
  int EBTruthStatus[NPTBINS], EETruthStatus[NPTBINS];

  // Template Fit per pT bin
  for(int isTruth=0; isTruth<2; isTruth++)
  {
    for(int isEB=0; isEB<2; isEB++)
    {
      for(int ptbin=0; ptbin<NPTBINS; ptbin++)
      {

  TCanvas *c=new TCanvas("canvas", "canvas", 1600, 500);
  c->Divide(2,1);

	TH1* hReal=GetHist(ptbin, isEB, Real);
	TH1* hFake= isTruth ? GetHist(ptbin, isEB, Truth) : GetHist(ptbin, isEB, Fake, "_chIso5To10");
	TH1* hNum=GetHist(ptbin, isEB, Numerator);
	TH1* hDem=GetHist(ptbin, isEB, Denominator);

	double frac, frace;
	int err=performFit(hNum, hReal, hFake, frac, frace);


	double norm1=hNum->Integral()/hReal->Integral();
	double norm2=hNum->Integral()/hFake->Integral();
	hReal->Scale(norm1*frac);
	hFake->Scale(norm2*(1-frac));
	hReal->SetFillColor(kBlue);
	hReal->SetFillStyle(3001);
	hFake->SetFillColor(kRed);
	hFake->SetFillStyle(3002);

	ostringstream oss;
	oss << "h" << PTBINS[ptbin] << "To" << PTBINS[ptbin+1] << "_" << (isEB ? "EB" : "EE") << "_" << (isTruth ? "Truth" : "Fake");
	THStack *hs=new THStack(oss.str().c_str(), "");
	hs->Add(hFake, "HIST");
	hs->Add(hReal, "HIST");

  // Draw for each pT to see match in peaks
  c->cd(1);
  hs->Draw();
  hNum->Draw("same");
  hs->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");

  auto legend = new TLegend(0.55, 0.65, 0.85, 0.85);
  legend->SetBorderSize(0);
  legend->AddEntry(hNum, "Numerator candidates", "ep");
  legend->AddEntry(hReal, "Real template", "f");
  legend->AddEntry(hFake, "Fake template", "f");
  legend->Draw();

  ostringstream ssptBin;
  ssptBin << PTBINS[ptbin] << " < p_{T} < " << PTBINS[ptbin+1] << " GeV";
  ostringstream sschIsoSideBand;
  sschIsoSideBand << 5 << " < Iso_{Ch} < " << 10;

  TLatex *t_label = new TLatex();
  t_label->SetTextAlign(12);
  if (isEB) t_label->DrawLatexNDC(0.55,0.60,"ECAL barrel");
  else t_label->DrawLatexNDC(0.55,0.60,"ECAL endcap");
  t_label->     DrawLatexNDC(0.55,0.55, ssptBin.str().c_str());
  t_label->     DrawLatexNDC(0.55,0.50, sschIsoSideBand.str().c_str());
  t_label->DrawLatexNDC(0.17, 0.975, "#font[62]{CMS} #scale[0.8]{#font[52]{Preliminary}}");
  t_label->SetTextFont(42);
  // t_label->DrawLatexNDC(0.70, 0.975, Form("%1.1f fb^{-1} (13 TeV)", luminosity[era.Data()]));

  // Draw for each pT setLog to see match in tail
  c->cd(2);
  hs->Draw();
  hNum->Draw("same");
  gPad->SetLogy(1);
	hs->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");

  ostringstream ssCanvas;
  ssCanvas <<"fakeRateTemplates_pT_"<< PTBINS[ptbin] << "To_" << PTBINS[ptbin+1] << "_" << (isEB ? "EB" : "EE") << "_" << (isTruth ? "Truth" : "Fake") << "_chIso5To10.pdf";
  c->SaveAs(ssCanvas.str().c_str());

  // Fake Rate Part
	double num=0.0, nume2=0.0;
	int nbins=isEB ? EBSIEIECUTBIN-1 : EESIEIECUTBIN-1;
	for(int i=1; i<=nbins; i++) {
	  num += hFake->GetBinContent(i);
	  nume2 += hFake->GetBinError(i)*hFake->GetBinError(i);
	}
	double error=sqrt(nume2/num/num+frace*frace/frac/frac)*num;
	double den=hDem->Integral();

	if(!isTruth) {
	  if(isEB) { EBFake[ptbin]=num/den; EBFakeE[ptbin]=error/den; EBFakeStatus[ptbin]=err; }
	  else     { EEFake[ptbin]=num/den; EEFakeE[ptbin]=error/den; EEFakeStatus[ptbin]=err; }
	} else {
	  if(isEB) { EBTruth[ptbin]=num/den; EBTruthE[ptbin]=error/den; EBTruthStatus[ptbin]=err; }
	  else     { EETruth[ptbin]=num/den; EETruthE[ptbin]=error/den; EETruthStatus[ptbin]=err; }
	}

      } //end loop over pT Bins
    } // end loop over EB or EE
  } // end loop over Truth

  for(int i=0; i<NPTBINS; i++)
    std::cout << "Fake EB " << i << ": " << EBFake[i] << " +/- " << EBFakeE[i] << " (" << EBFakeE[i]/EBFake[i]*100 << "%; status=" << EBFakeStatus[i] << ")" << std::endl;
  for(int i=0; i<NPTBINS; i++)
    std::cout << "Fake EE " << i << ": " << EEFake[i] << " +/- " << EEFakeE[i] << " (" << EEFakeE[i]/EEFake[i]*100 << "%; status=" << EEFakeStatus[i] << ")" << std::endl;
  for(int i=0; i<NPTBINS; i++)
    std::cout << "Truth EB " << i << ": " << EBTruth[i] << " +/- " << EBTruthE[i] << " (" << EBTruthE[i]/EBTruth[i]*100 << "%; status=" << EBTruthStatus[i] << ")" << std::endl;
  for(int i=0; i<NPTBINS; i++)
    std::cout << "Truth EE " << i << ": " << EETruth[i] << " +/- " << EETruthE[i] << " (" << EETruthE[i]/EETruth[i]*100 << "%; status=" << EETruthStatus[i] << ")" << std::endl;

  // Fake Rate
  TCanvas *cEBFakeRate=new TCanvas("cEBFakeRate", "EBFakeRate");
  TCanvas *cEEFakeRate=new TCanvas("cEEFakeRate", "EEFakeRate");
  TH1D* hEBFakeRate=new TH1D("hEBFakeRate", "EB FakeRate", NPTBINS, PTBINS);
  TH1D* hEEFakeRate=new TH1D("hEEFakeRate", "EE FakeRate", NPTBINS, PTBINS);
  TH1D* hEBFakeRateTruth=new TH1D("hEBFakeRateTruth", "EB FakeRateTruth", NPTBINS, PTBINS);
  TH1D* hEEFakeRateTruth=new TH1D("hEEFakeRateTruth", "EE FakeRateTruth", NPTBINS, PTBINS);

  for(int i=0; i<NPTBINS; i++) {
    // MC as data
    std::cout << "EB FakeRate " << i << ": " << EBFake[i]  << " +/- " << EBFakeE[i] << std::endl;
    hEBFakeRate->SetBinContent(i+1, EBFake[i]);
    hEBFakeRate->SetBinError(i+1, EBFakeE[i]);
    std::cout << "EE FakeRate " << i << ": " << EEFake[i]  << " +/- " << EEFakeE[i] << std::endl;
    hEEFakeRate->SetBinContent(i+1, EEFake[i]);
    hEEFakeRate->SetBinError(i+1, EEFakeE[i]);
    // MC as Truth
    std::cout << "EB FakeRateTruth " << i << ": " << EBTruth[i]  << " +/- " << EBTruthE[i] << std::endl;
    hEBFakeRateTruth->SetBinContent(i+1, EBTruth[i]);
    hEBFakeRateTruth->SetBinError(i+1, EBTruthE[i]);
    std::cout << "EE FakeRateTruth " << i << ": " << EETruth[i]  << " +/- " << EETruthE[i] << std::endl;
    hEEFakeRateTruth->SetBinContent(i+1, EETruth[i]);
    hEEFakeRateTruth->SetBinError(i+1, EETruthE[i]);
  }

  cEBFakeRate->cd(); hEBFakeRate->Draw();
  cEEFakeRate->cd(); hEEFakeRate->Draw();

  hEBFakeRate->SetMinimum(0);  hEEFakeRate->SetMinimum(0);
  hEBFakeRate->SetMaximum(0.2);  hEEFakeRate->SetMaximum(0.6);

  // Compare Fake Rate MC as data vs MC as truth
  TCanvas *cEBFakeRateComp=new TCanvas("cEBFakeRateComp", "EBFakeRateComp");
  TCanvas *cEEFakeRateComp=new TCanvas("cEEFakeRateComp", "EEFakeRateComp");

  // EB Fake Rate Truth Comparison
  cEBFakeRateComp->cd();
  hEBFakeRateTruth->SetLineColor(kOrange-5);
  hEBFakeRateTruth->Draw();
  hEBFakeRate->Draw("same");

  hEBFakeRate->SetMinimum(0);
  hEBFakeRate->SetMaximum(0.2);
  hEBFakeRateTruth->SetMinimum(0);
  hEBFakeRateTruth->SetMaximum(0.2);

  ostringstream sschIsoSideBand;
  sschIsoSideBand << 5 << " < Iso_{Ch} < " << 10;

  auto legendFR_EB = new TLegend(0.55, 0.65, 0.75, 0.85);
  legendFR_EB->SetBorderSize(0);
  legendFR_EB->AddEntry(hEBFakeRateTruth, "MC truth yields", "ep");
  legendFR_EB->AddEntry(hEBFakeRate, sschIsoSideBand.str().c_str(), "ep");
  legendFR_EB->Draw();

  TLatex *t_labelEB = new TLatex();
  t_labelEB->SetTextAlign(12);
  t_labelEB->SetTextAlign(12);
  t_labelEB->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  t_labelEB->DrawLatexNDC(0.25,0.70, "#sigma_{i#etai#eta} templates");
  t_labelEB->SetTextFont(42);

  // EE Fake Rate Truth Comparison
  cEEFakeRateComp->cd();
  hEEFakeRateTruth->SetLineColor(kOrange-5);
  hEEFakeRateTruth->Draw();
  hEEFakeRate->Draw("same");

  hEEFakeRate->SetMinimum(0);
  hEEFakeRate->SetMaximum(0.8);
  hEEFakeRateTruth->SetMinimum(0);
  hEEFakeRateTruth->SetMaximum(0.8);

  auto legendFR_EE = new TLegend(0.55, 0.65, 0.75, 0.85);
  legendFR_EE->SetBorderSize(0);
  legendFR_EE->AddEntry(hEEFakeRateTruth, "MC truth yields", "ep");
  legendFR_EE->AddEntry(hEEFakeRate, sschIsoSideBand.str().c_str(), "ep");
  legendFR_EE->Draw();

  TLatex *t_labelEE = new TLatex();
  t_labelEE->SetTextAlign(12);
  t_labelEE->SetTextAlign(12);
  t_labelEE->DrawLatexNDC(0.25,0.80,"ECAL barrel");
  t_labelEE->DrawLatexNDC(0.25,0.70, "#sigma_{i#etai#eta} templates");
  t_labelEE->SetTextFont(42);

  // Measure Fake Rate Underestimation or Overestimation
  // Ratio of the fake rate with the known MC truth as a function of pT
  TCanvas *c1=new TCanvas("cEBRatio","EBRatio");
  TCanvas *c2=new TCanvas("cEERatio","EERatio");
  TH1D* hEBRatio=new TH1D("hEBRatio","EB Ratio", NPTBINS, PTBINS);
  TH1D* hEERatio=new TH1D("hEERatio","EE Ratio", NPTBINS, PTBINS);

  for(int i=0; i<NPTBINS; i++) {
    double r=EBFake[i]/EBTruth[i];
    double e1=EBFakeE[i]/EBFake[i];
    double e2=EBTruthE[i]/EBTruth[i];
    double e=r*sqrt(e1*e1+e2*e2);
    std::cout << "EB Ratio " << i << ": " << r  << " +/- " << e << std::endl;
    hEBRatio->SetBinContent(i+1, r);
    hEBRatio->SetBinError(i+1, e);
  }

  for(int i=0; i<NPTBINS; i++) {
    double r=EEFake[i]/EETruth[i];
    double e1=EEFakeE[i]/EEFake[i];
    double e2=EETruthE[i]/EETruth[i];
    double e=r*sqrt(e1*e1+e2*e2);
    std::cout << "EE Ratio " << i << ": " << r  << " +/- " << e << std::endl;
    hEERatio->SetBinContent(i+1, r);
    hEERatio->SetBinError(i+1, e);
  }

  c1->cd(); hEBRatio->Draw();
  c2->cd(); hEERatio->Draw();

  hEBRatio->SetMinimum(0);  hEERatio->SetMinimum(0);
  hEBRatio->SetMaximum(2.0);  hEERatio->SetMaximum(2.0);

  // Fake Rate
  c1->SaveAs("fake_rate_EBRatio.pdf");
  c2->SaveAs("fake_rate_EERatio.pdf");
  cEBFakeRate->SaveAs("fake_rate_FakeTemplatesEB.pdf");
  cEEFakeRate->SaveAs("fake_rate_FakeTemplatesEE.pdf");
  cEBFakeRateComp->SaveAs("fake_rate_CompTruth_FakeTemplatesEB.pdf");
  cEEFakeRateComp->SaveAs("fake_rate_CompTruth_FakeTemplatesEE.pdf");

  cEB->SaveAs("fake_rate_cEB.pdf");
  cEE->SaveAs("fake_rate_cEE.pdf");
  cEBTruth->SaveAs("fake_rate_cEBTruth.pdf");
  cEETruth->SaveAs("fake_rate_cEETruth.pdf");

  TFile file_out("fake_rate_sieie_template_fits.root", "RECREATE");
  hEBFakeRate->Write();
  hEEFakeRate->Write();
  hEBFakeRateTruth->Write();
  hEEFakeRateTruth->Write();

  // Repeat For chIsoSidebands
  fitCHIsoSidebands();

  return;
}
