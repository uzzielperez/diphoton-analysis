#ifndef EVENT_INFO_INC
#define EVENT_INFO_INC

// for gen info
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

// for beam halo summary
#include "DataFormats/METReco/interface/BeamHaloSummary.h"

// cross sections
#include "diphoton-analysis/CommonClasses/interface/CrossSections.h"

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
    float qscale;
    float weight0;
    float weight;
    float weightLumi; // luminosity weight
    float weightAll; // luminosity weight and average event weight
    int interactingParton1PdgId;
    int interactingParton2PdgId;

    // CSC Beam Halo ID decisions
    bool beamHaloIDLoose;
    bool beamHaloIDTight;
    bool beamHaloIDTight2015;
  };

  // variables must be sorted in decreasing order of size
  std::string eventBranchDefString("run/L:LS:evnum:processid:bx:orbit:ptHat/F:alphaqcd:alphaqed:qscale:weight0:weight:weightLumi:weightAll:interactingParton1PdgId/I:interactingParton2PdgId:beamHaloIDLoose/O:beamHaloIDTight:beamHaloIDTight2015");
  
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
    eventInfo.weight0   = -99999.99;
    eventInfo.weight    = -99999.99;
    eventInfo.weightLumi= -99999.99;
    eventInfo.weightAll = -99999.99;
    eventInfo.interactingParton1PdgId = (int) -99999.99;
    eventInfo.interactingParton2PdgId = (int) -99999.99;
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
    eventInfo.qscale    = genInfo->qScale();
    eventInfo.processid = genInfo->signalProcessID();
    eventInfo.weight0   = genInfo->weights()[0];
    eventInfo.weight    = genInfo->weight();
  }

  void FillEventWeights(eventInfo_t &eventInfo, const TString& sample, double nEventsSample) {
    double normalizationLumi = 1000.; // pb
    eventInfo.weightLumi = crossSection(sample)*normalizationLumi/(nEventsSample*averageWeight(sample));
    eventInfo.weightAll = eventInfo.weight*eventInfo.weightLumi;
  }


} // end of namespace

#endif
