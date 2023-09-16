#!/bin/bash

if [[ $1 == "SHARED" ]];
then
    cmake -B "${{github.workspace}}/build"                                   \
        -DBUILD_SHARED_LIBRARIES=ON                                          \
        -DCMAKE_PREFIX_PATH="${{github.workspace}}/SFML/install/lib/cmake"
else
    cmake -B "${{github.workspace}}/build"                                   \
        -DBUILD_SHARED_LIBRARIES=OFF                                         \
        -DCMAKE_PREFIX_PATH="${{github.workspace}}/SFML/install/lib/cmake"
fi

cmake "${{github.workspace}}/build"