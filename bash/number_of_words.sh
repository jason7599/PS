# read -a words
# echo "${#words[@]}"
# MLE!!!....

read line
echo "$line" | awk '{print NF}'