#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

uint n_wires, wires[10'000];

bool f(int len, int n_req) {
    FOR(i, n_wires) {
        n_req -= wires[i] / len;
        if (n_req <= 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_req;
    input(n_wires, n_req);

    uint mx = 0;
    FOR(i, n_wires) {
        input(wires[i]);
        upmax(mx, wires[i]);
    }

    uint ans;
    for (uint l = 1, r = mx; l <= r;) {
        int m = (l + r) >> 1;
        if (f(m, n_req)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    print(ans);
}