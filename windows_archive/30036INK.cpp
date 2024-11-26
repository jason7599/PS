#include <iostream>
#include <algorithm>

using namespace std;

char board[100][100];
char colors[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int board_size;
    int num_colors;
    int num_commands;

    cin >> num_colors >> board_size >> num_commands;

    for (int i = 0; i < num_colors; i++)
        cin >> colors[i];

    int player_y;
    int player_x;

    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
        {
            char c;
            cin >> c;

            if (c == '@')
            {
                player_y = y;
                player_x = x;

                c = '.';
            }

            board[y][x] = c;
        }
    }

    int color_index = 0;
    int ink_ammount = 0;

    while (num_commands--)
    {
        char command;
        cin >> command;

        if (command == 'j')
        {
            ink_ammount++;
        }
        else if (command == 'J')
        {
            for (int y = player_y - ink_ammount; y <= player_y + ink_ammount; y++)
            {
                for (int x = player_x - ink_ammount; x <= player_x + ink_ammount; x++)
                {
                    if (abs(y - player_y) + abs(x - player_x) <= ink_ammount)
                    {
                        if (0 <= y && y < board_size && 0 <= x && x < board_size)
                        {
                            if (board[y][x] != '.')
                                board[y][x] = colors[color_index];
                        }
                    }
                }
            }

            ink_ammount = 0;
            color_index = (color_index + 1) % num_colors;
        }
        else
        {
            int ny = player_y;
            int nx = player_x;

            switch (command)
            {
                case 'U':
                    ny--;
                    break;
                case 'D':
                    ny++;
                    break;
                case 'L':
                    nx--;
                    break;
                case 'R':
                    nx++;
                    break;
            }

            if (0 <= ny && ny < board_size && 0 <= nx && nx < board_size && board[ny][nx] == '.')
            {
                player_y = ny;
                player_x = nx;
            }
        }
    }

    board[player_y][player_x] = '@';

    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
            cout << board[y][x];
        cout << '\n';
    }

    return 0;
}