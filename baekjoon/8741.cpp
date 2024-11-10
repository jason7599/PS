#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::cout << std::string(n, '1') << std::string(n - 1, '0');
}