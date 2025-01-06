#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<bool>>& banner, int y, int x)
{
    banner[y][x] = 0;
    for (int ny = y - 1; ny <= y + 1; ny++)
    {
        for (int nx = x - 1; nx <= x + 1; nx++)
        {
            if (ny < 0 || ny == banner.size() || nx < 0 || nx == banner[0].size())
                continue;
            
            if (banner[ny][nx])
                dfs(banner, ny, nx);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int banner_height, banner_width;
    std::cin >> banner_height >> banner_width;

    std::vector<std::vector<bool>> banner(banner_height, std::vector<bool>(banner_width));

    for (int y = 0; y < banner_height; y++)
    {
        for (int x = 0; x < banner_width; x++)
        {
            bool t;
            std::cin >> t;
            banner[y][x] = t;
        }
    }

    int n_letters = 0;

    for (int y = 0; y < banner_height; y++)
    {
        for (int x = 0; x < banner_width; x++)
        {
            if (banner[y][x])
            {
                n_letters++;
                dfs(banner, y, x);
            }
        }
    }

    std::cout << n_letters;
}