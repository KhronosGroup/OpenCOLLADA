#!/bin/sh

rm -r -f cmake_temp
mkdir cmake_temp
cd cmake_temp
cmake -DCMAKE_OSX_ARCHITECTURES="x86_64" -G Xcode ../