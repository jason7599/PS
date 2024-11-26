#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int inf = ~(1 << 31);

bool walls[500][500];
int dist[500][500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int height, width;
    cin >> height >> width;

    pii start, end;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char c;
            cin >> c;

            if (c == 'S')
                start = {y, x};
            if (c == 'E')
                end = {y, x};
            else
                walls[y][x] = c == '#';

            dist[y][x] = inf;
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    dist[start.first][start.second] = 0;
    pq.push({0, start});

    

    return 0;
}