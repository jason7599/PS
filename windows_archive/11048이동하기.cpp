#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int A[1000][1000];
int DP[1000][1000];

int dx[] = { 1, 0, 1 };
int dy[] = { 0, 1, 1 };

int func(int x = 0, int y = 0) {

    if (DP[x][y] != -1) return DP[x][y];
    if (x == n - 1 && y == m - 1) {
        DP[x][y] = A[x][y];
        return DP[x][y];
    }
    int res = 0;
    for (int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
        res = max(res, func(nx, ny));
    }
    DP[x][y] = res + A[x][y];
    return DP[x][y];
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            DP[i][j] = -1;
        }
    }

    cout << func();

}