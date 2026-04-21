#include <bits/stdc++.h>

using namespace std;

int matrix_size;
int matrix[250][250];

int max_vals[250][250];
int min_vals[250][250];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int submatrix_size, n_queries;
    cin >> matrix_size >> submatrix_size >> n_queries;

    for (int y = 0; y < matrix_size; y++) {
        for (int x = 0; x < matrix_size; x++)
            cin >> matrix[y][x];
    }

    
}