#!/bin/bash

if [[ "$1" == *.cpp ]]; then
    g++ "$1" -o a.out && ./a.out && rm a.out
elif [[ "$1" == *.rs ]]; then 
    rustc "$1" -o a.out && ./a.out && rm a.out
else
    echo "wtf kind of file is this?"
    exit 1
fi