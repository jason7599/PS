#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(n) for(int i = n; i > 0; i--)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> void input(T& t) { cin >> t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int dp[101][101];

// str[n - 1] = 0;
int f(int n, int k) {
    if (n < k + 1) {
        return 0;
    }

    if (n == k + 1) {
        return 1;
    }

    int& res = dp[n][k];
    if (res != -1) {
        return res;
    }

    res = 0;
    if (n - 1 >= k + 1) { // can place '0'
        res = f(n - 1, k);
    }

    for (int x = 1; n - x - 1 >= k - x - 1) {
        
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    memset(dp, -1, sizeof dp);

    REP(input()) {
        int n, k;
        input(n, k);
    }
}