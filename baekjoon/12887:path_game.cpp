#include <iostream>
#include <algorithm>
#include <queue>

int map_len;
bool white[2][50];

int get_path_len(bool y)
{
    if (!white[y][0])
        return 1319371892;

    bool v[2][50] = {0};
    std::queue<std::pair<bool, int>> q;

    v[y][0] = 1;
    q.push({y, 0});

    int moves = 1;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            bool y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (x == map_len - 1)
                return moves;
            
            if (white[!y][x] && !v[!y][x])
            {
                v[!y][x] = 1;
                q.push({!y, x});
            }

            if (white[y][x + 1] && !v[y][x + 1])
            {
                v[y][x + 1] = 1;
                q.push({y, x + 1});
            }
        }
        moves++;
    }
}

int main()
{
    std::cin >> map_len;
    int num_whites = 0;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < map_len; x++)
        {
            char c;
            std::cin >> c;
            white[y][x] = c == '.';
            if (white[y][x])
                num_whites++;
        }
    }

    std::cout << num_whites - std::min(get_path_len(0), get_path_len(1));
}