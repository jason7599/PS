#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

bool vis[30][15 * 29 + 1][30][30];
char ans[30];

bool f(int len, int k, int i, int a, int b) {
    if (!k) {
        // fill with a
        for (; i < len; i++) {
            ans[i] = 'A';
        }
        return 1;
    }
    if (i == len) {
        return 0;
    }
    if (vis[i][k][a][b]) {
        return 0;
    }
    vis[i][k][a][b] = 1;

    // place a
    if (f(len, k, i + 1, a + 1, b)) {
        ans[i] = 'A';
        return 1;
    }

    // place b
    if (k - a >= 0 && f(len, k - a, i + 1, a, b + 1)) {
        ans[i] = 'B';
        return 1;
    }

    // place c
    if (k - a - b >= 0 && f(len, k - a - b, i + 1, a, b)) {
        ans[i] = 'C';
        return 1;
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int len, k;
    cin >> len >> k;

    if (!f(len, k, 0, 0, 0)) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < len; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
}