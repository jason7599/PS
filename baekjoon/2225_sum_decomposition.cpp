#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int dp[201][201];

int solve(int n, int k) {
    if (!n || k == 1) {
        return 1;
    }

    int& res = dp[n][k];
    if (res) {
        return res;
    }

    for (int x = 0; x <= n; x++) {
        res = (res + solve(n - x, k -1)) % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << '\n';
}