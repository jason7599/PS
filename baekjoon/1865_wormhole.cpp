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

int n_nodes, n_edges;
int dmap[501];
pair<pii, int> edges[5200];

bool has_cycle() {
    FOR(iter, n_nodes) {
        FOR(e, n_edges) {
            const auto [a, b] = edges[e].fi;
            int d = edges[e].se;

            if (dmap[b] > dmap[a] + d) {
                if (iter == n_nodes - 1) {
                    return 1;
                }
                dmap[b] = dmap[a] + d;
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        input(n_nodes);
        fill(&dmap[2], &dmap[1 + n_nodes], 1e9);
        dmap[1] = 0;

        auto [n_p, n_n] = inputs<int, int>();
        n_edges = n_p * 2 + n_n;
        FOR(i, n_p + n_n) {
            auto [a, b, d] = inputs<int, int, int>();
            if (i < n_p) {
                edges[i] = {{a, b}, d};
                edges[n_p + n_n + i] = {{b, a}, d};
            } else {
                edges[i] = {{a, b}, -d};
            }
        }

        print(has_cycle() ? "YES" : "NO");
    }
}