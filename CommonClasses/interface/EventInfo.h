#ifndef EVENT_INFO_INC
#define EVENT_INFO_INC

// for gen info
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

// for beam halo summary
#include "DataFormats/METReco/interface/BeamHaloSummary.h"

// cross sections
#include "diphoton-analysis/CommonClasses/interface/CrossSections.h"

// pileup reweighting
#include "diphoton-analysis/CommonClasses/interface/PileupInfo.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

namespace ExoDiPhotons
{
  
  struct eventInfo_t {
    Long64_t run;
    Long64_t LS;
    Long64_t evnum; // event numbers can cause integer overflow (so, using Long64_t)
    Long64_t processid;
    Long64_t bx;
    Long64_t orbit;
    float ptHat;
    float alphaqcd;
    float alphaqed;
    float qscale; // qscale from PDF
    float x1; // x of PDF 1
    float x2; // x of PDF 2
    float pdf1; // value of PDF 1
    float pdf2; // value of PDF 2
    float weight0;
    float weight;
    float weightPuUp;
    float weightPu;
    float weightPuDown;
    float weightLumi; // luminosity weight
    float weightAll; // luminosity weight and average event weight
    int interactingParton1PdgId;
    int interactingParton2PdgId;
    int pdf_id1;  // PDG ID of parton 1
    int pdf_id2;  // PDG ID of parton 2
    int npv_true;
    // CSC Beam Halo ID decisions
    bool beamHaloIDLoose;
    bool beamHaloIDTight;
    bool beamHaloIDTight2015;
  };

  // variables must be sorted in decreasing order of size
  const std::string eventBranchDefString("run/L:LS:evnum:processid:bx:orbit:ptHat/F:alphaqcd:alphaqed:qscale:x1:x2:pdf1:pdf2:weight0:weight:weightPuUp:weightPu:weightPuDown:weightLumi:weightAll:interactingParton1PdgId/I:interactingParton2PdgId:pdf_id1:pdf_id2:npv_true:beamHaloIDLoose/O:beamHaloIDTight:beamHaloIDTight2015");
  
  void InitEventInfo(eventInfo_t &eventInfo) {
    eventInfo.run       = (Long64_t) -99999.99;
    eventInfo.LS        = (Long64_t) -99999.99;
    eventInfo.evnum     = (Long64_t) -99999.99;
    eventInfo.processid = (Long64_t) -99999.99;
    eventInfo.bx        = (Long64_t) -99999.99;
    eventInfo.orbit     = (Long64_t) -99999.99;
    eventInfo.ptHat     = -99999.99;
    eventInfo.alphaqcd  = -99999.99;
    eventInfo.alphaqed  = -99999.99;
    eventInfo.qscale    = -99999.99;
    eventInfo.x1        = -99999.99;
    eventInfo.x2        = -99999.99;
    eventInfo.pdf1      = -99999.99;
    eventInfo.pdf2      = -99999.99;
    eventInfo.weight0   = -99999.99;
    eventInfo.weight    = -99999.99;
    eventInfo.weightLumi= -99999.99;
    eventInfo.weightAll = -99999.99;
    eventInfo.weightPuUp= 1.0;
    eventInfo.weightPu  = 1.0;
    eventInfo.weightPuDown = 1.0;
    eventInfo.interactingParton1PdgId = (int) -99999.99;
    eventInfo.interactingParton2PdgId = (int) -99999.99;
    eventInfo.pdf_id1   = (int)-99999.99;
    eventInfo.pdf_id2   = (int)-99999.99;
    eventInfo.npv_true   = (int)-99999.99;
    eventInfo.beamHaloIDLoose     = false;
    eventInfo.beamHaloIDTight     = false;
    eventInfo.beamHaloIDTight2015 = false;
  }

  void FillBasicEventInfo(eventInfo_t &eventInfo, const edm::Event& iEvent) {
    eventInfo.run   = iEvent.id().run();
    eventInfo.LS    = iEvent.id().luminosityBlock();
    eventInfo.evnum = iEvent.id().event();
    eventInfo.bx    = iEvent.bunchCrossing();
    eventInfo.orbit = iEvent.orbitNumber();
  }
  
  void FillBeamHaloEventInfo(eventInfo_t &eventInfo, const reco::BeamHaloSummary* beamHaloSummary) {
    eventInfo.beamHaloIDLoose     = beamHaloSummary->CSCLooseHaloId();
    eventInfo.beamHaloIDTight     = beamHaloSummary->CSCTightHaloId();
    eventInfo.beamHaloIDTight2015 = beamHaloSummary->CSCTightHaloId2015();
  }
  
  void FillGenEventInfo(eventInfo_t &eventInfo, const GenEventInfoProduct *genInfo) {
    eventInfo.ptHat     = genInfo->hasBinningValues() ? (genInfo->binningValues())[0] : 0.0 ;
    eventInfo.alphaqcd  = genInfo->alphaQCD();
    eventInfo.alphaqed  = genInfo->alphaQED();
    if(genInfo->hasPDF()) {
      const gen::PdfInfo *pdf = genInfo->pdf();
      eventInfo.qscale = pdf->scalePDF;
      eventInfo.x1 = pdf->x.first;
      eventInfo.x2 = pdf->x.second;
      eventInfo.pdf1 = pdf->xPDF.first;
      eventInfo.pdf2 = pdf->xPDF.second;
      eventInfo.pdf_id1 = pdf->id.first;
      eventInfo.pdf_id2 = pdf->id.second;
    }
    else {
      eventInfo.qscale    = genInfo->qScale();
    }
    eventInfo.processid = genInfo->signalProcessID();
    eventInfo.weight0   = (genInfo->weights().size() > 0 ) ? genInfo->weights()[0] : 1.0;
    eventInfo.weight    = genInfo->weight();


  }

  void FillPileupInfo(eventInfo_t &eventInfo, const std::vector< PileupSummaryInfo > * puSummary) {
    for(unsigned int ipu=0; ipu<puSummary->size(); ipu++) {
      if(puSummary->at(ipu).getBunchCrossing()==0) {
	eventInfo.npv_true = puSummary->at(ipu).getTrueNumInteractions();
	eventInfo.weightPuDown = pileup::weight(eventInfo.npv_true, -1);
	eventInfo.weightPu = pileup::weight(eventInfo.npv_true, 0);
	eventInfo.weightPuUp = pileup::weight(eventInfo.npv_true, 1);
	break;
      }
    }
  }

  void FillEventWeights(eventInfo_t &eventInfo, const TString& sample, double nEventsSample) {
    double normalizationLumi = 1000.; // pb
    eventInfo.weightLumi = crossSection(sample)*normalizationLumi/(nEventsSample*averageWeight(sample));
    eventInfo.weightAll = eventInfo.weight*eventInfo.weightLumi;
  }


} // end of namespace

#endif
