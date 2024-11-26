#include <iostream>
#include <string>

using namespace std;

int boardHeight, boardWidth;
char board[100][100];
int maxSteps;
int memo[100][100][80]; // memo[y][x][i]: num paths starting from board[y][x] where findString[i] == board[y][x]
string findString;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int findStringPath(int y, int x, int charIndex)
{
    if (memo[y][x][charIndex] != -1)
        return memo[y][x][charIndex];
    
    if (board[y][x] != findString[charIndex])
        return memo[y][x][charIndex] = 0;
    
    if (charIndex == findString.length() - 1)
        return memo[y][x][charIndex] = 1;
    
    int res = 0;
    for (int d = 0; d < 4; d++)
    {
        int ny = y;
        int nx = x;
        for (int step = 1; step <= maxSteps; step++)
        {
            ny += dy[d];
            nx += dx[d];

            if (ny < 0 || ny >= boardHeight || nx < 0 || nx >= boardWidth)
                break;
            
            res += findStringPath(ny, nx, charIndex + 1);
        }
    }

    return memo[y][x][charIndex] = res;
}

int main()
{
    cin >> boardHeight >> boardWidth >> maxSteps;

    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            cin >> board[y][x];
            for (int t = 0; t < 80; t++)
                memo[y][x][t] = -1;
        }
    }

    cin >> findString;

    int ans = 0;
    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            ans += findStringPath(y, x, 0);
        }
    }

    cout << ans;
}