#include <iostream>

int main()
{
    long long n;
    std::cin >> n;

    bool good = n;
    while (n)
    {
        if (n % 3 == 2)
        {
            good = 0;
            break;
        }
        n /= 3;
    }

    std::cout << (good ? "YES" : "NO");
}