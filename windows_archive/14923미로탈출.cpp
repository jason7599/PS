#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int maze_height, maze_width;
bool maze_walls[1000][1000];

int solve(pii start, pii dest)
{
    const int dy[] = {1, 0, -1, 0};
    const int dx[] = {0, 1, 0, -1};

    static bool visited[1000][1000][2]; // 0: hasn't used staff
    queue<pair<pii, bool>> q;

    visited[start.first][start.second][0] = true;
    q.push({start, false});

    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        time++;
        while (q_size--)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            bool staff_used = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= maze_height
                || nx < 0 || nx >= maze_width
                || visited[ny][nx][staff_used])
                    continue;

                if (!staff_used && maze_walls[ny][nx] && !visited[ny][nx][1])
                {
                    if (make_pair(ny, nx) == dest)
                        return time;

                    visited[ny][nx][1] = true;
                    q.push({{ny, nx}, true});
                }
                else if (!maze_walls[ny][nx] && !visited[ny][nx][staff_used])
                {
                    if (make_pair(ny, nx) == dest)
                        return time;
                    
                    visited[ny][nx][staff_used] = true;
                    q.push({{ny, nx}, staff_used});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int y, x;

    cin >> maze_height >> maze_width;
    cin >> y >> x;
    pii start = {y - 1, x - 1};
    cin >> y >> x;
    pii dest = {y - 1, x - 1};

    for (y = 0; y < maze_height; y++)
    {
        for (x = 0; x < maze_width; x++)
            cin >> maze_walls[y][x];
    }

    cout << solve(start, dest);
    return 0;
}