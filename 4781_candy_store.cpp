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
pii arr[5000]; // <cal, price * 100>
int dp[5000][EE(4) + 1];

int f(int i, int k) {
    if (i == n || k < arr[i].se) {
        return 0;
    }

    int& res = dp[i][k];
    if (res != -1) {
        return res;
    }

    for (int t = 0; t * arr[i].se <= k; t++) {
        upmax(res, t * arr[i].fi + f(i + 1, k - t * arr[i].fi));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while (input(n)) {
        int k = input<float>() * 100;

        FOR(i, n) {
            auto [c, p] = inputs<int, float>();
            arr[i] = {c, p * 100};
            fill(&dp[i][0], &dp[i][1 + k], -1);
        }

        sort(arr, arr + n, [](pii& lhs, pii& rhs) {
            return lhs.se < rhs.se;
        });

        print(f(0, k));
    }
}