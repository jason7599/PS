#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> edges[300'001];
int cycle_len, cycle[300'000];
int time_map[300'001];
int start, dest;
vector<int> opt_edges[300'001];
int opt_dists[300'001];

/**
 * bfs로 최단 거리 방향 기록하고, 그 다음에 그걸 기반으로 다익스트라?
 */
 
void bfs() {
    queue<int> q;
    q.push(start);
    opt_dists[start] = 0;
    // time_map[dest] = INT_MAX; // hacky. using time_map[node] = INT_MAX to denote visited
    // time_map[start] = INT_MAX;
    // q.push(start);

    for (int dist = 0, q_size; (q_size = q.size()); dist++) {
        while (q_size--) {
            int cur = q.front();
            q.pop();

            for (int nxt : edges[cur]) {
                if (opt_dists[nxt] > dist + 1) {
                    opt_dists[nxt] = dist + 1;
                    opt_edges[cur].push_back(nxt);
                    q.push(nxt);
                } else if (opt_dists[nxt] == dist + 1) {
                    // opt_edges[cur].push_back(nxt);
                }
            }
        }
    }

    // while (!q.empty()) {
    //     int cur = q.front();
    //     q.pop();

    //     for (int nxt : edges[cur]) {
    //         if (!time_map[nxt]) {
    //             time_map[nxt] = INT_MAX;
    //             opt_edges[nxt].push_back(cur);
    //             // opt_edges[cur].push_back(nxt);
    //             q.push(nxt);
    //         }
    //     }
    // }
}

void djikstra() {
    priority_queue<pii> pq;

    pq.push({0, start});
    time_map[start] = 0;

    while (!pq.empty()) {
        int cur_time = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (time_map[cur_node] < cur_time) {
            continue;
        }

        if (cur_node == dest) {
            return;
        }

        for (int nxt : opt_edges[cur_node]) {
            int nxt_time = -1;
            for (int t = 1; t <= cycle_len; t++) {
                if (cycle[(cur_time + t) % cycle_len] != nxt) {
                    nxt_time = cur_time + t;
                    break;
                }
            }
            if (nxt_time == -1) {
                continue;
            }
            if (time_map[nxt] > nxt_time) {
                time_map[nxt] = nxt_time;
                pq.push({-nxt_time, nxt});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_node, n_edge;
    cin >> n_node >> n_edge;

    cin >> start >> dest;

    cin >> cycle_len;
    for (int i = 0; i < cycle_len; i++) {
        cin >> cycle[i];
    }

    while (n_edge--) {
        int n1, n2;
        cin >> n1 >> n2;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }

    fill(&time_map[1], &time_map[1 + n_node], INT_MAX);
    fill(&opt_dists[1], &opt_dists[1 + n_node], INT_MAX);

    bfs();
    djikstra();

    if (time_map[dest] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << time_map[dest] << '\n';
    }
}
