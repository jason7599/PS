#include <iostream>
#include <queue>

using pii = std::pair<int, int>;

int map_height, map_width;
bool map_walls[1'000][1'000];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

struct State
{
    pii pos;
    int num_breaks;
};

int solve(int num_breaks)
{
    static bool visited[2][11][1'000][1'000]; // [0]: night, [1]: day
    std::queue<State> q; // <<y, x>, breaks>

    visited[1][num_breaks][0][0] = 1;
    q.push({{0, 0}, num_breaks});

    int time = 1;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        bool is_day = time % 2;

        while (q_size--)
        {
            int y = q.front().pos.first;
            int x = q.front().pos.second;
            int breaks = q.front().num_breaks;
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
                    if (breaks > 0 && is_day)
                    {
                        if (!visited[!is_day][breaks - 1][ny][nx])
                        {
                            visited[!is_day][breaks - 1][ny][nx] = 1;
                            q.push({{ny, nx}, breaks - 1});
                        }
                    }
                }
                else
                {
                    if (!visited[!is_day][breaks][ny][nx])
                    {
                        visited[!is_day][breaks][ny][nx] = 1;
                        q.push({{ny, nx}, breaks});
                    }
                }
            }

            if (!visited[!is_day][breaks][y][x])
            {
                visited[!is_day][breaks][y][x] = 1;
                q.push({{y, x}, breaks});
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int num_breaks;
    std::cin >> map_height >> map_width >> num_breaks;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; 
            std::cin >> c;
            map_walls[y][x] = c == '1';
        }
    }

    std::cout << solve(num_breaks);

    return 0;
}