#include <bits/stdc++.h>

using namespace std;

// l d r
const int DIRS[3][2] = {{0, -1}, {1, 0}, {0, 1}};

int grid_h, grid_w;
int grid[1000][1000];
int dp[1000][1000][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> grid_h >> grid_w;
    for (int y = 0; y < grid_h; y++) {
        for (int x = 0; x < grid_w; x++) {
            cin >> grid[y][x];
            dp[y][x][0] = dp[y][x][1] = dp[y][x][2] = INT_MIN;
        }
    }
}