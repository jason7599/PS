#include <bits/stdc++.h>

const int MAX_VAL = 3e6;

bool is_prime[MAX_VAL + 1];

void init_primes(int x)
{
    std::fill(&is_prime[2], &is_prime[x + 1], 1);

    for (int i = 2; i * i <= x; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= x; j += i)
                is_prime[j] = 0;
        }
    }
}

int solve(int prime)
{
    static int cache[MAX_VAL + 1];

    if (cache[prime])
        return cache[prime];
    
    int val = prime - 1;
    int n_splits = 0;
    for (int p0 = val / 2; p0; p0--)
    {
        int p1 = val - p0;
        if (is_prime[p0] && is_prime[p1])
        {
            n_splits = solve(p0) + solve(p1);
            break;
        }
    }

    return cache[prime] = n_splits + 1;
}

int main()
{
    int x;
    std::cin >> x;

    init_primes(x);

    std::cout << solve(x);
}