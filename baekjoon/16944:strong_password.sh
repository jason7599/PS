read len
read str

for ((i = 0; i < $len; i++)) do
    c="${str:$i:1}"
    echo $c
done