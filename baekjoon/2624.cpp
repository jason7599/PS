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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF}
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_coins;
pii coins[100]; // <val, cnt>

int dp[100][10'001];

int f(int i, int targ) {
    if (!targ) {
        return 1;
    }

    if (i == n_coins || coins[i].fi > targ) {
        return 0;
    }

    int& res = dp[i][targ];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int j = 0; j <= coins[i].se && coins[i].fi * j <= targ; j++) {
        res += f(i + 1, targ - coins[i].fi * j);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int targ = input();
    FOR(i, input(n_coins)) {
        input(coins[i].fi, coins[i].se);
        fill(&dp[i][0], &dp[i][targ + 1], -1);
    }

    sort(coins, coins + n_coins);

    print(f(0, targ));
}