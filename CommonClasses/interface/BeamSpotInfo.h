#ifndef BEAM_SPOT_INFO
#define BEAM_SPOT_INFO

#include "DataFormats/BeamSpot/interface/BeamSpot.h"

namespace ExoDiPhotons
{
  
  struct beamSpotInfo_t {
    double x0;
    double y0;
    double z0;
    double sigmaZ;
    double x0error;
    double y0error;
    double z0error;
    double sigmaZ0error;
  };
  
  const std::string beamSpotBranchDefString("x0/D:y0:z0:sigmaZ:x0error:y0error:z0error:sigmaZ0error");
  
  void InitBeamSpotInfo(beamSpotInfo_t &beamSpotInfo) {
    beamSpotInfo.x0           = -9999.99;
    beamSpotInfo.y0           = -9999.99;
    beamSpotInfo.z0           = -9999.99;
    beamSpotInfo.sigmaZ       = -9999.99;
    beamSpotInfo.x0error      = -9999.99;
    beamSpotInfo.y0error      = -9999.99;
    beamSpotInfo.z0error      = -9999.99;
    beamSpotInfo.sigmaZ0error = -9999.99;
  }
  
  void FillBeamSpotInfo(beamSpotInfo_t &beamSpotInfo, const reco::BeamSpot *beamSpot) {
    beamSpotInfo.x0           = beamSpot->x0();
    beamSpotInfo.y0           = beamSpot->y0();
    beamSpotInfo.z0           = beamSpot->z0();
    beamSpotInfo.sigmaZ       = beamSpot->sigmaZ();
    beamSpotInfo.x0error      = beamSpot->x0Error();
    beamSpotInfo.y0error      = beamSpot->y0Error();
    beamSpotInfo.z0error      = beamSpot->z0Error();
    beamSpotInfo.sigmaZ0error = beamSpot->sigmaZ0Error();
  }
  
} // end namespace

#endif
