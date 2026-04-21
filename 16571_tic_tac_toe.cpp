#include <bits/stdc++.h>
using namespace std;

#define LOOP(i) for (int i = 0; i < 3; i++)

int board[3][3];

bool check(int i, int j, int di, int dj, int p) {
    LOOP(_) {
        if (board[i][j] != p) return 0;
        i += di, j += dj;
    }
    return 1;
}

bool check_win(int i, int j, int p) {
    return check(i, 0, 0, 1, p)
        || check(0, j, 1, 0, p)
        || (i == j && (
            check(0, 0, 1, 1, p)
            || check(0, 2, 1, -1, p)
        ));
}

int func(int p, int t) {
    cout << p << ", " << t << '\n';
    if (!t) return 0; // draw
    int lost = 0;
    LOOP(i) {
        LOOP(j) {
            if (!board[i][j]) {
                board[i][j] = p;
                if (check_win(i, j, p)) {
                    return 1;
                }
                int n = func(1 + (p % 2), t - 1);
                if (n == -1) {
                    return 1;
                } else if (n) {
                    lost++;
                }
                board[i][j] = 0;
            }
        }
    }
    return lost == t ? -1 : 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n1 = 0, n2 = 0;
    LOOP(i) {
        LOOP(j) {
            int t;
            cin >> t;
            board[i][j] = t;
            if (t) {
                (t == 1 ? n1 : n2)++;
            }
        }
    }

    cout << func(n1 <= n2 ? 1 : 2, 9 - n1 - n2) << '\n';
    // cout << "LDW"[func(n1 <= n2 ? 1 : 2, 9 - n1 - n2) + 1] << '\n';
}