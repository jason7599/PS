#include <iostream>

using namespace std;

bool board[1 << 10][1 << 10];

void make_triangle(int size, int y, int x)
{
    if (!size)
    {
        board[y][x] = 1;
        return;
    }

    make_triangle(size - 1, y, x);
    make_triangle(size - 1, y, x + (1 << (size - 1)));
    make_triangle(size - 1, y + (1 << (size - 1)), x);
}

void print_triangle(int size)
{
    int l = 1 << size;
    for (int y = 0; y < l; y++)
    {
        for (int x = 0; x < l - y; x++)
        {
            if (board[y][x])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int size;
    cin >> size;

    make_triangle(size, 0, 0);
    print_triangle(size);

    return 0;
}