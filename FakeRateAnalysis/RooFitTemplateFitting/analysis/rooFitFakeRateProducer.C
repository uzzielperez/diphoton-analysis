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

void rooFitFakeRateProducer()
{

  using namespace RooFit;
  using namespace std;

  TCanvas *canvas = new TCanvas("canvas","canvas",400,100,500,500);

  gSystem->Load("libRooFit"); 
  gSystem->AddIncludePath("-I$ROOFITSYS/include");

  TFile *historealmcfile = TFile::Open("TemplateHistosRealMCHighPtBarrel.root");
  TFile *histojetfile = TFile::Open("TemplateHistosJetRun2015DHighPtBarrelSideBand6_11.root");

  // get histos
  TH1F *h1 = (TH1F*)histojetfile->Get("histoSininWithPixelSeedFakeJetptbin20_40");
  h1->Print();
  TH1F *h2 = (TH1F*)historealmcfile->Get("histoSininWithPixelSeedRealMCptbin20_40");
  h2->Print();
  TH1F *hData = (TH1F*)histojetfile->Get("histoSininWithPixelSeedDataJetptbin20_40");
  hData->Print();
  TH1F *hnum = (TH1F*)histojetfile->Get("histoSininWithPixelSeedTightAndFakeJetptbin20_40");
  hnum->Print();

  //avoiding 0 entries in the histograms
  //fake and real mc histos are the most critical
  for(int bincount = 1; bincount <= h1->GetNbinsX();bincount++){
    if(h1->GetBinContent(bincount) == 0.) h1->SetBinContent(bincount,1.e-6);
  }
  for(int bincount = 1; bincount <= h2->GetNbinsX();bincount++){
    if(h2->GetBinContent(bincount) == 0.) h2->SetBinContent(bincount,1.e-6);
  }
  
  int ndataentries = hData->GetEntries();

  float sininmin = 0.;
  float sininmax = 0.1;

  TString roofitvartitle = "#sigma_{i #eta i #eta}";
  RooRealVar sinin("sinin",roofitvartitle.Data(),sininmin,sininmax);
  sinin.setRange("sigrange",0.005,0.0105);

  RooDataHist faketemplate("faketemplate","fake template",sinin,h1);
  RooHistPdf fakepdf("fakepdf","test hist fake pdf",sinin,faketemplate);
  
  RooDataHist realtemplate("realtemplate","real template",sinin,h2);
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
  xframe->Draw();

  TLegend *legend = new TLegend(0.62,0.65,0.82,0.85);
  legend->SetTextSize(0.02);
  legend->SetFillColor(kWhite);
  legend->SetLineColor(kWhite);

  TString legendheader = "p_{t} (GeV): [20-40]";
  cout<<"legend "<<legendheader.Data()<<endl;
  legend->SetHeader(legendheader.Data());

  TObject *objdata;
  TObject *objmodel;
  TObject *objsignal;
  TObject *objfake;

  for(int i=0;i<xframe->numItems();i++){
    cout<<xframe->nameOf(i)<<endl;
    TString objname = xframe->nameOf(i);
    if(objname.Contains("data")) objdata = (TObject*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && !objname.Contains("Comp")) objmodel = (TObject*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && objname.Contains("Signal")) objsignal = (TObject*)xframe->findObject(objname.Data());
    if(objname.Contains("model") && objname.Contains("Background")) objfake = (TObject*)xframe->findObject(objname.Data());
  }

  legend->AddEntry(objdata,"Data","lp");
  legend->AddEntry(objsignal,"Signal","l");
  legend->AddEntry(objfake,"Background","l");
  legend->AddEntry(objmodel,"Signal + Background","l");
  legend->Draw("same");

  canvas->Print("testPlot.png");

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

  int binnr = 21;
  float numerator = hData->Integral(0,binnr);
  float denominator = hnum->Integral();
  float contamination = sigvalue;

  cout<<numerator<<" "<<denominator<<" "<<contamination<<endl;

  float fakerate = (numerator-contamination)/denominator;
  float fakerateerror = fakerate * sqrt( (1./numerator) + (1./denominator) + ((sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );

  cout<<"Here: "<<fakerate<<" "<<fakerateerror<<endl;

  cout<<""<<endl;
  cout<<"***********************************************************"<<endl;
  cout<<"So in sigmaietaieta < (0.0105,0.028) there are "<<contamination<<" to subtract from "<<numerator<<endl;
  cout<<"and thus there are "<<(numerator-contamination)<<" total tight entries "<<endl;
  cout<<"and there are "<<denominator<<" entries in the tight and fake sample "<<endl;
  cout<<"and so the fake rate for the pt range 20-40 is "<<fakerate<<endl;
  cout<<"***********************************************************"<<endl;
  cout<<""<<endl;

  histojetfile->cd();
  histojetfile->Close();

  historealmcfile->cd();
  historealmcfile->Close();
  
} //end of rooFitFakeRateProducer()
