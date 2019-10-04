import os

def get_global_tag(dataset_name):
    '''Determine global tag to use from dataset name.'''
    globalTag = 'notset'
    if "Run2015" in dataset_name:
        globalTag = '76X_dataRun2_16Dec2015_v0'
    elif "Run2016" in dataset_name:
        if 'PromptReco' in dataset_name:
            globalTag = '80X_dataRun2_Prompt_v14'
        elif '03Feb2017' in dataset_name:
            globalTag = '80X_dataRun2_2016SeptRepro_v7'
        elif "17Jul2018" in dataset_name:
            globalTag = '94X_dataRun2_v10'
        else:
            globalTag = '80X_dataRun2_2016SeptRepro_v4'
    elif "Run2017" in dataset_name:
        if "31Mar2018" in dataset_name:
            globalTag = '94X_dataRun2_v11'
        elif "09Aug2019" in dataset_name:
            globalTag = '106X_dataRun2_v20'
        else:
            globalTag = '92X_dataRun2_Prompt_v8'
    elif "Run2018" in dataset_name:
        if "17Sep2018" in dataset_name:
            globalTag = '102X_dataRun2_v11'
        else:
            globalTag = '102X_dataRun2_Prompt_v14'
# otherwise it is MC
    elif "Run201" not in dataset_name: 
        version = os.getenv("CMSSW_VERSION")
        major_version = version.split('_')[1] # version number formattted as CMSSW_X_Y_Z
        if major_version == "10":
            globalTag = '102X_upgrade2018_realistic_v19'
        elif major_version == "9":
            if "Summer16MiniAODv3" in dataset_name:
                globalTag = '94X_mcRun2_asymptotic_v3'
            if "RunIIFall17MiniAODv2" in dataset_name:
                globalTag = '94X_mc2017_realistic_v17'
        elif major_version == "8":
            if "Spring16" in dataset_name:
                globalTag = '80X_mcRun2_asymptotic_2016_miniAODv2'
                if "Summer16" in dataset_name:
            #globalTag = '80X_mcRun2_asymptotic_2016_TrancheIV_v6'
            # the previous tag should only be used when to process
            # samples intended to match data previous to the
            # 03Feb2017 re-miniAOD
                    globalTag = '80X_mcRun2_asymptotic_2016_TrancheIV_v8'
        elif major_version == "7":
            globalTag = '76X_mcRun2_asymptotic_v12'
    else:
        print "Could not determine appropriate global tag from filename"
        sys.exit()
    return globalTag

def is_reminiaod(dataset_name):
    if '03Feb2017' in dataset_name or "17Jul2018" in dataset_name or "31Mar2018" in dataset_name or "09Aug2019" in dataset_name:
        return True
    else:
        return False

def get_dataset_list(dataset_type):
    datasets = [[]]

    if "2015_DiPhotonJets" in dataset_type:
        datasets.append(["/DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
    if "2015_GGJets" in dataset_type:
        datasets.append(["/GGJets_M-60To200_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-200To500_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
    if "2015_GJets" in dataset_type:
        datasets.append(["/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v3/MINIAODSIM"])
        datasets.append(["/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM"])

    if "2016_DiPhotonJets" in dataset_type:
        datasets.append(["/DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
    if "2016_GGJets" in dataset_type:
        datasets.append(["/GGJets_M-60To200_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-200To500_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM"])
    if "2016_GJets" in dataset_type:
        datasets.append(["/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", "/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", "/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", "/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", "/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM"])
        datasets.append(["/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", "/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM"])
    if "2016_GJets_sherpa" in dataset_type:
        datasets.append(["/GJets_Pt-20To100_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
        datasets.append(["/GJets_Pt-100To200_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
        datasets.append(["/GJets_Pt-200To500_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
        datasets.append(["/GJets_Pt-500To1000_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
        datasets.append(["/GJets_Pt-1000To2000_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
        datasets.append(["/GJets_Pt-2000To5000_13TeV-sherpa/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"])
    if "2017_GGJets" in dataset_type:
        datasets.append(["/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-200To500_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-60To200_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/MINIAODSIM"])
        datasets.append(["/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
    if "2017_GJets" in dataset_type:
        datasets.append(["/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/MINIAODSIM","/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_1core_94X_mc2017_realistic_v14_ext1-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/MINIAODSIM"])
        datasets.append(["/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM"])
    if "2018_GGJets" in dataset_type:
        datasets.append(["/GGJets_M-60To200_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-200To500_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-500To1000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
    if "2018_GGJets" in dataset_type:
        datasets.append(["/GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18MiniAOD-4cores5k_102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM"])
        datasets.append(["/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2/MINIAODSIM"])

    return datasets
