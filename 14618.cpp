#include <bits/stdc++.h>

using namespace std;

struct Road {
    int to;
    int dist;
};

struct House {
    char type = 0;
    vector<Road> roads;
};

int n_houses;
House houses[5001];
int dists[5001];

struct RoadCmp {
    bool operator()(const Road& lhs, const Road& rhs) {
        if (lhs.dist == rhs.dist) {
            return houses[rhs.to].type == 'A';
        }
        return lhs.dist > rhs.dist;
    }
};

int get_closest_house(int home_num) {
    priority_queue<Road, vector<Road>, RoadCmp> pq;

    dists[home_num] = 0;
    pq.push(Road{home_num, 0});

    while (!pq.empty()) {
        const auto [house, cur_dist] = pq.top();
        pq.pop();

        if (cur_dist > dists[house])
            continue;
        
        if (houses[house].type)
            return house;
        
        for (const auto [to, dist] : houses[house].roads) {
            int next_dist = cur_dist + dist;
            if (next_dist < dists[to]) {
                dists[to] = next_dist;
                pq.push(Road{to, next_dist});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_roads;
    cin >> n_houses >> n_roads;

    fill(&dists[1], &dists[n_houses + 1], INT_MAX);

    int home_num;
    cin >> home_num;

    int k;
    cin >> k;

    for (char type = 'A'; type <= 'B'; type++) {
        for (int i = 0; i < k; i++) {
            int h;
            cin >> h;
            houses[h].type = type;
        }
    }

    while (n_roads--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        houses[from].roads.push_back(Road{to, dist});
        houses[to].roads.push_back(Road{from, dist});
    }

    int ans = get_closest_house(home_num);
    if (ans != -1) {
        cout << houses[ans].type << '\n';
        cout << dists[ans] << '\n';
    } else {
        cout << -1 << '\n';
    }
}