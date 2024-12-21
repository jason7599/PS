while IFS= read -r line; do
	while [[ $line == *BUG* ]]; do
		line=${line//BUG/}
	done
	echo "$line"
done
