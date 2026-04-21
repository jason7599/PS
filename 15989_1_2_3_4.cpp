#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

ll dp[10'001][4];

ll f(int n, int b = 1) {
    if (!n) {
        return 1;
    }

    ll& res = dp[n][b];
    if (res != -1) {
        return res;
    }

    res = 0;
    RANGE(i, b, min(n, 3)) {
        res += f(n - i, i);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(dp, -1, sizeof dp);
    
    int n_tc;
    input(n_tc);
    REP(n_tc) {
        print(f(input<int>()));
    }
}