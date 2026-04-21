#include <bits/stdc++.h>
#define FOR(i, n) for (ll i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (ll i = s, _e = e; i <= _e; i++)
#define REP(n) for (ll _ = 0, _n = n; _ < _n; _++)
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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // d r u l

pii pii_add(pii lhs, pii rhs) {
    return {lhs.fi + rhs.fi, lhs.se + rhs.se};
}

pii pii_mult(pii p, int t) {
    return {p.fi * t, p.se * t};
}

int d_right(int d) {
    return (d + 3) % 4;
}

int d_left(int d) {
    return (d + 1) % 4;
}

pii transpose(pii pos, int d, int up, int right) {
    pii tmp = pii_add(pos, pii_mult(DIRS[d], up));
    return pii_add(tmp, pii_mult(DIRS[d_right(d)], right));
}

int g_sz;
int grid[499][499];

const pair<pii, int> SPREAD[] = {
    {{0, -1}, 1},
    {{0, 1}, 1},
    {{1, -2}, 2},
    {{1, -1}, 7},
    {{1, 1}, 7},
    {{1, 2}, 2},
    {{2, -1}, 10},
    {{2, 1}, 10},
    {{3, 0}, 5}
};

bool is_oob(int y, int x) {
    return y < 0 || y >= g_sz || x < 0 || x >= g_sz;
}

int solve() {
    int y = g_sz / 2, x = y;
    int d = 3;
    int l = 1;
    int res = 0;

    while (y + x) {
        if (is_oob(y, x)) {
            DBG(y), DBG(x);
            assert(0);
        }
        REP(2) {
            REP(l) {
                int alpha = grid[y][x];
                for (const auto& [sp, pcnt] : SPREAD) {
                    auto [ny, nx] = transpose({y, x}, d, sp.fi, sp.se);
                    
                    int amnt = grid[y][x] * pcnt / 100;
                    alpha -= amnt;

                    if (is_oob(ny, nx)) {
                        res += amnt;
                    } else {
                        grid[ny][nx] += amnt;
                    }
                }
                auto nx = transpose({y, x}, d, 1, 0);
                y = nx.fi, x = nx.se;
            }
            d = d_left(d);
        }
        l++;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    g_sz = input();
    FOR(y, g_sz) {
        FOR(x, g_sz) {
            input(grid[y][x]);
        }
    }

    print(solve());
}