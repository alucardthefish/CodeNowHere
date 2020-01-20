#!/bin/sh
echo "building binary locally in /build directory..."
mkdir build
echo "build directory created"
g++ -std=gnu++11 Main.cpp src/CodeNowHere.cpp -o build/cnhtest
echo "binary build: cnhtest"
exit 0