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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_sz;
int grid[EE(3)][EE(3)];
int dmap[EE(3)][EE(3)];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_sz);
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            input(grid[y][x]);
            dmap[y][x] = INT_MAX;
        }
    }

    dmap[0][0] = 0;
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {0, 0}});

    while (pq.size()) {
        int c_d = -pq.top().fi;
        const auto [y, x] = pq.top().se;
        pq.pop();

        if (dmap[y][x] < c_d) {
            continue;
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (ny < 0 || ny >= g_sz || nx < 0 || nx >= g_sz) {
                continue;
            }

            int nx_d = max(c_d, abs(grid[y][x] - grid[ny][nx]));
            if (dmap[ny][nx] > nx_d) {
                dmap[ny][nx] = nx_d;
                pq.push({-nx_d, {ny, nx}});
            }
        }
    }

    print(dmap[g_sz - 1][g_sz - 1]);
}
