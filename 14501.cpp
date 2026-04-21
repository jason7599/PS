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
template<typename T> bool upmax(T& v, const T& other) { if (v >= other) return 0; v = other; return 1; }
template<typename T> bool upmin(T& v, const T& other) { if (v <= other) return 0; v = other; return 1; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
pii arr[15]; // <time, profit>
int dp[15];

int f(int i) {
    if (i == n) {
        return 0;
    }

    int& res = dp[i];
    if (res != -1) {
        return res;
    }

    // no reason to skip if it takes one day
    if (arr[i].fi != 1) {
        res = f(i + 1); 
    }

    if (i + arr[i].fi <= n) {
        upmax(res, arr[i].se + f(i + arr[i].fi));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input(arr[i].fi, arr[i].se);
        dp[i] = -1;
    }

    print(f(0));
}