#include <iostream>

using namespace std;

int dp[15][15];

int f(int y, int x)
{
    if (dp[y][x])
        return dp[y][x];
    if (!y)
        return dp[y][x] = x;
    if (x == 1)
        return dp[y][x] = 1;
    return dp[y][x] = f(y, x - 1) + f(y - 1, x);
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int y, x; cin >> y >> x;
        cout << f(y, x) << '\n';
    }
}