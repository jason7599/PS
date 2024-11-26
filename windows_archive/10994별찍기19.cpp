#include <iostream>

using namespace std;

void print(char c, int n)
{
    while (n--)
        cout << c;
}

void draw(int len, int row)
{
    if (row == 0 || row == len - 1)
    {
        print('*', len);
        return;
    }

    if (row < 0 || row >= len)
    {
        print(' ', len);
        return;
    }

    cout << "* ";
    draw(len - 4, row - 2);
    cout << " *";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int size; cin >> size;
    int len = size * 4 - 3;

    for (int row = 0; row < len; row++)
    {
        draw(len, row);
        cout << '\n';
    }

    return 0;
}