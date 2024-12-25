#!/bin/bash

while IFS= read -r line; do
    lower=0
    upper=0
    blank=0
    number=0
    for ((i=0; i<${#line}; i++)); do
        char=${line:i:1}
        if [[ $char =~ [a-z] ]]; then
            ((lower++))
        elif [[ $char =~ [A-Z] ]]; then
            ((upper++))
        elif [[ $char =~ [0-9] ]]; then
            ((number++))
        elif [[ $char == " " ]]; then
            ((blank++))
        fi
    done
    echo "$lower $upper $number $blank"
done