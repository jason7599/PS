#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int map_height, map_width;
bool map_walls[20][20];

const int dys[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dxs[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};

bool oob(int y, int x)
{
    return y < 0 || y >= map_height || x < 0 || x >= map_width; 
}

int solve(pii init_a_pos, pii init_b_pos)
{
    bool visited[20][20][20][20] = {false}; 
    queue<pair<pii, pii>> q;

    visited[init_a_pos.first][init_a_pos.second][init_b_pos.first][init_b_pos.second] = true;
    q.push({init_a_pos, init_b_pos});

    int time = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            pii a_pos = q.front().first;
            pii b_pos = q.front().second;
            q.pop();

            if (a_pos == init_b_pos && b_pos == init_a_pos)
                return time;

            for (int d0 = 0; d0 < 9; d0++)
            {
                int a_ny = a_pos.first + dys[d0];
                int a_nx = a_pos.second + dxs[d0];

                if (oob(a_ny, a_nx) || map_walls[a_ny][a_nx])
                    continue;

                pii a_npos = {a_ny, a_nx};

                for (int d1 = 0; d1 < 9; d1++)
                {
                    int b_ny = b_pos.first + dys[d1];
                    int b_nx = b_pos.second + dxs[d1];

                    if (oob(b_ny, b_nx) || map_walls[b_ny][b_nx])
                        continue;

                    pii b_npos = {b_ny, b_nx};

                    if (b_npos == a_npos
                    || (a_npos == b_pos && b_npos == a_pos)
                    || visited[a_ny][a_nx][b_ny][b_nx])
                        continue;
                    
                    visited[a_ny][a_nx][b_ny][b_nx] = true;
                    q.push({a_npos, b_npos});
                }
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    cin >> map_height >> map_width;

    pii a_pos, b_pos;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            cin >> c;
            
            if (c == 'A')
                a_pos = {y, x};
            else if (c == 'B')
                b_pos = {y, x};
            else if (c == 'X')
                map_walls[y][x] = true;
        }
    }

    cout << solve(a_pos, b_pos);

    return 0;
}