#include <iostream>
#include <vector>

using namespace std;

enum class Direction
{
    Right,
    Left,
    Up,
    Down
};

Direction reverse(Direction dir)
{
    switch (dir)
    {
        case Direction::Right:
        return Direction::Left;
        case Direction::Left:
        return Direction::Right;
        case Direction::Up:
        return Direction::Down;
        case Direction::Down:
        return Direction::Up;
    }
}

pair<int,int> getPosition(pair<int,int> curPos, Direction dir)
{
    switch (dir)
    {
        case Direction::Right:
        return {curPos.first, curPos.second + 1};
        case Direction::Left:
        return {curPos.first, curPos.second - 1};
        case Direction::Up:
        return {curPos.first - 1, curPos.second};
        case Direction::Down:
        return {curPos.first + 1, curPos.second};
    }
}

enum class Color 
{ 
    White,
    Red,
    Blue 
};


class Piece
{
public:
    Piece(int row, int col, Direction dir)
    : m_row(row), m_col(col), m_dir(dir)
    { }
    
    void SetHi(int hi)
    {
        this->hi = hi;
    }

    int GetHi()
    {
        return hi;
    }
private:
    int hi;
    int m_row, m_col;
    Direction m_dir;
};

struct Tile
{
    Color color;
    vector<Piece> pieces;
};

int boardSize;
Tile board[12][12];
vector<Piece> pieces;

int main()
{
    int numPieces;
    cin >> boardSize >> numPieces;

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            int color; cin >> color;
            board[row][col].color = static_cast<Color>(color - 1);
        }
    }

    for (int i = 0; i < numPieces; i++)
    {
        int row, col, dir;
        cin >> row >> col >> dir;
        
        Piece piece{row - 1, col - 1, static_cast<Direction>(dir - 1)};
        pieces.push_back(piece);
        board[row - 1][col - 1].pieces.push_back(piece);
    }

    for (Piece piece : pieces)
    {
        piece.SetHi(3);
    }

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            for (Piece piece : board[row][col].pieces)
                cout << piece.GetHi() << '\n';
        }
    }
}