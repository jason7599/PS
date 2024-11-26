#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

using pii = pair<int, int>;

const char map_pac = 'P';
const char map_empty = '.';
const char map_wall = 'X';
const char map_ghost = 'G';

const char dirs[] = {'N', 'E', 'S', 'W'};
const int dys[] = {-1, 0, 1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
char map[50][50];
bool visited[50][50][50][50];

pii move_pos(pii pos, int d)
{
    int ny = pos.first + dys[d];
    int nx = pos.second + dxs[d];

    // wrap around
    if (ny < 0) ny = map_height - 1;
    else if (ny == map_height) ny = 0;

    if (nx < 0) nx = map_width - 1;
    else if (nx == map_width) nx = 0;

    if (map[ny][nx] == map_wall)
        return pos; // no movement

    // callee must check for ghosts
    return {ny, nx};
}

string solve(pii pac0, pii pac1)
{
    queue<pair<pair<pii, pii>, string>> q; // {{pac0, pac1}, path}

    memset(visited, 0, sizeof visited);

    visited[pac0.first][pac0.second][pac1.first][pac1.second] = true;
    q.push({{pac0, pac1}, ""});

    int q_size;
    while ((q_size = q.size()) != 0)
    {
        pac0 = q.front().first.first;
        pac1 = q.front().first.second;
        string path = q.front().second;
        q.pop();

        if (pac0 == pac1)
            return path;
        
        for (int d = 0; d < 4; d++)
        {
            pii npac0 = move_pos(pac0, d);
            pii npac1 = move_pos(pac1, d);

            if (map[npac0.first][npac0.second] == map_ghost
            || map[npac1.first][npac1.second] == map_ghost)
                continue;
            
            if (visited[npac0.first][npac0.second][npac1.first][npac1.second])
                continue;
            
            visited[npac0.first][npac0.second][npac1.first][npac1.second] = true;
            q.push({{npac0, npac1}, path + dirs[d]});
        }
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
        cin >> map_height >> map_width;

        pii pac0, pac1;
        bool pac0_found = false;

        for (int y = 0; y < map_height; y++)
        {
            for (int x = 0; x < map_width; x++)
            {
                char c; cin >> c;

                if (c == map_pac)
                {
                    if (!pac0_found)
                    {
                        pac0 = {y, x};
                        pac0_found = true;
                    }
                    else
                        pac1 = {y, x};
                    
                    map[y][x] = map_empty; //*
                }
                else
                    map[y][x] = c;
            }
        }

        string ans = solve(pac0, pac1);

        if (ans.empty())
            cout << "IMPOSSIBLE";
        else
            cout << ans.length() << ' ' << ans;
        cout << '\n';
    }

    return 0;
}