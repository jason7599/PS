#include <bits/stdc++.h>

const int DYS[] = {1, 0, -1, 0};
const int DXS[] = {0, 1, 0, -1};

int img_height, img_width;
bool image[500][500];

struct Pos
{
    int y;
    int x;
};

int get_area_size(int y, int x)
{
    std::queue<Pos> q({{y, x}});
    image[y][x] = 0;

    int size = 0;
    
    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        size++;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + DYS[d];
            int nx = x + DXS[d];

            if (ny < 0 || ny >= img_height || nx < 0 || nx >= img_width)
                continue;
            
            if (image[ny][nx])
            {
                image[ny][nx] = 0;
                q.push({ny, nx});
            }
        }
    }

    return size;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> img_height >> img_width;

    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
        {
            bool b;
            std::cin >> b;
            image[y][x] = b;
        }
    }

    int n_areas = 0;
    int max_area_size = 0;

    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
        {
            if (image[y][x])
            {
                n_areas++;
                max_area_size = std::max(max_area_size, get_area_size(y, x));
            }
        }
    }

    std::cout << n_areas << '\n' << max_area_size << '\n';
}