#include <iostream>
#include <vector>
#include <algorithm>

std::pair<std::vector<int>, int> get_divisors(int n)
{
    std::vector<int> divisors {1};
    int sum = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            divisors.push_back(i);
            if (n / i != i)
            {
                sum += n / i;
                divisors.push_back(n / i);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end());
    return {divisors, sum};
}

int main()
{
    while (1)
    {
        int x;
        std::cin >> x;
        if (x == -1)
            break;
        auto res = get_divisors(x);
        if (res.second == x)
        {
            std::cout << x << " = ";
            for (int i = 0; i < res.first.size(); i++)
            {
                std::cout << res.first[i];
                if (i < res.first.size() - 1)
                    std::cout << " + ";
            }
            std::cout << '\n';
        }
        else
            std::cout << x << " is NOT perfect.\n";
    }
}