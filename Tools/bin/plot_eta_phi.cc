#include "diphoton-analysis/Tools/interface/sampleList.hh"
#include "TCanvas.h"
#include "TH2F.h"
#include "TMath.h"

int main()
{
  init();

  TCanvas *c1 = new TCanvas;
  TH2F *eta_phi_1 = new TH2F("eta_phi_1", "eta_phi_1", 30, -3., 3., 20, -TMath::Pi(), TMath::Pi());
  chains["data_2017"]->Draw("Photon1.phi:Photon1.eta>>eta_phi_1", "isGood", "colz");
  eta_phi_1->SetTitle(";#eta_{1};#phi_{1}");
  c1->Print("plots/eta_phi_photon1.pdf");

  TCanvas *c2 = new TCanvas;
  TH2F *eta_phi_2 = new TH2F("eta_phi_2", "eta_phi_2", 30, -3., 3., 20, -TMath::Pi(), TMath::Pi());
  chains["data_2017"]->Draw("Photon2.phi:Photon2.eta>>eta_phi_2", "isGood", "colz");
  eta_phi_2->SetTitle(";#eta_{2};#phi_{2}");
  c2->Print("plots/eta_phi_photon2.pdf");

  return 0;
}
