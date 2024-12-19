IFS=',' read -a line
sum=0
for num in "${line[@]}"; do
    ((sum = sum + num))
done
echo $sum