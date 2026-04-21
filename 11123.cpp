#include <bits/stdc++.h>
using namespace std;

int g_h, g_w;
int grid[100][100];
int visited[100][100];
int id;

const pair<int, int> DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int y, int x) {
    visited[y][x] = id;
    for (const auto [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        if (ny < 0 || ny >= g_h || nx < 0 || nx >= g_w) {
            continue;
        }
        if (grid[ny][nx] == id && visited[ny][nx] != id) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    for (id = 1; id <= n_tc; id++) {
        cin >> g_h >> g_w;
        for (int y = 0; y < g_h; y++) {
            for (int x = 0; x < g_w; x++) {
                char c; 
                cin >> c;
                if (c == '#') {
                    grid[y][x] = id;
                }
            }
        }
        int n_groups = 0;
        for (int y = 0; y < g_h; y++) {
            for (int x = 0; x < g_w; x++) {
                if (grid[y][x] == id && visited[y][x] != id) {
                    n_groups++;
                    dfs(y, x);
                }
            }
        }
        cout << n_groups << '\n';
    }
}