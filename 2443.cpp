#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << std::string(i, ' ');
        std::cout << std::string(2 * (n - i) - 1, '*');
        std::cout << '\n';
    }
}