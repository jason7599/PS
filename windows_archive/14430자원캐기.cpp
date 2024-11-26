#include <iostream>
#include <algorithm>

using namespace std;

int depth, width;
bool resources[300][300];

int solve(int y, int x)
{
    static int dp[300][300];

    if (dp[y][x])
        return max(dp[y][x], 0);
    
    int res = 0;

    if (y + 1 == depth)
    {
        if (x + 1 != width)
            res = solve(y, x + 1);
    }
    else
    {
        res = solve(y + 1, x);

        if (x + 1 != width)
            res = max(res, solve(y, x + 1));
    }

    res += resources[y][x];

    dp[y][x] = res ? res : -1;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> depth >> width;

    for (int y = 0; y < depth; y++)
        for (int x = 0; x < width; x++)
            cin >> resources[y][x];
    
    cout << solve(0, 0);

    return 0;
}