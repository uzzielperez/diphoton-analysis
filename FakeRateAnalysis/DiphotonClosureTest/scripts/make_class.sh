#!/bin/bash

root -l -b -q diphoton_makeClass.C

echo " "

echo "Removing .C files from this \"scripts\" directory "
rm DiphotonClosureTest.C

echo "Moving .h files to analysis directory"
mv DiphotonClosureTest.h ../analysis

echo "Done"

echo " "
echo "Add this line to DiphotonClosureTest.h:"
echo "virtual double   fakeRate(TString region, double pt);"

echo " "