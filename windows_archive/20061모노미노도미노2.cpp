#include <iostream>

using namespace std;

struct Position
{
    int row;
    int col;
};

// enum class BlockType
// {
//     B_1x1,
//     B_1x2,
//     B_2x1
// };

class Board
{
public:
    static const int numRows = 6;
    static const int numCols = 4;
    static const int numSpecialRows = 2;
    
    void DropB1x1(int col);
    int GetScore() { return score; }
    void Print();
private:
    bool blocks[numRows][numCols] = {false};
    int score = 0;
    int CalculateBlockFallRow(int col);
    void CascadeDown(int row = numRows - 1, int delta = 1); 
    bool IsRowFull(int row);
};

int main()
{
    Board board;

    for (int col = 0; col < Board::numCols; col++)
    {
        board.DropB1x1(col);
        board.Print();
    }

    // board.Print();
    // cout << (BlockType::B_1x1 == static_cast<BlockType>(0));
}

void Board::DropB1x1(int col)
{
    int row = CalculateBlockFallRow(col);

    if (row < numSpecialRows)
        CascadeDown();
    else
    {
        blocks[row][col] = true;
        if (IsRowFull(row))
        {
            CascadeDown(row);
            score++;
        }
    }
}

// TODO: WRONG
// @param row: the row that will disappear, default bottom row
void Board::CascadeDown(int row, int delta)
{
    while (row--)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (row - delta >= 0)
                blocks[row][col] = blocks[row - delta][col];
            else
                blocks[row][col] = false;
        }
    }
}

bool Board::IsRowFull(int row)
{
    for (int col = 0; col < numCols; col++)
    {
        if (!blocks[row][col])
            return false; 
    }
    return true;
}

int Board::CalculateBlockFallRow(int col)
{
    for (int row = 0;; row++)
    {
        if (row == numRows || blocks[row][col])
            return row - 1;
    }
}

void Board::Print()
{
    cout << '\n';
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (blocks[row][col]) cout << '#';
            else cout << '_';
        }
        cout << '\n';
    }
    cout << '\n';
}