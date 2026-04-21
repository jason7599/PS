#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes;
vector<pii> edges[500];
int dmap[500];
vector<int> prevs[500];

bool banned_edges[500][500];

int dijkstra(int start, int dest, bool ban) {
    fill(&dmap[0], &dmap[n_nodes], INT_MAX);
    dmap[start] = 0;

    priority_queue<pii> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_dist > dmap[cur_node]) {
            continue;
        }

        if (cur_node == dest) {
            return cur_dist;
        }

        for (const auto& [nx_node, dist] : edges[cur_node]) {
            if (ban && banned_edges[cur_node][nx_node]) {
                continue;
            }
            int nx_dist = cur_dist + dist;
            if (nx_dist < dmap[nx_node]) {
                dmap[nx_node] = nx_dist;
                if (!ban) {
                    prevs[nx_node].clear();
                    prevs[nx_node].push_back(cur_node);
                }
                pq.push({-nx_dist, nx_node});
            } else if (!ban && nx_dist == dmap[nx_node]) {
                prevs[nx_node].push_back(cur_node);
            }
        }
    }

    return -1;
}

void ban_edges(int start, int dest) {
    if (dest == start) {
        return;
    }
    for (int p : prevs[dest]) {
        if (!banned_edges[p][dest]) {
            banned_edges[p][dest] = 1;
            ban_edges(start, p);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (;;) {
        int n_edges;
        cin >> n_nodes >> n_edges;
        if (!n_nodes) {
            break;
        }

        for (int i = 0; i < n_nodes; i++) {
            edges[i].clear();
        }

        int start, dest;
        cin >> start >> dest;

        while (n_edges--) {
            int from, to, dist;
            cin >> from >> to >> dist;
            edges[from].push_back({to, dist});
            banned_edges[from][to] = 0;
        }
            
        if (dijkstra(start, dest, 0) == -1) {
            cout << -1 << '\n';
            continue;
        }

        ban_edges(start, dest);

        cout << dijkstra(start, dest, 1) << '\n';
    }
}