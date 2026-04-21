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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int csum[1025][1025];

int get_sum(int sy, int sx, int ey, int ex) {
    return (
        csum[ey][ex]
        - csum[ey][sx - 1]
        - csum[sy - 1][ex]
        + csum[sy - 1][sx - 1]
    );
}

int f(int y, int x, int sz) {
    int sm = get_sum(y, x, y + sz - 1, x + sz - 1);
    if (sz == 1) {
        return sm;
    }

    int res = 0;
    for (int yy = y, i = 0; yy <= y + sz / 2; yy += sz / 2) {
        for (int xx = x; xx <= x + sz / 2; xx += sz / 2, i++) {
            if (i != sm % 4) {
                res += f(yy, xx, sz / 2);
            }
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        int sz = input();
        RANGE(y, 1, sz) {
            RANGE(x, 1, sz) {
                csum[y][x] = (
                    get_sum(1, 1, y - 1, x)
                    + get_sum(1, 1, y, x - 1)
                    - get_sum(1, 1, y - 1, x - 1)
                    + input<char>() - '0'
                );
            }
        }
        print(f(1, 1, sz));
    }
}