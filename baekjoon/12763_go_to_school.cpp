#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(n) FOR(i, n)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...);}

int n_nodes;
vector<pair<int, pii>> edges[101]; // <to, <time, cost>>
int dmap[101][10'001]; // dmap[n][t] = min cost to reach node n at time t

int f(int t_limit, int c_limit) {
    priority_queue<pair<pii, int>> pq; // <<-cost, -time>, node>
    pq.push({{0, 0}, 1});
    dmap[1][0] = 0;

    int ans = INT_MAX;

    for(; !pq.empty(); pq.pop()) {
        int cur_cost = -pq.top().first.first;
        int cur_time = -pq.top().first.second;
        int cur_node = pq.top().second;

        if (dmap[cur_node][cur_time] < cur_cost) {
            continue;
        }

        if (cur_node == n_nodes) {
            ans = min(ans, dmap[cur_node][cur_time]);
            continue;
        }

        for (const auto& edge : edges[cur_node]) {
            int nx_time = cur_time + edge.second.first;
            int nx_cost = cur_cost + edge.second.second;
            int nx_node = edge.first;

            if (nx_time > t_limit || nx_cost > c_limit) {
                continue;
            }

            if (dmap[nx_node][nx_time] > nx_cost) {
                dmap[nx_node][nx_time] = nx_cost;
                pq.push({{-nx_cost, -nx_time}, nx_node});
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t_limit, c_limit, n_edges;
    input(n_nodes, t_limit, c_limit, n_edges);

    RANGE(i, 1, n_nodes) {
        fill(&dmap[i][0], &dmap[i][t_limit + 1], INT_MAX);
    }

    REP(n_edges) {
        int n0, n1, t, c;
        input(n0, n1, t, c);
        edges[n0].push_back({n1, {t, c}});
        edges[n1].push_back({n0, {t, c}});
    }

    print(f(t_limit, c_limit));
}