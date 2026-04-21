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

int dp[4000][4000];

int f(string& a, string& b, int ai, int bi) {
    if (ai >= a.length() || bi >= b.length()) {
        return 0;
    }

    int& res = dp[ai][bi];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (; ai < a.length() && bi < b.length() && a[ai] == b[bi]; ai++, bi++) {
        res++;
    }

    return upmax(res, max(f(a, b, ai + 1, bi), f(a, b, ai, bi + 1)));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [a, b] = inputs<string, string>();
    FOR(i, a.length()) {
        fill(&dp[i][0], &dp[i][b.length()], -1);
    }

    print(f(a, b, 0, 0));
}