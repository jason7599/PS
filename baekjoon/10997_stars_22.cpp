#include <bits/stdc++.h>
using namespace std;

bool board[400 - 1][400 - 3];

const bool BITCH[7][5] = {
    {1, 1, 1, 1, 1},
    {1},
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

void draw(int n, int y, int x) {
    int h = 4 * n - 1;
    int w = h - 2;

    if (n == 2) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[y + i][x + j] = BITCH[i][j];
            }
        }
        return;
    }

    for (int i = 0; i < h; i++) {
        board[y + i][x] = board[y + i][x + w - 1] = 1;
    }

    board[y + 1][x + w - 1] = 0;

    for (int j = 1; j < w - 1; j++) {
        board[y][x + j] = board[y + h - 1][x + j] = 1;
    }

    draw(n - 1, y + 2, x + 2);

    board[y + 2][x + w - 2] = 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    if (n == 1) {
        cout << "*\n";
        return 0;
    }

    draw(n, 0, 0);

    for (int y = 0; y < 4 * n - 1; y++) {
        for (int x = 0; x < 4 * n - 3; x++) {
            cout << (board[y][x] ? '*' : ' ');
            if (y == 1 && x == 1) {
                break;
            }
        }
        cout << '\n';
    }
}
