#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w, s_l;
char grid[101][101];
int vis[101][101];
string str;

vector<pii> visl;

int f(int y, int x, int i, int v) {
    vis[y][x] = v;

    if (i == str.length()) {
        i = 0;
        v++;
    }

    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        if (ny <= 0 || ny > g_h || nx <= 0 || nx > g_w) {
            continue;
        }
        if (grid[ny][nx] != str[i] || vis[ny][nx] == v) {
            continue;
        }
        if (vis[ny][nx]) {
            cout << -1 << '\n';
            exit(0);
        }
        vis[ny][nx] = v;
        visl.push_back({ny, nx});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w >> s_l >> str;

    for (int y = 1; y <= g_h; y++) {
        for (int x = 1; x <= g_w; x++) {
            cin >> grid[y][x];
        }
    }
}