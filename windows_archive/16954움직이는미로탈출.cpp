#include <iostream>
#include <queue>

using namespace std;

const int board_size = 8;
bool init_walls[board_size][board_size];

bool is_oob(int y, int x)
{
    return y < 0 || y >= board_size || x < 0 || x >= board_size;
}

bool check_wall_at(int y, int x, int shift_dist)
{
    if ((y -= shift_dist) < 0)
        return false;
    return init_walls[y][x];
}

int main()
{
    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
        {
            char c; cin >> c;
            init_walls[y][x] = c == '#';
        }
    }

    const int eight = 8;
    struct trav { int y, x, shift; };

    queue<trav> queue;
    bool visited[board_size][board_size][eight] = {false};

    queue.push({board_size - 1, 0, 0});
    visited[board_size - 1][0][0] = true;

    while (!queue.empty())
    {
        trav cur = queue.front(); queue.pop();

        int next_shift = cur.shift + 1;
        
        for (int ny = cur.y - 1; ny <= cur.y + 1; ny++)
        {
            for (int nx = cur.x - 1; nx <= cur.x + 1; nx++)
            {
                if (is_oob(ny, nx) || visited[ny][nx][next_shift] || check_wall_at(ny, nx, cur.shift) || check_wall_at(ny, nx, next_shift))
                    continue;

                if (next_shift >= eight || (ny == 0 && nx == board_size - 1))
                    goto good;

                visited[ny][nx][next_shift] = true;
                queue.push({ny, nx, next_shift});
            }
        }
    }

    cout << 0;
    return 0;

good:
    cout << 1;
}