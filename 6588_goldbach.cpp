#include <iostream>

const int max_num = 1e6;

bool is_composite[max_num + 1];
int primes[max_num / 4]; // idk
int num_primes;

void sieve()
{
    for (int i = 2; i * i <= max_num; i++)
    {
        if (!is_composite[i])
        {
            for (int j = i * i; j <= max_num; j += i)
                is_composite[j] = 1;
        }
    }

    for (int i = 3; i <= max_num; i++)
    {
        if (!is_composite[i])
            primes[num_primes++] = i;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    sieve();

    while (1)
    {
        int n;
        std::cin >> n;
        if (!n)
            break;
        
        int ans = 0;
        for (int i = 0; i < num_primes; i++)
        {
            int p = primes[i];
            if (p >= n)
                break;
            
            if (!is_composite[n - p])
            {
                ans = p;
                break;
            }
        }

        if (ans)
            std::cout << n << " = " << ans << " + " << n - ans << '\n';
        else
            std::cout << "Goldbach's conjecture is wrong.\n";
    }
}