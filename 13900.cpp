#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n;
    std::cin >> n;

    long long sum = 0;
    long long psum = 0;

    while (n--)
    {
        int x;
        std::cin >> x;
        sum += x;
        psum += x * x;
    }

    std::cout << (sum * sum - psum) / 2;
}