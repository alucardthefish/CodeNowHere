#!/bin/sh
echo "building binary locally in /build directory..."
mkdir build
echo "build directory created"
g++ -std=gnu++11 Main.cpp src/CodeNowHere.cpp src/docopt.cpp src/OnlyFileBehavior.cpp src/ManyFileBehavior.cpp src/ICommandBehavior.cpp src/Helper.cpp -o build/cnh
echo "binary build: cnhtest"
exit 0