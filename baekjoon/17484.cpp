#include <bits/stdc++.h>
using namespace std;

int g_h, g_w;
int grid[6][6];
int dp[6][6][4];

int solve(int y, int x, int prev_d) {
    int& res = dp[y][x][prev_d];
    if (res) {
        return res;
    }

    if (y == g_h - 1) {
        return res = grid[y][x];
    }

    res = INT_MAX;
    for (int d = 0; d < 3; d++) {
        if (d == prev_d) {
            continue;
        }
        int nx = x + d - 1;
        if (nx < 0 || nx == g_w) {
            continue;
        }
        res = min(res, solve(y + 1, nx, d));
    }
    res += grid[y][x];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            cin >> grid[y][x];
        }
    }

    int ans = INT_MAX;
    for (int x = 0; x < g_w; x++) {
        ans = min(ans, solve(0, x, 3));
    }
    cout << ans << '\n';
}
