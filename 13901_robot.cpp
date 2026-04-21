#include <iostream>

using namespace std;

int map_height, map_width;
int map[1000][1000];

const int m_obstacle = -1;
const int m_empty = 0;

int moves[4];

// u, d, l, r
const int dys[] = {-1, 1, 0, 0};
const int dxs[] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> map_height >> map_width;

    int num_obstacles;
    cin >> num_obstacles;

    while (num_obstacles--)
    {
        int y, x;
        cin >> y >> x;
        map[y][x] = m_obstacle;
    }

    int bot_y, bot_x;
    cin >> bot_y >> bot_x;

    for (int i = 0; i < 4; i++)
    {
        cin >> moves[i];
        moves[i]--;
    }

    int t = 1;
    int move_idx = 0;
    while (1)
    {
        map[bot_y][bot_x] = t++;

        bool end = 1;
        for (int i = 0; i < 4; i++)
        {
            int nmove_idx = (move_idx + i) % 4;

            int ny = bot_y + dys[moves[nmove_idx]];
            int nx = bot_x + dxs[moves[nmove_idx]];

            if (0 <= ny && ny < map_height && 0 <= nx && nx < map_width
            && map[ny][nx] == m_empty)
            {
                move_idx = nmove_idx;
                bot_y = ny;
                bot_x = nx;
                end = 0;
                break;
            }
        }

        if (end)
            break;
    }

    cout << bot_y << ' ' << bot_x;
    return 0;
}