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

int arr[30'001];
vector<int> edges[30'001];
bool vis[30'001];
pii groups[30'000];
int dp[3'001];

// @return {size, sum}
pii dfs(int i) {
    vis[i] = 1;

    int sz = 1;
    int sm = arr[i];

    for (int nx : edges[i]) {
        if (!vis[nx]) {
            auto [nsz, nsm] = dfs(nx);
            sz += nsz;
            sm += nsm;
        }
    }

    return {sz, sm};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [n, m, k] = inputs<int, int, int>();

    RANGE(i, 1, n) {
        input(arr[i]);
    }

    REP(m) {
        auto [a, b] = inputs<int, int>();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int n_groups = 0;
    RANGE(i, 1, n) {
        if (!vis[i]) {
            groups[n_groups++] = dfs(i);
        }
    }

    // 1D array solution for the knapsack problem
    // Outer loop for each item (weight, value pair)
    // This ensures we don't use duplicate items.
    FOR(i, n_groups) {
        // Decreasing starting from the max capacity, down to the item's weight
        // In this case we exclude sz = groups[i].fi since we are not allowed to
        // reach K as the capacity, as is defined by the problem 
        for (int sz = k; sz > groups[i].fi; sz--) {
            upmax(dp[sz], dp[sz - groups[i].fi] + groups[i].se);
        }
    }

    print(dp[k]);
}