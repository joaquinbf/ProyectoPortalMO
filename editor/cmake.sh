#!/bin/sh
mkdir build
cd build/
cmake ..
make
./portal_editor
cd ..
rm -r build/
