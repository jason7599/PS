#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

ll dp[30][30];

ll f(int n, int m) {
    if (n == 1) {
        return m;
    }

    if (n == m) {
        return 1;
    }

    ll& res = dp[n][m];
    if (res) {
        return res;
    }

    for (; n - 1 <= m - 1; m--) {
        res += f(n - 1, m - 1);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        int n, m;
        cin >> n >> m;
        cout << f(n, m) << '\n';
    }
}