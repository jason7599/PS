#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w, grid[300][300];
int vis[300][300];
int nx_vis_id = 1;

string piistr(pii p) {
    return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

bool is_border(int y, int x) {
    return !y || y == g_h - 1 || !x || x == g_w - 1;
}

int f(int iy, int ix) {
    int vis_id = vis[iy][ix] = nx_vis_id++;
    vector<pii> q({{iy, ix}});
    
    int h = grid[iy][ix];
    int fill_h = INT_MAX;

    for (int i = 0; i < q.size();) {
        for (; i < q.size(); i++) {
            const auto [y, x] = q[i];

            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (grid[ny][nx] > h) {
                    fill_h = min(fill_h, grid[ny][nx]);
                } else if (vis[ny][nx] != vis_id) {
                    if (is_border(ny, nx)) {
                        return 0;
                    }

                    vis[ny][nx] = vis_id;
                    q.push_back({ny, nx});
                }
            }
        }
    }

    int res = 0;
    for (const auto& [y, x] : q) {
        res += fill_h - grid[y][x];
        grid[y][x] = fill_h;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_w >> g_h;
    FOR(y, g_h) {
        FOR(x, g_w) {
            cin >> grid[y][x];
        }
    }

    int ans = 0;
    FORR(y, 1, g_h - 2) {
        FORR(x, 1, g_w - 2) {
            ans += f(y, x);
        }
    }

    PRINT(ans)
}