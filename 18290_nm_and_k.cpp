#include <iostream>
#include <algorithm>

int board_height, board_width;
int board[10][10];
bool selected[10][10];

int ans = 4 * -10'000;

bool check(int row, int col)
{
    return !(row && selected[row - 1][col]) && !(col && selected[row][col - 1]);
}

void solve(int idx, int num_select, int res)
{
    if (!num_select)
    {
        ans = std::max(ans, res);
        return;
    }
    
    if (idx == board_height * board_width)
        return;

    int row = idx / board_width;
    int col = idx % board_width;

    if (!check(row, col))
        return solve(idx + 1, num_select, res);
    
    solve(idx + 1, num_select, res);
        
    if (check(row, col))
    {
        selected[row][col] = 1;
        solve(idx + 1, num_select - 1, res + board[row][col]);
        selected[row][col] = 0;
    }
}

int main()
{
    int num_select;
    std::cin >> board_height >> board_width >> num_select;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
            std::cin >> board[y][x];
    }

    solve(0, num_select, 0);

    std::cout << ans;
}