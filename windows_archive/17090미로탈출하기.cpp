#include <iostream>
#include <vector>

using namespace std;

int mazeHeight, mazeWidth;
char maze[500][500];

short memo[500][500];
const short m_none = 0;     // not visited yet
const short m_success = 1;  // escapable
const short m_fail = -1;    // not escapable
const short m_path = 2;     // memoization in progress; to detect cycles

int main()
{
    cin >> mazeHeight >> mazeWidth;

    for (int y = 0; y < mazeHeight; y++)
    {
        for (int x = 0; x < mazeWidth; x++)
        {
            cin >> maze[y][x];
        }
    }

    int escapableTiles = 0;
    for (int y = 0; y < mazeHeight; y++)
    {
        for (int x = 0; x < mazeWidth; x++)
        {
            if (memo[y][x] != m_none)
                continue;
            
            vector<pair<int,int>> path;
            path.push_back({y, x});
            memo[y][x] = m_path;

            short res;
            int ny = y;
            int nx = x;
            while (true)
            {
                switch (maze[ny][nx])
                {
                    case 'U': ny--; break;
                    case 'R': nx++; break;
                    case 'D': ny++; break;
                    case 'L': nx--; break;
                    default: break;
                }

                if (ny < 0 || ny == mazeHeight || nx < 0 || nx == mazeWidth
                || memo[ny][nx] == m_success)
                {
                    res = m_success;
                    break;
                }

                if (memo[ny][nx] == m_fail 
                || memo[ny][nx] == m_path) // cycle
                {
                    res = m_fail;
                    break;
                }

                path.push_back({ny, nx});
                memo[ny][nx] = m_path;
            }

            if (res == m_success)
                escapableTiles += path.size();
            
            for (pair<int,int> yx : path)
                memo[yx.first][yx.second] = res;
        }
    }

    cout << escapableTiles;
}