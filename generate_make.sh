#!/bin/sh

rm -r -f cmake_temp
mkdir cmake_temp
cd cmake_temp
cmake -G "Unix Makefiles" ../
