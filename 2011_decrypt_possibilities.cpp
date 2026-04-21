#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string seq;
    cin >> seq;

    if (seq.front() == '0') {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> dp(seq.length());
    dp[0] = 1;

    for (int i = 1; i < seq.length(); i++) {
        if (seq[i] != '0') {
            dp[i] = dp[i - 1];
        }
        if (seq[i - 1] != '0') {
            int v = (seq[i - 1] - '0') * 10 + seq[i] - '0';
            if (v <= 26) {
                if (i == 1) {
                    dp[i]++;
                } else {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                }
            }
        }
    }

    cout << dp.back() << '\n';
}