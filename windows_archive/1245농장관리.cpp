#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

const int dys[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dxs[] = {0, 1, 0, -1, 1, -1, -1, 1};

int map_size_y, map_size_x;
int height_map[100][70];

/**
 * 0  : not visited
 * 1  : visited this iteration
 * -1 : fucked
 */
int visited[100][70];

bool is_oob(int y, int x)
{
    return y < 0 || y >= map_size_y || x < 0 || x >= map_size_x;
}

bool is_mountain(int start_y, int start_x)
{
    int height = height_map[start_y][start_x];

    vector<pii> queue;
    queue.push_back({start_y, start_x});
    visited[start_y][start_x] = 1;
    
    bool result = true;

    for (int i = 0; i < queue.size(); i++)
    {
        int y = queue[i].first;
        int x = queue[i].second;

        for (int d = 0; d < 8; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (is_oob(ny, nx))
                continue;
            
            if (visited[ny][nx] == 1)
                continue;
            
            // 인접 칸이 더 작음. 인접 칸 = fuck
            if (height_map[ny][nx] < height)
            {
                visited[ny][nx] = -1;
            }
            // 같은 산봉우리
            else if (height_map[ny][nx] == height)
            {
                // 이미 다른 더 큰 산봉우리에 의해 fuck 표시 됨
                if (visited[ny][nx] == -1)
                {
                    result = false;
                }
                else // visited = 0
                {
                    visited[ny][nx] = 1;
                    queue.push_back({ny, nx});
                }
            }
            // 인접 칸이 더 큼. 좆된거지 뭐
            else
            {
                result = false;
            }
        }
    }

    if (!result)
    {
        for (pii yx : queue)
            visited[yx.first][yx.second] = -1;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_size_y >> map_size_x;

    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
            cin >> height_map[y][x];
    }

    int num_mountains = 0;

    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            if (height_map[y][x] == 0 || visited[y][x])
                continue;
            
            if (is_mountain(y, x))
                num_mountains++;
        }
    }

    cout << num_mountains;
    
    return 0;
}