#include <iostream>

using namespace std;

int map[1000][1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int map_size; cin >> map_size;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            char c; cin >> c;
            if (c == '.')
                continue;
            
            map[y][x] = -1;

            int val = c - '0';
            for (int ny = y - 1; ny <= y + 1; ny++)
            {
                for (int nx = x - 1; nx <= x + 1; nx++)
                {
                    if (ny < 0 || ny >= map_size
                    || nx < 0 || nx >= map_size
                    || map[ny][nx] == -1)
                        continue;
                    
                    map[ny][nx] += val;
                }
            }
        }
    }

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            if (map[y][x] == -1)
                cout << '*';
            else if (map[y][x] > 9)
                cout << 'M';
            else
                cout << map[y][x];
        }
        cout << '\n';
    }
}