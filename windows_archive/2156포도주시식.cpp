#include <iostream>
#include <algorithm>

using namespace std;

int numWines;
int wine[10'000];

int solve(int wineIndex = 0, bool drankLast = 0)
{
    static int dp[10'000][2];

    if (wineIndex >= numWines)
        return 0;

    if (dp[wineIndex][drankLast])
        return max(dp[wineIndex][drankLast], 0);
    
    int res = max(
        solve(wineIndex + 1, 0), // skip 
        wine[wineIndex] + (drankLast ? solve(wineIndex + 2, 0) : solve(wineIndex + 1, 1))
    );

    dp[wineIndex][drankLast] = res ? res : -1;

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> numWines;

    for (int i = 0; i < numWines; i++)
        cin >> wine[i];

    cout << solve();
    return 0;
    
}