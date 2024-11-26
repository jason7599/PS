#include <iostream>
#include <queue>

using namespace std;

int map_height, map_width;
char map[50][50];

const char map_empty = '.';
const char map_wall = '#';
const char map_exit = '1';

bool has_key(char key_mask, char key)
{
    return key_mask & (1 << (key - 'a')); 
}

char add_key(char key_mask, char key)
{
    return key_mask | (1 << (key - 'a'));
}

bool has_key_for_door(char key_mask, char door)
{
    return key_mask & (1 << (door - 'A'));
}

bool is_key(char c)
{
    return 'a' <= c && c <= 'f';
}

int solve(int start_y, int start_x)
{
    struct State
    {
        int y, x;
        char key_mask;
    };

    const int dy[] = {1, 0, -1, 0};
    const int dx[] = {0, 1, 0, -1};

    static bool visited[50][50][64];
    queue<State> q;

    visited[start_y][start_x][0] = true;
    q.push({start_y, start_x, 0});

    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        time++;
        while (q_size--)
        {
            // print_state(q.front());

            int y = q.front().y;
            int x = q.front().x;
            char key_mask = q.front().key_mask;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];
                char nkey_mask = key_mask;

                if (ny == -1 || ny == map_height || nx == -1 || nx == map_width)
                    continue;

                if (map[ny][nx] == map_exit)
                    return time;

                if (map[ny][nx] == map_wall)
                    continue;
                
                if (is_key(map[ny][nx]))
                {
                    // cout << "is key " << map[ny][nx] << '\n';
                    // cout << (int)key_mask << '\n';
                    if (!has_key(key_mask, map[ny][nx]))
                        nkey_mask = add_key(key_mask, map[ny][nx]);
                    // cout << (int)key_mask << '\n';
                }
                else if (map[ny][nx] != map_empty)
                {
                    if (!has_key_for_door(key_mask, map[ny][nx]))
                        continue;
                }

                if (!visited[ny][nx][nkey_mask])
                {
                    visited[ny][nx][nkey_mask] = true;
                    q.push({ny, nx, nkey_mask});
                }
            }
        }
    }

    return - 1;
}

int main()
{
    cin >> map_height >> map_width;

    int start_y, start_x;
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char t; cin >> t;
            if (t == '0')
            {
                start_y = y;
                start_x = x;
                map[y][x] = map_empty;
            }
            else
                map[y][x] = t;
        }
    }

    cout << solve(start_y, start_x);
}