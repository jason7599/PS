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

string p, s[2];
int dp[100][20][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(p, s[0], s[1]);
    const int n = s[0].length();

    FOR(i, 2) {
        dp[0][0][i] = s[i].front() == p.front();
    }

    RANGE(pi, 1, p.length() - 1) {
        RANGE(i, 1, n - 1) {
            FOR(si, 2) {
                dp[i][pi][si] += dp[i - 1][pi][si];
                if (s[si][i] == p[pi]) {
                    dp[i][pi][si] += dp[i - 1][pi - 1][!si];
                }
            }
        }
    }
}