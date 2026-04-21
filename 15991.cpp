#include <iostream>

using namespace std;

const int mod = 1e9 + 9;

int dp[100'001];

int solve(int n)
{
    if (!n)
        return 1;
    
    if (n < 0)
        return 0;

    if (dp[n])
        return dp[n];

    return dp[n] = ((solve(n - 2) + solve(n - 4)) % mod + solve(n - 6)) % mod;
}

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}