#include <iostream>

const int MAX_MAZE_SIZE = 300;

int maze_size;
bool maze_walls[MAX_MAZE_SIZE][MAX_MAZE_SIZE];

bool can_win(int y, int x, int max_move_dist)
{
    // 0: not cached, 1: win, -1: FUCKING lose BBBITCH
    static char cache[MAX_MAZE_SIZE][MAX_MAZE_SIZE][MAX_MAZE_SIZE + 1];

    if (cache[y][x][max_move_dist])
        return cache[y][x][max_move_dist] == 1;

    bool res = 0;

    for (int d = 0; d < 2; d++)
    {
        int dy = d, dx = !d;

        for (int dist = 1; dist <= max_move_dist; dist++)
        {
            if (max_move_dist % dist == 0)
            {
                if (dist != max_move_dist
                && (dist != 1 || max_move_dist != 1))
                {
                    if (!can_win(y, x, dist))
                    {
                        res = 1;
                        break;
                    }
                }
            }

            int ny = y + dy * dist;
            int nx = x + dx * dist;

            if (ny < maze_size && nx < maze_size
            && !maze_walls[ny][nx])
            {
                if (!can_win(ny, nx, max_move_dist))
                {
                    res = 1;
                    break;
                }
            }
        }
    }

    cache[y][x][max_move_dist] = res ? 1 : -1;
    return res;
}

int main()
{
    int max_move_dist;
    std::cin >> maze_size >> max_move_dist;

    for (int y = 0; y < maze_size; y++)
    {
        for (int x = 0; x < maze_size; x++)
            std::cin >> maze_walls[y][x];
    }

    std::cout << can_win(0, 0, max_move_dist);
}