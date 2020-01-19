#!/bin/sh
echo "building binary locally in /build directory..."
g++ src/Main.cpp src/CodeNowHere.cpp -o build/cnhtest
echo "binary created: build/cnhtest"
exit 0