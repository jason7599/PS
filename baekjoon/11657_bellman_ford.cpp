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
ll dmap[501];
pair<pii, int> edges[6000];

bool bellman_ford() {
    // "Relaxation": As done in Dijkstra, for an edge, update the shortest distance.
    // Repeat the relaxtion process V - 1 times.
    // A simple shortest path can have at most V - 1 edges, as otherwise it would form a cycle.
    //
    // Then, go over one more iteration of relaxation.
    // If there is one additional relaxation found here, it indicates that some negative edges have been traversed once more.
    // This indicates a negative weight cycle in the graph.
    FOR(iter, n_nodes) {
        FOR(e, n_edges) {
            auto [a, b] = edges[e].fi;
            int d = edges[e].se;

            // relaxation
            if (dmap[a] != INT64_MAX && dmap[b] > dmap[a] + d) {
                if (iter == n_nodes - 1) {
                    return 0;
                }
                dmap[b] = dmap[a] + d;
            }
        }
    }

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(n_nodes, n_edges);
    fill(&dmap[2], &dmap[1 + n_nodes], INT64_MAX);
    FOR(i, n_edges) {
        edges[i] = {{input(), input()}, input()};
    }

    if (bellman_ford()) {
        RANGE(i, 2, n_nodes) {
            print(dmap[i] == INT64_MAX ? -1 : dmap[i]);
        }
    } else {
        print(-1);
    }
}