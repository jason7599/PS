#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int g_h, g_w;
int grid[1000][1000][3];
bool vis[1000][1000];

bool is_obj(int y, int x, int thr) {
    int sm = 0;
    FOR(i, 3) {
        sm += grid[y][x][i];
    }
    return thr <= sm / 3;
}

void dfs(int y, int x, int thr) {
    vis[y][x] = 1;

    for (auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (0 <= ny && ny < g_h && 0 <= nx && nx < g_w 
        && !vis[ny][nx] && is_obj(ny, nx, thr)) {
            dfs(ny, nx, thr);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            FOR(i, 3) {
                input(grid[y][x][i]);
            }
        }
    }

    int thr = input();

    int ans = 0;
    FOR(y, g_h) {
        FOR(x, g_w) {
            if (!vis[y][x] && is_obj(y, x, thr)) {
                dfs(y, x, thr);
                ans++;
            }
        }
    }

    print(ans);
}