#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n_nodes;
vector<pii> edges[1001];
int dmap[1001]; // dist from dest(= 2)
int dp[1001];

void dijkstra() {
    fill(&dmap[1], &dmap[1 + n_nodes], INT_MAX);
    
    priority_queue<pii> pq;
    pq.push({0, 2});
    dmap[2] = 0;
    
    for (; pq.size(); pq.pop()) {
        int cur_d = -pq.top().first;
        int cur_n = pq.top().second;

        if (dmap[cur_n] < cur_d) {
            continue;
        }

        for (const auto& [n, d] : edges[cur_n]) {
            int nx_d = cur_d + d;
            if (dmap[n] > nx_d) {
                dmap[n] = nx_d;
                pq.push({-nx_d, n});
            }
        }
    }
}

int f(int n) {
    if (n == 2) {
        return 1;
    }

    int& res = dp[n];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (const auto& [nx, d] : edges[n]) {
        if (dmap[n] > dmap[nx]) {
            res += f(nx);
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_edges;
    input(n_nodes, n_edges);

    REP(n_edges) {
        int n0, n1, dist;
        input(n0, n1, dist);
        edges[n0].push_back({n1, dist});
        edges[n1].push_back({n0, dist});
    }

    dijkstra();

    fill(&dp[1], &dp[1 + n_nodes], -1);

    print(f(1));
}