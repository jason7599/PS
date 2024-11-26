#include <iostream>
#include <algorithm>

using namespace std;

int boardHeight, boardWidth;

bool board[1000][1000];
int memo[1000][1000];

int getBiggestSquareAt(int y, int x)
{
    if (y >= boardHeight || x >= boardWidth
    || !board[y][x])
        return 0;
    
    if (memo[y][x])
        return memo[y][x];
    
    return memo[y][x] = min({getBiggestSquareAt(y, x + 1), getBiggestSquareAt(y + 1, x), getBiggestSquareAt(y + 1, x + 1)}) + 1;
}

int main()
{
    cin >> boardHeight >> boardWidth;

    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            char c; cin >> c;
            board[y][x] = c == '1';
        }
    }

    int biggestSquare = 0;
    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            int square = getBiggestSquareAt(y, x);
            if (square > biggestSquare)
                biggestSquare = square;
        }
    }

    cout << biggestSquare * biggestSquare;
}