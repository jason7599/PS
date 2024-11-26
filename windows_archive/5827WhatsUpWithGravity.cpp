#include <iostream>

using namespace std;

const int maxGridSize = 500;

int gridSizeY, gridSizeX;
bool cells[maxGridSize][maxGridSize];

int main()
{
    cin >> gridSizeY >> gridSizeX;

    int startY, startX, targetY, targetX;

    for (int y = 0; y < gridSizeY; y++)
    {
        for (int x = 0; x < gridSizeX; x++)
        {
            char c; cin >> c;
            if (c == 'C')
            {
                startY = y;
                startX = x;
            }
            else if (c == 'D')
            {
                targetY = y;
                targetX = x;
            }
            else
            {
                cells[y][x] = c == '#';
            }
        }
    }
}