#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int map_size;
vector<vector<char>> map;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int solve(pii start)
{
    vector<vector<bool>> v(map_size, vector<bool>(map_size));
    queue<pii> q;

    v[start.first][start.second] = true;
    q.push(start);

    int moves = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (map[y][x] == 'd')
                return moves;
            
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (ny < 0 || ny >= map_size || nx < 0 || nx >= map_size
                || map[ny][nx] == '*' || v[ny][nx])
                    continue;
                
                v[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        moves++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> map_size;
        map = vector<vector<char>>(map_size, vector<char>(map_size));

        pii start;

        for (int y = 0; y < map_size; y++)
        {
            for (int x = 0; x < map_size; x++)
            {
                char c;
                cin >> c;
                map[y][x] = c;
                if (c == 's')
                    start = {y, x};
            }
        }

        cout << solve(start) << '\n';
    }
}