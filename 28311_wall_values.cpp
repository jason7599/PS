#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii DIRS[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w;
int grid[201][201]; // -1: start, 0 < n: wall of id n, 0: none
int vis[201][201][401]; // [y][x][n]: n = id of removed wall, 0 if none
int n_starts;
int dst_y, dst_x;
int n_walls;
int next_vis_id;
int without_removal;
int with_removal;

bool is_oob(int y, int x) {
    return y <= 0 || y > g_h || x <= 0 || x > g_w;
}

void bfs() {
    queue<pair<pii, int>> q;
    q.push({{dst_y, dst_x}, 0});
    int vis_id = vis[dst_y][dst_x][0] = ++next_vis_id;

    without_removal = 0;
    with_removal = 0;

    for (int dist = 0, q_size; (q_size = q.size()); dist++) {
        while (q_size--) {
            const auto [y, x] = q.front().first;
            int wall = q.front().second;
            q.pop();

            if (grid[y][x] == -1) {
                if (wall) {
                    with_removal += dist;
                } else {
                    without_removal += dist;
                }
            }

            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (is_oob(ny, nx)) {
                    continue;
                }

                int next_wall;
                if (grid[ny][nx]) {
                    if (wall) {
                        continue;
                    }
                    next_wall = grid[ny][nx];
                } else {
                    next_wall = wall;
                }

                if (vis[ny][nx][next_wall] != vis_id) {
                    vis[ny][nx][next_wall] = vis_id;
                    q.push({{ny, nx}, next_wall});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> g_h >> g_w >> n_starts >> dst_y >> dst_x;

        for (int i = 0; i < n_starts; i++) {
            int y, x;
            cin >> y >> x;
            grid[y][x] = INT_MAX; // hacky
        }

        n_walls = 0;
        for (int y = 1; y <= g_h; y++) {
            for (int x = 1; x <= g_w; x++) {
                char c;
                cin >> c;
                if (c == 'W') {
                    grid[y][x] = ++n_walls;
                } else if (grid[y][x] == INT_MAX) {
                    grid[y][x] = -1;
                } else {
                    grid[y][x] = 0;
                }
            }
        }
        
    }
}