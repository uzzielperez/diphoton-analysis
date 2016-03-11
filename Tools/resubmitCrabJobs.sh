#!/bin/bash

crabdir=$1;
blacklist=$2;
whitelist=$3;

echo "Checking $crabdir"

echo $NF;

listjobsFailed=$(crab -status short -c $crabdir | grep -A 1 "Exit Code : [1-9]" | grep "List of jobs:" | cut -d: -f2 | tr "\n" "," | sed 's/ //g');
listjobsAborted=$(crab -status short -c $crabdir | grep -A 2 "Aborted" | grep "List of jobs:" | cut -d: -f2 | tr "\n" "," | sed 's/ //g');

if [ ! -z $listjobsFailed ]
then
echo "Resubmitting" $listjobsFailed;
if [ ! -z $blacklist ]
then
crab -resubmit $listjobsFailed -c $crabdir -GRID.se_black_list=$blacklist;
fi
if [ -z $blacklist ]
then
crab -resubmit $listjobsFailed -c $crabdir;
fi
fi


if [ ! -z $listjobsAborted ]
then
echo "Resubmitting" $listjobsAborted;
if [ ! -z $blacklist ]
then
crab -resubmit $listjobsAborted -c $crabdir -GRID.se_black_list=$blacklist;
fi
if [ -z $blacklist ]
then
crab -resubmit $listjobsAborted -c $crabdir;
fi
fi