#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,pair<int,int>> pip;

enum class Tile 
{
    Safe,
    Danger,
    Death
};

Tile tiles[501][501];

const int inf = 1e9; 

void fillTiles(int y0, int x0, int y1, int x1, Tile tile)
{
    if (y0 > y1)
    {
        int t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x0 > x1)
    {
        int t = x0;
        x0 = x1;
        x1 = t;
    }

    for (int y = y0; y <= y1; y++)
    {
        for (int x = x0; x <= x1; x++)
            tiles[y][x] = max(tiles[y][x], tile);        
    }
}

int getMinDamageToEscape()
{
    static int distMatrix[501][501];

    const int dys[] = {1, 0, -1, 0};
    const int dxs[] = {0, 1, 0, -1};

    fill(&distMatrix[0][0], &distMatrix[0][0] + 501 * 501, inf);
    priority_queue<pip, vector<pip>, greater<pip>> pq;

    distMatrix[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny >= 501 || nx < 0 || nx >= 501
            || tiles[ny][nx] == Tile::Death)
                continue;
            
            int nDist = tiles[ny][nx] == Tile::Danger ? dist + 1 : dist;
            if (distMatrix[ny][nx] > nDist)
            {
                distMatrix[ny][nx] = nDist;
                pq.push({nDist, {ny, nx}});
            }
        }
    }

    return distMatrix[500][500] == inf ? -1 : distMatrix[500][500];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numDangerZones; cin >> numDangerZones;

    for (int i = 0; i < numDangerZones; i++)
    {
        int y0, x0, y1, x1;
        cin >> y0 >> x0 >> y1 >> x1;
        fillTiles(y0, x0, y1, x1, Tile::Danger);
    }

    int numDeathZones; cin >> numDeathZones;
    for (int i = 0; i < numDeathZones; i++)
    {
        int y0, x0, y1, x1;
        cin >> y0 >> x0 >> y1 >> x1;
        fillTiles(y0, x0, y1, x1, Tile::Death);
    }

    cout << getMinDamageToEscape();
}