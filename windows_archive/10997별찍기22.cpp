#include <iostream>

using namespace std;

void print(char c, int n)
{
    while (n--)
        cout << c;
}

void draw(int size, int row)
{
    if (size == 2)
    {
        switch (row)
        {
        case 0:
        case 6:
            cout << "*****";
            break;
        case 1:
            cout << "*    ";
            break;
        case 2:
            cout << "* ***";
            break;
        case 3:
        case 4:
            cout << "* * *";
            break;
        case 5:
            cout << "*   *";
        }
        return;
    }

    int width = 4 * size - 3;
    int height = 4 * size - 1;

    if (row == 0 || row == height - 1)
    {
        print('*', width);
        return;
    }

    cout << "* ";

    if (row == 1)
    {
        // print(' ', width - 2);
        return;
    }
    if (row == height - 2)
    {
        print(' ', width - 3);
        cout << '*';
        return;
    }

    draw(size - 1, row - 2);

    if (row - 2 == 0)
        cout << "**";
    else if (row - 2 == 1)
        print(' ', width - 2);
    else
        cout << " *";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int size; cin >> size;
    if (size == 1)
    {
        cout << "*\n";
        return 0;
    }

    for (int row = 0; row < 4 * size - 1; row++)
    {
        draw(size, row);
        cout << '\n';
    }


    return 0;
}