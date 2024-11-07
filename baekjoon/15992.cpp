#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 9;

int solve(int n, int m)
{
    static int dp[1'001][1'001];

    if (n < 0)
        return 0;

    if (n == 0)
        return m == 0;

    if (m == 1)
        return n <= 3;

    if (dp[n][m])
        return max(dp[n][m], 0);

    int res = ((solve(n - 1, m - 1) 
        + solve(n - 2, m - 1)) % mod
        + solve(n - 3, m - 1)) % mod;
    
    if (!res)
    {
        dp[n][m] = -1;
        return 0;
    }

    return dp[n][m] = res;
}

int main()
{
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