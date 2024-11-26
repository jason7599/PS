#include <iostream>
#include <queue>

using namespace std;

int map_height, map_width;
char map[100][100];
bool visited[100][100];

queue<pair<int, int>> wolf_q;

const char map_plains = '.';
const char map_ice = '+';
const char map_mountains = '#';
const char map_wolf = 'W';

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

void mark_areas()
{   
    while (!wolf_q.empty())
    {
        int y = wolf_q.front().first;
        int x = wolf_q.front().second;
        wolf_q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (map[ny][nx] == map_mountains)
                continue;

            while (map[ny][nx] == map_ice) 
            {
                int nny = ny + dys[d];
                int nnx = nx + dxs[d];

                if (map[nny][nnx] == map_mountains)
                    break;

                visited[ny][nx] = true;

                ny = nny;
                nx = nnx;
            }

            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                wolf_q.push({ny, nx});
            }
        }
    }
}

void print_map()
{
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            if (map[y][x] == map_plains && !visited[y][x])
                cout << 'P';
            else
                cout << map[y][x];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            if (c == map_wolf)
            {
                wolf_q.push({y, x});
                visited[y][x] = true;
            }
            map[y][x] = c;
        }
    }

    mark_areas();

    print_map();
    
    return 0;
}