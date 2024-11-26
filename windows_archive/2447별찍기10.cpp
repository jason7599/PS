#include <iostream>

using namespace std;

char board[2187][2187];

void draw(int size, int row, int col)
{
    if (size == 1)
    {
        board[row][col] = '*';
        return;
    }

    int n_size = size / 3;
    for (int y = 0; y < 3; y++)
    {
        int n_row = row + n_size * y;
        for (int x = 0; x < 3; x++)
        {
            int n_col = col + n_size * x;
    
            if (y == 1 && x == 1)
            {
                for (int i = n_row; i < n_row + n_size; i++)
                {
                    for (int j = n_col; j < n_col + n_size; j++)
                        board[i][j] = ' ';
                } 
            }
            else
                draw(n_size, n_row, n_col);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int size; cin >> size;

    draw(size, 0, 0);

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
            cout << board[row][col];
        cout << '\n';
    }

    return 0;
}