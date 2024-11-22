#include <iostream>

const int mod = 1e9 + 7;

int main()
{
    int f0 = 0;
    int f1 = 1;

    int n;
    std::cin >> n;

    if (!n)
    {
        std::cout << 0;
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        int t = f1;
        f1 = (f1 + f0) % mod;
        f0 = t;
    }

    std::cout << f1;
}