#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int dp[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    // dp[k][n]: number of sequences of length K with elems 0 ~ n
    // dp[k][n] = sum(dp[k - 1][n - x] for x in range [0, n])
    // base case: dp[n][1] = 1

    dp[0][0] = 1;
    for (int k = 1; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int x = 0; x <= n; x++) {
                dp[k][n] = (dp[k][n] + dp[k - 1][n - x]) % MOD;
            }
        }
    }

    cout << dp[K][N] << '\n';
}