#include <iostream>
#include <algorithm>
#include <optional>

const int MAX_GRID_SIZE = 100;

int g_height, g_width;
int grid_vals[MAX_GRID_SIZE][MAX_GRID_SIZE];

int get_max_value(int y, int x)
{
    static std::optional<int> memo[MAX_GRID_SIZE][MAX_GRID_SIZE];

    if (memo[y][x].has_value())
        return memo[y][x].value();

    int res = grid_vals[y][x];

    int t = 0;
    if (y + 1 != g_height)
        t = get_max_value(y + 1, x);
    if (x + 1 != g_width)
        t = std::max(t, get_max_value(y, x + 1));
    
    res += t;
    
    memo[y][x] = res;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> g_height >> g_width;

    for (int y = 0; y < g_height; y++)
    {
        for (int x = 0; x < g_width; x++)
            std::cin >> grid_vals[y][x];
    }

    std::cout << get_max_value(0, 0);
}