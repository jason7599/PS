#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    for (size_t i = 0; i < s.length(); i++)
        std::cout << i << '\n';
}