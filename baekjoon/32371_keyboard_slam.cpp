#include <iostream>

using namespace std;

int main()
{
    char keyboard[4][10];
    int cnt[4][10];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> keyboard[i][j];
            cnt[i][j] = 0;
        }
    }

    char ans;
    for (int t = 0; t < 9; t++)
    {
        char c;
        cin >> c;

        int y;
        int x;
        for (int i = 0; i < 40; i++)
        {
            if (keyboard[i / 10][i % 10] == c)
            {
                y = i / 10;
                x = i % 10;
                break;
            }
        }

        for (int ny = y - 1; ny <= y + 1; ny++)
        {
            for (int nx = x - 1; nx <= x + 1; nx++)
            {
                if (ny < 0 || ny == 4 || nx < 0 || nx == 10)
                    continue;
                
                if (++cnt[ny][nx] == 9)
                    ans = keyboard[ny][nx];
            }
        }
    }

    cout << ans;
    return 0;
}