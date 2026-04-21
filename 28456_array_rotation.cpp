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

int sz;
int grid[100][100];
int tmp[100][100];

void shift(int y) {
    int t = grid[y][sz - 1];
    for (int x = sz - 1; x > 0; x--) {
        grid[y][x] = grid[y][x - 1];
    }
    grid[y][0] = t;
}

void rotate() {
    FOR(y, sz) {
        FOR(x, sz) {
            tmp[x][sz - 1 - y] = grid[y][x];
        }
    }

    FOR(y, sz) {
        FOR(x, sz) {
            grid[y][x] = tmp[y][x];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(sz);
    FOR(y, sz) {
        FOR(x, sz) {
            input(grid[y][x]);
        }
    }

    REP(input()) {
        if (input() == 1) {
            shift(input() - 1);
        } else {
            rotate();
        }
    }

    FOR(y, sz) {
        FOR(x, sz) {
            cout << grid[y][x] << ' ';        
        }
        LF;
    }
}