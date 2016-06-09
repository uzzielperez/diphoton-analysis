#ifndef VERTEX_INFO
#define VERTEX_INFO

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

namespace ExoDiPhotons
{
  
  struct vertexInfo_t {
    double vx;
    double vy;
    double vz;
    double vxError;
    double vyError;
    double vzError;
    double ndof;
    double d0;
    
    int nTracks;
    
    bool isFake;
  };
  
  std::string vertexBranchDefString("vx/D:vy:vz:vxError:vyError:vzError:ndof:d0:nTracks/I:isFake/O");
  
  void InitVertexInfo(vertexInfo_t &vertexInfo) {
    vertexInfo.vx      = -9999.99;
    vertexInfo.vy      = -9999.99;
    vertexInfo.vz      = -9999.99;
    vertexInfo.vxError = -9999.99;
    vertexInfo.vyError = -9999.99;
    vertexInfo.vzError = -9999.99;
    vertexInfo.ndof    = -9999.99;
    vertexInfo.d0      = -9999.99;
    
    vertexInfo.nTracks = -9999;
    
    vertexInfo.isFake = false;
  }
  
  void FillVertexInfo(vertexInfo_t &vertexInfo, const reco::Vertex *vertex) {
    vertexInfo.vx      = vertex->x();
    vertexInfo.vy      = vertex->y();
    vertexInfo.vz      = vertex->z();
    vertexInfo.vxError = vertex->xError();
    vertexInfo.vyError = vertex->yError();
    vertexInfo.vzError = vertex->zError();
    vertexInfo.ndof    = vertex->ndof();
    vertexInfo.d0      = vertex->position().rho();
    
    vertexInfo.nTracks = vertex->tracksSize();
    
    vertexInfo.isFake = vertex->isFake();
  }
  
} // end namespace

#endif
