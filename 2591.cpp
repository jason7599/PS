#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.length();
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (str[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }
        int v = 10 * (str[i - 2] - '0') + (str[i - 1] - '0');
        if (10 <= v && v <= 34) {
            dp[i] += dp[i - 2];
        }
    }

    cout << dp.back() << '\n';
}