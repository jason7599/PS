#include <iostream>

using namespace std;

char board[3][3];

bool check(int y, int x, int dy, int dx, char p)
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

bool check_win(char p)
{
    for (int y = 0; y < 3; y++)
        if (check(y, 0, 0, 1, p))
            return 1;

    for (int x = 0; x < 3; x++)
        if (check(0, x, 1, 0, p))
            return 1;

    return check(0, 0, 1, 1, p) || check(2, 0, -1, 1, p);
}

void solve(char p)
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[y][x] == '-')
            {
                board[y][x] = p;
                if (check_win(p))
                    return;
                board[y][x] = '-';
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                cin >> board[y][x];
        
        char p;
        cin >> p;

        solve(p);

        cout << "Case " << i << ":\n";
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
                cout << board[y][x];
            cout << '\n';
        }
    }

    return 0;
}