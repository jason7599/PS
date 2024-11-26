#include <iostream>
#include <vector>

using namespace std;

const int max_board_size = 20;
const int max_moves = 10;

struct Tiles
{
    vector<int> rows[max_board_size];
    vector<int> cols[max_board_size];
};

int board_size;

Tiles shift_left(Tiles tiles)
{
    Tiles new_tiles;

    for (int row = 0; row < board_size; row++)
    {
        int next_col = 0;
        int prev = 0;
        for (int tile : tiles.rows[row])
        {
            if (prev)
            {
                if (prev == tile) // merge
                {
                    
                }
            }
        }
    }

    return new_tiles;
}

int main()
{
    cin >> board_size;

    Tiles tiles;
    for (int row = 0; row < board_size; row++)
    {
        for (int col = 0; col < board_size; col++)
        {
            int tile; cin >> tile;
            if (tile)
            {
                tiles.rows[row].push_back(tile);
                tiles.cols[col].push_back(tile);
            }
        }
    }

    // Tiles shift = shift_left(tiles);
    // cout << shift.rows[0].size();
}