#include <iostream>
#include <vector>

using namespace std;

bool visitedNumbersAtRow[9][10];
bool visitedNumbersAtCol[9][10];
bool visitedNumbersAtBox[9][10];

vector<pair<int,int>> emptySpots;
vector<int> ans;

int toBoxIndex(int row, int col)
{
    return (row / 3) * 3 + col / 3;
}

bool solve(int spotIndex = 0)
{
    if (spotIndex >= emptySpots.size())
        return true;

    int row = emptySpots[spotIndex].first;
    int col = emptySpots[spotIndex].second;
    int box = toBoxIndex(row, col);

    for (int num = 1; num <= 9; num++)
    {
        if (!visitedNumbersAtRow[row][num]
        && !visitedNumbersAtCol[col][num]
        && !visitedNumbersAtBox[box][num])
        {
            visitedNumbersAtRow[row][num] = true;
            visitedNumbersAtCol[col][num] = true;
            visitedNumbersAtBox[box][num] = true;

            ans.push_back(num);

            if (solve(spotIndex + 1))
                return true;
            
            ans.pop_back();

            visitedNumbersAtRow[row][num] = false;
            visitedNumbersAtCol[col][num] = false;
            visitedNumbersAtBox[box][num] = false;
        }
    }

    return false;
}

int main()
{
    char board[9][9];

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            char c; cin >> c; board[row][col] = c;
            int num = c - '0';
            if (num)
            {
                visitedNumbersAtRow[row][num] = true;
                visitedNumbersAtCol[col][num] = true;
                visitedNumbersAtBox[toBoxIndex(row, col)][num] = true;
            }
            else
                emptySpots.push_back({row, col});
        }
    }

    solve();

    int i = 0;
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            char c = board[row][col];
            if (c == '0') cout << ans[i++];
            else cout << c;
        }
        cout << '\n';
    }
}