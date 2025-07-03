#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w, grid[300][300];
bool vis[300][300];

int vis2[300][300];
int nx_vis_id = 1;

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

bool is_border(int y, int x) {
    return !y || y == g_h - 1 || !x || x == g_w - 1;
}

// string piistr(int y, int x) {
//     return "{" + to_string(y) + ", " + to_string(x) + "}"; 
// }

int f(int iy, int ix) {
    vector<pii> q;
    q.push_back({iy, ix});
    vis[iy][ix] = 1;

    priority_queue<pair<int, pii>> pq; // <-height, <y, x>>

    int res = 0;
    int base_h = grid[iy][ix];
    bool spill = 0;

    int vis_id = vis2[iy][ix] = nx_vis_id++;

    // cout << "start = " << piistr(iy, ix) << '\n';

    for (int i = 0; i < q.size();) {
        // cout << "base_h = " << base_h << '\n';

        for (; i < q.size(); i++) {
            const auto [y, x] = q[i];

            // cout << "\tpop " << piistr(y, x) << '\n';

            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (!is_oob(ny, nx)) {
                    if (grid[ny][nx] > base_h) {
                        if (vis2[ny][nx] != vis_id) {
                            vis2[ny][nx] = vis_id;
                            pq.push({-grid[ny][nx], {ny, nx}});
                        }
                    } else if (!vis[ny][nx]) {
                        vis[ny][nx] = 1;
                        if (is_border(ny, nx)) {
                            spill = 1;
                        }
                        // cout << "\t\tpush " << piistr(ny, nx) << '\n';
                        q.push_back({ny, nx});
                    }
                }
            }
        }

        if (spill || pq.empty()) {
            break;
        }
        
        base_h = -pq.top().first;
        // cout << "\tnew base_h = " << base_h << '\n';
        for (const auto [y, x] : q) {
            // if (grid[y][x] != base_h) {
            //     cout << "\tfill " << piistr(y, x) << " (+" << base_h - grid[y][x] << ")\n";
            // }

            res += base_h - grid[y][x];
            grid[y][x] = base_h;
        }
        
        while (!pq.empty() && -pq.top().first == base_h) {
            const auto [y, x] = pq.top().second;
            pq.pop();
            vis[y][x] = 1;
            q.push_back({y, x});
            // cout << "\tpush " << piistr(y, x) << '\n';

            // if (is_border(y, x)) {
            //     spill = 1;
            // }
        }

        // if (spill) {
        //     break;
        // }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    priority_queue<pair<int, pii>> pq;

    cin >> g_w >> g_h;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            cin >> grid[y][x];
            if (!is_border(y, x)) {
                pq.push({-grid[y][x], {y, x}});
            }
        }
    }

    int res = 0;
    while (!pq.empty()) {
        const auto [y, x] = pq.top().second;
        pq.pop();

        if (!vis[y][x]) {
            res += f(y, x);
        }
    }

    cout << res << '\n';
}