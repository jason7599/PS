#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w;
bool grid[1001][1001], vis[1001][1001];

int f(int y, int x) {
    vis[y][x] = 1;
    int size = 1;

    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (grid[ny][nx]) {
            continue;
        }

        ny += dy;
        nx += dx;

        if (ny < 0 || ny >= g_h || nx < 0 || nx >= g_w) {
            continue;
        }

        if (!vis[ny][nx]) {
            size += f(ny, nx);
        }
    }

    return size;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_lines;
    cin >> g_h >> g_w >> n_lines;
    g_h = g_h * 2 + 1;
    g_w = g_w * 2 + 1;
    while (n_lines--) {
        int s_y, s_x, e_y, e_x;
        cin >> s_y >> s_x >> e_y >> e_x;
        s_y *= 2, s_x *= 2, e_y *= 2, e_x *= 2;
        for (int y = min(s_y, e_y); y <= max(s_y, e_y); y++) {
            for (int x = min(s_x, e_x); x <= max(s_x, e_x); x++) {
                grid[y][x] = 1;
            }
        }
    }

    int min_size = INT_MAX, max_size = 0;
    for (int y = 1; y < g_h; y += 2) {
        for (int x = 1; x < g_w; x += 2) {
            if (!vis[y][x]) {
                int sz = f(y, x);
                min_size = min(min_size, sz);
                max_size = max(max_size, sz);
            }
        }
    }

    cout << max_size << '\n'  << min_size << '\n';
}