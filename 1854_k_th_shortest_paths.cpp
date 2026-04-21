#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes, k;
vector<pii> edges[1001];
int cnt[1001], ans[1001];

void f() {
    priority_queue<pii> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (++cnt[cur_node] == k) {
            ans[cur_node] = cur_cost;
        } else if (cnt[cur_node] > k) {
            continue;
        }

        for (const auto& [nx_node, cost] : edges[cur_node]) {
            int nx_cost = cur_cost + cost;
            pq.push({-nx_cost, nx_node});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges;
    cin >> n_nodes >> n_edges >> k;

    fill(&ans[1], &ans[1 + n_nodes], -1);

    while (n_edges--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back({to, dist});
    }

    f();

    for (int n = 1; n <= n_nodes; n++) {
        cout << ans[n] << '\n';
    }
}