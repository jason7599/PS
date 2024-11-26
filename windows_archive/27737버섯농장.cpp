#include <iostream>
#include <queue>

using namespace std;

int map_size;
bool arable[100][100];
int max_expand;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int bfs(int y, int x)
{
    static bool visited[100][100];
    queue<pair<int, int>> q;

    visited[y][x] = true;
    q.push({y, x});

    int size = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        size++;
        arable[y][x] = false;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny >= map_size || nx < 0 || nx >= map_size)
                continue;
            
            if (!arable[ny][nx] || visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    return size;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_seeds;
    cin >> map_size >> num_seeds >> max_expand;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            int t;
            cin >> t;
            if (t == 0)
                arable[y][x] = true;
        }
    }

    bool flag = false;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            if (arable[y][x])
            {
                int size = bfs(y, x);
                num_seeds -= size / max_expand + (size % max_expand != 0);
                flag = true;
                if (num_seeds < 0)
                {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }

    if (!flag)
        cout << "IMPOSSIBLE";
    else
        cout << "POSSIBLE\n" << num_seeds;
        
    return 0;
}