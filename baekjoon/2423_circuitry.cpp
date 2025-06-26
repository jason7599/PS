#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_h, g_w;
char grid[500][500];
int dmap[501][501];
priority_queue<pair<int, pii>> pq; // <-dist, pos>

void fuck(int ny, int nx, int ndist) {
    if (dmap[ny][nx] > ndist) {
        dmap[ny][nx] = ndist;
        pq.push({-ndist, {ny, nx}});
    }
}

void solve() {
    pq.push({0, {0, 0}});
    dmap[0][0] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        const auto [y, x] = pq.top().second;
        pq.pop();

        if (dmap[y][x] < dist) {
            continue;
        }

        if (y == g_h && x == g_w) {
            return;
        }

        // down-right 
        if (y != g_h && x != g_w) {
            fuck(y + 1, x + 1, dist + (grid[y][x] != '\\'));
        }

        // up-left
        if (y && x) {
            fuck(y - 1, x - 1, dist + (grid[y - 1][x - 1] != '\\'));
        }

        // up-right
        if (y && x != g_w) {
            fuck(y - 1, x + 1, dist + (grid[y - 1][x] != '/'));
        }

        // down-left
        if (y != g_h && x) {
            fuck(y + 1, x - 1, dist + (grid[y][x - 1] != '/'));
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            cin >> grid[y][x];
            dmap[y][x] = INT_MAX;
        }
        dmap[y][g_w] = INT_MAX;
    }
    fill(&dmap[g_h][0], &dmap[g_h][g_w + 1], INT_MAX);

    solve();

    if (dmap[g_h][g_w] == INT_MAX) {
        cout << "NO SOLUTION\n";
    } else {
        cout << dmap[g_h][g_w] << '\n';
    }
}