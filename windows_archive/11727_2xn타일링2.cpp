#include <iostream>

using namespace std;

int dp[1001], mod = 10007;

int main() {

    dp[1] = 1;
    dp[2] = 3;

    int n; cin >> n;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
    }

    cout << dp[n];

}