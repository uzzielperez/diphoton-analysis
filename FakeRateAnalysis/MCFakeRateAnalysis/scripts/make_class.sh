#!/bin/bash

root -l -b -q diphoton_makeClass.C

echo " "

echo "Removing .C files from this \"scripts\" directory "
rm MCFakeRateAnalysis.C

echo "Moving .h files to analysis directory"
mv MCFakeRateAnalysis.h ../analysis

echo "Done"
echo " "