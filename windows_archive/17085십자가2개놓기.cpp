#include <iostream>

using namespace std;

int board_height, board_width;
bool board_empty[15][15];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int ans;

int get_max_cross_len(int row, int col)
{
    for (int len = 0;; len++)
    {
        for (int d = 0; d < 4; d++)
        {
            int ny = row + dy[d] * (len + 1);
            int nx = col + dx[d] * (len + 1);

            if (ny < 0 || ny >= board_height
            || nx < 0 || nx >= board_width
            || !board_empty[ny][nx])
                return len;
        }
    }
}

void f(int pos_index = 0, int size0 = 0)
{
    if (pos_index == board_height * board_width)
        return;

    int row = pos_index / board_width;
    int col = pos_index % board_width;

    f(pos_index + 1, size0); // without placing 

    if (board_empty[row][col])
    {
        int cross_len = get_max_cross_len(row, col);

        if (size0)
        {
            int size1 = cross_len * 4 + 1;
            if (size0 * size1 > ans)
                ans = size0 * size1;
            return;
        }

        board_empty[row][col] = false;
        f(pos_index + 1, 1);
        for (int len = 0; len < cross_len; len++)
        {
            for (int d = 0; d < 4; d++)
            {
                int ny = row + dy[d] * (len + 1);
                int nx = col + dx[d] * (len + 1);
                board_empty[ny][nx] = false;
            }
            f(pos_index + 1, 4 * (len + 1) + 1);
        }
        for (int len = 0; len < cross_len; len++)
        {
            for (int d = 0; d < 4; d++)
            {
                int ny = row + dy[d] * (len + 1);
                int nx = col + dx[d] * (len + 1);
                board_empty[ny][nx] = true;
            }
        }
        board_empty[row][col] = true;
    }
}

int main()
{
    cin >> board_height >> board_width;
    for (int row = 0; row < board_height; row++)
    {
        for (int col = 0; col < board_width; col++)
        {
            char c; cin >> c;
            board_empty[row][col] = c == '#';
        }
    }

    f();

    cout << ans;
}