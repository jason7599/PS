#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int map_height, map_width;
bool obstacles[200][200];

int count_paths(int y, int x)
{
    static int dp[200][200];

    if (y == map_height || x == map_width || obstacles[y][x]) 
        return 0;

    if (y == map_height - 1 && x == map_width - 1)
        return 1;
    
    if (dp[y][x])
        return dp[y][x] == -1 ? 0 : dp[y][x];

    dp[y][x] = (count_paths(y + 1, x) % mod + count_paths(y, x + 1) % mod) % mod;
    
    if (!dp[y][x])
    {
        dp[y][x] = -1;
        return 0;
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            cin >> c;
            obstacles[y][x] = c == 'X';
        }
    }

    cout << count_paths(0, 0);
    
    return 0;
}