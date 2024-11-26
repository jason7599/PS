#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int height, width;
char grid[50][50];
bool v[50][50];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
    queue<pii> q ({{y, x}});
    v[y][x] = 1;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny == height || nx < 0 || nx == width
            || grid[ny][nx] == 'W' || v[ny][nx])
                continue;

            v[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> height >> width;

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> grid[y][x];

    int num_islands = 0;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (grid[y][x] == 'L' && !v[y][x])
            {
                bfs(y, x);
                num_islands++;
            }
            
    cout << num_islands;
    return 0;
}