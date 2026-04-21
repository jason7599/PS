#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii DIRS[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const char DIR_NAMES[] = "URDL";

int g_h, g_w;
char grid[501][510];

bool is_oob(int y, int x) {
    return y <= 0 || y > g_h || x <= 0 || x > g_w;
}

int signal_len(int src_y, int src_x, int dir) {
    static int vis[501][501][4];
    static int next_vis_id = 1;

    int vis_id = vis[src_y][src_x][dir] = next_vis_id++;
    int len = 1;

    for (int y = src_y, x = src_x;; len++) {
        int ny = y + DIRS[dir].first;
        int nx = x + DIRS[dir].second;

        if (is_oob(ny, nx) || grid[ny][nx] == 'C') {
            break;
        }

        if (grid[ny][nx] == '/') {
            switch (dir) {
            case 0: dir = 1; break;
            case 1: dir = 0; break;
            case 2: dir = 3; break;
            case 3: dir = 2; break;
            }
        } else if (grid[ny][nx] == '\\') {
            switch (dir) {
            case 0: dir = 3; break;
            case 1: dir = 2; break;
            case 2: dir = 1; break;
            case 3: dir = 0; break;
            }
        }

        if (vis[ny][nx][dir] == vis_id) {
            return -1;
        }

        vis[ny][nx][dir] = vis_id;

        y = ny, x = nx;
    }

    return len;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    for (int y = 1; y <= g_h; y++) {
        for (int x = 1; x <= g_w; x++) {
            cin >> grid[y][x];
        }
    }

    int src_y, src_x;
    cin >> src_y >> src_x;

    int max_len = 0;
    int max_len_dir;
    for (int d = 0; d < 4; d++) {
        int len = signal_len(src_y, src_x, d);
        if (len == -1 || len > max_len) {
            max_len = len;
            max_len_dir = d;
            if (len == -1) {
                break;
            }
        }
    }

    cout << DIR_NAMES[max_len_dir] << '\n';
    if (max_len == -1) {
        cout << "Voyager";
    } else {
        cout << max_len;
    }
    cout << '\n';
}