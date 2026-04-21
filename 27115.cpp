#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w;
bool vis[3001][3001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> g_h >> g_w >> k;

    priority_queue<pair<int, pii>> pq;
    while (k--) {
        int y, x, p;
        cin >> y >> x >> p;
        pq.push({p, {y, x}});
    }

    int ans = 0;
    queue<pii> q;
    for (int p = pq.top().first; p > 0; p--) {
        while (!pq.empty() && pq.top().first == p) {
            const auto [y, x] = pq.top().second;
            if (!vis[y][x]) {
                vis[y][x] = 1;
                q.push({y, x});
            }
            pq.pop();
        }

        for (int q_size = q.size(); q_size; q_size--) {
            const auto [y, x] = q.front();
            q.pop();
            ans++;

            for (const auto& [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (ny <= 0 || ny > g_h || nx <= 0 || nx > g_w) {
                    continue;
                }

                if (!vis[ny][nx]) {
                    vis[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }
    }

    cout << ans + q.size() << '\n';
}