#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_size;
bool grid[300][300];
char dp[300][300][301];

bool is_oob(int y, int x) {
    return y < 0 || y >= g_size || x < 0 || x >= g_size;
}

bool check(int y, int x) {
    return !is_oob(y, x) && !grid[y][x];
}

bool can_win(int y, int x, int k) {
    if (!check(y + 1, x) && !check(y, x + 1)) {
        return k != 1;
    }

    char& res = dp[y][x][k];
    if (res) {
        return res == 1;
    }

    for (int d = 0; d < 2; d++) {
        int dy = d, dx = !d;
        for (int t = 1, ny = y + dy, nx = x + dx; t <= k && check(ny, nx); t++, ny += dy, nx += dx) {
            if (!can_win(ny, nx, k)) {
                return res = 1;
            }
        }
    }

    for (int nk = 1; nk <= k / 2; nk++) {
        if (k % nk == 0) {
            if (!can_win(y, x, nk)) {
                return res = 1;
            }
        }
    }

    res = -1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int k;
    cin >> g_size >> k;
    for (int y = 0; y < g_size; y++) {
        for (int x = 0; x < g_size; x++) {
            cin >> grid[y][x];
        }
    }

    cout << can_win(0, 0, k) << '\n';
}