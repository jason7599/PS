#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        int64_t t;
        std::cin >> t;

        if (!t) break;

        t--;

        while (t)
        {
            if (t % 2)
            {

            }
            t >>= 1;
        }
    }
}