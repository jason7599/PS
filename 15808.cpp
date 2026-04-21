#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int DEST = 1001;

int n_nodes;
int dmap[1002];

vector<pii> edges[1002]; // edges[0]: p, edges[1001]: q

void f() {
    priority_queue<pii> pq; // <score, node>
    pq.push({0, 0});

    while (!pq.empty()) {
        const auto [cur_score, cur_node] = pq.top();
        pq.pop();

        if (dmap[cur_node] > cur_score) {
            continue;
        }
        
        for (const auto& [nx_node, score] : edges[cur_node]) {
            int nx_score = cur_score + score;
            if (dmap[nx_node] < nx_score) {
                dmap[nx_node] = nx_score;
                pq.push({nx_score, nx_node});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_nodes;
    for (int i = 1; i <= n_nodes; i++) {
        dmap[i] = INT_MIN;
        for (int j = 1; j <= n_nodes; j++) {
            int w;
            cin >> w;
            if (w) {
                edges[i].push_back({j, -w});
            }
        }
    }
    dmap[DEST] = INT_MIN;

    int n_ps, n_qs;
    cin >> n_ps >> n_qs;

    while (n_ps--) {
        int x, w;
        cin >> x >> w;
        edges[0].push_back({x, w});
    }

    while (n_qs--) {
        int x, w;
        cin >> x >> w;
        edges[x].push_back({DEST, w});
    }

    f();

    cout << dmap[DEST] << '\n';
}