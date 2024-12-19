read n_tc

for ((i = 0; i < n_tc; i++)); do
    read
    read elems
    echo "$elems" | awk '{ for (i = 1; i <= NF; i++) s += $i } END {print s}'
done