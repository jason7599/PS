#include <iostream>

using namespace std;

int boardSize;
int board[2187][2187];

struct CutResult
{
    int minusOne;
    int zero;
    int one;
};

CutResult getCutResult(int size, int y, int x)
{
    if (size == 1)
    {
        switch (board[y][x])
        {
            case -1: return {1, 0, 0};
            case 0: return {0, 1, 0};
            case 1: return {0, 0, 1};
        }
    }

    CutResult cutResult{0, 0, 0};

    int subSize = size / 3;
    for (int i = 0; i < 3; i++)
    {
        int yy = y + subSize * i;
        for (int j = 0; j < 3; j++)
        {
            int xx = x + subSize * j;

            CutResult subResult = getCutResult(subSize, yy, xx);

            cutResult.minusOne += subResult.minusOne;
            cutResult.zero += subResult.zero;
            cutResult.one += subResult.one;
        }
    }

    if (!cutResult.zero && !cutResult.one)
        return {1, 0, 0};
    if (!cutResult.one && !cutResult.minusOne)
        return {0, 1, 0};
    if (!cutResult.minusOne && !cutResult.zero)
        return {0, 0, 1};
    
    return cutResult;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> boardSize;

    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
            cin >> board[y][x];
    }

    CutResult result = getCutResult(boardSize, 0, 0);
    cout << result.minusOne << '\n' << result.zero << '\n' << result.one;
}