#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dist_map[10'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_shortcut, road_len;
    cin >> n_shortcut >> road_len;

    unordered_map<int, vector<pii>> edges; // <start, <dest, len>>;
    set<int> points_set;

    for (int i = 0; i < n_shortcut; i++) {
        int start, dest, len;
        cin >> start >> dest >> len;
        if (dest <= road_len && dest - start > len) {
            edges[start].push_back({dest, len});
            points_set.insert(start);
            points_set.insert(dest);
        }
    }

    vector<int> points(points_set.begin(), points_set.end());
    if (!points.empty()) {
        for (int prev = 0, i = 0; i < points.size(); i++) {
            edges[prev].push_back({points[i], points[i] - prev});
            prev = points[i];
        }
        edges[points.back()].push_back({road_len, road_len - points.back()});
    } else {
        edges[0].push_back({road_len, road_len});
    }

    fill(&dist_map[0], &dist_map[1 + road_len], INT_MAX);
    dist_map[0] = 0;

    priority_queue<pii> pq; 
    pq.push({0, 0});

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();

        if (dist_map[cur_pos] < cur_dist) {
            continue;
        }

        if (cur_pos == road_len) {
            break;
        }

        for (const auto& [nxt, len] : edges[cur_pos]) {
            int nxt_dist = cur_dist + len;
            if (nxt_dist < dist_map[nxt]) {
                dist_map[nxt] = nxt_dist;
                pq.push({-nxt_dist, nxt});
            }
        }
    }

    cout << dist_map[road_len] << '\n';
}
