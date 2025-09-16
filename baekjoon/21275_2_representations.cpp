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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int getv(char c) {
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

ll toll(string& s, int b) {
    ll res = 0;
    for (char c : s) {
        res = (res + getv(c)) * b;
    }
    return res;
}

ll fs[2][37];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [a, b] = inputs<string, 2>();

    int ad = 0;
    int bd = 0;
    for (char c : a) {
        upmax(ad, getv(c) + 1);
    }
    for (char c : b) {
        upmax(bd, getv(c) + 1);
    }

    FOR(i, 2) {
        RANGE(j, i ? bd : ad, 36) {
            fs[i][j] = toll(i ? b : a, j);
        }
    }

    ll ans = -1;
    pii ans_p;
    RANGE(ai, ad, 36) {
        RANGE(bi, bd, 36) {
            if (fs[0][ai] == fs[1][bi]) {
                if (ans == -1) {
                    ans = fs[0][ai];
                    ans_p = {ai, bi};
                }
            } else {
                print("Multiple");
                exit(0);
            }
        }
    }

    if (ans != -1) {
        print(ans, ans_p.fi, ans_p.se);
    } else {
        print("Impossible");
    }
}