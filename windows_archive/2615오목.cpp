#include <iostream>

using namespace std;

const int b_size = 19;

int board[b_size][b_size];

// down, right, downright, downleft
const int dys[] = {1, 0, 1, 1};
const int dxs[] = {0, 1, 1, -1};

bool checked[b_size][b_size][4]; 

int get_len(int y, int x, int d)
{
    int piece = board[y][x];
    int len = 0;

    while (y < b_size && x >= 0 && x < b_size && board[y][x] == piece)
    {
        checked[y][x][d] = true;
        len++;
        
        y += dys[d];
        x += dxs[d];
    }

    return len;
}

int main()
{
    for (int y = 0; y < b_size; y++)
    {
        for (int x = 0; x < b_size; x++)
        {
            cin >> board[y][x];
        }
    }

    for (int y = 0; y < b_size; y++)
    {
        for (int x = 0; x < b_size; x++)
        {
            if (board[y][x])
            {
                for (int d = 0; d < 4; d++)
                {
                    if (!checked[y][x][d])
                    {
                        if (get_len(y, x, d) == 5)
                        {
                            cout << board[y][x] << '\n';
                            if (d == 3) // fuck
                                cout << y + 5 << ' ' << x - 3;
                            else
                                cout << y + 1 << ' ' << x + 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}