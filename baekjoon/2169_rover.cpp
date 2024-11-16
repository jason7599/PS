#include <iostream>
#include <algorithm>

int m_height, m_width;
int m_values[1000][1000];

int solve(int y, int x)
{
    static int memo[1000][1000];
    static const int m_zero = 1e8 + 1;

    if (memo[y][x])
    {
        if (memo[y][x] == m_zero)
            return 0;
        return memo[y][x];
    }

    int res = 0;
    // last row -> rush right
    if (y == m_height - 1)
    {
        while (x < m_width)
            res += m_values[y][x++];
    }
    else
    {
        for (int dx = -1; dx <= 1; dx += 2)
        {
            int sm = m_values[y][x];
            int nx = x + dx;
            while (0 <= nx && nx < m_width)
            {
                sm += m_values[y][nx];
                res = std::max(res, sm + solve(y + 1, nx));
                nx += dx;
            }
        }

        res = std::max(res, m_values[y][x] + solve(y + 1, x));
    }

    memo[y][x] = res ? res : m_zero;
    return res;
}

int main()
{
    std::cin >> m_height >> m_width;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
            std::cin >> m_values[y][x];
    }

    std::cout << solve(0, 0);
}