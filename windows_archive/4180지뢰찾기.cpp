#include <iostream>

using namespace std;

const int dys[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dxs[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main()
{
    while (1)
    {
        int height, width;
        cin >> height >> width;

        if (height == 0 && width == 0)
            return 0;

        int ans[100][100] = {0};

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                char c;
                cin >> c;

                if (c == '*')
                {
                    ans[y][x] = -1;
                    for (int d = 0; d < 8; d++)
                    {
                        int ny = y + dys[d];
                        int nx = x + dxs[d];

                        if (ny < 0 || ny >= height || nx < 0 || nx >= width
                        || ans[ny][nx] == -1)
                            continue;
                        
                        ans[ny][nx]++;
                    }
                }
            }
        }

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (ans[y][x] == -1)
                    cout << '*';
                else
                    cout << ans[y][x];
            }
            cout << '\n';
        }
    }
}