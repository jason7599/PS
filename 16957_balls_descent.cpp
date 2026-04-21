#include <bits/stdc++.h>

using namespace std;

int board_height, board_width;
int board[500][500];
int ans[500][500];

struct Pos {
    int y = -1;
    int x;
};

Pos get_final_pos(int y, int x) {
    static Pos cache[500][500];

    Pos& res = cache[y][x];

    if (res.y != -1) {
        return res;
    }

    res = {y, x};

    for (int ny = y - 1; ny <= y + 1; ny++) {
        for (int nx = x - 1; nx <= x + 1; nx++) {
            if (ny < 0 || ny >= board_height || nx < 0 || nx >= board_width) {
                continue;
            }
            if (board[ny][nx] < board[res.y][res.x]) {
                res = {ny, nx};
            }
        }
    }

    if (res.y != y || res.x != x) {
        res = get_final_pos(res.y, res.x);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            cin >> board[y][x];
        }
    }

    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            const auto [i, j] = get_final_pos(y, x);
            ans[i][j]++;
        }
    }

    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            cout << ans[y][x] << ' ';
        }
        cout << '\n';
    }
}