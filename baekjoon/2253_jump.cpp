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

int n;
bool banned[10'001];
int dp[10'001][150];

int f(int i, int j) {
    if (i == n) {
        return 0;
    }

    if (banned[i]) {
        return -1;
    }

    int& res = dp[i][j];
    if (res) {
        return res;
    }

    res = INT_MAX;
    RANGE(nj, max(j - 1, 1), min(j + 1, n - i)) {
        int t = f(i + nj, nj);
        if (t != -1) {
            upmin(res, 1 + t);
        }
    }

    if (res == INT_MAX) {
        res = -1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    REP(input()) {
        banned[input()] = 1;
    }

    int t = f(2, 1);
    if (t != -1) {
        t++;
    }
    print(t);
}