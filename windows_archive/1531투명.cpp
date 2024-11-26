#include <iostream>

using namespace std;

int opacity[101][101];
int opaque_count;
int threshold;

void cover(int y0, int x0, int y1, int x1)
{
    for (int y = y0; y <= y1; y++)
    {
        for (int x = x0; x <= x1; x++)
        {
            if (opacity[y][x] > threshold)
                continue;
            
            if (++opacity[y][x] > threshold)
                opaque_count++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cover_count;
    cin >> cover_count >> threshold;

    for (int i = 0; i < cover_count; i++)
    {
        int y0, x0, y1, x1;
        cin >> y0 >> x0 >> y1 >> x1;
        cover(y0, x0, y1, x1);
    }

    cout << opaque_count;
    
    return 0;
}