#include <iostream>

int main()
{
    bool coins[100][100]; // have to make all 0

    int row_count, col_count;
    std::cin >> row_count >> col_count;

    for (int y = 0; y < row_count; y++)
    {
        for (int x = 0; x < col_count; x++)
        {
            char c;
            std::cin >> c;
            coins[y][x] = c == '1';
        }
    }

    int num_flips = 0;
    for (int x = col_count - 1; x >= 0; x--)
    {
        for (int y = row_count - 1; y >= 0; y--)
        {
            if (coins[y][x])
            {
                num_flips++;
                for (int i = 0; i <= y; i++)
                {
                    for (int j = 0; j <= x; j++)
                        coins[i][j] = !coins[i][j];
                }
            }
        }
    }

    std::cout << num_flips;
}