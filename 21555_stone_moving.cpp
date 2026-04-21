#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n, arr[2][200'000], k;
ll dp[2][200'000];

ll f(int i, int j) {
    if (j == n) {
        return 0;
    }
    
    ll& res = dp[i][j];
    if (res) {
        return res;
    }

    return res = min(
        arr[i][j] + f(i, j + 1),
        k + arr[!i][j] + f(!i, j + 1)
    );
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    FOR(i, 2) {
        FOR(j, n) {
            cin >> arr[i][j];
        }
    }

    PRINT(min(f(0, 0), f(1, 0)))
}