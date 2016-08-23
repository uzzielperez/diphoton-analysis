#!/usr/bin/env python
"""Submit a set of crab jobs to compute cross sections"""
import os


DATASETS = [[]]

# command to get a (formatted) list of all ADD datasets:
# das_client.py --limit=0 --query="dataset dataset=/ADDGravToGG*/RunIIFall15MiniAODv2-*/MINIAODSIM" | awk '{print "DATASETS.append(['\''"$1"'\''])"}'

# ADD signal samples
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-4_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-1_M-2000To3500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-4_M-2000To3500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v2/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-4_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-1_M-3000To4500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-4_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-4_M-3000To4500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-1_M-3000To5000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-4_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv1-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM']) # MiniAODv2 not avaliable
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-4_M-3000To5000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-1_M-4000To5500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-4_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-4_M-4000To5500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-1_M-4000To6000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-4_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-4_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-4_M-4000To6000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-2_KK-4_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
# background for ADD samples
DATASETS.append(['/GG_M-200To500_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/GG_M-500To1000_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/GG_M-1000To2000_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/GG_M-2000To4000_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/GG_M-4000To8000_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])
DATASETS.append(['/GG_M-8000To13000_Pt-70_13TeV-sherpa/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'])

for ilist in DATASETS:
  nevents = 0
  print ""

  for ids in ilist:
    cmssw_base = os.getenv("CMSSW_BASE")
    datasetID = ids.replace('/', '', 1).replace('/', '_', 1)
    datasetID = datasetID[0:datasetID.find('/')]
    inputfile = cmssw_base + "/src/diphoton-analysis/ExoDiPhotonBackgroundAnalyzer/test/crab_cfg_xsec_template.py"
    outputfile = "crab_cfg_xsec" + datasetID + ".py"

    s = open(inputfile).read()
    s = s.replace('DATASETNAME', ids)
    f = open(outputfile, 'w')
    f.write(s)
    f.close()
    print "Wrote crab configuration file " + outputfile

    cmd = "crab submit -c " + outputfile
    os.system(cmd)
    print "Submitted ", ids
