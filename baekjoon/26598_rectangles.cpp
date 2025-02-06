#include <bits/stdc++.h>

int board_height, board_width;
char board[1000][1000];
bool checked[1000][1000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
            std::cin >> board[y][x];
    }

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (checked[y][x])
                continue;

            char c = board[y][x];

            if ((y && board[y - 1][x] == c)
            || (x && board[y][x - 1] == c))
                goto babo;

            checked[y][x] = 1;

            int width = 1;
            while (x + width < board_width && board[y][x + width] == c)
            {
                if (y && board[y - 1][x + width] == c)
                    goto babo;
                checked[y][x + width++] = 1;
            }

            for (int yy = y + 1; yy < board_height && board[yy][x] == c; yy++)
            {
                checked[yy][x] = 1;
                for (int i = 1; i < width; i++)
                {
                    if (board[yy][x + i] != c)
                        goto babo;
                    
                    checked[yy][x + i] = 1;
                }
            }
        }
    }

    std::cout << "dd\n";
    return 0;

babo:
    std::cout << "BaboBabo\n";
}