#include <iostream>
#include <string>

std::string fix(const std::string& str)
{
    std::string res;

    size_t pos = 0;
    while (pos < str.length())
    {
        char c = str[pos];
        res += c;
        while (++pos < str.length() && str[pos] == c);
    }

    return res;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << fix(str);
}