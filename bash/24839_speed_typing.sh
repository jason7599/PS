#!/bin/bash

read n_tc
for ((t=1; t<=n_tc; t++)); do
    read dst
    read src
    
    dst_idx=0
    n_deletes=0
    for ((src_idx=0; src_idx<${#src}; src_idx++)); do
        if [[ dst_idx -eq ${#dst} 
        || ${src:src_idx:1} != ${dst:dst_idx:1} ]]; then
            ((n_deletes++))
        else
            ((dst_idx++))
        fi
    done
    echo -n "Case #$t: "
    if [[ dst_idx -eq ${#dst} ]]; then
        echo $n_deletes
    else
        echo IMPOSSIBLE
    fi
done