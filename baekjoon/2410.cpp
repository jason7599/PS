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
template<typename T = int> T input() { T x; cin >> x; return x; }
template<typename T> T input(T& x) { cin >> x; return x; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> x; apply([](auto&... args){input(args...);}, x); return x; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MOD = 1e9;

int dp[1'000'001][20];

int f(int n, int b = 0) {
    if (!n) {
        return 1;
    }

    int bv = 1 << b;
    if (bv > n) {
        return -1;
    }

    int& res = dp[n][b];
    if (res) {
        return res;
    }

    res = f(n - bv, b);
    int t = f(n - bv, b + 1);
    if (t != -1) {
        res = (res + t) % MOD;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    print(f(input()));
}