#include <iostream>
#include <algorithm>

using namespace std;

bool guardedRows[50];
bool guardedCols[50];

int main()
{
    int h, w;
    cin >> h >> w;

    int unguardedRowCount = h;
    int unguardedColCount = w;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            char c;
            cin >> c;
            if (c == 'X')
            {
                if (!guardedRows[y])
                {
                    guardedRows[y] = 1;
                    unguardedRowCount--;
                }
                if (!guardedCols[x])
                {
                    guardedCols[x] = 1;
                    unguardedColCount--;
                }
            }
        }
    }

    cout << max(unguardedRowCount, unguardedColCount);

    return 0;
}