#include <iostream>

int solve(int n)
{
    bool visited[1001][1001] = {0};

    int cnt = 0;

    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            if (!x && !y)
                continue;
            
            if (!visited[x][y])
            {
                cnt++;
                int nx = x;
                int ny = y;
                while (nx <= n && ny <= n)
                {
                    visited[nx][ny] = 1;
                    nx += x;
                    ny += y;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << solve(n) << '\n';
    }
}