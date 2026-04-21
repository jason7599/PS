#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }

const pii DIRS[] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};

int g_h;
int grid[100'000][3];
int dp[100'000][3];

bool is_oob(int y, int x) {
    return g_h <= y || x < 0 || 3 <= x || (y == g_h - 1 && x == 2);
}

int f(int y, int x) {
    int& res = dp[y][x];
    if (res != INT_MAX) {
        return res;
    }

    if (y == g_h - 1 && x == 1) {
        return res = grid[y][x];
    }

    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;

        if (!is_oob(ny, nx)) {
            upmin(res, f(ny, nx));
        }
    }

    return res += grid[y][x];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int tc = 1;; tc++) {
        if (input(g_h) == 0) {
            break;
        }
        FOR(y, g_h) {
            FOR(x, 3) {
                input(grid[y][x]);
                dp[y][x] = INT_MAX;
            }
        }
        cout << tc << ". " << f(0, 1) << '\n';
    }
}