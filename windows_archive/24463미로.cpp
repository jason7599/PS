#include <iostream>

using namespace std;

int maze_height, maze_width;
char maze[2'001][2'001];
bool visited[2'001][2'001];

pair<int, int> dest;

const char maze_wall = '+';
const char maze_empty = '.';
const char maze_unused = '@';

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

bool dfs(int y, int x)
{
    visited[y][x] = true;

    if (y == dest.first && x == dest.second)
        return true;

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dys[d];
        int nx = x + dxs[d];

        if (ny < 0 || ny == maze_height || nx < 0 || nx == maze_width
        || maze[ny][nx] == maze_wall || visited[ny][nx])
            continue;

        if (dfs(ny, nx))
        {
            maze[ny][nx] = maze_empty;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> maze_height >> maze_width;

    pair<int, int> start;
    bool start_flag = true;

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
        {
            char c; cin >> c;
            if (c == maze_empty)
            {
                if (y == 0 || y == maze_height - 1
                || x == 0 || x == maze_width - 1)
                {
                    maze[y][x] = maze_empty;

                    if (start_flag)
                    {
                        start = {y, x};
                        start_flag = false;
                    }
                    else
                    {
                        dest = {y, x};
                    }
                }
                else
                {
                    maze[y][x] = maze_unused;
                }
            }
            else
            {
                maze[y][x] = maze_wall;
            }
        }
    }

    dfs(start.first, start.second);

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
        {
            cout << maze[y][x];
        }
        cout << '\n';
    }

    return 0;
}