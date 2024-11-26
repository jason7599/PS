#include <iostream>

using namespace std;

int numRow, numCol;
int dontDoThat[26][26];

const int okIWontDoThat = -3;

int ans;

void help(int row = 0, int col = 0)
{
    if (row == numRow)
    {
        ans++;
        return;
    }
    if (col == numCol)
        return help(row + 1, 0);

    if (dontDoThat[row][col] != okIWontDoThat)
    {
        dontDoThat[row][col + 1]--;
        dontDoThat[row + 1][col]--;
        dontDoThat[row + 1][col + 1]--;

        help(row, col + 1);

        dontDoThat[row][col + 1]++;
        dontDoThat[row + 1][col]++;
        dontDoThat[row + 1][col + 1]++;
    }

    help(row, col + 1);
}

int main()
{
    cin >> numRow >> numCol;

    help();

    cout << ans;
}