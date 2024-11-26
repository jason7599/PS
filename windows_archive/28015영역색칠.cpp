#include <iostream>

using namespace std;

int height, width;
int painting[100][100];

int main()
{
    cin >> height >> width;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> painting[y][x];
    
    int num_strokes = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int c = painting[y][x];
            if (c != 0)
            {
                for (int i = x; i < width && painting[y][i] != 0; i++)
                    if (painting[y][i] == c)
                        painting[y][i] = 0;
                
                num_strokes++;
            }
        }
    }

    cout << num_strokes;
    return 0;
}