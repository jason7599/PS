#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n_nodes;
vector<pii> edges[3001];
int dmap[3001];

void f() {
    fill(&dmap[1], &dmap[1 + n_nodes], INT_MAX);
    priority_queue<pii> pq;
    pq.push({0, 0});

    while (pq.size()) {
        int c_cost = -pq.top().fi;
        int c_node = pq.top().se;
        pq.pop();

        // print("cur cost of", c_node, "is", c_cost);
        if (c_cost > dmap[c_node]) {
            continue;
        }

        for (const auto& [nxt, cost] : edges[c_node]) {
            int nxt_cost = c_cost + cost;
            if (dmap[nxt] > nxt_cost) {
                // print("dmap", nxt, "has been updated to", nxt_cost, "by", c_node);
                dmap[nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges, n_malls;
    input(n_nodes, n_edges, n_malls);

    REP(n_edges) {
        int a, b, l;
        input(a, b, l);
        edges[a].push_back({b, l});
        edges[b].push_back({a, l});
    }

    REP(n_malls) {
        edges[0].push_back({input(), 0});
    }
    
    f();

    int ans = 0;
    RANGE(n, 1, n_nodes) {
        print(n, dmap[n]);
        ans = max(ans, dmap[n]);
        for (const auto& [m, cost] : edges[n]) {
            // ans = max(ans, (cost + 1) / 2 + min(dmap[n], dmap[m]));
        }
    }

    print(ans);
}