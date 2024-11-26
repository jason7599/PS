#include <iostream>

using namespace std;

bool board[10][10];
int cover_count;
int ans = -1;

// int get_max_size(int row, int col)
// {

// }

bool test_size(int _row, int _col, int size)
{
    if (_row + size >= 10 || _col + size >= 10)
        return false;

    for (int row = _row; row <= _row + size; row++)
    {
        for (int col = _col; col <= _col + size; col++)
            if (!board[row][col])
                return false;
    }

    return true;
}

void set_val(int _row, int _col, int size, bool val)
{
    for (int row = _row; row <= _row + size; row++)
    {
        for (int col = _col; col <= _col + size; col++)
            board[row][col] = val;
    }
}

void solve(int pos_index = 0)
{
    static int pieces[] = {5, 5, 5, 5, 5};
    static int pieces_left = 25;
    static int covered;

    if (covered == cover_count)
    {
        if (ans == -1 || 25 - pieces_left < ans)
            ans = 25 - pieces_left;
        return;
    }

    if (pos_index == 100 || pieces_left == 0)
        return;

    int row = pos_index / 10;
    int col = pos_index % 10;

    if (!board[row][col])
        return solve(pos_index + 1);

    for (int size = 0; size < 5; size++)
    {
        if (pieces[size] != 0)
        {
            if (test_size(row, col, size))
            {
                set_val(row, col, size, true);
                pieces[size]--;
                pieces_left--;
                covered += (size + 1) * (size + 1);

                solve(pos_index + 1);

                set_val(row, col, size, false);
                pieces[size]++;
                pieces_left++;
                covered -= (size + 1) * (size + 1);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                cover_count++;
        }
    }

    solve();

    cout << ans;
}