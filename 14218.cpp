#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> edges[1001];
int vis[1001];
int vis_id;
int dis[1001];

void bfs() {
    queue<int> q({1});
    vis[1] = ++vis_id;

    for (int d = 0, qs; (qs = q.size()); d++) {
        while (qs--) {
            int n = q.front();
            q.pop();
            for (int nx : edges[n]) {
                if (vis[nx] != vis_id) {
                    vis[nx] = vis_id;
                    dis[nx] = d + 1;
                    q.push(nx);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_node, n_edge;
    cin >> n_node >> n_edge;
    while (n_edge--) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    cin >> n_edge;
    while (n_edge--) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);

        bfs();

        for (int n = 1; n <= n_node; n++) {
            if (vis[n] != vis_id) {
                cout << -1;
            } else {
                cout << dis[n];
            }
            cout << ' ';
        }
        cout << '\n';
    }
}
