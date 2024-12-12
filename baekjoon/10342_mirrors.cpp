#include <iostream>

const int DYS[] = {1, 0, -1, 0};
const int DXS[] = {0, 1, 0, -1};

const int D_DOWN = 0;
const int D_RIGHT = 1;
const int D_UP = 2;
const int D_LEFT = 3;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    for (int tc = 1;; tc++)
    {
        int maze_h, maze_w;
        std::cin >> maze_w >> maze_h;

        char maze[20][20];

        if (maze_h + maze_w == 0)
            break;

        int y, x;

        for (int i = 0; i < maze_h; i++)
        {
            for (int j = 0; j < maze_w; j++)
            {
                std::cin >> maze[i][j];
                if (maze[i][j] == '*')
                    y = i, x = j;
            }
        }

        int dir;
        if (!y)
            dir = D_DOWN;
        else
        {
            if (!x)
                dir = D_RIGHT;
            else if (x == maze_w - 1)
                dir = D_LEFT;
            else
                dir = D_UP;
        }

        while (1)
        {
            y += DYS[dir];
            x += DXS[dir];

            if (!y || y == maze_h - 1 || !x || x == maze_w - 1)
            {
                maze[y][x] = '&';
                break;
            }

            if (maze[y][x] == '/')
            {
                switch (dir)
                {
                case D_UP: dir = D_RIGHT; break;
                case D_DOWN: dir = D_LEFT; break;
                case D_LEFT: dir = D_DOWN; break;
                case D_RIGHT: dir = D_UP; break;
                }
            }
            else if (maze[y][x] == '\\')
            {
                switch (dir)
                {
                case D_UP: dir = D_LEFT; break;
                case D_DOWN: dir = D_RIGHT; break;
                case D_LEFT: dir = D_UP; break;
                case D_RIGHT: dir = D_DOWN; break;
                }
            }
        }

        std::cout << "HOUSE " << tc << '\n';
        for (int y = 0; y < maze_h; y++)
        {
            for (int x = 0; x < maze_w; x++)
                std::cout << maze[y][x];
            std::cout << '\n';
        }
    }
}