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

std::pair<double,double> rooFitFakeRateProducer(TString ptBin, int denomBin)
{

  using namespace RooFit;
  using namespace std;

  gROOT->SetBatch();

  TCanvas *canvas = new TCanvas("canvas","canvas",400,100,500,500);

  gSystem->Load("libRooFit"); 
  gSystem->AddIncludePath("-I$ROOFITSYS/include");

  TFile *historealmcfile = TFile::Open("diphoton_fakeRate_GGJets_M-200To500_Pt-50_13TeV-sherpa_76X_MiniAOD_histograms.root");
  TFile *histojetfile = TFile::Open("diphoton_fakeRate_JetHT_Run2015_16Dec2015-v1_MINIAOD_histograms.root");

  // get histos

  TH1F *hfakeTemplate = (TH1F*)histojetfile->Get( TString("sieieEB_faketemplate_pt") + ptBin );
  hfakeTemplate->Print();
  TH1F *hrealTemplate = (TH1F*)historealmcfile->Get( TString("sieieEB_realtemplate_pt") + ptBin );
  hrealTemplate->Print();
  TH1F *hData = (TH1F*)histojetfile->Get( TString("sieieEB_numerator_pt") + ptBin);
  hData->Print();
  TH1F *hdenom = (TH1F*)histojetfile->Get("phoPtEB_denominator_varbin");
  hdenom->Print();

  //avoiding 0 entries in the histograms
  //fake and real mc histos are the most critical
  for(int bincount = 1; bincount <= hfakeTemplate->GetNbinsX();bincount++){
    if(hfakeTemplate->GetBinContent(bincount) == 0.) hfakeTemplate->SetBinContent(bincount,1.e-6);
  }
  for(int bincount = 1; bincount <= hrealTemplate->GetNbinsX();bincount++){
    if(hrealTemplate->GetBinContent(bincount) == 0.) hrealTemplate->SetBinContent(bincount,1.e-6);
  }
  
  int ndataentries = hData->GetEntries();

  float sininmin = 0.;
  float sininmax = 0.1;

  TString roofitvartitle = "#sigma_{i #eta i #eta}";
  RooRealVar sinin("sinin",roofitvartitle.Data(),sininmin,sininmax);
  sinin.setRange("sigrange",0.005,0.0105);

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
  //model.fitTo(data,SumW2Error(kTRUE),PrintEvalErrors(-1));
  //model.chi2FitTo(data);
	    
  RooPlot *xframe = sinin.frame();
  xframe->SetTitle("");

  data.plotOn(xframe);
  model.plotOn(xframe);
  model.plotOn(xframe,Components(extpdfsig),LineColor(2),LineStyle(2));
  model.plotOn(xframe,Components(extpdffake),LineColor(8),LineStyle(2));

  canvas->cd();

  xframe->GetXaxis()->SetRangeUser(0.,0.1);
  float xframemax = xframe->GetMaximum();
  xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);
  // xframe->Draw();

  // TLegend *legend = new TLegend(0.62,0.65,0.82,0.85);
  // legend->SetTextSize(0.02);
  // legend->SetFillColor(kWhite);
  // legend->SetLineColor(kWhite);

  // TString legendheader = "p_{t} (GeV): [90-110]";
  // cout<<"legend "<<legendheader.Data()<<endl;
  // legend->SetHeader(legendheader.Data());

  // TObject *objdata;
  // TObject *objmodel;
  // TObject *objsignal;
  // TObject *objfake;

  // change to TH1D just so we can change the name
  TH1D *objdata;
  TH1D *objmodel;
  TH1D *objsignal;
  TH1D *objfake;
  for(int i=0;i<xframe->numItems();i++){
    cout<<xframe->nameOf(i)<<endl;
    TString objname = xframe->nameOf(i);
    if(objname.Contains("data")) objdata = (TH1D*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && !objname.Contains("Comp")) objmodel = (TH1D*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && objname.Contains("Signal")) objsignal = (TH1D*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && objname.Contains("Background")) objfake = (TH1D*)xframe->findObject(objname.Data());
  }

  objdata->SetName( TString("data_pt")+ptBin );
  objmodel->SetName( TString("sigplusbkgfit_pt") + ptBin );
  objsignal->SetName( TString("signalfit_pt") + ptBin );
  objfake->SetName( TString("bkgfit_pt") + ptBin );
  TFile outfile("fakeRatePlots.root","update");
  outfile.cd();
  objdata->Write();
  objmodel->Write();
  objsignal->Write();
  objfake->Write();

  // legend->AddEntry(objdata,"Data","lp");
  // legend->AddEntry(objsignal,"Signal","l");
  // legend->AddEntry(objfake,"Background","l");
  // legend->AddEntry(objmodel,"Signal + Background","l");
  // legend->Draw("same");

  // canvas->Print( TString("fakeRatePlot_EB_pT") + ptBin + TString(".png") );

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

  cout<<"sigvalue "<<sigvalue<<" sigerrormax "<<sigerrormax<<" sigerrormax/sigvalue "<<sigerrormax/sigvalue<<endl;
  cout<<"fakevalue "<<fakevalue<<" fakeerrormax "<<fakeerrormax<<" fakeerrormax/fakevalue "<<fakeerrormax/fakevalue<<endl;

  cout<<fakeresults.Data()<<endl;
  cout<<sigresults.Data()<<endl;

  float Ratio = (fakevalue/(fakevalue+sigvalue));
  float RatioError = Ratio*sqrt( ((fakeerrormax/fakevalue)*(fakeerrormax/fakevalue) + (sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );
  cout<<"Ratio "<<Ratio<<" +- "<<RatioError<<endl;

  int binnr = 21; // bin with upper edge = 0.0105, the sieie cut in the barrel
  float numerator = hData->Integral(0,binnr);
  float denominator = hdenom->GetBinContent( denomBin ); // pT bin in denominator pT distribution
  float contamination = sigvalue;

  cout<<numerator<<" "<<denominator<<" "<<contamination<<endl;

  float fakerate = (numerator-contamination)/denominator;
  float fakerateerror = fakerate * sqrt( (1./numerator) + (1./denominator) + ((sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );

  // cout<<"Here: "<<fakerate<<" "<<fakerateerror<<endl;
  return std::make_pair(fakerate,fakerateerror);

  // cout<<""<<endl;
  // cout<<"***********************************************************"<<endl;
  // cout<<"So in sigmaietaieta < (0.0105,0.028) there are "<<contamination<<" to subtract from "<<numerator<<endl;
  // cout<<"and thus there are "<<(numerator-contamination)<<" total tight entries "<<endl;
  // cout<<"and there are "<<denominator<<" entries in the tight and fake sample "<<endl;
  // cout<<"and so the fake rate for the pt range 90-100 is "<<fakerate<<endl;
  // cout<<"***********************************************************"<<endl;
  // cout<<""<<endl;

  histojetfile->cd();
  histojetfile->Close();

  historealmcfile->cd();
  historealmcfile->Close();
  
} //end of rooFitFakeRateProducer()
