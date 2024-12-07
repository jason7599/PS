#include <iostream>

int brightness_sum[1001][1001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int image_h, image_w, n_queries;
    std::cin >> image_h >> image_w >> n_queries;

    for (int y = 1; y <= image_h; y++)
    {
        for (int x = 1; x <= image_w; x++)
        {
            int brightness;
            std::cin >> brightness;

            brightness_sum[y][x] = brightness 
                + brightness_sum[y - 1][x]
                + brightness_sum[y][x - 1] 
                - brightness_sum[y - 1][x - 1];
        }
    }

    while (n_queries--)
    {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;

        int brightness = brightness_sum[r2][c2]
            - (
                brightness_sum[r2][c1 - 1]
                + brightness_sum[r1 - 1][c2]
                - brightness_sum[r1 - 1][c1 - 1]
            );
        
        int size = (r2 - r1 + 1) * (c2 - c1 + 1);

        std::cout << brightness / size << '\n';
    }
}