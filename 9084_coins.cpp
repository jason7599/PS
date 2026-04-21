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
template<typename T> bool upmax(T& v, const T& other) { if (v >= other) return 0; v = other; return 1; }
template<typename T> bool upmin(T& v, const T& other) { if (v <= other) return 0; v = other; return 1; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_coins, coin_vals[20];
int dp[20][10'001];

int f(int idx, int targ) {
    if (!targ) {
        return 1;
    }
    if (idx == n_coins || targ < coin_vals[idx]) {
        return 0;
    }
    int& res = dp[idx][targ];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (; targ >= 0; targ -= coin_vals[idx]) {
        res += f(idx + 1, targ);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        FOR(i, input(n_coins)) {
            input(coin_vals[i]);
        }
        int targ = input();
        FOR(i, n_coins) {
            fill(&dp[i][1], &dp[i][1 + targ], -1);
        }
        print(f(0, targ));
    }
}