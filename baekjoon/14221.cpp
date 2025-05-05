#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<pii> edges[5001];
int dists[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    fill(&dists[1], &dists[n_nodes + 1], INT_MAX);

    while (n_edges--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back({to, dist});
        edges[to].push_back({from, dist});
    }

    int n_candidates, n_stores;
    cin >> n_candidates >> n_stores;

    vector<int> candidates(n_candidates);
    for (int& c : candidates) {
        cin >> c;
    }

    priority_queue<pii> pq;
    while (n_stores--) {
        int store;
        cin >> store;
        dists[store] = 0;
        pq.push({0, store});
    }

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dists[cur] < cur_dist) {
            continue;
        }

        for (const auto& [next, dist] : edges[cur]) {
            int next_dist = cur_dist + dist;
            if (next_dist < dists[next]) {
                dists[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }

    int min_dist = INT_MAX;
    int min_dist_node;

    for (int c : candidates) {
        if (dists[c] > min_dist) {
            continue;
        }
        if (dists[c] < min_dist || c < min_dist_node) {
            min_dist = dists[c];
            min_dist_node = c;
        }
    }

    cout << min_dist_node << '\n';
}