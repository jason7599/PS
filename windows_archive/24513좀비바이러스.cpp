#include <iostream>
#include <queue>

using namespace std;

#define pii pair<int,int>

const int v0 = 0; //
const int v1 = 1;
const int v1_embryo = 4; // 
const int v2 = 2;
const int v3 = 3;
const int vac = -1;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int virus_map[1000][1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int map_size_y, map_size_x;
    
    cin >> map_size_y >> map_size_x;

    queue<pii> v1_q, v2_q;
    
    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            int t; cin >> t;

            if (t == v1) v1_q.push({y, x});
            else if (t == v2) v2_q.push({y, x});

            virus_map[y][x] = t;
        }
    }

    int n_v1 = 0, n_v2 = 1, n_v3 = 0;

    int v1_qs, v2_qs;
    while ((v1_qs = v1_q.size()) | (v2_qs = v2_q.size())) // bitwise or so both sizes are calculated
    {
        while (v1_qs--)
        {
            int y = v1_q.front().first;
            int x = v1_q.front().second;
            v1_q.pop();

            if (virus_map[y][x] == v3)
                continue;
            
            virus_map[y][x] = v1;
            n_v1++;
            
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= map_size_y || nx < 0 || nx >= map_size_x)
                    continue;

                if (virus_map[ny][nx] == v0)
                {
                    virus_map[ny][nx] = v1_embryo;
                    v1_q.push({ny, nx});
                }
            }
        }

        while (v2_qs--)
        {
            int y = v2_q.front().first;
            int x = v2_q.front().second;
            v2_q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= map_size_y || nx < 0 || nx >= map_size_x)
                    continue;

                if (virus_map[ny][nx] == v0)
                {
                    virus_map[ny][nx] = v2;
                    v2_q.push({ny, nx});
                    n_v2++;
                }
                else if (virus_map[ny][nx] == v1_embryo)
                {
                    virus_map[ny][nx] = v3;
                    n_v3++;
                }
            }
        }
    }

    cout << n_v1 << ' ' << n_v2 << ' ' << n_v3;
}