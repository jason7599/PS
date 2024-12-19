read n_lines
for ((i = 0; i < n_lines; i++)); do
    read line
    for ((j = ${#line} - 1; j >= 0; j--)); do
        printf '%c' ${line:j:1}
    done
    echo
done