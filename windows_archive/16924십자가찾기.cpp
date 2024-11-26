#include <iostream>
#include <vector>

using namespace std;

struct Cross
{
    int y, x;
    int len;
};

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1 };

int board_height, board_width;
char board[100][100];
bool covered[100][100];

int get_cross_len(int y, int x)
{
    int len = 0;
    while (true)
    {
        bool brk = false;
        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d] * (len + 1);
            int nx = x + dx[d] * (len + 1);

            if (ny < 0 || ny >= board_height || nx < 0 || nx >= board_width || board[ny][nx] != '*')
            {
                brk = true;
                break;
            }
        }
        if (brk) break;
        len++;
    }

    return len;
}

Cross place_cross(int y, int x, int len)
{
    covered[y][x] = true;
    for (int l = 1; l <= len; l++)
    {
        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d] * l;
            int nx = x + dx[d] * l;
            covered[ny][nx] = true;
        }
    }
    return {y, x, len};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
            cin >> board[y][x];
    }

    vector<Cross> crosses;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (board[y][x] == '*')
            {
                int len = get_cross_len(y, x);
                if (len)
                    crosses.push_back(place_cross(y, x, len));
            }
        }
    }

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (board[y][x] == '*' && !covered[y][x])
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << crosses.size() << '\n';
    for (Cross cross : crosses)
        cout << cross.y + 1 << ' ' << cross.x + 1<< ' ' << cross.len << '\n';
}