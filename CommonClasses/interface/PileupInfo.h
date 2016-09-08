#ifndef PILEUPINFO_H
#define PILEUPINFO_H
#include <vector>

class pileup {
 private:
  static std::vector<float> m_pileupWeightsMinus1Sigma;
  static std::vector<float> m_pileupWeights;
  static std::vector<float> m_pileupWeightsPlus1Sigma;
 public:
  static float weight(unsigned int npv, int type);
};

std::vector<float> pileup::m_pileupWeightsPlus1Sigma = std::vector<float>({
    4.130e-01, 6.438e-01, 7.489e-01, 8.671e-01, 8.671e-01, 6.140e-01, 
      3.840e-01, 4.785e-01, 8.062e-01, 1.060e+00, 1.177e+00, 1.209e+00, 
      1.206e+00, 1.136e+00, 9.725e-01, 7.459e-01, 5.109e-01, 3.104e-01, 
      1.630e-01, 7.124e-02, 2.635e-02, 9.338e-03, 3.730e-03, 1.837e-03, 
      1.081e-03, 6.947e-04, 4.558e-04, 2.969e-04, 1.906e-04, 1.206e-04, 
      7.524e-05, 4.627e-05, 2.804e-05, 1.672e-05, 9.780e-06, 5.592e-06, 
      3.107e-06, 1.667e-06, 8.572e-07, 4.193e-07, 1.941e-07, 8.487e-08, 
      3.507e-08, 1.375e-08, 5.139e-09, 1.840e-09, 6.339e-10, 2.108e-10, 
      6.778e-11, 2.121e-11});

// pileupCalc.py -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-258750_13TeV_PromptReco_Collisions15_25ns_JSON_Silver_v2.txt --inputLumiJSON /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/PileUp/pileup_latest.txt --calcMode true --minBiasXsec 69000 --maxPileupBin 50 --numPileupBins 50 pileup_nom.root

std::vector<float> pileup::m_pileupWeights = std::vector<float>({
    4.852e-01, 6.992e-01, 7.774e-01, 9.872e-01, 9.537e-01, 7.885e-01, 
      6.811e-01, 9.711e-01, 1.314e+00, 1.419e+00, 1.359e+00, 1.248e+00, 
      1.102e+00, 8.906e-01, 6.364e-01, 4.002e-01, 2.237e-01, 1.122e-01, 
      5.056e-02, 2.039e-02, 7.672e-03, 3.069e-03, 1.472e-03, 8.353e-04, 
      5.115e-04, 3.157e-04, 1.910e-04, 1.127e-04, 6.491e-05, 3.662e-05, 
      2.026e-05, 1.099e-05, 5.846e-06, 3.043e-06, 1.547e-06, 7.643e-07, 
      3.652e-07, 1.676e-07, 7.335e-08, 3.038e-08, 1.185e-08, 4.342e-09, 
      1.496e-09, 4.867e-10, 1.502e-10, 4.415e-11, 1.243e-11, 3.305e-12, 
      1.098e-12, 0.000e+00});

std::vector<float> pileup::m_pileupWeightsMinus1Sigma = std::vector<float>({
    5.676e-01, 7.579e-01, 8.278e-01, 1.127e+00, 1.061e+00, 1.116e+00, 
      1.393e+00, 1.887e+00, 1.987e+00, 1.777e+00, 1.480e+00, 1.200e+00, 
      9.080e-01, 6.067e-01, 3.498e-01, 1.757e-01, 7.916e-02, 3.329e-02, 
      1.362e-02, 5.574e-03, 2.401e-03, 1.175e-03, 6.507e-04, 3.788e-04, 
      2.191e-04, 1.228e-04, 6.631e-05, 3.460e-05, 1.751e-05, 8.628e-06, 
      4.143e-06, 1.940e-06, 8.850e-07, 3.929e-07, 1.692e-07, 7.047e-08, 
      2.821e-08, 1.078e-08, 3.904e-09, 1.331e-09, 4.245e-10, 1.265e-10, 
      3.523e-11, 9.210e-12, 2.275e-12, 5.318e-13, 1.126e-13, 0.000e+00, 
      0.000e+00, 0.000e+00});

float pileup::weight(unsigned int npv, int type)
{
  if(type==-1) {
    if(m_pileupWeightsMinus1Sigma.size()!=0 && npv<m_pileupWeightsMinus1Sigma.size()) return static_cast<float>(m_pileupWeightsMinus1Sigma.at(npv));
  }
  else if(type==1) {
    if(m_pileupWeightsPlus1Sigma.size()!=0 && npv<m_pileupWeightsPlus1Sigma.size()) return static_cast<float>(m_pileupWeightsPlus1Sigma.at(npv));
  }
  else {
    if(m_pileupWeights.size()!=0 && npv<m_pileupWeights.size()) return static_cast<float>(m_pileupWeights.at(npv));
  }
  return 1.0;
}
#endif
