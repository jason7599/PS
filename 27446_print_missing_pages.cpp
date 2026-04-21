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
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

bool vis[101];

int n_missing;
int missing_pages[101];

int dp[100];

int f(int i) {
    if (i == n_missing) {
        return 0;
    }

    int& res = dp[i];
    if (res) {
        return res;
    }

    res = 7 + f(i + 1);
    for (int t = 1; i + t < n_missing; t++) {
        upmin(res, 5 + 2 * (missing_pages[i + t] - missing_pages[i] + 1) + f(i + t + 1));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n_pages = input();
    REP(input()) {
        vis[input()] = 1;
    }

    RANGE(i, 1, n_pages) {
        if (!vis[i]) {
            missing_pages[n_missing++] = i;
        }
    }

    print(f(0));
}