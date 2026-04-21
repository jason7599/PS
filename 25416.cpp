#include <iostream>
#include <queue>

int board[5][5];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int solve(int start_y, int start_x)
{
    bool visited[5][5] = {0};
    std::queue<std::pair<int, int>> q;

    visited[start_y][start_x] = 1;
    q.push({start_y, start_x});

    int moves = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (board[y][x] == 1)
                return moves;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (0 <= ny && ny < 5 && 0 <= nx && nx < 5
                && board[ny][nx] != -1 && !visited[ny][nx])
                {
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }
        moves++;
    }

    return -1;
}

int main()
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
            std::cin >> board[y][x];
    }

    int start_y, start_x;
    std::cin >> start_y >> start_x;

    std::cout << solve(start_y, start_x);
}