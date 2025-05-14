#include <bits/stdc++.h>
using namespace std;

int grid_size;
int grid[30][30];
int64_t dp[30][30];

int64_t solve(int y, int x) {
    int64_t& res = dp[y][x];
    if (res != -1) {
        return res;
    }

    res = y + 1 < grid_size ? solve(y + 1, x) : 0;
    if (x + 1 < grid_size) {
        res = max(res, solve(y, x + 1));
    }

    if (grid[y][x]) {
        res += 1ll << (2 * grid_size - y - x - 2);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> grid_size;
    for (int y = 0; y < grid_size; y++) {
        for (int x = 0; x < grid_size; x++) {
            cin >> grid[y][x];
            dp[y][x] = -1;
        }
    }

    cout << solve(0, 0) << '\n';
}