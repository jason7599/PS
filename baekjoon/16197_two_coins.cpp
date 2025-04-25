#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int b_height, b_width;
bool board_obstacles[20][20];
bool visited[20][20][20][20];

bool get_board(pii coin) {
    return board_obstacles[coin.first][coin.second];
}

bool& get_visited(pii coin0, pii coin1) {
    return visited[coin0.first][coin0.second][coin1.first][coin1.second];
}

bool is_oob(int y, int x) {
    return y < 0 || y >= b_height || x < 0 || x >= b_width;
}

bool is_oob(pii coin) {
    return is_oob(coin.first, coin.second);
}

int solve(pii coin0, pii coin1) {
    queue<pair<pii, pii>> q({{coin0, coin1}});
    get_visited(coin0, coin1) = 1;

    int time = 0;
    for (int q_size; (q_size = q.size()) && time < 10; time++) {
        while (q_size--) {
            auto [coin0, coin1] = q.front();
            q.pop();

            for (const auto [dy, dx] : DIRS) {
                pii next0 = {coin0.first + dy, coin0.second + dx};
                pii next1 = {coin1.first + dy, coin1.second + dx};

                int oob_cnt = 0;

                if (is_oob(next0)) {
                    oob_cnt++;
                } else if (get_board(next0)) {
                    next0 = coin0;
                }
                if (is_oob(next1)) {
                    oob_cnt++;
                } else if (get_board(next1)) {
                    next1 = coin1;
                }

                if (next0 == next1 || oob_cnt == 2) {
                    continue;
                } else if (oob_cnt == 1) {
                    return time + 1;
                } else {
                    bool& v = get_visited(next0, next1);
                    if (!v) {
                        v = 1;
                        q.push({next0, next1});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    pii coin0{-1, -1}, coin1;
    cin >> b_height >> b_width;
    for (int y = 0; y < b_height; y++) {
        for (int x = 0; x < b_width; x++) {
            char c;
            cin >> c;
            if (c == 'o') {
                if (coin0.first == -1) {
                    coin0 = {y, x};
                } else {
                    coin1 = {y, x};
                }
            } else {
                board_obstacles[y][x] = c == '#';
            }
        }
    }

    cout << solve(coin0, coin1) << '\n';
}