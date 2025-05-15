#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_h, g_w;
int grid[1000][1000];
int breaks[1000][1000];

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        priority_queue<pair<int, pii>> pq;
        cin >> g_h >> g_w;
        for (int y = 0; y < g_h; y++) {
            for (int x = 0; x < g_w; x++) {
                cin >> grid[y][x];
                if (!y || y == g_h - 1 || !x || x == g_w - 1) {
                    pq.push({-(breaks[y][x] = grid[y][x]), {y, x}});
                } else {
                    breaks[y][x] = INT_MAX;
                }
            }
        }
        int max_breaks = -1;
        int max_break_cnt;
        while (pq.size()) {
            int n_breaks = -pq.top().first;
            const auto [y, x] = pq.top().second;
            pq.pop();
            if (breaks[y][x] < n_breaks) {
                continue;
            }
            if (!grid[y][x]) {
                if (n_breaks > max_breaks) {
                    max_breaks = n_breaks;
                    max_break_cnt = 1;
                } else if (n_breaks == max_breaks) {
                    max_break_cnt++;
                }
            }
            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;
                if (ny < 0 || ny >= g_h || nx < 0 || nx >= g_w) {
                    continue;
                }
                int next_breaks = n_breaks + grid[ny][nx];
                if (breaks[ny][nx] > next_breaks) {
                    breaks[ny][nx] = next_breaks;
                    pq.push({-next_breaks, {ny, nx}});
                }
            }
        }
        cout << max_breaks << ' ' << max_break_cnt << '\n';
    }
}
