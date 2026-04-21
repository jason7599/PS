#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct EdgeCmp {
    bool operator()(Edge& lhs, Edge& rhs) {
        return lhs.weight > rhs.weight;
    }
};

int n_nodes;
vector<Edge> edges[1001];
int dists[1001];
int prevs[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_edges;
    cin >> n_nodes >> n_edges;

    for (int i = 0; i < n_edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back(Edge{to, weight});
    }

    int src, dst;
    cin >> src >> dst;

    fill(&dists[1], &dists[n_nodes + 1], INT_MAX);
    
    dists[src] = 0;
    prevs[src] = -1;

    priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
    pq.push(Edge{src, 0});

    while (!pq.empty()) {
        const auto [cur_node, cur_dist] = pq.top();
        pq.pop();

        if (cur_node == dst) {
            break;
        }

        if (cur_dist > dists[cur_node]) {
            continue;
        }

        for (const auto [next, dist] : edges[cur_node]) {
            int next_dist = cur_dist + dist;
            if (next_dist < dists[next]) {
                dists[next] = next_dist;
                prevs[next] = cur_node;
                pq.push(Edge{next, next_dist});
            }
        }
    }

    cout << dists[dst] << '\n';
    
    stack<int> path;
    for (int n = dst; n != -1; n = prevs[n]) {
        path.push(n);
    }

    cout << path.size() << '\n';
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';
}