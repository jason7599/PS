#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<pii> edges[100'001];
int max_weights[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    int src, dst;
    cin >> src >> dst;

    while (n_edges--) {
        int n0, n1, w;
        cin >> n0 >> n1 >> w;
        edges[n0].push_back({n1, w});
        edges[n1].push_back({n0, w});
    }

    priority_queue<pii> pq;
    pq.push({INT_MAX, src});
    max_weights[src] = INT_MAX;

    while (pq.size()) {
        const auto [cur_weight, cur_node] = pq.top();
        pq.pop();

        if (max_weights[cur_node] > cur_weight) {
            continue;
        }

        if (cur_node == dst) {
            break;
        }

        for (const auto& [next, weight] : edges[cur_node]) {
            int next_weight = min(cur_weight, weight);
            if (next_weight > max_weights[next]) {
                max_weights[next] = next_weight;
                pq.push({next_weight, next});
            }
        }
    }

    cout << max_weights[dst] << '\n';
}