/**
 * 각 빈공간마다 id 부여하기
 * 가장 바깥 빈칸, 즉 외부 바다랑 맞닿아 있는 
 * 공간부터 시작해서 좁혀 들어오기. 
 * 
 * 빈공간을 기준으로 bfs해서 건들인 섬 타일을 
 * 큐에 집어넣고, 다음에 이 큐를 가지고 또 bfs.
 * 재귀적.
 * 
 * 섬에 대해서 해야겠네. 다시 말해 island_id를 인자로 줘야겠음
 * 그래야 높이 정보 수정하면서 하게
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w;
int island_ids[50][50];
bool vac_vis[50][50];

vector<queue<pii>> islands(1);

bool is_oob(int y, int x) {
    return y < 0 || x < 0 || y >= g_h || x >= g_w;
}

void mark_island(int y, int x, int id) {
    island_ids[y][x] = id;
    islands[id].push({y, x});
    for (int ny = max(0, y - 1); ny <= min(y + 1, g_h - 1); ny++) {
        for (int nx = max(0, x - 1); nx <= min(x + 1, g_w - 1); nx++) {
            if (island_ids[ny][nx] == -1) {
                mark_island(ny, nx, id);
            }
        }
    }
}

int max_height;
unordered_map<int, int> height_cnt;

int get_height(int island_id) {
    queue<pii>& q = islands[island_id];

    unordered_set<int> nx_island_ids;

    while (!q.empty()) {
        const auto [y, x] = q.front();
        q.pop();

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (is_oob(ny, nx) || vac_vis[ny][nx]) {
                continue;
            }

            vac_vis[ny][nx] = 1;

            int nx_island_id = island_ids[ny][nx];
            if (nx_island_id && nx_island_id != island_id) {
                nx_island_ids.insert(nx_island_id);
            } else {
                q.push({ny, nx});
            }
        }
    }

    int height = -1;
    for (int nx_island_id : nx_island_ids) {
        height = max(height, get_height(nx_island_id));
    }
    height++;

    if (island_id) {
        max_height = max(max_height, height);
        height_cnt[height]++;
    }

    return height;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            char c;
            cin >> c;
            if (c == 'x') {
                island_ids[y][x] = -1; // hacky
            } else {
                if (!y || y + 1 == g_h || !x || x + 1 == g_w) {
                    islands[0].push({y, x});
                    vac_vis[y][x] = 1;
                }
            }
        }
    }

    int n_islands = 0;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            if (island_ids[y][x] == -1) {
                islands.push_back({});
                mark_island(y, x, ++n_islands);
            }
        }
    }

    if (!n_islands) {
        cout << -1 << '\n';
        return 0;
    }

    get_height(islands[0].empty());

    for (int i = 0; i <= max_height; i++) {
        cout << height_cnt[i] << ' ';
    }
    cout << '\n';
}