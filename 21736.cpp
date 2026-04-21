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

const char T_SRC = 'I';
const char T_WALL = 'X';
const char T_PERSON = 'P';
const char T_EMPTY = 'O';

int g_h, g_w;
char grid[600][600];

int dfs(int y, int x) {
    int res = grid[y][x] == T_PERSON;
    
    grid[y][x] = T_WALL;
    for (const auto& [dy, dx]: DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        if (0 <= ny && ny < g_h && 0 <= nx && nx < g_w && grid[ny][nx] != T_WALL) {
            res += dfs(ny, nx);
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    int s_y, s_x;
    FOR(y, g_h) {
        FOR(x, g_w) {
            if (input(grid[y][x]) == T_SRC) {
                s_y = y, s_x = x;
            }
        }
    }

    int ans = dfs(s_y, s_x);

    if (ans) print(ans);
    else print("TT");
}