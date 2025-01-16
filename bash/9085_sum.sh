#!/bin/bash

read n_tc
for ((i = 0; i < n_tc; i++)); do
    read n_elems
    read -a arr
    ((sum = 0))
    for elem in "${arr[@]}"; do
        ((sum += elem))
    done
    echo "$sum"
done