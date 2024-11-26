#include <iostream>
#include <algorithm>

using namespace std;

int numCoins;
int coinVals[100];
int dp[10'001];

int solve(int target)
{
    if (target < 0)
        return -1;

    if (dp[target])
        return dp[target];

    int res = 1e9;
    for (int i = 0; i < numCoins; i++)
    {
        int t = solve(target - coinVals[i]);
        if (t != -1)
            res = min(res, t);
    }

    if (res == 1e9)
        res = -2;

    return dp[target] = 1 + res; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int target;

    cin >> numCoins >> target;
    for (int i = 0; i < numCoins; i++)
    {
        cin >> coinVals[i];
        if (coinVals[i] < 10'001)
            dp[coinVals[i]] = 1;
    }

    cout << solve(target);
    return 0;
}