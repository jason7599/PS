/**
 * S가 4개 이상.
 */

#include <iostream>
#include <queue>

using namespace std;

const int board_size = 5;
const int group_size = 7;

const char dasom = 'S';
const char doyun = 'Y';

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

char board[board_size][board_size];

int cnt;

void func(int y, int x)
{
    static bool visited[board_size][board_size];
    static vector<pair<int, int>> path;

    visited[y][x] = true;
    path.push_back({y, x});

    if (path.size() == group_size)
    {
        // char temp[board_size][board_size];
        // for (int yy = 0; yy < board_size; yy++)
        // {
        //     for (int xx = 0; xx < board_size; xx++)
        //         temp[yy][xx] = '.';
        // }
        // for (pair<int,int> pii : path)
        //     temp[pii.first][pii.second] = 'S';
        
        // for (int yy = 0; yy < board_size; yy++)
        // {
        //     for (int xx = 0; xx < board_size; xx++)
        //         cout << temp[yy][xx];
        //     cout << '\n';
        // }
        // cout << '\n';

        visited[y][x] = false;
        path.pop_back();
        
        cnt++;

        return;
    }

    for (pair<int, int> pii : path)
    {
        for (int d = 0; d < 4; d++)
        {
            int ny = pii.first + dy[d];
            int nx = pii.second + dx[d];
            
            if (ny < 0 || ny >= board_size || nx < 0 || nx >= board_size
            || visited[ny][nx])
                continue;
            
            func(ny, nx);
        }
    }

    visited[y][x] = false;
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
            func(y, x);
    }

    cout << cnt;

    // for (int y = 0; y < board_size; y++)
    // {
    //     for (int x = 0; x < board_size; x++)
    //         cin >> board[y][x];
    // }


}