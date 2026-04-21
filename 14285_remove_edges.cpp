#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_nodes;
vector<pii> adjmap[5001];
pii edges[100'000];
int dmap[2][5001];

void dijkstra(int start, bool b) {
    fill(&dmap[b][1], &dmap[b][1 + n_nodes], INT_MAX);
    dmap[b][start] = 0;

    priority_queue<pii> pq;
    pq.push({0, start});

    while (pq.size()) {
        int c_cost = -pq.top().fi;
        int c_node = pq.top().se;
        pq.pop();

        if (dmap[b][c_node] < c_cost) {
            continue;
        }

        for (const auto& [nxt, cost] : adjmap[c_node]) {
            int nxt_cost = c_cost + cost;
            if (nxt_cost < dmap[b][nxt]) {
                dmap[b][nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_edges;
    input(n_nodes, n_edges);

    int cost_sum = 0;
    FOR(i, n_edges) {
        int a, b, c;
        input(a, b, c);
        adjmap[a].push_back({b, c});
        adjmap[b].push_back({a, c});
        edges[i] = {a, b};
        cost_sum += c;
    }

    FOR(i, 2) dijkstra(input(), i);

    int mn = INT_MAX;
    FOR(i, n_edges) {
        const auto& [a, b] = edges[i];
        // shortest path WITHOUT including the cost of edge [a, b]
        upmin(mn, min(dmap[0][a] + dmap[1][b], dmap[0][b] + dmap[1][a]));
    }

    print(cost_sum - mn);
}