#include <iostream>

using namespace std;

enum class Tile
{
    Empty,
    White,
    Black
};

Tile board[20][20];

int get_len(Tile tile, int row, int col, int d_row, int d_col)
{
    int len = 0;
    for (;; len++)
    {
        row += d_row;
        col += d_col;

        if (row < 1 || row >= 20 || col < 1 || col >= 20
        || board[row][col] != tile)
            return len;
    }
}

bool place_tile(Tile tile, int row, int col)
{
    const int d_rows[] = {1, 0, 1, 1};
    const int d_cols[] = {0, 1, 1, -1};

    board[row][col] = tile;

    for (int d = 0; d < 4; d++)
    {
        if (get_len(tile, row, col, d_rows[d], d_cols[d]) + 1 + get_len(tile, row, col, -d_rows[d], -d_cols[d]) == 5)
            return true;
    }

    return false;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_turns; cin >> num_turns;
    for (int turn = 1; turn <= num_turns; turn++)
    {
        Tile tile = turn % 2 == 1 ? Tile::Black : Tile::White;
        int row, col; cin >> row >> col;
        if (place_tile(tile, row, col))
        {
            cout << turn;
            return 0;
        }
    }

    cout << -1;
    return 0;
}