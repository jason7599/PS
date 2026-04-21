#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n;
    while (std::cin >> n)
    {
        int len = 1;
        long long v = 1;
        while (v % n)
        {
            v = (v * 10 + 1) % n;
            len++;
        }
        std::cout << len << '\n';
    }
}
