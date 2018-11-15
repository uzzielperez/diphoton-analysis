#include "diphoton-analysis/Tools/interface/easyplot.hh"
#include "diphoton-analysis/Tools/interface/utilities.hh"

#include "TMath.h"

int main(int argc, char *argv[])
{
  std::string data_year("");

  std::string region;

  if(argc!=3) {
    std::cout << "Syntax: datadriven.exe [barrel/endcap] [2015/2016/2017/2018/2017_2018/2016_2017_2018/2018_newjson]" << std::endl;
    return -1;
  }
  else {
    region = argv[1];
    if(region!="barrel" and region!="endcap") {
      std::cout << "Only 'barrel' and 'endcap' are allowed regions. " << std::endl;
      return -1;
    }
    data_year = argv[2];
    if(data_year.compare("2015") !=0 && data_year.compare("2016") != 0 && data_year.compare("2017") != 0
       && data_year.compare("2018") != 0 && data_year.compare("2017_2018") && data_year.compare("2018_newjson") != 0  ) {
      std::cout << "Only '2015', '2016', '2017', '2018', and '2017_2018' are allowed years, plus '2018_newjson' for the data from the latest JSON." << std::endl;
      return -1;
    }
  }

  bool endcap = (region=="endcap");

  std::string kfactor = kfactorString("BB", "R1F1");
  if(endcap) kfactor = kfactorString("BE", "R1F1");

  std::string pt_cut("125");
  if(data_year.compare("2016") == 0) pt_cut = "125";
  std::string minv_cut("Diphoton.Minv > 500");
  std::string kinematic_cuts("Photon1.pt>" + pt_cut + " && Photon2.pt>" + pt_cut + "&&" + minv_cut);
  std::string id_cuts("Photon1.r9_5x5 > 0.8 && Photon2.r9_5x5 > 0.8");
  std::string eta_cuts_BB("abs(Photon1.scEta)<1.4442 && abs(Photon2.scEta)<1.4442");
  std::string eta_cuts_BE("( !(abs(Photon1.scEta)<1.4442 && abs(Photon2.scEta)<1.4442) && ((abs(Photon1.scEta)<1.4442 && (abs(Photon2.scEta)>1.56&&abs(Photon2.scEta)<2.5)) || (abs(Photon2.scEta)<1.4442 && (abs(Photon1.scEta)>1.56&&abs(Photon1.scEta)<2.5))))");
  std::string cut_no_Minv(kinematic_cuts + "&&" + eta_cuts_BB + "&&" + id_cuts + "&& isGood");
  if(endcap) cut_no_Minv = kinematic_cuts + "&&" + eta_cuts_BE + "&&" + id_cuts + "&& isGood";
  std::string cut(cut_no_Minv);
  cut += "&& Diphoton.Minv < 1000";

  // initialize chains and default styles
  init();

  std::string trigger("(HLT_DoublePhoton70 || HLT_ECALHT800)");
  if(data_year.compare("2016") == 0) trigger = "(HLT_DoublePhoton60 || HLT_ECALHT800)";
  // define samples to be used in histograms
  sample data("data", "Data", data_year, trigger);
  data.isData = true;
  sample gg("gg", "#gamma#gamma", data_year, kfactor);
  sample gj("gj", "#gamma + jets", data_year);
  if(region.compare("barrel") == 0) gj.isDataDrivenBarrel = true;
  if(region.compare("endcap") == 0) gj.isDataDrivenEndcap = true;
  sample vg("vg", "V#gamma", data_year);
  sample w("w", "W", data_year);
  sample dy("dy", "DY", data_year);
  sample ttg("ttg", "t#bar{t}#gamma", data_year);
  std::vector<sample> samples;
  samples.push_back(data);
  samples.push_back(ttg);
  samples.push_back(w);
  samples.push_back(vg);
  samples.push_back(dy);
  samples.push_back(gj);
  samples.push_back(gg);

  plot p0(samples, "Minv", cut_no_Minv, 40, 0, 2000);

  std::string extraFilenameInfo(region);
  extraFilenameInfo += "_datadriven_";
  extraFilenameInfo += data_year;

  p0.output("plots", extraFilenameInfo);

}
