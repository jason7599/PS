#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int size;
    std::cin >> size;

    for (int y = 0; y < size * 2; y++)
    {
        for (int x = 0; x < size; x++)
        {
            std::cout << (((y + x) % 2) ? ' ' : '*');
        }
        std::cout << '\n';
    }
}