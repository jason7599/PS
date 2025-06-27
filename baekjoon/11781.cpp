#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int to;
    int64_t time;
    bool delay;
};

int n_nodes;
vector<Edge> edges[5001];
int64_t delay_start, delay_end;
int64_t dmap[5001];

int64_t solve() {
    fill(&dmap[2], &dmap[1 + n_nodes], INT64_MAX);
    priority_queue<pair<int64_t, int>> pq;
    pq.push({0, 1});

    int64_t max_dist = 0;

    while (!pq.empty()) {
        int64_t cur_time = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dmap[cur_node] < cur_time) {
            continue;
        }

        max_dist = max(max_dist, cur_time);

        for (const auto& [nx_node, time, delay] : edges[cur_node]) {
            // cout << cur_node << " -> " << nx_node << " at " << cur_time << ": "; 

            int64_t nx_time = cur_time;
            if (delay && max(cur_time, delay_start) <= min(cur_time + time, delay_end)) { // delay happens during this movement
                int64_t move_dist = 0;
                if (delay_start > cur_time) { // delay starts during movement
                    nx_time += delay_start - cur_time;
                    move_dist += delay_start - cur_time;
                }
                
                // now the delay starts
                int64_t dist_left = time - move_dist;
                int64_t delayed_movement_end = min(nx_time + 4 * dist_left, delay_end);
                
                move_dist += (delayed_movement_end - nx_time);
                
                nx_time = delayed_movement_end;
                nx_time += time - move_dist;
            } else {
                nx_time += time;
            }

            // cout << nx_time << '\n';

            if (dmap[nx_node] > nx_time) {
                dmap[nx_node] = nx_time;
                pq.push({-nx_time, nx_node});
            }
        }
    }

    return max_dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges;
    cin >> n_nodes >> n_edges >> delay_start >> delay_end;

    delay_start *= 4;
    delay_end *= 4;

    while (n_edges--) {
        int from, to, time, to_delay, from_delay;
        cin >> from >> to >> time >> to_delay >> from_delay;

        edges[from].push_back(Edge{to, time * 4, (bool)to_delay});
        edges[to].push_back(Edge{from, time * 4, (bool)from_delay});
    }

    cout << solve() / 4.0f << '\n';
}