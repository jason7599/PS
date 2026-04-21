#include <bits/stdc++.h>
using namespace std;

char dp[1001];

bool game(int n) {
    if (!n) {
        return 1;
    }
    if (dp[n]) {
        return dp[n] == 1;
    }
    for (int i = 1; i <= min(4, n); i++) {
        if (i == 2) {
            continue;
        }
        if (!game(n - i)) {
            return dp[n] = 1;
        }
    }
    dp[n] = -1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    if (game(n)) {
        cout << "SK\n";
    } else {
        cout << "CY\n";
    }
}
