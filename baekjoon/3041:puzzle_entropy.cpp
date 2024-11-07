#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int entropy = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            char c;
            cin >> c;
            if (c != '.')
            {
                int yy = (c - 'A') / 4;
                int xx = (c - 'A') % 4;

                entropy += abs(yy - y) + abs(xx - x);
            }
        }
    }

    cout << entropy;
    return 0;
}