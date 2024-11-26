#include <iostream>
#include <queue>

using namespace std;

struct MonkeyState
{
    int y, x;
    int hops;
};

const int m_dy[] = {1, 0, -1, 0};
const int m_dx[] = {0, 1, 0, -1};
const int h_dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int h_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int hops;
int mapHeight, mapWidth;
bool map[200][200];
bool visited[200][200][31];

bool oob(int y, int x)
{
    return y < 0 || y >= mapHeight || x < 0 || x >= mapWidth;
}

int solve()
{
    queue<MonkeyState> q;
    q.push({0, 0, hops});
    visited[0][0][hops] = true;

    int ans = 0;
    int qSize;
    while ((qSize = q.size()))
    {
        while (qSize--)
        {
            int y = q.front().y;
            int x = q.front().x;
            int h = q.front().hops;

            if (y == mapHeight - 1 && x == mapWidth -1)
                return ans;

            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + m_dy[d];
                int nx = x + m_dx[d];

                if (oob(ny, nx) || map[ny][nx] || visited[ny][nx][h])
                    continue;
                
                q.push({ny, nx, h});
                visited[ny][nx][h] = true;
            }

            if (h)
            {
                for (int d = 0; d < 8; d++)
                {
                    int ny = y + h_dy[d];
                    int nx = x + h_dx[d];

                    if (oob(ny, nx) || map[ny][nx] || visited[ny][nx][h - 1])
                        continue;

                    q.push({ny, nx, h - 1});
                    visited[ny][nx][h - 1] = true;
                }
            }
        }

        ans++;
    }

    return -1;
}

int main()
{
    cin >> hops;
    cin >> mapWidth >> mapHeight;

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
            cin >> map[y][x];
    }

    cout << solve();
}