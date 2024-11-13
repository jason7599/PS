#include <iostream>
#include <algorithm>

const int max_num = 1e6;

bool is_prime[max_num + 1];

void sieve()
{    
    std::fill(is_prime, is_prime + max_num + 1, 1);

    is_prime[1] = 0;

    for (int i = 2; i * i <= max_num; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_num; j += i)
                is_prime[j] = 0;
        }
    }
}

int main()
{
    sieve();

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;

        int ans = n;
        while (1)
        {
            bool good = 0;
            if (!is_prime[ans])
            {
                for (int div = 2; div < ans; div++)
                {
                    if (is_prime[div]
                    && ans % div == 0
                    && div * div != ans
                    && is_prime[ans / div])
                    {
                        good = 1;
                        break;
                    }
                }
            }
            if (good)
                break;
            ans++;
        }

        std::cout << ans << '\n';
    }
}