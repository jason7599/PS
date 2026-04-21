#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int to;
    int costs[2]; // [cost, time]
};

int n_nodes;
vector<Edge> edges[101];
pii dmap[101][2];

void f(int start, int dest, bool b) {
    priority_queue<pair<int, pii>> pq; // <-costs[b], <-costs[!b], cur_node>> 
    pq.push({0, {0, start}});

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_dist2 = -pq.top().second.first;
        int cur_node = pq.top().second.second;
        pq.pop();

        if (dmap[cur_node][b] < make_pair(cur_dist, cur_dist2)) {
            continue;
        }

        // if (cur_node == dest) {
        //     return;
        // }

        for (const Edge& e : edges[cur_node]) {
            int nx_dist = cur_dist + e.costs[b];
            int nx_dist2 = cur_dist2 + e.costs[!b];
            if (dmap[e.to][b] > make_pair(nx_dist, nx_dist2)) {
                dmap[e.to][b] = {nx_dist, nx_dist2};
                pq.push({-nx_dist, {-nx_dist2, e.to}});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges, start, dest;
    cin >> n_nodes >> n_edges >> start >> dest;

    fill(&dmap[1][0], &dmap[1 + n_nodes][0], make_pair(INT_MAX, INT_MAX));
    dmap[start][0] = dmap[start][1] = {0, 0};

    while (n_edges--) {
        int from, to, cost0, cost1;
        cin >> from >> to >> cost0 >> cost1;
        edges[from].push_back({to, {cost0, cost1}});
        edges[to].push_back({from, {cost0, cost1}});
    }

    f(start, dest, 0);
    f(start, dest, 1);

    // cout << dmap[dest][0].first << ' ' << dmap[dest][0].second << '\n';
    // cout << dmap[dest][1].first << ' ' << dmap[dest][1].second << '\n';

    cout << 1 + (dmap[dest][0] != dmap[dest][1]) << '\n';
}