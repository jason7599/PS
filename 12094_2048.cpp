#include <iostream>
#include <vector>

struct Tile
{
    int val;
    int offs; // dist from y or x
};

const int MAX_BOARD_SIZE = 20;

const int AXIS_ROW = 0;
const int AXIS_COL = 1;

int board_size;
std::vector<Tile> axes[2][MAX_BOARD_SIZE];

// todo: max tile 

void print_board()
{
    int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};

    for (int x = 0; x < board_size; x++)
    {
        for (const auto [val, y] : axes[AXIS_COL][x])
            board[y][x] = val;
    }

    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
        {
            if (board[y][x])
                std::cout << board[y][x] << ' ';
            else
                std::cout << ". ";
        }
        std::cout << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> board_size;
    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
        {
            int t;
            std::cin >> t;
            axes[AXIS_ROW][y].push_back(Tile{t, x});
            axes[AXIS_COL][x].push_back(Tile{t, y});
        }
    }

    print_board();

    // push_tiles(row_tiles);

    // print_board();
}