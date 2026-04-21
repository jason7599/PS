#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str, size_t start, size_t len)
{
    for (size_t i = 0; i < len / 2; i++)
    {
        if (str[start + i] != str[start + len - i - 1])
            return 0;
    }
    return 1;
}

int solve(const std::string& str, size_t idx = 0)
{
    static int cache[2001];

    if (idx == str.length())
        return 0;

    int& res = cache[idx];
    if (res)
        return res;

    res = str.length() - idx;

    for (size_t len = 1; idx + len <= str.length(); len++)
    {
        if (is_palindrome(str, idx, len))
            res = std::min(res, 1 + solve(str, idx + len));
    }

    return res;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << solve(str);
}