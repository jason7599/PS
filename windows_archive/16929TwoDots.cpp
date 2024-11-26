#include <iostream>

using namespace std;

int board_height, board_width;
char board[50][50];

bool check_cycle(int row, int col, int prev_row = -1, int prev_col = -1)
{
    const int drow[] = {1, 0, -1, 0};
    const int dcol[] = {0, 1, 0, -1};

    static bool visited[50][50];

    visited[row][col] = true;

    for (int d = 0; d < 4; d++)
    {
        int nrow = row + drow[d];
        int ncol = col + dcol[d];

        if ((prev_row == nrow && prev_col == ncol) 
        || nrow < 0 || nrow >= board_height
        || ncol < 0 || ncol >= board_width
        || board[nrow][ncol] != board[row][col])
            continue;

        if (visited[nrow][ncol] || check_cycle(nrow, ncol, row, col))
        {
            visited[row][col] = false;
            return true;
        }   
    }

    visited[row][col] = false;
    return false;
}

int main()
{
    cin >> board_height >> board_width;
    for (int row = 0; row < board_height; row++)
    {
        for (int col = 0; col < board_width; col++)
            cin >> board[row][col];
    }

    for (int row = 0; row < board_height; row++)
    {
        for (int col = 0; col < board_width; col++)
        {
            if ((row != 0 && board[row][col] == board[row - 1][col])
            || (col != 0 && board[row][col] == board[row][col - 1]))
                continue;
            
            if (check_cycle(row, col))
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}