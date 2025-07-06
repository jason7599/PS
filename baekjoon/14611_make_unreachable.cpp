#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

/**
 * ㅈㄴ 야매풀이 같긴한데 이거 말고 아이디어가 없다
 * 
 * 격자의 아래쪽 & 왼쪽을 한쌍,
 * 격자의 위쪽 & 오른쪽을 한쌍으로 잡아서
 * 가각에 대한 더미 노드깔고, 서로를 연결하면 최소경로 찾으면 되는거 아님?
 * 
 * -2 인 애들은 가중치 0 노드인 셈인거고
 * 
 * 시작점이랑 끝점이 반대편 코너에 박혀있으니 가능한 방법이겠네
 * 
 * 아니 근데 생각해보니 더미노드가 2개나 필요한가?
 * 걍 한쪽은 pq 채우는 용으로만 해도 되는거 아닌가 맞는듯
 * 
 * 아 ㅅ바 대각선..
 * 
 */

// [0][0]: 위 & 오른쪽
int g_h, g_w;
int64_t grid[301][301];
int64_t dmap[301][301];

const pii DIRS[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

bool is_oob(int y, int x) {
    return y <= 0 || y > g_h || x <= 0 || x > g_w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w;

    // 아래 & 왼이 시작점인걸로 하자
    priority_queue<pair<int64_t, pii>> pq; // <-cost, <y, x>>

    for (int y = 1; y <= g_h; y++) {
        for (int x = 1; x <= g_w; x++) {
            cin >> grid[y][x];
            dmap[y][x] = INT64_MAX;

            if (grid[y][x] != -1 && (y == g_h || x == 1)) { // 아래 & 왼
                int64_t cost = grid[y][x] == -2 ? 0 : grid[y][x];
                dmap[y][x] = cost;
                pq.push({-cost, {y, x}});
                // cout << "init push " << y << ", " << x << ": " << cost << '\n';
            }
        }
    }

    int64_t ans = INT64_MAX;

    while (!pq.empty()) {
        int64_t cur_cost = -pq.top().first;
        const auto [y, x] = pq.top().second;
        pq.pop();

        if (dmap[y][x] < cur_cost) {
            continue;
        }

        if (y == 1 || x == g_w) {
            // ans = min(ans, cur_cost);
            assert(0);
            continue;
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (is_oob(ny, nx) || grid[ny][nx] == -1) {
                continue;
            }

            int64_t c = grid[ny][nx] == -2 ? 0 : grid[ny][nx];
            int64_t nxt_cost = cur_cost + c;
            if (ny == 1 || nx == g_w) {
                ans = min(ans, nxt_cost);
                continue;
            }

            if (nxt_cost < dmap[ny][nx]) {
                dmap[ny][nx] = nxt_cost;
                pq.push({-nxt_cost, {ny, nx}});
            }
        }
    }

    cout << (ans == INT64_MAX ? -1 : ans) << '\n';
}