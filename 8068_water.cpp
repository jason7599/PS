#include <iostream>
#include <vector>
#include <algorithm>

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
int terrain[100][100];

int solve(int y, int x)
{
    bool visited[100][100] = {0};
    std::vector<std::pair<int, int>> q;

    visited[y][x] = 1;
    q.push_back({y, x});

    int height = terrain[y][x];
    int fill_height = 1e9;

    size_t i = 0;
    size_t q_size;
    while (i < (q_size = q.size()))
    {
        while (i < q_size)
        {
            y = q[i].first;
            x = q[i++].second;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (terrain[ny][nx] > height)
                    fill_height = std::min(fill_height, terrain[ny][nx]);
                else if (!visited[ny][nx])
                {
                    if (!ny || ny == map_height - 1 || !nx || nx == map_width - 1)
                        return 0;
                    
                    visited[ny][nx] = 1;
                    q.push_back({ny, nx});
                }
            }
        }
    }

    int res = 0;
    for (auto [y, x] : q)
    {
        res += fill_height - terrain[y][x];
        terrain[y][x] = fill_height;
    }
    return res;
}

int main()
{
    std::cin >> map_height >> map_width;
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
            std::cin >> terrain[y][x];
    }

    int ans = 0;
    for (int y = 1; y < map_height - 1; y++)
    {
        for (int x = 1; x < map_width - 1; x++)
            ans += solve(y, x);
    }

    std::cout << ans;
}