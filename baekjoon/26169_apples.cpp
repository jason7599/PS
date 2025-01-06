#include <bits/stdc++.h>

int height, width;
int board[5][5];

const int B_NONE = 0;
const int B_APPLE = 1;
const int B_WALL = -1;

const int MOVES[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool can_eat(int y, int x, int cnt, int moves)
{
    if (board[y][x] == B_APPLE)
    {
        if (!--cnt)
            return 1;
    }

    if (!moves)
        return 0;
    
    int og = board[y][x];

    board[y][x] = B_WALL;

    for (int d = 0; d < 4; d++)
    {
        int ny = y + MOVES[d][0];
        int nx = x + MOVES[d][1];

        if (ny < 0 || ny == 5 || nx < 0 || nx == 5
        || board[ny][nx] == B_WALL)
            continue;
        
        if (can_eat(ny, nx, cnt, moves - 1))
            return 1;
    }

    board[y][x] = og;
    return 0;
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

    std::cout << can_eat(start_y, start_x, 2, 3);
}