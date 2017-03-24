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
echo "Add these lines to MCFakeRateClosureTest.h:"
echo "virtual double   FakeRateEB(double pt);"
echo "virtual double   FakeRateEE(double pt);"

echo " "