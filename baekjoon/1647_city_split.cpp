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

int n_nodes, roots[100'001];
pair<int, pii> edges[1'000'000];

int find_root(int n) {
    if (roots[n] != n) {
        roots[n] = find_root(roots[n]);
    }
    return roots[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    iota(roots + 1, roots + 1 + n_nodes, 1);

    int n_edges = input();
    FOR(i, n_edges) {
        auto [a, b, w] = inputs<int, int, int>();
        edges[i] = {w, {a, b}};
    }

    sort(edges, edges + n_edges, [](auto& lhs, auto& rhs) {
        return lhs.fi < rhs.fi;
    });

    int total_cost = 0;
    int last_cost = 0;
    for (int i = 0, t = 0; t < n_nodes - 1; i++) {
        assert(i < n_edges);

        int cost = edges[i].fi;
        auto [a, b] = edges[i].se;

        a = find_root(a);
        b = find_root(b);

        if (a != b) {
            roots[max(a, b)] = min(a, b);
            total_cost += cost;
            last_cost = cost;
            t++;
        }
    }

    print(total_cost - last_cost);
}