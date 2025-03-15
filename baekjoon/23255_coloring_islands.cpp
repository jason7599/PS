#include <bits/stdc++.h>

using namespace std;

const int MAX_N_NODES = 1e6;

int node_colors[MAX_N_NODES + 1];
vector<int> edges[MAX_N_NODES + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    while (n_edges--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int node = 1; node <= n_nodes; node++) {
        node_colors[node] = 1;
        sort(edges[node].begin(), edges[node].end());
    }

    for (int node = 1; node <= n_nodes; node++) {
        
    }
}