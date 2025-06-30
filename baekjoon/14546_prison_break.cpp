#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii MOVES[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool f(const vector<vector<char>>& grid, int y, int x, pii dest, vector<vector<bool>>& vis) {
    if (y == dest.first && x == dest.second) {
        return 1;
    }

    vis[y][x] = 1;

    for (const auto& [dy, dx] : MOVES) {
        int ny = y + dy;
        int nx = x + dx;

        if (0 <= ny && ny < grid.size() && 0 <= nx && nx < grid[0].size() && grid[y][x] == grid[ny][nx] && !vis[ny][nx]) {
            if (f(grid, ny, nx, dest, vis)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        int g_h, g_w, s_y, s_x, e_y, e_x;
        cin >> g_w >> g_h >> s_x >> s_y >> e_x >> e_y;

        s_x--, e_x--;
        s_y = g_h - s_y;
        e_y = g_h - e_y;

        vector<vector<char>> grid(g_h, vector<char>(g_w));
        vector<vector<bool>> vis(g_h, vector<bool>(g_w));

        for (int y = 0; y < g_h; y++) {
            for (int x = 0; x < g_w; x++) {
                cin >> grid[y][x];
            }
        }

        cout << (f(grid, s_y, s_x, {e_y, e_x}, vis) ? "YES" : "NO") << '\n';
    }
}