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

int n;
pii arr[20]; // <cost, delt>
int dp[20][1001];

int f(int i, int v) {
    int& res = dp[i][v];
    if (res) {
        return res;
    }
    
    res = arr[i].fi * ((v + arr[i].se - 1) / arr[i].se);
    if (i == n - 1) {
        return res;
    }

    for (int t = 0; arr[i].se * t < v; t++) {
        upmin(res, arr[i].fi * t + f(i + 1, v - arr[i].se * t));
    }
    
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int v = input();
    FOR(i, input(n)) {
        input(arr[i].fi, arr[i].se);
    }
    print(f(0, v));
}