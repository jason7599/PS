#include <iostream>
#include <vector>

using namespace std;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int height, width;
char map[500][500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> height >> width;
    vector<pair<int, int>> wolves;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char c;
            cin >> c;
            if (c == '.')
                c = 'D';
            else if (c == 'W')
                wolves.push_back({y, x});
            map[y][x] = c;
        }
    }

    for (auto wolf : wolves)
    {
        for (int d = 0; d < 4; d++)
        {
            int ny = wolf.first + dys[d];
            int nx = wolf.second + dxs[d];

            if (ny < 0 || ny == height || nx < 0 || nx == width)
                continue;
        
            if (map[ny][nx] == 'S')
            {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1 << '\n';
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
            cout << map[y][x];
        cout << '\n';
    }

    return 0;
}