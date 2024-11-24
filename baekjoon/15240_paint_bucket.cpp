#include <iostream>
#include <queue>

int img_height, img_width;
char image[1000][1000];

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

void bfs(int s_y, int s_x, char new_color)
{
    std::queue<std::pair<int, int>> q;

    char prev_color = image[s_y][s_x];
    image[s_y][s_x] = new_color;
    q.push({s_y, s_x});

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny == img_height || nx < 0 || nx == img_width)
                continue;

            if (image[ny][nx] == prev_color)
            {
                image[ny][nx] = new_color;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> img_height >> img_width;

    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
            std::cin >> image[y][x];
    }

    int s_y, s_x;
    char new_color;

    std::cin >> s_y >> s_x >> new_color;

    if (image[s_y][s_x] != new_color)
        bfs(s_y, s_x, new_color);

    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
            std::cout << image[y][x];
        std::cout << '\n';
    }
}