#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> void input(T& t) { cin >> t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n;
string p, s[2];

int dp[100][20][2];

int f(bool si, int i, int pi) {
    if (pi == p.length()) {
        return 1;
    }

    int& res = dp[i][pi][si];
    if(res != -1) {
        return res;
    }

    res = 0;
    for (; n - i >= p.length() - pi; i++) {
        if (s[si][i] == p[pi]) {
            res += f(!si, i + 1, pi + 1);
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(p, s[0], s[1]);
    n = s[0].length();

    FOR(i, n) {
        fill(&dp[i][0][0], &dp[i][p.length()][0], - 1);
    }

    print(f(0, 0, 0) + f(1, 0, 0));
}