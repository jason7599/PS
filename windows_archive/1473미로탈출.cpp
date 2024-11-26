#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

const char door_all = 'A';
const char door_none = 'B';
const char door_vertical = 'C';
const char door_horizontal = 'D';

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int maze_height, maze_width;
char maze_doors[7][7];
bool visited[7][7][16384];

int rotate(int y, int x, int rot_mask)
{
    return rot_mask ^ (1 << y) ^ (1 << (x + 7));
}

bool is_flipped(int y, int x, int rot_mask)
{
    return ((rot_mask >> y) & 1) + ((rot_mask >> (x + 7)) & 1) == 1;
}

char get_door(int y, int x, int rot_mask)
{
    bool flip = is_flipped(y, x, rot_mask);

    switch (maze_doors[y][x])
    {
        case door_all:
        return door_all;

        case door_none:
        return door_none;

        case door_vertical:
        if (flip)
            return door_horizontal; 
        return door_vertical;
    
        case door_horizontal:
        if (flip)
            return door_vertical;
        return door_horizontal;
    }

    return '@';
}

bool can_move(int y, int x, int d, int rot_mask)
{
    int ny = y + dys[d];
    int nx = x + dxs[d];

    if (ny < 0 || ny >= maze_height || nx < 0 || nx >= maze_width)
        return false;
    
    char start_door = get_door(y, x, rot_mask);
    char dest_door = get_door(ny, nx, rot_mask);

    if (start_door == door_none || dest_door == door_none)
        return false;

    if (d % 2 == 0) // vertical movement
        return start_door != door_horizontal && dest_door != door_horizontal;
    else // horizontal movement
        return start_door != door_vertical && dest_door != door_vertical;
}

int solve()
{
    queue<pair<pii, int>> q;

    q.push({{0, 0}, 0});
    visited[0][0][0] = true;

    int time = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int rot_mask = q.front().second;
            q.pop();

            if (y == maze_height - 1 && x == maze_width - 1)
                return time;
            
            for (int d = 0; d < 4; d++)
            {
                if (can_move(y, x, d, rot_mask))
                {
                    int ny = y + dys[d];
                    int nx = x + dxs[d];

                    if (!visited[ny][nx][rot_mask])
                    {
                        visited[ny][nx][rot_mask] = true;
                        q.push({{ny, nx}, rot_mask});
                    }
                }
            }

            int nrot_mask = rotate(y, x, rot_mask);
            if (!visited[y][x][nrot_mask])
            {
                visited[y][x][nrot_mask] = true;
                q.push({{y, x}, nrot_mask});
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    cin >> maze_height >> maze_width;

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
            cin >> maze_doors[y][x];
    }

    cout << solve();

    return 0;
}