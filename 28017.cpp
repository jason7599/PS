#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
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

int n, m;
int grid[500][10'001];
int dp[500][10'001];

int f(int y, int p) {
    if (y == n) return 0;

    int& res = dp[y][p];
    if (res) return res;

    res = INT_MAX;
    RANGE(x, 1, m) {
        if (x == p) continue;
        upmin(res, grid[y][x] + f(y + 1, x));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(n, m);
    FOR(i, n) {
        RANGE(j, 1, m) {
            input(grid[i][j]);
        }
    }

    print(f(0, 0));
}