#include <iostream>
#include <algorithm>

int board_len, str_len;
char board[5000], str[5000];

int solve(size_t board_pos, size_t str_idx = 0)
{
    static int cache[5000][5000];

    int& res = cache[board_pos][str_idx];

    if (res)
        return std::max(res, 0);

    res = board[board_pos] == str[str_idx];

    if (str_idx == str_len - 1)
        return res;
    
    int t = 0;
    if (board_pos)
        t = solve(board_pos - 1, str_idx + 1);
    if (board_pos + 1 < board_len)
        t = std::max(t, solve(board_pos + 1, str_idx + 1));

    res += t;

    if (!res)
    {
        res = -1;
        return 0;
    }
    return res;
}

int main()
{
    std::cin >> board_len >> str_len;

    for (int i = 0; i < board_len; i++)
        std::cin >> board[i];
    
    for (int i = 0; i < str_len; i++)
        std::cin >> str[i];
    
    int max_score = 0;
    for (size_t start = 0; start < board_len; start++)
        max_score = std::max(max_score, solve(start));

    std::cout << max_score;
}