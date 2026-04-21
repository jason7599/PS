#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w, grid[100][100];
int dmap[100][100]; // dist to dest, w/o jump

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

void map_levels() {
    priority_queue<pair<int, pii>> pq;
    pq.push({-grid[g_h - 1][g_w - 1], {g_h - 1, g_w - 1}});
    dmap[g_h - 1][g_w - 1] = grid[g_h - 1][g_w - 1];

    for (; pq.size(); pq.pop()) {
        int cur_level = -pq.top().first;
        const auto [y, x] = pq.top().second;

        if (dmap[y][x] < cur_level) {
            continue;
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (is_oob(ny, nx)) {
                continue;
            }

            int nx_level = max(cur_level, grid[ny][nx]);
            if (dmap[ny][nx] > nx_level) {
                dmap[ny][nx] = nx_level;
                pq.push({-nx_level, {ny, nx}});
            }
        }
    }
}

int vis[100][100];
int vis_id = 1;

bool dfs(int y, int x, int max_level) {
    vis[y][x] = vis_id;

    if (grid[y][x] > max_level) {
        return 0;
    }

    if (dmap[y][x] <= max_level) {
        return 1;
    }
    
    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (is_oob(ny, nx)) {
            continue;
        }

        if (vis[ny][nx] != vis_id) {
            if (dfs(ny, nx, max_level)) {
                return 1;
            }
        }

        ny += dy;
        nx += dx;

        if (!is_oob(ny, nx)) {
            if (dmap[ny][nx] <= max_level) {
                return 1;
            }
        }
    }

    return 0;
}

bool check(int max_level) {
    vis_id++;
    return dfs(0, 0, max_level);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            input(grid[y][x]);
            dmap[y][x] = INT_MAX;
        }
    }

    map_levels();

    int ans;
    for (int l = max(grid[0][0], grid[g_h - 1][g_w - 1]), r = dmap[0][0]; l <= r;) {
        int m = (l + r) >> 1;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    print(ans);
}