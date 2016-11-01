#!/bin/bash

root -l -b -q diphoton_makeClass.C

echo " "

echo "Removing .C files from this \"scripts\" directory "
rm MCFakeRateClosureTest.C
rm MCFakeRateClosureTestWithFakes.C

echo "Moving .h files to analysis directory"
mv MCFakeRateClosureTest.h ../analysis
mv MCFakeRateClosureTestWithFakes.h ../analysis

echo "Done"

echo " "