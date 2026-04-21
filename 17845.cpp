#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
#define LF cout << '\n'
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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
pii arr[1000]; // <time, score>
int dp[1000][10'001];

int f(int i, int k) {
    if (i == n || k < arr[i].fi) {
        return 0;
    }

    int& res = dp[i][k];
    if (res != -1) {
        return res;
    }

    return res = max(f(i + 1, k), arr[i].se + f(i + 1, k - arr[i].fi));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int k = input();
    FOR(i, input(n)) {
        input(arr[i].se, arr[i].fi);
        fill(&dp[i][0], &dp[i][k + 1], -1);
    }

    sort(arr, arr + n);

    print(f(0, k));
}