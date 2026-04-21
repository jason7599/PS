#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes;
int64_t cost_map[16][16];
int64_t dp[16][1 << 16];

int64_t solve(int cur, int mask) {
    if (mask == (1 << n_nodes) - 1) {
        return cost_map[cur][0] ? cost_map[cur][0] : INT64_MAX;
    }
    int64_t& res = dp[cur][mask];
    if (res != -1) {
        return res;
    }

    res = INT64_MAX;
    for (int nxt = 0; nxt < n_nodes; nxt++) {
        if (!(mask & (1 << nxt)) && cost_map[cur][nxt]) {
            int64_t t = solve(nxt, mask | (1 << nxt));
            if (t != INT64_MAX) {
                res = min(res, cost_map[cur][nxt] + t);
            }
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n_nodes;
    for (int i = 0; i < n_nodes; i++) {
        fill(&dp[i][0], &dp[i][1 << n_nodes], -1);
        for (int j = 0; j < n_nodes; j++) {
            cin >> cost_map[i][j];
        }
    }

    cout << solve(0, 1) << '\n';
}
