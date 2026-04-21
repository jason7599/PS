#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int res = 0;
    while (n)
    {
        res = res * 2 + n % 2;
        n /= 2;
    }

    std::cout << res;
}