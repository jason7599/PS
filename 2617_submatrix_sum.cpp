#include <bits/stdc++.h>

using namespace std;

int m_height, m_width;
int matrix_sums[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m_height >> m_width;

    for (int i = 1; i <= m_height; i++) {
        for (int j = 1; j <= m_width; j++) {
            int& x = matrix_sums[i][j];
            cin >> x;
            x += matrix_sums[i - 1][j]
                + matrix_sums[i][j - 1]
                - matrix_sums[i - 1][j - 1];
        }
    }

    int n_queries;
    cin >> n_queries;

    while (n_queries--) {
        int y0, x0, y1, x1;
        cin >> y0 >> x0 >> y1 >> x1;

        int sum = matrix_sums[y1][x1]
            - matrix_sums[y1][x0 - 1]
            - matrix_sums[y0 - 1][x1]
            + matrix_sums[y0 - 1][x0 - 1];
        cout << sum << '\n';
    }
}