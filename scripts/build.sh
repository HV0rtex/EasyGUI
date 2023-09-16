#!/bin/bash

if [[ ! -e "build" ]];
then
    mkdir build
fi

if [[ $1 == "SHARED" ]];
then
    cmake -B "build"                                                         \
        -DBUILD_SHARED_LIBRARIES=ON                                          \
        -DCMAKE_PREFIX_PATH="SFML/install/lib/cmake"
else
    cmake -B "build"                                                         \
        -DBUILD_SHARED_LIBRARIES=OFF                                         \
        -DCMAKE_PREFIX_PATH="SFML/install/lib/cmake"
fi

cmake "build"