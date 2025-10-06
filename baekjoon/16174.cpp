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

int g_sz, grid[64][64];
bool vis[64][64];

bool f(int y, int x) {
    if (y == g_sz - 1 && y == x) {
        return 1;
    }

    if (y >= g_sz || x >= g_sz || !grid[y][x] || vis[y][x]) {
        return 0;
    }

    vis[y][x] = 1;

    return f(y + grid[y][x], x) || f(y, x + grid[y][x]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(y, input(g_sz)) {
        FOR(x, g_sz) {
            input(grid[y][x]);
        }
    }

    print(f(0, 0) ? "HaruHaru" : "Hing");
}