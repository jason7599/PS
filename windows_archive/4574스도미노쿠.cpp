#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct Position
{
    int row;
    int col;
};

class Sudominoku
{
public:
    void Clear();
    void PlaceDomino(int num1, Position pos1, int num2, Position pos2);
    void PlaceNumber(int num, Position pos);
    void RemoveDomino(int num1, Position pos1, int num2, Position pos2);
    void RemoveNumber(int num, Position pos);
    bool CanPlaceNumber(int num, Position pos);
    bool IsDominoUsed(int num1, int num2);
    int GetNumberAt(Position pos);
    void PrintBoard();
private:
    int board[9][9];
    bool rowNumUsed[9][10];
    bool colNumUsed[9][10]; 
    bool boxNumUsed[3][3][10];
    bool dominoUsed[10][10];
};

Position parsePosition(const string& loc)
{
    return {loc[0] - 'A', loc[1] - '1'};
}

bool solveSudominoku(Sudominoku& sudominoku, int posIndex = 0)
{
    if (posIndex == 81)
        return true;

    int row = posIndex / 9;
    int col = posIndex % 9;

    if (sudominoku.GetNumberAt({row, col}) != 0)
        return solveSudominoku(sudominoku, posIndex + 1);

    for (int num = 1; num <= 9; num++)
    {
        if (sudominoku.CanPlaceNumber(num, {row, col}))
        {
            for (int otherNum = 1; otherNum <= 9; otherNum++)
            {
                if (num == otherNum || sudominoku.IsDominoUsed(num, otherNum))
                    continue;
                
                if (row != 8 && sudominoku.GetNumberAt({row + 1, col}) == 0 && sudominoku.CanPlaceNumber(otherNum, {row + 1, col}))
                {
                    sudominoku.PlaceDomino(num, {row, col}, otherNum, {row + 1, col});
                    if (solveSudominoku(sudominoku, posIndex + 1))
                        return true;
                    sudominoku.RemoveDomino(num, {row, col}, otherNum, {row + 1, col});
                }

                if (col != 8 && sudominoku.GetNumberAt({row, col + 1}) == 0 && sudominoku.CanPlaceNumber(otherNum, {row, col + 1}))
                {
                    sudominoku.PlaceDomino(num, {row, col}, otherNum, {row, col + 1});
                    if (solveSudominoku(sudominoku, posIndex + 1))
                        return true;
                    sudominoku.RemoveDomino(num, {row, col}, otherNum, {row, col + 1});
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Sudominoku sudmoinoku;

    for (int puzzleNum = 1; ; puzzleNum++)
    {
        int numDominoes;
        cin >> numDominoes;

        if (numDominoes == 0)
            break;

        sudmoinoku.Clear();

        for (int i = 0; i < numDominoes; i++)
        {
            int num1, num2; string loc1, loc2;
            cin >> num1 >> loc1 >> num2 >> loc2;
            sudmoinoku.PlaceDomino(num1, parsePosition(loc1), num2, parsePosition(loc2));
        }

        for (int num = 1; num <= 9; num++)
        {
            string loc; cin >> loc;
            sudmoinoku.PlaceNumber(num, parsePosition(loc));
        }

        solveSudominoku(sudmoinoku);

        cout << "Puzzle " << puzzleNum << '\n';
        sudmoinoku.PrintBoard();
    }
}

void Sudominoku::Clear()
{
    memset(board, 0, sizeof(board));
    memset(rowNumUsed, false, sizeof(rowNumUsed));
    memset(colNumUsed, false, sizeof(colNumUsed));
    memset(boxNumUsed, false, sizeof(boxNumUsed));
    memset(dominoUsed, false, sizeof(dominoUsed));
}

void Sudominoku::PlaceDomino(int num1, Position pos1, int num2, Position pos2)
{
    PlaceNumber(num1, pos1);
    PlaceNumber(num2, pos2);

    dominoUsed[num1][num2] = dominoUsed[num2][num1] = true;
}

void Sudominoku::PlaceNumber(int num, Position pos)
{
    board[pos.row][pos.col] = num;
    rowNumUsed[pos.row][num] = true;
    colNumUsed[pos.col][num] = true;
    boxNumUsed[pos.row / 3][pos.col / 3][num] = true;
}

void Sudominoku::RemoveDomino(int num1, Position pos1, int num2, Position pos2)
{
    RemoveNumber(num1, pos1);
    RemoveNumber(num2, pos2);

    dominoUsed[num1][num2] = dominoUsed[num2][num1] = false;
}

void Sudominoku::RemoveNumber(int num, Position pos)
{
    board[pos.row][pos.col] = 0;
    rowNumUsed[pos.row][num] = false;
    colNumUsed[pos.col][num] = false;
    boxNumUsed[pos.row / 3][pos.col / 3][num] = false;
}

bool Sudominoku::CanPlaceNumber(int num, Position pos)
{
    return !rowNumUsed[pos.row][num] && !colNumUsed[pos.col][num] && !boxNumUsed[pos.row / 3][pos.col / 3][num];
}

bool Sudominoku::IsDominoUsed(int num1, int num2)
{
    return dominoUsed[num1][num2];
}

int Sudominoku::GetNumberAt(Position pos)
{
    return board[pos.row][pos.col];
}

void Sudominoku::PrintBoard()
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
            cout << board[r][c];
        cout << '\n';
    }
}