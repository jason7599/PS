#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int map_height, map_width;
bool map_obstacles[1'000][1'000];
bool visited[1'000][1'000];

int solve(pii start_pos, int left, int right)
{
    queue<pair<pii, pii>> q;

    q.push({start_pos, {left, right}});
    visited[start_pos.first][start_pos.second] = true;

    int ans = 0;
    do
    {
        queue<pair<pii, pii>> next_q;

        while (!q.empty())
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int left = q.front().second.first;
            int right = q.front().second.second;
            q.pop();

            ans++;

            int ny = y - 1;
            while (ny >= 0 && !map_obstacles[ny][x] && !visited[ny][x])
            {
                visited[ny][x] = true;
                q.push({{ny, x}, {left, right}});
                ny--;
            }

            ny = y + 1;
            while (ny < map_height && !map_obstacles[ny][x] && !visited[ny][x])
            {
                visited[ny][x] = true;
                q.push({{ny, x}, {left, right}});
                ny++;
            }

            if (left)
            {
                int nx = x - 1;
                if (nx >= 0 && !map_obstacles[y][nx] && !visited[y][nx])
                {
                    visited[y][nx] = true;
                    next_q.push({{y, nx}, {left - 1, right}});
                }
            }

            if (right)
            {
                int nx = x + 1;
                if (nx < map_width && !map_obstacles[y][nx] && !visited[y][nx])
                {
                    visited[y][nx] = true;
                    next_q.push({{y, nx}, {left, right - 1}});
                }
            }
        }

        q = next_q;
    } 
    while (!q.empty());
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> map_height >> map_width;

    int left, right;
    cin >> left >> right;

    pii start_pos;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            if (c == '2')
            {
                start_pos = {y, x};
                c = '0';
            }
            map_obstacles[y][x] = c == '1';
        }
    }

    cout << solve(start_pos, left, right);

    return 0;
}