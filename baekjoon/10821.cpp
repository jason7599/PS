#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::cin >> line;

    int cnt = 0;

    size_t base = 0;
    size_t t;
    while ((t = line.find(',', base)) != std::string::npos)
    {
        base = t + 1;
        cnt++;
    }

    std::cout << cnt + 1;
}