#!/bin/sh
mkdir build
cd build/
cmake ..
make
./portal_init
cd ..
rm -r build/
