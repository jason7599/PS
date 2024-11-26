#include <iostream>

using namespace std;

const int max_board_size = 20;
const int max_moves = 10;

int board_size;
int board[max_board_size][max_board_size];



int main()
{
    cin >> board_size;
    for (int row = 0; row < board_size; row++)
    {
        for (int col = 0; col < board_size; col++)
        {
            cin >> board[row][col];
        }
    }
}