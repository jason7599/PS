#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int mazeHeight, mazeWidth;
char maze[100][100];
bool visited[100][100];
int numDots;
int minPlayers;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

bool isEntrance(char c)
{
    return 'A' <= c && c <= 'W';
}

void bfs(int y, int x)
{
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({y, x});

    bool collectedDot = false;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny >= mazeHeight || nx < 0 || nx >= mazeWidth
            || maze[ny][nx] == 'X' || isEntrance(maze[ny][nx]) || visited[ny][nx])
                continue;
            
            if (maze[ny][nx] == '.')
            {
                numDots--;
                collectedDot = true;
            }
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    if (collectedDot)
        minPlayers++;
}

int main()
{
    cin >> mazeHeight >> mazeWidth;
    vector<pair<int, int>> entrances;
    
    cin.ignore();
    for (int y = 0; y < mazeHeight; y++)
    {
        string row;
        getline(cin, row);
        for (int x = 0; x < mazeWidth; x++)
        {
            char c = maze[y][x] = row[x];

            if (isEntrance(c))
                entrances.push_back({y, x});
            else if (c == '.')
                numDots++;
        }
    }

    for (pair<int, int> entrance : entrances)
        bfs(entrance.first, entrance.second);

    cout << minPlayers << ' ' << numDots;
}