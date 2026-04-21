#include <iostream>
#include <queue>

int maze_size, daynight_cycle;
bool maze_walls[500][500];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

bool is_oob(int y, int x)
{
    return y < 0 || y >= maze_size || x < 0 || x >= maze_size;
}

int solve()
{
    static bool visited[500][500][2][10];
    std::queue<std::pair<int, int>> q;

    visited[0][0][1][0] = 1;
    q.push({0, 0});

    int time = 0;
    int q_size;

    while (q_size = q.size())
    {
        bool is_day = time % (daynight_cycle * 2) < daynight_cycle;
        int step = time % daynight_cycle;

        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (y == maze_size - 1 && x == maze_size - 1)
                return time;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (!is_day)
                {
                    while (!is_oob(ny, nx) && maze_walls[ny][nx])
                    {
                        ny += dys[d];
                        nx += dxs[d];
                    }
                }

                if (!is_oob(ny, nx) && !maze_walls[ny][nx])
                {
                    if (!visited[ny][nx][is_day][step])
                    {
                        visited[ny][nx][is_day][step] = 1;
                        q.push({ny, nx});
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
    std::cin >> maze_size >> daynight_cycle;
    for (int y = 0; y < maze_size; y++)
    {
        for (int x = 0; x < maze_size; x++)
            std::cin >> maze_walls[y][x];
    }

    int time = solve();

    if (time == -1)
        std::cout << -1;
    else
    {
        int day_num = time / (2 * daynight_cycle) + 1;
        bool is_day = time % (2 * daynight_cycle) < daynight_cycle;
        std::cout << day_num << (is_day ? " sun" : " moon");
    }
}