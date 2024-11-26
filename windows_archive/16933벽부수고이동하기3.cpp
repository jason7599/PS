#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int map_height, map_width;
bool map_walls[1'000][1'000];

const int dys[] = {1, 0, -1, 0, 0};
const int dxs[] = {0, 1, 0, -1, 0};

int solve(int num_breaks)
{
    static bool visited[1'000][1'000][11][2]; // [0]: day, [1]: night
    queue<pair<pii, int>> q; // <<y, x>, breaks>

    visited[0][0][num_breaks][0] = true;
    q.push({{0, 0}, num_breaks});

    int time = 1;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        bool is_day = time % 2 == 1;

        while (q_size--)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int breaks = q.front().second;
            q.pop();

            if (y == map_height - 1 && x == map_width - 1)
                return time;
            
            for (int d = 0; d < 5; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width)
                    continue;
                
                if (map_walls[ny][nx] && d != 5)
                {
                    if (breaks > 0 && is_day)
                    {
                        if (!visited[ny][nx][breaks - 1][!is_day])
                        {
                            visited[ny][nx][breaks - 1][!is_day] = true;
                            q.push({{ny, nx}, breaks - 1});
                        }
                    }
                }
                else
                {
                    if (!visited[ny][nx][breaks][!is_day])
                    {
                        visited[ny][nx][breaks][!is_day] = true;
                        q.push({{ny, nx}, breaks});
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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_breaks;
    cin >> map_height >> map_width >> num_breaks;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            map_walls[y][x] = c == '1';
        }
    }

    cout << solve(num_breaks);

    return 0;
}