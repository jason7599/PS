#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_node, n_free;
vector<pii> edges[1001]; // to, cost

bool check(int max_cost) {
    priority_queue<pii> pq; // <n_free, node>
    vector<int> d(n_node + 1, -1);

    pq.push({n_free, 1});
    d[1] = n_free;

    while (!pq.empty()) {
        const auto [nf, node] = pq.top();
        pq.pop();

        if (d[node] > nf) {
            continue;
        }

        for (const auto& [nx_node, cost] : edges[node]) {
            int nx_free = nf - (cost > max_cost);
            if (nx_free < 0) {
                continue;
            }

            if (nx_node == n_node) {
                return 1;
            }

            if (d[nx_node] < nx_free) {
                d[nx_node] = nx_free;
                pq.push({nx_free, nx_node});
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edge;
    cin >> n_node >> n_edge >> n_free;

    int max_cost = 0;
    while (n_edge--) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        edges[node1].push_back({node2, cost});
        edges[node2].push_back({node1, cost});
        max_cost = max(max_cost, cost);
    }

    int ans = -1;
    for (int l = 0, r = max_cost; l <= r;) {
        int m = (l + r) >> 1;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}
