#include <iostream>
#include <string>

int _solve(const std::string& str, size_t& pos)
{
    int res = 0;
    bool neg = 0;

    while (pos < str.length())
    {
        char c = str[pos];

        switch (c)
        {
        case '(':
            res += (neg ? -1 : 1) * _solve(str, ++pos);
            break;
        case ')':
            return res;
        case '+':
            break;
        case '-':
            neg = 1;
            break;
        default:
            res += (neg ? -1 : 1) * (c - '0');
            neg = 0;
        }

        pos++;
    }

    return res;
}

int solve(const std::string& str)
{
    size_t pos = 0;
    return _solve(str, pos);
}

int main()
{
    while (!std::cin.eof())
    {
        std::string str;
        std::cin >> str;
        std::cout << solve(str) << '\n';
    }
}