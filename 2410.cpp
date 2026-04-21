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
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MOD = 1e9;

int dp[1'000'001][20];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n = input();

    dp[0][0] = 1;
    RANGE(i, 1, n) {
        for (int p = 0; (1 << p) <= i; p++) {
            FOR(j, p + 1) {
                dp[i][p] = (dp[i][p] + dp[i - (1 << p)][j]) % MOD;
            }
        }
    }

    int ans = 0;
    FOR(i, 20) {
        ans = (ans + dp[n][i]) % MOD;
    }

    print(ans);
}