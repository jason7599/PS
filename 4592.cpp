#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        int n;
        std::cin >> n;

        if (!n)
            break;

        int prev =0 ;

        while (n--)
        {
            int x;
            std::cin >> x;
            if (x != prev)
            {
                std::cout << x << ' ';
                prev = x;
            }
        }
        std::cout << "$\n";
    }
}