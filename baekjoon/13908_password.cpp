#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dp[8][1 << 10];

int solve(int len, int mask) {
    if (!mask) {
        return pow(10, len);
    }
    if (!len) {
        return 0;
    }
    int& res = dp[len][mask];
    if (res != -1) {
        return res;
    }
    res = 0;
    for (int i = 0; i < 10; i++) {
        res += solve(len - 1, mask & ~(1 << i));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int len, n_key;
    cin >> len >> n_key;

    int mask = 0;
    while (n_key--) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }

    fill(&dp[0][0], &dp[len + 1][0], -1);

    cout << solve(len, mask) << '\n';
}
