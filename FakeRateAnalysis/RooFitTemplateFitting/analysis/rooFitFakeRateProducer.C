#include "TROOT.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TF1.h"
#include "RooHistPdf.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooDataHist.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooNDKeysPdf.h"
#include "TFile.h"
#include "TLegend.h"
#include "TText.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "RooChi2Var.h"

#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////
//
// return background and uncertainty instead of fakerate
//
////////////////////////////////////////////////////////

std::pair<double,double> rooFitFakeRateProducer(TString ptBin, TString etaBin, std::pair<double,double> sideband, int denomBin) {

  cout << endl;
  cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
    
  // true - data
  // false - mc (closure test)
  bool is_data = true;
  if (is_data) cout << "Running over data." << endl;
  if (!is_data) cout << "Running over MC." << endl;

  cout << "Starting rooFitFakeRateProducer" << endl;
  cout << "Using " << etaBin << ", pt " << ptBin << ", " << sideband.first << " < CHIso < " << sideband.second << endl;
  
  using namespace RooFit;
  using namespace std;

  gROOT->SetBatch();

  TCanvas *canvas = new TCanvas("canvas","Fit Result",1600,600);
  canvas->Divide(2,1);

  gSystem->Load("libRooFit"); 
  gSystem->AddIncludePath("-I$ROOFITSYS/include");

  // for real templates (same for data and mc)
  TFile *historealmcfile = TFile::Open("../../MCFakeRateAnalysis/analysis/diphoton_fake_rate_real_templates_GGJets_M-all_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  // numerator, fake templates, and denominator (choose data or mc)
  TFile *histojetfile;
  if (is_data) histojetfile = TFile::Open("../../DataFakeRateAnalysis/analysis/jetht_fakerate_vanilla.root");
  if (!is_data) histojetfile = TFile::Open("../../MCFakeRateClosureTest/analysis/diphoton_fake_rate_closure_test_QCD_Pt_all_TuneCUETP8M1_13TeV_pythia8_76X_MiniAOD_histograms.root");
  
  double sidebandLow = sideband.first;
  double sidebandHigh = sideband.second;
  TString postFix = TString::Format("_chIso%dTo%d",(int)sidebandLow,(int)sidebandHigh);

  // get histos
  TH1F *hfakeTemplate = (TH1F*)histojetfile->Get( TString("sieie") + etaBin + TString("_faketemplate_pt") + ptBin + postFix );
  hfakeTemplate->Print();
  TH1F *hrealTemplate = (TH1F*)historealmcfile->Get( TString("sieie") + etaBin + TString("_realtemplate_pt") + ptBin );
  hrealTemplate->Print();
  TH1F *hData = (TH1F*)histojetfile->Get( TString("sieie") + etaBin + TString("_numerator_pt") + ptBin);
  hData->Print();
  TH1F *hdenom = (TH1F*)histojetfile->Get( TString("phoPt") + etaBin + TString("_denominator_varbin") );
  hdenom->Print();

  // avoiding 0 entries in the histograms
  // fake and real mc histos are the most critical
  for (int bincount = 1; bincount <= hfakeTemplate->GetNbinsX();bincount++) {
    if (hfakeTemplate->GetBinContent(bincount) == 0.) hfakeTemplate->SetBinContent(bincount,1.e-6);
  }
  for (int bincount = 1; bincount <= hrealTemplate->GetNbinsX();bincount++) {
    if (hrealTemplate->GetBinContent(bincount) == 0.) hrealTemplate->SetBinContent(bincount,1.e-6);
  }
  
  int ndataentries = hData->Integral();

  float sininmin = 0.;
  float sininmax = 0.1;

  TString roofitvartitle = "#sigma_{i#etai#eta}";
  RooRealVar sinin("sinin",roofitvartitle.Data(),sininmin,sininmax);
  float sininCut = 0.0105; // sigma_IetaIeta cut for EB
  if (etaBin.Contains("EE")) sininCut = 0.028; // sigma_IetaIeta cut for EE
  sinin.setRange("sigrange",0.0,sininCut);

  RooDataHist faketemplate("faketemplate","fake template",sinin,hfakeTemplate);
  RooHistPdf fakepdf("fakepdf","test hist fake pdf",sinin,faketemplate);
  
  RooDataHist realtemplate("realtemplate","real template",sinin,hrealTemplate);
  RooHistPdf realpdf("realpdf","test hist real pdf",sinin,realtemplate);
  
  RooDataHist data("data","data to be fitted to",sinin,hData);
  
  RooRealVar fsig("fsig","signal fraction",0.1,0,1);
  
  RooRealVar signum("signum","signum",0,ndataentries);
  RooRealVar fakenum("fakenum","fakenum",0,ndataentries);
  
  RooExtendPdf extpdfsig("Signal","extpdfsig",realpdf,signum,"sigrange");
  RooExtendPdf extpdffake("Background","extpdffake",fakepdf,fakenum,"sigrange");
  
  RooAddPdf model("model","sig + background",RooArgList(extpdfsig,extpdffake));
  
  model.fitTo(data,RooFit::Minos(),SumW2Error(kTRUE),PrintEvalErrors(-1));
  
  TH1D* fitHist = (TH1D*)model.createHistogram("sinin",200);
  double fitres = hData->Chi2Test(fitHist,"CHI2/NDF");
  // cout << "CHI2 FIT RES = " << fitres << endl;
      
  RooPlot *xframe = sinin.frame();
  xframe->SetTitle("");

  data.plotOn(xframe);
  model.plotOn(xframe);
  model.plotOn(xframe,Components(extpdfsig),LineColor(2),LineStyle(2));
  model.plotOn(xframe,Components(extpdffake),LineColor(8),LineStyle(2));
  data.plotOn(xframe);

  canvas->cd(1);

  xframe->GetXaxis()->SetRangeUser(0.,0.03);
  if (etaBin.Contains("EE")) xframe->GetXaxis()->SetRangeUser(0.,0.08);
  float xframemax = xframe->GetMaximum();
  xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);
  xframe->GetYaxis()->SetTitleOffset(1.6);
  xframe->Draw();

  TString label_pt_bin = ptBin;
  label_pt_bin.ReplaceAll("To"," < p_{T} < ");
  
  TString chIsoString = TString::Format("%d < I_{ch} < %d GeV",(int)sidebandLow,(int)sidebandHigh);
  
  TLatex *t_label = new TLatex();
  t_label->SetTextAlign(12);
  if (etaBin == "EB") t_label->DrawLatexNDC(0.55,0.60,"ECAL barrel");
  else t_label->DrawLatexNDC(0.55,0.60,"ECAL endcap");
  t_label->     DrawLatexNDC(0.55,0.55,label_pt_bin + " GeV");
  t_label->     DrawLatexNDC(0.55,0.50,chIsoString);
  t_label->     DrawLatexNDC(0.55,0.45,TString::Format("#chi^{2}/ndf = %6.1f",fitres));
  
  TObject *objdata;
  TObject *objmodel;
  TObject *objsignal;
  TObject *objfake;

  for (int i = 0; i < xframe->numItems(); i++) {
    cout << xframe->nameOf(i) << endl;
    TString objname = xframe->nameOf(i);
    if (objname.Contains("data"))                                    objdata = (TObject*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && !objname.Contains("Comp"))      objmodel = (TObject*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && objname.Contains("Signal"))     objsignal = (TObject*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && objname.Contains("Background")) objfake = (TObject*) xframe->findObject(objname.Data());
  }

  TLegend *legend = new TLegend(0.65,0.65,0.85,0.85);
  legend->SetTextSize(0.03);
  legend->SetFillColor(0);
  legend->SetLineColor(0);
  legend->SetFillStyle(0);
  legend->AddEntry(objdata," Numerator","ep");
  legend->AddEntry(objsignal," Real template","l");
  legend->AddEntry(objfake," Fake template","l");
  legend->AddEntry(objmodel," Combined fit","l");
  legend->Draw("same");
    
  canvas->cd(2);

  RooPlot *xframeClone = (RooPlot*)xframe->emptyClone("xframeClone");
  xframeClone->SetTitle("");
  
  xframeClone->Draw();
  xframe->Draw("same");
  
  xframeClone->GetXaxis()->SetRangeUser(0.,0.03);
  if (etaBin.Contains("EE")) xframeClone->GetXaxis()->SetRangeUser(0.,0.08);
  xframeClone->GetYaxis()->SetRangeUser(1.e-1,10.0*xframemax);
  xframeClone->GetYaxis()->SetTitle("Events / ( 0.0005 )");
  xframeClone->GetYaxis()->SetTitleOffset(1.2);
  
  gPad->SetLogy();

  canvas->Print( TString("fakeRatePlot")+ etaBin + TString("_pT") + ptBin + postFix + TString(".pdf") );
  
  // change to TH1D just so we can change the name
  TH1D *hobjdata;
  TH1D *hobjmodel;
  TH1D *hobjsignal;
  TH1D *hobjfake;
  for (int i = 0; i < xframe->numItems(); i++) {
    cout << xframe->nameOf(i) << endl;
    TString objname = xframe->nameOf(i);
    if (objname.Contains("data"))                                    hobjdata = (TH1D*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && !objname.Contains("Comp"))      hobjmodel = (TH1D*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && objname.Contains("Signal"))     hobjsignal = (TH1D*) xframe->findObject(objname.Data());
    if (objname.Contains("model") && objname.Contains("Background")) hobjfake = (TH1D*) xframe->findObject(objname.Data());
  }

  hobjdata->SetName( TString("data") + etaBin + TString("_pt") + ptBin + postFix );
  hobjmodel->SetName( TString("sigplusbkgfit") + etaBin + TString("_pt") + ptBin + postFix );
  hobjsignal->SetName( TString("signalfit") + etaBin + TString("_pt") + ptBin + postFix );
  hobjfake->SetName( TString("bkgfit") + etaBin + TString("_pt") + ptBin + postFix );
  
  TFile outfile("fakeRatePlots.root","update");
  outfile.cd();
  hobjdata->Write();
  hobjmodel->Write();
  hobjsignal->Write();
  hobjfake->Write();

  float fakevalue = fakenum.getValV();
  float fakeerrorhi = fakenum.getErrorHi();
  float fakeerrorlo = fakenum.getErrorLo();
  float fakeerrormax = max(fabs(fakeerrorhi),fabs(fakeerrorlo));
  TString fakeresults = TString::Format("Fake results %f +%f %f",fakevalue,fakeerrorhi,fakeerrorlo);

  float sigvalue = signum.getValV();
  float sigerrorhi = signum.getErrorHi();
  float sigerrorlo = signum.getErrorLo();
  float sigerrormax = max(fabs(sigerrorhi),fabs(sigerrorlo));
  TString sigresults = TString::Format("Signal results %f +%f %f",sigvalue,sigerrorhi,sigerrorlo);

  cout << "sigvalue " << sigvalue << " sigerrormax " << sigerrormax << " sigerrormax/sigvalue " << sigerrormax/sigvalue << endl;
  cout << "fakevalue " << fakevalue << " fakeerrormax " << fakeerrormax << " fakeerrormax/fakevalue " << fakeerrormax/fakevalue << endl;

  cout << fakeresults.Data() << endl;
  cout << sigresults.Data() << endl;

  float Ratio = (fakevalue/(fakevalue+sigvalue));
  float RatioError = Ratio*sqrt( ((fakeerrormax/fakevalue)*(fakeerrormax/fakevalue) + (sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );
  cout << "Ratio " << Ratio << " +- " << RatioError << endl;

  int binnr = 21; // bin with upper edge = 0.0105, the sieie cut in the barrel
  if (etaBin.Contains("EE")) binnr = 56; // bin with upper edge = 0.028, the sieie
  float numerator = hData->Integral(0,binnr);
  float denominator = hdenom->GetBinContent( denomBin ); // pT bin in denominator pT distribution
  float contamination = sigvalue;

  cout << numerator << " " << denominator << " " << contamination << endl;

  float fakerate = fakevalue/denominator;
  float fakerateerror = TMath::Sqrt((fakeerrormax*fakeerrormax/denominator/denominator) + (fakerate*fakerate/denominator));

  cout << "Here: " << fakerate << " " << fakerateerror << endl;
  cout << "Ending rooFitFakeRateProducer" << endl;
  cout << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
  
  return std::make_pair(fakevalue,fakeerrormax);

  histojetfile->cd();
  histojetfile->Close();

  historealmcfile->cd();
  historealmcfile->Close();
  
} // end of rooFitFakeRateProducer()
