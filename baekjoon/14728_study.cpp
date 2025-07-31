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
pii arr[100];
int dp[100][10'001];

int f(int i, int t) {
    if (i == n || arr[i].fi > t) {
        return 0;
    }

    int& res = dp[i][t];
    if (res != -1) {
        return res;
    }

    res = max(
        f(i + 1, t),
        arr[i].se + f(i + 1, t - arr[i].fi)
    );

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    input(n, t);
    FOR(i, n) {
        input(arr[i].fi, arr[i].se);
        fill(&dp[i][0], &dp[i][1 + t], -1);
    }
    sort(arr, arr + n);

    print(f(0, t));
}