#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_size;
int grid[501][501];

int get_sum(int y, int x0, int x1) {
    return grid[y][x1] - grid[y][x0 - 1];
}

int get_tile(int y, int x) {
    return get_sum(y, x, x);
}

int solve(int s_y, int s_x, int jump_dist) {
    int ans = get_sum(s_y, s_x, g_size);

    for (int x = s_x; x <= g_size; x++) {
        for (int y = s_y; y <= g_size; y++) {
            int t = get_sum(s_y, s_x, x)
                + get_sum(y, x, g_size);
            ans = min(ans, t);
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_queries;
    cin >> g_size >> n_queries;
    for (int y = 1; y <= g_size; y++) {
        for (int x = 1; x <= g_size; x++) {
            cin >> grid[y][x];
            grid[y][x] += grid[y][x - 1];
        }
    }

    while (n_queries--) {
        int y, x, jump_dist;
        cin >> y >> x >> jump_dist;
        cout << solve(y, x, jump_dist) << '\n';
    }
}