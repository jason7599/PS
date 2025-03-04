#include <bits/stdc++.h>

using namespace std;

struct Node {
    char color;
    vector<int> adj;
};

Node tree[100'001];

int count_paths(int node_idx) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_nodes;
    cin >> n_nodes;

    for (int i = 0; i < n_nodes - 1; i++) {
        int node0, node1;
        cin >> node0 >> node1;
        tree[node0].adj.push_back(node1);
        tree[node1].adj.push_back(node0);
    }

    for (int i = 1; i <= n_nodes; i++) {
        cin >> tree[i].color;
    }

}