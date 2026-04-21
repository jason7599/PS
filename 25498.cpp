#include <bits/stdc++.h>
using namespace std;

const int MAX_N_NODES = 500'000;

int n_nodes;
char nodes[MAX_N_NODES + 1];
vector<int> edges[MAX_N_NODES + 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_nodes;
    for (int i = 1; i <= n_nodes; i++) {
        cin >> nodes[i];
    }

    for (int i = 0; i < n_nodes - 1; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
}