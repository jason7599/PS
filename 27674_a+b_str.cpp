#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string str;
        std::cin >> str;

        std::sort(str.rbegin(), str.rend());

        long long i = std::stoll(str);
        std::cout << i / 10 + i % 10 << '\n';
    }
}