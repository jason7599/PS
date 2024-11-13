#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string str;
        std::cin >> str;

        std::sort(str.begin(), str.end());

        do
            std::cout << str << '\n';
        while (std::next_permutation(str.begin(), str.end()));
    }
}