#include <iostream>
#include <cmath>

char solve(int idx)
{
    int len = 1;
    while (idx > len * std::pow(26, len))
    {
        idx -= len * std::pow(26, len);
        len++;
    }

    
}

int main()
{
    int idx;
    std::cin >> idx;
    std::cout << solve(idx);
}