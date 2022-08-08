#!/bin/bash

#
# Cleaning previous environment
#
if [[ -e "../build" ]]; then
    rm -rf ../build
fi

#
# Recreating container for build files
#
mkdir ../build
cd ../build

#
# Configuring CMake & building project
#
cmake ../
make && make install .
