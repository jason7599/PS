#include <iostream>
#include <queue>

struct Pos
{
    int y;
    int x;
};

const int DYS[] = {1, 0, -1, 0};
const int DXS[] = {0, 1, 0, -1};

const int MAX_MAP_SIZE = 500;

int map_height, map_width;
int jump_grid[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE];

int solve()
{
    std::queue<Pos> q ({{0, 0}});
    visited[0][0] = 1;

    int moves = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            const auto [y, x] = q.front();
            q.pop();

            if (y == map_height - 1 && x == map_width - 1)
                return moves;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + DYS[d] * jump_grid[y][x];
                int nx = x + DXS[d] * jump_grid[y][x];

                if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width
                || visited[ny][nx])
                    continue;
                
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
        moves++;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            std::cin >> c;
            jump_grid[y][x] = c - '0';
        }
    }

    int t = solve();
    if (t == -1)
        std::cout << "IMPOSSIBLE";
    else
        std::cout << t;
}