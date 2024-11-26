#include <iostream>
#include <vector>

using namespace std;

bool rowCheck[9][10];
bool colCheck[9][10];
bool boxCheck[9][10];

int board[9][9];

vector<pair<int, int>> emptySpots;

void printBoard()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            cout << board[row][col] << ' ';
        }
        cout << '\n';
    }
}

void setNum(int row, int col, int num)
{
    board[row][col] = num;
    rowCheck[row][num] = true;
    colCheck[col][num] = true;
    boxCheck[(row / 3) * 3 + col / 3][num] = true;
}

void unsetNum(int row, int col)
{
    int num = board[row][col];
    board[row][col] = 0;
    rowCheck[row][num] = false;
    colCheck[col][num] = false;
    boxCheck[(row / 3) * 3 + col / 3][num] = false;
}

bool checkPossible(int row, int col, int num)
{
    return !rowCheck[row][num] && !colCheck[col][num] && !boxCheck[(row / 3) * 3 + col / 3][num];
}

bool solve(int index = 0)
{
    if (index == emptySpots.size())
    {
        return true;
    }

    int row = emptySpots[index].first;
    int col = emptySpots[index].second;

    for (int num = 1; num <= 9; num++)
    {
        if (checkPossible(row, col, num))
        {
            setNum(row, col, num);

            if (solve(index + 1))
            {
                return true;
            }

            unsetNum(row, col);
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            int num;
            cin >> num;

            if (num == 0)
            {
                emptySpots.push_back({row, col});
            }
            else
            {
                setNum(row, col, num);
            }
        }
    }

    solve();

    printBoard();

    return 0;
}