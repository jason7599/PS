#include <iostream>

using namespace std;

// n <= 3 * 2^10 = 3072

char board[3 * 1024][3 * 1024 * 2 - 1];

void draw(int size, int y, int x)
{
    if (size == 3)
    {
        board[y][x] = '*';
        board[y + 1][x - 1] = '*';
        board[y + 1][x + 1] = '*';
        for (int i = 0; i < 5; i++)
            board[y + 2][x - 2 + i] = '*';
        return;
    }

    draw(size / 2, y, x);
    draw(size / 2, y + size / 2, x - size / 2);
    draw(size / 2, y + size / 2, x + size / 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int size; cin >> size;

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size * 2 - 1; x++)
            board[y][x] = ' ';
    }

    draw(size, 0, size - 1);

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size * 2 - 1; x++)
            cout << board[y][x];
        cout << '\n';
    }

    return 0;
}