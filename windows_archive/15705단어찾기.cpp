#include <iostream>
#include <string>

using namespace std;

int board_height, board_width;
char board[100][100];

const int dys[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dxs[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string target;
    cin >> target;

    cin >> board_height >> board_width;
    for (int y = 0; y < board_height; y++)
        for (int x = 0; x < board_width; x++)
            cin >> board[y][x];

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (board[y][x] != target[0])
                continue;

            for (int d = 0; d < 8; d++)
            {
                int ey = y + dys[d] * (target.length() - 1);
                int ex = x + dxs[d] * (target.length() - 1); 

                if (ey < 0 || ey >= board_height || ex < 0 || ex >= board_width)
                    continue;
                
                bool good = 1;
                for (int i = target.length() - 1; i > 0; i--)
                {
                    if (target[i] != board[ey][ex])
                    {
                        good = 0;
                        break;
                    }

                    ey -= dys[d];
                    ex -= dxs[d];
                }

                if (good)
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}