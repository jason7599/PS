#include <iostream>

int main()
{
    int rows_last_cut[11] = {};
    int cols_last_cut[11] = {};

    int n_weeks;
    std::cin >> n_weeks;

    for (int w = 1; w <= n_weeks; w++)
    {
        for (int i = 0; i < 3; i++)
        {
            int r;
            std::cin >> r;
            rows_last_cut[r] = w;
        }
        for (int i = 0; i < 3; i++)
        {
            int c;
            std::cin >> c;
            cols_last_cut[c] = w;
        }
    }

    int grass_height = n_weeks + 1;

    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            int last_cut = std::max(rows_last_cut[y], cols_last_cut[x]);
            std::cout << grass_height - last_cut << ' ';
        }
        std::cout << '\n';
    }
}