#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

char board[1000][1000];
bool v[1000][1000];

int dys[] = {1, 0, -1, 0};
int dxs[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int height, width;
    cin >> height >> width;
    queue<pii> q;

    for (int x = 0; x < width; x++)
    {
        cin >> board[0][x];
        if (board[0][x] =='0')
        {
            v[0][x] = 1;
            q.push({0, x});
        }
    }

    for (int y = 1; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> board[y][x];

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || nx < 0 || nx == width || board[ny][nx] == '1' || v[ny][nx])
                continue;

            if (ny == height - 1)
            {
                cout << "YES";
                return 0;
            }

            v[ny][nx] = 1;
            q.push({ny, nx});
        }
    }

    cout << "NO";
    return 0;
}   
