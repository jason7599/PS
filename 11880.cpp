#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        u_int64_t dims[3];
        for (u_int64_t& d : dims)
            std::cin >> d;

        std::sort(dims, dims + 3);

        std::cout << (u_int64_t)(std::pow(dims[0] + dims[1], 2) + std::pow(dims[2], 2)) << '\n';
    }
}