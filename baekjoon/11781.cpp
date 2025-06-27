#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int to;
    int time;
    bool delay;
};

int n_nodes;
vector<Edge> edges[5001];
double delay_start, delay_end;
double dmap[5001];

double solve() {
    fill(&dmap[1], &dmap[1 + n_nodes], (double)1e18);
    dmap[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.push({0, 1});

    double max_dist = 0;

    while (!pq.empty()) {
        double cur_time = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dmap[cur_node] < cur_time) {
            continue;
        }

        max_dist = max(max_dist, cur_time);

        for (const auto& [nx_node, time, delay] : edges[cur_node]) {
            // cout << cur_node << " -> " << nx_node << " at " << cur_time << ": "; 

            double nx_time = cur_time;
            if (delay && max(cur_time, delay_start) <= min(cur_time + time, delay_end)) { // delay happens during this movement
                double move_dist = 0;
                if (delay_start > cur_time) { // delay starts during movement
                    nx_time += delay_start - cur_time;
                    move_dist += delay_start - cur_time;
                }
                
                // now the delay starts
                double dist_left = time - move_dist;
                double delayed_movement_end = min(nx_time + 2 * dist_left, delay_end);
                
                move_dist += (delayed_movement_end - nx_time) / 2;
                
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

    while (n_edges--) {
        int from, to, time, to_delay, from_delay;
        cin >> from >> to >> time >> to_delay >> from_delay;

        edges[from].push_back(Edge{to, time, (bool)to_delay});
        edges[to].push_back(Edge{from, time, (bool)from_delay});
    }

    cout << solve() << '\n';
}