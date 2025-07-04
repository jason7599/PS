#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes;
vector<pii> edges[200'001];
int dmap[200'001];
int prevs[200'001];
bool vis[200'001];

void path_stack(int node, int start, stack<int>& path) {
    for (int n = node; n != start; n = prevs[n]) {
        path.push(n);
    }
    path.push(start);
}

int f(int start, int dest, bool check_vis) {
    fill(&dmap[1], &dmap[n_nodes + 1], INT_MAX);
    dmap[start] = 0;

    priority_queue<pii> pq;
    pq.push({0, -start});

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = -pq.top().second;
        pq.pop();

        if (dmap[cur_node] < cur_dist) {
            continue;
        }

        for (const auto& [nx_node, dist] : edges[cur_node]) {
            if (!check_vis || !vis[nx_node]) {
                int nx_dist = cur_dist + dist;
                if (dmap[nx_node] > nx_dist) {
                    dmap[nx_node] = nx_dist;
                    prevs[nx_node] = cur_node;
                    pq.push({-nx_dist, -nx_node});
                } else if (!check_vis && dmap[nx_node] == nx_dist) {
                    stack<int> prev_path, new_path;
                    path_stack(nx_node, start, prev_path);

                    new_path.push(nx_node);
                    path_stack(cur_node, start, new_path);

                    bool b;
                    for (;; prev_path.pop(), new_path.pop()) {
                        int pp = prev_path.top(), np = new_path.top();
                        if (pp != np) {
                            b = pp > np;
                            break;
                        }
                    }

                    if (b) {
                        prevs[nx_node] = cur_node;
                    }
                }
            }
        }
    }

    return dmap[dest];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges;
    cin >> n_nodes >> n_edges;

    while (n_edges--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back({to, dist});
        edges[to].push_back({from, dist});
    }

    int start, dest;
    cin >> start >> dest;

    int d = f(start, dest, 0);

    for (int n = prevs[dest]; n != start; n = prevs[n]) {
        vis[n] = 1;
    }

    cout << d + f(dest, start, 1) << '\n';
}