#include <iostream>
#include <queue>

using namespace std;

#define WALL '#'
#define EMPTY '.'
#define PASS 'J'    // visited
#define FIRE 'F'

#define qpii queue<pair<int,int>>

int size_x, size_y;
char map[1000][1000];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y)
{
    return x < 0 || x >= size_x || y < 0 || y >= size_y;
}

int main()
{
    int start_x, start_y;
    qpii fire_queue;

    cin >> size_x >> size_y;

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            char c; cin >> c;
            if (c == PASS)
            {
                start_x = x;
                start_y = y;
            }
            else if (c == FIRE)
            {
                fire_queue.push({x, y});
            }
            map[x][y] = c;
        }
    }

    int time = 0;
    qpii prot_queue;
    prot_queue.push({start_x, start_y});

    while (1)
    {
        time++;

        int q_size = fire_queue.size();
        while (q_size--)
        {
            int x = fire_queue.front().first;
            int y = fire_queue.front().second;
            fire_queue.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (oob(nx, ny) || map[nx][ny] == FIRE || map[nx][ny] == WALL)
                    continue;
                
                map[nx][ny] = FIRE;
                fire_queue.push({nx, ny});
            }
        }

        q_size = prot_queue.size();
        while (q_size--)
        {
            int x = prot_queue.front().first;
            int y = prot_queue.front().second;
            prot_queue.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (oob(nx, ny))
                {
                    cout << time;
                    return 0;
                }

                if (map[nx][ny] == EMPTY)
                {
                    map[nx][ny] = PASS;
                    prot_queue.push({nx, ny});
                }
            }
        }
        if (prot_queue.empty())
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
}