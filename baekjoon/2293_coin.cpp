#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dp[100'001];
int coins[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_coin, val;
    cin >> n_coin >> val;

    for (int i = 0; i < n_coin; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + n_coin);

    dp[0] = 1;
    for (int i = 0; i < n_coin; i++) {
        for (int v = coins[i]; v <= val; v++) {
            dp[v] += dp[v - coins[i]];
        }
    }

    cout << dp[val] << '\n';
}
