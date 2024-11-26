#include <iostream>

using namespace std;

int map_size;
int tiles[100][100];

int solve(int y = 0, int x = 0)
{
    static int dp[100][100]; // -1 = 길 없음

    if (dp[y][x])
    {
        if (dp[y][x] == -1)
            return 0;
        return dp[y][x];
    }

    if (y == map_size - 1 && x == map_size - 1)
        return 1;

    if (tiles[y][x] == 0)
    {
        dp[y][x] = -1;
        return 0;
    }

    int res = 0;

    if (y + tiles[y][x] < map_size)
        res += solve(y + tiles[y][x], x);
    if (x + tiles[y][x] < map_size)
        res += solve(y, x + tiles[y][x]);
    
    if (res)
        return dp[y][x] = res;
    
    dp[y][x] = -1;
    return 0;
}

int main()
{
    cin >> map_size;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
            cin >> tiles[y][x];
    }

    cout << solve();

    return 0;
}