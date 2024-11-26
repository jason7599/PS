#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

struct state
{
    pii pos;
    int mask;
};

int map_height, map_width;

/**
 * tiles:
 *  -2: obstacle
 *  -1: dirty
 *  x >= 0: dirty_index
 */
const int tile_obstacle = -2;
const int tile_empty = -1;
int tiles[20][20];

int solve(pii start_pos, int num_dirties)
{
    const int dy[] = {1, 0, -1, 0};
    const int dx[] = {0, 1, 0, -1};

    bool visited[1024][20][20] = {false};
    queue<state> q;
    int target_mask = (1 << num_dirties) - 1;

    visited[0][start_pos.first][start_pos.second] = true;
    q.push({start_pos, 0});

    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int y = q.front().pos.first;
            int x = q.front().pos.second;
            int mask = q.front().mask;
            q.pop();

            if (mask == target_mask)
                return time;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width
                || tiles[ny][nx] == tile_obstacle)
                    continue;
                
                int nmask = mask;
                if (tiles[ny][nx] != tile_empty)
                    nmask |= (1 << tiles[ny][nx]);

                if (!visited[nmask][ny][nx])
                {
                    visited[nmask][ny][nx] = true;
                    q.push({{ny, nx}, nmask});
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

    while (true)
    {
        cin >> map_width >> map_height;

        if (map_width == 0 && map_height == 0)
            break;
        
        pii start_pos;
        int num_dirties = 0;

        for (int y = 0; y < map_height; y++)
        {
            for (int x = 0; x < map_width; x++)
            {
                char c; cin >> c;
                switch (c)
                {
                    case 'o':
                    start_pos = {y, x};
                    // fall through

                    case '.':
                    tiles[y][x] = tile_empty;
                    break;

                    case 'x':
                    tiles[y][x] = tile_obstacle;
                    break;

                    case '*':
                    tiles[y][x] = num_dirties++;
                }
            }
        }

        cout << solve(start_pos, num_dirties) << '\n';
    }

    return 0;
}