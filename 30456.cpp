#include <iostream>

int main()
{
    int end, len;
    std::cin >> end >> len;

    if (!end)
    {
        std::cout << 1;
        for (int i = 1; i < len; i++)
            std::cout << 0;
    }
    else
    {
        std::cout << end;
        for (int i = 1; i < len; i++)
            std::cout << 1;
    }
}