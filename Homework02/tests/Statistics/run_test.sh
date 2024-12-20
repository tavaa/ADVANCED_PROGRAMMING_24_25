#!/bin/bash

make clean > /dev/null 2>&1
make > /dev/null 2>&1

cd ../..  > /dev/null 2>&1 || exit
cd build/ > /dev/null 2>&1 || exit

./StatisticsTest