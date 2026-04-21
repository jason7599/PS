#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_h, g_w;
int grid[1001][1001];
bool vis[1001][1001];
vector<pii> jumps[1000 * 1000 + 1];

bool dfs(int y, int x) {
    vis[y][x] = 1;

    if (y == g_h && x == g_w) {
        return 1;
    }

    for (const auto& [ny, nx] : jumps[grid[y][x]]) {
        if (!vis[ny][nx]) {
            if (dfs(ny, nx)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w;
    for (int y = 1; y <= g_h; y++) {
        for (int x = 1; x <= g_w; x++) {
            cin >> grid[y][x];
            jumps[y * x].push_back({y, x});
        }
    }

    cout << (dfs(1, 1) ? "yes" : "no") << '\n';
}
