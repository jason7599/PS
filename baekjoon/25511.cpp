#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<int> edges;
};

Node tree[100'000];

int find_depth(int val, int idx = 0, int prev = -1) {
    Node& node = tree[idx];
    if (node.val == val) {
        return 0;
    }

    for (int next : node.edges) {
        if (next == prev) {
            continue;
        }
        int t = find_depth(val, next, idx);
        if (t != -1) {
            return 1 + t;
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes, k;
    cin >> n_nodes >> k;

    for (int i = 0; i < n_nodes - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].edges.push_back(n2);
        tree[n2].edges.push_back(n1);
    }

    for (int i = 0; i < n_nodes; i++) {
        cin >> tree[i].val;
    }

    cout << find_depth(k) << '\n';
}
