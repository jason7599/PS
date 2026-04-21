#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> edges[10'001];
int dmap[10'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_node, n_edge;
    cin >> n_node >> n_edge;

    while (n_edge--) {
        int n1, n2, limit;
        cin >> n1 >> n2 >> limit;
        edges[n1].push_back({n2, limit});
        edges[n2].push_back({n1, limit});
    }

    int src, dst;
    cin >> src >> dst;

    dmap[src] = INT_MAX;

    priority_queue<pii> pq;
    pq.push({INT_MAX, src});

    while (!pq.empty()) {
        const auto [cur_limit, cur_node] = pq.top();
        pq.pop();

        if (dmap[cur_node] > cur_limit) {
            continue;
        }


        if (cur_node == dst) {
            break;
        }

        for (const auto& [nxt, limit] : edges[cur_node]) {
            int nxt_limit = min(cur_limit, limit);
            if (nxt_limit > dmap[nxt]) {
                dmap[nxt] = nxt_limit;
                pq.push({nxt_limit, nxt});
            }
        }
    }

    cout << dmap[dst] << '\n';
}
