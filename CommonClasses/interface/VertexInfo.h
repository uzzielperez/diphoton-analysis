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
  struct vertexCollInfo_t {
    std::vector<double> vx;
    std::vector<double> vy;
    std::vector<double> vz;
    std::vector<double> vxError;
    std::vector<double> vyError;
    std::vector<double> vzError;
    std::vector<double> ndof;
    std::vector<double> d0;
    
    std::vector<int> nTracks;
    std::vector<int> isFake;
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

  void FillVertexCollInfo(vertexCollInfo_t &vertexInfo, const reco::VertexCollection* vtxColl ){
    vertexInfo.vx.clear();
    vertexInfo.vy.clear();
    vertexInfo.vz.clear();
    vertexInfo.vxError.clear();
    vertexInfo.vyError.clear();
    vertexInfo.vzError.clear();
    vertexInfo.ndof.clear();
    vertexInfo.d0.clear();
    vertexInfo.nTracks.clear();
    vertexInfo.isFake.clear();

    for (unsigned int i=0; i<vtxColl->size(); i++){

      reco::Vertex iVtx = vtxColl->at(i);

      vertexInfo.vx.push_back( iVtx.x() );
      vertexInfo.vy.push_back( iVtx.y() );
      vertexInfo.vz.push_back( iVtx.z() );
      vertexInfo.vxError.push_back( iVtx.xError() );
      vertexInfo.vyError.push_back( iVtx.yError() );
      vertexInfo.vzError.push_back( iVtx.zError() );
      vertexInfo.ndof.push_back( iVtx.ndof() );
      vertexInfo.d0.push_back( iVtx.position().rho() );
      vertexInfo.nTracks.push_back( iVtx.tracksSize() );
      vertexInfo.isFake.push_back( 1.*iVtx.isFake() );

    }

  }
  
} // end namespace

#endif
