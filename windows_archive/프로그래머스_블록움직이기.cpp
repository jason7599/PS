#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

// right, down, left, up
const int dys[] = {0, 1, 0, -1};
const int dxs[] = {1, 0, -1, 0};

int height;
int width;

bool is_oob(int y, int x)
{
    return y < 0 || y >= height || x < 0 || x >= width;
}

int solution(vector<vector<int>> board)
{
    height = board.size();
    width = board[0].size();

    static bool v[100][100][2];
    // 왼쪽과 윗쪽 기준.
    queue<pair<pii, bool>> q;

    v[0][0][0] = 1;
    q.push({{0, 0}, 0});

    int moves = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int y0 = q.front().first.first;
            int x0 = q.front().first.second;
            bool is_vertical = q.front().second;
            q.pop();

            int y1 = y0 + dys[is_vertical];
            int x1 = x0 + dxs[is_vertical];

            if ((y0 == height - 1 && x0 == width - 1) || (y1 == height - 1 && x1 == width - 1))
                return moves;

            for (int dd = 0; dd < 4; dd++)
            {
                int ny0 = y0 + dys[dd];
                int nx0 = x0 + dxs[dd];

                if (is_oob(ny0, nx0) || board[ny0][nx0])
                    continue;
                
                int ny1 = y1 + dys[dd];
                int nx1 = x1 + dxs[dd];

                if (is_oob(ny1, nx1) || board[ny1][nx1])
                    continue;

                if (!v[ny0][nx0][is_vertical])
                {
                    v[ny0][nx0][is_vertical] = 1;
                    q.push({{ny0, nx0}, is_vertical});
                }
            }

            pii points[2] = {{y0, x0}, {y1, x1}};

            // vertical (is_vertical = 1) => 0, 2
            // horizontal (is_vertical = 0) => 1, 3
            for (int rd = !is_vertical; rd < 4; rd += 2)
            {
                bool can_rotate = 1;

                for (int pi = 0; pi < 2; pi++)
                {
                    int ny = points[pi].first + dys[rd];
                    int nx = points[pi].second + dxs[rd];

                    if (is_oob(ny, nx) || board[ny][nx])
                    {
                        can_rotate = 0;
                        break;
                    }
                }

                if (can_rotate)
                {
                    for (int pi = 0; pi < 2; pi++)
                    {
                        int ny0 = points[pi].first;
                        int nx0 = points[pi].second;

                        int ny1 = ny0 + dys[rd];
                        int nx1 = nx0 + dxs[rd];

                        int y;
                        int x;

                        if (ny1 < ny0 || nx1 < nx0)
                        {
                            y = ny1;
                            x = nx1;
                        }
                        else
                        {
                            y = ny0;
                            x = nx0;
                        }

                        if (!v[y][x][!is_vertical])
                        {
                            v[y][x][!is_vertical] = 1;
                            q.push({{y, x}, !is_vertical});
                        }
                    }
                }
            }
        }

        moves++;
    }

    return stoi("승훈");
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    cout << string(15, '\n');
    cout << solution(board);
    return 0;
}