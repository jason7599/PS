#!/bin/bash

# Check if a filename was provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Append .cpp to the filename
FILE_NAME="baekjoon/$1.cpp"

# Check if the file already exists
if [ -f "$FILE_NAME" ]; then
    echo "Error: $FILE_NAME already exists!"
    exit 1
fi

# Create the file with the boilerplate
cat << EOF > "$FILE_NAME"
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
}
EOF

echo "$FILE_NAME created successfully."
