#include <iostream>
#include <queue>

using namespace std;

int board_height, board_width;
bool board_obstacles[1000][1000];
int rect_height, rect_width;

bool is_oob(int y, int x)
{
    return y < 0 || y >= board_height || x < 0 || x >= board_width;
}

bool check_obstacles(int y, int x, int dy, int dx, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (is_oob(y, x) || board_obstacles[y][x])
            return true;
        
        y += dy;
        x += dx;
    }

    return false;
}

int solve(int start_y, int start_x, int dest_y, int dest_x)
{
    const int dys[] = {1, 0, -1, 0};
    const int dxs[] = {0, 1, 0, -1};
    
    bool visited[1000][1000] = {0};
    queue<pair<int, int>> q;

    visited[start_y][start_x] = true;
    q.push({start_y, start_x});

    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (y == dest_y && x == dest_x)
                return time;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (is_oob(ny, nx) || visited[ny][nx])
                    continue;
                
                int check_y = y;
                int check_x = x;
                int check_dy = 0;
                int check_dx = 0;
                int len;

                switch (d)
                {
                case 0: // 1, 0 : down
                    check_y += rect_height;
                    check_dx++;
                    len = rect_width;
                    break;
                case 1: // 0, 1 : right
                    check_x += rect_width;
                    check_dy++;
                    len = rect_height;
                    break;
                case 2: // -1, 0 : up
                    check_y--;
                    check_dx++;
                    len = rect_width;
                    break;
                case 3: // 0, -1 : left
                    check_x--;
                    check_dy++;
                    len = rect_height;
                }

                if (!check_obstacles(check_y, check_x, check_dy, check_dx, len))
                {
                    visited[ny][nx] = true;
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
    cin.tie(0); cout.tie(0);

    cin >> board_height >> board_width;
    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
            cin >> board_obstacles[y][x];
    }

    cin >> rect_height >> rect_width;

    int start_y, start_x, dest_y, dest_x;
    
    cin >> start_y >> start_x >> dest_y >> dest_x;
    start_y--, start_x--, dest_y--, dest_x--;

    cout << solve(start_y, start_x, dest_y, dest_x);

    return 0;
}