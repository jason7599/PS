#include <bits/stdc++.h>

using namespace std;

int n_nodes;
vector<int> edges[1001];
bool visited[1001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_edges, init_node, n_moves;
    cin >> n_nodes >> n_edges >> init_node >> n_moves;

    while (n_edges--) {
        int node0, node1;
        cin >> node0 >> node1;

        edges[node0].push_back(node1);
        edges[node1].push_back(node0);
    }

    queue<int> q({init_node});

    for (int q_size; (q_size = q.size()) && n_moves; n_moves--) {

        bool nx_visit = (n_moves + 1) % 2;

        while (q_size--) {
            int node = q.front();
            q.pop();
    
            for (int next : edges[node]) {
                if (!visited[next][nx_visit]) {
                    visited[next][nx_visit] = 1;
                    q.push(next);
                }
            }
        }
    }

    bool nothing = 1;
    for (int i = 1; i <= n_nodes; i++) {
        if (visited[i][0]) {
            nothing = 0;
            cout << i << ' ';
        }
    }

    if (nothing)
        cout << -1;

    cout << '\n';
}