#include <iostream>
#include <queue>

using namespace std;

int map_len, jump_len;
bool obstacles[2][100'000];

bool solve()
{
    static bool visited[2][100'000];
    queue<pair<int,int>> q;

    visited[0][0] = true;
    q.push({0, 0});

    int q_size;
    int time = 0;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int side = q.front().first;
            int pos = q.front().second;
            q.pop();

            if (pos < time)
                continue;
            
            if (pos + 1 == map_len || pos + jump_len >= map_len)
                return true;
            
            if (!obstacles[side][pos + 1] && !visited[side][pos + 1])
            {
                visited[side][pos + 1] = true;
                q.push({side, pos + 1});
            }

            if (pos != 0 && !obstacles[side][pos - 1] && !visited[side][pos - 1])
            {
                visited[side][pos - 1] = true;
                q.push({side, pos - 1});
            }

            if (!obstacles[(side + 1) % 2][pos + jump_len] && !visited[(side + 1) % 2][pos + jump_len])
            {
                visited[(side + 1) % 2][pos + jump_len] = true;
                q.push({(side + 1) % 2, pos + jump_len});
            }
        }

        time++;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_len >> jump_len;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < map_len; j++)
        {
            char c; cin >> c;
            obstacles[i][j] = c == '0';
        }
    }

    cout << solve();
}