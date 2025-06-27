#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> edges[51];
int dmap[51][1001];

int solve(int dest, int n_power_uses) {
    priority_queue<pair<int, pii>> pq; // <-cost, <cur_node, n_powers>>
    dmap[1][n_power_uses] = 0;
    pq.push({0, {1, n_power_uses}});

    int ans = INT_MAX;

    while (!pq.empty()) {
        int cur_cost = -pq.top().first;
        const auto [cur_node, cur_n_powers] = pq.top().second;
        pq.pop();
        
        if (dmap[cur_node][cur_n_powers] < cur_cost) {
            continue;
        }

        if (cur_node == dest) {
            ans = min(ans, cur_cost);
        }

        for (const auto& [nx_node, cost] : edges[cur_node]) {
            if (cur_n_powers && cost && dmap[nx_node][cur_n_powers - 1] > cur_cost - cost) {
                dmap[nx_node][cur_n_powers - 1] = cur_cost - cost;
                pq.push({cost - cur_cost, {nx_node, cur_n_powers - 1}});
            }

            int nx_cost = cur_cost + cost;
            if (dmap[nx_node][cur_n_powers] > nx_cost) {
                dmap[nx_node][cur_n_powers] = nx_cost;
                pq.push({-nx_cost, {nx_node, cur_n_powers}});
            }
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes, n_edges, n_power_uses;
    cin >> n_nodes >> n_edges >> n_power_uses;

    for (int i = 1; i <= n_nodes; i++) {
        fill(&dmap[i][0], &dmap[i][1 + n_power_uses], INT_MAX);
    }

    while (n_edges--) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    cout << solve(n_nodes, n_power_uses) << '\n';
}