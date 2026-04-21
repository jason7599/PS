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

int h, w, g[201][201];

int f(int sy, int sx, int ey, int ex) {
    return g[ey][ex]
        - g[sy - 1][ex]
        - g[ey][sx - 1]
        + g[sy - 1][sx - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(h, w);
    RANGE(y, 1, h) {
        RANGE(x, 1, w) {
            g[y][x] = input()
                + g[y - 1][x]
                + g[y][x - 1]
                - g[y - 1][x - 1];
        }
    }

    int ans = INT_MIN;
    RANGE(y, 1, h) {
        RANGE(x, 1, w) {

            RANGE(yy, 1, y - 1) {
                RANGE(xx, 1, w) {
                    upmax(ans, f(yy, min(x, xx), y, max(x, xx)));
                } 
            }

            RANGE(xx, 1, x) {
                upmax(ans, f(y, xx, y, x));
            }

        }
    }

    print(ans);
}