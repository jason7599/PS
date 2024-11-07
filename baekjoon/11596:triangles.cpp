#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

std::array<int, 3> input_triangle()
{
    std::array<int, 3> triangle;

    for (int i = 0; i < 3; i++)
        std::cin >> triangle[i];
    
    std::sort(triangle.begin(), triangle.end());

    return triangle;
}

int main()
{
    auto t0 = input_triangle();
    auto t1 = input_triangle();

    if (t0 == t1 && std::pow(t0[0], 2) + std::pow(t0[1], 2) == std::pow(t0[2], 2))
        std::cout << "YES";
    else
        std::cout << "NO";
}