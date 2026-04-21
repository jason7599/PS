#include <bits/stdc++.h>
#define FOR(i, n) for ( i = 0, _n = n; i < _n; i++)
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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool broke[10];

int f(int n) {
    if (!n) {
        return broke[0] ? -1 : 1;
    }
    int len = 0;
    for (; n; n /= 10, len++) {
        if (broke[n % 10]) {
            return -1;
        }
    }
    return len;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int dst = input();
    int n_broke = input();
    REP(n_broke) {
        broke[input()] = 1;
    }

    int mn = abs(dst - 100);
    if (n_broke == 10) {
    } else if (n_broke == 9 && !broke[0]) {
        upmin(mn, 1 + dst);
    } else {
        for (int i = 0;; i++) {
            int l = f(i);
            if (l != -1) {
                upmin(mn, l + abs(dst - i));
                if (dst <= i) {
                    break;
                }
            }
        }
    }
    print(mn);
}