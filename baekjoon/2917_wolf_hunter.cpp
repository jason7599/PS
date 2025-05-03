#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w;
int tree_dists[500][500];
int min_tree_dists[500][500];

int& get_cell(int A[][500], pii pos) {
    return A[pos.first][pos.second];
}

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

void map_tree_dists(queue<pii>& trees) {
    for (int dist = 0, q_size; (q_size = trees.size()); dist++) {
        while (q_size--) {
            const auto [y, x] = trees.front();
            trees.pop();

            for (const auto [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (is_oob(ny, nx)) {
                    continue;
                }
                
                if (tree_dists[ny][nx] == INT_MAX) {
                    tree_dists[ny][nx] = dist + 1;
                    trees.push({ny, nx});
                }
            }
        }
    }
}

int get_min_tree_dist(pii start, pii dest) {
    priority_queue<pair<int, pii>> pq;
    pq.push({get_cell(tree_dists, start), start});
    get_cell(min_tree_dists, start) = get_cell(tree_dists, start);

    while (pq.size()) {
        int cur_dist = pq.top().first;
        const auto [y, x] = pq.top().second;
        pq.pop();

        if (cur_dist < min_tree_dists[y][x]) {
            continue;
        }

        if (y == dest.first && x == dest.second) {
            return cur_dist;
        }

        for (const auto [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (is_oob(ny, nx)) {
                continue;
            }

            int next_dist = min(cur_dist, tree_dists[ny][nx]);
            if (next_dist > min_tree_dists[ny][nx]) {
                min_tree_dists[ny][nx] = next_dist;
                pq.push({next_dist, {ny, nx}});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    
    pii start, dest;
    queue<pii> trees;

    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            char c;
            cin >> c;
            tree_dists[y][x] = INT_MAX;
            min_tree_dists[y][x] = -1;
            if (c == 'V') {
                start = {y, x};
            } else if (c == 'J') {
                dest = {y, x};
            } else if (c == '+') {
                trees.push({y, x});
                tree_dists[y][x] = 0;
            }
        }
    }

    map_tree_dists(trees);

    cout << get_min_tree_dist(start, dest) << '\n';
}