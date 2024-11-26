#include <iostream>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int map_size;
int bamboos[500][500];
int memo[500][500]; // -1: not memoed

int solve(int y, int x)
{
    if (memo[y][x] != -1)
        return memo[y][x];
    
    int max = 0;
    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny == map_size
        || nx < 0 || nx == map_size
        || bamboos[ny][nx] <= bamboos[y][x])
            continue;
        
        int t = solve(ny, nx);
        if (t > max)
            max = t;
    }

    return memo[y][x] = max + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_size;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            cin >> bamboos[y][x];
            memo[y][x] = -1;
        }
    }

    int ans = 0;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            int t = solve(y, x);
            if (t > ans)
                ans = t;
        }
    }

    cout << ans;
}