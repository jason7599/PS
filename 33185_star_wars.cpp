#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int g_h, g_w;
char grid[50][50];
int dp[50][50];

int solve(int y, int x) {
    int& res = dp[y][x];
    if (res != -1) {
        return res;
    }

    res = 0;

    if (y) {
        for (int nx = max(0, x - 1); nx <= min(x + 1, g_w - 1); nx++) {
            if (grid[y - 1][nx] != 'W') {
                res = max(res, solve(y - 1, nx));
            }
        }
    }

    res += grid[y][x] == 'B';
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    vector<pii> starts;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == 'W') {
                starts.push_back({y, x});
            }
            dp[y][x] = -1;
        }
    }

    int ans = 0;
    for (const auto& [y, x] : starts) {
        ans = max(ans, solve(y, x));
    }
    cout << ans << '\n';
}
