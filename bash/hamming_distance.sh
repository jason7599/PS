read n_tc

for ((i=0; i<n_tc; i++)); do
    read str0
    read str1
    ((dist=0))
    for ((j=0; j<${#str0}; j++)); do
        if [[ ${str0:j:1} != ${str1:j:1} ]]; then
            ((dist++))
        fi
    done
    echo "Hamming distance is ${dist}."
done