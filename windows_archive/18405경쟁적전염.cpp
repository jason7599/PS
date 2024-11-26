#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;

int mapSize, virusCount, map[201][201], X, Y, T;
queue<pair<int, int>> virusCoords[1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool spreadVirus(int virusNumber)
{
    int qSize = virusCoords[virusNumber].size();

    while (qSize--)
    {
        int x = virusCoords[virusNumber].front().first;
        int y = virusCoords[virusNumber].front().second;
        virusCoords[virusNumber].pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (!nx || nx > mapSize || !ny || ny > mapSize || map[nx][ny]) continue;

            virusCoords[virusNumber].push({nx, ny});
            map[nx][ny] = virusNumber;

            if (nx == X && ny == Y) return true;
        }
    }

    return false;
}

int main() 
{
    cin >> mapSize >> virusCount;

    FOR(i, mapSize) 
    {
        FOR(j, mapSize) 
        {
            int temp; cin >> temp;
            if (temp) virusCoords[temp].push({i, j});
            map[i][j] = temp;
        }
    }

    cin >> T >> X >> Y;

    FOR(t, T)
    {
        FOR(v, virusCount)
        {
            if (spreadVirus(v))
            {
                cout << map[X][Y];
                return 0;
            }
        }
    }

    cout << map[X][Y];

}