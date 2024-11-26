#include <iostream>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int b_hole = 0;

const int m_path = -1; // memo in progress
const int m_none = 0; // not memoed

int board_height, board_width;
int board[50][50];
int memo[50][50];

int max_moves(int y, int x)
{
    if (memo[y][x] != m_none)
        return memo[y][x];

    memo[y][x] = m_path;

    int res = 0;
    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d] * board[y][x];
        int nx = x + dx[d] * board[y][x];

        if (ny < 0 || ny >= board_height || nx < 0 || nx >= board_width
        || board[ny][nx] == b_hole)
            continue;
        
        int t = max_moves(ny, nx);
        if (t == m_path) // cycle
            return m_path; 
        if (t > res)
            res = t;
    }

    return memo[y][x] = res + 1;
}

int main()
{
    cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            char c; cin >> c;

            if (c == 'H')
                board[y][x] = b_hole;
            else
                board[y][x] = c - '0';
        }
    }

    cout << max_moves(0, 0);
}