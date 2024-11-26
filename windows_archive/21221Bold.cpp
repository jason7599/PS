#include <iostream>

using namespace std;

int height, width;
char message[100][100];

void fuck(int y, int x)
{
    if (y < height && x < width)
        message[y][x] = '#';
}

void fucks(int y, int x)
{
    message[y][x] = '#';
    fuck(y, x + 1);
    fuck(y + 1, x);
    fuck(y + 1, x + 1);
}

int main()
{
    cin >> height >> width;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char c;
            cin >> c;
            if (c == '#')
                fucks(y, x);
            else
            {
                if (message[y][x] != '#')
                    message[y][x] = '.';
            }
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
            cout << message[y][x];
        cout << '\n';
    }

    return 0;
}