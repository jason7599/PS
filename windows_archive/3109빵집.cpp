#include <iostream>

using namespace std;

const int dy[] = {-1, 0, 1};

int map_height, map_width;
bool occupied[10'000][500];
bool failed[10'000][500];

bool dfs(int y, int x)
{
    if (x + 1 == map_width)
    {
        occupied[y][x] = true;
        return true;
    }
    
    for (int d = 0; d < 3; d++)
    {
        int ny = y + dy[d];
        if (ny < 0 || ny >= map_height || occupied[ny][x + 1] || failed[ny][x + 1])
            continue;
        
        if (dfs(ny, x + 1))
        {
            occupied[y][x] = true;
            return true;
        }
    }

    failed[y][x] = true;
    return false;
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
            occupied[y][x] = c == 'x';
        }
    }

    int ans = 0;
    for (int y = 0; y < map_height; y++)
    {
        if (dfs(y, 0))
            ans++;
    }

    cout << ans;
}