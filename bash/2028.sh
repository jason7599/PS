#!/bin/bash

read n_tc
for ((i = 0; i < n_tc; i++)); do
    read n
    if [[ "$((n ** 2))" == *"$n" ]]; then
        echo YES
    else
        echo NO
    fi
done