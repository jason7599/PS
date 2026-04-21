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

int n_nodes, edges[101][101];
int prevs[101], dmap[101];

int dijkstra(int start) {
    fill(&dmap[1], &dmap[1 + n_nodes], INT_MAX);
    priority_queue<pii> pq;
    pq.push({0, start});
    dmap[start] = 0;

    while (pq.size()) {
        int c_dist = -pq.top().first;
        int c_node = pq.top().second;
        pq.pop();

        if (dmap[c_node] < c_dist) {
            continue;
        }

        RANGE(nx_node, 1, n_nodes) {
            if (edges[c_node][nx_node]) {
                int nx_dist = c_dist + edges[c_node][nx_node];
                if (nx_dist < dmap[nx_node]) {
                    dmap[nx_node] = nx_dist;
                    prevs[nx_node] = c_node;
                    pq.push({-nx_dist, nx_node});
                }
            }
        }
    }

    return dmap[n_nodes];
}

void backtrack(int node, stack<pii>& res) {
    int prev = prevs[node];
    res.push({prev, node});
    if (prev != 1) {
        backtrack(prev, res);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    REP(input()) {
        int a, b, l;
        input(a, b, l);
        edges[a][b] = l;
        edges[b][a] = l;
    }

    if (n_nodes == 1) {
        print(0);
        return 0;
    }

    int og_cost = dijkstra(1);

    stack<pii> path;
    backtrack(n_nodes, path);

    int ans = 0;
    for (; path.size(); path.pop()) {
        const auto [from, to] = path.top();

        edges[from][to] *= 2, edges[to][from] *= 2;

        int new_cost = dijkstra(1);
        ans = max(ans, new_cost - og_cost);

        edges[from][to] /= 2, edges[to][from] /= 2;
    }
    print(ans);
}