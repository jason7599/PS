#include <iostream>
#include <algorithm>

int m_height, m_width;
int m_values[1000][1000];

const int dys[] = {0, 1, 0};
const int dxs[] = {-1, 0, 1};

int memo[1000][1000][3];
const int m_zero = 1e8 + 1;

int solve(int y, int x, int d)
{
    if (memo[y][x][d])
    {
        if (memo[y][x][d] == m_zero)
            return 0;
        return memo[y][x][d];
    }

    int res = 0;
    for (int dd = 0; dd < 3; dd++)
    {
        if (dys[d] + dys[dd] == 0 && dxs[d] + dxs[dd] == 0)
            continue;
        
        int ny = y + dys[dd];
        int nx = x + dxs[dd];

        if (ny < 0 || ny == m_height || nx < 0 || nx == m_width)
            continue;
        
        res = std::max(res, solve(ny, nx, dd));
    }

    res += m_values[y][x];
    memo[y][x][d] = res ? res : m_zero;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> m_height >> m_width;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
            std::cin >> m_values[y][x];
    }
    
    solve(0, 0, 0);

    std::cout << solve(m_height - 1, m_width - 1, 2) + solve(m_height - 1, m_width - 1, 1);
}