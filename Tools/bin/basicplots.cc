#include "diphoton-analysis/Tools/interface/easyplot.hh"
#include "diphoton-analysis/Tools/interface/utilities.hh"

#include "TMath.h"

int main(int argc, char *argv[])
{
  std::string data_year("");

  std::string region;

  if(argc!=3) {
    std::cout << "Syntax: basicplots.exe [barrel/endcap] [2015/2016/2017]" << std::endl;
    return -1;
  }
  else {
    region = argv[1];
    if(region!="barrel" and region!="endcap") {
      std::cout << "Only 'barrel' and 'endcap' are allowed regions. " << std::endl;
      return -1;
    }
    data_year = argv[2];
    if(data_year.compare("2015") !=0 && data_year.compare("2016") != 0 && data_year.compare("2017") != 0 ) {
      std::cout << "Only '2015', '2016', and '2017' are allowed years." << std::endl;
      return -1;
    }
  }

  bool endcap = (region=="endcap");

  std::string kfactor = kfactorString("BB", "R1F1");
  if(endcap) kfactor = kfactorString("BE", "R1F1");

  std::string cut("Photon1.pt>125&&Photon2.pt>125 && abs(Photon1.eta)<1.4442 && abs(Photon2.eta)<1.4442 && Diphoton.Minv > 500 && Diphoton.Minv < 1000 && isGood");
  if(endcap) cut = "Photon1.pt>125&&Photon2.pt>125 && Diphoton.Minv > 500 && Diphoton.Minv < 1000 && isGood && ( !(abs(Photon1.eta)<1.4442 && abs(Photon2.eta)<1.4442) && ((abs(Photon1.eta)<1.4442 && (abs(Photon2.eta)>1.56&&abs(Photon2.eta)<2.5)) || (abs(Photon2.eta)<1.4442 && (abs(Photon1.eta)>1.56&&abs(Photon1.eta)<2.5))))";
  int nbins=100;
  double xmin=0.0; // GeV
  double xmax=2000; // GeV

  // initialize chains and default styles
  init();

  // define samples to be used in histograms
  sample data("data_" + data_year, "Data");
  sample gg("gg", "#gamma#gamma", kfactor);
  sample gj("gj", "#gamma + jets");
  sample vg("vg", "V#gamma");
  sample w("w", "W");
  sample dy("dy", "DY");
  sample ttg("ttg", "t#bar{t}#gamma");
  std::vector<sample> samples;
  samples.push_back(data);
  samples.push_back(ttg);
  samples.push_back(w);
  samples.push_back(vg);
  samples.push_back(dy);
  samples.push_back(gj);
  samples.push_back(gg);

  plot p0(samples, "Minv", cut, nbins/2, xmin, xmax);
  plot p1(samples, "Photon1.pt", cut, nbins/2, xmin, xmax/2);
  plot p2(samples, "Photon2.pt", cut, nbins/2, xmin, xmax/2);
  plot p3(samples, "Diphoton.qt", cut, nbins/2, xmin, xmax/2);
  plot p4(samples, "Diphoton.deltaPhi", cut, nbins/2, -TMath::Pi(), TMath::Pi());
  plot p5(samples, "Diphoton.deltaEta", cut, nbins/2, -5, 5);
  plot p6(samples, "abs(Diphoton.cosThetaStar)", cut, 20, 0, 1);
  plot p7(samples, "nPV", cut, 50, 0, 50);
  plot p8(samples, "Diphoton.deltaR", cut, nbins/2, 0, 5);
  plot p9(samples, "Photon1.eta", cut, nbins/2, -5, 5);
  plot p10(samples, "Photon2.eta", cut, nbins/2, -5, 5);
  plot p11(samples, "Photon1.phi", cut, nbins/2, -TMath::Pi(), TMath::Pi());
  plot p12(samples, "Photon2.phi", cut, nbins/2, -TMath::Pi(), TMath::Pi());

  std::string extraFilenameInfo(region);
  extraFilenameInfo += "_";
  extraFilenameInfo += data_year;

  p0.output("plots", extraFilenameInfo);
  p1.output("plots", extraFilenameInfo);
  p2.output("plots", extraFilenameInfo);
  p3.output("plots", extraFilenameInfo);
  p4.output("plots", extraFilenameInfo);
  p5.output("plots", extraFilenameInfo);
  p6.output("plots", extraFilenameInfo);
  p7.output("plots", extraFilenameInfo);
  p8.output("plots", extraFilenameInfo);
  p9.output("plots", extraFilenameInfo);
  p10.output("plots", extraFilenameInfo);
  p11.output("plots", extraFilenameInfo);
  p12.output("plots", extraFilenameInfo);

}
