#include <iostream>
#include <queue>

struct state
{
    int y;
    int x;
    int num_breaks;    
};

int map_height, map_width;
bool map_walls[1000][1000];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int solve(int max_breaks)
{
    static bool v[11][1000][1000];
    std::queue<state> q;

    v[max_breaks][0][0] = 1;
    q.push({0, 0, max_breaks});

    int time = 1;
    int q_size;
    while (q_size = q.size())
    {
        while (q_size--)
        {
            auto [y, x, num_breaks] = q.front();
            q.pop();

            if (y == map_height - 1 && x == map_width - 1)
                return time;
            
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width)
                    continue;
                
                if (map_walls[ny][nx])
                {
                    if (num_breaks && !v[num_breaks - 1][ny][nx])
                    {
                        v[num_breaks - 1][ny][nx] = 1;
                        q.push({ny, nx, num_breaks - 1});
                    }
                }
                else
                {
                    if (!v[num_breaks][ny][nx])
                    {
                        v[num_breaks][ny][nx] = 1;
                        q.push({ny, nx, num_breaks});
                    }
                }
            }
        }
        time++;
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int max_breaks;
    std::cin >> map_height >> map_width >> max_breaks;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            std::cin >> c;
            map_walls[y][x] = c == '1';
        }
    }

    std::cout << solve(max_breaks);
}