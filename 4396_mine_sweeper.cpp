#include <bits/stdc++.h>
using namespace std;

int g_size;
bool mines[10][10];
char res[10][10];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_size;
    for (int y = 0; y < g_size; y++) {
        for (int x = 0; x < g_size; x++) {
            char c;
            cin >> c;
            mines[y][x] = c == '*';
        }
    }

    bool game_over = 0;
    for (int y = 0; y < g_size; y++) {
        for (int x = 0; x < g_size; x++) {
            char c;
            cin >> c;
            if (c == 'x') {
                if (mines[y][x]) {
                    game_over = 1;
                } else {
                    int cnt = 0;
                    for (int ny = max(y - 1, 0); ny <= min(y + 1, g_size - 1); ny++) {
                        for (int nx = max(x - 1, 0); nx <= min(x + 1, g_size - 1); nx++) {
                            if (ny == y && nx == x) {
                                continue;
                            }
                            cnt += mines[ny][nx];
                        }
                    }
                    res[y][x] = '0' + cnt;
                }
            } else {
                res[y][x] = '.';
            }
        }
    }

    for (int y = 0; y < g_size; y++) {
        for (int x = 0; x < g_size; x++) {
            if (mines[y][x]) {
                if (game_over) {
                    cout << '*';
                } else {
                    cout << '.';
                }
            } else {
                cout << res[y][x];
            }
        }
        cout << '\n';
    }
}
