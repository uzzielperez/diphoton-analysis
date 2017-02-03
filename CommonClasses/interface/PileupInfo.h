#ifndef PILEUPINFO_H
#define PILEUPINFO_H
#include <vector>

unsigned int year = 2016;

class pileup {
 private:
  static std::vector<float> m_pileupWeightsMinus1Sigma;
  static std::vector<float> m_pileupWeights;
  static std::vector<float> m_pileupWeightsPlus1Sigma;
  static std::vector<float> m_pileupWeightsMinus1Sigma2016;
  static std::vector<float> m_pileupWeights2016;
  static std::vector<float> m_pileupWeightsPlus1Sigma2016;
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

std::vector<float> pileup::m_pileupWeightsPlus1Sigma2016 = std::vector<float>({
    3.567e-01, 7.039e-01, 1.133e+00, 8.460e-01, 1.020e+00, 1.049e+00,
      7.257e-01, 3.478e-01, 5.006e-01, 6.030e-01, 6.322e-01, 7.328e-01,
      8.278e-01, 9.125e-01, 9.599e-01, 9.885e-01, 1.024e+00, 1.053e+00,
      1.051e+00, 1.027e+00, 1.006e+00, 9.980e-01, 1.015e+00, 1.038e+00,
      1.058e+00, 1.085e+00, 1.121e+00, 1.155e+00, 1.193e+00, 1.231e+00,
      1.246e+00, 1.268e+00, 1.259e+00, 1.234e+00, 1.182e+00, 1.105e+00,
      1.002e+00, 8.894e-01, 7.691e-01, 6.539e-01, 5.325e-01, 4.226e-01,
      3.298e-01, 2.499e-01, 1.886e-01, 1.382e-01, 9.684e-02, 6.865e-02,
      4.735e-02, 3.249e-02, 2.171e-02, 1.453e-02, 9.585e-03, 6.168e-03,
      4.278e-03, 3.071e-03, 2.242e-03, 1.923e-03, 2.023e-03, 2.397e-03,
      3.652e-03, 4.779e-03, 5.725e-03, 6.274e-03, 7.045e-03, 6.866e-03,
      6.372e-03, 5.755e-03, 5.366e-03, 4.866e-03, 4.374e-03, 3.905e-03,
      3.469e-03, 3.090e-03, 2.704e-03});

std::vector<float> pileup::m_pileupWeights2016 = std::vector<float>({
    3.661e-01, 8.939e-01, 1.198e+00, 9.627e-01, 1.121e+00, 1.165e+00,
      7.956e-01, 4.958e-01, 7.422e-01, 8.789e-01, 9.642e-01, 1.072e+00,
      1.125e+00, 1.176e+00, 1.202e+00, 1.208e+00, 1.200e+00, 1.183e+00,
      1.144e+00, 1.097e+00, 1.066e+00, 1.051e+00, 1.052e+00, 1.051e+00,
      1.050e+00, 1.058e+00, 1.072e+00, 1.083e+00, 1.096e+00, 1.108e+00,
      1.095e+00, 1.083e+00, 1.041e+00, 9.858e-01, 9.108e-01, 8.209e-01,
      7.168e-01, 6.100e-01, 5.031e-01, 4.048e-01, 3.092e-01, 2.279e-01,
      1.637e-01, 1.132e-01, 7.730e-02, 5.092e-02, 3.189e-02, 2.009e-02,
      1.226e-02, 7.426e-03, 4.380e-03, 2.608e-03, 1.566e-03, 9.714e-04,
      7.292e-04, 6.727e-04, 7.305e-04, 9.488e-04, 1.355e-03, 1.894e-03,
      3.082e-03, 4.097e-03, 4.874e-03, 5.256e-03, 5.785e-03, 5.515e-03,
      5.000e-03, 4.410e-03, 4.012e-03, 3.548e-03, 3.108e-03, 2.702e-03,
      2.337e-03, 2.025e-03, 1.723e-03});

std::vector<float> pileup::m_pileupWeightsMinus1Sigma2016 = std::vector<float>({
    3.793e-01, 1.141e+00, 1.260e+00, 1.099e+00, 1.250e+00, 1.281e+00,
      9.202e-01, 7.677e-01, 1.093e+00, 1.337e+00, 1.486e+00, 1.528e+00,
      1.498e+00, 1.501e+00, 1.497e+00, 1.444e+00, 1.368e+00, 1.299e+00,
      1.227e+00, 1.166e+00, 1.125e+00, 1.091e+00, 1.064e+00, 1.040e+00,
      1.019e+00, 1.006e+00, 9.970e-01, 9.849e-01, 9.728e-01, 9.565e-01,
      9.147e-01, 8.722e-01, 8.071e-01, 7.343e-01, 6.510e-01, 5.614e-01,
      4.664e-01, 3.745e-01, 2.885e-01, 2.145e-01, 1.497e-01, 9.989e-02,
      6.434e-02, 3.959e-02, 2.389e-02, 1.382e-02, 7.566e-03, 4.156e-03,
      2.215e-03, 1.187e-03, 6.427e-04, 3.841e-04, 2.728e-04, 2.434e-04,
      2.896e-04, 3.958e-04, 5.440e-04, 7.828e-04, 1.151e-03, 1.604e-03,
      2.568e-03, 3.340e-03, 3.880e-03, 4.079e-03, 4.373e-03, 4.058e-03,
      3.579e-03, 3.068e-03, 2.712e-03, 2.327e-03, 1.978e-03, 1.667e-03,
      1.397e-03, 1.172e-03, 9.649e-04});

float pileup::weight(unsigned int npv, int type)
{
  switch (year) {
  case 2015:
    if(type==-1) {
      if(m_pileupWeightsMinus1Sigma.size()!=0 && npv<m_pileupWeightsMinus1Sigma.size()) return static_cast<float>(m_pileupWeightsMinus1Sigma.at(npv));
    }
    else if(type==1) {
      if(m_pileupWeightsPlus1Sigma.size()!=0 && npv<m_pileupWeightsPlus1Sigma.size()) return static_cast<float>(m_pileupWeightsPlus1Sigma.at(npv));
    }
    else {
      if(m_pileupWeights.size()!=0 && npv<m_pileupWeights.size()) return static_cast<float>(m_pileupWeights.at(npv));
    }
  case 2016:
    if(type==-1) {
      if(m_pileupWeightsMinus1Sigma2016.size()!=0 && npv<m_pileupWeightsMinus1Sigma2016.size()) return static_cast<float>(m_pileupWeightsMinus1Sigma2016.at(npv));
    }
    else if(type==1) {
      if(m_pileupWeightsPlus1Sigma2016.size()!=0 && npv<m_pileupWeightsPlus1Sigma2016.size()) return static_cast<float>(m_pileupWeightsPlus1Sigma2016.at(npv));
    }
    else {
      if(m_pileupWeights2016.size()!=0 && npv<m_pileupWeights2016.size()) return static_cast<float>(m_pileupWeights2016.at(npv));
    }
  }

  return 1.0;
}
#endif
