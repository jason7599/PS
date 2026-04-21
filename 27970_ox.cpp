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

const int MOD = 1e9 + 7;

int dp[100'001];

int f(int x) {
    if (!x) {
        return 1;
    }

    int& res = dp[x];
    if (res != -1) {
        return res;
    }

    res = 1;
    FOR(i, x) {
        res = (res + f(i)) % MOD;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    input(s);

    fill(&dp[1], &dp[s.length()], -1);

    int ans = 0;
    FOR(i, s.length()) {
        if (s[i] == 'O') {
            ans = (ans + f(i)) % MOD;
        }
    }

    print(ans);
}