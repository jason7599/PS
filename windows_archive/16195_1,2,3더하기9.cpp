#include <iostream>

using namespace std;

const int mod = 1e9 + 9;

int dp[1001][1001];

int solve(int n, int m)
{
    if (n <= 0 || m <= 0)
        return 0;
    
    if (dp[n][m])
        return dp[n][m];
    
    return dp[n][m]
        = solve(n - 1, m - 1)
        + solve(n - 2, m - 1)
        + solve(n - 3, m - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << '\n';
    }

    return 0;
}