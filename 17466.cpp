#include <iostream>

int main()
{
    int n, p;
    std::cin >> n >> p;

    int res = 1;
    for (int i = 2; i <= n; i++)
        res = ((res * (i % p)) % p);

    std::cout << res;
}