#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, arr[200][2], dp[200][201][3];

int f(int i, int k, int p) {
    if (i == n || !k) { // sussy baka
        return 0;
    }

    int& res = dp[i][k][p];
    if (res != -1) {
        return res;
    }

    res = INT_MAX;
    if (p) {
        res = arr[i][p - 1] + f(i + 1, k - 1, p);
    } else {
        for (int j = 0; j < 2; j++) {
            res = min(res, arr[i][j] + f(i + 1, k - 1, j + 1));
        }
    }

    if (n - i > k) {
        res = min(res, f(i + 1, k, 0));
    }
    
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (;;) {
        int k, sum = 0;
        cin >> n >> k;
        if (!n) {
            break;
        }
        for (int i = 0; i < n; i++) {
            fill(&dp[i][0][0], &dp[i][k + 1][0], -1);
            for (int j = 0; j < 2; j++) {
                cin >> arr[i][j];
                sum += arr[i][j];
            }
        }
        cout << sum - f(0, k, 0) << '\n';
    }
}