#include <bits/stdc++.h>

int map_height, map_width;
int map[300][300];

int solve(int y, int x)
{
    static int cache[300][300];

    if (y == map_height - 1 && x == map_width - 1)
        return 0;

    if (cache[y][x])
        return std::max(cache[y][x], 0);

    int min_stops = INT_MAX;

    static const int MOVES[][2] = {{1, 0}, {0, 1}};

    for (int m = 0; m < 2; m++)
    {
        int ny = y;
        int nx = x;
        for (int d = 0; d < map[y][x]; d++)
        {
            ny += MOVES[m][0];
            nx += MOVES[m][1];

            if (ny == map_height || nx == map_width)
                break;
            
            min_stops = std::min(min_stops, solve(ny, nx));
        }
    }

    return cache[y][x] = min_stops + 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
            std::cin >> map[y][x];
    }

    std::cout << solve(0, 0);
}