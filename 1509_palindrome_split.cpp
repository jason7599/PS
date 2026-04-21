#include <iostream>
#include <string>
#include <algorithm>

std::string str;

bool is_palindrome(int start, int end)
{
    for (int i = 0; i < (end - start + 1) / 2; i++)
    {
        if (str[start + i] != str[end - i])
            return 0;
    }
    return 1;
}

int solve(int idx = 0)
{
    static int memo[2500];

    if (idx == str.length())
        return 0;

    if (memo[idx])
        return memo[idx];
    
    int res = 1e9;
    for (int end_idx = idx; end_idx < str.length(); end_idx++)
    {
        if (is_palindrome(idx, end_idx))
            res = std::min(res, 1 + solve(end_idx + 1));
    }

    return memo[idx] = res;
}

int main()
{
    std::cin >> str;
    std::cout << solve();
}