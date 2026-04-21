#include <bits/stdc++.h>

using namespace std;

const int MAX_N_NODES = 100'000;

char colors[MAX_N_NODES + 1];
int roots[MAX_N_NODES + 1];
int sizes[MAX_N_NODES + 1];

int find_root(int node) {
    int& parent = roots[node];
    if (parent != node) {
        parent = find_root(parent);
    }
    return parent;
}

void make_union(int node0, int node1) {
    int root0 = find_root(node0);
    int root1 = find_root(node1);

    if (root0 != root1) {
        int a = min(root0, root1);
        int b = max(root0, root1);

        roots[b] = a;
        sizes[a] += sizes[b];
        sizes[b] = sizes[a];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_nodes;
    cin >> n_nodes;

    list<pair<int, int>> edges(n_nodes - 1);
    for (auto& [i, j] : edges) {
        cin >> i >> j;
    }

    for (int i = 1; i <= n_nodes; i++) {
        cin >> colors[i];
        roots[i] = i;
        sizes[i] = 1;
    }

    for (auto it = edges.begin(); it != edges.end();) {
        const auto& [i, j] = *it;

        if (colors[i] == colors[j]) {
            if (colors[i] == 'R') {
                make_union(i, j);
            }
            it = edges.erase(it); // don't care about black - black edges
        } else {
            it++;
        }
    }

    int64_t ans = 0;
    for (const auto& [i, j] : edges) {
        ans += sizes[find_root(colors[i] == 'R' ? i : j)];
    }

    cout << ans << '\n';
}