#ifndef FAKERATEANALYSIS_UTILITIES_HH
#define FAKERATEANALYSIS_UTILITIES_HH

TString cmssw_version(int year)
{
  std::map<int, TString> cmssw_version_map;
  cmssw_version_map[2016] = "76X";
  cmssw_version_map[2017] = "94X";
  cmssw_version_map[2018] = "102X";

  return cmssw_version_map[year];
}
#endif
