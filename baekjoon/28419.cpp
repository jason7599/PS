#include <iostream>

int main()
{
    int len;
    std::cin >> len;

    int odd = 0;
    int even = 0;
    for (int i = 1; i <= len; i++)
    {
        int x;
        std::cin >> x;
        if (i % 2)
            odd += x;
        else
            even += x;
    }

    int ops = 0;
    while (odd != even)
    {
        if (odd < even)
        {

        }
        else
        {
            
        }
    }

    std::cout << ops;
}