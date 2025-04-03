#include <bits/stdc++.h>

using namespace std;

int grid_height, grid_width;
char grid[10][10];

int64_t solve(int y, int x, const string& target, size_t idx, vector<vector<vector<int64_t>>>& dp) {
    if (idx == target.length() - 1) {
        return 1;
    }

    int64_t& res = dp[y][x][idx];
    if (res) {
        return max(res, 0l);
    }

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (!dy && !dx) {
                continue;
            }
            int ny = y + dy;
            int nx = x + dx;
            if (ny == -1) {
                ny = grid_height - 1;
            }
            else if (ny == grid_height) {
                ny = 0;
            }
            if (nx == -1) {
                nx = grid_width - 1;
            }
            else if (nx == grid_width) {
                nx = 0;
            }

            if (grid[ny][nx] == target[idx + 1]) {
                res += solve(ny, nx, target, idx + 1, dp);
            }
        }
    }

    if (!res) {
        res = -1;
        return 0;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_targets;
    cin >> grid_height >> grid_width >> n_targets;

    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
            cin >> grid[y][x];
        }
    }

    while (n_targets--) {
        string target;
        cin >> target;

        vector<vector<vector<int64_t>>> dp(
            grid_height, vector<vector<int64_t>> (
                grid_width, vector<int64_t>(
                    target.length())
            )
        );

        int64_t ans = 0;
        for (int y = 0; y < grid_height; y++) {
            for (int x = 0; x < grid_width; x++) {
                if (grid[y][x] == target.front()) {
                    ans += solve(y, x, target, 0, dp);
                }
            }
        }

        cout << ans << '\n';
    }
}