#include <iostream>

using namespace std;

const char map_empty = '.';
const char map_gahee = 'G';
const char map_sweet = 'S';
const char map_block = '#';

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
char map[100][100];

int max_sweets;

void solve(int y, int x, int moves_left, int sweets = 0)
{
    if (!moves_left)
    {
        if (map[y][x] == map_sweet)
            sweets++;

        if (sweets > max_sweets)
            max_sweets = sweets;
        return;
    }

    bool sweet_flag;
    if ((sweet_flag = (map[y][x] == map_sweet)))
    {
        sweets++;
        map[y][x] = map_empty;
    }

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dys[d];
        int nx = x + dxs[d];

        if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width
        || map[ny][nx] == map_block)
            continue;
        
        solve(ny, nx, moves_left - 1, sweets);
    }

    if (sweet_flag)
        map[y][x] = map_sweet;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_moves;

    cin >> map_height >> map_width >> num_moves;

    int start_y, start_x;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            if (c == map_gahee)
            {
                start_y = y;
                start_x = x;
                map[y][x] = map_empty;
            }
            map[y][x] = c;
        }
    }

    solve(start_y, start_x, num_moves);

    cout << max_sweets;

    return 0;
}