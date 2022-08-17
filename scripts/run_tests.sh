#!/bin/bash

for item in $(ls .);
do
    if [[ $item = *UT ]];
    then
        echo "Running test $item"

        ./$item
        
        if [[ $? != 0 ]];
        then
            exit 1
        fi
    fi
done