#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> edges[10'001];
int64_t dmap[21][10'001];

void solve(int dest, int n_revamp) {
    priority_queue<pair<int64_t, pii>> pq; // <-dist, <cur, #revamp>>
    pq.push({0, {1, n_revamp}});
    dmap[n_revamp][1] = 0;

    while (!pq.empty()) {
        int64_t cur_dist = -pq.top().first;
        const auto [cur_node, cur_n_revamp] = pq.top().second;
        pq.pop();

        if (dmap[cur_n_revamp][cur_node] < cur_dist) {
            continue;
        }

        if (cur_node == dest) {
            continue;
        }

        for (const auto& [nx_node, dist] : edges[cur_node]) {
            if (cur_n_revamp) {
                if (dmap[cur_n_revamp - 1][nx_node] > cur_dist) {
                    dmap[cur_n_revamp - 1][nx_node] = cur_dist;
                    pq.push({-cur_dist, {nx_node, cur_n_revamp - 1}});
                }
            }
            int64_t nx_dist = cur_dist + dist;
            if (dmap[cur_n_revamp][nx_node] > nx_dist) {
                dmap[cur_n_revamp][nx_node] = nx_dist;
                pq.push({-nx_dist, {nx_node, cur_n_revamp}});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes, n_edges, n_revamp;
    cin >> n_nodes >> n_edges >> n_revamp;

    for (int i = 0; i <= n_revamp; i++) {
        fill(&dmap[i][1], &dmap[i][n_nodes + 1], INT64_MAX);
    }

    while (n_edges--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back({to, dist});
        edges[to].push_back({from, dist});
    }

    solve(n_nodes, n_revamp);

    int64_t ans = INT64_MAX;
    for (int i = 0; i <= n_revamp; i++) {
        ans = min(ans, dmap[i][n_nodes]);
    }

    cout << ans << '\n';
}