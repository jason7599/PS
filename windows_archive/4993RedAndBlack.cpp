#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int board_height, board_width;
bool board_red[20][20];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int solve(pii start_pos)
{
    bool v[20][20] = {0};
    queue<pii> q ({start_pos});
    v[start_pos.first][start_pos.second] = 1;

    int ans = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        ans++;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny >= board_height || nx < 0 || nx >= board_width
            || board_red[ny][nx] || v[ny][nx])
                continue;

            v[ny][nx] = 1;
            q.push({ny, nx});
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        cin >> board_width >> board_height;

        if (board_height == 0 && board_width == 0)
            break;

        pii start_pos;
        for (int y = 0; y < board_height; y++)
        {
            for (int x = 0; x < board_width; x++)
            {
                char c;
                cin >> c;
                board_red[y][x] = c == '#';
                if (c == '@')
                    start_pos = {y, x};
            }
        }

        cout << solve(start_pos) << '\n';
    }    

    return 0;
}