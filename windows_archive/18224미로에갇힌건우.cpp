#include <iostream>
#include <queue>

using namespace std;

int map_size, daynight_cycle;
bool map_obstacles[500][500];
bool visited[500][500][20];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

bool oob(int y, int x)
{
    return y < 0 || y >= map_size || x < 0 || x >= map_size;
}

bool is_sun(int time)
{
    return (time / daynight_cycle) % 2 == 0;
}

int solve()
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    visited[0][0][0] = true;

    // queue<pair<int,int>> visited_q;

    int time = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            int sun = is_sun(time);
            q.pop();

            if (y == map_size - 1 && x == map_size - 1)
                return time;
            
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (oob(ny, nx))
                    continue;

                if (map_obstacles[ny][nx])
                {
                    if (sun)
                        continue;
                    
                    while (!oob(ny, nx) && map_obstacles[ny][nx])
                    {
                        ny += dys[d];
                        nx += dxs[d];
                    }
                }

                if (!oob(ny, nx) && !visited[ny][nx][time % daynight_cycle])
                {
                    visited[ny][nx][time % daynight_cycle] = true;
                    q.push({ny, nx});
                }
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> map_size >> daynight_cycle;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            cin >> map_obstacles[y][x];
        }
    }

    int ans = solve();

    if (ans == -1)
        cout << -1;
    else
        cout << (ans) / daynight_cycle << ' ' << (is_sun(ans) ? "sun" : "moon");

    return 0;
}