read n
for ((i=0; i<n; i++)); do
    read str
    cnt=0
    for ((j=0; j<${#str}; j++)) do
        c="${str:$j:1}"
        
        echo $c
    done
    echo "The number of vowels in $str is $cnt."
done