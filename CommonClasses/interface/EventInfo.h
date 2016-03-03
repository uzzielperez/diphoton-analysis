#ifndef EVENT_INFO_INC
#define EVENT_INFO_INC

// for gen info
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

namespace ExoDiPhotons
{
  
  struct eventInfo_t {
    float pthat;
    float alphaqcd;
    float alphaqed;
    float qscale;
    float weight;
    float jetHT;
    int run;
    int LS;
    int evnum;
    int processid;
    int bx;
    int orbit;
    int interactingParton1PdgId;
    int interactingParton2PdgId;
    int nJets;
  };
  
  std::string eventBranchDefString("pthat/F:alphaqcd:alphaqed:qscale:weight:jetHT:run/I:LS:evnum:processid:bx:orbit:interactingParton1PdgId:interactingParton2PdgId:nJets");
  
  void InitEventInfo(eventInfo_t &eventInfo) {
    eventInfo.processid = (int) -99999.99;
    eventInfo.pthat = -99999.99;
    eventInfo.alphaqcd = -99999.99;
    eventInfo.alphaqed = -99999.99;
    eventInfo.qscale = -99999.99;
    eventInfo.weight = -99999.99;
    eventInfo.jetHT = -99999.99;
    eventInfo.run = (int) -99999.99;
    eventInfo.LS = (int) -99999.99;
    eventInfo.evnum = (int) -99999.99;
    eventInfo.bx = (int) -99999.99;
    eventInfo.orbit = (int) -99999.99;
    eventInfo.interactingParton1PdgId = (int) -99999.99;
    eventInfo.interactingParton2PdgId = (int) -99999.99;
    eventInfo.nJets = (int) -99999.99;
  }

  void FillBasicEventInfo(eventInfo_t &eventInfo, const edm::Event& iEvent) {
    eventInfo.run   = iEvent.id().run();
    eventInfo.LS    = iEvent.id().luminosityBlock();
    eventInfo.evnum = iEvent.id().event();
    eventInfo.bx    = iEvent.bunchCrossing();
    eventInfo.orbit = iEvent.orbitNumber();
  }

  void FillGenEventInfo(eventInfo_t &eventInfo, const GenEventInfoProduct *genInfoHandle) {
    eventInfo.pthat = genInfoHandle->hasBinningValues() ? (genInfoHandle->binningValues())[0] : 0.0 ;
    eventInfo.alphaqcd = genInfoHandle->alphaQCD();
    eventInfo.alphaqed = genInfoHandle->alphaQED();
    eventInfo.qscale = genInfoHandle->qScale();
    eventInfo.processid = genInfoHandle->signalProcessID();
    eventInfo.weight = genInfoHandle->weights()[0];
  }

} // end of namespace

#endif
