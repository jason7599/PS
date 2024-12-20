#include <iostream>

int main()
{
    int n_tc;
    std::cin >> n_tc;

    std::cout.precision(3);
    std::cout << std::fixed;

    while (n_tc--)
    {
        int k, p, x;
        std::cin >> k >> p >> x;

        float min_cost = k * p + x;
        for (int m = 2;; m++)
        {
            float cost = (float)k * p / m + m * x;
            if (cost > min_cost)
                break;
            min_cost = cost;
        }

        std::cout << min_cost << '\n';
    }
}