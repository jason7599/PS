#include <bits/stdc++.h>
using namespace std;

const pair<int, int> MOVES[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int grid[5][5];

int solve(int y, int x) {
    static bool vis[5][5];
    static int score;

    if (grid[y][x] == 1) {
        if (score == 2) {
            return 0;
        }
        score++;
    }

    vis[y][x] = 1;

    int res = 25;
    for (const auto& [dy, dx] : MOVES) {
        int ny = y + dy, nx = x + dx;
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) {
            continue;
        }
        if (grid[ny][nx] == -1 || vis[ny][nx]) {
            continue;
        }
        int t = solve(ny, nx);
        if (t != -1) {
            res = min(res, 1 + t);
        }
    }

    vis[y][x] = 0;

    if (grid[y][x] == 1) {
        score--;
    }

    return res == 25 ? -1 : res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> grid[y][x];
        }
    }

    int s_y, s_x;
    cin >> s_y >> s_x;

    cout << solve(s_y, s_x) << '\n';
}
