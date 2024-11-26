#include <iostream>
#include <queue>

using namespace std;

int map_len;
int jump_map[1000];

int get_minimum_jumps()
{
    if (map_len == 1)
        return 0;

    bool visited[1000] = {false};
    queue<int> q;

    visited[0] = true;
    q.push(0);

    int jumps = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        jumps++;

        while (q_size--)
        {
            int x = q.front();
            q.pop();

            for (int dist = 1; dist <= jump_map[x]; dist++)
            {
                int nx = x + dist;
                if (nx >= map_len - 1)
                    return jumps;
                
                if (!visited[nx])
                {
                    visited[nx] = true;
                    q.push(nx);
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_len;
    for (int i = 0; i < map_len; i++)
        cin >> jump_map[i];

    cout << get_minimum_jumps();
}