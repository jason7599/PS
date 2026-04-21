#include <iostream>
#include <algorithm>

int board_len;
int board[100'000][3];

int get_score(int y, int x, bool max)
{
    static int memo[2][100'000][3];

    if (y == board_len)
        return 0;
    
    if (memo[max][y][x])
        return std::max(memo[max][y][x], 0);
    
    int res = max ? 0 : 1e9;
    for (int nx = std::max(x - 1, 0); nx <= std::min(x + 1, 2); nx++)
    {
        int t = board[y][x] + get_score(y + 1, nx, max);

        if (max)
            res = std::max(res, t);
        else
            res = std::min(res, t);
    }

    if (!res)
    {
        memo[max][y][x] = -1;
        return 0;
    }

    return memo[max][y][x] = res;
}

int main()
{
    std::cin >> board_len;
    for (int y = 0; y < board_len; y++)
    {
        for (int x = 0; x < 3; x++)
            std::cin >> board[y][x];
    }

    int max_score = 0, min_score = 1e9;
    for (int x = 0; x < 3; x++)
    {
        max_score = std::max(max_score, get_score(0, x, 1));
        min_score = std::min(min_score, get_score(0, x, 0));
    }
    
    std::cout << max_score << ' ' << min_score;
}