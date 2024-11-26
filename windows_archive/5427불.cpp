#include <iostream>
#include <queue>

#define WALL '#'
#define EMPTY '.'
#define START '@'
#define FIRE '*'

#define MAX_SIZE 1000
#define qpii queue<pair<int,int>>

using namespace std;

int size_x, size_y;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool out_of_bounds(int x, int y)
{
    return x < 0 || x >= size_x || y < 0 || y >= size_y;
}

int fastest_exit_time(int start_x, int start_y, qpii fire_queue)
{
    qpii q;
    int q_size, x, y, nx, ny, time = 0;

    q.push({start_x, start_y});
    map[start_x][start_y] = EMPTY;
    visited[start_x][start_y] = true;

    while (true)
    {
        time++;

        q_size = fire_queue.size();
        while (q_size--)
        {
            x = fire_queue.front().first;
            y = fire_queue.front().second;
            fire_queue.pop();

            for (int d = 0; d < 4; d++)
            {
                nx = x + dx[d];
                ny = y + dy[d];

                if (out_of_bounds(nx, ny) || map[nx][ny] != EMPTY)
                    continue;
                
                map[nx][ny] = FIRE;
                fire_queue.push({nx, ny});
            }
        }

        q_size = q.size();
        while (q_size--)
        {
            x = q.front().first;
            y = q.front().second;
            q.pop(); 

            for (int d = 0; d < 4; d++)
            {
                nx = x + dx[d];
                ny = y + dy[d];

                if (out_of_bounds(nx, ny))
                    return time;

                if (map[nx][ny] == EMPTY && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        if (q.empty()) return -1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--)
    {
        int start_x, start_y, res;
        qpii fire_queue;

        cin >> size_y >> size_x;

        for (int x = 0; x < size_x; x++)
        {
            for (int y = 0; y < size_y; y++)
            {
                char t; cin >> t;
                if (t == START)
                {
                    start_x = x;
                    start_y = y;
                }
                else if (t == FIRE)
                {
                    fire_queue.push({x, y});
                }
                map[x][y] = t;
                visited[x][y] = false;
            }
        }

        res = fastest_exit_time(start_x, start_y, fire_queue);
        if (res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
}