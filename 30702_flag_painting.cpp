#include <iostream>
#include <queue>

int flag_height, flag_width;
char flags[2][50][50];
bool visited[50][50];

const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool solve()
{
    for (int y = 0; y < flag_height; y++)
    {
        for (int x = 0; x < flag_width; x++)
        {
            if (visited[y][x])
                continue;
            
            char src_c = flags[0][y][x];
            char dst_c = flags[1][y][x];

            std::queue<std::pair<int, int>> q;

            q.push({y, x});
            visited[y][x] = 1;

            while (!q.empty())
            {
                const auto [cur_y, cur_x] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = cur_y + DIRS[d][0];
                    int nx = cur_x + DIRS[d][1];

                    if (ny < 0 || ny >= flag_height || nx < 0 || nx >= flag_width
                    || visited[ny][nx] || flags[0][ny][nx] != src_c)
                        continue;

                    if (flags[1][ny][nx] != dst_c)
                        return 0;

                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }
    }

    return 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> flag_height >> flag_width;

    for (int i = 0; i < 2; i++)
    {
        for (int y = 0; y < flag_height; y++)
        {
            for (int x = 0; x < flag_width; x++)
                std::cin >> flags[i][y][x];
        }
    }

    std::cout << (solve() ? "YES" : "NO");
}