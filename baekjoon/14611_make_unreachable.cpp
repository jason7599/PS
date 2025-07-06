#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_h, g_w;
int64_t grid[300][300];
int64_t dmap[300][300];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w;

    priority_queue<pair<int64_t, pii>> pq; // <-cost, <y, x>>

    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            cin >> grid[y][x];
            dmap[y][x] = INT64_MAX;

            if (grid[y][x] == -2) {
                grid[y][x] = 0;
            }

            if (grid[y][x] != -1 && (y == g_h - 1 || !x)) {
                pq.push({-grid[y][x], {y, x}});
                dmap[y][x] = grid[y][x];
            }
        }
    }

    int64_t ans = INT64_MAX;

    while (!pq.empty()) {
        int64_t cur_cost = -pq.top().first;
        const auto [y, x] = pq.top().second;
        pq.pop();

        if (dmap[y][x] < cur_cost) {
            continue;
        }

        if (!y || x == g_w - 1) {
            ans = min(ans, cur_cost);
            continue;
        }

        for (int ny = max(y - 1, 0); ny <= min(y + 1, g_h - 1); ny++) {
            for (int nx = max(x - 1, 0); nx <= min(x + 1, g_w - 1); nx++) {
                if ((ny == y && nx == x) || grid[ny][nx] == -1) {
                    continue;
                }

                int64_t nxt_cost = cur_cost + grid[ny][nx];
                if (nxt_cost < dmap[ny][nx]) {
                    dmap[ny][nx] = nxt_cost;
                    pq.push({-nxt_cost, {ny, nx}});
                }
            }
        }
    }

    cout << (ans == INT64_MAX ? -1 : ans) << '\n';
}