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

int get_val(char c) {
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

ll interpret(string& str, int base) {
    ll res = 0;
    for (char c : str) {
        res = res * base + get_val(c);
        if (res < 0) {
            return -1;
        }
    }
    return res;
}

string strs[2];
int base_mns[2];
ll vals[2][37];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(strs[0], strs[1]);

    FOR(i, 2) {
        for (char c : strs[i]) {
            upmax(base_mns[i], 1 + get_val(c));
        }
    }

    FOR(i, 2) {
        RANGE(j, base_mns[i], 36) {
            vals[i][j] = interpret(strs[i], j);
        }
    }

    ll ans = -1;
    pii ans_p;
    RANGE(i, base_mns[0], 36) {
        if (vals[0][i] == -1) {
            continue;
        }
        RANGE(j, base_mns[1], 36) {
            if (i == j) {
                continue;
            }
            if (vals[0][i] == vals[1][j]) {
                if (ans == -1) {
                    ans = vals[0][i];
                    ans_p = {i, j};
                } else {
                    print("Multiple");
                    exit(0);
                }
            }
        }
    }

    if (ans == -1) {
        print("Impossible");
    } else {
        print(ans, ans_p.fi, ans_p.se);
    }
}