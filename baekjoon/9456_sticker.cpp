#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n, arr[2][100'000], dp[3][100'000];

int f(int i, int p) {
    if (i == n) {
        return 0;
    }

    int& res = dp[p][i];
    if (res != -1) {
        return res;
    }

    res = f(i + 1, 0);
    FORR(j, 1, 2) {
        if (j != p) {
            res = max(res, arr[j - 1][i] + f(i + 1, j));
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> n;
        FOR(i, 2) {
            FOR(j, n) {
                cin >> arr[i][j];
                dp[i][j] = -1;
            }
            fill(&dp[2][0], &dp[2][n], -1);
        }
        PRINT(f(0, 0))
    }
}