#include <iostream>
#include <queue>

using namespace std;

#define VULN 0
#define qpii queue<pair<int,int>>

int size_x, size_y;
int map[1000][1000];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool out_of_bounds(int x, int y)
{
    return x < 0 || x >= size_x || y < 0 || y >= size_y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> size_x >> size_y;

    qpii vuln_queue;

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            char c; 
            cin >> c;

            if (c == '.')
            {
                map[x][y] = VULN;
                vuln_queue.push({x, y});
            }
            else
                map[x][y] = c - '0';
        }
    }

    int wave_num = 0;

    while (1)
    {
        int q_size = vuln_queue.size();

        while (q_size--)
        {
            int x = vuln_queue.front().first;
            int y = vuln_queue.front().second;
            vuln_queue.pop();

            for (int d = 0; d < 8; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (out_of_bounds(nx, ny) || map[nx][ny] == VULN)
                    continue;
                
                if (--map[nx][ny] == VULN)
                    vuln_queue.push({nx, ny});
            }
        }

        if (vuln_queue.empty())
            break;

        wave_num++;
    }

    cout << wave_num;
}