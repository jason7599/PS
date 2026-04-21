#include <iostream>

using namespace std;

int board[3][3]; 

bool check(int y, int x, int dy, int dx, int p)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[y][x] != p)
            return 0;
        y += dy;
        x += dx;
    }
    return 1;
}

bool place(int y, int x, int p)
{
    y--, x--;
    board[y][x] = p;

    if (check(y, 0, 0, 1, p)
        || check(0, x, 1, 0, p)
        || (y == x && 
            (check(0, 0, 1, 1, p)
            || check(0, 2, 1, -1, p))))
        return 1;
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int player;
    cin >> player;

    int winner = 0;

    for (int i = 0; i < 9; i++)
    {
        int y, x;
        cin >> y >> x;
        if (place(y, x, player))
        {
            winner = player;
            break;
        }
        player = 1 + player % 2;
    }

    cout << winner;
    return 0;
}