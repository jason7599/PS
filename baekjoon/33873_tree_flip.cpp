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

int n_nodes;
int vals[100'001][2];
vector<int> edges[100'001];
pii dp[100'001][2];

pii f(int node, int parent, bool flipped) {
    if (dp[node][flipped].fi != INT_MIN) {
        return dp[node][flipped];
    }

    if (vals[node][0] != vals[node][1]) {
        bool should_flip = (vals[node][0] < vals[node][1]) ^ flipped;

        int score_sum = max(vals[node][0], vals[node][1]);
        int n_flips = should_flip;
        for (int nxt : edges[node]) {
            if (nxt == parent) {
                continue;
            }
            auto [a, b] = f(nxt, node, should_flip ^ flipped);
            score_sum += a;
            n_flips += b;
        }

        return dp[node][flipped] = {score_sum, n_flips};
    }

    // vals[node][0] == vals[node][1]....
    pii res[2]{}; // [0]: no_flip, [1]: flip
    res[0].fi = res[1].fi = vals[node][0];
    for (int nxt : edges[node]) {
        if (nxt == parent) {
            continue;
        }
        FOR(i, 2) {
            auto [a, b] = f(nxt, node, i);
            res[i].fi += a;
            res[i].se += b;
        }
    }
    res[!flipped].se += 1;

    assert(res[0].fi == res[1].fi);

    return dp[node][flipped] = {res[0].fi, min(res[0].se, res[1].se)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    FOR(i, 2) {
        RANGE(j, 1, n_nodes) {
            input(vals[j][i]);
            dp[j][i].fi = INT_MIN;
        }
    }

    REP(n_nodes - 1) {
        auto [a, b] = inputs<int, int>();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    auto [a, b] = f(1, 0, 0);
    print(a, b);
}