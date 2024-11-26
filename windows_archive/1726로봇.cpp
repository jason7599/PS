#include <iostream>
#include <queue>

using namespace std;

// e s w n
const int dys[] = {0, 1, 0, -1};
const int dxs[] = {1, 0, -1, 0};

struct BState
{
    int y, x, dir;

    bool operator== (const BState& other) const 
    {
        return y == other.y && x == other.x && dir == other.dir;
    }
};

int map_height, map_width;
bool map_obstacles[100][100];

BState get_bstate()
{
    // e w s n => e s w n
    static int dt[] = {0, 2, 1, 3};

    int y, x, d;
    cin >> y >> x >> d;
    y--, x--, d--;

    return {y, x, dt[d]};
}

int get_min_commands(BState src_state, BState dest_state)
{
    bool visited[100][100][4] = {false};
    queue<BState> q;

    visited[src_state.y][src_state.x][src_state.dir] = true;
    q.push(src_state);

    int commands = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            if (q.front() == dest_state)
                return commands;

            int y = q.front().y;
            int x = q.front().x;
            int dir = q.front().dir;
            q.pop();

            if (!visited[y][x][(dir + 1) % 4])
            {
                visited[y][x][(dir + 1) % 4] = true;
                q.push({y, x, (dir + 1) % 4});
            }
            if (!visited[y][x][(dir + 3) % 4])
            {
                visited[y][x][(dir + 3) % 4] = true;
                q.push({y, x, (dir + 3) % 4});
            }

            int ny = y;
            int nx = x;
            for (int i = 0; i < 3; i++)
            {
                ny += dys[dir];
                nx += dxs[dir];

                if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width
                || map_obstacles[ny][nx])
                    break;
                
                if (!visited[ny][nx][dir])
                {
                    visited[ny][nx][dir] = true;
                    q.push({ny, nx, dir});
                }
            }

        }

        commands++;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_height >> map_width;
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
            cin >> map_obstacles[y][x];
    }

    BState src_state = get_bstate();
    BState dest_state = get_bstate();

    cout << get_min_commands(src_state, dest_state);
}