#include <iostream>

using namespace std;

int num_cols;
int num_rows;
// connect[x][y]: left side of row x, col y
bool connect[30][11];
int ans = -1;

void print()
{
    cout << '\n';
    for (int row = 0; row < num_rows; row++)
    {
        cout << row << ' ';
        for (int col = 0; col < num_cols; col++)
        {
            cout << '|';
            if (connect[row][col + 1])
                cout << '_';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}

int simulate_result(int col)
{
    for (int row = 0; row < num_rows; row++)
    {
        if (connect[row][col])
            col = col - 1;
        else if (connect[row][col + 1])
            col = col + 1;
    }
    return col;
}

bool validate()
{
    for (int col = 0; col < num_cols; col++)
    {
        if (simulate_result(col) != col)
            return false;
    }
    return true;
}

void solve(int _row = 0, int _col = 1, int placed = 0)
{
    // print();

    if (validate())
    {
        if (ans == -1 || ans > placed)
            ans = placed;
        return;
    }

    if (placed == 3)
        return;

    if (_col == num_cols)
    {
        _col = 1;
        if (++_row == num_rows)
            return;
    }

    for (int col = _col; col < num_cols; col++)
    {
        if (!connect[_row][col - 1] && !connect[_row][col])
        {
            connect[_row][col] = true;
            solve(_row, col + 1, placed + 1);
            connect[_row][col] = false;
        }
    }

    for (int row = _row; row < num_rows; row++)
    {
        for (int col = 1; col < num_cols; col++)
        {
            if (!connect[row][col - 1] && !connect[row][col])
            {
                connect[row][col] = true;
                solve(row, col + 1, placed + 1);
                connect[row][col] = false;
            }
        }
    }
}

int main()
{
    int num_connects;
    cin >> num_cols >> num_connects >> num_rows;

    for (int i = 0; i < num_connects; i++)
    {
        int row, col; cin >> row >> col;
        connect[row - 1][col] = true;
    }

    // print();

    solve();

    cout << ans;
}