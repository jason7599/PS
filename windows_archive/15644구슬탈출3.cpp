#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

using pos = pair<int, int>;

const char ds[] = {'D', 'R', 'U', 'L'};
const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int board_height, board_width;
bool board_walls[10][10];
pos exit_pos;

bool red_goes_first(pos red_pos, pos blu_pos, int d)
{
    int red_v = red_pos.first * dys[d] + red_pos.second * dxs[d];
    int blu_v = blu_pos.first * dys[d] + blu_pos.second * dxs[d];
    return red_v > blu_v;
}

pos roll(pos pos, int d)
{
    int y = pos.first;
    int x = pos.second;

    while (true)
    {
        if (y == exit_pos.first && x == exit_pos.second)
            break;

        int ny = y + dys[d];
        int nx = x + dxs[d];

        if (board_walls[ny][nx])
            break;

        y = ny;
        x = nx;
    }

    return {y, x};
}

string solve(pos init_red_pos, pos init_blu_pos)
{
    static bool visited[10][10][10][10]; // [r.y][r.x][b.y][b.x]
    queue<tuple<pos, pos, string>> q; // {r_pos, b_pos, path}

    visited[init_red_pos.first][init_red_pos.second][init_blu_pos.first][init_blu_pos.second] = true;
    q.push({init_red_pos, init_blu_pos, ""});

    while (!q.empty())
    {
        pos red_pos = get<0>(q.front());
        pos blu_pos = get<1>(q.front());
        string path = get<2>(q.front());
        q.pop();

        if (red_pos == exit_pos)
            return path;
        
        if (path.length() == 10)
            continue;

        for (int d = 0; d < 4; d++)
        {
            pos n_red_pos, n_blu_pos;

            if (red_goes_first(red_pos, blu_pos, d))
            {
                n_red_pos = roll(red_pos, d);

                if (n_red_pos != exit_pos)
                {
                    board_walls[n_red_pos.first][n_red_pos.second] = true;
                    n_blu_pos = roll(blu_pos, d);                    
                    board_walls[n_red_pos.first][n_red_pos.second] = false;
                }
                else
                    n_blu_pos = roll(blu_pos, d);
            }
            else
            {
                n_blu_pos = roll(blu_pos, d);

                if (n_blu_pos != exit_pos)
                {
                    board_walls[n_blu_pos.first][n_blu_pos.second] = true;
                    n_red_pos = roll(red_pos, d);
                    board_walls[n_blu_pos.first][n_blu_pos.second] = false;
                }
                else
                    n_red_pos = roll(red_pos, d);
            }

            if (n_blu_pos == exit_pos)
                continue;

            if (!visited[n_red_pos.first][n_red_pos.second][n_blu_pos.first][n_blu_pos.second])
            {
                visited[n_red_pos.first][n_red_pos.second][n_blu_pos.first][n_blu_pos.second] = true;
                q.push({n_red_pos, n_blu_pos, path + ds[d]});
            }
        }
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> board_height >> board_width;

    pos red_pos, blu_pos;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            char c;
            cin >> c;
            
            if (c == '#')
                board_walls[y][x] = true;
            else
            {
                if (c == 'R')
                    red_pos = {y, x};
                else if (c == 'B')
                    blu_pos = {y, x};
                else if (c == 'O')
                    exit_pos = {y, x};
            }
        }
    }

    string ans = solve(red_pos, blu_pos);

    if (!ans.empty())
        cout << ans.length() << '\n' << ans;
    else
        cout << -1;

    return 0;
}