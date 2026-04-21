#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int to;
    int64_t time;   // Time is already scaled by 2
    bool delay;
};

int n_nodes;
vector<Edge> edges[5001];
int64_t delay_start, delay_end;
int64_t dmap[5001];

double solve() {
    const int64_t INF = 1e18;
    fill(&dmap[1], &dmap[1 + n_nodes], INF);
    dmap[1] = 0;

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
            int64_t nx_time = cur_time;

            if (delay && max(cur_time, delay_start) <= min(cur_time + time, delay_end)) {
                int64_t move_dist = 0;

                if (delay_start > cur_time) {
                    int64_t normal_time = delay_start - cur_time;
                    nx_time += normal_time;
                    move_dist += normal_time;
                }

                // Delay starts
                int64_t dist_left = time - move_dist;
                int64_t delay_time_available = delay_end - nx_time;
                int64_t delay_movement_time = min(2 * dist_left, delay_time_available);

                int64_t delay_dist = delay_movement_time / 2;
                move_dist += delay_dist;
                nx_time += delay_movement_time;

                // Finish remaining at normal speed
                nx_time += (time - move_dist);
            } else {
                nx_time += time;
            }

            if (dmap[nx_node] > nx_time) {
                dmap[nx_node] = nx_time;
                pq.push({-nx_time, nx_node});
            }
        }
    }

    return max_dist / 2.0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_edges;
    cin >> n_nodes >> n_edges >> delay_start >> delay_end;

    delay_start *= 2;
    delay_end *= 2;

    while (n_edges--) {
        int from, to, time, to_delay, from_delay;
        cin >> from >> to >> time >> to_delay >> from_delay;
        edges[from].push_back(Edge{to, time * 2, (bool)to_delay});
        edges[to].push_back(Edge{from, time * 2, (bool)from_delay});
    }

    cout << solve() << '\n';
}
