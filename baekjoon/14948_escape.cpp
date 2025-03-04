#include <bits/stdc++.h>

using namespace std;

const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int map_height, map_width;
int map_levels[100][100];

bool is_oob(int y, int x) {
    return y < 0 || y >= map_height || x < 0 || x >= map_width;
}

struct State {
    int y, x;
    bool jumped;
};

bool can_escape(int level) {
    static int visited[100][100][2];
    static int nx_visit_id = 1;

    int visit_id = visited[0][0][0] = nx_visit_id++;
    queue<State> q({State{0, 0, 0}});

    while (!q.empty()) {

        const auto [y, x, jumped] = q.front();
        q.pop();

        if (y == map_height - 1 && x == map_width - 1)
            return 1;
        
        for (const auto& [dy, dx] : DIRS) {
            int ny = y;
            int nx = x;

            for (int i = 0; i <= !jumped; i++) {
                ny += dy;
                nx += dx;

                if (is_oob(ny, nx))
                    break;
                
                bool t = i ? 0 : jumped;
                if (level >= map_levels[ny][nx] && visited[ny][nx][t] != visit_id) {
                    visited[ny][nx][t] = visit_id;
                    q.push(State{ny, nx, t});
                }
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> map_height >> map_width;

    int low = INT_MAX;
    int high = 0;

    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            int& level = map_levels[y][x];
            cin >> level;
            low = min(low, level);
            high = max(high, level);
        }
    }

    while (low < high) {
        int mid = (low + high) >> 1;

        if (can_escape(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << high << '\n';
}