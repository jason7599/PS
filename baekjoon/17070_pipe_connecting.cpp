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

const pii pipes[3] = {{0, 1}, {1, 0}, {1, 1}};

int g_size;
bool grid[16][16];
int dp[16][16][3];

int f(int y, int x, int p) {
    if (y == g_size - 1 && y == x) {
        return 1;
    }

    int& res = dp[y][x][p];
    if (res != -1) {
        return res;
    }

    res = 0;
    FOR(d, 3) {
        if (p + d == 1) {
        cont:
            continue;
        }

        int ny = y + pipes[d].fi;
        int nx = x + pipes[d].se;

        if (ny >= g_size || nx >= g_size) {
            continue;
        }

        RANGE(i, y, ny) {
            RANGE(j, x, nx) {
                if (grid[i][j]) {
                    goto cont;
                }
            }
        }

        res += f(ny, nx, d);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_size);
    FOR(y, g_size) {
        FOR(x, g_size) {
            input(grid[y][x]);
            fill(&dp[y][x][0], &dp[y][x][3], -1);
        }
    }

    print(f(0, 1, 0));
}