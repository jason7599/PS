#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int roots[100'001];

int find_root(int n) {
    if (roots[n] != n) {
        roots[n] = find_root(roots[n]);
    }
    return roots[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_nodes, n_edges, end_time] = inputs<int, 3>();

    iota(roots + 1, roots + 1 + n_nodes, 1);

    vector<pair<int, pii>> edges(n_edges);

    for (auto& edge : edges) {
        input(edge.se.fi, edge.se.se, edge.fi);
    }
    sort(edges.begin(), edges.end());

    long res = 0;
    int prv_time = 1;
    int n_comps = n_nodes;

    for (auto edge : edges) {
        int time = edge.fi;
        auto [a, b] = edge.se;

        res += (long)n_comps * (time - prv_time);

        a = find_root(a);
        b = find_root(b);
        if (a != b) {
            n_comps--;
            roots[min(a, b)] = max(a, b);
        }

        prv_time = time;
    }

    res += (long)n_comps * (end_time + 1 - prv_time);

    print(res);
}