#include <iostream>
#include <algorithm>

struct Cell 
{
    bool val;
    int ld_streak;
    int rd_streak;
    int lu_streak;
    int ru_streak;
};

int b_height, b_width;
Cell cells[750][750];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> b_height >> b_width;

    for (int y = 0; y < b_height; y++)
    {
        for (int x = 0; x < b_width; x++)
        {
            char c;
            std::cin >> c;
            cells[y][x].val =
                cells[y][x].ld_streak =
                cells[y][x].rd_streak = 
                cells[y][x].lu_streak =
                cells[y][x].ru_streak = c == '1';

            if (y && cells[y][x].val)
            {
                if (x)
                    cells[y][x].lu_streak += cells[y - 1][x - 1].lu_streak;
                if (x + 1 != b_width)
                    cells[y][x].ru_streak += cells[y - 1][x + 1].ru_streak;
            }
        }
    }

    for (int y = b_height - 2; y >= 0; y--)
    {
        for (int x = 0; x < b_width; x++)
        {
            if (cells[y][x].val)
            {
                if (x)
                    cells[y][x].ld_streak += cells[y + 1][x - 1].ld_streak;
                if (x + 1 != b_width)
                    cells[y][x].rd_streak += cells[y + 1][x + 1].rd_streak;
            }
        }
    }

    int max_size = 0;

    for (int y = 0; y < b_height; y++)
    {
        for (int x = 0; x < b_width; x++)
        {
            if (!cells[y][x].val)
                continue;
            
            int size = std::min(cells[y][x].ld_streak, cells[y][x].rd_streak);
            
            while (size > max_size)
            {
                int ny = y + (size - 1) * 2;
                if (ny >= b_height)
                {
                    size--;
                    continue;
                }
                
                if (size <= std::min(cells[ny][x].lu_streak, cells[ny][x].ru_streak))
                {
                    max_size = size;
                    break;
                }

                size--;
            }
        }
    }

    std::cout << max_size;
}