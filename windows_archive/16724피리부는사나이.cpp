#include <iostream>

using namespace std;

int mapHeight, mapWidth;
char map[1000][1000];
int pathIds[1000][1000];
int nextPathId = 1;

bool needsSafeZone(int y, int x)
{
    if (pathIds[y][x])
        return false;
    
    int pathId = nextPathId++;
    pathIds[y][x] = pathId;

    while (true)
    {
        int ny = y;
        int nx = x;

        switch (map[y][x])
        {
            case 'U': ny--; break;
            case 'D': ny++; break;
            case 'L': nx--; break;
            case 'R': nx++; break;
        }

        if (!pathIds[ny][nx])
        {
            pathIds[ny][nx] = pathId;
            y = ny;
            x = nx;
        }
        else if (pathIds[ny][nx] == pathId)
            return true;
        else
            return false;
    }
}

int main()
{
    cin >> mapHeight >> mapWidth;

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            cin >> map[y][x];
        }
    }

    int ans = 0;
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            if (needsSafeZone(y, x))
                ans++;
        }
    }

    cout << ans;
}
